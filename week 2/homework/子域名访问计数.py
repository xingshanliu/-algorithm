class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        ans = []
        hash = {}
        for i in cpdomains:
            num, urls = i.split(' ')
            index = -1
            urls = urls.split('.')
            long = -len(urls)
            while index >= long:
                url = '.'.join(urls[index:])
                if url in hash:
                    hash[url] = hash[url] + int(num)
                else:
                    hash[url] = int(num)
                index -= 1
        for k, v in hash.items():
            ans.append(str(v) + ' ' + k)
        return ans
