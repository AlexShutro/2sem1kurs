import React, { useState } from "react";
import './Notes.css'
function Notes(){
    let[heading,getHeading] = useState('')
    let[text,getText] = useState('')
    let [count, setCount] = useState(0);
     let[notes] = useState([])
   
    let date = new Date()
    function AddNewNote(e) {
        setCount(count + 1);
        e.preventDefault()
        notes.push(<div className={count < 7 ? "note" : "notemore"}>
            <p className={count < 7 ? "notvisible" : "visible"} >Слишком много заметок</p>
            <p className="heading">{heading}</p>
            <p className="data">  {date.toLocaleDateString()}</p>
            <p className="text">{text}</p>
        </div>)
        getHeading('')
        getText('')
      
      }
      function DeleteFirstNote(e){
     
         notes.shift()
         e.preventDefault()
         setCount(count - 1);
      }
      function DeleteLastNote(e){
     
        notes.pop()
        e.preventDefault()
        setCount(count - 1);
     }
    return(
        <div>
          
            <form className="NotesStyle">
                <p>Название</p>
                <input type ="text" value={heading} onChange={e => getHeading(e.target.value)}/>
                <p>Текст заметки</p>
                <textarea  rows = '5' value={text} onChange={e => getText(e.target.value)}></textarea>
                <br/>
                <button onClick={AddNewNote}>Add</button>
                <button className={count < 3 ? "notvisibleblock": "visibleblock"} onClick={DeleteFirstNote}>DeleteFirst</button>
                <button onClick={DeleteLastNote} className={count < 3 ? "notvisibleblock": "visibleblock"}>DeleteLast</button>
            </form>
           <div className="notes">
           {notes}
           </div>
        </div>
    )
}
export default Notes