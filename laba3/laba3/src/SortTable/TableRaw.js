export const TableRaw = (object, index) => {
    let className = "";
    if (+object.inStock === 0) className = "equal_to_0";
    else if (+object.inStock < 3) className = "less_than_3";
    return [
        <tr>
            <td> {index + 1} </td>
            <td> {object.name} </td>
            <td > {object.price} </td>
            <td className={className}> {object.inStock} </td>
        </tr>
    ];


}