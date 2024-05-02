# ipcalc
a cli tool for converting between decimal and binary versions of IPv4 and IPv6 addresses
and do some operations on IP addresses, check [features](#features) for more info.

## features
**SOON**

## usage
### requirements

* make
* gcc or clang


### installation

* initialization:
```sh
make init
```

* compiling and installing:
```sh
make install
```

* unistalling:
```sh
make uninstall
```


### available options
> [!NOTE]
> the only two options that works are **-b** and **-h**

```
-b, --bin=VER	convert decimal to binary
--isnet=ADDR	check if it is a network address
--isint=ADDR	check if it isan interface address
-t, --type		network type: interface|network
-h, --help		print this help
```

**Notes:**
* `-b` can be used multiple times in a single command

## TODO
### Fixes
- [ ] seg fault when using `--bin` with invalid ip version:
	```sh
	./build/ipcalc --bin=9 192.0.1.0
	```
	and another one when using `--isnet` without `-s`:
	```sh
	ipcalc --isnet 192.0.0.0
	```

### Document
- [ ] **document**: the *'core/ipv4.h'* functions, ...
- [ ] **document**: the `ipc_type()` function

### Makefile
- [ ] **Makefile:** add options: `install` and `uninstall`
- [ ] **Makefile:** organize the dependancy graph

### Features
- [X] **feat:** is network or interface ip address? (`--isnet`, `--isint`, `--type*`)
- [ ] **feat:** network address
- [ ] **feat:** broadcast address
- [ ] **feat:** usable host ip range
- [ ] **feat:** total number of hosts
- [ ] **feat:** number of usable hosts
- [ ] **feat:** subnet mask (for example *'/16'* <-> *'255.255.0.0'*)
- [ ] **feat:** wildcard mask
- [X] **feat:** binary ip (`--bin`)
- [ ] **feat:** ip class
- [ ] **feat:** **CIDR** notation (*/24*) of the subnet mask (*255.255.255.0*)
- [ ] **feat:** ip type: **public** or **private**
- [ ] **feat:** short notation, ex: `192.168.1.1/24`
- [ ] **feat:** all possible addresses for the ip address
- [ ] **feat:** table of the number of hosts per subnet

### Other
- [X] remove replacable `fprintf()` with `log_err()`
- [X] make `log_err()` accept multiple arguments like `printf()` family
- [ ] solve all the warnings resulting from `make`
- [X] make a script that remove comments from source code
- [ ] **no comments script**: deal with links, and other exceptions
- [X] rename functions and variables
- [ ] use the [belformat](https://github.com/Artiom-Astashonak/belformat) library
- [ ] add some examples to that **README**
- [X] make an `ip` struct
- [X] use `getopt_long` or `getopt_long_only` instead of `getopt`
- [ ] handle errors like a pro
- [ ] think about making the while loop in `main` as the following steps:
	1. **check** for option
	2. **handle** option
	3. **log** errors
- [ ] making some global options options subcommands, like `--bin` will be used without dashes (`bin`).
