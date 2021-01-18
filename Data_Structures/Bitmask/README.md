### 원소의 포함 여부 확인

    bitset & (1 << p)

### 원소의 추가

    bitset |= (1 << p)

### 원소의 삭제

    bitset &= ~(1 << p)

### 원소의 토글

    bitset ^= (1 << p)

### 두 집합에 대한 연산

    union = a | b
    intersection = a & b
    difference = a & ~b
    exclusive_or = a ^ b

### 집합의 크기

```python
bin(bitset).count('1')
```

### 최소 원소 찾기

    bitset & ~bitset

### 최소 원소 지우기

    bitset &= (bitset - 1)

### 모든 부분 집합 순회

```python
subset = bitset
while subset:
    ...
    subset = (subset - 1) & bitset
```
