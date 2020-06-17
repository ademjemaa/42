FROM alpine:latest
RUN	apk update
RUN	apk add influxdb
RUN mkdir /var/lib/influxdb/
COPY srcs/cr_user.sql .
COPY srcs/cr_user.sh .
COPY srcs/setup.sh .
RUN chmod +x setup.sh
RUN chmod +x cr_user.sh
CMD ./setup.sh
