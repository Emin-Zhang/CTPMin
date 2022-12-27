/*
 * iCTPMin期货行情交易(非开源)
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __STDAFX_H__
#define __STDAFX_H__
#pragma once

// C 运行时头文件
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <locale.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <cmath>
#include <time.h>
#include <algorithm>
#include <float.h>
#include <memory.h>
#include <wchar.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cctype>
#include <string>

#include "ThostFtdcMdApi.h"
#include "ThostFtdcTraderApi.h"
#define CTP_QUOTE_SO		("thostmduserapi.so")
#define CTP_TRADE_SO		("thosttraderapi.so")
//行情
#define _CreateFtdcMdApi	("_ZN15CThostFtdcMdApi15CreateFtdcMdApiEPKcbb")

//交易
#define _CreateFtdcTraderApi	("_ZN19CThostFtdcTraderApi19CreateFtdcTraderApiEPKc")

using namespace std; 


#endif