TARGET = bin/mort_calc
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))


test : clean compile
	./$(TARGET) -p 100000 -d 20000 -t 30 -i 5

compile: $(TARGET)

clean:
	rm -f obj/*.o
	rm -f bin/*
	rm -f *.db

$(TARGET): $(OBJ)
	gcc -o $@ $? -lm


obj/%.o : src/%.c
	gcc -c $< -o $@ -Iinclude