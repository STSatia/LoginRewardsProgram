Dự án này cần:

A - Chức năng:
    1: Tạo mới tài khoản khi đăng kí: tạo mới bộ dữ liệu liên quan đến tài khoản người dùng.            - Done
        Người dùng nhập dữ liệu để tạo tài khoản.                                                       - Done
        Có thể có nhân viên nhập liệu (người quản lý) để tạo tài khoản hộ người dùng, với điều kiện     - Done
            người dùng cung cấp đầy đủ thông tin cá nhân theo yêu cầu tạo tài khoản.
        
        Phân tích và đề xuất một cấu trúc dữ liệu (lớp) quản lý thông tin tài khoản người dùng.         - Dùng JSON file.

    2 - Lưu trữ dữ liệu: lưu lại dữ liệu tài khoản người dùng xuống tập tin                             - Dùng JSON file.
        Hãy đề xuất việc lưu trữ dữ liệu người dùng dưới dạng tập tin riêng cho từng người
        hay là một tập tin cho tất cả người dùng? Nêu lý do lựa chọn giải pháp.
        
        Với mật khẩu, hãy tìm hiểu cách lưu mật khẩu của người dùng vào cơ sở dữ liệu. (Dùng hash function)

        Mọi lưu trữ phải có bản sao lưu (backup). Tìm hiểu quy trình sao lưu - phục hồi dữ liệu. Đề xuất giải pháp sao lưu cho dữ liệu người dùng.
        

    3 - Quản lý đăng nhập
        3.1 - Sinh mật khẩu tự động: sinh một mật khẩu tự động kèm theo thông tin đăng nhập của người dùng trong trường hợp người dùng không cung cấp mật khẩu.

        Trường hợp này thường được sử dụng khi nhân viên quản lý mở tài khoản mới và người dùng không thể trực tiếp nhập mật khẩu cho mình.

        3.2 - Thay đổi mật khẩu: một người dùng có thể tự thay đổi mật khẩu đăng nhập của mình.

        Hãy tìm hiểu quy trình xử lý thay đổi mật khẩu.

        Với trường hợp mật khẩu tự sinh, hệ thống phải kiểm tra mật khẩu là tự sinh và yêu cầu người dùng thay đổi ngay mật khẩu mới trong lần đăng nhập đầu tiên của mình.

        3.3 - OTP - One Time Password: bảo mật hai lớp để xác thực giao dịch.

        OTP được sử dụng trong đồ án này để xác thực các hoạt động thay đổi thông tin quan trọng của người dùng.

        Hãy tìm hiểu về OTP và đề xuất giải pháp OTP cho đồ án.

        3.4 - Đăng nhập - Khi người dùng đăng nhập bằng tài khoản của mình, chương trình phải tìm kiếm trong dữ liệu đã lưu trữ và xác định liệu thông tin đăng nhập đó có tồn tại và hợp lệ không. Nếu hợp lệ, cho phép người dùng vào hệ thống và sử dụng các chức năng tương ứng.


B - Phân chia người dùng và chức năng:

    Nhóm người dùng gồm:
        a - Người dùng thông thường, chỉ được phép truy xuất thông tin cá nhân của mình.
        Được phép điều chỉnh tên, mật khẩu. Hãy căn cứ vào quản lý thông tin tài khoản trên để đưa ra yêu cầu cho phép điều chỉnh, thay đổi trường dữ liệu cụ thể và viết các chức năng cập nhật tương ứng.

        Khi điều chỉnh xong, hệ thống gửi một mã OTP đến chủ tài khoản cùng thông báo các nội dung sẽ thay đổi để chủ tài khoản xác nhận thao tác cập nhật.

        Nếu mã OTP do chủ tài khoản nhập vào hợp lệ, hệ thống tiến hành cập nhật thông tin của người dùng.
        
        b - người dùng quản lý: ngoài chức năng quản lý thông tin cá nhân, người quản lý có thể:
        b1 - theo dõi danh sách nhóm
        b2 - tạo thêm tài khoản mới
        b3 - điều chỉnh thông tin của tài khoản khi có yêu cầu từ chủ tài khoản (làm hộ). Khi điều chỉnh
        xong, hệ thống gửi một mã OTP đến chủ tài khoản cùng thông báo các nội dung sẽ thay đổi chủ đề 
        chủ tài khoản xác nhận thao tác cập nhật.

        Nếu mã OTP do chủ tài khoản nhập vào hợp lệ, hệ thống tiến hành cập nhật thông tin của người dùng

        Chú ý: Không được phép thay đổi tên tài khoản đăng nhập

        C. Quản lý hoạt động ví:

        Mỗi người dùng có một bộ dữ liệu về số điểm (ví - wallet) và dữ liệu các giao dịch trao đổi, chuyển điểm từ một ví sang một ví khác.
        Một ví có mã số định danh duy nhất phân biệt với tất cả các ví còn lại.
        Ví tổng: nguồn duy nhất sinh ra tổng số điểm sẽ lưu chuyển trong toàn bộ hệ thống.

        Giao dịch chuyển d điểm từ ví A sang ví B sẽ bao gồm các thao tác thành phần sau:

        1_ tìm, mở ví A: Đây là ví chủ của giao dịch, là ví của chủ tài khoản muốn thực hiện chuyển điểm đi.
        2_ tìm, mở ví B: đây là ví đích của giao dịch. Nếu mã ví B tồn tại, tiếp tục đến 3_ Giao dịch
        3_ Giao dịch: Hai tác vụ dưới đây là không tách rời (atomic). Bất kì có một bất thường (exception)
        nào xảy ra trong một tác vụ đều dẫn đến hủy toàn bộ giao dịch, phục hồi lại trạng thái số dư của hai ví.
        3_1: if A.balance >= d thì A.balance = A.balance - d
             else "Low balance, cannot proceed". 
        3_2: B.balance = B.balance + d
        4_: Kết thúc

    
    - Hãy đề xuất cách sử dụng OTP để xác nhận thực hiện giao dịch chuyển điểm giữa các ví.
 

Hệ thống ghi nhận lại giao dịch này trong lịch sử giao dịch (transaction log)

Báo cáo: hệ thống cho phép người dùng theo dõi số dư, lịch sử giao dịch (và trạng thái thực hiện giao dịch)
