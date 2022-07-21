long long colosseum(int N,vector<int> A) {
        int sz = A.size();
        vector<long long> first(A.size() , 0) , last(A.size() , 0);
        priority_queue<long long> pq; 
        int n = A.size()/3;
        first[0] = A[0];
        pq.push(-A[0]);
        for(int i = 1;i<n;i++){
            first[i] += first[i-1] + A[i];
            pq.push(-A[i]);
        }
        for(int i = n;i<2*n;i++){
            first[i] = first[i-1];
            if(first[i] < first[i] + A[i] + pq.top()){
                first[i] = first[i] + A[i] + pq.top();
                pq.pop();
                pq.push(-A[i]);
            }
        }
         priority_queue<long long> q; 
        last[A.size()-1] = A.back();
        q.push(A.back());
        for(int  i = A.size()-2;i>=2*n;i--){
            last[i] = last[i+1] + A[i];
            q.push(A[i]);
        }
        for(int i = 2*n-1;i>=n;i--){
             last[i] = last[i+1];
             if(last[i] > last[i] + A[i] - q.top()){
                 last[i] = last[i] + A[i] - q.top();
                 q.pop();
                 q.push(A[i]);
             }
        }
        long long ans = INT_MIN;
        for(int i = n;i<=2*n;i++){
            ans = max(ans , first[i-1] - last[i]);
        }
        return ans;
        
   }