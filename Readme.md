[![CMake](https://github.com/Sharkbyteprojects/consoleLoadingbar/actions/workflows/cmake.yml/badge.svg)](https://github.com/Sharkbyteprojects/consoleLoadingbar/actions/workflows/cmake.yml) [![CMake-Windows](https://github.com/Sharkbyteprojects/consoleLoadingbar/actions/workflows/cmake-win.yml/badge.svg)](https://github.com/Sharkbyteprojects/consoleLoadingbar/actions/workflows/cmake-win.yml) [![CodeQL](https://github.com/Sharkbyteprojects/consoleLoadingbar/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/Sharkbyteprojects/consoleLoadingbar/actions/workflows/codeql-analysis.yml)

---

# console loadingbar

## USAGE

To include the Lib, you need to `add_subdirectory("consoleLoadingbar")` in your `CMakeLists.txt` if you download this repo into `%yourProject%/consoleLoadingbar`.

You need to link `sharks::consoleLoadingBar` in your project

Include the loading bar header at the top of the C++ file where you like to use it (`#include <consoleLoadingBar.h>`)

Create a object of class (Example: `CloadingBarConsole bar`)

Now you can set the value of Percent: `bar.setPercent(30);`

You can also change the color of your bar with following colorcodes:

COLORCODE             | Color  | EXAMPLE
--------------------- | ------ | ---------
`colorcode::OK`       | Green  | `bar.setColorCode(colorcode::OK);` or `bar.setColorCode();`
`colorcode::SUSPEND`  | Yellow | `bar.setColorCode(colorcode::SUSPEND);`
`colorcode::CANCEL`   | Red    | `bar.setColorCode(colorcode::CANCEL);`



To see the Bar, render it after every change (or continuing in a seperate thread) render means also resizing to console window `bar.render();`

[EXAMPLE GIST](https://gist.github.com/Sharkbyteprojects/7340bfbff7e063fd0686ebf537e92ed8)


## Other Versions
- [MSBUILD DLL VERSION](https://github.com/Sharkbyteprojects/consoleLoadingBar-win) ([![MSBuild](https://github.com/Sharkbyteprojects/consoleLoadingBar-win/actions/workflows/msbuild.yml/badge.svg)](https://github.com/Sharkbyteprojects/consoleLoadingBar-win/actions/workflows/msbuild.yml) [![CodeQL](https://github.com/Sharkbyteprojects/consoleLoadingBar-win/actions/workflows/codeql.yml/badge.svg)](https://github.com/Sharkbyteprojects/consoleLoadingBar-win/actions/workflows/codeql.yml))

&copy; Sharkbyteprojects
