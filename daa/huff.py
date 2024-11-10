import heapq

# Define a class for the nodes in the Huffman tree
class Node:
    def __init__(self, char, freq):
        self.char = char  # Character
        self.freq = freq  # Frequency of the character
        self.left = None  # Left child
        self.right = None  # Right child

    # Define a comparison method for the priority queue
    def __lt__(self, other):
        return self.freq < other.freq

# Function to build the Huffman tree
def build_huffman_tree(chars, freq):
    # Create a priority queue (min-heap) with initial nodes
    heap = []
    for i in range(len(chars)):
        node = Node(chars[i], freq[i])
        heap.append(node)
    heapq.heapify(heap)

    # Combine nodes until there is only one node left (the root of the tree)
    while len(heap) > 1:
        left = heapq.heappop(heap)  # Remove the node with the smallest frequency
        right = heapq.heappop(heap)  # Remove the next smallest node
        merged = Node(None, left.freq + right.freq)  # Create a new internal node
        merged.left = left  # Set the left child
        merged.right = right  # Set the right child
        heapq.heappush(heap, merged)  # Add the new node back to the heap

    return heap[0]  # The remaining node is the root of the Huffman tree

# Function to generate Huffman codes from the tree
def generate_codes(node, prefix="", codebook=None):
    if codebook is None:
        codebook = {}  # Initialize the codebook
    if node.char is not None:
        codebook[node.char] = prefix  # Assign the code to the character
    else:
        generate_codes(node.left, prefix + "0", codebook)  # Traverse left
        generate_codes(node.right, prefix + "1", codebook)  # Traverse right
    return codebook

# Example characters and their frequencies
chars = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
freq = [4, 7, 12, 14, 17, 43, 54]

# Build the Huffman tree and generate the codes
huffman_tree = build_huffman_tree(chars, freq)
huffman_codes = generate_codes(huffman_tree)

# Print the Huffman codes for each character
for char in chars:
    print(f"{char} -> {huffman_codes[char]}")