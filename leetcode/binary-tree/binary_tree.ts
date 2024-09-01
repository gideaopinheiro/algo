class TNode <T> {
  public left: TNode<T>;
  public right: TNode<T>;
  
  constructor(public val: T) {
    this.val = val;
    this.left = null;
    this.right = null;
  }
}

const a = new TNode('a');
const b = new TNode('b');
const c = new TNode('c');
const d = new TNode('d');
const e = new TNode('e');
const f = new TNode('f');

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


const allNodes = [a, b, c, d, e ,f];

function deathFirstValue(root) {
  if (root === null) {
    return;
  }

  deathFirstValue(root.left);
  deathFirstValue(root.right);
}

// deathFirstValue(a);

function breadthFirstValue(root) {
  if (root === null) return [];

  const values = [];
  const queue = [root];

  while (queue.length > 0) {
    const current = queue.shift();
    values.push(current.val);

    if (current.left !== null) queue.push(current.left);
    if (current.right !== null) queue.push(current.right);
  }

  return values;
}


const result = breadthFirstValue(a);
//console.log(result);


function deathFirstSearch(root, target) {
  if (root === null) return false;
  if (root.val === target) return true;
  return deathFirstSearch(root.left, target) || deathFirstSearch(root.right, target);
}

//console.log(deathFirstSearch(a, 'p'));

function sumTree(root) {
  if (root === null) return 0;
  return root.val + sumTree(root.left) + sumTree(root.right);
}

const a1 = new TNode(5);
const b1 = new TNode(11);
const c1 = new TNode(3);
const d1 = new TNode(4);
const e1 = new TNode(2);
const f1 = new TNode(1);

a1.left = b1;
a1.right = c1;
c1.left = f1;
b1.left = d1;
b1.right = e1;


//console.log(sumTree(a1));
//console.log(deathFirstSearch(a1, 9));

function minValTree(root: TNode<number>) {
  if (root === null) return Number.MAX_VALUE;
  const a = Math.min(root.val, minValTree(root.left)) 
  const b = Math.min(root.val, minValTree(root.right));
  return (a < b) ? a : b;
}

const menorValor = minValTree(a1);
//console.log("O menor valor é: ", menorValor);

function maxPathSum(root: TNode<number>) {
  if (root === null) return 0;
  const sumLeft = root.val + maxPathSum(root.left);
  const sumRight = root.val + maxPathSum(root.right);
  return (sumLeft > sumRight) ? sumLeft : sumRight;
}

function maxPathSumTree(root: TNode<number>) {
  if (root === null) return -Infinity;
  if (root.left === null && root.right === null) return root.val;
  const maxChildPathSum = Math.max(maxPathSumTree(root.left), maxPathSumTree(root.right));
  return root.val + maxChildPathSum;
}

const maxPathSumResult = maxPathSum(a1);
const mpst = maxPathSumTree(a1);
//console.log('O caminho mais caro tem valor total de: ', maxPathSumResult);
//console.log('O caminho mais caro tem valor total de: ', mpst);

// function binaryTreeDepth(root: TNode<string>) {
//   if (root === null) return 0;
//   console.log(root.val);
//   const a = 1 + binaryTreeDepth(root.left);
//   const b = 1 + binaryTreeDepth(root.right);
//   return (Math.abs(a - b) > 1);
// }

function nodeDepth(node: TNode<number>):number {
  if (node === null) return 0;

  return 1 + Math.max(nodeDepth(node.left), nodeDepth(node.right));
}

function isBalancedTree(root: TNode<number>) {
  if (root === null) return false;

  const stack = [root];
  
  while (stack.length > 0) {
    const current = stack.pop();
    const isBalanced = !(Math.abs(nodeDepth(current.left) - nodeDepth(current.right)) > 1);
    if (!isBalanced) {
      return false;
    }
    if (current.left !== null) stack.push(current.left);
    if (current.right !== null) stack.push(current.right);
  }

  return true;
}

const isBalanced = isBalancedTree(a1);
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
