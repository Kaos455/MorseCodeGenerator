## MorseCodeGenerator

### Overview

**MorseCodeGenerator** is a Morse code generator developed in C++ , designed to translate typical **ASCII-identifiable characters** (A-Z, 0-9, ?!,.) into Morse code in real time. It features a simple GUI made with Dear ImGui where users can adjust the frequencies, dot and dash timings, and customise the output to create their own unique version of Morse code.

---
> **Note** - This Project is primarly for a University Assignment

### Features

- `ASCII to Morse code` translation.
  
- `Real-time` translations.
  
- Real-time Morse code readout (`Sound implementation`).
  
- Immediate mode `GUI`.
  
- Ability to adjust settings such as `frequencies` and `dot/dash timings`.
  
#### Additional Expected Features

- **Encryption** - `Encrypt` the input before translating to Morse code.
  
- **Export Capabilities** - `Export` the output in a printable format or WAV/MP3.

### Installation

To install the Morse Code Generator, follow these steps:
> **Note** - This project requires you have installed CMake and VCPKG
1. **Clone the Repository**:
```bash
git clone https://github.com/Kaos455/MorseCodeGenerator.git
cd MorseCodeGenerator
```
2. **Create build directory**:
```bash
mkdir build
cd build
```
3. **Install Directories and Build the project with CMake**
```bash
cmake -DCMAKE_TOOLCHAIN_FILE={PATH TO ROOT OF VCPKG}/scripts/buildsystems/vcpkg.cmake -S .. # Make sure to change {} to the root of vcpkg for example "C:Users/mark/vcpkg"
cmake --build . # add "--config release" to build release version"
```
4. **Run the application**:
```bash
.build\debug\MorseCodeGenerator.exe # if debug build
.build\release\MorseCodeGenerator.exe # if release build
```

### File Structure

- **MorseCodeGenerator/**: Root Directory of the project.
  - **src/**: Contains all source files (`.cpp` files) for the application.
  - **include/**: Header files (`.h` files) for the application, including dependencies.
  - **vendors/**: Contains third-party dependencies that VCPKG could not install or that need to be included manually.

### Technologies Used

- **CMake**: Used to build the project into an executable, providing a clear and flexible build configuration process that supports multiple platforms (if ever decided to push to other Operating Systems).
- **VCPKG**: Facilitates the dowloading of the dependencies required for the application, integrating with CMake seamlessly.
- **Dear ImGui**: Chosen for its ease of use as a GUI framework that does not require external dependencies. It offers the feature set necessary for the application and operates as an immediate mode GUI, simplifying devleopment. Although not providing much in terms of stylability, it provides an aethetic I enjoy.
- **PortAudio**: Utilised for real-time audio generation within the application, as well as generating the media sent to the exporter.
- **Mp3Lame**: Utilised for exporting to MP3 file format
- **GLFW + GLAD**: Since `Dear ImGui` is a framework that requires a backend, I chose to use OpenGL for its simplicity. Using GFLW and GLAD together to more easily use the OpenGL backend.

### Usage

The Morse Code Generator provides a simple interface that allows users to:

- **Translate ASCII characters to Morse code in real-time**: As you type in the input box, the Morse code will be displayed in the output box.

- **Adjust settings of Morse code such as Frequencies and Timings**: Adjust the frequency and timings of dots and dashes to make the Morse code sound unique when listening back within Application or exported audio.
  
- **Export results in various formats**:
  - **Printable Formats**: Save your Morse code output as text file (.txt) for easy printing or sharing.
  - **Audio Formats**: Export the Morse code output as WAV or MP3 files, allowing you to listen to the generated Morse code.

#### Example Workflow

1. Enter ASCII text in the input box.
2. Notice how the generated Morse code appears within the output box.
3. Use toolbar to find setting to adjust and adjust it to your liking.
4. Choose your preferred export format from the options provided.
5. Export the generated Morse code.

### Licensing

This project is licensed under the MIT License - See the LICENSE file for details

---
