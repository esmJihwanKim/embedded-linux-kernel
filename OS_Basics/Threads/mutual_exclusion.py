from concurrent.futures import thread
import threading 

g_count = 0

def thread_main():
    global g_count
    lock.acquire()
    for i in range(10000000):
        g_count = g_count + 1
    lock.release()

lock = threading.Lock()
threads = []

for i in range(50):
    th = threading.Thread(target = thread_main)
    threads.append(th)

for th in threads:
    th.start()

for th in threads:
    th.join()

print('g_count = ', g_count)