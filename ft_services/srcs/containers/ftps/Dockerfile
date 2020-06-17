FROM alpine:latest

RUN apk update
RUN apk add vsftpd
RUN apk add openssl
RUN mkdir /srv/ftp
COPY srcs/vsftpd.conf /etc/vsftpd/
COPY srcs/chroot.list /etc/vsftpd/
RUN openssl req -x509 -nodes -days 7300 -newkey rsa:2048 -subj "/C=FR/ST=fr/L=Paris/O=School 42/CN=abarbour" -keyout /etc/ssl/private/vsftpd.key.pem -out /etc/ssl/private/vsftpd.cert.pem

COPY srcs/setup.sh .
RUN chmod +x setup.sh
CMD ./setup.sh
