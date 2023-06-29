EXECUTABLES := base_converter base3_add

.PHONY: all clean

all: $(EXECUTABLES)

base_converter: base_converter.c
	gcc -Wall -Werror base_converter.c -o base_converter

base3_add: base3_add.c
	gcc -Wall -Werror base3_add.c -o base3_add

clean:
	rm -f $(EXECUTABLES)