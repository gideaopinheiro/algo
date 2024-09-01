function plusMinus(arr) {
  let negative = 0, positive = 0, neutral = 0;
  for (const element of arr) {
    if (element < 0) {
      negative++;
    } else if (element === 0) {
      neutral++;
    } else {
      positive++;
    }
  }

  const length = arr.length;

  console.log(`${(positive / length).toFixed(6)}\n${(negative / length).toFixed(6)}\n${(neutral / length).toFixed(6)}`);
}

plusMinus([1, 1, 0, -1, -1]);
