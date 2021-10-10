#FROM gcc:4.9
FROM ottoq/ubuntu:0.5
COPY . /usr/src/3xplus1
WORKDIR /usr/src/3xplus1

RUN git clone --depth 1 --branch master https://github.com/ShashankBongale/Large_Integer_Module.git /usr/lib/intal

#RUN gcc -o 3xplus1 3xplus1.c -lm -O3 -I/usr/lib/intal
RUN gcc -o 3xplus1 3xplus1.c /usr/lib/intal/intal_source.c -lm -O3 -I/usr/lib/intal
CMD ["./3xplus1"]