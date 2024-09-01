function matchingStrings(strings, queries) {
  let mapStrings = new Map();
  strings.forEach(str => {
    if (mapStrings.has(str)) {
      mapStrings.set(str, mapStrings.get(str) + 1);
    } else {
      mapStrings.set(str, 1);
    }
  });

  let results = [];

  queries.forEach(query => {
    if(mapStrings.has(query)) {
      results.push(mapStrings.get(query));
    } else {
      results.push(0);
    }
  });

  return results;
}

const result = matchingStrings(['ab', 'ab', 'abc'], ['ab', 'abc', 'bc']);
console.log(result);