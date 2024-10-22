import React, {useState} from 'react';
import SwitchFlag from "../SwitchFlag";
import {OperatorsButtonList} from "../OperatorsButtons/OperatorsButtonList";
import InputNumber from "../InputNumber/InputNumber";
import {NumberFormats} from "../NumberFormats";
import "./PhoneInput.css";

export const PhoneInput = ({IsPhoneInputValid}) => {

    const [id, setId] = useState(1);



    const CheckPhone = (value,number) => {
        IsPhoneInputValid(value,number);
    };

    return (
        <div className="container">
            <div className="phoneInput">
                    <label htmlFor="Number">Telephone Number</label>
                    <InputNumber ChangePhone = {CheckPhone} numbers={NumberFormats} id={id} setId={setId} />
                    <SwitchFlag id={id}/>
            </div>

            <div className="countrySelect">
                <label>Country</label>
                <select id="select" className="countrySelect_select" onChange={e => setId(+e.target.value)} style={{borderRadius: "5px"}}>
                    {NumberFormats.map(item =>
                        <option key={item.id} value={item.id} selected={id === item.id}>
                            {item.name}
                        </option>
                    )}
                </select>
            </div>

            <OperatorsButtonList  numberFormats={NumberFormats} id={id}/>
        </div>
    );
};


