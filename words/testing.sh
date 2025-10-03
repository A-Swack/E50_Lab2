# no arguments, reading from stdin
echo "Hello world! 123 test-case." | ./words

# one file as input
echo "This is a test file." > input1.txt
./words input1.txt

# multiple files in sequence
echo "Another file with words!" > input2.txt
./words input1.txt input2.txt

# use '-' to mix stdin with files
echo "Mixed stdin input." | ./words input1.txt - input2.txt

# file with no words
echo "1234 !@#$$%" > empty.txt
./words empty.txt

# non-existent file (should trigger error to stderr)
./words no_such_file.txt

