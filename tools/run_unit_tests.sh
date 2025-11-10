#!/usr/bin/env sh

echo "Cleaning previous tests executions"

rm -rf $(dirname $(readlink -f $0))/../build/test

ceedling test:all
