## Tips

- In some programs you may need to pass `EOF` as an input. This can be done by pressing <kbd>Ctrl</kbd>+<kbd>Z</kbd> and then <kbd>Enter</kbd> on a new line of the command line.

- Some programs may require an input as text. Often, you want to run that program several times, so it is wise to store that input text in a file and pass that as the input to the program. This can be done as follows.

    On window's powershell, use the following command for using `sample-text.txt` as your input from the command line to a compiled program such as `main.exe`.
    
        Get-Content sample-text.txt | .\main.exe
            
    On any GNU/Linux distribution just use

        sample-text.txt | ./main.exe