## Usage

1) Initialize submodules:
```bash
git submodule update --init --recursive
```

2) Make LibOpenCM3
```bash
cd libopencm3/
make
```

3) Building:
```bash
mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=../cmake/arm-toolchain.cmake ../

make
```

## Contributors

- **[S. Rappensperger](https://github.com/RabbeS/)**
- **[F. Hölzlwimmer](https://github.com/Hoeze/)**


#### Many thanks to **[David Mak](https://github.com/Derppening/)** and **[waicool20](https://github.com/waicool20)** for donating their cmake build system to this project!

## License

This project is licensed under GPLv3 - see [COPYING](COPYING) for details.

[libopencm3](https://github.com/libopencm3/libopencm3) is licensed under [LGPLv3](https://github.com/libopencm3/libopencm3/blob/master/COPYING.LGPL3).


