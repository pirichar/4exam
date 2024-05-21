#! /bin/bash

gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main.c 
./a.out text.txt
rm a.out