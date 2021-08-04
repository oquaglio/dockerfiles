FROM eclipse-mosquitto:2.0.11
LABEL maintainer="Otto Quaglio <otto.q@gmx.com>"

COPY ./mosquitto.conf /mosquitto/config/

# Install logrotate (using Alpine package manager)
RUN apk add --update logrotate

CMD [“echo”,”Image created”]

# TODOS
# Add logrotate config
# Start logrotate service

