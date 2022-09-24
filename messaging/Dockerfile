FROM ottoq/ubuntu:latest
LABEL maintainer "Otto Quaglio <otto.q@gmx.com>"

# Install Paho MQTT Client Lib
RUN \
  #pip3 install --upgrade setuptools \
  pip3 install paho-mqtt

ENV MESSAGING /root/messaging

RUN git clone --depth 1 --branch master https://github.com/oquaglio/messaging.git $MESSAGING

RUN chmod +x $MESSAGING/mqtt/mqtt_multi_publisher_load_test.sh
RUN chmod +x $MESSAGING//mqtt/mqtt_multi_subscriber_load_test.sh

WORKDIR $MESSAGING
