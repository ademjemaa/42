adduser -D -h "/www" "$SSH_USER"
echo "$SSH_USER:$SSH_PASSWORD" | chpasswd
addgroup "$SSH_USER" www

/usr/sbin/sshd
nginx -g "daemon off;"
