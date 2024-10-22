import React, { useState } from "react";

const StudentInfoHandler = (props)=>{
    let emailOperator = props.emailst
    let numberOperator = props.telephonest
    // Email
    let emails  = ''
    if(emailOperator.includes('gmail.com')){
        emails = "gmail.com"
    }
    else if(emailOperator.includes('mail.ru')){
        emails = "mail.ru"
    }
    else if(emailOperator.includes('mail.com')){
        emails = "mail.com"
    }
    else{
       emails = "Неккоректно"
    }
    // Email

    // Telephone
    let operator = ''
    if(numberOperator.includes('37544')){
        operator = 'A1'
    }
    else if (numberOperator.includes('37529')){
        operator = 'МТС'
    }
    else if(numberOperator.includes('37533')){
        operator = 'A1'
    }
    else if(numberOperator.includes('37525')){
        operator = 'life'
      
    }
    else{
        operator = "Другой оператор"
    }
    
    // Telephone
    return(
        <tr>
                
                    <td>{props.nameSt}</td>
                    <td>{props.surnameSt}</td>
                    <td>{2023 - props.ageSt}</td>
                    <td>{props.facultyst}</td>
                    <td>{props.specializationst}</td>
                    <td>{props.groupst}</td>
                    <td>{props.emailst}</td>
                    <td>{emails}</td>
                    <td>{props.telephonest}</td>
                    <td>{operator}</td>
        </tr>
    )
}

const StudentInfo = ()=>{
   let[users, setUsers] = useState([
   { studentName: "Александр", surname: "Шутро",age:2004,faculty:"ФИТ",specialization:"ИСиТ",Group: 3,email:"alexshutro03@mail.ru",opemail:"mail.ru",
   phonenumber:"+375298047726",opteleph:"МТС" }
   ])
    let[studentName,getName] = useState('')
    let[surname, getSurName] = useState('')
    let[age, getAge] = useState(2023)
    let[faculty, getFaculty] = useState("")
    let[specialization, getSpecialization] = useState("")
    let[Group, getGroup] = useState()
    let[email,getEmail] = useState('')
    let[phonenumber, getphonenumber] = useState('')
    const AddNewUser = (e) =>{
        e.preventDefault()
        const newUser = {
            id: Date.now(),
            studentName,
            surname,
            age,
            faculty,specialization,Group,
            email, phonenumber
        }
        setUsers([...users,newUser])
        getName('')
        getSurName('')
        getFaculty('')
        getSpecialization('')
        getGroup('')
        getEmail('')
        getphonenumber('')
    }
    let days = []
    let year = []
    const monthName = ['January', 'February', 'March', 'April', 'May', 'June',
    'July', 'August', 'September', 'October', 'November', 'December'];
    let month = []
    for(let i = 1; i < 32; i++){
        days.push(<option>{i}</option>)
    }
    for(let i = 2023; i >= 1940; i--){
        year.push(<option>{i}</option>)
    }
    for(let i = 0; i < 12; i++){
        month.push(<option>{monthName[i]}</option>)
    }
    return(
        <div>
           <table>
            <tr>
                <td>Имя</td>
                <td>Фамилия</td>
                <td>Возраст</td>
                <td>Факультет</td>
                <td>Специальность</td>
                <td>Группа</td>
                <td>Email</td>
                <td>Email Adress</td>
                <td>Telephone</td>
                <td>Operator</td>
            </tr>
            
            {users.map(user =>
            <StudentInfoHandler surnameSt = {user.surname} nameSt = {user.studentName} ageSt = {user.age} 
            facultyst = {user.faculty} specializationst = {user.specialization} groupst = {user.Group} 
            emailst = {user.email} telephonest = {user.phonenumber}
            />)}
           </table>
           <form className="form">
           <p>Name</p>
            <input type="text" value={studentName} onChange={(e)=>{getName(e.target.value)} }/>
            <p>Surname</p>
            <input type="text" value={surname} onChange={(e)=>{getSurName(e.target.value)} }/>
            <p>Age</p>
            <select>{days}</select>
            <select>{month}</select>
            <select onChange={e => getAge(e.target.value)}>{year}</select>
            <p>Faculty</p>
            <input type="text" value={faculty} onChange={(e)=>{getFaculty(e.target.value)} }/>
            <p>Specialization</p>
            <input type="text" value={specialization} onChange={(e)=>{getSpecialization(e.target.value)} }/>
            <p>Group</p>
            <input type="text" value={Group} onChange={(e)=>{getGroup(e.target.value)} }/>
            <p>Email</p>
            <input type="text" value={email} onChange={(e)=>{getEmail(e.target.value)} }/>
            <p>Telephone</p>
            <input type="text" value={phonenumber} onChange={(e)=>{getphonenumber(e.target.value)} }/>
            <br/>
            <button onClick={AddNewUser}>Add</button>
           </form>
        </div>
    )
}
export default StudentInfo