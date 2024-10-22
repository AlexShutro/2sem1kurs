import React from 'react';
import { countryPhoneList } from "../countryPhone.data"
import PhoneInput from './PhoneInput';
import "../styles/form.css"

class MyPhoneInput extends React.Component {
  constructor(props){
    super(props);
    this.state = {
      input:'',
      select: 'none',
      country: '',
      mask: '+999',
      code: ''
    }
  }

  render() {
    const operatorChange = (e) => {
      this.setState({ 
        code: e.target.value, 
        input: this.state.input + e.target.value
      })
    }

    const addOperator = () => {
      const country = this.state.country
      const filteredList = countryPhoneList.filter(currentCountry => currentCountry.country === country)

      return(
          filteredList.length?(
            filteredList[0].data.operators.map((operator,id) => 
            <div className='operators' key={id}>
              <input 
                className='radio'
                type='radio' 
                name={operator.radio} 
                value={operator.code} 
                onChange={(e) => operatorChange(e)}
              />
              <label htmlFor="" className='radio'>{operator.name}</label>
            </div>
            )
          ):(
            null
          )
      )

    }

    const SelectCountryCode = (e) => {
      const country = e.target.value

      let whichMask = "+999"
      let selectValue = 'none'
      let newCountry = ''

      if(country === '+375'){
        whichMask = countryPhoneList[0].data.mask
        selectValue = '+375'
        newCountry = 'Belarus'
      }

      else if(country === '+7'){
        whichMask = countryPhoneList[1].data.mask
        selectValue = '+7'
        newCountry = 'Russia'
      }

      else if(country === '+380'){
        whichMask = countryPhoneList[2].data.mask
        selectValue = '+380'
        newCountry = 'Ukraine'
      }

      else if(country === '+48'){
        whichMask = countryPhoneList[3].data.mask
        selectValue = '+48'
        newCountry = 'Poland'
      }

      else if(country === '+370'){
        whichMask = countryPhoneList[4].data.mask
        selectValue = '+370'
        newCountry = 'Lithuania'
      }

      else if(country === '+371'){
        whichMask = countryPhoneList[5].data.mask
        selectValue = '+371'
        newCountry = 'Latvia'
      }

      return(
        this.setState({ 
          input : e.target.value,
          mask : whichMask,
          select : selectValue,
          country : newCountry
        })
      )
    }
     
    const CountryCode = (e) => {
      const numberString = e.target.value
      let whichMask = '+999'
      let selectValue = 'none'
      let country = 'none'

        if (numberString.includes('+375')){
          whichMask = countryPhoneList[0].data.mask
          selectValue = '+375'
          country = 'Belarus'
        }

        else if (numberString.includes('+7')){
          whichMask = countryPhoneList[1].data.mask
          selectValue = '+7'
          country = 'Russia'
        }

        else if (numberString.includes('+380')){
          whichMask = countryPhoneList[2].data.mask
          selectValue = '+380'
          country = 'Ukraine'
        }

        else if (numberString.includes('+48')){
          whichMask = countryPhoneList[3].data.mask
          selectValue = '+48'
          country = 'Poland'
        }
        else if (numberString.includes('+370')){
          whichMask = countryPhoneList[4].data.mask
          selectValue = '+370'
          country = 'Lithuania'
        }
        
        else if (numberString.includes('+371')){
          whichMask = countryPhoneList[5].data.mask
          selectValue = '+371'
          country = 'Latvia'
        }

        return(
          this.setState({ 
            mask : whichMask,
            input : e.target.value,
            country : country,
            select : selectValue
          })
        )
    }

    return (
      <div>
        <div action="">
          <select className="select_country" onChange={(e) => SelectCountryCode(e)} value={this.state.select}>
            <option defaultChecked value="none">+</option>
            <option value="+375">+375 BEL</option>
            <option value="+7">+7 &nbsp;&nbsp;&nbsp;&nbsp;RUS</option>
            <option value="+380">+380 UKR</option>
            <option value="+48">+48 &nbsp;&nbsp;POL</option>
            <option value="+370">+370 LIT</option>
            <option value="+371">+371 LAT</option>
          </select>

          <div className='phoneInput'>
            <PhoneInput
              mask={this.state.mask}
              value={this.state.input}
              onChange={(e) => CountryCode(e)}>
            </PhoneInput>
          </div>
          {addOperator()}

        </div>
      </div>
    );
  }
}

export default MyPhoneInput;