import os

# Get the directory where the current Python file is located
base_dir = os.path.dirname(os.path.abspath(__file__))  # This gets the directory of the current file

# Create a directory for test cases in the same directory as the Python file
test_cases_dir = os.path.join(base_dir, 'test_cases')
os.makedirs(test_cases_dir, exist_ok=True)

# Test cases data
test_cases = {
    '1.in': "4 3\n1 2 3 4\n1 1 2 2\n2 1 4\n2 2 3\n",
    '1.out': "12\n8\n",
    '2.in': "5 4\n5 10 15 20 25\n1 2 4 5\n2 1 3\n1 1 5 -3\n2 2 5\n",
    '2.out': "30\n44\n",
    '3.in': "1 1\n1000000000\n2 1 1\n",
    '3.out': "1000000000\n",
    '4.in': "6 5\n2 4 6 8 10 12\n1 1 3 1\n2 1 6\n1 4 6 -2\n2 3 5\n",
    '4.out': "42\n20\n"
}

# Save test cases to files in the same directory as the Python file
for file_name, content in test_cases.items():
    file_path = os.path.join(test_cases_dir, file_name)
    with open(file_path, 'w') as f:
        f.write(content)

print(f"Test cases generated in: {test_cases_dir}")
