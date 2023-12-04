#
# MySQL Dockerfile
#
# https://github.com/dockerfile/mysql
#

# Pull base image.
FROM ottoq/ubuntu:latest
# https://registry.hub.docker.com/r/phusion/baseimage/
#FROM phusion/baseimage:master

#RUN rm -f /etc/service/sshd/down

# Regenerate SSH host keys. baseimage-docker does not contain any, so you
# have to do that yourself. You may also comment out this instruction; the
# init system will auto-generate one during boot.
#RUN /etc/my_init.d/00_regen_ssh_host_keys.sh

# Install MySQL.
RUN \
  apt-get update && \
  #DEBIAN_FRONTEND=noninteractive apt-get install -y \
  apt-get install -y \
  mysql-server \
  # for MYSQL_RANDOM_ROOT_PASSWORD
	pwgen \
  # for mysql_ssl_rsa_setup
	openssl \
	perl \
  # install "xz-utils" for .sql.xz docker-entrypoint-initdb.d files
	xz-utils \
  --no-install-recommends

RUN rm -rf /var/lib/apt/lists/* && \
  sed -i 's/^\(bind-address\s.*\)/# \1/' /etc/mysql/my.cnf && \
  sed -i 's/^\(log_error\s.*\)/# \1/' /etc/mysql/my.cnf && \
  echo "mysqld_safe &" > /tmp/config && \
  echo "mysqladmin --silent --wait=30 ping || exit 1" >> /tmp/config && \
  echo "mysql -e 'GRANT ALL PRIVILEGES ON *.* TO \"root\"@\"%\" WITH GRANT OPTION;'" >> /tmp/config && \
  bash /tmp/config && \
  rm -f /tmp/config && \
	rm -rf /var/lib/apt/lists/*

RUN apt -y install phpmyadmin php-mbstring php-zip php-gd php-json php-curl --no-install-recommends

#ENV MYSQL_MAJOR 8.0
#ENV MYSQL_VERSION 8.0.26-1debian10

# Define mountable directories.
VOLUME ["/etc/mysql", "/var/lib/mysql"]

# Define working directory.
WORKDIR /data

# Define default command.
#CMD ["mysqld_safe"]


# Expose ports.
EXPOSE 3306