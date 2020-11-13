# TASAT
Travellers' Aid Society Access Terminal

The Travellers' Aid Society Access Terminal (TASAT) is an open source computer application (non-commercial only) for use by players and Referees who want a real-life experience using a TAS terminal in a starport or on a spacecraft.

It is written in C/C++/C# and using the Irrlicht3d game engine (http://irrlicht.sourceforge.net/ )

It is recommended that you read the documentation manual and download and install the full application
installation binary located in the /bin folder to get a good understanding of the TASAT.

Forward from Perry Horner
-------------------------
I have always wanted a Traveller® computer application that my players could use as they would use their character’s ship computer and TAS terminals in starports.  I began with a large outline of what such a program would consist of.  The de-facto era I chose to design it around is the Classic/MegaTraveller period during the 4th and 5th Frontier War until around 1115.  After looking it over, I realized that it would take me years to write such a program (I started prototyping the program in GW-BASIC back in 1984, then Turbo-C 1989, then Microsoft C 1995, DirectX in 2000, then Visual C++ using SDL in 2001- lots of porting and rewriting code!).  Instead, I decided to work on the most needed section first- the Navigation Library.  Since this was my very first Windows-based computer program I ever wrote, it has resulted in what may not be considered very pretty or efficient code.  But it is working for me and my players.  I also wanted the code to be as cross-platform as possible, so I selected the open source SDL 1.2.x library for the graphics layer and ANSI C for the language.  I do not have the time to make and distribute other OS versions so I opened up the project/source code for other Traveller® programmers and referees and made sure all was released under the GPL.  Thus, the Travellers’ Aid Society Access Terminal was born.  I would like to share the work I have done and the master schema.  I hope others can add additional modules and modifications to make this program fully functional (tall request, I know.)  Even the Navigation Library has still a lot of work to be done.  Sectors need to be added for various eras, library data generated, addition of planetoid info, and other program modifications, or a new port to a newer operating system. Please enjoy, and thank you Marc Miller for creating this inspiring game! – Perry Horner, October 2014
