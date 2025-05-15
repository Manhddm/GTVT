# Bài toán sắp xếp balo (Bài toán cái túi - Knapsack)

## Đề bài
Cho n đồ vật, mỗi đồ vật có trọng lượng (KT[i]) và giá trị (GT[i]). Cho trước sức chứa tối đa của balo là M. Hỏi có thể chọn các đồ vật nào để tổng trọng lượng không vượt quá M mà tổng giá trị là lớn nhất?

## Ý tưởng giải
Sử dụng quy hoạch động (dynamic programming) để tối ưu hóa việc chọn các đồ vật:
- Định nghĩa C[i][j] là giá trị lớn nhất có thể đạt được khi xét i đồ vật đầu tiên và balo có sức chứa tối đa là j.
- Khởi tạo: C[0][j] = 0 với mọi j (chưa chọn vật nào thì giá trị là 0).
- Duyệt từng vật i từ 1 tới n, với từng sức chứa j từ 0 tới M:
  - Nếu không lấy vật i: C[i][j] = C[i-1][j]
  - Nếu lấy vật i (và j >= KT[i]): C[i][j] = max(C[i][j], C[i-1][j-KT[i]] + GT[i])
  - Nghĩa là: so sánh giá trị khi không lấy và khi lấy vật i, chọn giá trị lớn nhất.

## Minh họa thuật toán (không có truy vấn q)

Giả sử:
- n = 3
- KT = [2, 3, 4] (trọng lượng từng vật)
- GT = [3, 4, 5] (giá trị từng vật)
- Sức chứa balo M = 5

### Các bước thực hiện:
1. Bắt đầu với bảng giá trị C, ban đầu mọi giá trị đều là 0.
2. Xét từng vật, cập nhật giá trị lớn nhất có thể đạt được cho từng sức chứa.

### Bảng giá trị C[i][j] (i: số đồ vật, j: sức chứa):

| i\j | 0 | 1 | 2 | 3 | 4 | 5 |
|-----|---|---|---|---|---|---|
| 0   | 0 | 0 | 0 | 0 | 0 | 0 |
| 1   | 0 | 0 | 3 | 3 | 3 | 3 |
| 2   | 0 | 0 | 3 | 4 | 4 | 7 |
| 3   | 0 | 0 | 3 | 4 | 5 | 7 |

**Giải thích từng bước:**
- i=1: Chỉ xét vật 1 (trọng lượng 2, giá trị 3). Nếu sức chứa >=2 thì lấy được vật này, giá trị là 3.
- i=2: Xét thêm vật 2 (trọng lượng 3, giá trị 4). Nếu sức chứa >=3, có thể chọn vật này hoặc không, lấy giá trị lớn nhất.
  - Ví dụ sức chứa 5: lấy cả vật 1 và vật 2 được 3+4=7.

---

**Lưu ý:**  
Nếu không nhập q truy vấn, bạn có thể in ra bảng C[n][j] với j từ 0 đến M để xem giá trị lớn nhất cho từng sức chứa.
