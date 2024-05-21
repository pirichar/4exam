#! /bin/bash

gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main.c -g
./a.out text.txt