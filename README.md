# To-Do List Manager (C++)

A simple command-line to-do list manager written in C++. Add tasks, list them, mark them done, and remove them — all through an interactive menu.

## Features

- **Add task** — create a task with a title and description. Each task gets a unique, auto-incrementing ID that is never reused, even after removal.
- **List tasks** — view all tasks with their ID, title, description, and completion status.
- **Mark task done** — mark a task as completed by its ID.
- **Remove task** — delete a task by its ID.
- Robust input validation: rejects non-numeric input, out-of-range menu choices, and leftover garbage after a number (e.g. `"3x"`, `"4klkl"`), using `std::stoi` with position tracking and exception handling.

## How it works

Tasks are stored in memory using a `TodoList` class, which wraps a `std::vector<Task>` and exposes controlled methods (`addTask`, `listTasks`, `markDone`, `removeTask`) for interacting with the list. Each `Task` is a struct holding a title, description, unique ID, and completion status.

The `main()` function handles all user interaction (the menu loop, prompts, and input parsing), while `TodoList` focuses purely on managing the task data — keeping console I/O and data logic separate.

## Requirements

- A C++17-compatible compiler (e.g. `g++`)

## Build and run

```bash
g++ -std=c++17 -o todo main.cpp
./todo
```

On Windows, the compiled binary will be `todo.exe` instead.

## Usage

Run the program and choose an option from the menu:

--- To-Do List ---
1. Add task
2. List tasks
3. Mark task done
4. Remove task
5. Quit
Choose an option:

## Roadmap / possible future additions

- Persist tasks to a file so they survive between runs
- Task due dates or priority levels
- Edit an existing task's title/description
