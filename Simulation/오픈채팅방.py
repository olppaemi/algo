# https://programmers.co.kr/learn/courses/30/lessons/42888

def solution(records):
    answer = []
    id_to_name = {}

    for record in records:
        rec = record.split()
        op = rec[0]
        id = rec[1]
        if op == "Enter":
            id_to_name[id] = rec[2]
        elif op == "Change":
            id_to_name[id] = rec[2]

    for record in records:
        rec = record.split()
        op = rec[0]
        id = rec[1]
        if op == "Enter":
            answer.append(f"{id_to_name[id]}님이 들어왔습니다.")
        elif op == "Leave":
            answer.append(f"{id_to_name[id]}님이 나갔습니다.")

    return answer


print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo",
                "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"]))
