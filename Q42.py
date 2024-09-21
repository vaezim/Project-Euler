
triangle_nums = set()
for i in range(1, 1000):
    triangle_nums.add(i * (i+1) // 2)

def IsTriangleWord(w: str):
    sum = 0
    for c in w:
        sum += (ord(c) - ord('A') + 1)
    return sum in triangle_nums


if __name__ == "__main__":
    with open("resources/0042_words.txt") as f:
        text = f.readline()

    words = text.split(',')
    words = list(map(lambda x: x[1:-1], words))
    num = 0
    for w in words:
        num += IsTriangleWord(w)
    print(f"Answer = {num}")