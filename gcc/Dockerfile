#FROM debian:bullseye-slim
FROM gcc:4.9
LABEL maintainer "Otto Quaglio <otto.q@gmx.com>"

FROM gcc:4.9
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o myapp main.c
CMD ["./myapp"]