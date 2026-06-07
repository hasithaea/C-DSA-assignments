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

### Download and install Visual Studio Code.

Install the following extension:

- WSL (Microsoft)

### Open the Project in Visual Studio Code with WSL

Follow these steps to open your project in Visual Studio Code using the Windows Subsystem for Linux (WSL):

1. Open **Windows Terminal**, **PowerShell**, or **Command Prompt**.

2. Start your WSL environment by running:

   ```bash
   wsl
   ```

3. Navigate to your project folder using one of the following methods:

   **Option 1: Open WSL Directly from File Explorer**

   * Open your project folder in File Explorer.
   * Click the address bar at the top of the window.
   * Type `wsl` and press **Enter**.
   * A WSL terminal will open in the current directory.

   **Option 2: Navigate Manually in WSL**

   Use the `cd` command to move to your project directory:

   ```bash
   cd /path/to/project
   ```

   Example:

   ```bash
   cd ~/projects/my-app
   ```

4. Once you are inside the project directory, open it in Visual Studio Code:

   ```bash
   code .
   ```

5. Visual Studio Code will launch and connect to the WSL environment, allowing you to edit, build, and run your project directly from Linux.

> **Note:** If the `code` command is not available, ensure that Visual Studio Code is installed and that the **WSL extension** is installed and enabled.


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
