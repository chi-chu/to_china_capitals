# to_china_capitals
A PHP extention to translate  number to capitals

一个把数字转化为 中文大写金额的 php 扩展

example：
<?php
to_china_capitals(123.12);

"壹佰贰拾叁圆壹角贰分"


#安装
cd to your php source code
bash:  ./ext/ext_skel --extname=to_china_capitals

use  this file to cover the to_china_capitals directory

bash:  phpize
bash:  ./configure --with-php-config=PATH TO YOUR php-config
bash:  make && make install

do not forget to edit php.ini  and restart
