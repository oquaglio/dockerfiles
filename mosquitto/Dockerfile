FROM eclipse-mosquitto
MAINTAINER ottoq
# Install logrotate (using Alpine package manager)
RUN apk add --update logrotate

# Copy MyApp nginx config
#COPY config/nginx.conf /etc/nginx/nginx.conf

#Copy logrotate nginx configuration
#COPY config/logrotate.d/nginx /etc/logrotate.d/

CMD [“echo”,”Image created”]