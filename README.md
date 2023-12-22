<p align="left">
  <img src="https://img.shields.io/badge/42-Barcelona-black" />
  <img src="https://img.shields.io/github/license/alanusse/get_next_line" />
  <img src="https://img.shields.io/github/languages/code-size/alanusse/get_next_line" />
</p>

# get_next_line

`get_next_line` is a function that returns a read line of specific file descriptor.
This function allow you to retrieve a line when you call it, and remembering which one was the last line returned.
Also you can use it with different file descriptors in every call and the function will be able to remember the last state of file descriptor.

## Requirements

To use this function you need to have GCC compiler installed in your computer.

## How to use it

1. Clone this repository and enter into folder.

```bash
git clone https://github.com/alanusse/get_next_line && cd get_next_line
```

2. Create a .txt extension file with some content.
```c
// file.txt

this is a line
here another line
that's it.
```

3. Create a main.c file with the following content.
```c
#include "get_next_line.h"
#include <printf.h>

int main()
{
  int   fd;
  char  *line;

  fd = open("file.txt", O_RDONLY);
  if (fd < 0)
    return (0);
  line = get_next_line(fd);
  while (line)
  {
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
  }
  close(fd);
  return (0);
}
```

4. Run it with the following command.
```bash
gcc main.c get_next_line.c get_next_line_utils.c && ./a.out
```

5. The output will looks like this:
```bash
this is a line
here another line
that's it.
```

By default `BUFFER_SIZE` size is 10, but you can edit this value when you compile the code:
```bash
gcc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=30
```
If `BUFFER_SIZE` is 0 or a negative number, get_next_line function will return `NULL`.
Same behaviour will happen if file descriptor is negative or an error occurred trying to open a file.
## Tests

I made some tests for mandatory part only. In the future I will add more tests and also for bonus part.

To run unit tests you need to follow this steps.

1. Enter into tests folder, compile code and run unit tests.
```bash
cd tests && gcc main.c ../get_next_line.c ../get_next_line_utils.c && ./a.out
```

2. If you want to test different `BUFFER_SIZE` values, you need to put value when you compile.
```bash
cd tests && gcc main.c ../get_next_line.c ../get_next_line_utils.c -D BUFFER_SIZE=25 && ./a.out
```
