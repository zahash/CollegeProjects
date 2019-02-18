import random

# class Process(NamedTuple):
#     pid: str
#     arrival_time: int
#     burst_time: int = None
#     priority: int = None


class Process:
    global_pid_counter = 0

    def __init__(self, pid, AT, BT, priority):
        self.pid = pid
        self.arrival_time = AT
        self.burst_time = BT
        self.priority = priority

        self.__class__.global_pid_counter += 1

    def __repr__(self):
        return f"[pid:{self.pid}, AT:{self.arrival_time}, BT:{self.burst_time}, priority:{self.priority}]"
