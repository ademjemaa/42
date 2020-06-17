FROM alpine:latest
RUN	apk update
RUN	apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session
RUN	mkdir /www
RUN chmod 775 /www
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.4/phpMyAdmin-4.9.4-all-languages.zip
RUN unzip phpMyAdmin-4.9.4-all-languages.zip
RUN mv /phpMyAdmin-4.9.4-all-languages/* /www/
COPY srcs/config.inc.php /www/
COPY srcs/setup.sh .
RUN chmod +x setup.sh
CMD ./setup.sh
