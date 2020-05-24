# Author: allannozomu
# Runtime: 140 ms
# Memory: 19.9 MB

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        nodes_list = 
        nodes_queue = [root]
        while nodes_queue:
            new_nodes = 
            for node in nodes_queue:
                if node != None:
                    nodes_list.append(node.val)
                    new_nodes.append(node.left)
                    new_nodes.append(node.right)
                else:
                    nodes_list.append(None)
            nodes_queue = new_nodes
        nodes_string = ','.join([str(n) if n is not None else 'null' for n in nodes_list])
        return '[{}]'.format(nodes_string)


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data = data[1:-1]
        values = [int(val) if val != 'null' else None for val in data.split(',')]

        if values[0] is None:
            return None
        
        root = TreeNode(values[0])
        prev_nodes = [root]
        next_nodes = values[1:]
        
        while prev_nodes:
            new_nodes = 
            for i in range(len(prev_nodes)):
                curr = prev_nodes[i]
                if next_nodes[i * 2] is not None:
                    curr.left = TreeNode(next_nodes[i * 2])
                    new_nodes.append(curr.left)
                if next_nodes[i * 2 + 1] is not None:
                    curr.right = TreeNode(next_nodes[i * 2 + 1])
                    new_nodes.append(curr.right)
            next_nodes = next_nodes[len(prev_nodes) * 2 : ]
            prev_nodes = new_nodes
        print(root)
        return root
            

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))