# NechiOS

«A custom operating system built from scratch using C and Assembly.»

---

About the Project

NechiOS is an operating system developed from scratch by me.
The main goals of the project:

* Create a custom kernel and system components
* Learn low-level programming
* Build a platform for applications and games using the ".nechi" format

---

Current Status

The project is currently in an early stage of development.

Implemented

* ✅ GRUB booting
* ✅ Multiboot support
* ✅ GDT
* ✅ Kernel entry
* ✅ ISO building
* ✅ Running through QEMU

Planned Features

* 🔲 IDT
* 🔲 Interrupt handling
* 🔲 Memory manager
* 🔲 File system
* 🔲 Device drivers
* 🔲 Graphical interface

---

🛠 Requirements

To build NechiOS, you will need:

qemu
gcc
ld
nasm
grub
make

🔧 Installing Tools

Ubuntu / Debian / WSL

Update packages:

sudo apt update

Install required tools:

sudo apt install build-essential gcc nasm grub-pc-bin xorriso qemu-system-x86 make

Check installation:

gcc --version
nasm -v
qemu-system-i386 --version
grub-mkrescue --version

---

Arch Linux

sudo pacman -S gcc nasm grub xorriso qemu make

---

Fedora

sudo dnf install gcc nasm grub2-tools xorriso qemu-system-x86 make

---

Windows

Using WSL (Windows Subsystem for Linux) is recommended.

1. Open PowerShell as Administrator.
2. Run:

wsl --install

3. Restart your computer.
4. Open Ubuntu and follow the instructions from the Ubuntu / Debian section.

---

Verification

After installing all dependencies, run:

make all
make run

If the system starts in QEMU, everything is configured correctly.

---

📦 Building

Create an ISO image:

make all

Run in QEMU:

make run

Clean temporary files:

make clean

---

🤝 Contributing

If you are interested in operating system development, low-level programming in C and Assembly, contributions are welcome.

You can:

* Fix bugs
* Improve kernel code
* Add new features
* Improve documentation

All contributors will be listed in a separate file in the project.

---

Author

Development started on June 16, 2026.

Owner: NechiGames

Main Developer (Lead Contributor): NechiCyber

---

«You can be a user or a contributor — everyone is welcome.
Also, use VS Code, because this operating system was created using it.»