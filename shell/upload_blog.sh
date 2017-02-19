#!/bin/bash

scp -P 2022 $1 exmagic.moe:/var/www/blog/source/_posts/

ssh -p 2022 exmagic.moe 'cd /var/www/blog/ && hexo generate && exit'
