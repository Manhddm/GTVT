# Bài toán đổi tiền (Coin Change) - Phương pháp quy hoạch động (Dynamic Programming)

## Đề bài
Cho n loại tiền có mệnh giá a₁, a₂, ..., aₙ. Hỏi cần ít nhất bao nhiêu tờ tiền để đổi được số tiền m (nếu không đổi được thì in -1).

## Ý tưởng giải (Dynamic Programming)
- dp[x]: số tờ tiền ít nhất để đổi được x đồng.
- Khởi tạo dp[0] = 0, các dp[x] khác = ∞ (hoặc giá trị rất lớn).
- Với mỗi loại tiền, cập nhật:  
  dp[j] = min(dp[j], dp[j - a[i]] + 1) với mọi j ≥ a[i].

## Minh họa với ví dụ:
Giả sử:
- n = 3, m = 10
- a = [1, 7, 5]

### Các bước thực hiện:
1. Khởi tạo dp[0] = 0, dp[1..10] = ∞.
2. Với từng mệnh giá, cập nhật dp như sau:

| m (số tiền cần đổi) | dp[m] sau khi tính | Cách chọn tờ tiền |
|---------------------|-------------------|-------------------|
| 1                   | 1                 | 1                 |
| 2                   | 2                 | 1+1               |
| 3                   | 3                 | 1+1+1             |
| 4                   | 4                 | 1+1+1+1           |
| 5                   | 1                 | 5                 |
| 6                   | 2                 | 5+1               |
| 7                   | 1                 | 7                 |
| 8                   | 2                 | 7+1               |
| 9                   | 3                 | 7+1+1             |
| 10                  | 2                 | 5+5 hoặc 7+1+1+1  |

### Kết quả:
- Đổi 10: cần 2 tờ (5+5)
- Nếu không thể đổi được số tiền m nào đó, dp[m] sẽ vẫn là ∞, in ra -1.

## Đặc điểm:
- Độ phức tạp O(n*m), phù hợp với n, m lớn vừa phải.
- Đảm bảo tìm ra đáp án tối ưu (nếu có).

---

**Lưu ý:**  
Phương pháp này hiệu quả hơn quay lui khi n, m lớn.