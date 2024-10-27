def trap_icarus(S):
    N = len(S) + 1  # Total nodes in the tree
    A = 1  # Starting node
    B = N  # Exit node, which is unreachable
    
    print(N, A, B)
    
    # Define the tree structure
    for i in range(1, N):
        left_child = 0   # No left child to keep the tree linear
        right_child = i + 1 if i + 1 <= N else 0
        print(left_child, right_child)

# Input
S = input().strip()
trap_icarus(S)
