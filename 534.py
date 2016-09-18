import sys

class QueenBoardBuilder():
    def __init__(self, n, m, w):
        self.n = n
        self.m = m
        self.w = w
        self.state_queen_vector = None
        self.state_queen_count = None
        self.solution_count = None
        self.solutions = None

    def build_count(self):
        self.state_queen_vector = [None for i in range(self.m)]
        self.state_queen_count = 0
        self.solution_count = 0
        self.__backtrack_count()
        return self.solution_count

    def build_solutions(self):
        self.state_queen_vector = [None for i in range(self.m)]
        self.state_queen_count = 0
        self.solutions = []
        self.__backtrack_solutions()
        return self.solutions

    def __backtrack_count(self):
        if self.state_queen_count == self.m:
            self.solution_count += 1
        else:
            safe_pos_list = self.__get_safe_pos_list()
            for i in safe_pos_list:
                self.state_queen_vector[self.state_queen_count] = i
                self.state_queen_count += 1
                self.__backtrack_count()
                self.state_queen_count -= 1

    def __backtrack_solutions(self):
        if self.state_queen_count == self.m:
            self.solutions.append(list(self.state_queen_vector))
        else:
            safe_pos_list = self.__get_safe_pos_list()
            for i in safe_pos_list:
                self.state_queen_vector[self.state_queen_count] = i
                self.state_queen_count += 1
                self.__backtrack_solutions()
                self.state_queen_count -= 1        

    def __get_safe_pos_list(self):
        safe_pos_sieve = [True for i in range(self.n)]
        k = self.state_queen_count
        for i in range(k):
            if k - i >= self.n - self.w:
                continue
            j = self.state_queen_vector[i]
            safe_pos_sieve[j] = False 
            h = k - i + j
            if h >= 0 and h < self.n:
                safe_pos_sieve[h] = False
            h = i - k + j
            if h >= 0 and h < self.n:
                safe_pos_sieve[h] = False
        return [i for i in range(self.n) if safe_pos_sieve[i]]

class StrongQueenAlgorithm():
    def __init__(self, n, w):
        self.builder = QueenBoardBuilder(n, n, w)

    def run(self):
        return self.builder.build_count()

class WeakQueenAlgorithm():
    def __init__(self, n, w):
        self.n = n
        self.w = w

    def run(self):
        states = QueenBoardBuilder(self.n, self.n - self.w, self.w).build_solutions()
        state_id_map = self.__get_state_id_map(states)
        transition_map = self.__get_transition_map(states, state_id_map)
        print('Q({0},{1}) dim = {2}'.format(self.n, self.w, len(states)))

        state_count = len(states)
        solution_count_vector = [1 for i in range(state_count)]
        for k in range(self.w):
            next_vector = [0 for i in range(state_count)]
            for i in range(state_count):
                for j in transition_map[i]:
                    next_vector[i] += solution_count_vector[j]
            solution_count_vector = next_vector
        return sum(solution_count_vector)

    def __get_transition_map(self, states, state_id_map):
        state_count = len(states)
        transition_map = [[] for i in range(state_count)]
        for i in range(state_count):
            state = states[i]
            for j in range(self.n):
                next_key = str(state[1:] + [j])
                if next_key in state_id_map:
                    transition_map[i].append(state_id_map[next_key])
        return transition_map

    def __get_state_id_map(self, states):
        output = {}
        for i in range(len(states)):
            key = str(states[i])
            output[key] = i
        return output

class Problem():
    def solve(self):
        print(self.get(14))

    def get(self, n):
        total_count = 0
        for w in range(n)[::-1]:
            count = WeakQueenAlgorithm(n, w).run()
            total_count += count
            print('Q({0},{1}) = {2}'.format(n, w, count))
        return total_count

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
