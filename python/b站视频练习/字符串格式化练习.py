name='传智播客'
stock_price='003032'
stock_code=19.99
stock_price_daily_growth_factor=1.2
growth_days=7
print(f"公司:{name},股票代码:{stock_price},当前股价:{stock_code}")
print("每日增涨系数是:%1.1f,经过%i天的增长后,股价达到了:%.2f" %(stock_price_daily_growth_factor,growth_days,stock_code*stock_price_daily_growth_factor**growth_days))