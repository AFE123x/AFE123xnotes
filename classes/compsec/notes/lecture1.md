# Lecture one notes

## what is computer security

- computer security is the protection of information systems and the information they contain from unauthorized access, use, disclosure, disruption, modification, or destruction.
    - the size of these systems are vast (could be big/small).
    - security issues can cost money, and 95% of the security vunerabilities are caused by human error.

## CIA Triad - Foundatino of Computer Security

- There are three words that sumarizes computer security:
    - confidentiality: preserving authorized restrictions on information access and disclosure.
        - no one else except me should know my SSN, etc.
    - integrity: guarding against improper information, modification or destruction.
        - Example: Lets say my CS grades were X, then someone changed it to Y.
    - availability: ensure timely and reliable access to information by authorized users.


## confidentiality: two aspects

- Data confidentiality: Private information shouldn't be disclosed to unauthorized individuals
- Privacy: you have control over the collection, use and disclosure of personal information.
    - this is a key disctiontion, as for example, even if your instagram profile is private, instagram can still use your data for data collection.

- Protection Mechanisms:
    - Encryption (at rest & in transit)
    - Access control lists (ACLs)
    - Authentication systems
    - information classification.


## Integrity: two aspects

- Data Integrity: data hasn't been altered in an unauthorized manner.
    - if someone changed your grade in report card, for example
- System Integrity: System performs intended function without manipulation.
    - if your calculator's supposed to add, but substracts.

- common remedies:
    - hash functions (SHA-256).
    - digital signatures.
    - message authentication Codecs (MAC).
    - version control system.

## availability

- ensuring timely and reliable access to and use of information by authorized users.
- The system should **always** be available to the user, can't be brought down by a DDoS attack.

**threats**

- DoS attach -> DDoS protection
- Ransomware -> backup and recovery
- hardware failures -> redundancy & failover
    - example: what if tesla DSP fails?

## assets:

- resource of value requiring protect (data, hardware, software, people, services)
- whatever needs to be protected.

## vulnerability

- weakness in a system that can be exploited (software bugs, misconfigurations, human error, physical security).
- an open door, doesn't need a hacker to explicitly exploit it.

## threat

- potential for a threat agent to exploit of a vulnerability (hackers, insiders, natural disasters.)
- it's the act of the hacker, given they know about the vulnerability.

## attack

- Deliberate attempt to evade security service sand violate security policy.

## countermeasure

- Any means taken to deal with a security attacks (prevent -> detect -> recover).

## passive vs. active attacks

- contermeasures differ depending on passive vs. active attacks.


**passive attacks**

- I'm aiming to observe and monitor transmission.
    - We just want to obtain information being transmitted, don't actually change anything.
- this is a compromise of confidentiality, doesn't violate integrity or availability (not intrusive).
- Here, we need to **prevent**, as we can't detect passive attacks.
- **example**: packet sniffing.

- common defenses include encryption, VPNs, anonymous networks, traffic padding (sending bs), etc.

**active attacks**

- Here, the attacker will modify data stream or create false streams.
- The goal is to modify or disrupt system.

- easier to detect as the attacker leaves traces.
    - Prevention is hard, detection and recovery is the goal.

- four categories of active attacks:
    - masquerade: attacker pretends to be authorized user (stolen credentials).
    - replay: capture/retransmit legitimate data (capture and replay authentication credentials).
        - this is mainly why we have 2 factor authentication
    - modification: alter legitimate message (change amounts, modify routing info, etc.)
    - denial of service: prevent legitimate users from accessing service (floods, crashes).

## Compture security challenges

- Security isn't simple, as there are complex and contradictory requirements.
    - For example, a long password is nice, but not simple for the client.
- seen as impediment: it's inconvenient:
    - For example, using Duo to login.
- often an afterthought
    - security shouldn't be an afterthought. Security should be built in on the get go.
- requires monitoring:
    - there are people that just monitor, and see what's happening. Security is never an ending story.
- battle of wits: social engineering exploits human psychology.
    - you want things to be easier for you (social engineering), but that's a entry to security vunerabilities.
- little benefit until failure: hard to justify a security budget.
    - at first, it doesn't seem necessary, but the consequences are severe. 
- authentication challenges:
    - balance security with user convenience.

## policy vs. mechanism

- policy is a statement of what is and what is not.
    - example: password should be 12+ characters, have special characters, etc.
- mechanism it the implementation of the policy:
    - example: a password complexity checker, to enforce the policy described above.