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
-b,	--bin=DEC	convert decimal to binary
-d,	--dec=BIN	convert binary to decimal
-h,	--help		print this help
```

**Notes:**
* `-b` can be used multiple times in a single command

## todo

- [ ] remove replacable `fprintf()` with `log_err()`
- [ ] solve all the warnings resulting from make
- [ ] **document**: the *'core/ipv4.h'* functions, ...
- [X] make a script that remove comments from source code
- [X] rename functions and variables
- [ ] **Makefile:** organize the dependancy graph
- [X] **feat:** is network address?
- [X] **feat:** network address
- [ ] **feat:** usable host ip range
- [ ] **feat:** broadcast address
- [ ] **feat:** total number of hosts
- [ ] **feat:** number of usable hosts
- [ ] **feat:** subnet mask (for example *'/16'* <-> *'255.255.0.0'*)
- [ ] **feat:** wildcard mask
- [X] **feat:** binary ip add **feat:** ip class
- [ ] **feat:** **CIDR** notation (*/24*) of the subnet mask (*255.255.255.0*)
- [ ] **feat:** ip type: **public** or **private**
- [ ] **feat:** short notation, ex: `192.168.1.1/24`
- [ ] **feat:** all possible addresses for the ip address
- [ ] **feat:** table of the number of hosts per subnet
- [ ] use the [belformat](https://github.com/Artiom-Astashonak/belformat) library
- [ ] add some examples to that **README**
- [X] make an `ip` struct
- [X] use `getopt_long` or `getopt_long_only` instead of `getopt`
- [ ] handle errors like a pro
- [ ] think about making the while loop in `main` as the following steps:
	1. **check** for option
	2. **handle** option
	3. **log** errors
