import heapq

class node:

    def __init__(self, freq, symbol, left=None, right=None):

        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = ''

    def __lt__(self, nxt):
        return self.freq < nxt.freq



def printnodes(node, val = ''):
    
    newval = val + node.huff

    if(node.left):
        
        printnodes(node.left, newval)

    if(node.right):
        
        printnodes(node.right, newval)
    if(not node.left and not node.right):
        print(node.symbol, " ->", newval)
        
w = int (input ("Enter Total Number of Characters: "))    
    
chars = []
for i in range(w):
    p = input("Enter the Character: ")
    chars.append(p)
    
freq = []
for i in range(w):
    p = int(input("Enter the Frequency: "))
    freq.append(p)

nodes = []

for n in range(len(chars)):
    heapq.heappush(nodes, node(freq[n], chars[n]))


while len(nodes) > 1:

    left = heapq.heappop(nodes)
    right = heapq.heappop(nodes)

    left.huff = '0'
    right.huff = '1'

    newNode = node(left.freq+right.freq, left.symbol+right.symbol, left = left, right = right)

    heapq.heappush(nodes, newNode)

printnodes(nodes[0])





    
