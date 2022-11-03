# V3D

Programm to visualize the 3D model.

The program was developed in C++ language of C++17 standard follow the Google style
The program built with Makefile which contains standard set of targets for GNU-programs: 
all, install, uninstall, clean, dvi, dist, tests.
The program is developed according to the principles of object-oriented programming;
Unit tests coverage of modules related to model loading 

The program provides the ability to:

Load a model from an obj file (vertices, surfaces and normal list support).
Translate the model by a given distance in relation to the X, Y, Z axes.
Rotate the model by a given angle in relation to its X, Y, Z axes.
Scale the model by a given value.
Toggle the type of object display: wireframe model, flat shading and smooth shading (by Gouraud or Phong methods)
Create multiple light sources and customize their base intensity, position and direction.

GUI implementation, based on Qt library

The graphical user interface contains:

A button to select the model file and a field to output its name.
A visualization area for the model.
Buttons and input fields for translating the model.
Buttons and input fields for rotating the model.
Buttons and input fields for scaling the model.
Information about the uploaded model - file name, number of vertices and edges.

The program implemented using the MVC pattern.

The program allows customizing the type of projection (parallel and central)
The program allows setting up the type (solid, dashed), color and thickness of the edges, display method (none, circle, square), color and size of the vertices
The program allows choosing the background color
The program allows selecting the base color of the object
Settings saved between program restarts

The program allows saving the captured (rendered) images as bmp, jpeg and gif files.

The program allows applying a texture to an object (texture mapping) that has a UV-map
When rendering, the polygons of the model shaded according to the UV-mapping
When loading a model with UV-mapping, the is available "Apply Texture" button, which allows you to select a texture file
The texture can only be square, and the coordinates are always normalized to values between 0 and 1
After the textures are loaded, the "Remove texture" button is available in the program interface, after which the texture is unloaded from memory and reinstalled on the program model.

A more detailed description of the interface is available after running the dvi target