const canSum = (targetSum, numbers) => {
  if (targetSum === 0) return true;
  if (targetSum < 0) return false;
  for (let elem of numbers) {
    if (canSum((targetSum - elem), numbers) === true) {
      return true;
    }
  }
  return false;
}

const canSumMemo = (targetSum, numbers, memo = {}) => {
  if (targetSum in memo) return memo[targetSum];
  if (targetSum == 0) return true;
  if (targetSum < 0) return false;
  for (let elem of numbers) {
    memo[elem] = canSum((targetSum - elem), numbers, memo)
    if (memo[elem] === true) {
      return memo[elem];
    }
  }
  memo[targetSum] = false;
  return false;
}

// console.log(canSum(2200158, [3, 7, 4, 5, 9, 1, 14]));
console.log(canSumMemo(2200158, [3, 7, 4, 5]));
