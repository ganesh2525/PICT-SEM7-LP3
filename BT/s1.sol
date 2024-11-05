// SPDX-License-Identifier: MIT
pragma solidity ^0.8.22;

contract StudentData {
    struct Student {
        uint roll;
        string name;
    }

    event StudentAdded(uint roll, string name);
    event UnmatchedFunctionCall(address sender, uint value, bytes data);
    event EtherReceived(address sender, uint value);

    Student[] public arr;

    function addStudent(uint roll, string memory name) public {
        for (uint i = 0; i < arr.length; i++) {
            if (arr[i].roll == roll) {
                revert("Roll No Exists!");
            }
        }
        arr.push(Student(roll, name));
        emit StudentAdded(roll, name); // Corrected event emission
    }

    function getAllStudents() public view returns (Student[] memory) {
        return arr;
    }

    function getTotalStudent() public view returns (uint) {
        return arr.length;
    }

    function getStudent(uint index) public view returns (Student memory) {
        require(arr.length > index, "Out of index"); // Corrected error message
        return arr[index];
    }

    // Fallback function to handle unmatched calls
    fallback() external payable {
        emit UnmatchedFunctionCall(msg.sender, msg.value, msg.data);
    }

    // Receive function to accept ether transfers
    receive() external payable {
        emit EtherReceived(msg.sender, msg.value);
    }
}


