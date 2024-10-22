import React, { Component } from 'react';

class AdditionalInfo extends Component {
  render() {
    return (
      <div> 
        <label htmlFor="">Фамилия:</label>
        <input type="text" />
        <label htmlFor="">Имя:</label>
        <input type="text" />
        <label htmlFor="">Отчество:</label>
        <input type="text" />

        <input type="radio" name='gender' id='woman' className='radio' />
        <label htmlFor="woman" className='radio'>Женский</label>
        <input type="radio" name='gender' id='man' className='radio' />
        <label htmlFor="man" className='radio'>Мужской</label>
        <br />

        <label htmlFor="">Введите дату рождения:</label>
        <input type="date" />
      </div>
    );
  }
}

export default AdditionalInfo;
