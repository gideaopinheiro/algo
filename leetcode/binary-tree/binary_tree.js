var TNode = /** @class */ (function () {
    function TNode(val) {
        this.val = val;
        this.val = val;
        this.left = null;
        this.right = null;
    }
    return TNode;
}());
var a = new TNode('a');
var b = new TNode('b');
var c = new TNode('c');
var d = new TNode('d');
var e = new TNode('e');
var f = new TNode('f');
// a.left = b;
// a.right = c;
// b.left = d;
// b.right = e;
// c.right = f;
a.left = b;
a.right = c;
b.left = d;
b.right = e;
d.left = f;
var allNodes = [a, b, c, d, e, f];
function deathFirstValue(root) {
    if (root === null) {
        return;
    }
    deathFirstValue(root.left);
    deathFirstValue(root.right);
}
// deathFirstValue(a);
function breadthFirstValue(root) {
    if (root === null)
        return [];
    var values = [];
    var queue = [root];
    while (queue.length > 0) {
        var current = queue.shift();
        values.push(current.val);
        if (current.left !== null)
            queue.push(current.left);
        if (current.right !== null)
            queue.push(current.right);
    }
    return values;
}
var result = breadthFirstValue(a);
//console.log(result);
function deathFirstSearch(root, target) {
    if (root === null)
        return false;
    if (root.val === target)
        return true;
    return deathFirstSearch(root.left, target) || deathFirstSearch(root.right, target);
}
//console.log(deathFirstSearch(a, 'p'));
function sumTree(root) {
    if (root === null)
        return 0;
    return root.val + sumTree(root.left) + sumTree(root.right);
}
var a1 = new TNode(5);
var b1 = new TNode(11);
var c1 = new TNode(3);
var d1 = new TNode(4);
var e1 = new TNode(2);
var f1 = new TNode(1);
a1.left = b1;
a1.right = c1;
c1.left = f1;
b1.left = d1;
b1.right = e1;
//console.log(sumTree(a1));
//console.log(deathFirstSearch(a1, 9));
function minValTree(root) {
    if (root === null)
        return Number.MAX_VALUE;
    var a = Math.min(root.val, minValTree(root.left));
    var b = Math.min(root.val, minValTree(root.right));
    return (a < b) ? a : b;
}
var menorValor = minValTree(a1);
//console.log("O menor valor é: ", menorValor);
function maxPathSum(root) {
    if (root === null)
        return 0;
    var sumLeft = root.val + maxPathSum(root.left);
    var sumRight = root.val + maxPathSum(root.right);
    return (sumLeft > sumRight) ? sumLeft : sumRight;
}
function maxPathSumTree(root) {
    if (root === null)
        return -Infinity;
    if (root.left === null && root.right === null)
        return root.val;
    var maxChildPathSum = Math.max(maxPathSumTree(root.left), maxPathSumTree(root.right));
    return root.val + maxChildPathSum;
}
var maxPathSumResult = maxPathSum(a1);
var mpst = maxPathSumTree(a1);
//console.log('O caminho mais caro tem valor total de: ', maxPathSumResult);
//console.log('O caminho mais caro tem valor total de: ', mpst);
// function binaryTreeDepth(root: TNode<string>) {
//   if (root === null) return 0;
//   console.log(root.val);
//   const a = 1 + binaryTreeDepth(root.left);
//   const b = 1 + binaryTreeDepth(root.right);
//   return (Math.abs(a - b) > 1);
// }
function nodeDepth(node) {
    if (node === null)
        return 0;
    return 1 + Math.max(nodeDepth(node.left), nodeDepth(node.right));
}
function isBalancedTree(root) {
    if (root === null)
        return false;
    var stack = [root];
    while (stack.length > 0) {
        var current = stack.pop();
        var isBalanced_1 = !(Math.abs(nodeDepth(current.left) - nodeDepth(current.right)) > 1);
        if (!isBalanced_1) {
            return false;
        }
        if (current.left !== null)
            stack.push(current.left);
        if (current.right !== null)
            stack.push(current.right);
    }
    return true;
}
var isBalanced = isBalancedTree(a1);
console.log('A arvore é balanceada: ', isBalanced);
/**
 * Aluguel
 *      -->> Reserva de emergência (12 meses)
 * Comprar Imóvel (Financiamento é mais provável)
 *      -->> Dar lances na amortização
 *      -->> Renda Fixa (75%)
 *      -->> Renda Variável (25%)
 * Comprar carro (Financiamento é mais provável / 2ª mão)
 *
 */
