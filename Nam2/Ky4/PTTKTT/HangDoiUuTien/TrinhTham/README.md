# Thuật toán tìm giá trị lớn nhất trong mỗi đoạn con độ dài k (Sliding Window Maximum)

## Mô tả bài toán

Cho dãy số gồm `n` phần tử và số nguyên `k`. Với mỗi vị trí `i` (từ `k` đến `n`), hãy tìm giá trị lớn nhất trong đoạn con gồm `k` phần tử kết thúc tại vị trí `i`.

## Các bước thuật toán

1. **Khởi tạo** một hàng đợi ưu tiên (priority queue) để lưu các cặp giá trị `(giá trị, vị trí)` của các phần tử.
2. **Duyệt** từng phần tử của dãy số:
   - Đưa phần tử hiện tại vào hàng đợi ưu tiên cùng với chỉ số của nó.
   - Loại bỏ các phần tử ở đầu hàng đợi nếu chúng nằm ngoài đoạn con độ dài `k` (tức là chỉ số của chúng nhỏ hơn `i - k + 1`).
   - Nếu đã duyệt đủ `k` phần tử, in ra giá trị lớn nhất hiện tại (phần tử đầu hàng đợi).
3. **Lặp lại** cho đến hết dãy số.

## Minh họa chi tiết

Giả sử dãy số là: `1 3 -1 -3 5 3 6 7`, `n = 8`, `k = 3`.

| i | Giá trị đọc vào | Hàng đợi ưu tiên (giá trị, vị trí) | Kết quả in ra |
|---|----------------|-------------------------------------|---------------|
| 1 | 1              | (1,1)                               |               |
| 2 | 3              | (3,2), (1,1)                        |               |
| 3 | -1             | (3,2), (1,1), (-1,3)                | 3             |
| 4 | -3             | (3,2), (1,1), (-1,3), (-3,4)        | 3             |
| 5 | 5              | (5,5), (3,2), (1,1), ...            | 5             |
| 6 | 3              | (5,5), (3,6), ...                   | 5             |
| 7 | 6              | (6,7), (5,5), ...                   | 6             |
| 8 | 7              | (7,8), (6,7), ...                   | 7             |

- Ở mỗi bước, loại bỏ các phần tử đã ra khỏi cửa sổ độ dài `k`.
- Kết quả cuối cùng: `3 3 5 5 6 7`

## Độ phức tạp

- Thời gian: O(n log k)
- Không gian: O(k)
