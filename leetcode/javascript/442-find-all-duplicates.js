/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
  const duplicates = new Map();
  const answer = [];
  for (const n of nums) {
    if (duplicates.has(n)) {
      answer.push(n);
    } else {
      duplicates.set(n, 1);
    }
  }
  return answer;
};

const array = [4,3,2,7,8,2,3,1]
console.log(findDuplicates(array));
