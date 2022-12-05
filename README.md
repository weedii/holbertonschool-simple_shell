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

| File               | Description       |
| ------------------ | ----------------- |
| [main.c](./main.c) | The main function |
| ...                | ...               |

### Simple Shell :shell:

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
- The program quit when the user enter **CTRL + C**
- The user could stop the program using **CTRL + D**

* I made this flowchart to explaine more whats happning

  <img src="https://scontent.ftun10-1.fna.fbcdn.net/v/t1.15752-9/318099785_3238372739759675_6411486135834890360_n.jpg?_nc_cat=107&ccb=1-7&_nc_sid=ae9488&_nc_ohc=v6Xox-mUd4QAX_cGIUh&_nc_ht=scontent.ftun10-1.fna&oh=03_AdRwOmbNfZ9P0f8sjkM1rP4tNnEGSi8kXKAhEnMCRXzjyA&oe=63B5B986" alt="flowchart" />
