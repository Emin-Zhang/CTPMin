/*
 * iCTPMin期货行情交易(非开源)
 * 上海卷卷猫信息技术有限公司
 */

#include "stdafx.h"
#include <windows.h>
#include "Business\MyTrade.h"

//MyTrade.h 你真正需要面对的类
//MT.h 行情交易处理类
//TD.h 交易对接类
//MD.h 行情对接类

int _tmain(int argc, _TCHAR* argv[])
{
	std::locale::global(std::locale(""));
	//创建对象
	MyTrade fycTrade;
	//启动服务
	fycTrade.Run("simnow_client_test", "0000000000000000", "tcp://180.168.146.187:10212", "tcp://180.168.146.187:10202", "9999", "198450", "jjmfc1984!");
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
