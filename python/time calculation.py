import time
from functools import wraps
def time_calclation(func):
    @wraps(func)
    def a(*args,**kwargs):
        start = float(time.perf_counter())
        func(*args,**kwargs)
        end = float(time.perf_counter())
        print("%.6f"%(end-start))
    return a