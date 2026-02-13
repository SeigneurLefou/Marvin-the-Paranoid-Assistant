# Marvin the Paranoid Assistant

Marvin is a terminal assistant who simplifies complex tasks with basic commands and more with macros, functions that are added by the user.
It's Linux only, maybe it works on macOS, maybe not, it's not a priority in development.

## Usage

If you want to add your own command the actual methode is to move your binary to the folder `~/.marvin/usr/bin/`

## Commands

| Command | Description |
| --- | --- |
| update | A command to update Marvin to the next version |

## Download

To download Marvin, you can use this command in your shell terminal.
```bash
curl https://raw.githubusercontent.com/SeigneurLefou/Marvin-the-Paranoid-Assistant/refs/heads/main/install.sh | sh
```

If it doesn't work, add this command to your config file :
```bash
export PATH=$PATH:$HOME/.local/bin/
```

## User Contributions

If you have ideas for useful commands or features, feel free to open an issue to present your suggestion ! If the idea you suggest is not universal, give it as an add-on.

## Download Roadmap

- [x] Add download script with export in PATH.
- [ ] Add graphic annotation to the build and remove functions.
- [x] Add PWD variable in the Makefile for a deinstall command more powerful.

## Basic Command Roadmap

- [ ] Add basic printable commands like `bbl`, `albbl`, or `show`.
- [ ] Add `shutdown` command.
- [ ] Add `reboot` command.
- [ ] Add `timer` command.
- [ ] Add `date` command with flags for syntax.
- [ ] Add `search` command, a more powerful version of cd.
- [ ] Add basic universal commands (based on user ideas).

## Add-on Roadmap 

- [ ] Create a separate repository for add-ons, including themes and bundles for less universal utilities.
- [ ] Add install command for installing add-ons.
- [ ] Add load command for load add-ons.
- [ ] Add uninstall command for uninstall add-ons.

## Other (If Time Permits)

- [ ] Create the Marvin website to centralize Marvin downloads, Add-ons, themes, function bundles, and more !

