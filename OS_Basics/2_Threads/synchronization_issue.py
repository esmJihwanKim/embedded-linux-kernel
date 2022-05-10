import threading 

g_count = 0

def thread_main():
    global g_count
    for i in range(1000000):
        g_count = g_count + 1

threads = []

for i in range(50):
    th = threading.Thread(target=thread_main)
    threads.append(th)

for th in threads:
    th.start()

print('g_count = ', g_count)

# Execution result as expected when range 10000
# but starts to become unstable when range value is greater 