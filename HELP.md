# C Line Editor - HELP File

A command-line text editor operating on single line numbers.

## Command Reference

* `display` (or `p`): Show all document lines with numbers.
* `insert <line>` (or `i <line>`): Insert text at specified line number.
* `delete <line>` (or `d <line>`): Remove line at specified line number.
* `save <file>` (or `s <file>`): Save contents to specified file name.
* `help` (or `h`): Display quick syntax guide.
* `quit` (or `q`): Exit editor safely and free memory.

## Examples

```bash
> insert 1
Enter text: Hello World
Line inserted at 1.

> save document.txt
Saved to document.txt successfully.