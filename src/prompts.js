function buttonPrompt(method) {
    let value = window.prompt("How much?", "0");
    if (value == null || value == "") return;
    if (isNaN(parseInt(value))) {
        do {
            value = window.prompt("Not a Number.\nHow much?", "0");
            if (value == null || value == "") return;
        } while (isNaN(parseInt(value)));
    }
    if (parseInt(value) == 0) return;
    ajax(parseInt(value), method);    
}

function ajax(value, method) {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("money").innerHTML = this.responseXML.getElementsByTagName("MONEY")[0].innerHTML;
            document.getElementById("debt").innerHTML = this.responseXML.getElementsByTagName("DEBT")[0].innerHTML;
            document.getElementById("net").innerHTML = this.responseXML.getElementsByTagName("NET")[0].innerHTML;
        } else if (this.readyState == 4 && (this.status == 400 || this.status == 500)) {
            window.alert(this.responseText);
        } else if (this.readyState == 4 && this.status == 300) {
            location.assign(this.responseXML.getElementsByTagName("URL")[0].innerHTML);
        }
    };
    xmlhttp.open("POST", "process.php", true);
    xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xmlhttp.overrideMimeType('application/xml');
    xmlhttp.send("method=" + method + "&value=" + value);
}

function deposit() {return buttonPrompt("deposit");}
function withdraw() {return buttonPrompt("withdraw");}
function loan() {return buttonPrompt("loan");}
function payBack() {return buttonPrompt("payBack");}
function signOut() {return ajax(0, "signOut");}