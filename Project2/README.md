# Compile all utilities:
`$ make`
## Compile chosen utility:
`$ make [my-cat, my-grep, my-zip, my-unzip]`
## Clean project
`$ make clean`

# Usage

## my-cat
my-cat prints the contents of each file that is given as an argument. If no arguments are given it won't do anything.

You can run it with:

`./my-cat file1 [file2 ...]`

## my-grep
my-grep searches a given string in given input. This input can be either one or more files or just stdin.
It will print out each line with the excact corresponding string. 

You can run it with:

`./my-grep pattern [file1 ...]`

## my-zip
my-zip takes in one or more files that it then compresses. It uses a simple form of compression called run-length encoding (RLE).
In RLE if there are the same n characters in a row it will turn that to a number n and a single character. aaabb -> 3a2b.
This program varies as it writes the number out as 4-byte integer in binary format. So the entries are 5-bytes each.
Content from multiple files will be written without declaring that they are from diffirent files.

You can run it with:

`./my-zip file1 [file2 ...]`

The output is standard stdout file stream so you can redirect the compressed output to a file using UNIX shell redirection like this:

`./my-zip file1 [file2 ...] > file.z`

## my-unzip
my-unzip simply reads the compressed file we just compressed and turns it into regular ASCII-form. 
Just like my-zip it takes one or more files and doesn't store the information that they are from diffirent files.

You can run it with:

`./my-unzip file.z [file2.z ...]`

The output is printed with printf().
