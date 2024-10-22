import React from 'react';
import SignUpEmailInput from "../components/SignUpEmailInput"
import SignUpPasswordInput from "../components/SignUpPasswordInput"
import MyPhoneInput from './MyPhoneInput';
import AdditionalInfo from './AdditionalInfo';
import PropTypes from 'prop-types';
import TestComponent from './TestComponent';


class SignUpForm extends React.Component {
  constructor(){
    super()

		this.state = {

      formValid: false,
      emailValid: false,
      passwordValid: false,
    }
    this.checkEmailValid = this.checkEmailValid.bind(this)
    this.checkFormValid = this.checkFormValid.bind(this)
    this.checkPasswordValid = this.checkPasswordValid.bind(this)
	}
	
  checkFormValid = () =>{
    if(this.state.emailValid === true && this.state.passwordValid === true){
      this.setState({formValid: true})
    }
    else{
      this.setState({formValid: false})
    }

  }

  checkPasswordValid = (check) =>{
    this.setState((state) => {
      return { passwordValid: check, formValid: state.emailValid === true && check === true }
     })
  }

  checkEmailValid = (check) =>{
    this.setState((state) => {
      return { emailValid: check, formValid: check === true && state.passwordValid === true }
     })
  }    


	testArray = []
	testBool = true
	testNumber = 0
	testObject = {
		testStringProperty: 'hello',
	}
	testString = 'hello!'
	testSymbol = Symbol('s')

	testFunction = () => {
		return 	
	}

  render() {

    return (
        <div className='form'>
          <form action="">
            <SignUpEmailInput checkValid={this.checkEmailValid}/>
            <SignUpPasswordInput checkValid={this.checkPasswordValid} />
            <AdditionalInfo/>
						<MyPhoneInput />
						<TestComponent
							array={this.testArray}
							bool={this.testBool}
							number={this.testNumber}
							object={this.testObject}
							string={this.testString}
							symbol={this.testSymbol}
							func={this.testFunction}
						/>
						<input type='submit' disabled={!this.state.formValid} />
					

          </form>
        </div>
    );
  }
}

SignUpPasswordInput.propTypes = {
	checkValid: PropTypes.func
};

SignUpEmailInput.propTypes = {
	checkValid: PropTypes.func
};

export default SignUpForm;
