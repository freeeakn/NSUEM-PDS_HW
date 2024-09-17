CC=g++
FLAGS=-Wall -Werror -Wextra

all:
	$(CC) $(FLAGS) src/main.cpp -o My_HomeWork
	./My_HomeWork

clean:
	rm -rf My_HomeWork

lint:
	clang-format -i src/*.h src/*.cpp