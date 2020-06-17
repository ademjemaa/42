sh srcs/ikubctl.sh
export MINIKUBE_HOME=/goinfre/.minikube/
minikube start --vm-driver=virtualbox --cpus=4 --memory=4000m --disk-size=6000
sleep 2
minikube ip
sleep 2
sed -i.bak 's/\(pasv_address=\).*/\1'$(minikube ip)'/g' srcs/containers/ftps/srcs/vsftpd.conf && rm srcs/containers/ftps/srcs/vsftpd.conf.bak
sed -i.bak "s/\(define('WP_SITEURL', \).*/\1'http:\/\/$(minikube ip):5050\/');/g"  srcs/containers/wordpress/srcs/wordpress/wp-config.php
sed -i.bak "s/\(define('WP_HOME', \).*/\1'http:\/\/$(minikube ip):5050\/');/g"  srcs/containers/wordpress/srcs/wordpress/wp-config.php && rm srcs/containers/wordpress/srcs/wordpress/wp-config.php.bak
sed -i.bak "s/\(1, 'siteurl', \).*/\1'http:\/\/$(minikube ip):5050\/', 'yes'),/g"   srcs/containers/mysql/srcs/wordpress.sql
sed -i.bak "s/\(2, 'home', \).*/\1'http:\/\/$(minikube ip):5050\/', 'yes'),/g"   srcs/containers/mysql/srcs/wordpress.sql && rm srcs/containers/mysql/srcs/wordpress.sql.bak
minikube ssh "sudo -u root awk 'NR==14{print \"    - --service-node-port-range=1-35000\"}7' /etc/kubernetes/manifests/kube-apiserver.yaml >> tmp && sudo -u root rm /etc/kubernetes/manifests/kube-apiserver.yaml && sudo -u root mv tmp /etc/kubernetes/manifests/kube-apiserver.yaml"
eval $(minikube docker-env)
sleep 2
minikube mount srcs/:/srcs &
sleep 2
minikube ssh "docker build -t nginx /srcs/containers/nginx/"
sleep 2
minikube ssh "docker build -t ftps /srcs/containers/ftps/"
sleep 2
minikube ssh "docker build -t mysql /srcs/containers/mysql/"
sleep 2
minikube ssh "docker build -t phpmyadmin /srcs/containers/phpmyadmin/"
sleep 2
minikube ssh "docker build -t wordpress /srcs/containers/wordpress/"
sleep 2
minikube ssh "docker build -t influxdb /srcs/containers/influxdb/"
sleep 2
minikube ssh "docker build -t grafana /srcs/containers/grafana/"
sleep 2
kubectl apply -f srcs/yaml/nginx.yaml
sleep 2
kubectl apply -f srcs/yaml/ingress.yaml
sleep 2
kubectl apply -f srcs/yaml/ftps.yaml
sleep 2
kubectl apply -f srcs/yaml/mysql.yaml
sleep 2
kubectl apply -f srcs/yaml/phpmyadmin.yaml
sleep 2
kubectl apply -f srcs/yaml/wordpress.yaml
sleep 2
kubectl apply -f srcs/yaml/influxdb.yaml
sleep 2
kubectl apply -f srcs/yaml/grafana.yaml
sleep 2
echo "ip is : $(minikube ip)"
minikube addons enable ingress
minikube dashboard &
