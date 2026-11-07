# MFMS - Week 10 (Persistent storage)

Municipal Financial Management System, modular C program with file storage.

## Modules

| File | Responsibility |
|------|----------------|
| main.c | Application flow and menu |
| employees.c / .h | Salary, search, employee records, text and binary save/load |
| suppliers.c / .h | Supplier records, text save/load |
| assets.c / .h | Asset records, text save/load |
| budget_records.c / .h | Budget records, text save/load |
| budget.c / .h | VAT and budget calculation |
| utilities.c / .h | Safe input functions (readInt, readFloat) |
| reports.c / .h | Budget and search result reports |

## Build

```
gcc -std=c99 -Wall -Wextra -pedantic -c main.c employees.c suppliers.c assets.c budget_records.c budget.c utilities.c reports.c
gcc main.o employees.o suppliers.o assets.o budget_records.o budget.o utilities.o reports.o -o mfms
```

## Run

```
./mfms
```

After a restart, use option 14 (Load Data) before option 13 (Save Data),
otherwise the files are overwritten with empty lists.

## Data files (folder data/)

Text format, one record per line, fields separated by `|`:
`id|name|value` (employees.txt, suppliers.txt, assets.txt, budgets.txt).
Binary format: employees.dat (raw Employee structs).

## Text vs Binary storage

| | employees.txt | employees.dat |
|---|---|---|
| Functions | fprintf / fscanf | fwrite / fread |
| Human-readable | Yes | No |
| Size (1 record) | 21 bytes | 64 bytes |
| Parsing | Needed (separator \|) | None (raw struct) |
| Portability | Better | Depends on type sizes, padding, byte order |
| Best use | Export, debugging | Fast storage of fixed records |

The binary file is larger for one record because each name is stored
as a fixed 50-character array, plus padding added by the compiler.
On Windows, text mode writes line endings as two bytes (\r\n), so the
text file is 1 byte larger per line than on Linux.