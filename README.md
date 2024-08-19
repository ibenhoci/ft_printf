# ft_printf

`ft_printf` is a custom implementation of the standard `printf` function from libc, designed to demonstrate fundamental concepts in C programming and library creation.

## Overview

The `ft_printf` function aims to replicate the behavior of `printf` for specific format conversions while adhering to the requirements listed below. This implementation does not handle buffer management as the original `printf` does.

## Features

The `ft_printf` function supports the following format specifiers:

- `%c` - Prints a single character.
- `%s` - Prints a string (as defined by the common C convention).
- `%p` - Prints a `void *` pointer argument in hexadecimal format.
- `%d` - Prints a decimal (base 10) number.
- `%i` - Prints an integer in base 10.
- `%u` - Prints an unsigned decimal (base 10) number.
- `%x` - Prints a number in hexadecimal (base 16) lowercase format.
- `%X` - Prints a number in hexadecimal (base 16) uppercase format.
- `%%` - Prints a percent sign.

## Building the Library

To create the static library `libftprintf.a`, use the following steps:

1. **Compile the Source Code:**
   Compile your source files to object files using `gcc`:

   ```bash
   	Make
	```
## Usage
To use the ft_printf library in your project:

1. **Include the Header**:
Include the header file in your source files where you want to use ft_printf.
	```
		# include "ft_printf.h"
	```
2. **Link Against the Library**:
When compiling your project, link against the libftprintf.a library:

	```bash
		gcc -o my_program my_program.c -L. -lftprintf
	```
Ensure libftprintf.a is in the same directory as your compilation command or provide the appropriate path.

## Example
Here's an example of using ft_printf:
	```
		#include "ft_printf.h"

		int main() {
			ft_printf("Character: %c\n", 'A');
			ft_printf("String: %s\n", "Hello, World!");
			ft_printf("Pointer: %p\n", (void*)0x1234);
			ft_printf("Decimal: %d\n", 1234);
			ft_printf("Integer: %i\n", -5678);
			ft_printf("Unsigned: %u\n", 123456);
			ft_printf("Hex lowercase: %x\n", 255);
			ft_printf("Hex uppercase: %X\n", 255);
			ft_printf("Percent: %%\n");

			return 0;
		}
	```

## Testing
To test your implementation, compare the output of ft_printf with the standard printf function. Ensure that all supported format specifiers are correctly handled and produce the expected results.

## Contributing
To contribute to this project:

1. Fork the repository.
2. Make your changes.
3. Submit a pull request with your modifications.
Please ensure that your code adheres to the existing style and passes all tests.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgments
Special thanks to the contributors and educators who have provided valuable insights into C programming and library development.