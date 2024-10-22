import React from 'react';

class CommentsEdit extends React.Component {
	constructor(props) {
		super(props)
		this.state = {
			editButtonFlag: false,
			text: props.post.text,
			name:	props.post.name
		}
	}

	render() {
		const changeFlag = () => {
			this.setState((state) => {
				return {
					editButtonFlag: !state.editButtonFlag,
					text: this.props.post.text
				}
			})
		}

		const editPost = (e) => {
			e.preventDefault()

			let editedPost = this.props.post
			editedPost.text = this.state.text
			editedPost.changed = true
			editedPost.date = new Date().toLocaleString()

			this.props.editPost(editedPost)

			this.setState((state) => {
				return {
					editButtonFlag: !state.editButtonFlag,
				}
			})
		}

		if(this.state.editButtonFlag === false)
		return (
			<>
				<button onClick={changeFlag}>{this.props.children}</button>
			</>
		)
	else
		return (
			<>
				<button onClick={changeFlag}>{this.props.children}</button>
				<form action="" className='edit_Menu'>
					<label htmlFor="">Введите новый текст</label>
					<textarea type="text" value={this.state.text} onChange={e => this.setState({text: e.target.value})}/>
					<button onClick={e => editPost(e)}>Подтвердить</button>
				</form>
			</>
		)
  }
}

export default CommentsEdit;