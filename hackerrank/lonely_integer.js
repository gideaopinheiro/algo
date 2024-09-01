function lonelyinteger(a) {
  const integerMap = new Map();
  a.forEach(element => {
    if (integerMap.has(element)) {
      integerMap.delete(element);
    } else {
      integerMap.set(element, 1);
    }
  });

  // return integerMap.keys().next().value;
  return [...integerMap.keys()][0];
}

const result = lonelyinteger([1, 2, 3, 4, 3, 2, 1]);
console.log(result);