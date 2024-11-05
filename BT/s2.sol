pragma solidity ^0.8.22;

contract StudentData {
    struct Student{
        uint roll;
        string name;
    }

    event UnmatchedFunctionCall(address sender,uint value,bytes data);
    event EtherReceived(address sender,uint value);

    Student[] public arr;

    function addStudent(uint roll, string memory name) public {
        for(uint i=0; i<arr.length; i++){
            if(arr[i].roll==roll){
                revert("Roll no. not exist");
            }
        }
        arr.push(Student(roll,name));
    }  

    function getStudent(uint index) public view returns(Student memory) {
        require(index<arr.length,"Outoff index");
        return arr[index];
    } 

    function getAllStudent() public view returns(Student[] memory) {
        return arr;
    }

    function totalStudent() public view returns(uint) {
        return arr.length;
    }      

    fallback() external payable {
        emit UnmatchedFunctionCall(msg.sender,msg.value,msg.data);
    }

    receive() external payable {
        emit EtherReceived(msg.sender,msg.value);
    }
}

