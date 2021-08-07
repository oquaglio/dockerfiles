# Mosquitto to Solace Bridge <!-- omit in toc -->
- [About](#about)
- [References](#references)
  - [haproxy Docker](#haproxy-docker)
  - [Debian Buster Slim](#debian-buster-slim)
# About

Creates a Mosquitto broker and 2 Solace brokers with HA load balancer and monitoring.

Mosquitto is configured to bridge to Solace via LB.

https://lmddgtfy.net/?q=docker%20compose%20up

# References

## haproxy Docker

https://github.com/docker-library/haproxy/blob/7807127e2f96d6cd90b8a11e87c41032c58afc62/2.4/Dockerfile

## Debian Buster Slim
https://github.com/docker-library/repo-info/blob/master/repos/debian/local/buster-slim.md
