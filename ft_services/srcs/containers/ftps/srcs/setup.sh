adduser -D "$FTPS_USER"
echo "$FTPS_USER:$FTPS_PASSWORD" | chpasswd
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf

