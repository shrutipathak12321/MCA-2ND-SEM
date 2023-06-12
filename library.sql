use library_mca;
CREATE TABLE Books
(
	BookID varchar(6) NOT NULL,
    Title varchar(30) NOT NULL,
    Author varchar(30) NOT NULL,
    Book_Status varchar(20),
    Price varchar(10),
    PRIMARY KEY(BookID)
    
);

describe Books;
INSERT INTO Books VALUES('B00001','PROGRAMMING WITH JAVA','E BALAGURUSAMY','Available','500');
INSERT INTO Books VALUES('B00002','DATABASE MANAGEMENT SYSTEM','RAJIV CHOPRA','Available','300');
ALTER TABLE Books MODIFY TITLE VARCHAR(50);
INSERT INTO Books VALUES('B00003','PYTHON PROGRAMMING FOR BEGINNERS','ANTHONY ADAMS','Available','700');
INSERT INTO Books VALUES('B00004','OPERATING SYSTEMS','WILLIAM STALLINGS','Not Available','400');
INSERT INTO Books VALUES('B00005','DATA STRUCTURES USING C','REEMA THAREJA','Available','200');
SELECT * FROM library_MCA.Books;

CREATE TABLE Member
(
	MembID varchar(6) NOT NULL PRIMARY KEY,
    Name varchar(30) NOT NULL,
    Contact_No varchar(10) NOT NULL,
    Address varchar(50),
    Memb_Type varchar(20) NOT NULL,
    Memb_Date date,
    Expiry_Date date
 );   

 INSERT INTO Member VALUES('M00001','Arjun Kapoor','6778767564','Alipore,Kolkata','Student','2021-05-01','2026-04-30');
 INSERT INTO Member VALUES('M00002','Ishani Dutta','9387827966','Dhakuria,Kolkata','Teacher','2020-08-01','2025-07-30');
 INSERT INTO Member VALUES('M00003','Kabir Singh','8136976445','Jadavpur,Kolkata','Student','2018-10-01','2023-09-30');
 INSERT INTO Member VALUES('M00004','Ananya Pandey','9855465765','Behala,Kolkata','Staff','2022-05-01','2027-04-30');
SELECT * FROM library_MCA.Member;

 CREATE TABLE Publisher
(
	PubID varchar(6) NOT NULL PRIMARY KEY,
    Name varchar(30) NOT NULL,
    Contact_No varchar(30) NOT NULL,
    Address varchar(20)
);

INSERT INTO Publisher VALUES('P00001','Mc Graw Hill','6869875744','Gariahat,Kolkata');
INSERT INTO Publisher VALUES('P00002','Pearson','7834512879','Dumdum,Kolkata');
INSERT INTO Publisher VALUES('P00003','OXFORD','7812434509','Park Street,Kolkata');
INSERT INTO Publisher VALUES('P00004','WILEY','9823451289','Ballygunge,Kolkata');
SELECT * FROM library_MCA.Publisher;

 CREATE TABLE Staff
(
	StaffID varchar(6) NOT NULL PRIMARY KEY,
    Name varchar(30) NOT NULL,
    Contact_No varchar(30) NOT NULL,
    Address varchar(20)
);

INSERT INTO Staff VALUES('S00001','Aayan Kundu','7346015361','Tollygunge,Kolkata');
INSERT INTO Staff VALUES('S00002','Ishita Dutta','9572534269','New Alipore,Kolkata');
INSERT INTO Staff VALUES('S00003','Ananya Pandey','9855465765','Behala,Kolkata');
INSERT INTO Staff VALUES('S00004','Jay Mahato','9823451289','Ballygunge,Kolkata');
SELECT * FROM library_MCA.Staff;


