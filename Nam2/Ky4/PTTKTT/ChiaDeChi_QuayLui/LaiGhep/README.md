# Bài toán Lai ghép

## Đề bài
Cho hai xâu nhiễm sắc thể X và Y (chỉ gồm các ký tự T, H, A, L, N) có cùng độ dài n. Hãy liệt kê tất cả các xâu con có thể tạo ra bằng cách, tại mỗi vị trí i (1 ≤ i ≤ n), chọn ký tự X[i] hoặc Y[i]. Kết quả liệt kê theo thứ tự từ điển.

## Ý tưởng giải
- Sử dụng quay lui (backtracking) để duyệt tất cả các cách chọn ký tự tại mỗi vị trí.
- Với mỗi vị trí i, chọn 1 trong 2 ký tự X[i] hoặc Y[i] (nếu giống nhau chỉ chọn 1).
- Khi đã chọn đủ n ký tự, thêm xâu vào danh sách kết quả.
- Sau khi sinh ra tất cả các xâu, sắp xếp kết quả theo thứ tự từ điển.

## Minh họa chi tiết với ví dụ

Giả sử:
- X = "TANAL"
- Y = "HANHL"

Ta có n = 5.

### Bảng các lựa chọn tại từng vị trí:

| Vị trí | Ký tự X | Ký tự Y | Lựa chọn      |
|--------|---------|---------|--------------|
| 1      | T       | H       | T hoặc H     |
| 2      | A       | A       | A            |
| 3      | N       | N       | N            |
| 4      | A       | H       | A hoặc H     |
| 5      | L       | L       | L            |

### Cây trạng thái sinh các xâu:

- 1. Chọn H ở vị trí 1:
    - 2. Chọn A ở vị trí 2
        - 3. Chọn N ở vị trí 3
            - 4. Chọn A ở vị trí 4 → HAL__
                - 5. Chọn L ở vị trí 5 → HANAL
            - 4. Chọn H ở vị trí 4 → HAN__
                - 5. Chọn L ở vị trí 5 → HANHL
- 1. Chọn T ở vị trí 1:
    - 2. Chọn A ở vị trí 2
        - 3. Chọn N ở vị trí 3
            - 4. Chọn A ở vị trí 4 → TAN__
                - 5. Chọn L ở vị trí 5 → TANAL
            - 4. Chọn H ở vị trí 4 → TAN__
                - 5. Chọn L ở vị trí 5 → TANHL

### Kết quả liệt kê:
| Kết quả |
|---------|
| HANAL   |
| HANHL   |
| TANAL   |
| TANHL   |

---

**Lưu ý:**  
- Nếu ký tự X[i] và Y[i] giống nhau, chỉ cần chọn 1 lần.
- Kết quả phải sắp xếp theo thứ tự từ điển.
