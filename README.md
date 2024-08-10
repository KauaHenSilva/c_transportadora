# Carrier in C

A simple project that simulates the routes of a carrier. The application was built using the C language, Meson, and Ninja.

## 🚀 Getting Started

Follow the instructions below to have the project running locally.

## ❤️ Contribution

Contributions are welcome! To contribute, favorite the project and give your opinion about it!

## 🐬 Improve the Project.

Help improve the project! Fork it and develop your creativity!

>https://github.com/KauaHenSilva/c_delivery_carrier


## 📋 Prerequisites (Installation Docker) (Linux)

The project was developed in the Ubuntu environment, so the commands may vary according to the operating system. The project uses the following dependencies: 

### Docker
  
  ```bash
  sudo apt-get -y install docker
  ```


## 📋 Prerequisites (Installation Local) (Linux)

The project was developed in the Ubuntu environment, so the commands may vary according to the operating system. The project uses the following dependencies: 

### GCC 

  ```bash
  sudo apt install build-essential
  ```

### Meson 

  ```bash
  sudo apt-get -y install meson 
  ```

### Ninja 

  ```bash
  sudo apt-get -y install ninja-build
  ```


## 📦 Local Installation  (Linux)
To install the project locally, follow the steps below:

1. **Clone this repository:**

  ```bash
  git clone https://github.com/KauaHenSilva/c_delivery_carrier
  ```
2. **Navigate to the project directory:**

  ```bash
  cd c_app_list_enc
  ```
3. **setup:**

  ```bash
  meson setup builddir
  ```
4. **build:**

  ```bash
  ninja -C builddir
  ```

5. **run:**

  ```bash
  ./builddir/src/<nameEXE>
  ```
