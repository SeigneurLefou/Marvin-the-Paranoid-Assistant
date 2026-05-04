#!/bin/bash
mkdir -p ~/.local/bin

# Add .local/bin to the PATH
export PATH="$PATH:$HOME/.local/bin/"
export MARV="$PWD/"

make build

# zsh install
echo "export PATH=\$PATH:\$HOME/.local/bin/" >> ~/.zshrc
echo "export MARV=$PWD" >> ~/.zshrc

# bash install
echo "export PATH=\$PATH:\$HOME/.local/bin/" >> ~/.bashrc
echo "export MARV=$PWD" >> ~/.bashrc

# global install
echo -e "Add this line to your shell config file\necho 'export PATH=\$PATH:\$HOME/.local/bin/'\necho 'export MARV=$PWD'"
