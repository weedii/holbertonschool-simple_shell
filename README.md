# <h1 align="center">Simple Shell Project</h1>

---

## <img src="http://www.videogameconsolelibrary.com/images/articles/mg-blogs/blog-2010-10-25-Prompt.gif" width=100% height=50% />

---

## 📋 Description:

<h3>The simple shell is a command line interface (CLI) program that takes commands from the keyboard and gives them to the operating system to perform.<h3/>

### Basic loop of a shell : REPL

1. Print prompt
2. Read a line from a standard input and parse it
3. Execute the command line
4. Loop and print the prompt again

### Files contents :card_index_dividers:

| File                                       | Description                                      |
| ------------------------------------------ | ------------------------------------------------ |
| [main Function](./main.c)                  | The main function                                |
| [Split Function](./split.c)                | Function that parse or split a line              |
| [Print Environment](./print_environment.c) | Function that print environment                  |
| [Get Path](./get_path.c)                   | Function that returns the path of a command line |
| [Execute Function](./execute.c)            | Function that executes a command line            |

### Simple Shell 🛠️:

- The prompt is displayed each time a command has been executed
- This program displays a prompt and wait for user type a command
- When the user type EXIT, shell will end and exit the interface
- The program print the current environement when user type ENV
- The program execute the most commun shell commands such as
  - ls
  - pwd
  - cd
  - exit
  - env
- The user could stop the program using **CTRL + D**

* I made this flowchart to explaine more whats happning

  <img src="https://scontent.ftun10-1.fna.fbcdn.net/v/t1.15752-9/318099785_3238372739759675_6411486135834890360_n.jpg?_nc_cat=107&ccb=1-7&_nc_sid=ae9488&_nc_ohc=v6Xox-mUd4QAX_cGIUh&_nc_ht=scontent.ftun10-1.fna&oh=03_AdRwOmbNfZ9P0f8sjkM1rP4tNnEGSi8kXKAhEnMCRXzjyA&oe=63B5B986" alt="flowchart" />

### For more information:

- [Manual page for Simple Shell](./man_1_simple_shell)

## List of allowed functions and system calls in this project :

```
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)
```

---

## 🔭 Compilation and testing

### Our compiler:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

```

### Testing

- Your \*shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

- But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

---

## License :busts_in_silhouette:

Authors :

- Wael Abidi < 5684@holbertonstudents.com >
- GitHub < https://github.com/weedii >
