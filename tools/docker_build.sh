#!/usr/bin/env sh

docker build \
    --build-arg host_uid=$(id -u $USER) \
    --build-arg host_gid=$(id -g $USER) \
    -t lib-pdm:latest $(dirname $(realpath $0))/../.
