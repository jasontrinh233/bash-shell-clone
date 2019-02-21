# Basic Linux - Bash Program

0. Require library:
- `readline`
- `ncurses`: `sudo apt-get install libncurses5-dev libncursesw5-dev`
1. Compile:
```
g++ -o command -g tokenizer.cpp command.cpp -lreadline -lcurses
```
2. Execute:
```
./command
```
3. Feature:
- `ls`: list directories and files. (custom-defined)
- `cd`: change directory. (custom-defined)
- `pwd`: display current working directory. (custom-defined)
- `clear`: clear terminal screen. (custom-defined)
-  ... : (system call using fork() and execvp())
