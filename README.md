# 🐚 Prash:) Mini Shell in C

A lightweight custom **Linux shell** written in **C**, designed to mimic basic Bash functionality.  
It supports running system commands, built-in commands, and maintains a command history — all in a simple, educational implementation.

---

## 🚀 Features

- Execute system commands (`ls`, `pwd`, `cat`, `echo`, etc.)
- Built-in commands:
  - `cd <dir>` → Change directory  
  - `help` → Display available commands  
  - `clear` → Clear the terminal  
  - `history` → Show previous commands  
  - `exit` → Exit the shell
- Command history (stores last 100 commands)
- Simple, clean, and easy to extend

---

## ⚙️ Installation & Usage

```bash
git clone https://github.com/<your-username>/mini-shell.git
cd mini-shell
make
./shell

## 💻 Example Usage (Demo)

> Quick demo of **PrashShell** in action:

```bash
prash:) > help
Mini Shell Commands:
  cd <dir>     - change directory
  history      - show command history
  clear        - clear the screen
  help         - show this help message
  exit         - exit the shell
You can also run external commands like ls, cat, echo, etc.

prash:) > pwd
/home/user/projects/prashshell

prash:) > ls
shell.c  README.md  Makefile

prash:) > history
1: help
2: pwd
3: ls
4: history

prash:) > cd /tmp
prash:) > pwd
/tmp

prash:) > exit
