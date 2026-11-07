# Dynamic Memory & Process Management in C

These three C programming exercises demonstrate progressively more complex concepts about dynamic memory allocation and process management.

**Progression:** Memory management → Process duplication → Process replacement — the building blocks of how Unix/Linux systems run programs.

---

## Exercise 1: String Reversal with Dynamic Memory

### Main concepts
- **Basic `malloc`/`free`**: Allocate exactly the right amount of memory dynamically.
- **Memory calculation**: Understand why you need `strlen() + 1` (room for the null terminator).
- **Memory responsibility**: You allocate it, you must free it.
- **Safe input handling**: Use `fgets()` instead of `scanf()` to prevent buffer overflows.

### Takeaway
This is the foundation: managing memory within a single process. It builds the discipline of *"if you `malloc` it, you must `free` it"* without the complications of multiple processes.

---

## Exercise 2: Fork and Memory Copying

### Main concepts
- **Memory duplication**: When you call `fork()`, the child gets a *copy* of the parent's memory.
- **Virtual memory illusion**: Both processes show the same address, but each address maps to different physical memory.
- **Process independence**: Changes in the child don't affect the parent, and vice versa.

### Takeaway
`fork()` creates a **separate memory space**. Even though the addresses look identical, each is mapped to a different physical location. When the child changes the value to `200`, the parent still has `100` — proof that memory was duplicated, not shared.

---

## Exercise 3: Fork vs. Exec and Memory Replacement

### Main concepts
- **Fork duplicates memory**: As in Exercise 2, the child initially has a copy of everything.
- **Exec *replaces* memory**: When the child calls `exec()`, its entire program is replaced — all `malloc`'d memory disappears.
- **Process transformation**: `exec()` doesn't create a new process; it transforms the current one into a completely different program.

### Takeaway
This shows the difference between `fork()` (which copies) and `exec()` (which replaces). The `malloc`'d memory exists after `fork()` but vanishes after `exec()` because `ls` is now running instead of your program. This is why shells **fork, then exec**: the parent keeps its memory while the child becomes a new program.

---

## Summary

| Exercise | Concept | Key Call(s) |
|----------|---------|-------------|
| 1 | Managing memory in one process | `malloc`, `free`, `fgets` |
| 2 | Duplicating a process and its memory | `fork` |
| 3 | Replacing a process's program and memory | `fork`, `exec` |
