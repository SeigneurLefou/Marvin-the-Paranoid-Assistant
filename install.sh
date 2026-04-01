#!/bin/bash
# Move to home
mkdir -p ~/.local
mkdir -p ~/.local/bin
# Remove old .marvin
rm -rf ~/.marvin
# Clone the repo
mkdir -p ~/.marvin
cp -r .  ~/.marvin
# Move to .marvin
cd ~/.marvin

# Add .local/bin to the PATH
export PATH=$PATH:$HOME/.local/bin/
# For security add previous line in the config file
echo "export PATH=$PATH:$HOME/.local/bin/" >> ~/.zshrc
# For security add previous line in the config file
echo "export PATH=$PATH:$HOME/.local/bin/" >> ~/.bashrc
# Build the binary
make build
