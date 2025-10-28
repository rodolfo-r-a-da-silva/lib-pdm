#!/usr/bin/env sh

docker run --rm -it \
    -v .:/app \
    lib-pdm:latest sh