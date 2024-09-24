import random
import os

# Get the directory where the current Python file is located
base_dir = os.path.dirname(os.path.abspath(__file__))  # This gets the directory of the current file

# Create a directory for test cases in the same directory as the Python file
test_cases_dir = os.path.join(base_dir, 'test_cases')
os.makedirs(test_cases_dir, exist_ok=True)


def generate_test_case(filename, n, q, max_value=1000000000):
    with open(filename, 'w') as f:
        f.write(f"{n} {q}\n")
        # 生成初始亮度值
        values = [random.randint(1, max_value) for _ in range(n)]
        f.write(' '.join(map(str, values)) + '\n')
        
        # 生成 q 个操作
        for _ in range(q):
            operation_type = random.choice([1, 2])
            if operation_type == 1:
                l = random.randint(1, n)
                r = random.randint(l, n)
                d = random.randint(-1000, 1000)
                f.write(f"1 {l} {r} {d}\n")
            else:
                l = random.randint(1, n)
                r = random.randint(l, n)
                f.write(f"2 {l} {r}\n")

# 使用示例
generate_test_case('test1.in', 1000, 500)  # 生成 1000 个路灯，500 次操作的测试点


# Save test cases to files in the same directory as the Python file
for file_name, content in test_cases.items():
    file_path = os.path.join(test_cases_dir, file_name)
    with open(file_path, 'w') as f:
        f.write(content)

print(f"Test cases generated in: {test_cases_dir}")