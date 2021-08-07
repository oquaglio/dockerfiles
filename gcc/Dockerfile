#FROM debian:bullseye-slim
FROM debian:latest
LABEL maintainer "Otto Quaglio <otto.q@gmx.com>"

RUN apt-get update && apt-get install -y \
	gcc \
	libc6-dev \
	--no-install-recommends \
	&& rm -rf /var/lib/apt/lists/*
