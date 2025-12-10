# Marvin the Paranoid Assistant

Marvin is a personal assistant designed to automate tasks or create macros in Python, and soon in Bash, C, and C++. Macros are functions in a supported language that Marvin includes in his code as a subcommand. You can also use basic commands like `marvin albbl "text"` in your `.bashrc` or `.zshrc` by defining simple functions. Macros are just one part of Marvin's capabilities—over time, you could even code a game and integrate it into Marvin using `sys` and importing different files.

## Commands

| Command | Description |
| --- | --- |
|  |  |

## Download

For download Marvin you need to use this command in your shell terminal.
```bash
# Clone the repo
git clone https://www.github.com/SeigneurLefou/Marvin-the-Paranoid-Assistant .marvin
# Move in the folder
cd .marvin
# Build the binary
make build
```

## User Contributions

If you have ideas for useful commands or features, feel free to open an issue to present your suggestion ! If the idea you suggest is not universal, give it as an add-on.

## Principal Roadmap

- [x] Add download script with export in PATH
- [ ] Add graphic annotation to the build and remove functions
- [ ] Add PWD variable in the Makefile for a deinstall command more powerful

## Basic Command Roadmap

- [ ] Add basic printable commands like `bbl`, `albbl`, ou `show`
- [ ] Add `emot` command
- [ ] Add `shutdown` command
- [ ] Add `reboot` command
- [ ] Add `timer` command
- [ ] Add `date` commande with flag for syntaxe
- [ ] Add basic universal commands (based on user ideas)

## Macro Command Roadmap

- [ ] Add `macropy` command
- [ ] Add `reload` command for user functions
- [ ] Add `delete` command for user functions
- [ ] Add `macroc` command
- [ ] Add `macrocpp` command
- [ ] Add `macrosh` command
- [ ] Add `macroasm` command

## Other (If Time Permits)

- [ ] Add a library with Marvin’s basic commands
- [ ] Create a separate repository for add-ons, including themes and bundles for less universal utilities
- [ ] Create the Marvin website for centralize Marvin download, Add-ons, themes, function bundle and more !
