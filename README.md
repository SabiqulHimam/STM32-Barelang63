# STM32-Barelang63
Barelang63 STM32 program


## Download and Generate Project

1. Download Program 
```bash
  git clone https://github.com/SabiqulHimam/STM32-Barelang63.git
```

2. Buka Project dengan menggunakan STM32 Cube IDE

3. ganti nama program `main.cpp` menjadi `main.c` dan `Stm32f4xx_it.cpp` menjadi `Stm32f4xx_it.c`. 

3. Buka `STM32-Barelang63-main.ioc`, lalu setel pin aktuator dan sensor yang menggunakan STM32, lalu generate Project dengan menekan `Ctrl+S`

4. Kembalikan nama yang tadi diubah menjadi `main.cpp` dan `Stm32f4xx_it.cpp` kembali.

## Setting aktuator

1. Buka `mainpp.h`

2. Sesuaikan pin motor dan IMU pada define yang sudah ada


## Setting Encoder

1. Buka `Stm32f4xx_it.cpp`

2. Masukkan fungsi `Encoder*->Counting();` pada interrupt encoder sesuai dengan urutan encoder. Jika pembacaan encoder terbalik, gunkan fungsi `Encoder*->CountingReverse();` agar pembacaan encoder menjadi normal.







