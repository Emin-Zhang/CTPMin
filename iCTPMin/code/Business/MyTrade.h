/*
 * iCTPMin�ڻ����齻��(��Դ)
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __MYTRADE_H__
#define __MYTRADE_H__
#pragma once
#include "..\CTP\MT.h"

class MT;
/*
*�ҵĽ���
*/
class MyTrade
	: public CTPListener
{
public:
	/*
	*���׶���
	*/
	MT *m_pTrade;
public:
	/*
	*���캯��
	*/
	MyTrade();
	/*
	*��������
	*/
	virtual ~MyTrade();
public:
	/*
	*��������
	* @param appID Ӧ��ID
	* @param authCode �û�����
	* @param mdServer ����˵�ַ
	* @param tdServer ���׶˵�ַ
	* @param brokerID �����˺�
	* @param investorID Ͷ�����˺�
	* @param password ����
	*/
	void Run(char *appID, char *authCode, char *mdServer, char *tdServer, char *brokerID, char *investorID, char *password);
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

#endif