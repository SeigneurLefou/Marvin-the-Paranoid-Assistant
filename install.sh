#!/bin/bash
# Move to home
cd ~
mkdir -p .local
mkdir -p .local/bin
# Remove old .marvin
rm -Rf .marvin
# Clone the repo
git clone https://www.github.com/SeigneurLefou/Marvin-the-Paranoid-Assistant .marvin
# Move to .marvin
cd .marvin

# Add .local/bin to the PATH
export PATH=$PATH:$HOME/.local/bin/
export MARV=$HOME/.marvin/
# For security add previous line in the config file
echo 'export PATH=$PATH:$HOME/.local/bin/' >> ~/.zshrc
echo 'export MARV=$HOME/.marvin' >> ~/.zshrc
# For security add previous line in the config file
echo 'export PATH=$PATH:$HOME/.local/bin/' >> ~/.bashrc
echo 'export MARV=$HOME/.marvin' >> ~/.bashrc
# Build the binary
make build
