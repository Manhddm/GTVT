# Bài toán Robot
[Bài toán](http://laptrinhonline.club/problem/tichpxrobot)

Ý tưởng giải bài:
    Sử dụng thuật toán BFS
minh họa thuật toán 
x =  10
y = 10
bước 1 khởi tạo:
queue: {10,10}
set: {10,10}

### Minh họa thuật toán theo code Robot.cpp

Giả sử nhập: x = 10, y = 10

#### Bước 1: Khởi tạo
- Queue: {(10, 10)}
- Set đã thăm: {(10, 10)}

#### Bước 2: Lặp BFS
- Lấy (10, 10) ra khỏi queue. In ra: 10 10
  - u = 10 (chẵn) ⇒ sinh (10, 5) → thêm vào queue và set
  - v = 10 (chẵn) ⇒ không sinh trạng thái mới
- Queue: {(10, 5)}
- Set: {(10, 10), (10, 5)}

- Lấy (10, 5) ra khỏi queue. In ra: 10 5
  - u = 10 (chẵn) ⇒ sinh (5, 5)
  - v = 5 (lẻ) ⇒ sinh (3, 10)
- Queue: {(5, 5), (3, 10)}
- Set: {(10, 10), (10, 5), (5, 5), (3, 10)}

- Lấy (5, 5) ra khỏi queue. In ra: 5 5
  - v = 5 (lẻ) ⇒ sinh (3, 5)
- Queue: {(3, 10), (3, 5)}
- Set: {(10, 10), (10, 5), (5, 5), (3, 10), (3, 5)}

- Lấy (3, 10) ra khỏi queue. In ra: 3 10
- Queue: {(3, 5)}

- Lấy (3, 5) ra khỏi queue. In ra: 3 5
  - v = 5 (lẻ) ⇒ sinh (3, 3)
- Queue: {(3, 3)}
- Set: ...

- Lấy (3, 3) ra khỏi queue. In ra: 3 3
  - v = 3 (lẻ) ⇒ sinh (2, 3)
- Queue: {(2, 3)}

- Lấy (2, 3) ra khỏi queue. In ra: 2 3
  - u = 2 (chẵn) ⇒ sinh (3, 1)
  - v = 3 (lẻ) ⇒ sinh (2, 2)
- Queue: {(3, 1), (2, 2)}

... (tiếp tục cho đến khi queue rỗng)

#### Kết thúc
- In ra số trạng thái khác nhau đã duyệt (vis.size()).

**Thuật toán sẽ in ra từng trạng thái duyệt được theo thứ tự BFS, và cuối cùng in ra tổng số trạng thái khác nhau mà robot có thể đạt được từ trạng thái ban đầu theo các quy tắc đã cho.**
