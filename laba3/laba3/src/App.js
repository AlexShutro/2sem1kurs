import React, {useState} from 'react';
import { SortTable } from '../../../laba3/laba3/src/SortTable/SortTable';
const countries = [
    {name: 'Belarus', code: '+375', operators: ['МТС', 'A1', 'life:)']},
    {name: 'Russia', code: '+7', operators: ['Билайн', 'Мегафон', 'МТС', 'Tele2']},
    {name: 'Ukraine', code: '+380', operators: ['Lifecell', 'Vodafone', 'Київстар']},
    {name: 'Poland', code: '+48', operators: ['Orange', 'Play', 'Plus', 'T-mobile']},
    {name: 'Lithuania', code: '+370', operators: ['Telia', 'Bite', 'Tele2']},
    {name: 'Latvia', code: '+371', operators: ['LMT', 'Tele2', 'Bite']},
];

const operatorCodes = {
    'МТС': '29',
    'A1': '44',
    'life:)': '25',
    'Билайн': '99',
    'Мегафон': '92',
    'Tele2': '91',
    'Lifecell': '63',
    'Vodafone': '50',
    'Київстар': '67',
    'Orange': '22',
    'Play': '24',
    'Plus': '60',
    'T-mobile': '69',
    'Telia': '68',
    'Bite': '65',
    'LMT': '66',
};

const PhoneForm = () => {
    const [phoneNumber, setPhoneNumber] = useState('');
    const [selectedCountry, setSelectedCountry] = useState(countries[0]);
    const [selectedOperator, setSelectedOperator] = useState(selectedCountry.operators[0]);
    const [input, setInput] = useState(`+375`);

    const handleCountryChange = (event) => {
        const selectedCountryCode = event.target.value;
        const newSelectedCountry = countries.find((country) => country.code === selectedCountryCode);
        setSelectedCountry(newSelectedCountry);
        setPhoneNumber('');
        setInput(`${newSelectedCountry.code}`);
    };


    const handleOperatorChange = (event) => {
        const selectedOperatorName = event.target.value;
        const selectedOperatorCode = operatorCodes[selectedOperatorName];
        setSelectedOperator(selectedOperatorName);
        setPhoneNumber(selectedCountry.code + selectedOperatorCode);
        setInput(`${selectedCountry.code} (${selectedOperatorCode})`);
    };


    function inputHandler(event) {
        let countryCode = "";
        let operatorCode = "";
        let codesBuffer = "";
        let codesBuffer_raw = "";
        let bracketTemplate = false;
        let phoneNumber = "";
        let supportMode = false;
        let countryCodeStage = false;
        let operatorCodeStage = false;
        let phoneNumberStage = false;
        if (event.target.value[0] === '+') countryCodeStage = true;
        for (let i = 0; i < event.target.value.length; i++) {
            codesBuffer += event.target.value[i];
            codesBuffer_raw += event.target.value[i];

            if ((event.target.value[i] === ' ' || event.target.value[i] === '(') && countryCodeStage) {
                if (event.target.value[i] === '(' && !bracketTemplate) bracketTemplate = true;
                countryCode = codesBuffer.slice(0, codesBuffer.length - 1);
                countryCode = countryCode.replace(/\s/g, '');
                countryCodeStage = false;
                operatorCodeStage = true;
                codesBuffer = "";
            } else if ((event.target.value[i] === ' ' || event.target.value[i] === ')') && operatorCodeStage) {
                if (event.target.value[i] === ')' && !bracketTemplate) bracketTemplate = true;
                operatorCode = codesBuffer.slice(0, codesBuffer.length - 1);
                codesBuffer = "";
                phoneNumberStage = true;
                break;
            }
        }

        operatorCode = operatorCode.replace(/[()]/g, '');
        countryCode = countryCode.replace(/[()]/g, '');

        if (phoneNumberStage === true) {
            supportMode = true;
        }
        phoneNumber = event.target.value.replace(codesBuffer_raw, '');
        phoneNumber = phoneNumber.replace(`(${operatorCode})`, '');
        phoneNumber = phoneNumber.replace(/[a-zA-Z]/g, '');
        phoneNumber = phoneNumber.replace(/\s/g, '');
        phoneNumber = phoneNumber.replace(/(\d{3})(\d{2})(\d{2})/, "$1-$2-$3");

        let foundCountry = countries.find((country) => {
            if (countryCode === country.code) return country;
        })
        if (foundCountry) {
            setSelectedCountry(foundCountry);
        }

        if (supportMode) {
            if (bracketTemplate) {
                setInput(`${selectedCountry.code} (${operatorCode}) ${phoneNumber}`);
            } else {
                setInput(`${selectedCountry.code} ${operatorCode} ${phoneNumber}`);
            }
        } else {
            setInput(event.target.value);
        }
    }

    return (
        <div>
            <select id="select" value={selectedCountry.code} onChange={handleCountryChange}>
                {countries.map((country) => ( 
                    <option key={country.code} value={country.code}>
                        {country.name}
                    </option>
                ))}
            </select>
            <input onInput={inputHandler} value={`${input}`}/>
            <div>
                {selectedCountry.operators.map((operator) => (
                    <label key={operator}>
                        <input
                            type="radio"
                            value={operator}
                            checked={selectedOperator === operator}
                            onChange={handleOperatorChange}
                        />
                        {` ${operator} (${selectedCountry.code.substring(1, 3)})`}
                    </label>
                ))}
            </div>
            <div>
            <SortTable/>

            </div>
        </div>
    );
}

export default PhoneForm;
