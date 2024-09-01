const gridtraveler = (m, n) => {
  if (m === 1 && n === 1) return 1;
  if (m === 0 || n === 0) return 0;
  return gridtraveler(m-1, n) + (gridtraveler(m, n-1))
}


const gridTravelerMemo = (m, n, memo={}) => {
  const key = m + ',' + n;

  if (key in memo) return memo[key];
  if (m === 1 && n === 1) return 1;
  if (m === 0 || n === 0) return 0;

  memo[key] = gridTravelerMemo(m - 1, n, memo) + gridTravelerMemo(m, n - 1, memo);
  return memo[key];
}

// console.log(gridtraveler(18, 18))
console.log(gridTravelerMemo(18, 18))
