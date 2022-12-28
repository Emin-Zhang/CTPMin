/*
 * iCTPMin期货行情交易(开源)
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __MYTRADE_H__
#define __MYTRADE_H__
#pragma once
#include "stdafx.h"
#include "MT.h"

class MT;
/*
*我的交易
*/
class MyTrade
	: public CTPListener
{
public:
	/*
	*交易对象
	*/
	MT *m_pTrade;
public:
	/*
	*构造函数
	*/
	MyTrade();
	/*
	*析构函数
	*/
	virtual ~MyTrade();
public:
	/*
	*启动服务
	* @param appID 应用ID
	* @param authCode 用户代码
	* @param mdServer 行情端地址
	* @param tdServer 交易端地址
	* @param brokerID 机构账号
	* @param investorID 投资者账号
	* @param password 密码
	*/
	void Run(char *appID, char *authCode, char *mdServer, char *tdServer, char *brokerID, char *investorID, char *password);
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

#endif