#!/usr/bin/env sh

docker build -t lib-pdm:latest $(dirname $(realpath $0))/../.
