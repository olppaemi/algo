### 순차 탐색

```python
def sequential_search(array, target):
  n = len(array)
  for i in range(n):
    if array[i] == target:
      return i
```

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
