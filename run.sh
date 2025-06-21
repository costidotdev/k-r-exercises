#!/bin/bash

# Default values
SRC="main.cpp"
OUT="main"
INPUT=""
DEBUG=0

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -s|--src)
            SRC="$2"
            shift 2
            ;;
        -o|--out)
            OUT="$2"
            shift 2
            ;;
        -i|--input)
            INPUT="$2"
            shift 2
            ;;
        -g|--debug)
            DEBUG=1
            shift
            ;;
        -h|--help)
            echo "Usage: $0 [OPTIONS]"
            echo "Options:"
            echo "  -s, --src FILE      Source file (default: main.cpp)"
            echo "  -o, --out FILE      Output executable (default: main)"
            echo "  -i, --input FILE    Input text file to pass to program"
            echo "  -g, --debug         Enable debugging symbols (-g flag for g++)"
            echo "  -h, --help          Show this help message"
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            echo "Use -h or --help for usage information"
            exit 1
            ;;
    esac
done

# Check if source file exists
if [ ! -f "$SRC" ]; then
    echo "Error: Source file '$SRC' not found"
    exit 1
fi

# Compile if source is newer than output or output doesn't exist
if [ "$SRC" -nt "$OUT" ] || [ ! -f "$OUT" ]; then
    echo "Compiling $SRC..."
    CXXFLAGS="-std=c++17 -O2"
    [[ $DEBUG -eq 1 ]] && CXXFLAGS="-std=c++17 -O0 -g" || CXXFLAGS="-std=c++17 -O2"
    g++ $CXXFLAGS "$SRC" -o "$OUT"
    if [ $? -ne 0 ]; then
        echo "Compilation failed"
        exit 1
    fi
fi

# Run the program
echo "Running $OUT..."
if [ -n "$INPUT" ]; then
    if [ ! -f "$INPUT" ]; then
        echo "Error: Input file '$INPUT' not found"
        exit 1
    fi
    ./"$OUT" < "$INPUT"
else
    ./"$OUT"
fi
