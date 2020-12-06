 # 24780 Group Project  
 This github repo manages 24780 Group Project.
 
 Please replace the following dependencies with your platform specific ones.  
 ```
 .../fssimplewindow.cpp  
 .../fssimplewindow.h  
 .../ysglfontdata.c  
 .../ysglfontdata.h  
 .../yspng.cpp  
 .../yspng.h  
 .../yssimplesound.cpp  
 .../yssimplesound.h  
 .../yssimplesound_dsound.cpp
 ```
     
**Compile Instruction**:  
This release version was tested under Windows MSVC Compiler Version 19.28.29334 for x86. After downloading the package, change directory to `c++opoly`, then run the following command in terminal.
 ```
 cl .\*.cpp .\*.c /I"include/" /Fe"bin/c++opoly" /Fo"obj/"
 ```  
 Then change directory to `bin`, and execute `c++opoly` to start the game.
