
cd $(dirname "$0")
SCRIPT_DIR=`pwd`
PRUDOCT_DIR=product
BUILD_DIR=build
# BUILD_TYPE=Release
BUILD_TYPE=Debug

if [ -d "$PRUDOCT_DIR" ]; then
    rm -rf "$PRUDOCT_DIR"
fi

if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi

if [ $# == 2 ]; then
    cmake -B "$BUILD_DIR" -S . -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DMYTARGET=test$1_$2
elif [ $# == 0 ]; then
    cmake -B "$BUILD_DIR" -S . -DCMAKE_BUILD_TYPE=$BUILD_TYPE
elif [ $# == 1 ]; then
    if [ ! -f "./complex/$1/CMakeLists.txt" ]; then
        echo "\033[31mCMakeLists.txt文件不存在\033[0m"
        exit 0
    fi
    cmake -B "$BUILD_DIR" -S "./complex/$1" -DCMAKE_BUILD_TYPE=$BUILD_TYPE
else
    echo "\033[31m参数不符合预期\033[0m"
    exit 0
fi

if [ $? != 0 ]; then
    echo "\033[31mcmake创建项目失败\033[0m"
    exit $?
fi

cmake --build "$BUILD_DIR"

if [ $? != 0 ]; then
    echo "\033[31mcmake编译失败\033[0m"
    exit $?
fi

cmake --install "$BUILD_DIR" --prefix "$SCRIPT_DIR/$PRUDOCT_DIR"

if [ $? != 0 ]; then
    echo "\033[31mcmake安装失败\033[0m"
    exit $?
fi
