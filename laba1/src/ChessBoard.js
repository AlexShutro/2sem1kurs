import React from 'react';

const ChessBoard =() =>{
    const desk = [];
    for(let i=8;i>0;i--){
    desk.push(
      <tr>
        <td style={{color:" rgb(50, 31, 31"}}>{i}</td>
        <td style={{backgroundColor: i%2?"bisque":" rgb(50, 31, 31"}}></td>
        <td style={{backgroundColor: i%2?" rgb(50, 31, 31":"bisque"}}></td>
        <td style={{backgroundColor: i%2?"bisque":" rgb(50, 31, 31"}}></td>
        <td style={{backgroundColor: i%2?" rgb(50, 31, 31":"bisque"}}></td>
        <td style={{backgroundColor: i%2?"bisque":" rgb(50, 31, 31"}}></td>
        <td style={{backgroundColor: i%2?" rgb(50, 31, 31":"bisque"}}></td>
        <td style={{backgroundColor: i%2?"bisque":" rgb(50, 31, 31"}}></td>
        <td style={{backgroundColor: i%2?" rgb(50, 31, 31":"bisque"}}></td>
        <td style={{color:" rgb(50, 31, 31"}}>{i}</td>
      </tr>
    )
   }
   return desk;
}
const Letters =() =>{
    return (
     <tr className='letters'>
         <td></td>
         <td>a</td>
         <td>b</td>
         <td>c</td>
         <td>d</td>
         <td>e</td>
         <td>f</td>
         <td>g</td>
         <td>h</td>
         <td></td>
       </tr>
    )
 }

   export function Chess(){
    return (
        <table className='tab'>
            {Letters()}
            {ChessBoard()}
            {Letters()}
        </table>
    )
   }