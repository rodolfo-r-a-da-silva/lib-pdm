FROM alpine:latest

RUN apk update && apk add --no-cache \
        build-base \
        cmake \
        ruby \
        shadow

RUN gem install ceedling

ARG host_uid=1000
ARG host_gid=1000

RUN addgroup -g ${host_gid} pdmgrp && \
    adduser -u ${host_uid} -G pdmgrp -D pdmusr

USER pdmusr

RUN mkdir /home/pdmusr/project

WORKDIR /home/pdmusr/project

CMD ["/bin/sh"]