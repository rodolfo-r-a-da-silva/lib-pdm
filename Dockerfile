FROM alpine:latest

RUN apk update && apk add --no-cache \
        build-base \
        cmake \
        ruby

RUN gem install ceedling

WORKDIR /app

CMD ["/bin/sh"]