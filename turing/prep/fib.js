
const fibonacci = (n) => {
  if (n <= 2) {
    return 1;
  }
  return fibonacci(n-1) + fibonacci(n-2);
}

const fibonacciDP = (n, memo = {}) => {
  if (n in memo) return memo[n];
  if (n <= 2) {
    return 1;
  }
  memo[n] = fibonacciDP(n - 1, memo) + fibonacciDP(n - 2, memo);
  return memo[n];
}

console.log(fibonacci(8));
console.log(fibonacciDP(50));
