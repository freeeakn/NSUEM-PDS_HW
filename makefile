.PHONY: all lectureOne lectureSecond lectureThird
OS = $(shell uname)

ifeq ($(OS),Linux)
	FILENAME = lectureOne lectureSecond lectureThird
else
	FILENAME = *.exe
endif
ifeq ($(OS),Darwin)
	FILENAME = lectureOne lectureSecond lectureThird
endif

CC = g++
FORMAT = clang-format -i
FLAGS = -std=c++20 -Wall -Werror -Wextra
PATHGO = src/go/

all: hello lint lectureOne lectureSecond lectureThird lectureFourth clean
	@echo "GoodBye..."

lectureOne:
	$(CC) $(FLAGS) src/cpp/lecture_1/main.cpp -o lectureOne
	./lectureOne

lectureSecond:
	$(CC) $(FLAGS) src/cpp/lecture_2/main.cpp -o lectureSecond
	./lectureSecond

lectureThird:
	$(CC) $(FLAGS) src/cpp/lecture_3/main.cpp -o lectureThird
	./lectureThird

lectureFourth:
	cd $(PATHGO)lectureFourth ; go mod init lectureFourth ; cd RecursiveFunc; go test ; cd ../RecursiveFromTwoArgs; go test; cd .. ; go run .

# ==============================
# UTILS
# ==============================

hello:
	@echo "==============================================="
	@echo "  ______ _____ ___   ___ ___                   "
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
	@echo "==============================================="
	sleep 3


lint:
	@echo "starts linting..."
	$(FORMAT) src/cpp/**/*.h
	$(FORMAT) src/cpp/**/*.cpp
	@echo "all..."

clean:
	@echo "Cleaning up..."
	rm -rf $(FILENAME)