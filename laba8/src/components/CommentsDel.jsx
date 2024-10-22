import React from 'react';

class CommentsDel extends React.Component {
	constructor() {
		super()
		this.state = {
			deleteButtonFlag: false,
			text:''
		}
	}
	render() {
		const changeFlag = () => {
			this.setState((state) => {
					return {
						deleteButtonFlag: !state.deleteButtonFlag,
						text: ''
					}
				})
		}

		const deletePost = (e) => {
			e.preventDefault()

			if (this.state.text === this.props.post.secretWord) {
				this.props.deletePost(this.props.post)
				this.setState((state) => {
					return {
						deleteButtonFlag: !state.editButtonFlag,
						text: ''
					}
				})
			}
		}

		if(this.state.deleteButtonFlag === false)
			return (
				<>
					<button onClick={changeFlag}>{this.props.children}</button>
				</>
			)
		else
			return (
				<>
					<button onClick={changeFlag}>{this.props.children}</button>
					<form action="" className='delete_Menu'>
						<label htmlFor="">Введите секретное слово для удаления</label>
						<input type="text" value={this.state.text} onChange={e => this.setState({text: e.target.value})}/>
						<button onClick={deletePost}>Подтвердить</button>
					</form>
				</>
			)
  }
}

export default CommentsDel;