# Employee Management System (C)

A small command-line Employee Management System written in C.

This program keeps an in-memory list of employees, provides a simple text-menu UI for adding, listing,
searching, updating and deleting employees, and can save/load the list to a CSV file (`employees.csv`).

## Features
- Add an employee
- Display all employees
- Search by ID
- Search by name
- Update an employee
- Delete an employee
- Save to CSV file
- Load from CSV file

## Project structure

- `main.c`         — program entry and main menu loop
- `employee.c`/`employee.h` — in-memory Employee and EmployeeList implementation
- `file_handler.c`/`file_handler.h` — CSV save/load routines
- `ui.c`/`ui.h`   — user interaction functions (menu, input helpers)
- `utils.c`/`utils.h` — small utilities (e.g., trim)
- `employees.csv`  — sample/target CSV file used by save/load
- `test_main.c`    — small harness that can redirect input to test the program

## Data (CSV) format

Lines are stored without a header. Each line has the format:

id,name,age,position,salary

Example:

1,John Doe,30,Engineer,55000.00

Notes:
- `id` is an integer unique identifier.
- `name` and `position` are strings (commas in fields are NOT supported).
- `salary` is a floating-point number.

## Build

Compile the program using GCC. The example below builds the main program as `ems`:

```sh
gcc -Wall -Wextra -std=c11 main.c employee.c file_handler.c ui.c utils.c -o ems
```

If you want to compile the test harness (it expects the `ems` executable to exist):

```sh
gcc -Wall -Wextra -std=c11 test_main.c -o test_main
```

## Run

Start the program:

```sh
./ems
```

Then use the menu to add/list/search/update/delete employees. The default filename used for save/load is `employees.csv`.

## Running tests (manual)

`test_main.c` demonstrates redirecting stdin from a file and running `./ems`. Create a `test_input.txt` containing
the keystrokes/choices you want to simulate then run the compiled `test_main`:

```sh
# create a simple input script (example)
cat > test_input.txt <<'EOF'
1
101
Alice
28
Developer
60000
2
0
EOF

# run the harness
./test_main
```

Adjust `test_input.txt` to exercise other menu options.

## Usage: menu options

The menu provides the following options (displayed by the program):

1. Add Employee
2. Display All Employees
3. Search Employee by ID
4. Search Employee by Name
5. Update Employee
6. Delete Employee
7. Save to file
8. Load from file
0. Exit

## Notes & assumptions

- The implementation stores employees in a dynamic array (`EmployeeList`) and grows capacity automatically.
- CSV parsing is simple (uses `sscanf` and `strcpy`) and does not handle escaped commas or quoted fields.
- Input helpers read lines with `fgets` and trim trailing newlines.

## Git quick commands

Create and switch to a new branch:

```sh
git checkout -b <branch-name>
```

Push your branch to the remote:

```sh
git push origin <branch-name>
```

## License
Add a license file if you intend to publish or share this repository publicly.

---

If you'd like, I can also add a small `Makefile` or a `build.sh` script to simplify compilation.