# Bài toán đổi tiền (Coin Change) - Phương pháp quay lui (Backtracking)

## Đề bài
Cho n loại tiền có mệnh giá a₁, a₂, ..., aₙ. Hỏi cần ít nhất bao nhiêu tờ tiền để đổi được số tiền m (nếu không đổi được thì in -1).

## Ý tưởng giải (Backtracking)
- Thử tất cả các cách chọn số tờ tiền của từng mệnh giá, sao cho tổng tiền không vượt quá m.
- Với mỗi cách chọn, nếu tổng tiền đạt đúng m, cập nhật kết quả nhỏ nhất.
- Nếu không thể đổi được, in ra -1.

## Minh họa chi tiết với ví dụ:
Giả sử:
- n = 3, m = 10
- a = [1, 7, 5]

### Bảng minh họa các nhánh thử (Backtracking):

| Số tờ 1 đồng | Số tờ 7 đồng | Số tờ 5 đồng | Tổng tiền | Tổng số tờ | Hợp lệ |
|--------------|--------------|--------------|-----------|------------|--------|
| 0            | 0            | 2            | 10        | 2          | ✔      |
| 0            | 1            | 0            | 7         | 1          | ✗      |
| 1            | 0            | 1            | 6         | 2          | ✗      |
| 1            | 1            | 0            | 8         | 2          | ✗      |
| 2            | 0            | 1            | 7         | 3          | ✗      |
| 2            | 1            | 0            | 9         | 3          | ✗      |
| 3            | 0            | 1            | 8         | 4          | ✗      |
| 3            | 1            | 0            | 10        | 4          | ✔      |
| 5            | 1            | 0            | 12        | 6          | ✗      |
| 5            | 0            | 1            | 10        | 6          | ✔      |
| 10           | 0            | 0            | 10        | 10         | ✔      |

Chỉ những dòng có "Hợp lệ" là ✔ mới là đáp án hợp lệ.

### Kết quả:
- Số tờ ít nhất là **2** (2 tờ 5 đồng).

## Đặc điểm:
- Độ phức tạp cao nếu n hoặc m lớn.
- Đảm bảo tìm ra đáp án tối ưu (nếu có).

---

**Lưu ý:**  
Phương pháp này chỉ phù hợp với n, m nhỏ do số trường hợp thử là rất lớn.
