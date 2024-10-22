import React from 'react';
import Search from './Search';

class Catalog extends React.Component {
	constructor(props) {
		super(props)
		this.state = {
			sortMode: 'name',
			reverse: false,
			searchList: props.productList.sort(product => product.new === true),
		}
	}

	render() {
		const salePrice = (price, sale) => {
			return Number(price) - Number(price * (sale / 100))	 
		}

		const changeSortMode = (e) => {
			if (this.state.sortMode === e.target.dataset.value)
				this.setState({ reverse: !this.state.reverse })
			
			this.setState({sortMode: e.target.dataset.value})
		}

		const sortCatalog = () => {
			let sortMode = this.state.sortMode
			let reverse = this.state.reverse
			let newList = [...this.props.productList]

			if (reverse === false) {
				if (sortMode === 'name') {
					newList = newList.sort((a, b) => a.name - b.name)
				}
				else if (sortMode === 'price') {
					newList = newList.sort((a, b) => a.price - b.price)
				}
				else if (sortMode === 'stock') {
					newList = newList.sort((a, b) => a.stock - b.stock)
				}
				else if (sortMode === 'sale') {
					newList = newList.sort((a, b) => a.sale - b.sale)
				}
			}
			else {
				if (sortMode === 'name') {
					newList = newList.sort((a, b) => a.name - b.name).reverse()
				}
				else if (sortMode === 'price') {
					newList = newList.sort((a, b) => a.price - b.price).reverse()
				}
				else if (sortMode === 'stock') {
					newList = newList.sort((a, b) => a.stock - b.stock).reverse()
				}
				else if (sortMode === 'sale') {
					newList = newList.sort((a, b) => a.sale - b.sale).reverse()
				}
			}
        
			let newProductList = newList.filter((product) => product.newProduct === true)
			let notNewProductList = newList.filter((product) => product.newProduct !== true)

			newList = [...newProductList, ...notNewProductList]

			return newList
		}

		const getSearchList = (searchList) => {
			this.setState({
				searchList: searchList
			})
		}

		const finalList = () => {
			if (this.state.searchList === this.props.productList)
				return sortCatalog()
			else 
				return this.state.searchList
		}

    return (
			<div className='catalog'>
				<h1 className='poisk'>Поиск:</h1>
				<Search productList={sortCatalog()} getSearchList={getSearchList} />

				<div className="Catalog_buttons">
				<button onClick={changeSortMode} data-value='name'>Sort by name </button>
				<button onClick={changeSortMode} data-value='price'>Sort by price </button>
				<button onClick={changeSortMode} data-value='sale'>Sort by discount </button>
				<button onClick={changeSortMode} data-value='stock'>Sort by availability </button>
				</div>
				{
					finalList().map((product, id) => {
					return (
						<div className='oneProduct' key={id}>
							<div className={'product_container'}>
								<div className={"info"  + (product.newProduct === true ? ' new' : '') + (product.sale > 0 ? ' sale' : '')}>
									<div className='newInfo'>New</div>
									<div className='saleInfo'>{product.sale}%</div>
								</div>
								<div className='image' style={{ backgroundImage: `url(${product.image})`, width: '350px', height: '350px', backgroundSize: 'cover', backgroundPosition: 'center' }} ></div>
								<div className='product_information'>
									<h2>{product.name}</h2>
									<h3>{salePrice(product.price, product.sale)}р <span>{product.sale > 0 ? product.price+'р' : ''}</span></h3>
									<h4>В наличии {product.stock} шт. </h4>
									<p className='description'>{product.description}</p>
								</div>
							</div>
							<div className="separator02"/>
						</div>
					)
				})}
			</div>
    );
  }
}

export default Catalog;