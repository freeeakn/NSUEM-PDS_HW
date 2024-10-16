.PHONY: all
OS = $(shell uname)

ifeq ($(OS),Linux)
	FILENAME = lectureOne lectureSecond
else
	FILENAME = *.exe
endif
ifeq ($(OS),Darwin)
	FILENAME = lectureOne lectureSecond
endif

CC = g++
FORMAT = clang-format -i
FLAGS = -std=c++20 -Wall -Werror -Wextra

all: hello lint lectureOne lectureSecond clean
	@echo "GoodBye..."

lectureOne:
	$(CC) $(FLAGS) src/lecture_1/main.cpp -o lectureOne
	./lectureOne

lectureSecond:
	$(CC) $(FLAGS) src/lecture_2/main.cpp -o lectureSecond
	./lectureSecond

# ==============================
# UTILS
# ==============================

hello:
	@echo " |  ____|_   _|__ \ / _ \__ \                  "
	@echo " | |__    | |    ) | | | | ) |                 "
	@echo " |  __|   | |   / /| | | |/ /                  "
	@echo " | |     _| |_ / /_| |_| / /_                  "
	@echo " |_|    |_____|____|\___/____|                 "
	@echo "     /\        | | | |                         "
	@echo "    /  \   _ __| |_| |__  _   _ _ __           "
	@echo "   / /\ \ | '__| __| '_ \| | | | '__|          "
	@echo "  / ____ \| |  | |_| | | | |_| | |             "
	@echo " /_/___ \_\_|   \__|_| |_|\__,_|_|_    _       "
	@echo " |  __ \        | |              | |  (_)      "
	@echo " | |__) |__  ___| |__   ___ _ __ | | ___ _ __  "
	@echo " |  ___/ _ \/ __| '_ \ / _ \ '_ \| |/ / | '_ \ "
	@echo " | |  |  __/ (__| | | |  __/ | | |   <| | | | |"
	@echo " |_|   \___|\___|_| |_|\___|_| |_|_|\_\_|_| |_|"
	sleep 3


lint:
	@echo "starts linting..."
	$(FORMAT) src/**/*.h
	$(FORMAT) src/**/*.cpp
	@echo "all..."

clean:
	@echo "Cleaning up..."
	rm -rf $(FILENAME)