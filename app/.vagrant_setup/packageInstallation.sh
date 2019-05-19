#!/bin/bash

sudo apt-get update
sudo apt-get install nginx git emacs g++ make openssl -y

sudo cp /app/.vagrant_setup/nginx/nginx.conf /etc/nginx/nginx.conf
sudo cp /app/.vagrant_setup/nginx/nginx.default /etc/nginx/sites-available/default

printf "\n\n\n"
echo "==============================================="
echo "Enter the following information for certificate"
echo "==============================================="
printf "country: <your country>\nstate/province: <your state/province>\ncity: <your city>\ncompany: Sniddl\nUnit: Development\nName: 192.168.10.10\nemail: <your email>"

sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
sudo openssl dhparam -out /etc/nginx/dhparam.pem 4096

cp /app/.vagrant_setup/nginx/self-signed.conf /etc/nginx/snippets/self-signed.conf
cp /app/.vagrant_setup/nginx/ssl-params.conf /etc/nginx/snippets/ssl-params.conf

sudo nginx -t
sudo nginx -s reload


make -C /app -j --warn-undefined-variables