# Conception d'application réparties - Mise en place d'un serveur FTP
#### Nicolas CACHERA - Pierre FALEZ
###### 29/01/2015

#### Introduction

Cette application est un serveur FTP classique permettant d'exécuter les commandes les plus classiques. Le serveur nécessite un compte afin de pouvoir s'y connecter, comptes stockés dans le fichier user.conf. Toutefois, il existe un compte anonyme ayant pour identifiant "anonymous" et pour mot de passe "_".

Voici la liste des commandes disponibles sur le serveur
* CDUP -> Equivalent à CWD ..
* CWD directory -> Permet de changer le répertoire courant du serveur.
* FEAT -> Permet de connaitre d'éventuelles commandes non-habituelles supportées par le serveur.
* LIST -> Affiche la liste des fichiers présent dans le répertoire courant du serveur.
* MKD directory -> Supprime le dossier directory dans le répertoire courant du serveur.
* PASS password -> Permet d'entre le mot de passe utilisateur.
* PASV -> Permet d'activer le mode passif.
* PORT -> Permet d'ouvrir une nouvelle connexion.
* PWD -> Affiche le chemin du répertoire courant du serveur.
* QUIT -> Permet de quitter le serveur.
* RETR filename -> Permet de récuperer un fichier sur le serveur.
* RMD directory -> Crée le dossier directory dans le répertoire courant du serveur.
* STOR filename -> Permet de déposer un fichier sur le serveur.
* SYST -> Demande des informations sur le système du serveur.
* TYPE -> Définis le type de fichier à transférer.
* USER username -> Permet d'entrer le login utilisateur.

#### Architecture

Cette application comprends 4 packages : core, exception, system et network

Le package core contient tout ce qui concerne le serveur en lui même. Il est composé de quelques classes et d'un sous package (message) lui même divisé en deux packages :
* answer : Contient tout ce qui concerne les types de réponse à une requête
* request : Contient tout ce qui concerne les requêtes

Le package exception contient, comme son nom l'indique, tout ce qui concerne les exceptions

Les packages system et network sont des packages contenant toute l'encapsulation de méthodes C permettant de manipuler les dossiers (system) et les sockets et adresses IP (network).

L'application fonctionne de la sorte :
* Le serveur est lancé, il attends une connexion.
* Lorsqu'une connexion est reçue, le serveur en crée un utilisateur et lui créer un nouveau thread pour pouvoir continuer de recevoir d'autres connexions.
* Une connexion est créée sous la forme de la classe Client, elle est utilisée pour reçevoir toutes les requêtes que l'utilisateur lui enverra.
* Elle garde en mémoire, grâce à la classe User, le nom d'utilisateur et le dossier courant de l'utilisateur.
* Une fois une requête reçu, la classe User la prend et l'envoie à la RequestFactory afin de récupérer la bonne classe correspondant à la requête.
* La RequestFactory va en réalité prendre le premier argument de la requête et le comparer aux commandes qu'elle connait. Si elle trouve la commande, elle crée la requête avec l'aide des arguments suivants si nécessaire. Sinon, elle retourne un pointeur null.
* Enfin, la classe User enverra cette classe au RequestHandler qui s'occupera de distribuer la classe à la bonne méthode afin qu'elle puisse l'executer et renvoyer d'elle même la réponse. Si la classe retournée est un pointeur null, le client enverra une réponse de type AnswerUnimplemented à l'utilisateur.
* Plusieurs classe de réponse sont précréée, chacune liée à un code. Un texte peut y être ajouté en tant qu'argument pour accompagner le code qui sera affiché à l'utilisateur.

Voici les différentes erreurs pouvant être attrapées ou lancées par l'application :
* THROW(UnrecognizedMessageException, "PORT "+raw_address, std::string(token)+" is an incorrect number") par la méthode eval de la classe RequestFactory. Lancée lorsque la commande PORT comporte des champ qui ne sont pas des nombre dans l'addresse et le port client (a1,a2,a3,a4,p1,p2)
* THROW(UnrecognizedMessageException, "PORT "+raw_address, "too many arguments") par la méthode eval de la classe RequestFactory. Lancée lorsque il y a plus de 6 nombre separé par des virgule dans la commande PORT
* THROW(UnrecognizedMessageException, "PORT "+raw_address, "not enough argument") par la méthode eval de la classe RequestFactory. Lancée lorsque il y a moins de 6 nombre separé par des virgule dans la commande PORT
* THROW(UnrecognizedMessageException, "TYPE", "Unrecognized type "+type_char) par la méthode eval de la classe RequestFactory. Lancée lorsque le type de fichier à transferer demander par l'utilisateur est inconnu
* THROW(NoActiveConnectionException, "") par la méthode openDataConnection de la classe Client. Lancée lorsque le serveur tente d'ouvrir une nouvelle connexion active alors qu'aucun port n'a été spécifié.
* try { ... } catch(SystemException& e) { ...	} par la méthode processListConnection de la classe RequestHandler. L'exception est attrapée lorsque le répertoire donné avec la requête liste n'est pas atteignable. Une réponse de type AnswerFileUnavailable sera alors envoyée à l'utilisateur
* THROW(UserNotFoundException, username) par la méthode findUser de la classe UserList. Lancée lorsque l'utilisateur cherché n'a pas été trouvé.
* THROW(FileNotFoundException, pathname) par la méthode process de la classe UserConfigurationReader. Lancée lorsque le fichier de configuration n'a pas été trouvé.
* THROW(IncorrecteFileFormatException, FILE_FORMAT_LINE, line_number, pathname) par la méthode process de la classe UserConfigurationReader. Lancée lorsque la syntaxe du fichier config est incorrecte.
* try { ... }	catch(const Exception& e) { ... } par la méthode main. Attrape l'exception lorsque le serveur à lancé une exception. La méthode envoie alors un message aux utilisateurs indiquant que le serveur a planté.
* try { ... }	catch(const Exception& e) { ... } par chaque thread client. Attrape l'exception lorsque le client à lancé une exception. Le client en question est fermé mais les autres client et le serveur no sont pas atteind
#### Code Samples

Gestion de l'écoute de nouveau client
```
while(_listener.isOpen()) {
	TCP::Socket client;
        _listener.accept(client); // accept next client

        Thread<Client> thread(new Client(this, client)); // open a new thread for handle the client connection
        thread.run(); // run client thread
    }

```

Gestion des meesage dans chaque client
```

while(_socket.isOpen() && _isOpen) { // While the socket is open and the client is running
	Packet packet;

	_socket.receive(packet); // receive next packet

	Request* message = RequestFactory::eval(packet); //Send apcket to factory for create a structured message

	if(message != nullptr) {
		RequestHandler::process(*message, this); //process message
		delete message;
        }
	else { // if message is unrecognized, then send Answer to client with unimplemented command content
            Packet answer_packet;

            AnswerUnimplemented answer;
            answer.addArgument("Uninplemented command");
            answer.generatePacket(answer_packet);

            _socket.send(answer_packet);
        }
}

```

Gestion de connexion sur le canal de donnée pour les mode passif et actif

```

if(_inPassiveMode) { // if client is currently in passive mode
	_passiveDataSocket.close();
	_passiveDataListener.accept(_passiveDataSocket); // then wait client connection
	std::cout << "[Client " << _uid << "] Accept new passive data connection" << std::endl;
}
else {
	if(_nextActivePort == 0) // if client don't specified data socket address with a PORT command
		THROW(NoActiveConnectionException, "");
	_activeDataSocket.close();
	_activeDataSocket.connect(_nextActiveAddress, _nextActivePort); // then connect to the address:port specified in last command PORT
	std::cout << "[Client " << _uid << "] Open new active data connection (" << _nextActiveAddress << ":" << _nextActivePort << ") " << std::endl;
}
```

Gestion des erreur dans les thread pour éviter de stopper toute l'application quand une exception survient dans un thread client 
```
try {
	arg_cast->_class->run(); // run the main methods of thread class
}
catch(const Exception& e) { // if uncaught exception arise here
	std::cerr << "Exception caught" << std::endl;
	std::cerr << e.getMessage() << std::endl;
	if(e.getFile() != nullptr)
		std::cerr << "Line " << e.getLine() << " in file " << e.getFile() << std::endl;
	arg_cast->_class->close(); // close thread class
}
```

Création du server et libération des ressources, comme les socket encore connecté, lorsque le programme s'arrete de maniere attendu ou non.
```
void onExit() {
    if(server_ref != nullptr) {
        server_ref->close();
    }
}

//[...]

ServerConfiguration configuration;

FTPServer server(configuration);
server_ref = &server;

atexit(onExit);

server.run();
```
