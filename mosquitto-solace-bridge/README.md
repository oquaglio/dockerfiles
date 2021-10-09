# Mosquitto to Solace Bridge <!-- omit in toc -->
- [About](#about)
- [Docker](#docker)
- [Solace](#solace)
  - [Ports](#ports)
- [Mosquitto](#mosquitto)
- [MySQL](#mysql)
- [PhpMyAdmin](#phpmyadmin)
- [References](#references)
  - [haproxy Docker](#haproxy-docker)
  - [Debian Buster Slim](#debian-buster-slim)
# About

Creates a Mosquitto broker and 2 Solace brokers with HA load balancer and monitoring.

Mosquitto is configured to bridge to Solace via LB.

# Docker

    docker-compose config
    docker-compose ps
    docker-compose up -d <service>
    docker-compose build --no-cache <service>

# Solace

## Ports

- port 8008 -- Web transport
- port 1883 -- MQTT Default VPN
- port 5672 -- AMQP Default VPN
- port 8000 -- MQTT Default VPN over WebSockets
- port 8080 -- SEMP / PubSub+ Manager
- port 9000 -- REST Default VPN
- port 55555 -- SMF
- port 2222 -- SSH connection to the Solace CLI

# Mosquitto

# MySQL

# PhpMyAdmin

[localhost:8183](localhost:8183)

# References

## haproxy Docker

https://github.com/docker-library/haproxy/blob/7807127e2f96d6cd90b8a11e87c41032c58afc62/2.4/Dockerfile

## Debian Buster Slim
https://github.com/docker-library/repo-info/blob/master/repos/debian/local/buster-slim.md
