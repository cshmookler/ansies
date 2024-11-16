# **ansies**

A header-only C++ library for using ANSI escape sequences. Supported on Windows and Unix-like operating systems.

## Build from Source

### 1.&nbsp; Install a C++ compiler, Git, and Python.

#### Windows:

Install ONE of the following C++ compilers:

- [Visual Studio's C++ compiler](https://visualstudio.microsoft.com/downloads/) (MSVC)
    - Select the "Desktop development with C++" option.
- [MinGW](https://sourceforge.net/projects/mingw/) (GCC for Windows)
    - Mark "mingw32-gcc-g++" for installation. Then select "Apply Changes" within the "Installation" dropdown.
    - Add the MinGW bin directory (C:\\MinGW\\bin\\) to your [PATH](https://stackoverflow.com/questions/5733220/how-do-i-add-the-mingw-bin-directory-to-my-system-path).

Install Git and Python:

1. [Git](https://git-scm.com/downloads/) (distributed version control)
2. [Python](https://python.org/downloads/) (interpreted scripting language)
    - Select the "Add python.exe to PATH" option.

#### Mac:

Install [Homebrew](https://brew.sh/) (package manager for Mac) by opening a terminal and entering the following command:

```zsh
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Use Homebrew to install Git, Python, and GCC (C++ compiler):

```zsh
brew install git python gcc
```

#### Linux (Ubuntu):

```bash
sudo apt install git python3 build-essential
```

#### Linux (Arch):

```bash
sudo pacman -S git python base-devel
```

### 2.&nbsp; Clone this project.

Open command prompt (Windows) or a shell (Linux & Mac) and enter the commands below. This project will be downloaded to the current working directory.

```
git clone https://github.com/cshmookler/ansies.git
cd ansies
```

> NOTE: This project must be cloned with Git. Do NOT download this project from a hosting platform (e.g. GitHub) because the .git folder will not be included. Project versioning depends on the contents of the .git folder. If the .git folder is missing or corrupted (or Git is not installed) this project will be assigned a null version of "0.0.0".

### 3.&nbsp; Build this project from source.

```
python build.py
```

### 4.&nbsp; (Optional) Install this project globally.

```
python install.py
```

## **TODO**

- [X] Add basic ANSI escape codes for modifying terminal colors.
