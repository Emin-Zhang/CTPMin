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
	printf("CallBack:接收手续费\r\n");
}

void MyTrade::OnDepthMarketDatasCallBack(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	printf("CallBack:接收行情\r\n");
	if(pDepthMarketData->LastPrice > 72730){
		//'3'为当日有效，如果不成即撤填'1'
		/*m_pTrade->BidOpen("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //买开
		m_pTrade->AskOpen("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //卖开
		m_pTrade->BidClose("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //买平
		m_pTrade->AskClose("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //卖平
		m_pTrade->BidCloseToday("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //买平今
		m_pTrade->AskCloseToday("cu2205", "SHFE", pDepthMarketData->LastPrice, 1, '3', 0, ""); //卖平今
		m_pTrade->CancelOrder("SHFE", "", 0, ""); //撤单*/
	}
}

void MyTrade::OnInstrumentsCallBack(vector<CThostFtdcInstrumentField> *pInstruments)
{
	printf("CallBack:接收代码列表\r\n");
	m_pTrade->SubMarketData("cu2205", 0);
}

void MyTrade::OnInvestorPositionsCallBack(vector<CThostFtdcInvestorPositionField> *pInvestorPosition)
{
	printf("CallBack:接收持仓\r\n");
}

void MyTrade::OnInvestorPositionCombineDetailsCallBack(vector<CThostFtdcInvestorPositionCombineDetailField> *pInvestorPositionCombineDetails)
{
}

void MyTrade::OnInvestorPositionDetailsCallBack(vector<CThostFtdcInvestorPositionDetailField> *pInvestorPositionDetails)
{
	printf("CallBack:接收持仓明细\r\n");
}

void MyTrade::OnLogCallBack(const string& time, const string& log)
{
}

void MyTrade::OnMarginRatesCallBack(vector<CThostFtdcInstrumentMarginRateField> *pInstrumentMarginRates)
{
	printf("CallBack:接收保证金\r\n");
}

void MyTrade::OnOrderInfoCallBack(CThostFtdcOrderField *pOrder)
{
	printf("CallBack:接收最新委托回报\r\n");
}

void MyTrade::OnOrderInfosCallBack(vector<CThostFtdcOrderField> *pOrders)
{
	printf("CallBack:接收历史委托\r\n");
}

void MyTrade::OnStateCallBack()
{
}

void MyTrade::OnTradeAccountCallBack(CThostFtdcTradingAccountField *pTradingAccount)
{
	printf("CallBack:接收账户信息\r\n");

}

void MyTrade::OnTradeRecordCallBack(CThostFtdcTradeField *pTradeInfo)
{
	printf("CallBack:接收最新成交回报\r\n");
}

void MyTrade::OnTradeRecordsCallBack(vector<CThostFtdcTradeField> *pTradeInfos)
{
	printf("CallBack:接收历史成交\r\n");
}
