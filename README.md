# C Learning Library

```
   ██████╗     ██╗     ███████╗ █████╗ ██████╗ ███╗   ██╗██╗███╗   ██╗ ██████╗ 
  ██╔════╝     ██║     ██╔════╝██╔══██╗██╔══██╗████╗  ██║██║████╗  ██║██╔════╝ 
  ██║          ██║     █████╗  ███████║██████╔╝██╔██╗ ██║██║██╔██╗ ██║██║  ███╗
  ██║          ██║     ██╔══╝  ██╔══██║██╔══██╗██║╚██╗██║██║██║╚██╗██║██║   ██║
  ╚██████╗     ███████╗███████╗██║  ██║██║  ██║██║ ╚████║██║██║ ╚████║╚██████╔╝
   ╚═════╝     ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝ ╚═════╝ 
```

---

## Start here (copy-paste)

```bash
chmod +x setup.sh && ./setup.sh   # checks gcc, make, optional tools
make run-all                      # runs every example in order
```

Run **one** program (the part after `TOPIC=` is `folder/name` without `.c`):

```bash
make run TOPIC=01_hello_world/hello_world
```

| Command | What it does |
|---------|----------------|
| `make all` | Build everything into `bin/` |
| `make run-all` | Tour all examples |
| `make preview` | Create `topics/*/previews/preview_*.png` (code + sample output) |
| `make clean` | Delete `bin/` |

---

## What you need

| OS | Get a compiler + `make` |
|----|-------------------------|
| macOS | `xcode-select --install` |
| Linux | e.g. `sudo apt install build-essential` |
| Windows | WSL or MSYS2 (use a Unix-style shell for the scripts) |

**Optional:** [silicon](https://github.com/Aloxaf/silicon) pretties the *code* in preview images. `make preview` uses Python **Pillow** to merge images; if needed, a venv is created under `scripts/.venv/`.

---

## Chapters (open `topics/` → chapter → `.c` file)

1. Hello world & variables  
2. Operators  
3. Control flow (`if`, `switch`)  
4. Loops (`for`, `while`, `do`/`while`, `break`/`continue`, `goto`)  
5. Functions (including recursion)  
6. Arrays & strings  
7. Pointers  
8. Structs  

This repo stops at **structs**; file I/O, `malloc`, and lists are a good next step after you are comfortable here.

---

## Preview pictures

After `make preview`, each example has **one** image: source + **program output** under `topics/<chapter>/previews/preview_<name>.png`.

| | | |
|:---:|:---:|:---:|
| ![hello_world](topics/01_hello_world/previews/preview_hello_world.png) | ![for_loop](topics/04_loops/previews/preview_for_loop.png) | ![pointer_basics](topics/07_pointers/previews/preview_pointer_basics.png) |
| `hello_world` | `for_loop` | `pointer_basics` |

*(Generate the rest the same way — every `.c` file has a matching `preview_*.png`.)*

---

## Add your own example

1. Copy the comment block from any file in `topics/`.  
2. Save as `topics/<chapter>/your_name.c`.  
3. Run `make all` and `make run TOPIC=<chapter>/your_name`.

---

## Layout

```
topics/01_hello_world/ … 08_structs/   ← source + previews/
scripts/                              ← run_all, generate previews
bin/                                  ← builds here (ignored by git)
```

---

## About the author

**Chamath Thiwanka** — BICT (Hons), University of Sri Jayewardenepura.
