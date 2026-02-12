# lecture 5

## what is access control

- access control determines who can access what resource and what operations can they perform.

## access control components

- three major components:
    - subject: entities that request access. For example, a person, process, etc.
    - object: files, directories, printers, etc.
    - operation (access rights): for example: read, write, execute, delete, etc.


## principles of access

- least priviledge: give users the minimum permissions needed to do their job.
- separation of duties: critical operations where no single person can execute the job.
    - AKA: two people need to agree to let a job happen.
- defense in depth: multiple layers of access control.
    - example: there are multiple steps taken to access sensitive data.
- fail safe defaults: default is deny access, explicitly grant permissions.

## DAC 

- Discretionary Access Control
- Access control where the owner of an object can decide who can access it.
    - aka, the object owner controls access.

### dac implementation

- it's simply a matrix consisting of people per row, and each column contains the thing that needs access permissions, like a file.

### advantages

- flexible: owner controls their resources
- easy to understand and implement
- common in operating systems

### limitations

- trojan horse attack impersonates user
- no central control: hard to enfoorce organizational policy
- permission creep: users accumulate permissions over time
- difficult to audit

## ACL

- here, we store a list of subjects and their permissions with each object.

- Object: report.pdf
    - alice: read, write
    - bob: read

### advantages

- easy to see who can access an object
- easy to revoke all access to object
- natural for operating systems.

### disadvantage

- hard to see all permissions for one user.
- hard to revoke user from all objects.


## capability based systems

- stores list of objects and permissions with each user.

- user: alice.
    - capabilities:
        - file1: read/write
        - file2: read
        - printer: write


### advantages

- easy to see all permissions for one user
- portable
- efficient for users

### disadvantage

- hard to see who can access specific object
- hard to revoke access to object
- security: must protect capabilities from forgery.

## MAC

- Mandatory Access Control

- access control based on system enforced security policy. User cannot override or change access rules
- here, the user's access depends on their security label.

### advantage

- strong security
- prevents trojan horse attacks
- enforces organizational policy centrally
- good for classified/regulated environments

### disadvantage

- complex to configure and manage
- less flexible
- can interfere with legitimate use
- requires careful policy design

## RBAC

- assign permission to roles
    - elon is ceo, has access to more things than a senior software engineer.