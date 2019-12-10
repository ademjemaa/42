cd /var/www/

if [ $INDEX -eq 1 ]
then	
	rm -f index.nginx-debian.html index.php index.html && rm -rf phpMyAdmin wordpress && mv /index.html .
fi
service nginx start && service php7.3-fpm start && service mysql start
