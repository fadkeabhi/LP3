// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

/**
@title ContractName 
@dev ContractDescription
@custom:dev-run-script scripts/deploy_with_ethers.ts
*/

contract Student_management {
    struct Student {
        int256 stud_id;
        string name;
        string department;
    }

    Student[] public Students;

    function addStudent(
        int256 stud_id,
        string memory name,
        string memory department
    ) public {
        Student memory stud = Student(stud_id, name, department);
        Students.push(stud);
    }

    function getStudent(int256 stud_id)
        public
        view
        returns (string memory, string memory)
    {
        for (uint256 i = 0; i < Students.length; i++) {
            Student memory stud = Students[i];
            if (stud.stud_id == stud_id) {
                return (stud.name, stud.department);
            }
        }
        return ("Not Found", "Not Found");
    }
}
