flPlug is a library whose purpose is to provide a type-safe interface
for the event callback system of the Fast Light ToolKit (FLTK) library.

The FLTK's callback system is a powerful mechanism but suffers for some
comfortless features that flPlug tries to easy:
- The callbacks have to be global functions, not object member functions
- The interface for callbacks is not type-safe (you have to cast the parameters
	to/from void* to use external data)


flPlug has been tested with FLTK versions 1.1.* and 1.3.*.

Please send me your comments to flplug@gmail.com

Happy coding!

Diego Florio
