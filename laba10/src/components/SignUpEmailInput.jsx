import React from 'react';

class SignUpEmailInput extends React.Component {
  constructor(props){
    super(props)

    this.state = {
      input: '',
    }
  }
  currentEmailInput = (e) =>{

    this.setState({ input: e.target.value })
    if( e.target.value.includes('@gmail.') ||
        e.target.value.includes('@mail.')  ||
        e.target.value.includes('@email.') ||
        e.target.value.includes('@yandex.')){
      this.props.checkValid(true)
    }
    else{
      this.props.checkValid(false)
    }
  }
  render() {

    return (
      <div>  
        <label htmlFor="">Введите электронную почту:</label>
        <input type="text" value={this.state.input} onChange={(e) => { return this.currentEmailInput(e) }}/>

      </div>

    );
  }
}



export default SignUpEmailInput;
