# Bizi Compiler — Low-Level Compiler

Bizi is a modular compiler designed to translate custom `.bizi` syntax into standard Intel x86 assembly code (NASM) that supports the **Multiboot** boot standard.

## 📥 How to Download and Install

You can download, build, and install the `bizi` compiler as a system utility to run it from any directory.

### 1. Clone the Repository and Navigate to the Folder
Open your terminal and run the following commands:
```bash
git clone https://github.com
cd bizi

```

### 2. Build the Compiler

Compile the C source files using `gcc`:

```bash
gcc bizi.c codegen.c commands.c -o bizi

```

### 3. Install to the System (Global Access)

Copy the executable file to the `/usr/local/bin/` directory. This allows you to run the `bizi` command anywhere in the terminal without specifying the `./` path:

```bash
sudo cp bizi /usr/local/bin/

```

### 4. Verify Installation

Now you can verify the compiler works from any folder on your computer:

```bash
bizi

```

If everything is done correctly, the utility will display usage instructions (`Usage:...`).

## 🚀 Quick Start

### 1. Compiling the Compiler Itself

Build the project from the C source files using `gcc`:

```bash
gcc bizi.c codegen.c commands.c -o bizi

```

### 2. The Two-Step Build Process for Your Code

The compiler operates in two modes depending on the flags used:

**Step 1: Generating the Intermediate File (`-o`)**
Analyzes the source code and creates an optimized intermediate code file.

```bash
bizi bizi/mboot.bizi -o out

```

**Step 2: Generating the Final Assembly (`-a`)**
Converts the intermediate file into a ready-to-use `.asm` file. If the destination folder (e.g., `multiboot/`) does not exist, the compiler will create it automatically.

```bash
bizi out -a multiboot/boot.asm

```

---

## 📝 Bizi Language Syntax

Files with the `.bizi` extension support a set of commands to manage the kernel binary structure and low-level CPU instructions.

| Command in `.bizi` | Result in `.asm` (NASM) | Description |
| --- | --- | --- |
| `multiboot` | `section .multiboot` | Multiboot header section |
| `stext` | `section .text` | Main code section |
| `globalST` | `global _start` | Declares the global entry point |
| `ST: ` | `_start:` | Label for the start of program execution |
| `extern [name]` | `extern [name]` | Includes an external function (e.g., from C) |
| `call [name]` | `call [name]` | Function call |
| `jmp [label]` | `jmp [label]` | Unconditional jump |
| `align [number]` | `align [number]` | Memory data alignment |
| `cli` | `cli` | Disables hardware interrupts |
| `hlt` | `hlt` | Halts the CPU |
| `; [text]` | `; [text]` | Single-line comment |
| `[name]:` | `[name]:` | Custom user label |

### Special Arguments for the `dd` (Data) Command

To simplify creating a Multiboot kernel, the `dd` command automatically calculates the bootloader's magic structures:

* `dd MAGIC` ➡️ Becomes `dd 0x1BADB002` (Multiboot magic number)
* `dd FLAG` ➡️ Becomes `dd 0` (Boot flags)
* `dd CHECKSUM` ➡️ Becomes `dd -(0x1BADB002)` (Checksum)
* `dd [number]` ➡️ Becomes `dd [number]` (Any other numerical value)

---

## 🛠 Project Architecture

The compiler code is split into isolated modules, making it easy to add new commands without modifying the core parser logic.

```text
├── bizi.c       # Entry point. Manages flags (-o, -a) and operating modes.
├── codegen.c    # Parser engine. Reads lines, manages directories and the command table.
├── commands.c   # Command implementation. Each command is an isolated function.
└── commands.h   # Header file. Command structure and function prototypes.

```

### How to Add a New Command to the Compiler?

1. **In the `commands.c` file**, write the handler function:
```c
void handle_mov(const char *arg, FILE *boot) {
    fprintf(boot, "mov %s\n", arg);
}

```



```
2. **In the `commands.h` file**, register its prototype:
c
   void handle_mov(const char *arg, FILE *boot);

```

3. **In the `codegen.c` file**, add the keyword and function to the `cmd_table`:
```c
static Command cmd_table[] = {
    ...
    {"mov ", handle_mov},
};

```



```

### TERMINAL COMMANDS

1. `bizi -v` - displays the **specific version** of the compiler


```