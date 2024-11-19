# StringOperator

## Task:
Implement the [] operator for the already implemented String class.
This operator should implement the following behavior: the operator should be implemented in such a way that for a String object str, one can write str[i][j], and this expression returns a substring starting at position i (counting from 0) and ending at position j (not including).

## Example:
- `String const hello("hello");`
- `String const hell = hello[0][4];` // now hell contains the substring "hell"
- `String const ell = hello[1][4];`  // now ell contains the substring "ell"

`i` can be equal to `j`, in this case, the result should be an empty string. It is guaranteed that `i` will never be greater than `j`, and they will not go beyond the length of the string.

## Requirements

- C++17 or later
- g++ compiler

## Build Instructions

To build the project, run the following commands in your terminal:

```bash
make
```

This will compile the code and generate the executable file `Bank`.

## Clean Up

To remove the object files and the compiled executable, run:

```bash
make clean
```

## License

This project is licensed under the Apache-2.0 License - see the [LICENSE](LICENSE) file for details.
