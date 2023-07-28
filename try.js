const MAX = 10;

class Stack {
  constructor() {
    this.data = new Array(MAX);
    this.top = -1;
  }

  isEmpty() {
    return this.top === -1;
  }

  isFull() {
    return this.top === MAX - 1;
  }

  push(item) {
    if (this.isFull()) {
      console.log("Stack overflow.");
    } else {
      this.top++;
      this.data[this.top] = item;
      console.log(`The item ${item} was pushed.`);
    }
  }

  pop() {
    if (this.isEmpty()) {
      console.log("Stack underflow.");
    } else {
      const item = this.data[this.top];
      this.top--;
      console.log(`${item} was removed from the stack.`);
    }
  }

  display() {
    if (this.isEmpty()) {
      console.log("The stack is empty.");
    } else {
      let result = "Stack elements: ";
      for (let i = this.top; i >= 0; i--) {
        result += this.data[i] + " ";
      }
      console.log(result);
    }
  }
}

function main() {
  const stack = new Stack();
  let choice;
  do {
    console.log("Stack operations:");
    console.log("1. Push");
    console.log("2. Pop");
    console.log("3. Display");
    console.log("4. Exit");
    console.log("Enter the choice:");
    choice = parseInt(prompt("Enter the choice:"));

    switch (choice) {
      case 1:
        const item = parseInt(prompt("Enter the item you want to insert:"));
        stack.push(item);
        break;
      case 2:
        stack.pop();
        break;
      case 3:
        stack.display();
        break;
      case 4:
        console.log("Exiting the program.");
        break;
      default:
        console.log("Invalid data.");
    }
  } while (choice !== 4);
}

main();

