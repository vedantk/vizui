# viz3d Makefile
# Original Author: Chris Wyman (January 2, 2007)
# Modified for VTK 5.4, other tweaks: Vedant Kumar (November 21, 2009)

EXENAME = viz3d
SOURCE = viz3d.cxx

VTKLIBS = /usr/local/lib/vtk-5.4
VTKINCLUDE = /usr/local/include/vtk-5.4

CC = g++
INCLUDES = -I. -I /usr/X11R6/include/ -I $(VTKINCLUDE)
LDFLAGS = -L $(VTKLIBS) -L /usr/X11R6/lib/ -L /usr/lib
CCFLAGS = -Wno-deprecated -O3 
EXE = $(EXENAME)

LIBS = -lvtkWidgets -lvtkRendering -lvtkImaging -lvtkGraphics -lvtkFiltering \
       -lvtkGenericFiltering -lvtkHybrid -lvtkIO -lvtkftgl -lvtkVolumeRendering -lvtkNetCDF \
       -lvtkDICOMParser -lvtkCommon -lvtkexoIIc -lvtkexpat -lvtkfreetype -lvtkjpeg \
       -lvtkParallel -lvtkverdict -lvtkmetaio -lvtksqlite \
       -lvtkpng -lvtksys -lvtktiff -lvtkzlib -lGL -lGLU -lX11 -lXmu -lXi -lm -lpthread

OBJS = $(SOURCE:.o)
BASEOBJ = $(notdir $(OBJS))
FINALOBJ = $(addprefix obj/,$(BASEOBJ))

default: $(SOURCE) $(EXE) 

$(EXE): obj/ $(FINALOBJ) 
	$(CC) $(INCLUDES) $(CCFLAGS) $(LDFLAGS) $(FINALOBJ) $(LIBS) $(SOURCE) -o $@

obj/%.o: %.cpp
	$(CC) -c $(CCFLAGS) $(INCLUDES) $< -o $@

obj/:
	mkdir obj
	
clean:
	rm -f $(addprefix obj/,$(BASEOBJ)) $(EXE)
