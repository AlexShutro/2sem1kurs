import React, { Component } from "react";
import List from "./List";
class JobMenu extends Component {
  constructor(props) { //Вызывается до монтирования и реализации компонента React. React.Component 
   super(props); // При реализации конструктора подкласса React.Component вы должны называть super(props) перед любым другим выражением. 
    this.state = { // В противном случае this.props не будет определен в конструкторе, что может привести к багам.
      job: "1",
    };
    this.handleChange = this.handleChange.bind(this);
    //Метод bind() создаёт новую функцию, которая при вызове устанавливает в качестве 
    //контекста выполнения this предоставленное значение
    // handleChange() используется для установки нового состояния для входных данных.
  }  handleChange(choose) {
    this.setState({//добавляет в очередь изменения в состоянии компонента, Планирует обновление объекта компонента
      job: choose.target.value,
    });
  }

  render() {
    return (
      <div>
        <form>
          <select
            id="_select"
            value={this.state.job}
            onChange={this.handleChange}
          >
            <option value="1">Спасатель</option>
            <option value="2">Ветеринар</option>
            <option value="3">Программист</option>
            <option value="4">Банкир</option>
            <option value="5">Психолог</option>
            <h1 value='6'>Стоматолог</h1>
          </select>
        </form>
        <div>
          <List jobs={this.state.job }/>
        </div>
      </div>
    );
  }
}
export default JobMenu;