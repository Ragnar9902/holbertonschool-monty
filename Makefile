all:
	gcc -Wall -Werror -Wextra -pedantic *.c -o monty

gitup:
	git add .
	git commit -m "default"
	git push