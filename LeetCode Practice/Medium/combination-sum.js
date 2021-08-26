var combinationSum = function(candidates, target) {
    let index = 0
    let inter = []
    let ans = []

    function backtracking(index, target, inter) {
        if(target === 0) {
            ans.push([...inter])
            return
        }
    
        if(target < 0) return;
    
        for(let i=index; i<candidates.length; i++) {
            inter.push(candidates[i])
            backtracking(i, target-candidates[i], inter)
            inter.pop()
        }
    }
    backtracking(index, target, inter)
    return ans;
};


// function fn(target ,sum ,index) {
  
//     if(target == 0){
//         return;
//     }
//     if(target<0) return;
//     for(let i = index;i<12;i++){
//         if(target- cand[i] >=0) {
//             sum+=cand[i];
//     fn(target-cand[i],sum,i);
//             sum-=cand[i];
//         }

//     }
// }