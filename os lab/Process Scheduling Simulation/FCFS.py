from collections import deque
from process import Process
import threading
import random
import time

# one thread will generate new process and
# enqueues them to the ready queue

# another thread will run sleep(burst_time)
# of the most recent dequeued process
# which simulates the execution of program

ready_queue = deque()
time_to_wait_for_new_process = 0.5

max_time_taken_to_create_new_process = 5
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
