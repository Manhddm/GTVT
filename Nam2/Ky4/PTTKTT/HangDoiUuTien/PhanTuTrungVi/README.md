# Thuật toán tìm phần tử trung vị động (Median of Stream)

## Mô tả bài toán

Cho dãy số gồm `n` phần tử. Sau mỗi lần thêm một phần tử vào dãy, hãy xuất ra phần tử trung vị của dãy con hiện tại.

- Trung vị là phần tử ở vị trí giữa khi dãy được sắp xếp (nếu số lượng phần tử lẻ), hoặc là phần tử nhỏ hơn trong hai phần tử giữa (nếu số lượng phần tử chẵn).

## Các bước thuật toán

1. **Khởi tạo** hai hàng đợi ưu tiên:
   - `l`: max-heap (ưu tiên phần tử lớn nhất bên trái)
   - `r`: min-heap (ưu tiên phần tử nhỏ nhất bên phải)
2. **Duyệt từng phần tử** của dãy:
   - Nếu số lượng phần tử hiện tại là lẻ, thêm phần tử vào max-heap `l`.
   - Nếu là chẵn, thêm vào min-heap `r`.
3. **Đảm bảo tính chất**: mọi phần tử trong `l` đều nhỏ hơn hoặc bằng mọi phần tử trong `r`.
   - Nếu `l.top() > r.top()`, hoán đổi hai phần tử đầu của hai heap.
4. **In ra trung vị**: luôn là `l.top()` sau mỗi lần thêm phần tử.

## Minh họa chi tiết

Giả sử dãy số: `7 4 2 1 6 5 8 5 7`

| Bước | Dãy con hiện tại | max-heap (l) | min-heap (r) | Trung vị |
|------|------------------|--------------|--------------|----------|
| 1    | 7                | 7            |              | 7        |
| 2    | 7 4              | 4            | 7            | 4        |
| 3    | 7 4 2            | 4 2          | 7            | 4        |
| 4    | 7 4 2 1          | 2 1          | 4 7          | 2        |
| 5    | 7 4 2 1 6        | 4 1 2        | 6 7          | 4        |
| 6    | 7 4 2 1 6 5      | 4 1 2        | 5 6 7        | 4        |
| 7    | 7 4 2 1 6 5 8    | 5 4 2 1      | 6 7 8        | 5        |
| 8    | 7 4 2 1 6 5 8 5  | 5 4 2 1      | 5 6 7 8      | 5        |
| 9    | 7 4 2 1 6 5 8 5 7| 5 5 2 1 4    | 6 7 8        | 5        |

Kết quả in ra: `7 4 4 2 4 4 5 5 5`

## Độ phức tạp

- Thời gian: O(n log n)
- Không gian: O(n)
