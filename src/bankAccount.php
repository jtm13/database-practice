<?php
include_once("container.php");
class BankAccount extends Container {
    private int $money;
    private int $debt;
    private int $net;

    function __construct($it) {
        parent::__construct($it);
        $this->money = parent::getArray()["Money"];
        $this->debt = parent::getArray()["Debt"];
        $this->net = parent::getArray()["Net"];
    }

    function info(): string {
        return '<div class="account-info">
        <header class="info-header">
        <h3 class="Username">Hello ' .$_SESSION["User"] . ',</h3>
        <div class="account-number">
        <p class="number">Account Number: ' . parent::getArray()["AccountNumber"] . '</p>
        </div>
        </header>
        <div class="info">
        <table>
        <tr>
        <th class="first">Cash</td>
        <th class="first">Debt</td>
        <th class="first">Net</td>
        </tr>
        <tr>
        <td id="money">' . $this->money . '</td>
        <td id="debt">' . $this->debt . '</td>
        <td id="net">' . $this->net . '</td>
        </tr>
        </table>
        </div>
        </div>';
    }

    function getMoney(): int {
        return $this->money;
    }

    function getDebt(): int {
        return $this->debt;
    }

    function getNet(): int {
        return $this->net;
    }

    function deposit(int $val): bool {
        if ($this->money + $val >= 500000) return false;
        $this->money += $val;
        $this->computeNet();
        return true;
    }

    function withdraw(int $val): bool {
        $this->money -= $val;
        if ($this->money < 0) {
            if(!$this->loan(abs($this->money))) {
                $this->money += $val * 2;
                return false;
            }
            $this->money = 0;
        }
        $this->computeNet();
        return true;
    }

    function loan(int $val): bool {
        if ($this->debt + $val >= 500000) return false;
        $this->debt += $val;
        $this->computeNet();
        return true;
    }

    function payBack(int $val): bool {
        $this->debt -= $val;
        if ($this->debt < 0) {
            if(!$this->deposit(abs($this->debt))) {
                $this->debt += $val * 2;
                return false;
            }
            $this->debt = 0;
        }
        $this->computeNet();
        return true;
    }

    private function computeNet() {
        $this->net = $this->money - $this->debt;
    }
}
?>