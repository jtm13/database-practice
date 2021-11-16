create table bank (
UserID int auto_increment,
AccountNumber int NOT NULL unique,
UserName int NOT NULL unique,
Pass int NOT NULL,
Money int unsigned default(0),
primary key(USERID)
);