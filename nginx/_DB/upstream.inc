upstream upstream_php_fpm {
    #ip_hash;
    #server 192.168.125.142:9000 weight=3;
    #server 192.168.125.143:9000;
    #server 192.168.125.144:9000 max_fails=5 fail_timeout=30s;
    #server unix:/var/run/php5-fpm.sock backup;
    server unix:/var/run/php-fpm/php-fpm.sock;
}