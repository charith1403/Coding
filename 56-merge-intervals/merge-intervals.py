class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if(len(intervals) == 1):
            return intervals
        
        intervals.sort(key = lambda x: (x[0], x[1]))
        ans : List[List[int]] = []
        start : int = intervals[0][0]
        end : int = intervals[0][1]
        i : int = 1

        while(i < len(intervals)):
            if(end >= intervals[i][0]):
                end = max(end,intervals[i][1])
                i+=1
                continue

            ans.append([start,end])
            start = intervals[i][0]
            end = intervals[i][1]
            i += 1

        ans.append([start,end])
        return ans