# Conception d'application réparties - Mise en place d'un serveur FTP
#### Nicolas CACHERA - Pierre FALEZ
###### 29/01/2015

#### Introduction

Cette application est un serveur FTP classique permettant d'exécuter les commandes les plus classiques. Le serveur nécessite un compte afin de pouvoir s'y connecter, comptes stockés dans le fichier user.conf. Toutefois, il existe un compte anonyme ayant pour identifiant "anonymous" et pour mot de passe "_".

Voici la liste des commandes disponibles sur le serveur :
* USER username -> Permet d'entrer le login utilisateur.
* PASS password -> Permet d'entre le mot de passe utilisateur.
* RETR filename -> Permet de récuperer un fichier sur le serveur.
* STOR filename -> Permet de déposer un fichier sur le serveur.
* LIST -> Affiche la liste des fichiers présent dans le répertoire courant du serveur.
* PWD -> Affiche le chemin du répertoire courant du serveur.
* CWD directory -> Permet de changer le répertoire courant du serveur.
* CDUP -> Equivalent à CWD ..
* QUIT -> Permet de quitter le serveur
* PORT ->
* SYST ->
* FEAT ->
* TYPE ->
* PASV ->

#### Architecture

#### Code Samples