# GameEngine

## Comment compiler le projet

Sous Windows : Nécessite d'avoir installé CLion et un compilateur C++ (nous recommandons Visual C++ via Visual Studio 2017).

Dans Clion, une fois le projet ouvert, aller dans _File -> Settings -> Build, Execution & Deployment_ et modifier les éléments suivants :

* Dans _Toolchains_ :
  * Choisir comme _Environment_ Visual Studio, et indiquer l'emplacement de Visual Studio 2017
  * Modifier la valeur d'_Architecture_ en **_amd64_**

* Dans _CMake_ :
  * Modifier la valeur de _Generation path_ en la racine du projet (dossier **_GameEngine_** par défaut)
