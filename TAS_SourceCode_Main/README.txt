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

ROOT DIRECTORY INSTALLATION STRUCTURE/MAP
------------------------------------------

+---accounts
|   +---bank
|   \---users
+---bmaps
|   +---accounts
|   +---admin
|   +---advertisements
|   +---classifieds
|   |   \---forsale
|   +---communications
|   +---libdata
|   +---menu
|   +---navlib
|   |   \---silhouette
|   +---news
|   \---planet
|       \---colors
+---communications
|   \---messages
|       \---mailbox
+---docs
+---extra
+---fonts
+---librdata
|   +---classic
|   +---custom
|   +---m0
|   +---T5
|   \---tne
+---news
|   +---classic
|   |   +---1005
|   |   +---1008
|   |   +---1010
|   |   +---1021
|   |   +---1025
|   |   +---1035
|   |   +---1037
|   |   +---1040
|   |   +---1042
|   |   +---1049
|   |   +---1057
|   |   +---1074
|   |   +---1077
|   |   +---1079
|   |   +---1083
|   |   +---1085
|   |   +---1086
|   |   +---1087
|   |   +---1088
|   |   +---1089
|   |   +---1090
|   |   +---1092
|   |   +---1094
|   |   +---1095
|   |   +---1098
|   |   +---1099
|   |   +---1101
|   |   +---1103
|   |   +---1105
|   |   +---1106
|   |   +---1107
|   |   +---1108
|   |   +---1109
|   |   +---1110
|   |   +---1111
|   |   +---1112
|   |   +---1113
|   |   +---1114
|   |   +---1115
|   |   +---1116
|   |   +---1117
|   |   +---1118
|   |   +---1119
|   |   +---1120
|   |   +---1121
|   |   +---1122
|   |   +---1123
|   |   +---1124
|   |   +---1125
|   |   +---1126
|   |   +---1127
|   |   +---1128
|   |   +---1129
|   |   \---1130
|   +---custom
|   +---m0
|   +---T5
|   \---tne
|       +---1201
|       \---1202
+---saved
|   +---account
|   +---jobs
|   +---missions
|   +---planet
|   +---sector
|   \---subsector
+---sectors
|   +---classic
|   |   +---100
|   |   |   \---data
|   |   +---101
|   |   |   \---data
|   |   +---102
|   |   |   \---data
|   |   +---109
|   |   |   \---data
|   |   +---110
|   |   |   \---data
|   |   +---111
|   |   |   \---data
|   |   +---112
|   |   |   \---data
|   |   +---113
|   |   |   \---data
|   |   +---114
|   |   |   \---data
|   |   +---115
|   |   |   \---data
|   |   +---116
|   |   |   \---data
|   |   +---117
|   |   |   \---data
|   |   +---118
|   |   |   \---data
|   |   +---119
|   |   |   \---data
|   |   +---120
|   |   |   \---data
|   |   +---121
|   |   |   \---data
|   |   +---127
|   |   |   \---data
|   |   +---128
|   |   |   \---data
|   |   +---129
|   |   |   \---data
|   |   +---130
|   |   |   \---data
|   |   +---131
|   |   |   \---data
|   |   +---132
|   |   |   \---data
|   |   +---133
|   |   |   \---data
|   |   +---134
|   |   |   \---data
|   |   +---135
|   |   |   \---data
|   |   +---136
|   |   |   \---data
|   |   +---137
|   |   |   \---data
|   |   +---138
|   |   |   \---data
|   |   +---145
|   |   |   \---data
|   |   +---150
|   |   |   \---data
|   |   +---151
|   |   |   +---data
|   |   |   \---routes
|   |   +---152
|   |   |   \---data
|   |   +---153
|   |   |   \---data
|   |   +---154
|   |   |   \---data
|   |   +---155
|   |   |   \---data
|   |   +---169
|   |   |   \---data
|   |   +---170
|   |   |   \---data
|   |   +---171
|   |   |   \---data
|   |   +---188
|   |   |   \---data
|   |   +---189
|   |   |   \---data
|   |   +---23
|   |   |   \---data
|   |   +---24
|   |   |   \---data
|   |   +---25
|   |   |   \---data
|   |   +---26
|   |   |   \---data
|   |   +---27
|   |   |   \---data
|   |   +---28
|   |   |   \---data
|   |   +---29
|   |   |   \---data
|   |   +---30
|   |   |   \---data
|   |   +---31
|   |   |   \---data
|   |   +---32
|   |   |   \---data
|   |   +---33
|   |   |   \---data
|   |   +---36
|   |   |   \---data
|   |   +---38
|   |   |   \---data
|   |   +---39
|   |   |   \---data
|   |   +---40
|   |   |   \---data
|   |   +---41
|   |   |   \---data
|   |   +---42
|   |   |   \---data
|   |   +---43
|   |   |   \---data
|   |   +---44
|   |   |   \---data
|   |   +---45
|   |   |   \---data
|   |   +---46
|   |   |   \---data
|   |   +---47
|   |   |   \---data
|   |   +---48
|   |   |   \---data
|   |   +---49
|   |   |   \---data
|   |   +---55
|   |   |   \---data
|   |   +---56
|   |   |   \---data
|   |   +---57
|   |   |   \---data
|   |   +---58
|   |   |   \---data
|   |   +---59
|   |   |   \---data
|   |   +---6
|   |   |   \---data
|   |   +---60
|   |   |   \---data
|   |   +---61
|   |   |   \---data
|   |   +---62
|   |   |   \---data
|   |   +---63
|   |   |   \---data
|   |   +---64
|   |   |   \---data
|   |   +---65
|   |   |   \---data
|   |   +---66
|   |   |   \---data
|   |   +---73
|   |   |   \---data
|   |   +---74
|   |   |   \---data
|   |   +---75
|   |   |   \---data
|   |   +---76
|   |   |   \---data
|   |   +---77
|   |   |   \---data
|   |   +---78
|   |   |   \---data
|   |   +---79
|   |   |   \---data
|   |   +---80
|   |   |   \---data
|   |   +---81
|   |   |   \---data
|   |   +---82
|   |   |   \---data
|   |   +---83
|   |   |   +---data
|   |   |   \---desc
|   |   +---84
|   |   |   \---data
|   |   +---91
|   |   |   \---data
|   |   +---92
|   |   |   \---data
|   |   +---93
|   |   |   \---data
|   |   +---94
|   |   |   \---data
|   |   +---95
|   |   |   \---data
|   |   +---96
|   |   |   \---data
|   |   +---97
|   |   |   \---data
|   |   +---98
|   |   |   \---data
|   |   \---99
|   |       \---data
|   +---custom
|   +---m0
|   |   +---100
|   |   |   \---data
|   |   +---61
|   |   |   \---data
|   |   +---62
|   |   |   \---data
|   |   +---63
|   |   |   \---data
|   |   +---64
|   |   |   \---data
|   |   \---81
|   |       \---data
|   +---T5
|   \---tne
|       +---136
|       |   \---data
|       +---56
|       |   \---data
|       +---59
|       |   \---data
|       \---60
|           \---data
+---sounds
+---spacecraft
|   \---player
+---temp
\---templates
    \---sector
        \---data

