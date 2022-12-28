/*
 * iCTPMin期货行情交易(开源)
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __MT_H__
#define __MT_H__
#pragma once
#include "..\\stdafx.h"
#include "MD.h"
#include "TD.h"

class MD;
class TD;

/*
* 同步锁
*/
class CLock
{
private:
	CRITICAL_SECTION m_cs;
public:
	/*
	*构造函数
	*/
	CLock(){
		::InitializeCriticalSection(&m_cs);
	}
	/*
	*析构函数
	*/
	~CLock(){
		::DeleteCriticalSection(&m_cs);
	}
	/*
	*加锁
	*/
	void Lock(){
		::EnterCriticalSection(&m_cs);
	}
	/*
	*解锁
	*/
	void UnLock(){
		::LeaveCriticalSection(&m_cs);
	}
};

/*
* CTP数据监听
*/
class CTPListener
{
public:
/*
	*用户保证金费率回调
	* @param pInstrumentCommissionRates 手续费数据
	*/
	virtual void OnCommissionRatesCallBack(vector<CThostFtdcInstrumentCommissionRateField> *pInstrumentCommissionRates);
	/*
	*深度数据回调
	* @param pDepthMarketData 深度数据
	*/
	virtual void OnDepthMarketDatasCallBack(CThostFtdcDepthMarketDataField *pDepthMarketData);
	/*
	*合约列表回调
	* @param pInstruments 合约列表
	*/
	virtual void OnInstrumentsCallBack(vector<CThostFtdcInstrumentField> *pInstruments);
	/*
	*持仓数据回调
	* @param pInstruments 持仓数据
	*/
	virtual void OnInvestorPositionsCallBack(vector<CThostFtdcInvestorPositionField> *pInvestorPosition);
	/*
	*持仓组合数据回调
	* @param pInvestorPositionCombineDetails 持仓组合数据
	*/
	virtual void OnInvestorPositionCombineDetailsCallBack(vector<CThostFtdcInvestorPositionCombineDetailField> *pInvestorPositionCombineDetails);
	/*
	*持仓明细数据回调
	* @param pInvestorPositionDetails 持仓明细数据
	*/
	virtual void OnInvestorPositionDetailsCallBack(vector<CThostFtdcInvestorPositionDetailField> *pInvestorPositionDetails);
	/*
	*日志回调
	* @param time 时间
	* @param log 日志
	*/
	virtual void OnLogCallBack(const string& time, const string& log);
	/*
	*用户保证金率回调
	* @param pInstrumentMarginRates 用户保证金率
	*/
	virtual void OnMarginRatesCallBack(vector<CThostFtdcInstrumentMarginRateField> *pInstrumentMarginRates);
	/*
	* 委托回报回调
	* @param pInstrumentMarginRates 委托回报
	*/
	virtual void OnOrderInfoCallBack(CThostFtdcOrderField *pOrder);
	/*
	*委托历史回调
	* @param pOrders 委托历史数据
	*/
	virtual void OnOrderInfosCallBack(vector<CThostFtdcOrderField> *pOrders);
	/*
	*状态改变消息
	*/
	virtual void OnStateCallBack();
	/*
	*用户账户回调
	* @param pTradingAccount 资金账户信息
	*/
	virtual void OnTradeAccountCallBack(CThostFtdcTradingAccountField *pTradingAccount);
	/*
	* 成交回报回调
	* @param pInstrumentMarginRates 成交回报
	*/
	virtual void OnTradeRecordCallBack(CThostFtdcTradeField *pTradeInfo);
	/*
	* 成交记录列表回调
	* @param pTradeInfos 成交历史数据
	*/
	virtual void OnTradeRecordsCallBack(vector<CThostFtdcTradeField> *pTradeInfos);
};

//查询数据结构
class CTPQuery{
public:
	/*
	* 构造函数
	*/
	CTPQuery(int id, int reqID, void *args, const string &code = "");
	/*
	* 析构函数
	*/
	virtual ~CTPQuery();
	int m_id;//编号
	void *m_args; //参数
	string m_code; //代码
	int m_reqID; //请求ID
};

/*
*开仓参数类
*/
class CTPOpenQuery{
public:
	/*
	* 构造函数
	*/
	CTPOpenQuery(const string &code, const string& exchangeID, double price, int qty, int type, char timeCondition, int reqID, const string &orderRef);
	string m_code; //代码
	string m_exchangeID; //交易所ID
	string m_orderRef; //追加信息
	double m_price; //价格
	int m_qty; //量
	int m_reqID; //请求ID
	char m_timeCondition; //有效日期
	int m_type; //类型
};

/*
*平仓参数类
*/
class CTPCloseQuery{
public:
	/*
	* 构造函数
	*/
	CTPCloseQuery(char closeType, const string &code, const string& exchangeID, double price, int qty, int type, char timeCondition, int reqID, const string &orderRef);
	char m_closeType; //平仓类型
	string m_exchangeID; //交易所ID
	string m_code; //代码
	string m_orderRef; //追加信息
	double m_price; //价格
	int m_qty; //量
	int m_reqID; //请求ID
	int m_type; //类型
	char m_timeCondition; //有效日期
};

/*
*撤单参数类
*/
class CTPCancelOrderQuery{
public:
	/*
	* 构造函数
	*/
	CTPCancelOrderQuery(const string &exchangeID, const string &orderSysID, int m_reqID, const string &orderRef);
	string m_exchangeID; //交易所ID
	string m_orderRef; //追加信息
	string m_orderSysID; //委托编号
	int m_reqID; //请求ID
};

/*
*注册行情类
*/
class CTPSubMarketDataQuery{
public:
	/*
	* 构造函数
	*/
	CTPSubMarketDataQuery();
	vector<string> m_codes; //代码
};


/*
*CTP字符串转换
*/
struct StringPtr
{
	char *m_ptr;
	StringPtr(const string &str)
	{
		int len = (int)str.length();
		m_ptr = new char[len + 1];
		memset(m_ptr, 0, len + 1);
		memcpy_s(m_ptr, len+1, str.c_str(), len);
	}
	~StringPtr()
	{
		if (m_ptr)
		{
			delete []m_ptr;
			m_ptr = 0;
		}
	}
	char* GetPtr()
	{
		return m_ptr;
	}
};

/*
* 服务器信息
*/
class CTPServerConfig
{
public:
	/*
	* 构造函数
	*/
	CTPServerConfig();
	string m_appID; //应用ID
	string m_authCode; //用户代码
	string m_brokerID; //机构ID
	string m_investorID; //投资者账号
	vector<string> m_mtFronts; //行情服务端组
	string m_name; //名称
	string m_password; //密码
	vector<string> m_tdFronts; //交易服务端组
public:
	/*
	* 清除
	*/
	void Clear();
};

/*
*CTP操作类
*/
class MT
{
private:
	vector<string> m_allInsID;//订阅的代码
	CLock m_allCommissionIDLock; //请求手续费的锁
	map<string, string> m_allCommissionID; //请求手续费的代码
	CLock m_allMarginIDLock; //请求保证金的锁
	map<string, string> m_allMarginID; //请求保证金的代码
	vector<int> m_allReqIDs; //所有的请求ID
	bool m_checkingLogined; //检查登录
	bool m_clearanced; //是否结算
	map<string, string> m_codesMap; //代码列表
	bool m_connected; //是否连接
	CTPListener *m_listener; //回调接口
	MD *m_md; //行情对象
	bool m_mdIsLogined; //行情是否登录
	bool m_mdIsRunning; //行情是否运行
	vector<CTPQuery> m_querys; //一类请求
	vector<CTPQuery> m_querys2; //二类请求
	map<int, string> m_reqID2codes; //请求ID
	int m_sessionID; //会话ID
	CTPServerConfig m_serverConfig; //配置信息
	TD *m_td; //交易对象
	bool m_tdIsLogined; //交易是否登录
	bool m_tdIsRunning; //交易是否运行
private:
	/*
	* 检查登录的线程
	*/
	static DWORD WINAPI CheckLogined(LPVOID lpParam);
	/*
	* 检查交易行情的线程
	*/
	static DWORD WINAPI CheckMT(LPVOID lpParam);
	/*
	* 检查交易时间的线程
	*/
	static DWORD WINAPI CheckTradingTime(LPVOID lpParam);
	/*
	* 加载行情的线程
	*/
	static DWORD WINAPI LoadMD(LPVOID lpParam);
	/*
	* 加载交易的线程
	*/
	static DWORD WINAPI LoadTD(LPVOID lpParam);
	/*
	* 查询数据的线程
	*/
	static DWORD WINAPI QueryData(LPVOID lpParam);
	/*
	* 处理交易请求
	* @param ctpQuery 请求信息
	*/
	int tradeHandler(const CTPQuery &ctpQuery);
public:
	/*
	* 行情事件锁
	*/
	HANDLE m_mdEvent;
	/*
	* 交易事件锁
	*/
	HANDLE m_tdEvent; 
private:
	//锁
	CLock m_Lock;
public:
	/*
	* 构造函数
	*/
	MT();
	/*
	* 析构函数
	*/
	virtual ~MT();
	/*
	*程序ID
	*/
	string GetAppID();
	void SetAppID(const string &appID);
	/*
	*用户ID
	*/
	string GetAuthCode();
	void SetAuthCode(const string &authCode);
	/*
	*机构代码
	*/
	string GetBrokerID();
	void SetBrokerID(const string &brokerID);
	/*
	*是否结算
	*/
	bool IsClearanced();
	void SetClearanced(bool clearanced);
	/*
	*是否连接
	*/
	bool IsConnected();
	void SetConnected(bool connected);
	/*
	*获取投资者帐号
	*/
	string GetInvestorID();
	void SetInvestorID(const string &investorID);
	/*
	*监听
	*/
	CTPListener* GetListener();
	void SetListener(CTPListener *listener);
	/*
	*行情对象
	*/
	MD* GetMD();
	void SetMD(MD *md);
	/*
	*行情是否已登录
	*/
	bool IsMdLogined();
	void SetMdLogined(bool mdIsLogined);
	/*
	*行情是否在运行
	*/
	bool IsMdRunning();
	void SetMdRunning(bool mdIsRunning);
	/*
	*行情服务器
	*/
	vector<string> GetMdServers();
	void AddMdServer(const string &mdServer);
	/*
	*密码
	*/
	string GetPassword();
	void SetPassword(const string &password);
	/*
	*会话ID
	*/
	int GetSessionID();
	void SetSessionID(int sessionID);
	/*
	*断线重连后,需重新订阅所有行情
	*/
	void ReSubMarketData(int reqID);
	/*
	*交易对象
	*/
	TD* GetTD();
	void SetTD(TD *td);
	/*
	*交易是否已登录
	*/
	bool IsTdLogined();
	void SetTdLogined(bool tdIsLogined);
	/*
	*交易是否在运行
	*/
	bool IsTdRunning();
	void SetTdRunning(bool tdIsRunning);
	/*
	*交易服务器
	*/
	vector<string> GetTdServers();
	void AddTdServer(const string &tdServer);
public:
	/*
	*增加订阅的合约代码
	* @param code 代码
	*/
	bool AddInsID(const string &code);
	/*
	*卖平：多单平仓
	* @param code 代码
	* @param exchangeID 交易所ID
	* @param price 价格
	* @param qty 数量
	* @param timeCondition 有效期 
	* @param reqID 请求ID
	* @param orderRef 附加信息 
	*/
	int AskClose(const string& code, const string& exchangeID, double price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*卖平今仓：平今天的开仓的空单
	* @param code 代码
	* @param exchangeID 交易所ID
	* @param price 价格
	* @param qty 数量
	* @param timeCondition 有效期 
	* @param reqID 请求ID
	* @param orderRef 附加信息 
	*/
	int AskCloseToday(const string& code, const string& exchangeID, double price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*卖开：空单开仓
	* @param code 代码
	* @param exchangeID 交易所ID
	* @param price 价格
	* @param qty 数量
	* @param timeCondition 有效期 
	* @param reqID 请求ID
	* @param orderRef 附加信息 
	*/
	int AskOpen(const string& code, const string& exchangeID, double price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*买平：空单平仓
	* @param code 代码
	* @param exchangeID 交易所ID
	* @param price 价格
	* @param qty 数量
	* @param timeCondition 有效期 
	* @param reqID 请求ID
	* @param orderRef 附加信息 
	*/
	int BidClose(const string& code, const string& exchangeID, double price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*买平今仓：平今天的开仓的空单
	* @param code 代码
	* @param exchangeID 交易所ID
	* @param price 价格
	* @param qty 数量
	* @param timeCondition 有效期 
	* @param reqID 请求ID
	* @param orderRef 附加信息 
	*/
	int BidCloseToday(const string& code, const string& exchangeID, double price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*买开：多单开仓
	* @param code 代码
	* @param exchangeID 交易所ID
	* @param price 价格
	* @param qty 数量
	* @param timeCondition 有效期 
	* @param reqID 请求ID
	* @param orderRef 附加信息 
	*/
	int BidOpen(const string& code, const string& exchangeID, double  price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*撤单
	* @param exchangeID 交易所ID
	* @param orderSysID 委托ID
	* @param reqID 请求ID
	* @param orderRef 附加信息 
	*/
	int CancelOrder(const string& exchangeID, const string& orderSysID, int reqID, const string &orderRef);
	/*
	*获取程序路径
	*/
	static string GetProgramDir();
	/*
	*获取最新的查询ID
	* @param ctpQuery 请求信息
	*/
	int GetNewQuery(CTPQuery *ctpQuery);
	/*
	*获取最新的查询ID2
	* @param ctpQuery 请求信息
	*/
	int GetNewQuery2(CTPQuery *ctpQuery);
	/*
	*获取交易日
	*/
	string GetTradingDate();
	/*
	*获取交易时间
	*/
	string GetTradingTime();
	/*
	*是否结算时间
	*/
	static bool IsClearanceTime();
	/*
	*是否交易时间
	*/
	static bool IsTradingTime();
	/*
	*请求资金保证金费率
	* @param wCode 代码
	* @param reqID 请求ID
	*/
	void ReqCommissionRate(const string &wCode, int reqID);
	/*
	*查询结算
	* @param reqID 请求ID
	*/
	void ReqConfirmSettlementInfo(int reqID);
	/*
	*请求合约信息
	* @param reqID 请求ID
	*/
	void ReqInstrumentInfo(int reqID);
	/*
	*请求持仓
	* @param reqID 请求ID
	*/
	void ReqQryInvestorPosition(int reqID);
	/*
	*请求持仓明细
	* @param reqID 请求ID
	*/
	void ReqQryInvestorPositionDetail(int reqID);
	/*
	*请求资金保证金率
	* @param wCode 代码
	* @param reqID 请求ID
	*/
	void ReqMarginRate(const string &wCode, int reqID);
	/*
	*请求委托信息
	* @param reqID 请求ID
	*/
	void RspQryOrderInfo(int reqID);
	/*
	*请求资金账户
	* @param reqID 请求ID
	*/
	void ReqQryTradingAccount(int reqID);	
	/*
	*请求交易信息
	* @param reqID 请求ID
	*/
	void ReqQryTradeInfo(int reqID);
	/*
	*启动
	*/
	void Start();
	/*
	*启动服务
	* @param appID APPID
	* @param authCode 用户ID
	* @param mdServer 行情地址
	* @param tdServer 交易地址
	* @param brokerID 机构号
	* @param investorID 投资者账号
	* @param password 密码
	*/
	void Start(const string &appID, const string &authCode, const string &mdServer, const string &tdServer, const string &brokerID, const string &investorID, const string &password);
	/*
	*注册单个合约的行情
	* @param code 代码
	* @param reqID 请求ID
	*/
	void SubMarketData(const string& code, int reqID);
	/*
	*注册多个合约的行情
	* @param codes 代码集合
	* @param reqID 请求ID
	*/
	void SubMarketDatas(const vector<string> *codes, int reqID);
	/*
	*取消注册单个合约的行情
	* @param code 代码
	* @param reqID 请求ID
	*/
	void UnSubMarketData(const string& code, int reqID);
	/*
	*取消注册多个合约的行情
	* @param codes 代码集合
	* @param reqID 请求ID
	*/
	void UnSubMarketDatas(vector<string> *codes, int reqID);
public:
	/*
	*创建目录
	* @param dir 目录
	*/
	static void CreateDirectory(const char *dir);
	/*
	*判断目录是否存在
	* @param dir 目录
	*/
	static bool IsDirectoryExist(const char *dir);
};

#endif