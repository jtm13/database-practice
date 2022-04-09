DIR = /c/xampp/htdocs/mine/bank/
SRC = src/

all: 	login bank_account

login:
	cp $(SRC)login.php $(DIR)

bankAccount : container css
	cp $(SRC)bankAccount.php $(DIR)

main: bankAccount defined
	cp $(SRC)main.php $(DIR)

container:
	cp $(SRC)container.php $(DIR)

bank_account: main favicon template css process prompts
	cp $(SRC)bank_account.php $(DIR)

process: bankAccount defined
	cp $(SRC)process.php $(DIR)

prompts:
	cp $(SRC)prompts.js $(DIR)

template:
	cp $(SRC)template.php $(DIR)

favicon:
	cp img/favicon.svg $(DIR)img/

css:
	cp $(SRC)css/*.css $(DIR)css/

defined: 
	cp $(SRC)private/defined.php $(DIR)private/

clean:
	rm -f $(DIR)*.*
	rm -f $(DIR)css/*.css
