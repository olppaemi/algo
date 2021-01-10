# https://programmers.co.kr/learn/courses/30/lessons/12981

def solution(n, words):
    answer = [0, 0]
    used_words = {words[0]}

    for i in range(1, len(words)):
        if words[i - 1][-1] != words[i][0] or words[i] in used_words:
            answer = [i % n + 1, i // n + 1]
            break
        used_words.add(words[i])

    return answer


print(solution(3, ["tank", "kick", "know", "wheel",
                   "land", "dream", "mother", "robot", "tank"]))
print(solution(5, ["hello", "observe", "effect", "take", "either", "recognize", "encourage",
                   "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"]))
print(solution(2, ["hello", "one", "even", "never", "now", "world", "draw"]))
