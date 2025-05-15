# Bài toán chia của (Partition)

## Đề bài
Cho n tài sản có giá trị a₁, a₂, ..., aₙ. Chia n tài sản này cho 2 người sao cho chênh lệch tổng giá trị giữa 2 người là nhỏ nhất.

## Ý tưởng giải
- Duyệt tất cả các cách chia n tài sản thành 2 nhóm.
- Tính tổng giá trị mỗi nhóm, lấy hiệu tuyệt đối.
- Kết quả là hiệu nhỏ nhất tìm được.

## Minh họa chi tiết với ví dụ

Giả sử:
- n = 3
- a = [8, 4, 6]

Tổng M = 8 + 4 + 6 = 18

### Các cách chia:
- Chia 1: Người 1 nhận 8, Người 2 nhận 4+6=10 → chênh lệch |8-10| = 2
- Chia 2: Người 1 nhận 4, Người 2 nhận 8+6=14 → chênh lệch |4-14| = 10
- Chia 3: Người 1 nhận 6, Người 2 nhận 8+4=12 → chênh lệch |6-12| = 6
- Chia 4: Người 1 nhận 8+4=12, Người 2 nhận 6 → chênh lệch |12-6| = 6
- Chia 5: Người 1 nhận 8+6=14, Người 2 nhận 4 → chênh lệch |14-4| = 10
- Chia 6: Người 1 nhận 4+6=10, Người 2 nhận 8 → chênh lệch |10-8| = 2

### Kết quả:
- Chênh lệch nhỏ nhất là **2**.

## Thuật toán (theo code ChiaCua.cpp)
- Sử dụng quay lui (backtracking) để thử tất cả các cách chia.
- Tại mỗi bước, thử đưa tài sản thứ k vào nhóm 1 hoặc nhóm 2.
- Khi đã chia hết, cập nhật kết quả nhỏ nhất.

---

**Lưu ý:**  
Bài toán này là một dạng của bài toán chia tập con có tổng gần nhau nhất (Partition problem).
