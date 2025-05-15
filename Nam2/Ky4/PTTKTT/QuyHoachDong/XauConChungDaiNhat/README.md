# Bài toán xâu con chung dài nhất (LCS - Longest Common Subsequence)

## Đề bài
Cho hai xâu ký tự X và Y. Hãy tìm tất cả các xâu con chung dài nhất của X và Y.

## Ý tưởng giải
- Sử dụng quy hoạch động (dynamic programming) để tính độ dài xâu con chung dài nhất (LCS).
- Dùng mảng C[i][j] lưu độ dài LCS của X[1..i] và Y[1..j].
- Dùng mảng P[i][j] (kiểu set<string>) lưu tất cả các xâu con chung dài nhất của X[1..i] và Y[1..j].

## Từng bước thuật toán

1. Khởi tạo:
   - C[0][j] = 0, C[i][0] = 0 với mọi i, j.
   - P[0][j] = {""}, P[i][0] = {""}.

2. Duyệt i từ 1 đến n, j từ 1 đến m:
   - Nếu X[i] == Y[j]:
     - C[i][j] = C[i-1][j-1] + 1
     - Nếu C[i][j] == 1: P[i][j] = {X[i]}
     - Nếu C[i][j] > 1: P[i][j] = {s + X[i] | s ∈ P[i-1][j-1]}
   - Nếu X[i] != Y[j]:
     - C[i][j] = max(C[i-1][j], C[i][j-1])
     - Nếu C[i-1][j] == C[i][j]: thêm tất cả xâu của P[i-1][j] vào P[i][j]
     - Nếu C[i][j-1] == C[i][j]: thêm tất cả xâu của P[i][j-1] vào P[i][j]

3. Kết quả là tất cả các xâu trong P[n][m].

## Minh họa chi tiết với ví dụ

Giả sử:
- X = "ABCBDAB"
- Y = "BDCABA"

### Bảng C[i][j] (độ dài LCS):

|   |   | B | D | C | A | B | A |
|---|---|---|---|---|---|---|---|
|   | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| A | 0 | 0 | 0 | 0 | 1 | 1 | 1 |
| B | 0 | 1 | 1 | 1 | 1 | 2 | 2 |
| C | 0 | 1 | 1 | 2 | 2 | 2 | 2 |
| B | 0 | 1 | 1 | 2 | 2 | 3 | 3 |
| D | 0 | 1 | 2 | 2 | 2 | 3 | 3 |
| A | 0 | 1 | 2 | 2 | 3 | 3 | 4 |
| B | 0 | 1 | 2 | 2 | 3 | 4 | 4 |

- Độ dài LCS là 4.

### Một số xâu con chung dài nhất:
- "BCBA"
- "BDAB"
- "BCAB"
- "BDAB"

### Bảng minh họa từng bước (rút gọn):

| i | j | X[i] | Y[j] | C[i][j] | P[i][j] cập nhật |
|---|---|------|------|---------|------------------|
| 1 | 4 |  A   |  A   |   1     | {A}              |
| 2 | 1 |  B   |  B   |   1     | {B}              |
| 3 | 3 |  C   |  C   |   2     | {BC}             |
| ... | ... | ... | ... | ... | ...              |
| 7 | 6 |  B   |  A   |   4     | {BCBA, BDAB, BCAB, BDAB} |

## Kết quả:
- Tất cả các xâu con chung dài nhất của X và Y là các xâu trong P[n][m].

---

**Lưu ý:**  
- Có thể có nhiều xâu con chung dài nhất khác nhau.
- Kết quả in ra là tất cả các xâu con chung dài nhất, không trùng lặp.
