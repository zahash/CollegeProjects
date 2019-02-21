from queue import PriorityQueue
from process import Process
import threading
import random
import time

# in SJF the burst time will be used as a priority
# becuase, process with least burst time should be
# executed first


# extending the class to have a nice repr
class PriorityQueue(PriorityQueue):
    def __repr__(self):
        return str(self.queue)


# overwriting the operator overload for the Process class
class Process(Process):
    def __lt__(self, other):
        return [self.burst_time, self.pid] < [other.burst_time, other.pid]

    def __le__(self, other):
        return [self.burst_time, self.pid] <= [other.burst_time, other.pid]

    def __gt__(self, other):
        return [self.burst_time, self.pid] > [other.burst_time, other.pid]

    def __ge__(self, other):
        return [self.burst_time, self.pid] >= [other.burst_time, other.pid]


ready_queue = PriorityQueue()
time_to_wait_for_new_process = 2

max_time_taken_to_create_new_process = 20
max_burst_time = 2
# priority is from 1 to 5


def enqueue_random_process():

    print("creating process...")

    random_process = Process(Process.global_pid_counter,
                             int(time.time()),
                             random.randint(1, max_burst_time),
                             random.randint(1, 5))

    print(f"process created: {random_process} \n")

    print("enqueuing process...")

    ready_queue.put([random_process.burst_time, random_process])

    print(f"process enqueued: {ready_queue} \n")

    # thread to call the function recursively
    threading.Timer(random.randint(1, max_time_taken_to_create_new_process), function=enqueue_random_process).start()


def execute_process_from_ready_queue(time_to_wait_for_new_process=time_to_wait_for_new_process):

    if ready_queue.empty():
        # print(f"Queue is empty... waiting({time_to_wait_for_new_process}) for new processes \n")
        # time.sleep(time_to_wait_for_new_process)
        # execute_process_from_ready_queue()

        print("Queue is empty... waiting for new processes\n")

    _, process = ready_queue.get()
    print(f"executing process: {process} \n")
    time.sleep(process.burst_time)

    # making another thread to continuously call the function
    threading.Timer(0, function=execute_process_from_ready_queue, args=[time_to_wait_for_new_process]).start()


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
