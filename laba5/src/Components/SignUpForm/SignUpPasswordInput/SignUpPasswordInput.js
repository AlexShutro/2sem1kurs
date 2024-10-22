import {useEffect, useState} from "react";
import {ProgressBar} from "./ProgressBar";

export function SignUpPasswordInput({IsPasswordValid}) {

    const [password, setPassword] = useState('');
    const [passwordConfirm, setPasswordConfirm] = useState('');
    const [passwordStyle, setPasswordStyle] = useState("PasswordInput BlankPassword");
    const [progressBarValue, setProgressBarValue] = useState(0);




    useEffect(() => {
        if (password === passwordConfirm) {
            if (password === '') {
                setPasswordStyle("PasswordInput BlankPassword");
                ChangeProgressBarValue(0);
            } else {
                const passwordStrength= CheckPasswordStrength(password);
                ChangeProgressBarValue(passwordStrength);
                setPasswordStyle("PasswordInput ValidPassword");
                IsPasswordValid(true,password);
            }

        } else {
            IsPasswordValid(false);
            setPasswordStyle("PasswordInput InvalidPassword");
            ChangeProgressBarValue(0);
        }
    }, [password, passwordConfirm]);

    const CheckPasswordStrength = (password) => {
        let strength = 25;

        if (password.length >= 8) {
            strength += 25;
        }
        if (password.match(/([a-zA-Z])/) && password.match(/([0-9])/)) {
            strength += 25;
        }
        if (password.match(/([!,%&@#$^*?_~])/)) {
            strength += 25;
        }


        return strength;
    };

    const ChangePassword = (e) => {
        setPassword(e.target.value);
    }

    const ChangePasswordConfirm = (e) => {
        setPasswordConfirm(e.target.value);
    }

    const ChangeProgressBarValue = (value) => {
         setProgressBarValue(value);
    }




    return (
        <>
            <div className="formField password">
                <label htmlFor="Password">Password</label>
                <input type="password" onChange={ChangePassword} className={passwordStyle} id="password" placeholder="Пароль"/>
            </div>
            <div className="formField password">
                <label htmlFor="PasswordConfirm">Password Confirm</label>
                <input type="password" onChange={ChangePasswordConfirm} className={passwordStyle} id="passwordConfirm" placeholder="Подтвердить"/>
            </div>
            <ProgressBar currentValue={progressBarValue}/>
        </>
    );

}