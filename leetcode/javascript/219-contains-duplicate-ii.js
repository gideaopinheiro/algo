/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
  const numerosNaJanela = new Map();

  for (let i = 0; i < nums.length; i++) {
    if (i - numerosNaJanela.get(nums[i]) <= k) {
      return true;
    }
    numerosNaJanela.set(nums[i], i);
  }

  return false;
};

// AINDA ESTÁ ERRADA 
const caso1 = [1, 2, 3, 1];
const caso2 = [1, 0, 3, 1];
const caso3 = [1, 2, 3, 1, 2, 3];
console.log('caso 1: ', containsNearbyDuplicate(caso1, 3));
console.log('\n');
console.log('caso 2: ', containsNearbyDuplicate(caso2, 1));
console.log('\n');
console.log('caso 3: ', containsNearbyDuplicate(caso3, 2));

