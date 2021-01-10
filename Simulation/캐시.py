# https://programmers.co.kr/learn/courses/30/lessons/17680

def solution(cacheSize, cities):
    if cacheSize == 0:
        return 5 * len(cities)

    answer = 0
    cache = []

    for city in cities:
        city = city.lower()
        # 캐시에 저장되어 있다면,
        if city in cache:
            cache.remove(city)
            cache.append(city)
            answer += 1
        # 캐시가 다 차서 새로운 도시를 넣을 수 없다면,
        # LRU 정책을 이용해 캐시의 내용을 변경
        elif len(cache) == cacheSize:
            cache.pop(0)
            cache.append(city)
            answer += 5
        # 캐시가 아직 다 채워지지 않았다면,
        else:
            cache.append(city)
            answer += 5

    return answer


print(solution(3, ["Jeju", "Pangyo", "Seoul", "NewYork",
                   "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]))
