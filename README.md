# Marvin the Paranoid Assistant

Marvina is a personal assistant designed to automate tasks or create macros in Python, and soon in Bash, C, and C++. Macros are functions in a supported language that Marvin includes in his code as a subcommand. You can also use basic commands like `marvin albbl "text"` in your `.bashrc` or `.zshrc` by defining simple functions. Macros are just one part of Marvin's capabilities—over time, you could even code a game and integrate it into Marvin using `sys` and importing different files.

## Commands

| Command          | Description                                                                                                                                                                                                 |
|------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `marvin show`    | Displays Marvin’s face with a specific emotion (use the `--emot` flag) or a neutral face by default.                                                                                                       |
| `marvin emot`    | Adds a new emotion with a name, eyebrows, ears, eyes, nose, and mouth.                                                                                                                                      |
| `marvin list`    | Lists available emotions for Marvin’s face. Can be displayed in rows, columns, or with examples.                                                                                                           |
| `marvin bbl`     | Prints a simple speech bubble with text wrapping and size limitations.                                                                                                                                       |
| `marvin albbl`   | Prints Marvin with a speech bubble, including an emotion, text wrapping, and size limits.                                                                                                                   |
| `marvin macropy` | Adds a user-defined Python function. Use type specifiers for arguments! Use `marvin macropy -h "Help text for your function" -f "$(cat file_with_only_one_function.py)"`.                                      |

## Download

Install Marvin using the following command. You can specify a target directory or omit it to install in your home folder (`~/.marvin/`).

Copy and execute the appropriate command for your terminal:
Marvin-AssistantMarvin-Assistant
- **Zsh terminal:**
  ```bash
  curl https://raw.githubusercontent.com/SeigneurLefou/Marvin-Assistant/refs/heads/main/.download.sh | zsh
  
- **Bash terminal:**
  ```bash
  curl https://raw.githubusercontent.com/SeigneurLefou/Marvin-Assistant/refs/heads/main/.download.sh | bash
  
- **Fish terminal:**
  ```bash
  curl https://raw.githubusercontent.com/SeigneurLefou/Marvin-Assistant/refs/heads/main/.download.sh | fish

## User Contributions

If you have ideas for useful commands or features, feel free to open an issue to present your suggestion!

## Basic Roadmap

- [ ] Add basic printable commands
- [ ] Add download script
- [ ] Add `emot` command

## Macro Command Roadmap

- [ ] Add `macropy` command
- [ ] Add reload command for user functions *
- [ ] Add delete command for user functions *
- [ ] Add `macroc` command
- [ ] Add `macrocpp` command
- [ ] Add `macrosh` command
- [ ] Add `macroasm` command

## Command Roadmap

- [ ] Add shutdown command *
- [ ] Add reboot command *
- [ ] Add basic universal commands (based on user ideas) *

## Other (If Time Permits)

- [ ] Add a library with Marvin’s basic commands
- [ ] Create a separate repository for add-ons, including themes and bundles for less universal utilities
- [ ] Create the Marvin website for centralize Marvin download, Add-ons, themes, function bundle and more ! *
