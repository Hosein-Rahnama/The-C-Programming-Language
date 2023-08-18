# Tips

You can indirect the output of this program to a file using the following command.

```bash
main.exe input-1.txt input-2.txt > output.txt
```

 In ver-2 of the program, if any error occurs in accessing the input files, its corresponding diagnostic message won't be lost inside the `output.txt` file and you will see it on the command line. As an example, try

```bash
main.exe input-1.txt input-invalid.txt > output.txt
```

for both ver-1 and ver-2 to see the difference.