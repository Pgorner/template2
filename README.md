Template Builder v.2.0
Template Builder is a command-line tool that can be used to create template files for C++ programs. It provides functionality to generate main files, class files, and a Makefile adhering to the Orthodox canonical class form and follows the Google C++ Style Guide.
Additionally, it sets up an alias in your .zshrc file, allowing you to execute the program from anywhere using the template command. The tool is designed to simplify the initial setup process by automating the creation of these files.

If wanted, it also includes the standard 42 header. You will have to modify the template.h accordingly.

The version 1.0 was written by @fsandel.

Prerequisites
To use the Class Template Generator, ensure that you have the following software installed on your system:

C++ compiler (GCC or Clang)
Zsh shell (for automatic alias setup)

Installation
Clone this repository to your local machine:
git clone https://github.com/fsandel/template template
Navigate to the project directory:
cd template
Build and install the program using the provided Makefile:
make install
This will create an alias named "template" that points to the executable file of the Class Template Generator.

Usage
The program will prompt you to choose between a full build or a single build. Enter either full or single to proceed.
Full Build: This option generates a Makefile and multiple class files as well as a main(.cpp and .hpp) based on your input.
Single Build: This option creates a single class file(.cpp and .hpp) based on your input.
Follow the on-screen instructions to provide the necessary input, such as program name and class names.
Once the files are generated, you will find the output files in the current directory.
Examples
Full Build
Here's an example of a full build using Template Builder:
------------------------------------------------------------------
|                Welcome to Template Builder                     |
------------------------------------------------------------------
|Template Builder can either create all necessary templates or   |
|just single ones.                                               |
|Full build means Makefile and any amount of classes with .cpp & |
|.hpp with OCC classes                                           |
|Single build means one class with matching .cpp & .hpp          |
|Type "single" for single build and "full" for full build        |
------------------------------------------------------------------
full
------------------------------------------------------------------
|                         full confirmed                         |
|                    -enter program name below-                  |
------------------------------------------------------------------
Programname
------------------------------------------------------------------
Program name: Programname
------------------------------------------------------------------
------------------------------------------------------------------
| Enter all needed class names seperated by spaces               |
| Press enter when done                                          |
------------------------------------------------------------------
class1 class2 class3
------------------------------------------------------------------
Class names:
class1
class2
class3
------------------------------------------------------------------
Making class:class1
Making class:class2
Making class:class3
------------------------------------------------------------------
|                     MAKEFILE ALREADY EXISTS                    |
------------------------------------------------------------------
------------------------------------------------------------------
|                     MAIN ALREADY EXISTS                        |
------------------------------------------------------------------
License
This project is licensed under the MIT License.

Feel free to customize and adapt the generated files to suit your needs. Happy coding!
