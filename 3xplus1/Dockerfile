#FROM gcc:4.9
FROM ottoq/ubuntu:0.5
COPY . /usr/src/3xplus1
WORKDIR /usr/src/3xplus1
RUN gcc -o 3xplus1 main.c -lm
CMD ["./3xplus1"]