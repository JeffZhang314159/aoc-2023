class TrieNode:
    def __init__(self, isWord, word = ''):
        self.isWord = isWord
        self.children = {}
        self.word = word

words = {
    'one': 1,
    'two': 2,
    'three': 3,
    'four': 4,
    'five': 5,
    'six': 6,
    'seven': 7,
    'eight': 8,
    'nine': 9
}

trie = TrieNode(False)
for word in words.keys():
    cur = trie
    for c in word:
        if c not in cur.children:
            cur.children[c] = TrieNode(False)
        cur = cur.children[c]
    cur.isWord = True
    cur.word = word

total = 0
with open('trebuchet.txt') as f:
    for line in f:
        nums = []
        partials = set()
        for c in line:
            if c.isnumeric():
                nums.append(int(c))
                partials.clear()
                continue

            newPartials = set()
            partials.add(trie)
            for p in partials:
                if c in p.children:
                    if p.children[c].isWord:
                        nums.append(words[p.children[c].word])
                    else:
                        newPartials.add(p.children[c])
            partials = newPartials
        
        #print(nums)
        total += nums[0]*10 + nums[-1]

print(total)