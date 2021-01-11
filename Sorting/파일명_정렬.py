# https://programmers.co.kr/learn/courses/30/lessons/17686

def solution(files):

    def split_filename(filename):
        head, number, tail = '', '', ''
        flag = 1
        num_count = 0  # 최대 NUMBER는 다섯 글자
        for c in filename:
            if flag == 1:
                if not c.isnumeric():
                    head += c
                else:
                    number += c
                    num_count += 1
                    flag = 2
            elif flag == 2:
                if c.isnumeric():
                    number += c
                    num_count += 1
                    if num_count == 5:
                        flag = 3
                else:
                    tail += c
                    flag = 3
            else:
                tail += c

        return head, int(number)

    return sorted(files, key=lambda file: split_filename(file.lower()))


def solution2(files):
    import re

    def split_filename(filename):
        head, number, tail = re.match(
            r'([a-z-. ]+)(\d{1,5})(.*)', filename).groups()
        return head, int(number)

    return sorted(files, key=lambda file: split_filename(file.lower()))


print(solution(["img12.png", "img10.png", "img02.png",
                "img1.png", "IMG01.GIF", "img2.JPG"]))
print(solution2(["img12.png", "img10.png", "img02.png",
                 "img1.png", "IMG01.GIF", "img2.JPG"]))
