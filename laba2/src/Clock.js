import React from 'react';
  export default class Clock extends React.Component {
  constructor(props){
    super(props);
this.state = {date:new Date()};
  }
  componentDidMount(){ //Вызывается сразу после монтирования компонента React
this.timerID = setInterval(() => this.tick(), 1000); // механизм принудительного обновления
  }
  componentWillUnmount(){ // (В этом методе выполняется) Вызывается непосредственно перед размонтированием и уничтожением компонента
clearInterval(this.timerID); //необходимый сброс: отмена таймеров, сетевых запросов и подписок, созданных в componentDidMount()
  }
  tick(){
    this.setState({ //Планирует обновление объекта компонента
        date: new Date()
    });
  }
}
