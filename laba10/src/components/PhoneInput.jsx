import React from "react";
import InputMask from 'react-input-mask';
import PropTypes from 'prop-types';


export default class PhoneInput extends React.Component{
  render(){
    return( 
    <InputMask
      mask={this.props.mask}
      maskChar={'_'}
      alwaysShowMask

      value={this.props.value} 
      onChange={this.props.onChange}>
    </InputMask>
  )
}
}

InputMask.propTypes = {
	mask: PropTypes.string,
	value: PropTypes.string
}