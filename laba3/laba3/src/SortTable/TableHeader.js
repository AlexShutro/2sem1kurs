import {ArrowButtons} from "./ArrowButtons";
import react from "react";

export class TableHeader extends react.Component {
    constructor(props) {
        super(props);
    }
    render() {
        return (
            <thead>
            <tr>
                <th>
                    <div className="head-items">
                        <span>Number</span>
                    </div>
                </th>
                <th>
                    <div className="head-items">
                        <span>Name</span>
                        <ArrowButtons arrowAttribute = "name" handler = {this.props.handler}/>
                    </div>
                </th>
                <th>
                    <div className="head-items">
                        <span>Price</span>
                        <ArrowButtons arrowAttribute = "price" handler = {this.props.handler}/>
                    </div>
                </th>
                <th>
                    <div className="head-items">
                        <span>In Stock</span>
                        <ArrowButtons arrowAttribute = "inStock" handler = {this.props.handler}/>
                    </div>
                </th>
            </tr>
            </thead>
        )
    }
}