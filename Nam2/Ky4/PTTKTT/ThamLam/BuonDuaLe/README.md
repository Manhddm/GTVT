# Bài toán Buôn dưa lê

## Đề bài
Có n thửa ruộng, mỗi thửa ruộng khi bắt đầu chín thì phải thu hoạch trong vòng k ngày, mỗi ngày chỉ được thu hoạch tối đa m đơn vị sản lượng. Hỏi tổng sản lượng lớn nhất Tito có thể thu hoạch được là bao nhiêu?

## Ý tưởng giải
- Duyệt từng ngày, mỗi ngày xét các thửa ruộng đang chín trong cửa sổ k ngày.
- Mỗi ngày chỉ thu hoạch tối đa m đơn vị, ưu tiên thu hoạch các thửa ruộng chín sớm hơn.
- Sử dụng hàng đợi (queue) để quản lý các thửa ruộng trong cửa sổ k ngày.

## Minh họa với ví dụ:
Giả sử:
- n = 6, k = 2, m = 5
- a = [4, 7, 2, 18, 1, 10]

### Các bước thực hiện:
- Ngày 1: Thêm 4 vào queue. Thu hoạch tối đa 4 (vì m=5), còn lại 0. Tổng = 4.
- Ngày 2: Thêm 7 vào queue. Thu hoạch tối đa 5 (lấy hết 7, còn lại 2). Tổng = 4+5=9.
- Ngày 3: Thêm 2 vào queue. Thu hoạch tối đa 5 (lấy hết 2, còn lại 0; lấy tiếp 2 còn lại từ ngày trước, hết 2, còn lại 0). Tổng = 9+4=13.
- Ngày 4: Thêm 18 vào queue. Thu hoạch tối đa 5 (lấy 5 từ 18, còn lại 13). Tổng = 13+5=18.
- Ngày 5: Thêm 1 vào queue. Thu hoạch tối đa 5 (lấy 5 từ 13 còn lại, còn lại 8). Tổng = 18+5=23.
- Ngày 6: Thêm 10 vào queue. Thu hoạch tối đa 5 (lấy 5 từ 8 còn lại, còn lại 3). Tổng = 23+5=28.
- Ngày 7: Thêm 0 vào queue (không còn ruộng mới). Thu hoạch tối đa 5 (lấy 3 từ 3 còn lại, còn lại 0; lấy tiếp 2 từ 10, còn lại 8). Tổng = 28+5=33.

### Kết quả:
- Tổng sản lượng thu hoạch tối đa: **33**

---

**Lưu ý:**  
Bài toán sử dụng kỹ thuật tham lam kết hợp hàng đợi để tối ưu hóa sản lượng thu hoạch mỗi ngày.
