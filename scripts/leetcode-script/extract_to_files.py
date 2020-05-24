import json
import os
import shutil
from collections import defaultdict

if os.path.exists('res'):
    shutil.rmtree('res')
os.makedirs('res')

def create_if_not_exist(folder):
    if not os.path.exists(folder):
        os.makedirs(folder)
        
def get_difficulty(d):
    if d == 1:
        return "easy"
    if d == 2:
        return "medium"
    return "hard"

with open('result.json') as f:
    data = json.load(f)

with open('src/all_question.json') as f:
    question_data = json.load(f)
    questions = {q['stat']['question__title'] : q for q in question_data['stat_status_pairs']} 


count = defaultdict(int)
languages = defaultdict(set)
solved = [] 

readme = """
# Leetcode problems [![forthebadge](https://forthebadge.com/images/badges/60-percent-of-the-time-works-every-time.svg)](https://forthebadge.com)

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com) [![forthebadge](https://forthebadge.com/images/badges/made-with-python.svg)](https://forthebadge.com)

This repository contains the code of my submissions of leetcode problems. Some of them are closed problems so you may need subscription to access the statement of the problems. Each folder may contain more than one file because this repository contains all my AC submissions.

User: [allannozomu](https://leetcode.com/allannozomu/)

Total solved: {}

 - :green_heart: Easy: {} 
 - :yellow_heart: Medium: {} 
 - :heart: Hard: {} 

""".format(question_data['num_solved'], question_data['ac_easy'], question_data['ac_medium'], question_data['ac_hard'])

for resolution in data:
    if resolution['lang'] == 'java':
        continue

    folder = resolution['title']
    create_if_not_exist('res/{}'.format(folder))

    if count[folder] == 0:
        solved.append(questions[resolution['title']])

    count[folder] += 1
    languages[resolution['title']].add(resolution['lang'])

    filename = "{}.{}".format(count[folder], 'py' if resolution['lang'] == 'python3' else resolution['lang'])
    with open('res/{}/{}'.format(folder, filename), 'w') as f:
        f.write(resolution['code'])

readme += """| Id | Title | Dificulty | Paid only | Resolution Language|
|---|---|---|---|---|
"""
for k in sorted(solved, key=lambda item: item['stat']['question_id']):
    stat = k['stat']
    link = "https://leetcode.com/problems/{}".format(stat['question__title_slug'])
    readme += "[{}]({}) | {} | {} | {} | {}\n".format(
            stat['question_id'],
            link,
            stat['question__title'],
            get_difficulty(k['difficulty']['level']),
            ":lock:" if k['paid_only'] else "",
            ", ".join(languages[stat['question__title']]) 
            )
with open('README.md', 'w') as f:
    f.write(readme)

