#!/bin/bash

b_dir="build"

# mkdir build dir
if [ ! -d "$b_dir" ]; then
	mkdir "$b_dir"
fi

# ensure that `belformat` was installed correctly
# export LD_LIBRARY_PATH='/usr/local/lib:$LD_LIBRARY_PATH'

# success!!
echo "project initialized successfully"
