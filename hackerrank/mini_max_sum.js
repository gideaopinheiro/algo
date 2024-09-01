function miniMaxSum(arr) {
  newArr = arr.sort((a, b) => a - b);
  mini = newArr.slice(0, arr.length - 1).reduce((acc, elem) => acc + elem);
  max = newArr.slice(1, arr.length).reduce((acc, elem) => acc + elem);
  console.log(`${mini} ${max}`);
}

// miniMaxSum([1, 3, 5, 7, 9])
miniMaxSum([1, 2, 3, 4, 5]);