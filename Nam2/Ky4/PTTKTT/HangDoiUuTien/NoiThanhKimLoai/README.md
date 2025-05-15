# Thuật toán nối thanh kim loại tối ưu (Bài toán nối dây)

## Mô tả bài toán

Cho `n` thanh kim loại với độ dài lần lượt là `a1, a2, ..., an`. Mỗi lần nối hai thanh độ dài `a` và `b` sẽ tốn chi phí là `a + b`. Hỏi tổng chi phí nhỏ nhất để nối tất cả các thanh thành một thanh duy nhất là bao nhiêu?

## Các bước thuật toán

1. **Đưa tất cả các thanh vào một hàng đợi ưu tiên (min-heap)** để luôn lấy ra hai thanh ngắn nhất.
2. **Lặp lại cho đến khi chỉ còn một thanh:**
   - Lấy ra hai thanh ngắn nhất.
   - Nối chúng lại, cộng chi phí vào tổng chi phí.
   - Đưa thanh mới vừa nối vào lại min-heap.
3. **Kết quả** là tổng chi phí đã cộng.

## Minh họa chi tiết

Giả sử dãy số: `8 4 6`

- Bước 1: Đưa vào min-heap: `[4, 6, 8]`
- Bước 2: Lấy 4 và 6, nối lại được 10, chi phí = 10. Đưa 10 vào heap: `[8, 10]`
- Bước 3: Lấy 8 và 10, nối lại được 18, chi phí = 18. Đưa 18 vào heap: `[18]`
- Tổng chi phí: 10 + 18 = **28**

Nếu nối theo cách khác (ví dụ 8+4=12, rồi 12+6=18), tổng chi phí sẽ là 12+18=30 (không tối ưu).

## Độ phức tạp

- Thời gian: O(n log n)
- Không gian: O(n)
