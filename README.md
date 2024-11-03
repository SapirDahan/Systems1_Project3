# StrListManager

## Description
**StrListManager** is a C-based library and command-line application for managing and manipulating a linked list of strings. The project provides various functionalities for inserting, removing, sorting, and counting strings within a list. This library efficiently handles dynamic string lists and offers essential operations for text-based data structures.

## Features
- **Dynamic Insertion**: Insert strings at specific indexes or append to the end.
- **Deletion**: Remove strings by value or at a specified index.
- **List Management**: Print the list, retrieve the first element, and count total characters.
- **Sorting**: Sorts the list in lexicographical order.
- **Reverse**: Reverse the order of elements in the list.
- **Comparison**: Check if two lists are equal.
- **Clone**: Clone an existing list.

## Compilation
Use the provided `makefile` to compile the program:
```bash
make
```

## Usage
Run the compiled `StrList` executable to manage the string list through a menu-driven interface:
```bash
./StrList
```

## Menu Options
The program accepts a variety of options to manipulate the list:
1. **Add a Line**: Insert multiple strings to the end.
2. **Insert at Index**: Insert a string at a specific index.
3. **Print List**: Display the current elements of the list.
4. **Size**: Show the number of elements.
5. **Print Element at Index**: Show the string at a specific index.
6. **Count Characters**: Print the total number of characters in the list.
7. **Count Occurrences**: Show how many times a specific string appears in the list.
8. **Remove All**: Delete all occurrences of a specified string.
9. **Remove at Index**: Delete a string at a specific index.
10. **Reverse**: Reverse the order of elements.
11. **Clear List**: Remove all elements.
12. **Sort**: Sort the list lexicographically.
13. **Check Sorted**: Verify if the list is in lexicographical order.
0. **Exit**: Free all memory and exit.

