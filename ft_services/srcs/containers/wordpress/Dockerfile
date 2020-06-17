FROM alpine:latest
RUN	apk update
RUN	apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session
RUN	mkdir /www
RUN chmod 775 /www
COPY srcs/wordpress/ /www/
COPY srcs/setup.sh .
RUN chmod +x setup.sh
CMD ./setup.sh
