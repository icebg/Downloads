#########################################################################
# File Name: test.sh
# Author: Yufeng Huang <icebggg@qq.com>
# Created Time: Sun 02 Jan 2022 08:16:58 AM PST
#########################################################################
#! /bin/bash
cp textfile.bak textfile && ./myDelete10thLine textfile && vimdiff textfile*

