pragma solidity ^0.8.0;

contract Bank {
    address public account;
    int public balance;

    constructor(){
        account = msg.sender;
    }

    function deposit(int amount) public {
        balance+=amount;
    }

    function withdraw(int amount) public {
        require(balance<amount, "Insufficient amount");
        balance-=amount;
    }

    function viewBalance() public view returns(int) {
        return balance;
    }
}