# Bài toán Lập lịch (Activity Selection Problem)

## Đề bài
Toto được giao làm chủ tịch công ty, cần chọn nhiều công việc nhất sao cho các công việc không giao nhau (không trùng thời gian).  
Mỗi công việc có thời gian bắt đầu sᵢ và kết thúc fᵢ (sᵢ < fᵢ).  
Chọn tập công việc lớn nhất mà không có hai công việc nào giao nhau.

## Ý tưởng giải
- Sắp xếp các công việc theo thời gian kết thúc tăng dần.
- Duyệt từng công việc, nếu thời gian bắt đầu của công việc hiện tại lớn hơn thời gian kết thúc của công việc trước đó đã chọn, thì chọn công việc này.

## Minh họa chi tiết với ví dụ

Giả sử:
- n = 5
- Danh sách công việc (s, f):

| Công việc | Bắt đầu (s) | Kết thúc (f) |
|-----------|-------------|--------------|
| 1         | 4           | 7            |
| 2         | 2           | 8            |
| 3         | 3           | 6            |
| 4         | 7           | 9            |
| 5         | 9           | 12           |

### Bước 1: Sắp xếp theo thời gian kết thúc

| Công việc | Bắt đầu | Kết thúc |
|-----------|---------|----------|
| 3         | 3       | 6        |
| 1         | 4       | 7        |
| 2         | 2       | 8        |
| 4         | 7       | 9        |
| 5         | 9       | 12       |

### Bước 2: Duyệt chọn công việc

| Công việc | Bắt đầu | Kết thúc | Có chọn không? | Lý do                |
|-----------|---------|----------|----------------|----------------------|
| 3         | 3       | 6        | ✔              | Đầu tiên, luôn chọn  |
| 1         | 4       | 7        | ✗              | 4 < 6 (bị giao nhau) |
| 2         | 2       | 8        | ✗              | 2 < 6 (bị giao nhau) |
| 4         | 7       | 9        | ✔              | 7 > 6                |
| 5         | 9       | 12       | ✔              | 9 > 9 (bằng, không chọn), 9 >= 9 (chọn nếu không trùng) |

### Kết quả:
- Số công việc chọn được nhiều nhất: **2**
- Các công việc được chọn: (3,6) và (7,9) hoặc (3,6) và (9,12)

---

**Lưu ý:**  
- Luôn ưu tiên chọn công việc kết thúc sớm nhất để dành thời gian cho các công việc sau.
- Đây là một bài toán kinh điển về tham lam (greedy).
