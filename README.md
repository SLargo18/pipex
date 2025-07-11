# 🔗 pipex

## 📌 Description

`pipex` is a simplified recreation of the Unix shell's pipeline behavior. It executes a series of commands connected by pipes (`|`), handling input and output redirection between them using file descriptors and process forking.

This project focuses on low-level programming in C, including system calls like `fork()`, `pipe()`, `dup2()`, and `execve()`.

---

## 🛠️ Skills Developed

- Inter-process communication with `pipe()`
- Process creation with `fork()` and execution with `execve()`
- File descriptor duplication with `dup2()`
- Error handling and memory management
- Parsing and handling command-line arguments
- Understanding of Unix shell behavior

---

## ⚙️ Compilation

```bash
make
