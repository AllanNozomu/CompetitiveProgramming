\*
Author: allannozomu
Runtime: 44 ms
Memory: 13.9 MB*\

class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter_logs = 
        digit_logs = 
        
        for log in logs:
            split_logs = log.split(' ')
            is_letter_log = False
            
            for word in split_logs[1:]:
                if not word.isdigit():
                    is_letter_log = True
                    break
                    
            if is_letter_log:
                letter_logs.append((' '.join(split_logs[1:]), split_logs[0]))
            else:
                digit_logs.append(log)
        
        letter_logs = sorted(letter_logs)
        res = 
        for letter_log, _id in letter_logs:
            res.append('{} {}'.format(_id, letter_log))
        
        return res + digit_logs
                