# Bài toán đổi tiền (Coin Change)

## Đề bài
Cho n loại tiền có mệnh giá a₁, a₂, ..., aₙ. Hỏi với số tiền M, cần ít nhất bao nhiêu tờ tiền để đổi được đúng số tiền M? Nếu không thể đổi được thì in ra -1.

## Ý tưởng thuật toán

- Sử dụng quy hoạch động hai chiều: C[i][j] là số tờ tiền ít nhất để đổi được số tiền j chỉ dùng các loại tiền từ 1 đến i.
- Khởi tạo: C[0][j] = ∞ với mọi j > 0 (không dùng đồng nào thì không đổi được số tiền dương).
- Với mỗi loại tiền i, xét từng số tiền j từ 1 đến M:
    - Nếu không dùng đồng i: C[i][j] = C[i-1][j]
    - Nếu dùng đồng i (nếu j ≥ a[i]): C[i][j] = min(C[i][j], C[i][j-a[i]] + 1)

## Minh họa chi tiết

Giả sử:
- n = 3, M = 10
- a = [1, 7, 5]

Bảng C[i][j] (i: loại tiền, j: số tiền):

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|----|
|0  |∞  |∞  |∞  |∞  |∞  |∞  |∞  |∞  |∞  |∞   |
|1  |1  |2  |3  |4  |5  |6  |7  |8  |9  |10  |
|2  |1  |2  |3  |4  |5  |6  |1  |2  |3  |4   |
|3  |1  |2  |3  |4  |1  |2  |1  |2  |3  |2   |

- Dòng 1: chỉ dùng đồng 1, cần đúng j tờ cho số tiền j.
- Dòng 2: thêm đồng 7, với j ≥ 7 có thể dùng 1 tờ 7 + số tờ cho phần còn lại.
- Dòng 3: thêm đồng 5, với j ≥ 5 có thể dùng 1 tờ 5 + số tờ cho phần còn lại.

Ví dụ: Đổi 10 đồng:
- Dùng hai tờ 5 (C[3][10] = 2).

## Độ phức tạp

- Thời gian: O(n*M)
- Không gian: O(n*M)