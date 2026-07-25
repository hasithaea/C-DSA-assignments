#!/bin/bash
set -e

SOURCE="${BASH_SOURCE[0]}"
while [ -L "$SOURCE" ]; do
    DIR="$(cd -P "$(dirname "$SOURCE")" >/dev/null 2>&1 && pwd)"
    SOURCE="$(readlink "$SOURCE")"
    [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
done
ROOT_DIR="$(cd -P "$(dirname "$SOURCE")" >/dev/null 2>&1 && pwd)"

CURRENT_DIR="$(pwd)"

if [ "$CURRENT_DIR" != "$ROOT_DIR" ] && [ ! -e "$CURRENT_DIR/builder.sh" ]; then
    REL_TO_ROOT="$(python3 -c "import os; print(os.path.relpath('$ROOT_DIR', '$CURRENT_DIR'))" 2>/dev/null || realpath --relative-to="$CURRENT_DIR" "$ROOT_DIR")"
    ln -s "$REL_TO_ROOT/builder.sh" "$CURRENT_DIR/builder.sh"
    echo "Set up builder.sh symlink in $CURRENT_DIR"
fi

CFILE=$(find . -maxdepth 1 -name "*.c" | head -n 1)

if [ -z "$CFILE" ]; then
    echo "No .c file found in current directory."
    exit 1
fi

REL_PATH="${CURRENT_DIR#$ROOT_DIR/}"
FILE_NAME="$(basename "$CFILE" .c)"

OUT_NAME=$(echo "$REL_PATH/$FILE_NAME" | sed 's#/#_#g')
OUT="$ROOT_DIR/compiled-files/$OUT_NAME"

mkdir -p "$ROOT_DIR/compiled-files"

gcc "$CFILE" -o "$OUT"
echo "Build successful."
echo "Running..."
echo ""
"$OUT"
echo ""