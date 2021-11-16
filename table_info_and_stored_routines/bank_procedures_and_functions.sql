CREATE PROCEDURE new_account(AN INT, UN INT, P INT, M INT UNSIGNED)
insert into bank 
(accountnumber, username, pass, money)
values (AN, UN, P, M);
CREATE PROCEDURE update_Money(UN INT, M INT UNSIGNED, D INT UNSIGNED)
UPDATE bank
SET money=M,debt=D
WHERE username=UN;
CREATE PROCEDURE change_pass(UN INT, OP INT, NP INT)
UPDATE bank
SET pass=NP 
WHERE username=UN AND pass=OP;
CREATE PROCEDURE delete_account(UN INT, P INT)
DELETE FROM bank
WHERE username=UN AND pass=P;
DELIMITER $$
CREATE FUNCTION getMoney(UN INT, P INT)
 RETURNS INT
 READS SQL DATA
 BEGIN
 RETURN (SELECT money FROM bank WHERE username=UN AND pass=P);
 END; $$
DELIMITER $$
CREATE FUNCTION getDebt(UN INT, P INT)
 RETURNS INT
 READS SQL DATA
 BEGIN
 RETURN (SELECT debt FROM bank WHERE username=UN AND pass=P);
 END; $$ 
DELIMITER $$
DELIMITER $$
CREATE FUNCTION getNet(UN INT, P INT)
 RETURNS INT
 READS SQL DATA
 BEGIN
 RETURN (SELECT net FROM bank WHERE username=UN AND pass=P);
 END; $$ 
DELIMITER $$
# Returns 0 if credentials are not correct, 1 if it is
CREATE FUNCTION check_login(UN INT, P INT)
 RETURNS INT
 READS SQL DATA
 BEGIN
 RETURN (SELECT COUNT(
 CASE 
 WHEN username=UN AND pass=P THEN userid END)
 FROM bank);
 END; $$