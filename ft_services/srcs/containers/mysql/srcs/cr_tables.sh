until mysql --socket="/var/lib/mysql/mysqld.sock" -u root < cr_user.sql
do
        echo "MYSQL is not ready"
done

/usr/bin/mysql --socket="/var/lib/mysql/mysqld.sock" -u root < wordpress.sql
/usr/bin/mysql --socket="/var/lib/mysql/mysqld.sock" -u root < create_tables.sql
