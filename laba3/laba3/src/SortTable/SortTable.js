import {Component} from "react";
import {TableHeader} from "./TableHeader";
import {TableBody} from "./TableBody";
import "./SortTable.css"
import "./TableHeader.css"
import "./ArrowButtons.css"
import {content} from "./Content";

export class SortTable extends Component {

    constructor(props) {
        super(props);
        this.state = {array: content};
    }

        sortTable = (sortingValue, sortType) => {

        const direction = sortType === "ascending" ? 1 : -1;
        const currentContent = this.state.array;
        let newContent;

        switch (sortingValue) {
            case "price":
                newContent = currentContent.sort((a, b) => (a.price - b.price) * direction);
                break;
            case "inStock":
                newContent = currentContent.sort((a, b) => (a.inStock - b.inStock) * direction);
                break;
            case "name":
                newContent = currentContent.sort((a,b) => a.name>b.name);
                if (direction === -1) newContent.reverse();
                break;
        }
        this.setState( {array: newContent});
    }


    render() {
        return (
            <table>
                <TableHeader handler = {this.sortTable}/>
                {TableBody(this.state.array)}
            </table>
        )
    }
}
