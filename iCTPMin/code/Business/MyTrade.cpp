#include "..\\stdafx.h"
#include "MyTrade.h"


MyTrade::MyTrade()
{
	m_pTrade = new MT();
	m_pTrade->SetListener(this);
	//m_futureLatestDataCallBack = &callBackFunc;
}

MyTrade::~MyTrade()
{
	if (m_pTrade)
	{
		delete m_pTrade;
	}
	m_pTrade = NULL;
}

void MyTrade::Run(char *appID, char *authCode, char *mdServer, char *tdServer, char *brokerID, char *investorID, char *password)
{
	if (m_pTrade)
	{
		m_pTrade->Start(appID, authCode, mdServer, tdServer, brokerID, investorID, password);
	}
}

void MyTrade::OnCommissionRatesCallBack(vector<CThostFtdcInstrumentCommissionRateField> *pInstrumentCommissionRates)
{
	printf("CallBack:����������\r\n");
}

void MyTrade::OnDepthMarketDatasCallBack(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	printf("CallBack:��������\r\n");
	if(pDepthMarketData->LastPrice > 72730){
		//'3'Ϊ������Ч��������ɼ�����'1'
		/*m_pTrade->BidOpen("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //��
		m_pTrade->AskOpen("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //����
		m_pTrade->BidClose("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //��ƽ
		m_pTrade->AskClose("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //��ƽ
		m_pTrade->BidCloseToday("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //��ƽ��
		m_pTrade->AskCloseToday("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //��ƽ��
		m_pTrade->CancelOrder("SHFE", "", 0, ""); //����*/
	}
}

void MyTrade::OnInstrumentsCallBack(vector<CThostFtdcInstrumentField> *pInstruments)
{
	printf("CallBack:���մ����б�\r\n");
	m_pTrade->SubMarketData("cu2205", 0);
}

void MyTrade::OnInvestorPositionsCallBack(vector<CThostFtdcInvestorPositionField> *pInvestorPosition)
{
	printf("CallBack:���ճֲ�\r\n");
}

void MyTrade::OnInvestorPositionCombineDetailsCallBack(vector<CThostFtdcInvestorPositionCombineDetailField> *pInvestorPositionCombineDetails)
{
}

void MyTrade::OnInvestorPositionDetailsCallBack(vector<CThostFtdcInvestorPositionDetailField> *pInvestorPositionDetails)
{
	printf("CallBack:���ճֲ���ϸ\r\n");
}

void MyTrade::OnLogCallBack(const string& time, const string& log)
{
}

void MyTrade::OnMarginRatesCallBack(vector<CThostFtdcInstrumentMarginRateField> *pInstrumentMarginRates)
{
	printf("CallBack:���ձ�֤��\r\n");
}

void MyTrade::OnOrderInfoCallBack(CThostFtdcOrderField *pOrder)
{
	printf("CallBack:��������ί�лر�\r\n");
}

void MyTrade::OnOrderInfosCallBack(vector<CThostFtdcOrderField> *pOrders)
{
	printf("CallBack:������ʷί��\r\n");
}

void MyTrade::OnStateCallBack()
{
}

void MyTrade::OnTradeAccountCallBack(CThostFtdcTradingAccountField *pTradingAccount)
{
	printf("CallBack:�����˻���Ϣ\r\n");

}

void MyTrade::OnTradeRecordCallBack(CThostFtdcTradeField *pTradeInfo)
{
	printf("CallBack:�������³ɽ��ر�\r\n");
}

void MyTrade::OnTradeRecordsCallBack(vector<CThostFtdcTradeField> *pTradeInfos)
{
	printf("CallBack:������ʷ�ɽ�\r\n");
}
