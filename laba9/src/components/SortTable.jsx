import React from 'react';
import { tableList } from '../sortTable.data'
import "../styles/table.css"

class SortTable extends React.Component {
    constructor(props){
        super(props);
        this.state = {
            sortMode: 'default',
            reverse: false
        }
    }
  render() {

    // фун-я для изменения текущего метода сортировки 
    const switchSortMode = (e) => {
        if (this.state.sortMode === e.target.dataset.value)
            this.setState((state) => { return {reverse: !state.reverse} })

        this.setState({
            sortMode: e.target.dataset.value
        })
    }
    
    // фун-я, возвращающая отсортированный массив товаров
    // сортировка по имени, цене и наличию
    const sortedList = () =>{
        let sortMode = this.state.sortMode
        let reverse = this.state.reverse
        let newList = [...tableList]

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
        
        return newList
    }
		
		const salePrice = (price, sale) => {
			return Number(price) - Number(price * (sale / 100))	 
		}
    
		return (
      <div> 
        {/* Кастомная таблица */}


        <div className='table'>
            <div className='th'> 
                <div className='td th id' data-value='default'>ID</div>
								<div className='td th name' data-value='name' onClick={(e) => switchSortMode(e)} >Name</div>
                <div className='td th image' data-value='image'>Image</div>
                <div className='td th price' data-value='price' onClick={(e) => switchSortMode(e)} >Price</div>
                <div className='td th description' data-value='description'>Description</div>
                <div className='td th new' data-value='new'>New</div>
                <div className='td th sale' data-value='sale' onClick={(e) => switchSortMode(e)} >Sale</div>
                <div className='td th stock' data-value='stock' onClick={(e) => switchSortMode(e)} >Stock</div>
            </div>
            
        { sortedList().map((product, id) => 
            <div className='tr' key={id}>
                <div className='td id'>{id + 1}</div>
                <div className='td name'>{product.name}</div>
                <div className='td image'><div style={{backgroundImage: `url(${product.image})`, width:'40px', height:'40px', backgroundSize: 'cover', backgroundPosition: 'center'}}></div></div>
                <div className='td price'>{salePrice(product.price, product.sale)}</div>
                <div className='td description'>{product.description}</div>
                <div className='td new'>{product.newProduct === false ? '-' : '+'}</div>
                <div className='td sale'>{product.sale !== '0' ? `${product.sale}%`: 'none'}</div>
                <div 
                    className='td stock' 
                    style={ Number(product.stock) === 0 ? {backgroundColor : 'darkorange', borderRadius: '5px'}
                         : product.stock > 0 && product.stock < 3 ? {backgroundColor:"lightgreen", borderRadius: '5px'}
                         : null }
                >
                    {product.stock}
                </div>
            </div>
        )}
        </div>


      </div>
    );
  }
}

export default SortTable;