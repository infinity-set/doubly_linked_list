# Doubly Linked List Operations in C

## Overview

Welcome to the Doubly Linked List Operations in C repository! This C program provides a practical implementation of various operations on doubly linked lists, making it an excellent resource for junior developers looking to enhance their understanding of memory management, pointers, and data structures.

## Table of Contents

- [Why Use This Script](#why-use-this-script)
- [Prerequisites](#prerequisites)
- [Languages and Utilities Used](#languages-and-utilities-used)
- [Environments Used](#environments-used)
- [Memory Management and Pointers](#memory-management-and-pointers)
- [Adding Nodes](#adding-nodes)
- [Deleting Nodes](#deleting-nodes)
- [Reverse List](#reverse-list)
- [Printing Nodes](#printing-nodes)

## Why Use This Script

Doubly linked lists are fundamental data structures with real-world applications in software development. This C program not only demonstrates the implementation of common operations on doubly linked lists but also provides a practical context for junior developers to deepen their understanding of memory management and pointers.

## Prerequisites

Before using this C program, ensure that you have the following:

- A C compiler installed on your system.
- Basic understanding of C programming, including memory management concepts.

## Languages and Utilities Used

- **C**
- **Visual Studio Code**

[<img  alt="C Logo Icon" width="45px" src="https://upload.wikimedia.org/wikipedia/commons/1/18/C_Programming_Language.svg" />][C]
[<img alt="Visual Code Icon" width="45px" src="https://upload.wikimedia.org/wikipedia/commons/9/9a/Visual_Studio_Code_1.35_icon.svg" />][vscode]

[C]: https://learn.microsoft.com/en-us/cpp/c-language/
[vscode]: https://code.visualstudio.com/

## Environments Used

- **Windows**

[<img align="left" alt="Microsoft Icon" width="35px" src="https://upload.wikimedia.org/wikipedia/commons/3/34/Windows_logo_-_2012_derivative.svg" />][windows]

[windows]: https://www.microsoft.com/
<br /><br />


## Memory Management and Pointers

This repository places a strong emphasis on memory management and pointers, critical concepts for any C developer. Throughout the code, you'll encounter dynamic memory allocation, pointer manipulation, and proper deallocation techniques. Understanding these aspects is crucial for building robust and efficient C programs.

## Adding Nodes

### New List

Initialize a new list with a given head and number.

```c
void new_list(dub_node *head, int num);
```

### New List

Initialize a new list with a given head and number.

```c
void new_list(dub_node *head, int num);
```

### Add at End

Add a new node with a given number at the end of the list.

```c
void add_at_end(dub_node *head, int num);
```

### Add at Beginning

Add a new node with a given number at the beginning of the list.

```c
dub_node *add_at_beginning(dub_node *head, int num);
```

### Insert at Index

Insert a new node with a given number at a specified index in the list.

```c
dub_node *insert_at_index(dub_node *head, int index, int num);
```

## Deleting Nodes

### Delete at Beginning

Delete the first node in the list.

```c
dub_node *delete_at_beginning(dub_node *head);
```

### Delete at End

Delete the last node in the list.

```c
void delete_at_end(dub_node *head);
```

### Delete at Index

Delete the node at a specified index in the list.

```c
dub_node *delete_at_index(dub_node *head, int index);
```

### Delete Entire List

Delete the entire list.

```c
dub_node *delete_list(dub_node *head);
```

## Reverse List

### Reverse List

Reverse the entire list.

```c
dub_node *reverse_list(dub_node *head);
```

## Printing Nodes

### Print List

Print the elements of the list.

```c
void print_list(dub_node *head);
```

## Usage

The main function in the provided C code demonstrates the usage of these doubly linked list operations.

Feel free to explore and modify the code based on your requirements!

#

⬅️ **[Home](https://github.com/infinity-set)**

