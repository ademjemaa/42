FROM alpine:latest
RUN	apk update
RUN	apk add nginx
RUN	apk add openssh
RUN ssh-keygen -f /etc/ssh/ssh_host_dsa_key -N '' -t dsa
RUN ssh-keygen -f /etc/ssh/ssh_host_rsa_key -N '' -t rsa
RUN ssh-keygen -f /etc/ssh/ssh_host_ecdsa_key -N '' -t ecdsa
RUN ssh-keygen -f /etc/ssh/ssh_host_ed25519_key -N '' -t ed25519
RUN	mkdir /run/nginx
RUN	mkdir /var/run/sshd
RUN	mkdir /www
RUN	adduser -D -g 'www' www && chown -R www:www /var/lib/nginx && chown -R www:www /www 
RUN chmod 775 /www
COPY ./srcs/default.conf /etc/nginx/conf.d/
COPY ./srcs/server.crt /ssl_certificate/
COPY ./srcs/server.key /ssl_certificate/
COPY srcs/sshd_config /etc/ssh/
COPY srcs/nginx.conf /etc/nginx/
COPY srcs/setup.sh .
RUN chmod +x setup.sh
CMD ./setup.sh
EXPOSE 80/tcp
EXPOSE 443/tcp
EXPOSE 2222/tcp
