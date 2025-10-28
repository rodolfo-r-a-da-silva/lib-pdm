#!/usr/bin/env sh

docker run --rm -it \
    -v .:/home/pdmusr/project \
    lib-pdm:latest sh