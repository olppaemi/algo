## 그래프 순회

### 1. DFS

<details>
<summary>Python</summary>

```python
def dfs(graph, now, visited):
  visited[now] = True
  print(now)

  for next in graph[now]:
    if not visited[next]:
      dfs(graph, next, visited)
```

</details>

### 2. BFS

<details>
<summary>Python</summary>

```python
def bfs(graph, start, visited):
  queue = deque([start])
  visited[start] = True

  while queue:
    now = queue.popleft()
    print(now)

    for next in graph[now]:
      if not visited[next]:
        queue.append(next)
        visited[i] = True
```

</details>

## 최단 경로

### 1. 다익스트라 알고리즘

<details>
<summary>Python</summary>

```python
def dijkstra(start):
  q = []
  heappush(q, (0, start))
  distance[start] = 0

  # 큐가 비어있지 않다면
  while q:
    # 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
    dist, now = heappop(q)
    # 현재 노드가 이미 처리된 적이 있는 노드라면 무시
    if distance[now] < dist:
      continue

    for next in graph[now]:
      cost = dist + next[1]
      # 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
      if cost < distance[next[0]]:
        distance[next[0]] = cost
        heappush(q, (cost, next[0]))
```

</details>

### 2. 플로이드-워셜

<details>
<summary>Python</summary>

```python
for k in range(1, n + 1):
  for a in range(1, n + 1):
    for b in range(1, n + 1):
      graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])
```

</details>

## 최소 신장 트리

<details>
<summary>Python</summary>

```python
def find(u):
  if parent[u] != u:
    parent[u] = find(parent[u])
  return parent[u]

def union(u, v):
  u = find(u)
  v = find(v)
  if u < v:
    parent[v] = u
  else:
    parent[u] = v

answer = 0
for edge in edges:
  cost, u, v = edge
  if find(u) != find(v):
    union(u, v)
    answer += cost

print(answer)
```

</details>
