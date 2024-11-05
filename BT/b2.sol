pragma solidity ^0.8.0;

contract Bank {
    address public account;
    uint public balance;

    constructor(){
        account=msg.sender;
    }

    function deposit(uint amount) public {
        balance+=amount;
    }

    function withdraw(uint amount) public {
        require(balance<amount,"Insufficient Balance");
        balance-=amount;
    }

    function viewBalance() public view returns(uint) {
        return balance;
    }
}