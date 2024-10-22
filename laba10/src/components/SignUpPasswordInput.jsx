import React from 'react';
import ProgressBar from './ProgressBar';

class SignUpPasswordInput extends React.Component {
  constructor() {
    super()

    this.state = {
      input1: '',
      input2: '',
      trustFactor: 0,
      valid: true
    }
  }
  render() {

    const changeInput1 = (e) => {
      let trust = 0

      this.setState((state) => { return { input1: e.target.value } })

      //проверка на наличие букв 
      if ((/[a-z]/g).test(e.target.value))
        trust = trust + 1
      //проверка на наличие цифр
      if ((/\d/g).test(e.target.value))
        trust = trust + 1
      //проверка на наличие специальных символов
      if ((/[_\-$]/g).test(e.target.value))
        trust = trust + 1
      //проверка на наличие заглавных букв    
      if ((/[A-Z]/g).test(e.target.value))
        trust = trust + 1
      //проверка на длину    
      if (e.target.value.length > 10)
        trust = trust + 1

      if (e.target.value.length > 50)
        trust = trust + 1

      this.setState((state) => { return { trustFactor: trust } })

      if (this.state.input2 === e.target.value)
        this.props.checkValid(true)
      else
        this.props.checkValid(false)
    }

    const changeInput2 = (e) => {
      this.setState((state) => { return { input2: e.target.value } })

      if (this.state.input1 === e.target.value)
        this.props.checkValid(true)
      else
        this.props.checkValid(false)
    }

    const checkAlert = (e) => {
      if( this.state.input1 !== e.target.value )
        this.setState({ valid: false})
      else
        this.setState({ valid: true})
    }

    return (
      <div>
        <br />
        <label>Введите пароль:</label>
        <input
          type="password"
          minLength={5} maxLength={51}
          value={this.state.input1}
          onInput={(e) => {
            return changeInput1(e)
          }}  />
        <ProgressBar
          trust={this.state.trustFactor}
        />
        <label>Подтвердите пароль:</label>
        <input 
          type="text" 
          minLength={5} maxLength={51} 
          value={this.state.input2} 
          onChange={(e) => changeInput2(e)} 
          onBlur={(e) => checkAlert(e)}/>
        <span className='password_alert'>{ this.state.valid !== true ? 'Пароли не совпадают' : null}</span>
        <br />
        <br />
      </div>
    );
  }
}

export default SignUpPasswordInput;