<div align="center">

# NechiOS

</div>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg">
  <img src="https://img.shields.io/badge/Assembly-NASM-orange.svg">
  <img src="https://img.shields.io/badge/Bootloader-GRUB-green.svg">
  <img src="https://img.shields.io/badge/Platform-x86-lightgrey.svg">
  <img src="https://img.shields.io/badge/Status-Early%20Development-yellow.svg">
</p>

> *A custom operating system built from scratch using C and Assembly.
BIZI COMPILE TUTOR FOR CONTRIBUTERS - https://github.com/NechiGames/NechiOS/blob/main/BIZI.md*

---

## About the Project

NechiOS is an operating system developed from scratch by me.

The main goals of the project:

* Create a custom kernel and system components
* Learn low-level programming
* Build a platform for applications and games using the ".nechi" format

---

## Current Status

The project is currently in an early stage of development.

### Development Progress

| Component            | Status   |
| -------------------- | -------- |
| GRUB booting         | Complete |
| Multiboot support    | Complete |
| GDT                  | Complete |
| Kernel entry         | Complete |
| ISO building         | Complete |
| Running through QEMU | Complete |
| IDT                  | Planned  |
| Interrupt handling   | Planned  |
| Memory manager       | Planned  |
| File system          | Planned  |
| Device drivers       | Planned  |
| Graphical interface  | Planned  |

---

## Project Structure

```text
NechiOS/
├── include/          # Header files
│   ├── keyboard/
│   └── lib/
├── kernel/           # Kernel source code
│   ├── keyboard/
│   └── lib/
├── multiboot/        # Boot and GDT assembly code
├── Makefile          # Build system
├── linker.ld         # Linker script
└── README.md
```
---

## 🛠 Requirements & Installation

To build and run **NechiOS**, ensure you have the following prerequisites installed:

* `gcc` & `ld` (GNU Compiler Collection & Linker)
* `nasm` (Netwide Assembler)
* `make` (GNU Build Automation Tool)
* `grub` (GRUB Bootloader Utilities)
* `xorriso` (ISO Image Creation Tool)
* `qemu` (Processor Emulator)

Choose your operating system below to install all dependencies at once.

### 🐧 Ubuntu / Debian / WSL

```bash
sudo apt update && sudo apt install -y build-essential gcc nasm grub-pc-bin xorriso qemu-system-x86 make
```

### 🦥 Arch Linux

```bash
sudo pacman -Syu --needed gcc nasm grub xorriso qemu make
```

### 🎩 Fedora

```bash
sudo dnf install -y gcc nasm grub2-tools xorriso qemu-system-x86 make
```

### 🪟 Windows

Using **WSL (Windows Subsystem for Linux)** is highly recommended.

1. Open **PowerShell** as Administrator and run:

```powershell
wsl --install
```

2. Restart your computer.
3. Open the installed Ubuntu distribution and follow the **Ubuntu / Debian** instructions above.

---

## 🔍 Verification & Running

After installation, verify that everything is configured correctly by booting the system in QEMU:

```bash
make all
make run
```

---

## 📦 Build Commands

### Create an ISO image

```bash
make all
```

### Run the system in QEMU

```bash
make run
```

### Clean temporary build files

```bash
make clean
```

---

## 🤝 Contributing

If you are interested in operating system development, low-level programming in C and Assembly, contributions are welcome.

You can:

* Fix bugs
* Improve kernel code
* Add new features
* Improve documentation

All contributors will be listed in a separate file in the project.

---

## Author

Development started on June 16, 2026.

**Owner:** NechiGames

**Main Developer (Lead Contributor):** NechiCyber

---

> *You can be a user or a contributor — everyone is welcome.*
>
> *Also, use VS Code, because this operating system was created using it.*
