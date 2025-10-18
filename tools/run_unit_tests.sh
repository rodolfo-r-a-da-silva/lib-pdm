#!/usr/bin/env bash

echo "Cleaning previous tests executions"

rm -rf $(dirname $(realpath $BASH_SOURCE))/../build/test

ceedling test:all
