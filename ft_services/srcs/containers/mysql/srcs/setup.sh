sh ./cr_tables.sh &
/usr/bin/mysql_install_db --user=mysql --datadir="/var/lib/mysql/"
/usr/bin/mysqld -u mysql
