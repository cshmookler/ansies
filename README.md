# **ANSI Escape Sequences**
A cross-platform C++ library for using ANSI escape sequences. Supported on Windows and Unix-like operating systems.

### **Build from source and install using Conan 2 (for Unix-like systems)**
**1.** Install a C++ compiler (Example: g++), Git, Python >=3.7, and the Python Virtual Environment using the system package manager (Example: apt).
```bash
$ sudo apt install g++ git python3 python3-venv
```
**2.** Create a Python >=3.7 virtual environment and activate it.
```bash
$ python3 -m venv venv
$ source venv/bin/activate
```
**3.** Install Conan 2.
```bash
$ pip3 install "conan>=2.0.0"
```
**4.** Create the default Conan profile. Ensure that it is configured to use C++11 or higher.
```bash
$ conan profile detect
```
**5.** Clone the ansies git repository and enter the root directory of the project.
```bash
$ git clone https://github.com/cshmookler/ansies.git
$ cd ansies
```
**6.** Build and install this project with Conan 2.
```bash
$ conan create .
```

### **Build from source and install using Conan 2 (for Windows)**
**1.** Download and install a C++ compiler that supports C++11 or higher (Example: MSVC).

**2.** Download and install Python >=3.7 from https://www.python.org/downloads/ (Make sure you add python.exe to your PATH during installation!).

**3.** Download and install the latest version of Git from https://git-scm.com/downloads.

**4.** Open a new command prompt window by pressing the super key, typing `cmd`, and pressing enter. Then use the `cd` command to navigate to your downloads folder.
```shell
> cd Downloads
```
**5.** Clone the ansies git repository and enter the root directory of the project.
```shell
> git clone https://github.com/cshmookler/ansies.git
> cd ansies
```
**6.** Create a Python >=3.7 virtual environment and activate it.
```shell
> python -m venv venv
> .\venv\Scripts\Activate.bat
```
**7.** Install Conan 2.
```shell
> pip install "conan>=2.0.0"
```
**8.** Create the default Conan profile. It should detect the C++ compiler you installed earlier. Ensure that it is configured to use C++11 or higher.
```shell
> conan profile detect
```
**9.** Build and install this project with Conan 2.
```bash
> conan create .
```