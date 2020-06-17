FROM alpine:latest
RUN	apk update
RUN wget https://dl.grafana.com/oss/release/grafana-6.6.2.linux-amd64.tar.gz
RUN tar -zxvf grafana-6.6.2.linux-amd64.tar.gz
RUN apk add --no-cache --repository=http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat
RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.13.3-static_linux_amd64.tar.gz
RUN tar -C . -xzf telegraf-1.13.3-static_linux_amd64.tar.gz
RUN cp telegraf/telegraf /usr/bin/
RUN mkdir /etc/telegraf
COPY srcs/grafana.db /grafana-6.6.2/data/
COPY srcs/telegraf.conf /etc/telegraf/
COPY srcs/setup.sh .
RUN chmod +x setup.sh
CMD ./setup.sh
