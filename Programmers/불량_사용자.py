# https://programmers.co.kr/learn/courses/30/lessons/64064

import re
from itertools import permutations


def solution(user_id, banned_id):
    answer = []
    for candidate in permutations(user_id, len(banned_id)):
        for idx, uid in enumerate(candidate):
            if not re.match(f"^{banned_id[idx].replace('*', '.')}$", uid):
                break
        else:
            candidate = set(candidate)
            if candidate not in answer:
                answer.append(candidate)

    return len(answer)


print(solution(["frodo", "fradi", "crodo",
                "abc123", "frodoc"], ["fr*d*", "abc1**"]))
print(solution(["frodo", "fradi", "crodo", "abc123",
                "frodoc"], ["*rodo", "*rodo", "******"]))
print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],
               ["fr*d*", "*rodo", "******", "******"]))
