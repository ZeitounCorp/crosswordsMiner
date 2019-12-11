## Check if the words you can think of are in the table(ARRAY[][]) 

# First look at main.c,
You'll find a matrix of chars like this :
```char m[MATRIX_SIZE][MATRIX_SIZE] = {{'C', 'A', 'R', 'T'},```
                                         ```{'E', 'T', 'A', 'K'},```
                                         ```{'E', 'S', 'M', 'E'},```
                                         ```{'L', 'L', 'P', 'N'}};```

```@MATRIX_SIZE is by default 4 (defined at the top of the file);```

The content of the matrix m is completely up to you, what is written right now is for sample purpose.

# Then look at crossword.h

You'll will only need to modify words that are defined in ```bool isWord(char s[])``` to check wether they are present in the matrix you defined in main.c

## Compiling
```cd ~/crosswordsMiner```
```gcc main.c -o app```
```./app``` (in order to execute it)

## Finally, just enjoy the words coming up to your screen while the computer finds them 

Brought to you by @Zcorp with 🖤
