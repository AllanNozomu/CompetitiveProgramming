#include<bits/stdc++.h>

using namespace std;

typedef struct circle{
  long long x;
  long long y;
  long long r;
} circle;

int intersects(circle& c1, circle& c2) {
  long long dx = c1.x - c2.x;
  long long dy = c1.y - c2.y;
  if (dx * dx + dy * dy <= (c1.r + c2.r) * (c1.r + c2.r)) return 1;
  return 0;
}

int main(){
  int m, n, q;
  cin >> m >> n >> q; 

  vector<list<circle>> circles_group;

  for (int i = 0 ; i <  q; ++i){
    circle new_circle;
    cin >> new_circle.x >> new_circle.y >> new_circle.r;
    int match;
    
    list<circle> new_group = {new_circle};

    for (auto &circles : circles_group){
      match = 0;
      for (auto &circle : circles){
        if (intersects(circle, new_circle)){
          match = 1;
          break;
        }
      }
      if (match) {
        new_group.splice(new_group.end(), circles);
      }
    }
    circles_group.push_back(new_group);
  }

  circle entrance;
  entrance.x = entrance.y = 0;
  entrance.r = 0;

  circle art;
  art.x = m;
  art.y = n;
  art.r = 0;

  for (auto &circles : circles_group){
    long long min_x = m, max_x = 0, min_y = n, max_y = 0;
    for (auto &circle : circles){
      if (intersects(circle, art) || intersects(circle, entrance)){
        cout << 'N' << endl;
        return 0;
      }
      min_x = min(min_x, circle.x - circle.r);
      max_x = max(max_x, circle.x + circle.r);
      min_y = min(min_y, circle.y - circle.r);
      max_y = max(max_y, circle.y + circle.r);
    }
    if ((min_x <= 0 && max_x >= m) || (min_y <= 0 && max_y >= n) || (min_y <= 0 && min_x <= 0) || (max_x >= m && max_y >= n)) {
      cout << 'N' << endl;
      return 0;
    }
  }
  cout << 'S' << endl;

  return 0;
}