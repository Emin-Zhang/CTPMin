/*
 * iCTPMin�ڻ����齻��(�ǿ�Դ)
 * �Ϻ����è��Ϣ�������޹�˾
 */

#include "stdafx.h"
#include <windows.h>
#include "Business\MyTrade.h"

//MyTrade.h ��������Ҫ��Ե���
//MT.h ���齻�״�����
//TD.h ���׶Խ���
//MD.h ����Խ���

int _tmain(int argc, _TCHAR* argv[])
{
	std::locale::global(std::locale(""));
	//��������
	MyTrade fycTrade;
	//��������
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
