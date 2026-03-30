# C Learning Library

```
   ██████╗     ██╗     ███████╗ █████╗ ██████╗ ███╗   ██╗██╗███╗   ██╗ ██████╗ 
  ██╔════╝     ██║     ██╔════╝██╔══██╗██╔══██╗████╗  ██║██║████╗  ██║██╔════╝ 
  ██║          ██║     █████╗  ███████║██████╔╝██╔██╗ ██║██║██╔██╗ ██║██║  ███╗
  ██║          ██║     ██╔══╝  ██╔══██║██╔══██╗██║╚██╗██║██║██║╚██╗██║██║   ██║
  ╚██████╗     ███████╗███████╗██║  ██║██║  ██║██║ ╚████║██║██║ ╚████║╚██████╔╝
   ╚═════╝     ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝ ╚═════╝ 
```

**Small programs, one idea each — clone, build, run.**

## What is this?

- **Who it is for:** anyone starting C and wanting a calm, ordered path through the basics.
- **What is inside:** short, heavily commented examples grouped into eight chapters under `topics/`.
- **How to use it:** run `./setup.sh` once, then `make run-all` for a guided tour, or `make run TOPIC=…` for a single example.

## Prerequisites

| OS | Install | Notes |
|----|---------|--------|
| macOS | `xcode-select --install` | Provides `clang`/`gcc` and `make` |
| Linux (Debian/Ubuntu) | `sudo apt install build-essential` | `gcc` + `make` |
| Windows | MSYS2, WSL, or Visual Studio Build Tools | Use a Unix-like shell for the scripts |

**Previews:** `make preview` needs **Pillow** (merged images). A venv is created at `scripts/.venv/` if your system Python is PEP-668–managed. Optional **[silicon](https://github.com/Aloxaf/silicon)** (`brew install silicon`) syntax-highlights the **source** half of each image; run output is always rendered as monospace text so it stays readable.

## Quick start

```bash
chmod +x setup.sh && ./setup.sh
make run-all
```

Try one file:

```bash
make run TOPIC=01_hello_world/hello_world
```

## What you will learn

- **01 — Hello world & variables** — first program, built-in types and sizes  
- **02 — Operators** — arithmetic, comparisons, logic  
- **03 — Control flow** — `if` / `else`, `switch` / `case`  
- **04 — Loops** — `for`, `while`, `do`/`while`, `break` / `continue`, `goto` (with caution)  
- **05 — Functions** — calls, recursion, pass-by-value  
- **06 — Arrays & strings** — 1D/2D arrays, C strings  
- **07 — Pointers** — addresses, `*`, `&`, pointer arithmetic  
- **08 — Structs** — grouping data, arrays of structs  

There are **22** example programs in total (the layout matches the chapter list above).

## Preview images (code + output)

Run `make preview`. Every example gets **one** PNG: `topics/<chapter>/previews/preview_<name>.png`. It stacks **syntax-highlighted source** (silicon, if installed) and a **Program output** section (stdout/stderr from running the binary).

### Spotlight examples

#### `hello_world.c`

![hello_world — source + output](topics/01_hello_world/previews/preview_hello_world.png)

#### `for_loop.c`

![for_loop — source + output](topics/04_loops/previews/preview_for_loop.png)

#### `pointer_basics.c`

![pointer_basics — source + output](topics/07_pointers/previews/preview_pointer_basics.png)

### All preview files

| Chapter | Preview |
|---------|---------|
| 01 | [`preview_hello_world.png`](topics/01_hello_world/previews/preview_hello_world.png) · [`preview_variables_types.png`](topics/01_hello_world/previews/preview_variables_types.png) |
| 02 | [`preview_arithmetic.png`](topics/02_operators/previews/preview_arithmetic.png) · [`preview_comparison.png`](topics/02_operators/previews/preview_comparison.png) · [`preview_logical.png`](topics/02_operators/previews/preview_logical.png) |
| 03 | [`preview_if_else.png`](topics/03_control_flow/previews/preview_if_else.png) · [`preview_switch_case.png`](topics/03_control_flow/previews/preview_switch_case.png) |
| 04 | [`preview_for_loop.png`](topics/04_loops/previews/preview_for_loop.png) · [`preview_while_loop.png`](topics/04_loops/previews/preview_while_loop.png) · [`preview_do_while.png`](topics/04_loops/previews/preview_do_while.png) · [`preview_break_continue.png`](topics/04_loops/previews/preview_break_continue.png) · [`preview_goto_label.png`](topics/04_loops/previews/preview_goto_label.png) |
| 05 | [`preview_basic_functions.png`](topics/05_functions/previews/preview_basic_functions.png) · [`preview_recursion.png`](topics/05_functions/previews/preview_recursion.png) · [`preview_pass_by_value.png`](topics/05_functions/previews/preview_pass_by_value.png) |
| 06 | [`preview_arrays_1d.png`](topics/06_arrays_strings/previews/preview_arrays_1d.png) · [`preview_arrays_2d.png`](topics/06_arrays_strings/previews/preview_arrays_2d.png) · [`preview_strings_basics.png`](topics/06_arrays_strings/previews/preview_strings_basics.png) |
| 07 | [`preview_pointer_basics.png`](topics/07_pointers/previews/preview_pointer_basics.png) · [`preview_pointer_arithmetic.png`](topics/07_pointers/previews/preview_pointer_arithmetic.png) |
| 08 | [`preview_struct_basics.png`](topics/08_structs/previews/preview_struct_basics.png) · [`preview_struct_array.png`](topics/08_structs/previews/preview_struct_array.png) |

## Project structure

```
c-practice-2/
├── README.md
├── Makefile
├── setup.sh
├── scripts/
│   ├── generate_previews.sh
│   ├── combine_preview.py
│   ├── render_text_png.py
│   └── run_all.sh
├── topics/
│   ├── 01_hello_world/
│   ├── 02_operators/
│   ├── 03_control_flow/
│   ├── 04_loops/
│   ├── 05_functions/
│   ├── 06_arrays_strings/
│   ├── 07_pointers/
│   └── 08_structs/
└── bin/                 ← built binaries (git-ignored)
```

## How to run any example

Examples compile to `bin/<name>` where `<name>` is the `.c` filename without the extension.

```bash
make run TOPIC=04_loops/for_loop    # runs bin/for_loop
make run TOPIC=07_pointers/pointer_basics
```

- `make all` — build everything  
- `make run-all` — run every example in chapter order  
- `make preview` — write `topics/*/previews/preview_*.png` (code + run output)  
- `make clean` — remove `bin/`  

## Contributing / extending

1. Add `topics/<chapter>/<name>.c` using the header block at the top of existing files.  
2. Run `make all` to confirm it compiles with no warnings.  
3. Run `make preview` to add `previews/preview_<name>.png`.  

Template:

```c
/*
 * TOPIC: [Chapter Name]
 * EXAMPLE: [Example Title]
 * CONCEPT: One sentence explaining what this teaches.
 *
 * TRY IT: A suggested small modification for the learner.
 */
```

## Philosophy

Every file is one idea, one story. The comments explain *why* as much as *what*, so you can change a line, re-run, and see the effect immediately. Nothing here is clever for its own sake — only what helps a beginner see C clearly.

## PNG tooling

- **silicon** (optional): renders the **source code** panel when available. Flags match silicon 0.5.x (line numbers are on by default; there is no `--line-number` flag).  
- **Pillow** (required for `make preview`): renders **program output** and **merges** code + output into `preview_*.png` via `combine_preview.py`.  

---

**Scope:** this library stops at **structs** (chapter 08). Extensions such as file I/O, `malloc`/`free`, and linked lists are natural next steps once these examples feel familiar.
