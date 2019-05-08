Cấu trúc các file quan trọng trong thư mục:
│   detectEmo.py
│   environment.yml
│   myCNN.py
│   trainStation.py
├───datasets
│   └───fer2013
│           fer2013.csv
├───keras_model
│       fer2013myCNN.99-0.61.hdf5
├───utils
│   │   datasets.py
│   │   preprocessor.py


- detectEmo.py là file chạy thực thi chương trình nhận dạng chính.
- environment.yml là file cấu hình môi trường của anaconda - dùng để tạo môi trường nhanh.
- myCNN.py là file lưu mã nguồn model CNN.
- trainStation.py là file chạy thực thi huấn luyện mô hình.
- Thư mục datasets chứa bộ dữ liệu.
- Thư mục keras_model lưu các model đã được huấn luyện.
- Thư mục utils chứa các chương trình hỗ trợ cho chương trình chính.

*Cách chạy chương trình:
1. Cài đặt môi trường
- Cài Anaconda. Có thể tải trực tiếp từ https://anaconda.org/
- Xây dựng môi trường bằng Anaconda (có 2 cách)
    + Cách 1: tạo môi trường chuẩn được thiết kế bởi Anaconda bằng câu lệnh (bao gồm hầu hết các thư viện cần dùng)
        conda create -n <yourenvname> python=<x.x> anaconda     //với <yourenvname> là tên môi trường tùy ý, <x.x> là phiên bản python muốn dùng
    + Cách 2: tạo môi trường từ file environment.yml (chỉ chạy trên HĐH Windows, máy có GPU Nvidia vì nhóm thực hiện trên Windows và với GPU Nvidia GTX950m)
        conda env create -f environment.yml
- Kích hoạt môi trường chạy bằng lệnh:
        activate <yourenvname>
- Để bắt đầu huấn luyện, chạy lệnh:
        python trainStation.py
- Để bắt đầu chạy chương trình nhận dạng, chạy lệnh:
        python detectEmo.py

Lưu ý:
* Nếu trong quá trình chạy có bất kì lỗi nào về việc thiếu thư viện, có thể cài đặt 
thêm thư viện đó cho môi trường Anaconda bằng cách kích hoạt môi trường, sau đó chạy:
    conda install -c <packages-provider> <libraryname>
    Trong đó <packages-provider> và <libraryname> có thể dễ dàng tìm thấy trên kho dữ liệu đám mây của Anaconda, 
    ví dụ keras: https://anaconda.org/conda-forge/keras
