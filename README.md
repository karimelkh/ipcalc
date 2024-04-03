# ipcalc

a cli tool for converting between decimal and binary versions of IPv4 and IPv6 addresses

## usage

### requirements

* **make** - to compile source code
* ...


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


### usage

> [!NOTE]
> the only two options that works are **-b** and **-h**<br>
> **--bin** and **--help** are not working for now

```
-b,	--bin=DEC	convert decimal to binary
-d,	--dec=BIN	convert binary to decimal
-h,	--help		print this help
```
**Notes:**
* `-b` can be used multiple times in a single command
* ...

## todo

- [ ] Makefile:
	- [ ] organize the dependancy graph

- [ ] display:
    - [ ] network address
    - [ ] usable host ip range
    - [ ] broadcast address
    - [ ] total number of hosts
    - [ ] number of usable hosts
    - [ ] subnet mask (for example from */16* to *255.255.0.0*)
    - [ ] wildcard mask
    - [X] binary ip address
    - [ ] binary subnet mask
    - [ ] ip class
    - [ ] **CIDR** notation (*/24*) of the subnet mask (*255.255.255.0*)
    - [ ] ip type: **public** or **private**
    - [ ] short notation, ex: `192.168.1.1/24`
    - [ ] all possible addresses for the ip address
    - [ ] table of the number of hosts per subnet
    - [ ] ...

- [ ] use the [belformat](https://github.com/Artiom-Astashonak/belformat) library

- [ ] ...

<!--
don't forget to use
    * enums
    * bitwise operators
    * stdlib functions:
        * sscanf
        * 
    * arpa/inet functions:
        * inet_pton
        * inet_nton
        * 
-->
