/* 
 * File:   main.cpp
 * Author: taode
 *
 * Created on 2022年3月4日, 上午11:44
 */

#include <cstdlib>
#include <stdio.h>
#include <string>
#include <vector>
#include "MyTrade.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //创建对象
    MyTrade fycTrade;
    //启动服务
    fycTrade.Run("simnow_client_test", "0000000000000000", "tcp://180.168.146.187:10212", "tcp://180.168.146.187:10202", "9999", "021739", "123456");
    while(true)
    {
            string input;
            cin >> input;
            if( input == "exit" )
            {
                    break;
            }
    }
    return 0;
}

