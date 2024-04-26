#!/bin/bash

src_dir="src"
noc_src_dir="noc_src"

if [ ! -d $noc_src_dir ]; then
	cp -r $src_dir $noc_src_dir
fi

orig_src=$(find $noc_src_dir -name "*.c" -o -name "*.h")

for src_file in $orig_src
do
	./scripts/noc.pl $src_file > $src_file.temp
	mv $src_file.temp $src_file
done

