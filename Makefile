DIR = /c/xampp/htdocs/mine/bank/
SRC = src/

all: 	bank_account

bankAccount : container normalize
	cp $(SRC)bankAccount.php $(DIR)

main: bankAccount defined
	cp $(SRC)main.php $(DIR)

container:
	cp $(SRC)container.php $(DIR)

bank_account: main favicon
	cp $(SRC)bank_account.html $(DIR)

favicon:
	cp img/favicon.svg $(DIR)img/

normalize:
	cp $(SRC)normalize.css $(DIR)

defined: 
	cp $(SRC)private/defined.php $(DIR)private/

clean:
	rm -f $(DIR)*.php
	rm -f $(DIR)*.css
