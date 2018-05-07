# to_china_capitals
A PHP extention to translate  number to capitals

一个把数字转化为 中文大写金额的 php 扩展

# 实例：
to_china_capitals(123.12);

"壹佰贰拾叁圆壹角贰分"


# 安装
1. cd to your php source code
2. bash:  ./ext/ext_skel --extname=to_china_capitals

3. use  this file to cover the to_china_capitals directory

4. bash:  phpize
5. bash:  ./configure --with-php-config=PATH TO YOUR php-config
6. bash:  make && make install

7. do not forget to edit php.ini  and restart
