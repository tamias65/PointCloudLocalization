#########################################
### 
###      M A K E F I L E
###
###
###



# compiler flags ------------------------------


CPP  = gcc

CFLAGS = -I/usr/X11/include

$./%.o %.o: %.cpp
	@ echo "    ---- Compiling $< (C++)"
	@ $(CPP) $(CFLAGS) -c -o $@ $<

# object files ----------------------------------------------------

OBJS = initx.o windowx.o textx.o colorx.o drawx.o cursorx.o grey.o

# libraries ----------------------------------------------------

LIBS = -lezx -lX11 -lm -L. -L/usr/X11R6/lib

# compile --------------------------------------------------------

all:	libezx.a tst2


libezx.a:	Makefile.depend $(OBJS)
	@ echo "    ---- Creating $@"
	@ ar r $@ $(OBJS)
	@ ranlib $@


tst2:	Makefile.depend libezx.a tst2.o
	@ echo "    ---- Linking"
	@ $(CPP) tst2.o $(LIBS) -o tst2



clean:
	rm -f -R *.o *.a Makefile.depend demo scrabble core
	 

# General dependencies -------------------------------------------


Makefile.depend:
	@ echo "    ---- Analyzing dependencies"
	@ $(CPP) -MM $(CFLAGS) *.c > Makefile.depend

depend:	Makefile.depend


include Makefile.depend
