TASAT uses irrlicht3d includes and libraries

Fonts created by using tool at http://armen138.me/FontMapper/
Source for font maker at https://github.com/Armen138/FontMapper

The distribution compiled binary is 32-bit using 32-bit versions of irrlicht3d.


MS Visual Studio
-----------------
In your project properties under the "Linker/System" tab, change the SubSystem from Console to Windows so the command line window does not appear in the background.  Make sure to set the additional include directories to your irrlicht developer code in the C/C++ options, add Irrlicht.lib to the linker. 

Error recording is done through file pointer ERR which writes to error.txt

The launcher application executes external process calls to the .tas applications (just .exe files renamed with .tas)



GCC
-------
GCC Linking (rename main.cpp to main.c): gcc -I/usr/include/Irrlicht -I/usr/include main.c /usr/lib/libm.a -o tas -lIrrlicht -Wfatal-errors

