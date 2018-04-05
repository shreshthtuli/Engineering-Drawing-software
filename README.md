# Engineering-Drawing-software

This repository holds the mathematical model, documentation, functional descriptions and source files of an Engineering Drawing and 3D CAD
 development software as a part of COP290 Course at IIT Delhi. </br>
 Team Members: Shreshth Tuli (2016CS10680), Sankalan Pal Chowdhury (2106CS10701) 
 
 ## Aim

The package is supposed to have the following functionalities:
   1. We should be able to interactively input or read from a file either </br> i) an isometric drawing and a 3D object model or </br> ii) projections on to any cross section.
   2. Given the 3D model description we should be able to generate projections on to any cross section or cutting plane.
   3. Given two or more projections we should be able to interactively recover the 3D description and produce an isometric drawing from any view direction. 
   
## Screenshot

![Alt text](/screen.png "Screenshot")

## Structure

The package structure for the software package is as follows:  
Engineering Drawing Software </br>
  |  </br>
  |-> build</br>
   &nbsp; |-> release
  |-> doc </br>
   &nbsp; |-> doc_src</br>
   &nbsp; |-> doxygen</br>
   &nbsp; |-> model_mathematics</br>
   &nbsp; |-> functional_model_UML.mdj</br>
  |-> screenshots</br>
  |-> src</br>
   &nbsp; |-> COP290_6
   &nbsp; |-> build-COP290-Qt_static-Release 
  |-> test</br>
    
Following is the description of the directories:
1. **build** : The executable and dependent files/binaries </br>
2. **doc** : Documentation and related files
i) *doc* : Source files for doxygen
ii) *doxygen* : Doxygen generated documentation and class structure of the software. Also contains inital source files for documentation.
iii) *model_mathematics* : Mathematical model description
iv) *Functional Description* : StarUML functional description of all the features and parts of the software.
4. **3D CAD Software** : Main file containing all the software files including - </br>
i) *build* : The executable and dependent files </br>
ii) *src* : source (C++, XML) files developed for the software</br>
iii) *screenshots* : some screens showing the features</br>
iv) *test-files* : some exemplar files (.txt) used for testing

## Qt and OpenGL

The Model has been developed using Qt and OpenGL libraries. These are not required to be installed, as the executable is statically linked and deployment ready.
This is not a cross-platform software and is built to run on Windows.

## Compilation and execution instructions
 
Go to the src directory inside build folder and run
```
make
```
Then change current directory to build and run
```
./COP290
```

## TODO:

1. Make the plane reconstruction code more stable and ready for complex models
2. Optimize the 3D reconstruction
3. Adding features for seamlessly building 3D Models

