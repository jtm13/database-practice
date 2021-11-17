create table bank (
UserID int auto_increment,
AccountNumber int NOT NULL unique,
UserName VARCHAR(18) NOT NULL unique,
Pass VARCHAR(18) NOT NULL,
Money int unsigned default(0),
primary key(USERID)
);