FROM alpine:latest
RUN	apk update
RUN	apk add mariadb mariadb-client
COPY srcs/mariadb-server.cnf /etc/my.cnf.d/
COPY srcs/cr_user.sql .
COPY srcs/wordpress.sql .
COPY srcs/create_tables.sql .
COPY srcs/setup.sh .
COPY srcs/cr_tables.sh .
RUN chmod +x setup.sh
RUN chmod +x cr_tables.sh
CMD ./setup.sh
