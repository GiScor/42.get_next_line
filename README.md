*This project has been created as part of the 42 curriculum by gscorzon.*

# Description

**get_next_line** is a C function designed to read readable content from a file descriptor (`fd`) one line at a time. Each subsequent call to `get_next_line()` fetches the next available line until reaching the end of the file or encountering an error.

## Key Features & Requirements

* **Line-by-Line Reading:** Reads and returns a single line per call without reading the entire file into memory at once.
* **Newline Handling:** Includes the terminating `\n` character at the end of the returned string (unless the end of the file is reached without a trailing newline).
* **Flexible Sources:** Works seamlessly with standard text files as well as `stdin` (Standard Input).
* **Buffer Management:** Compiles using a customizable buffer size defined at compilation time via the `-D BUFFER_SIZE=n` flag.
* **Static Variable Usage:** Leverages a static buffer across multiple function invocations to preserve unread data between calls.

# Instructions

To quickly test the fuction, download ```Makefile``` and ```main.c``` from https://github.com/GiScor/42.get_next_line.

You can do so with a simple `curl` command:  
```curl https://github.com/GiScor/42.get_next_line/raw/refs/heads/main/main.c - o main.c && curl https://github.com/GiScor/42.get_next_line/raw/refs/heads/main/Makefile -o Makefile```

# Resources
