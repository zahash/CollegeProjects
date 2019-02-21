# popleft -> execute -> append with BT = BT - TQuantum
# if BT - TQuantum < 0 -> don't append because process finished

from collections import deque
from process import Process
import threading
import random
import time


ready_queue = deque()
time_to_wait_for_new_process = 0.5
time_quantum = 3

max_time_taken_to_create_new_process = 3
max_burst_time = 10
# priority is from 1 to 5


def enqueue_random_process():

    print("creating process...")
    random_process = Process(Process.global_pid_counter, int(time.time()), random.randint(1, max_burst_time), random.randint(1, 5))
    print(f"process created: {random_process} \n")

    print("enqueuing process...")
    ready_queue.append(random_process)
    print(f"process enqueued: {ready_queue} \n")

    # making another thread to continuously call the function
    threading.Timer(random.randint(1, max_time_taken_to_create_new_process), function=enqueue_random_process).start()


def execute_process_from_ready_queue(time_to_wait_for_new_process=time_to_wait_for_new_process):
    try:
        process = ready_queue.popleft()

        if process.burst_time - time_quantum > 0:
            print(f"executing process: {process} \n")

            process.burst_time -= time_quantum
            ready_queue.append(process)

            time.sleep(time_quantum)

        else:  # if burst time <= time quantum
            print(f"executing process: {process} \n")
            time.sleep(process.burst_time)

        # making another thread to continuously call the function
        threading.Timer(0, function=execute_process_from_ready_queue, args=[time_to_wait_for_new_process]).start()

    except IndexError:  # if the queue is empty, sleep for a while and then execute again
        print(f"Queue is empty... waiting({time_to_wait_for_new_process}) for new processes \n")
        time.sleep(time_to_wait_for_new_process)
        execute_process_from_ready_queue()


T1 = threading.Timer(random.randint(1, max_time_taken_to_create_new_process), function=enqueue_random_process)
T2 = threading.Timer(0, function=execute_process_from_ready_queue, args=[time_to_wait_for_new_process])

T1.start()
T2.start()

# T1.join()
# T2.join()


# q = PriorityQueue()
# q.put([2, 'zahash'])
# q.put([1, 'hazash'])

# # while not q.empty():
# #     print(q.get())

# print(q.get())
# print(q.get())
# print(q.get())
# q.put([5, 'z'])
# print(q.get())
