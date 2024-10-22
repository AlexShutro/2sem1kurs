import React from 'react';
import './App.css';
import {Chess} from './ChessBoard';

function App() {
  const arr = [ 
    { 
        stock_name: "EFX", 
        company_name: "Equifax Inc", 
        price: 163.55, 
        currency: "USD", 
        change: "+9.03"
    }, 
    { 
        stock_name: "IRM", 
        company_name: "Iron Mountain Inc", 
        price: 33.21, 
        currency: "USD", 
        change: "+1.42"
    }, 
    { 
        stock_name: "NTAP", 
        company_name: "NetApp Inc", 
        price: 54.81, 
        currency: "USD", 
        change: "-6.01"
    }, 
    { 
        stock_name: "CTL", 
        company_name: "Centurylink Inc", 
        price: 13.79, 
        currency: "USD", 
        change: "-1.37" 
    }];
    

  return (
   <div> 
    <h1>Задание 1</h1>
     { <input type="text" value={new Date().getDate()+'.0'+ (new Date().getMonth()+1) + '.' + new Date().getFullYear()}/>}
   <h1>Задание 2</h1>
   <table style={{borderCollapse:"collapse"}}>
     {arr.map((item) => ( 
                     <tr> 
                         <td style={{border:"1px solid black"}}>{item.stock_name}</td> 
                         <td style={{border:"1px solid black"}}>{item.company_name}</td> 
                         <td style={{border:"1px solid black"}}>{item.price}</td> 
                         <td style={{border:"1px solid black"}}>{item.currency}</td> 
                         <td style ={{background: item.change>0?"green":"red",border:"1px solid black"}}> 
                             {item.change}</td> 
                     </tr> 
                 )) 
             }
   </table>
   <h1>Задание 3</h1>
   <Chess/>
</div>
);}
export default App ;

