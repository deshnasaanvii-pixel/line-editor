---

 Repository Readme (`README.md`)**[cite: 1]

Create this file for the root of your GitHub repository:

```markdown
# Simple C Line Editor

## Team Members & Responsibilities
* ** Anjali M Patil**: Part A - Core Operations, Dynamic Memory Allocation & Pointer Management (`init_doc`, `free_doc`, `display_doc`, `insert_line`, `delete_line`).
* ** Deshna Saanvi M**: Part B - File I/O (`save_file`, `load_file`), REPL Command Loop, `HELP.md`, `README.md`, and Repo Management.

## Implemented Features
1. **Insert Line (Core)**: Dynamic array expansion with reallocation[cite: 1].
2. **Delete Line (Core)**: Array element shifting and memory deallocation[cite: 1].
3. **Display (Core)**: Numbered document output[cite: 1].
4. **Save/Load File (Core)**: Disk persistence and command-line file argument support[cite: 1].

## Build and Run Instructions

### Compile
```bash
gcc -Wall -o editor main.c