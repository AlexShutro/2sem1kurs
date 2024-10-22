import React from 'react';

class Search extends React.Component {
	constructor(props) {
		super(props)

		this.state = {
			input: '',
			searchList: props.productList
		}
	}
	render() {
		console.log(this.props.productList)
		
		const handleChange = (e) => {
			this.setState({
				input: e.target.value,
			})

			this.props.getSearchList([...this.props.productList.filter(product => product.name.toLowerCase().includes(e.target.value.toLowerCase()))])
		}

    return (
        <>
					<div>
          	<input type="text" value={this.state.input} onChange={e => handleChange(e)}/>
					</div>
				</>
    );
  }
}

export default Search;
