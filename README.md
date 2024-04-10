Install CMake: You can download the installer from the CMake website and follow the installation instructions provided there.

Add CMake to PATH:

On Windows:
During installation, there's an option to add CMake to the system PATH. Make sure this option is selected.
If you've already installed CMake without adding it to PATH, you can manually add it:
Open Control Panel -> System -> Advanced System Settings -> Environment Variables.
In the System Variables section, find the PATH variable and click Edit.
Add the path to the CMake binaries directory (typically C:\Program Files\CMake\bin) to the list of paths. Make sure to separate it from other paths with a semicolon.

On Unix-like systems (Linux, macOS):
You can install CMake using your package manager (e.g., sudo apt-get install cmake on Ubuntu).
After installation, CMake should be automatically added to your PATH. You can verify by running cmake --version in your terminal.
Once you've installed CMake and added it to your PATH, you should be able to run the cmake command successfully to generate build files for your project.




How run without shell file
1. create a build directory inside the project( mkdir -p build)
2. change the directory to build( cd build)
3. cmake ..
4. make
5. ./main

How to run with shell file
1. sh build_project.sh

