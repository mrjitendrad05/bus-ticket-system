# Insurance Management System - Beginner C++ Project

This beginner version uses only:
- `iostream` for input/output
- `fstream` for file handling
- `string` for text
- `struct`, functions, loops and `if-else`

## Files
- `main.cpp`
- `data/customers.txt`
- `data/policies.txt`

## Compile and run
Run the terminal from this project folder.

Windows with MinGW:
```powershell
g++ -std=c++17 main.cpp -o insurance.exe
.\insurance.exe
```

Linux/macOS:
```bash
g++ -std=c++17 main.cpp -o insurance
./insurance
```

## Test
1. Add a customer with option 1.
2. List customers with option 2.
3. Search for the customer using option 3.
4. Create a policy with option 4.
5. List policies with option 5.
6. Exit and run again to check that records persist.

IDs are entered manually to keep the project beginner-friendly. Premium percentages are examples for a college demonstration, not real insurance rates. Run from the project folder so the relative `data/` paths work.
