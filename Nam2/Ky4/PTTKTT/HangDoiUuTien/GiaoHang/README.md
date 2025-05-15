# Thuật toán giao hàng tối ưu (Deadline Scheduling)

## Mô tả bài toán

Có `n` món hàng, mỗi món hàng thứ `i` có hạn giao là `t_i` và phần thưởng nếu giao đúng hạn là `v_i`. Mỗi đơn hàng chỉ giao được một lần trong một đơn vị thời gian, và mỗi thời điểm chỉ giao được một đơn hàng. Hãy chọn cách giao để tổng phần thưởng là lớn nhất.

## Các bước thuật toán

1. **Nhóm các đơn hàng theo hạn giao**: Đưa phần thưởng của các đơn hàng có cùng hạn vào cùng một nhóm.
2. **Duyệt ngược thời gian từ hạn lớn nhất về 1**:
   - Ở mỗi thời điểm, đưa tất cả phần thưởng của các đơn hàng có hạn đúng thời điểm đó vào một hàng đợi ưu tiên (max-heap).
   - Nếu heap không rỗng, chọn đơn hàng có phần thưởng lớn nhất để giao (lấy ra khỏi heap và cộng vào tổng thưởng).
3. **Lặp lại** cho đến khi hết thời gian.

## Minh họa chi tiết

Ví dụ:  
Input:  
```
6
3 5
3 7
2 6
2 4
1 2
1 1
```

- Nhóm theo hạn:
  - t=3: [5, 7]
  - t=2: [6, 4]
  - t=1: [2, 1]

- Duyệt từ t=3 về t=1:
  - t=3: Đưa 5, 7 vào heap → chọn 7 (res=7)
  - t=2: Đưa 6, 4 vào heap → heap còn 5, 6, 4 → chọn 6 (res=13)
  - t=1: Đưa 2, 1 vào heap → heap còn 5, 4, 2, 1 → chọn 5 (res=18)

Nhưng chỉ được giao 1 đơn mỗi thời điểm, nên:
- t=3: chọn 7
- t=2: chọn 6
- t=1: chọn 4

Tổng thưởng: 7 + 6 + 4 = **17**

## Độ phức tạp

- Thời gian: O(n log n)
- Không gian: O(n)
