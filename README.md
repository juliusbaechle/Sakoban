# CMake project template

The following files must be added, to complete the template:

-   .clang-format
-   .gitignore

# CMake Template

Dieses Template wird ab sofort als Vorlage für Projekte (Applikationen und Libraries) verwendet.
Einschränkung: nur Qt-Apps/Libs.

# CMake Erklärt

## Projekte und Artefakte

CMake erstellt mit `project()` ein Projekt. Dieses kann beliebig viele Applikationen `add_executable(appname main.cpp)` und Libraries `add_library(libname file1.cpp file2.cpp)` erzeugen. Die Abhängigkeiten zueinander löst CMake selbst auf indem man `target_link_libraries(appname libname)` verwendet.

Zusatz: Nach dem Build können Post-Build-Schritte hinzugefügt werden, die z.B. die Artefakte in einen bestimmten Ordner kopieren.

## CMakeLists.txt - Hierarchie

Da die komplette Definition eines Projektes üblicherweise nicht in einer einzigen Datei in einem Ordner liegt, muss eine Hierarchie geschaffen werden. Ein Modul (App oder Lib) wird normalerweise in einem Ordner mit Sourcen, Tests, Benchmarks etc. und der CMake-Definition abgelegt. Die übergeordnete CMakeLists.txt hat dann einen Verweis auf den Modul-Pfad der App oder der Lib `add_subdirectory(path_to_module)`. Variablen und Optionen werden vererbt und können wiederverwendet werden.

```text
Z://Plattform/Git
├── app1/
|   ├── app/
|   |   ├── CMakesLists.txt
|   |   |   // add_executable(app1 ../src/main.cpp),target_link_libraries(app1 lib1)
|   |   └── main.cpp
|   ├── benchmarks/
|   ├── build/
|   ├── cmake/
|   |   ├── General/
|   |   |   └── Warnings.cmake, CodeCoverage.cmake, Documentation.cmake, ...
|   |   ├── Qt/
|   |   |   └── QtConfiguration.cmake, QtHelperFuntions.cmake
│   |   ├── IncludeDirs.cmake
│   |   └── Sources.cmake
│   ├── docs/
|   |   └── Doxyfile, ...
│   ├── external/
│   ├── src/
|   |   └── foo.cpp, bar.cpp, ...
│   ├── tests/
│   ├── .clang-format
│   ├── .gitignore
│   ├── CMakesLists.txt
│   │    // project(app1), add_subdirectory(submodules/lib1), ...
│   ├── LICENSE
│   └── README.md
|
├── submodules/lib1/
|   ├── benchmarks/
|   ├── cmake/
|   |   ├── General/
|   |   |   └── Warnings.cmake, CodeCoverage.cmake, Documentation.cmake, ...
|   |   ├── Qt/
|   |   |   └── QtConfiguration.cmake, QtHelperFuntions.cmake
│   |   ├── IncludeDirs.cmake
│   |   └── Sources.cmake
│   ├── docs/
|   |   └── Doxyfile, ...
│   ├── external/
│   ├── src/
|   |   └── foo.cpp, bar.cpp, ...
│   ├── submodules/
|   |   ├── lib2/ // Referenz auf submodule commit (optional)
|   |   └── ...
│   ├── tests/
│   ├── .clang-format
│   ├── .gitignore
│   ├── .gitsubmodules
│   ├── CMakesLists.txt
│   │    // add_library(lib1 SHARED foo.cpp bar.cpp), ...
│   ├── LICENSE
│   └── README.md
|
├── .gitattributes
├── .gitmodules
├── README.md
├── ...
```
