# SaveObj.h
This is the main header file (also the only .h file). This file contains the methods:
* `void writeObject<T>(const T* object, const char* fileName)`
* `T readObject<t>(const char* fileName)`

# Demo.cpp
In this demo file I show how to use the functions in SaveObj.h; please take a good look at them!

# TODO
* More error handling; please report any errors.

# License
I don't have a license, just use it idc.

# Note
Note that every compiler implements padding differently. These files also won't work crossplatform because of the difference in memory management. I only tested it on Win x64 so errors/bugs may happen on other platforms.
