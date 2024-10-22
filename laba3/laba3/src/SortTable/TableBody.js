import {TableRaw} from "./TableRaw";
import react from "react";

export const TableBody = (content) => {
    return(
        <tbody>
        {content.map(TableRaw)}
        </tbody>
    )
}