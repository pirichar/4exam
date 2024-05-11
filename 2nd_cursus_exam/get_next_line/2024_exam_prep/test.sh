#! /bin/bash

echo -e '\n\n\nTest with 0\n\n\n';
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=0 -g may_11.c
./a.out text.txt
echo -e '\n\n\nTest with 1\n\n\n';
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 -g may_11.c
./a.out text.txt
echo -e '\n\n\nTest with 42\n\n\n';
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 -g may_11.c
./a.out text.txt
echo -e '\n\n\nTest with 100\n\n\n';
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=100 -g may_11.c
./a.out text.txt

rm a.out
rm -rf a.out.dSYM