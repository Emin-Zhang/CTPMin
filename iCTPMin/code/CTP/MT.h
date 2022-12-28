/*
 * iCTPMin�ڻ����齻��(��Դ)
 * �Ϻ����è��Ϣ�������޹�˾
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
* ͬ����
*/
class CLock
{
private:
	CRITICAL_SECTION m_cs;
public:
	/*
	*���캯��
	*/
	CLock(){
		::InitializeCriticalSection(&m_cs);
	}
	/*
	*��������
	*/
	~CLock(){
		::DeleteCriticalSection(&m_cs);
	}
	/*
	*����
	*/
	void Lock(){
		::EnterCriticalSection(&m_cs);
	}
	/*
	*����
	*/
	void UnLock(){
		::LeaveCriticalSection(&m_cs);
	}
};

/*
* CTP���ݼ���
*/
class CTPListener
{
public:
/*
	*�û���֤����ʻص�
	* @param pInstrumentCommissionRates ����������
	*/
	virtual void OnCommissionRatesCallBack(vector<CThostFtdcInstrumentCommissionRateField> *pInstrumentCommissionRates);
	/*
	*������ݻص�
	* @param pDepthMarketData �������
	*/
	virtual void OnDepthMarketDatasCallBack(CThostFtdcDepthMarketDataField *pDepthMarketData);
	/*
	*��Լ�б�ص�
	* @param pInstruments ��Լ�б�
	*/
	virtual void OnInstrumentsCallBack(vector<CThostFtdcInstrumentField> *pInstruments);
	/*
	*�ֲ����ݻص�
	* @param pInstruments �ֲ�����
	*/
	virtual void OnInvestorPositionsCallBack(vector<CThostFtdcInvestorPositionField> *pInvestorPosition);
	/*
	*�ֲ�������ݻص�
	* @param pInvestorPositionCombineDetails �ֲ��������
	*/
	virtual void OnInvestorPositionCombineDetailsCallBack(vector<CThostFtdcInvestorPositionCombineDetailField> *pInvestorPositionCombineDetails);
	/*
	*�ֲ���ϸ���ݻص�
	* @param pInvestorPositionDetails �ֲ���ϸ����
	*/
	virtual void OnInvestorPositionDetailsCallBack(vector<CThostFtdcInvestorPositionDetailField> *pInvestorPositionDetails);
	/*
	*��־�ص�
	* @param time ʱ��
	* @param log ��־
	*/
	virtual void OnLogCallBack(const string& time, const string& log);
	/*
	*�û���֤���ʻص�
	* @param pInstrumentMarginRates �û���֤����
	*/
	virtual void OnMarginRatesCallBack(vector<CThostFtdcInstrumentMarginRateField> *pInstrumentMarginRates);
	/*
	* ί�лر��ص�
	* @param pInstrumentMarginRates ί�лر�
	*/
	virtual void OnOrderInfoCallBack(CThostFtdcOrderField *pOrder);
	/*
	*ί����ʷ�ص�
	* @param pOrders ί����ʷ����
	*/
	virtual void OnOrderInfosCallBack(vector<CThostFtdcOrderField> *pOrders);
	/*
	*״̬�ı���Ϣ
	*/
	virtual void OnStateCallBack();
	/*
	*�û��˻��ص�
	* @param pTradingAccount �ʽ��˻���Ϣ
	*/
	virtual void OnTradeAccountCallBack(CThostFtdcTradingAccountField *pTradingAccount);
	/*
	* �ɽ��ر��ص�
	* @param pInstrumentMarginRates �ɽ��ر�
	*/
	virtual void OnTradeRecordCallBack(CThostFtdcTradeField *pTradeInfo);
	/*
	* �ɽ���¼�б�ص�
	* @param pTradeInfos �ɽ���ʷ����
	*/
	virtual void OnTradeRecordsCallBack(vector<CThostFtdcTradeField> *pTradeInfos);
};

//��ѯ���ݽṹ
class CTPQuery{
public:
	/*
	* ���캯��
	*/
	CTPQuery(int id, int reqID, void *args, const string &code = "");
	/*
	* ��������
	*/
	virtual ~CTPQuery();
	int m_id;//���
	void *m_args; //����
	string m_code; //����
	int m_reqID; //����ID
};

/*
*���ֲ�����
*/
class CTPOpenQuery{
public:
	/*
	* ���캯��
	*/
	CTPOpenQuery(const string &code, const string& exchangeID, double price, int qty, int type, char timeCondition, int reqID, const string &orderRef);
	string m_code; //����
	string m_exchangeID; //������ID
	string m_orderRef; //׷����Ϣ
	double m_price; //�۸�
	int m_qty; //��
	int m_reqID; //����ID
	char m_timeCondition; //��Ч����
	int m_type; //����
};

/*
*ƽ�ֲ�����
*/
class CTPCloseQuery{
public:
	/*
	* ���캯��
	*/
	CTPCloseQuery(char closeType, const string &code, const string& exchangeID, double price, int qty, int type, char timeCondition, int reqID, const string &orderRef);
	char m_closeType; //ƽ������
	string m_exchangeID; //������ID
	string m_code; //����
	string m_orderRef; //׷����Ϣ
	double m_price; //�۸�
	int m_qty; //��
	int m_reqID; //����ID
	int m_type; //����
	char m_timeCondition; //��Ч����
};

/*
*����������
*/
class CTPCancelOrderQuery{
public:
	/*
	* ���캯��
	*/
	CTPCancelOrderQuery(const string &exchangeID, const string &orderSysID, int m_reqID, const string &orderRef);
	string m_exchangeID; //������ID
	string m_orderRef; //׷����Ϣ
	string m_orderSysID; //ί�б��
	int m_reqID; //����ID
};

/*
*ע��������
*/
class CTPSubMarketDataQuery{
public:
	/*
	* ���캯��
	*/
	CTPSubMarketDataQuery();
	vector<string> m_codes; //����
};


/*
*CTP�ַ���ת��
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
* ��������Ϣ
*/
class CTPServerConfig
{
public:
	/*
	* ���캯��
	*/
	CTPServerConfig();
	string m_appID; //Ӧ��ID
	string m_authCode; //�û�����
	string m_brokerID; //����ID
	string m_investorID; //Ͷ�����˺�
	vector<string> m_mtFronts; //����������
	string m_name; //����
	string m_password; //����
	vector<string> m_tdFronts; //���׷������
public:
	/*
	* ���
	*/
	void Clear();
};

/*
*CTP������
*/
class MT
{
private:
	vector<string> m_allInsID;//���ĵĴ���
	CLock m_allCommissionIDLock; //���������ѵ���
	map<string, string> m_allCommissionID; //���������ѵĴ���
	CLock m_allMarginIDLock; //����֤�����
	map<string, string> m_allMarginID; //����֤��Ĵ���
	vector<int> m_allReqIDs; //���е�����ID
	bool m_checkingLogined; //����¼
	bool m_clearanced; //�Ƿ����
	map<string, string> m_codesMap; //�����б�
	bool m_connected; //�Ƿ�����
	CTPListener *m_listener; //�ص��ӿ�
	MD *m_md; //�������
	bool m_mdIsLogined; //�����Ƿ��¼
	bool m_mdIsRunning; //�����Ƿ�����
	vector<CTPQuery> m_querys; //һ������
	vector<CTPQuery> m_querys2; //��������
	map<int, string> m_reqID2codes; //����ID
	int m_sessionID; //�ỰID
	CTPServerConfig m_serverConfig; //������Ϣ
	TD *m_td; //���׶���
	bool m_tdIsLogined; //�����Ƿ��¼
	bool m_tdIsRunning; //�����Ƿ�����
private:
	/*
	* ����¼���߳�
	*/
	static DWORD WINAPI CheckLogined(LPVOID lpParam);
	/*
	* ��齻��������߳�
	*/
	static DWORD WINAPI CheckMT(LPVOID lpParam);
	/*
	* ��齻��ʱ����߳�
	*/
	static DWORD WINAPI CheckTradingTime(LPVOID lpParam);
	/*
	* ����������߳�
	*/
	static DWORD WINAPI LoadMD(LPVOID lpParam);
	/*
	* ���ؽ��׵��߳�
	*/
	static DWORD WINAPI LoadTD(LPVOID lpParam);
	/*
	* ��ѯ���ݵ��߳�
	*/
	static DWORD WINAPI QueryData(LPVOID lpParam);
	/*
	* ����������
	* @param ctpQuery ������Ϣ
	*/
	int tradeHandler(const CTPQuery &ctpQuery);
public:
	/*
	* �����¼���
	*/
	HANDLE m_mdEvent;
	/*
	* �����¼���
	*/
	HANDLE m_tdEvent; 
private:
	//��
	CLock m_Lock;
public:
	/*
	* ���캯��
	*/
	MT();
	/*
	* ��������
	*/
	virtual ~MT();
	/*
	*����ID
	*/
	string GetAppID();
	void SetAppID(const string &appID);
	/*
	*�û�ID
	*/
	string GetAuthCode();
	void SetAuthCode(const string &authCode);
	/*
	*��������
	*/
	string GetBrokerID();
	void SetBrokerID(const string &brokerID);
	/*
	*�Ƿ����
	*/
	bool IsClearanced();
	void SetClearanced(bool clearanced);
	/*
	*�Ƿ�����
	*/
	bool IsConnected();
	void SetConnected(bool connected);
	/*
	*��ȡͶ�����ʺ�
	*/
	string GetInvestorID();
	void SetInvestorID(const string &investorID);
	/*
	*����
	*/
	CTPListener* GetListener();
	void SetListener(CTPListener *listener);
	/*
	*�������
	*/
	MD* GetMD();
	void SetMD(MD *md);
	/*
	*�����Ƿ��ѵ�¼
	*/
	bool IsMdLogined();
	void SetMdLogined(bool mdIsLogined);
	/*
	*�����Ƿ�������
	*/
	bool IsMdRunning();
	void SetMdRunning(bool mdIsRunning);
	/*
	*���������
	*/
	vector<string> GetMdServers();
	void AddMdServer(const string &mdServer);
	/*
	*����
	*/
	string GetPassword();
	void SetPassword(const string &password);
	/*
	*�ỰID
	*/
	int GetSessionID();
	void SetSessionID(int sessionID);
	/*
	*����������,�����¶�����������
	*/
	void ReSubMarketData(int reqID);
	/*
	*���׶���
	*/
	TD* GetTD();
	void SetTD(TD *td);
	/*
	*�����Ƿ��ѵ�¼
	*/
	bool IsTdLogined();
	void SetTdLogined(bool tdIsLogined);
	/*
	*�����Ƿ�������
	*/
	bool IsTdRunning();
	void SetTdRunning(bool tdIsRunning);
	/*
	*���׷�����
	*/
	vector<string> GetTdServers();
	void AddTdServer(const string &tdServer);
public:
	/*
	*���Ӷ��ĵĺ�Լ����
	* @param code ����
	*/
	bool AddInsID(const string &code);
	/*
	*��ƽ���൥ƽ��
	* @param code ����
	* @param exchangeID ������ID
	* @param price �۸�
	* @param qty ����
	* @param timeCondition ��Ч�� 
	* @param reqID ����ID
	* @param orderRef ������Ϣ 
	*/
	int AskClose(const string& code, const string& exchangeID, double price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*��ƽ��֣�ƽ����Ŀ��ֵĿյ�
	* @param code ����
	* @param exchangeID ������ID
	* @param price �۸�
	* @param qty ����
	* @param timeCondition ��Ч�� 
	* @param reqID ����ID
	* @param orderRef ������Ϣ 
	*/
	int AskCloseToday(const string& code, const string& exchangeID, double price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*�������յ�����
	* @param code ����
	* @param exchangeID ������ID
	* @param price �۸�
	* @param qty ����
	* @param timeCondition ��Ч�� 
	* @param reqID ����ID
	* @param orderRef ������Ϣ 
	*/
	int AskOpen(const string& code, const string& exchangeID, double price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*��ƽ���յ�ƽ��
	* @param code ����
	* @param exchangeID ������ID
	* @param price �۸�
	* @param qty ����
	* @param timeCondition ��Ч�� 
	* @param reqID ����ID
	* @param orderRef ������Ϣ 
	*/
	int BidClose(const string& code, const string& exchangeID, double price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*��ƽ��֣�ƽ����Ŀ��ֵĿյ�
	* @param code ����
	* @param exchangeID ������ID
	* @param price �۸�
	* @param qty ����
	* @param timeCondition ��Ч�� 
	* @param reqID ����ID
	* @param orderRef ������Ϣ 
	*/
	int BidCloseToday(const string& code, const string& exchangeID, double price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*�򿪣��൥����
	* @param code ����
	* @param exchangeID ������ID
	* @param price �۸�
	* @param qty ����
	* @param timeCondition ��Ч�� 
	* @param reqID ����ID
	* @param orderRef ������Ϣ 
	*/
	int BidOpen(const string& code, const string& exchangeID, double  price, int qty, char timeCondition, int reqID, const string &orderRef);
	/*
	*����
	* @param exchangeID ������ID
	* @param orderSysID ί��ID
	* @param reqID ����ID
	* @param orderRef ������Ϣ 
	*/
	int CancelOrder(const string& exchangeID, const string& orderSysID, int reqID, const string &orderRef);
	/*
	*��ȡ����·��
	*/
	static string GetProgramDir();
	/*
	*��ȡ���µĲ�ѯID
	* @param ctpQuery ������Ϣ
	*/
	int GetNewQuery(CTPQuery *ctpQuery);
	/*
	*��ȡ���µĲ�ѯID2
	* @param ctpQuery ������Ϣ
	*/
	int GetNewQuery2(CTPQuery *ctpQuery);
	/*
	*��ȡ������
	*/
	string GetTradingDate();
	/*
	*��ȡ����ʱ��
	*/
	string GetTradingTime();
	/*
	*�Ƿ����ʱ��
	*/
	static bool IsClearanceTime();
	/*
	*�Ƿ���ʱ��
	*/
	static bool IsTradingTime();
	/*
	*�����ʽ�֤�����
	* @param wCode ����
	* @param reqID ����ID
	*/
	void ReqCommissionRate(const string &wCode, int reqID);
	/*
	*��ѯ����
	* @param reqID ����ID
	*/
	void ReqConfirmSettlementInfo(int reqID);
	/*
	*�����Լ��Ϣ
	* @param reqID ����ID
	*/
	void ReqInstrumentInfo(int reqID);
	/*
	*����ֲ�
	* @param reqID ����ID
	*/
	void ReqQryInvestorPosition(int reqID);
	/*
	*����ֲ���ϸ
	* @param reqID ����ID
	*/
	void ReqQryInvestorPositionDetail(int reqID);
	/*
	*�����ʽ�֤����
	* @param wCode ����
	* @param reqID ����ID
	*/
	void ReqMarginRate(const string &wCode, int reqID);
	/*
	*����ί����Ϣ
	* @param reqID ����ID
	*/
	void RspQryOrderInfo(int reqID);
	/*
	*�����ʽ��˻�
	* @param reqID ����ID
	*/
	void ReqQryTradingAccount(int reqID);	
	/*
	*��������Ϣ
	* @param reqID ����ID
	*/
	void ReqQryTradeInfo(int reqID);
	/*
	*����
	*/
	void Start();
	/*
	*��������
	* @param appID APPID
	* @param authCode �û�ID
	* @param mdServer �����ַ
	* @param tdServer ���׵�ַ
	* @param brokerID ������
	* @param investorID Ͷ�����˺�
	* @param password ����
	*/
	void Start(const string &appID, const string &authCode, const string &mdServer, const string &tdServer, const string &brokerID, const string &investorID, const string &password);
	/*
	*ע�ᵥ����Լ������
	* @param code ����
	* @param reqID ����ID
	*/
	void SubMarketData(const string& code, int reqID);
	/*
	*ע������Լ������
	* @param codes ���뼯��
	* @param reqID ����ID
	*/
	void SubMarketDatas(const vector<string> *codes, int reqID);
	/*
	*ȡ��ע�ᵥ����Լ������
	* @param code ����
	* @param reqID ����ID
	*/
	void UnSubMarketData(const string& code, int reqID);
	/*
	*ȡ��ע������Լ������
	* @param codes ���뼯��
	* @param reqID ����ID
	*/
	void UnSubMarketDatas(vector<string> *codes, int reqID);
public:
	/*
	*����Ŀ¼
	* @param dir Ŀ¼
	*/
	static void CreateDirectory(const char *dir);
	/*
	*�ж�Ŀ¼�Ƿ����
	* @param dir Ŀ¼
	*/
	static bool IsDirectoryExist(const char *dir);
};

#endif