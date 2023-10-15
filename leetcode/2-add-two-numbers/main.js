class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    addTwoNumbers(l1, l2) {
        const dummy = new ListNode();
        let currentNode = dummy;
        let carry = 0;

        while (l1 || l2 || carry) {
            const value1 = l1 ? l1.val : 0;
            const value2 = l2 ? l2.val : 0;
            const sum = value1 + value2 + carry;

            carry = Math.floor(sum / 10);
            currentNode.next = new ListNode(sum % 10);
            currentNode = currentNode.next;

            if (l1) l1 = l1.next;
            if (l2) l2 = l2.next;
        }

        return dummy.next;
    }
}

function createLinkedListFromArray(array) {
    const dummy = new ListNode();
    let currentNode = dummy;

    for (const value of array) {
        currentNode.next = new ListNode(value);
        currentNode = currentNode.next;
    }

    return dummy.next;
}

function printLinkedListWithArrows(list) {
    const values = [];
    let currentNode = list;
    while (currentNode) {
        values.push(currentNode.val);
        currentNode = currentNode.next;
    }
    console.log(values.join(""));
}

const list1 = createLinkedListFromArray([2, 4, 3]);
const list2 = createLinkedListFromArray([5, 6, 4]);

const solution = new Solution();
const result = solution.addTwoNumbers(list1, list2);

printLinkedListWithArrows(result);
