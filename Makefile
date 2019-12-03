csrc = $(wildcard src/graphics/window.c)
hsrc = $(wildcard src/graphics/window.h)
osrc = $(csrc:window.c=window.o)

OS := $(shell uname)

ifeq ($(OS), Darwin)
	# Check if its in MAC OS
	LDFLAGS = -framework OpenGl -lglfw -lGLEW
else
	# Check if its Linux
	LDFLAGS = -lGL -lglut -lGLEW -lglfw 
endif


all: engine srcPrep

# To compile the window programs fom the graphic folder
srcPrep: $(csrc) $(hsrc)
	gcc -Wall -c $(csrc) $(LDFLAGS)

engine: torpoEngine.o $(osrc)
	gcc -Wall -o engine torpoEngine.o $(osrc) $(LDFLAGS)

torpoEngine.o: torpoEngine.c $(hsrc)
	gcc -Wall -c torpoEngine.c $(LDFLAGS)

clean:
	rm -f engine *.o $(osrc)