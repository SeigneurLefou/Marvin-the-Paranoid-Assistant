#!/bin/bash
# Move to home
cd ~
# Clone the repo
git clone https://www.github.com/SeigneurLefou/Marvin-the-Paranoid-Assistant .marvin
# Move to .marvin
cd .marvin
# Build the binary
make build
# Add .local/bin to the PATH
export PATH=$PATH:$HOME/.local/bin/
