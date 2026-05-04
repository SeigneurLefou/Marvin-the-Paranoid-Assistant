BASE_DIR="${MARV:-.}"
BUNDLE_DIR="$BASE_DIR/bundle"

mkdir -p "$BUNDLE_DIR/bin" "$BUNDLE_DIR/src"

if [ -z "$1" ]; then
    echo "Usage: $0 utilisateur/depot"
    exit 1
fi

REPO_PATH="$BUNDLE_DIR/src/$1"

if [[ -d "$REPO_PATH" ]]; then
    rm -rf "$REPO_PATH"
fi

echo "Clonage de $1..."
git clone "https://github.com/$1" "$REPO_PATH"

if [[ $? -ne 0 ]]; then
    echo -e "\e[31mError: There is no reference of $1\e[0m"
    exit 1
fi

echo "Compilation..."
make MARV="$MARV" -C "$REPO_PATH" marvinstall

if [[ $? -eq 0 ]]; then
    if [ -d "$REPO_PATH/bin" ]; then
        cp "$REPO_PATH/bin/"* "$BUNDLE_DIR/bin/"
        echo -e "\e[32mInstall working !\e[0m"
    else
        echo -e "\e[33mWarning: No bin directory found in the source\e[0m"
    fi
else
    echo -e "\e[31mError: Make failed\e[0m"
    exit 1
fi
