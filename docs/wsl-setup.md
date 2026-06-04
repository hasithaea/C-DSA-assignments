# WSL Development Environment Setup

This repository was developed and tested using Ubuntu on Windows Subsystem for Linux (WSL).

## Prerequisites

- Windows 10 (version 2004+) or Windows 11
- Administrator privileges

## 1. Install WSL

Open PowerShell as Administrator and run:

```powershell
wsl --install
```

Restart your computer if prompted.

## 2. Launch Ubuntu

Open Ubuntu from the Start Menu.

During the first launch, create:

- Username
- Password

## 3. Update the System

```bash
sudo apt update
sudo apt upgrade -y
```

## 4. Install GCC

```bash
sudo apt install build-essential -y
```

Verify the installation:

```bash
gcc --version
```

## 5. Install Git

```bash
sudo apt install git -y
```

Verify:

```bash
git --version
```

## 6. Install Visual Studio Code

Download and install Visual Studio Code.

Install the following extension:

- WSL (Microsoft)

Open your project from WSL:

```bash
code .
```

## 7. Compile and Run C Programs

Compile:

```bash
gcc filename.c -o program
```

Run:

```bash
./program
```

## Example

```bash
gcc queue.c -o queue
./queue
```