````markdown
# Bizi Compiler — Low-Level Compiler

Bizi is a modular compiler designed to translate a custom `.bizi` syntax into standard Intel x86 assembly code (NASM), supporting the **Multiboot** boot standard.

## 📥 Download and Installation

You can download, build, and install the `bizi` compiler as a system utility so it can be used from any directory.

### 1. Clone the repository and enter the folder
```bash
git clone https://github.com
cd bizi
````

### 2. Build the compiler

```bash
gcc bizi.c codegen.c commands.c -o bizi
```

### 3. Install globally

```bash
sudo cp bizi /usr/local/bin/
```

### 4. Check installation

```bash
bizi
```

---

## 🚀 Quick Start

### Build compiler

```bash
gcc bizi.c codegen.c commands.c -o bizi
```

### Two-stage compilation

```bash
bizi bizi/mboot.bizi -o out
bizi out -a multiboot/boot.asm
```

---

## 📝 Bizi Language Syntax

| Command       | NASM Output        | Description              |
| ------------- | ------------------ | ------------------------ |
| multiboot     | section .multiboot | Multiboot header section |
| stext         | section .text      | Main code section        |
| globalST      | global _start      | Entry point              |
| ST:           | _start:            | Start label              |
| extern [name] | extern [name]      | External function        |
| call [name]   | call [name]        | Function call            |
| jmp [label]   | jmp [label]        | Jump                     |
| align [n]     | align [n]          | Alignment                |
| cli           | cli                | Disable interrupts       |
| hlt           | hlt                | Halt CPU                 |
| ; text        | ; text             | Comment                  |
| name:         | name:              | Label                    |

---

## 🧠 dd rules

* dd MAGIC → dd 0x1BADB002
* dd FLAG → dd 0
* dd CHECKSUM → dd -(0x1BADB002)
* dd number → dd number

---

## 🛠 Architecture

```
├── bizi.c
├── codegen.c
├── commands.c
└── commands.h
```

---

## ➕ Add command

### commands.c

```c
void handle_mov(const char *arg, FILE *boot) {
    fprintf(boot, "mov %s\n", arg);
}
```

### commands.h

```c
void handle_mov(const char *arg, FILE *boot);
```

### codegen.c

```c
static Command cmd_table[] = {
    {"mov ", handle_mov},
};
```

---

## 🖥 Commands

```bash
bizi -v
```

```
```
