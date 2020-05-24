# Author: allannozomu
# Runtime: 52 ms
# Memory: 14 MB

class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        valid_emails = {}
        
        for email in emails:
            local_name, domain_name = email.split('@')
            
            local_name = local_name.replace('.', '')
            if '+' in local_name:
                local_name = local_name[:local_name.index('+')]
            valid_emails[local_name + '@' + domain_name] = 1
            
        return len(valid_emails)
            
            