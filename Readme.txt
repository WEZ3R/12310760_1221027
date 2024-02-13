Projet Image

Ce projet contient les classes Pixel et Image ainsi que trois programmes principaux qui les utilisent : mainTest, mainExemple et mainAffichage.

Dépendances

Ce projet dépend de la bibliothèque SDL2 pour l'affichage graphique. Pour l'installer sur Linux, vous pouvez exécuter la commande suivante : sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev

Compilation

Le projet peut être compilé en exécutant la commande make. Les fichiers exécutables seront créés dans le répertoire bin.

Exécution

Les trois programmes principaux peuvent être exécutés en exécutant les commandes suivantes :
./bin/test
./bin/exemple
./bin/affichage

Organisation des fichiers

    Les fichiers source se trouvent dans le répertoire src.
    Les fichiers objets générés par la compilation se trouvent dans le répertoire obj.
    Les fichiers exécutables générés par la compilation se trouvent dans le répertoire bin.	
    Les mages créées par l'exécutable "exemple" se trouvent dans le répertoire data.
