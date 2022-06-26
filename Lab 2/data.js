// importing required package/module
const fspromise = require('fs').promises;
const path = require('path');

var employee = {} // empty Object
var customers = {} // empty Object
var outputarray = []; // empty array

const fileops = async () => {
  try {
    // Reading data from data.txt file
    const data = await fspromise.readFile(path.join(__dirname, 'data.txt'), 'utf-8');
    // spliting data into a single line
    data.split(/\r?\n/).
    forEach(line => {
      // spliting the data into a single word
      var splitted_line = line.split(" ");
      // checking the first word of data is e or c
      if (splitted_line[0] === 'e') {
        const id = splitted_line[1];
        const name = splitted_line[2]
        employee[id] = name;
      }
      if (splitted_line[0] === 'c') {
        const id = splitted_line[1];
        const name = splitted_line[2];
        const balance = splitted_line[3];
        var c = {}
        c.name = name
        c.balance = balance
        customers[id] = c
      }
      // checking the first line is t or not
      if (splitted_line[0] == 't') {
        const customerId = splitted_line[1];
        const employeeId = splitted_line[2];
        const withdrawOrDeposit = splitted_line[3];
        let amount = splitted_line[4];
        // checking the fourth line is d or w
        if (withdrawOrDeposit === 'd') {
          // converting the string value into float
          let currentBalance = parseFloat(customers[customerId].balance);
          currentBalance += parseFloat(amount);
          // set customer balance
          customers[customerId].balance = currentBalance.toFixed(2);
          amount = `+$${amount}`;
        }
        if (withdrawOrDeposit === 'w') {
          // converting the string value into float
          let currentBalance = parseFloat(customers[customerId].balance);
          currentBalance -= parseFloat(amount);
          // set customer balance
          customers[customerId].balance = currentBalance.toFixed(2);
          amount = `-$${amount}`;
        }
        // creating the array of the output value
        const output = `${customers[customerId].name} ${employee[employeeId]} ${amount} $${customers[customerId].balance}`;
        outputarray.push(output);
      }
    });
    console.log("Output ---> ",outputarray);
    // handling the error
  } catch (error) {
    console.log(error);
  }
}


const testfileops = async () => {
  try {
    // reading the data from actualoutut.txt file
    const testdata = await fspromise.readFile(path.join(__dirname, 'ActualOutput.txt'), 'utf-8');
    var testarray = []; // empty array
    // creating the array of testdata
    testarray.push(testdata);
    // comparing the array of testdata with outputarray
    for (let i = 0; i < outputarray.length; i++) {
      if (testdata.split(/\r?\n/)[i] == outputarray[i]) {
        console.log("Test Successful","------->",i);
      } else {
        console.log("Test Unsuccessful","------->",i);
      }
    }
    // handling the error
  } catch (error) {
    console.log(error);
  }
}

fileops();
testfileops();