# 분할 정복

분할 정복은 문제를 여러 작은 부분 문제로 나누어서 이 부분 문제들을 해결하고, 해결된 부분 문제들을 결합해 원래 문제의 해를 구하는 방법이다.

1. 원래 문제를 부분 문제로 나눈다. (Divide)
2. 나눈 부분 문제를 일정 크기가 되면 푼다. (Conquer)
3. 해결된 부분 문제를 결합해 원래 문제를 해결한다. (Combine)

### 이진 탐색 (1)

```python
def binary_search(array, target, start, end):
  if start > end:
    return None
  mid = (start + end) // 2
  if array[mid] == target:
    return mid
  elif array[mid] > target:
    return binary_search(array, target, start, mid - 1)
  else:
    return binary_search(array, target, mid + 1, end)
```

### 이진 탐색 (2)

```python
def binary_search(array, target, start, end):
  while start <= end:
    mid = (start + end) // 2
    if array[mid] == target:
      return mid
    elif array[mid] < target:
      end = mid - 1
    else:
      start = mid + 1
  return None
```
