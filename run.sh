#! /bin/bash

Path=$(dirname $0)
cd $Path

make
./phasor_test
