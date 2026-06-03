_This project has been created as part of the 42 curriculum by csanasi._
# ft_printf
## Description
`ft_printf` is a from-scratch recreation of the C standard library's `printf` function. It produces a static library, `libftprintf.a`, that prints formatted output for the supported format specifiers.

## Usage

Clone the repository and compile the library:

```bash
git clone https://github.com/chiarasanasi/ft_printf.git
cd ft_printf
make
```

Then link it in your project:

```bash
cc your_file.c -L. -lftprintf -o your_program
```

Include the header:

```c
#include "ft_printf.h"
```

> **Note:** this project already includes the necessary functions from my [libft](https://github.com/chiarasanasi/libft) inside `util/libft/` — you don't need to download it separately. Only the functions actually used by ft_printf are included.

## Instructions
From the project root:
```bash
make
```
Produces `libftprintf.a`. Other targets: `clean`, `fclean`, `re`.
To use it in your own program:
```c
#include "ft_printf.h"
int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    return (0);
}
```
Compile with:
```bash
cc your_program.c -L. -lftprintf -o your_program
```
## Supported Features
**Conversions:** `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`
**Flags (bonus):** `-`, `0`, `.` (precision), `#`, `+`, ` ` (space), and field width.
## Algorithm
For every specifier, the program follows the same three steps: **parse** flags, width, and precision into a `t_flag` struct; **build** the textual representation of the value (with `ft_itoa`, `ft_utoa`, `ft_itoa_hex`, etc.); **emit** the result via `write`, inserting padding (spaces or zeros) in the position required by the flags.
A second struct, `t_info_nbr`, carries the rendering context (digit string, sign, precision zeros, padding) so the same emission logic is reused across `%d`, `%u`, `%x`, `%X`, and `%p`. Variadic arguments are read with `<stdarg.h>` using the correct type for each conversion.
## Resources
- `man 3 printf` — reference for the format specifiers and variadic arguments.
- [Tripouille's printfTester](https://github.com/Tripouille/printfTester) — used to validate against the real `printf`.
### AI usage
Anthropic's Claude was consulted as a reference when needed — to clarify edge cases of the format specifiers, discuss flag interactions, and double-check Norm compliance. All design choices, code, and debugging were done by me.
