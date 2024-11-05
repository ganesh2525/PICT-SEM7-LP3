import time

cur_x = 2  # The algorithm starts at x=2
rate = 0.1  # Learning rate
precision = 0.000001  # This tells us when to stop the algorithm
previous_step_size = 1
max_iters = 10000  # maximum number of iterations
iters = 0  # iteration counter
df = lambda x: 2 * (x + 3)  # Gradient of our function

while previous_step_size > precision and iters < max_iters:
    prev_x = cur_x  # Store current x value in prev_x
    cur_x = cur_x - rate * df(prev_x)  # Gradient descent step
    previous_step_size = abs(cur_x - prev_x)  # Change in x
    iters += 1  # iteration count
    print("Iteration", iters, "\nX value is", cur_x)  # Print iterations
    time.sleep(0.5)  # Pause for 0.1 seconds

print("The local minimum occurs at", cur_x)
