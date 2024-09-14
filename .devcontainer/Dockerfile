FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=nointeractive

RUN apt-get update \
	&& apt install -y -q \
	cmake \
	git \
	hwdata \
	linux-tools-virtual \
	udev \
	sudo \
	g++ \
	mosquitto \
	libpaho-mqtt-dev \
	libpaho-mqttpp-dev \
	protobuf-compiler \
	&& apt-get autoremove -y \
    && apt-get clean -y \
	&& rm -rf /var/lib/apt/lists/*

ENV LC_ALL=C.UTF-8
ENV LANG=C.UTF-8

RUN useradd \
      --create-home \
      --gid root \
      --groups sudo \
      --no-log-init \
      --shell /bin/bash \
      --system \
      dever && \
    echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
