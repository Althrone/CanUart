子仓库都是通过'git submodule add https://github.com/xxx.git'的形式导入的
只适用于stm32g0b1，所以多余的启动文件都删了，但是保留了不同编译器的启动文件
git submodule add https://github.com/STMicroelectronics/cmsis-device-g0.git
这个基本只提供芯片头文件，启动代码不需要
git submodule add https://github.com/STMicroelectronics/cmsis-core.git
内核头文件
git submodule add https://github.com/STMicroelectronics/stm32g0xx-hal-driver.git
hal库
git submodule add https://github.com/modm-io/cmsis-svd-stm32.git
svd文件

cmsis-core

stm32g0xx-hal-driver

make的话用
cmake -B build -G "MSYS Makefiles"
cmake --build build

mingw32-make的话用
cmake -B build -G "MinGW Makefiles"

ninja的话用
cmake -B build -G Ninja