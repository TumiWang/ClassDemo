
cd $(dirname "$0")
SCRIPT_DIR=`pwd`
PRUDOCT_DIR=product
BUILD_DIR=build
BUILD_TYPE=Release

if [ -d "$PRUDOCT_DIR" ]; then
    rm -rf "$PRUDOCT_DIR"
fi

if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi

# cmake -B "$BUILD_DIR" -S . -DCMAKE_BUILD_TYPE=$BUILD_TYPE
cmake -B "$BUILD_DIR" -S . -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DMYTARGET=test4_1

cmake --build "$BUILD_DIR"

cmake --install "$BUILD_DIR" --prefix "$SCRIPT_DIR/$PRUDOCT_DIR"
