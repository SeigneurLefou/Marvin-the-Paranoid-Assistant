# Marvin the Paranoid Assistant (MPA)

Marvin is a Linux terminal command assistant developed in C++. It acts as a command wrapper capable of executing built-in functions, external modules (bundles), and system binaries, while providing a visual interface through ASCII art.

## Search Architecture

When a command is submitted, Marvin applies the following priority hierarchy:
1. **Builtins**: Native functions compiled directly into the application core (hash table lookup).
2. **Bundles**: Binaries located in the structured directory `bundles/[username].[repo]/bin/`.
3. **User Bin**: Binaries manually added to `usr/bin/`.
4. **System**: Automatic search within the user's PATH.

## Installation

To download Marvin, please clone the repository and navigate into it (the name .marvin is optional):
```bash
git clone https://github.com/SeigneurLefou/Marvin-the-Paranoid-Assistant .marvin
cd .marvin
```

Then, run the installation script:
```bash
./install.sh
```

## Built-in Commands

| Command | Description |
| --- | --- |
| --help, -h | Displays help and command syntax. |
| update | Updates the Marvin directory and rebuilds the project. |
| whereis | Identifies the location of a binary and detects naming conflicts. |
| search | Recursive search for files or directories with depth management. |

## Bundle Management

Bundles are remote extensions developed by users that can be managed via dedicated commands:

| Command | Description |
| --- | --- |
| install | Clones and installs a bundle from a remote repository. |
| list | Lists available bundles (use the `--installed` flag for local modules). |
| remove | Completely uninstalls a bundle. |
| load | Updates and recompiles an existing module. |

## Project Roadmap

### Infrastructure and Core
- [x] Installation script with automatic PATH export.
- [x] Dynamic MARV variable in the Makefile for uninstallation.
- [ ] Complete codebase migration to C++17/20 standard.
- [ ] Implementation of core built-in commands.
- [ ] Implementation of the Search command.

### Official Modules
- [ ] Todo-list: Task management with prioritization and reordering (add, move, remove, clear, list, check).
- [ ] Chat: Client-server communication via POSIX sockets (server-chat, client-chat).

### Ecosystem
- [ ] Creation of a centralized repository for add-ons and themes.
- [ ] Technical documentation website with a marketplace for bundles.

## Contributions

To suggest a new feature or report a bug, please open an Issue on the official GitHub repository. Contributions via Pull Requests are welcome following technical review.
