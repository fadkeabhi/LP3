// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentManagement {
    // Define a structure for student data
    struct Student {
        int256 studId;
        string name;
        string department;
    }

    // Mapping to store student data by student ID
    mapping(int256 => Student) public studentMap;

    // Event emitted when a student is added
    event StudentAdded(int256 studId, string name, string department);

    // Event emitted when a student is updated
    event StudentUpdated(int256 studId, string name, string department);

    // Event emitted when a student is deleted
    event StudentDeleted(int256 studId);

    // Function modifier to prevent reentrancy
    modifier nonReentrant() {
        require(msg.sender != address(0), "Invalid caller");
        _;
    }

    // Function to add a new student
    function addStudent(
        int256 _studId,
        string memory _name,
        string memory _department
    ) public nonReentrant {
        // Check if student already exists
        require(studentMap[_studId].studId == 0, "Student already exists");

        // Create a new student
        Student memory student = Student(_studId, _name, _department);

        // Add student to mapping
        studentMap[_studId] = student;

        // Emit event
        emit StudentAdded(_studId, _name, _department);
    }

    // Function to update an existing student
    function updateStudent(
        int256 _studId,
        string memory _name,
        string memory _department
    ) public nonReentrant {
        // Check if student exists
        require(studentMap[_studId].studId != 0, "Student does not exist");

        // Update student data
        studentMap[_studId].name = _name;
        studentMap[_studId].department = _department;

        // Emit event
        emit StudentUpdated(_studId, _name, _department);
    }

    // Function to delete a student
    function deleteStudent(int256 _studId) public nonReentrant {
        // Check if student exists
        require(studentMap[_studId].studId != 0, "Student does not exist");

        // Delete student data
        delete studentMap[_studId];

        // Emit event
        emit StudentDeleted(_studId);
    }

    // Function to get student data by student ID
    function getStudent(int256 _studId) public view returns (Student memory) {
        // Check if student exists
        require(studentMap[_studId].studId != 0, "Student does not exist");

        // Return student data
        return studentMap[_studId];
    }

    function getSender() public view returns (address) {
        return msg.sender;
    }
}
