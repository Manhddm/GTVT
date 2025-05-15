# Bài toán Buôn dưa lê

## Đề bài
Có n thửa ruộng, mỗi thửa ruộng khi bắt đầu chín thì phải thu hoạch trong vòng k ngày, mỗi ngày chỉ được thu hoạch tối đa m đơn vị sản lượng. Hỏi tổng sản lượng lớn nhất Tito có thể thu hoạch được là bao nhiêu?

## Các bước thuật toán

1. **Khởi tạo** một hàng đợi (queue) để lưu sản lượng các thửa ruộng đang trong thời gian thu hoạch (cửa sổ k ngày).
2. **Duyệt từng ngày** từ 1 đến n+k-1:
   - Nếu còn thửa ruộng mới, thêm sản lượng của thửa ruộng đó vào queue, nếu không thì thêm 0.
   - Nếu queue có nhiều hơn k phần tử, loại bỏ phần tử đầu (đã quá hạn thu hoạch).
3. **Mỗi ngày**, thu hoạch tối đa m đơn vị:
   - Lấy lần lượt các thửa ruộng trong queue, ưu tiên thửa chín sớm (đầu queue).
   - Nếu tổng đã thu hoạch trong ngày + sản lượng thửa ruộng <= m, lấy hết thửa ruộng đó.
   - Nếu không, chỉ lấy phần còn lại đủ m, cập nhật lại sản lượng thửa ruộng đầu queue.
   - Cộng tổng sản lượng thu hoạch trong ngày vào kết quả.
4. **Lặp lại** cho đến hết các ngày.

## Minh họa với ví dụ

Giả sử:
- n = 6, k = 2, m = 5
- a = [4, 7, 2, 18, 1, 10]

| Ngày | Queue trước | Thêm vào | Queue sau thêm | Thu hoạch | Queue sau thu hoạch | Tổng |
|------|------------|----------|---------------|-----------|---------------------|------|
| 1    | []         | 4        | [4]           | 4         | []                  | 4    |
| 2    | []         | 7        | [7]           | 5         | [2]                 | 9    |
| 3    | [2]        | 2        | [2,2]         | 4         | []                  | 13   |
| 4    | []         | 18       | [18]          | 5         | [13]                | 18   |
| 5    | [13]       | 1        | [13,1]        | 5         | [8,1]               | 23   |
| 6    | [8,1]      | 10       | [8,1,10]      | 5         | [3,1,10]            | 28   |
| 7    | [3,1,10]   | 0        | [3,1,10]      | 5         | [0,1,10]            | 33   |

- Tổng sản lượng thu hoạch tối đa: **33**

---

**Lưu ý:**  
Thuật toán sử dụng kỹ thuật tham lam và hàng đợi để đảm bảo luôn ưu tiên thu hoạch các thửa ruộng chín sớm nhất trong giới hạn mỗi ngày.
