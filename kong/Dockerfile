
FROM kong

LABEL maintainer="Otto Quaglio <otto.q@gmx.com>"



KONG_DATABASE="off" 
KONG_PROXY_ACCESS_LOG="/dev/stdout" 
KONG_ADMIN_ACCESS_LOG="/dev/stdout" 
KONG_PROXY_ERROR_LOG="/dev/stderr" 
KONG_ADMIN_ERROR_LOG="/dev/stderr"
KONG_ADMIN_LISTEN="0.0.0.0:8001, 0.0.0.0:8444 ssl
 8000:8000 \
 8443:8443 \
 8001:8001 \
 8444:8444 \
