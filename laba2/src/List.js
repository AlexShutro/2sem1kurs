import React, { Component } from "react";

class Menu extends Component {

  render() {
    switch (this.props.jobs) {
      case "1":
        return (
          <div>
            <ol>
            <li><a href="https://adukar.com/by/news/abiturientu/professiya-spasatel">Спасатель </a></li>
            <li><a href="https://fireman.club">Спасатель </a></li>
            <li><a href="https://fireguys.ru">Спасатель </a></li>
            <li><a href="https://mchs.fun">Спасатель </a></li>
            <li><a href="https://pojaru.net.ru">Спасатель </a></li>
            <li><a href="https://pozarka.ru">Спасатель</a></li>
            <li><a href="https://propozhar.ru">Спасатель</a></li>
            </ol>
          </div>
        );
      case "2":
        return (
          <div>
          <ol>
          <li><a href="https://adukar.com/by/news/abiturientu/professiya-veterinar">Ветеринар </a></li>
          <li><a href="https://glavnoehvost.by">Ветеринар </a></li>
          <li><a href="https://myvetexpert.ru">Ветеринар </a></li>
          <li><a href="https://veterinar.by">Ветеринар </a></li>
          <li><a href="https://bva.by">Ветеринар </a></li>
          <li><a href="https://veterynar.online">Ветеринар </a></li>
          <li><a href="https://veterinarka.ru">Ветеринар</a></li>
            </ol>
         </div>
        );
      case "3":
            return (
                <div>
                  <ol>
                  <li> <a href="https://kudapostupat.by/speciality/id/275">Программист </a></li>
                  <li> <a href="https://www.topassistant.ru">Программист </a></li>
                  <li> <a href="https://srs.myrusakov.ru">Программист </a></li>
                  <li> <a href="https://www.cyberforum.ru">Программист </a></li>
                  <li> <a href="http://learn.javascript.ru">Программист </a></li>
                  <li> <a href="http://iguania.ru">Программист </a></li>
                  <li> <a href="http://ruseller.com">Программист</a></li>
                  </ol>
                </div>
        );
      case "4":
        return (
          <div>
            <ol>
            <li><a href="https://www.kp.ru/putevoditel/obrazovanie/bankir/">Банкир </a></li>
            <li><a href="https://www.tadviser.ru">Банкир </a></li>
            <li><a href="https://webbankir.com">Банкир </a></li>
            <li><a href="https://yabankir.ru">Банкир </a></li>
            <li><a href="https://www.kommersant.ru">Банкир </a></li>
            <li><a href="https://www.kp.ru/putevoditel/obrazovanie/bankir/">Банкир </a></li>
            <li><a href="https://bankira.by/">Банкир</a></li>
            </ol>
          </div>
        );
      case "5":
        return (
          <div>
            <ol>
            <li><a href="https://www.profguide.io/professions/psychologist.html">Психолог </a></li>
            <li><a href="https://trevoga.by/">Психолог </a></li>
            <li><a href="https://xn--80aaitajhdnjfbjyemp7bo1jxc.xn--p1acf/">Психолог </a></li>
            <li><a href="https://www.b17.ru/">Психолог </a></li>
            <li><a href="https://pisareva.by/">Психолог </a></li>
            <li><a href="https://www.mymind.by/">Психолог </a></li>
            <li><a href="https://dushaved.by/">Психолог</a></li>
            </ol>
            </div>
        );
    }
  }
}
export default Menu;