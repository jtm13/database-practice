<?php

function head(bool $logged_in = true): void {
    $str = ($logged_in) ? '<ul class="nav-list-container">
                    <!--The format is very important to enure there are no spaces between items-->
                    <li class="nav-list"><button onClick="deposit()" class="nav-buttons"> Deposit </a></li
                    ><li class="nav-list"><button onClick="withdraw()" class="nav-buttons"> Withdraw </a></li
                    ><li class="nav-list"><button onClick="loan()" class="nav-buttons"> Loans </a></li
                    ><li class="nav-list"><button onClick="payBack()" class="nav-buttons"> Payback Loans </a></li
                    ><li class="nav-list"><button onClick="signOut()" class="nav-buttons"> SignOut </a></li>
                </ul>' : '';
    echo '<header id="global-head">
            <nav id="global-navigation">
                <span id="global-name">Bank of Justin</span>'
                . $str .
            '</nav>
        </header>';
}

function foot(): void {
    echo '<footer id="global-foot">
    <p id="copyright">Copyright &#169 BANK OF JUSTIN COPYRIGHT 2022 | All Rights Reserved</p>
    </footer>';
}

function cssFile(string $fileName = "global"): void {
    echo '<link rel="stylesheet" type="text/css" href="css/' . $fileName . '.css">';
}

function jsFile(string $fileName) {
    echo '<script src="' . $fileName . '.js"></script>';
}

function favicon(): void {
    echo '<link rel="icon" type="image/x-icon" href="img/favicon.svg">';
}

function meta(string $description = "Bank of Justin Page", 
    string $keywords = "Bank of Justin"): void {
    echo '<meta charset="UTF-8">
        <meta name="description" content="' . $description . '">
        <meta name="keywords" content="' . $keywords . '">
        <meta name="author" content="Justin Moon">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">';
}

function headInfo(string $description, string $keywords, array $cssFiles = []): void {
    meta("Bank of Justin $description Page", "Bank of Justin $description, Bank of Justin, " . $keywords);
    jsFile("prompts");
    favicon();
    cssFile("normalize");
    cssFile();
    foreach($cssFiles as $file) {
        cssFile($file);
    }
}
?>