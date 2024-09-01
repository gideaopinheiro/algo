const bulbsCost = (bulbs) => {
  let cost = 0;
  const size = bulbs.length;
  for (let i = 0; i < size; i++) {
    if (bulbs[i] === 0) {
      cost++;
      for (let j = i; j < size; j++) {
        bulbs[j] = (1 - bulbs[j]);
      }
    }
  }
  return cost;
}

const bulbsCostGreedy = (bulbs) => {
  let cost = 0;
  for (let b in bulbs) {
    if (cost % 2 === 0) {
      b = b;
    } else {
      b = (1 - b);
    }

    if (b % 2 != 1) {
      cost++;
    }
  }
  return cost;
}

console.log(bulbsCostGreedy([1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1]));
