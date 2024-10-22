import React from 'react';
import CommentList from './CommentList'

class Comments extends React.Component {
	constructor() {
		super()

		this.state = {
			postList:[],
			post: {
				id: 0,
				name: 'Шутро',
				image: '',
				email: 'shutro@gmail.com',
				text: 'я учусь в БГТУ',
				secretWord: '12345',
				date: null,
				changed: false
			}
		}
	}

	
	render() {
		const nameChage = (e) => {
			this.setState((state) => { return { post: Object.assign(state.post, { name: e.target.value }) } })
		}
		const avatarChage = (e) => {
			this.setState((state) => { return { post: Object.assign(state.post, { image: e.target.value }) } })
		}
		const emailChage = (e) => {
			this.setState((state) => { return { post: Object.assign(state.post, { email: e.target.value }) } })
		}
		const textChage = (e) => {
			this.setState((state) => { return { post: Object.assign(state.post, { text: e.target.value }) } })
		}
		const secretWordChage = (e) => {
			this.setState((state) => { return { post: Object.assign(state.post, { secretWord: e.target.value }) } })
		}

		const addPost = (e) => {
			e.preventDefault()

			let id = this.state.post.id
			let name = this.state.post.name
			let image = this.state.post.image
			let email = this.state.post.email
			let text = this.state.post.text
			let secretWord = this.state.post.secretWord
			let date = new Date().toLocaleString()
			let changed = this.state.post.changed

			const newPost = {
				id,
				name,
				image,
				email,
				text,
				secretWord,
				date,
				changed
			}

			if (this.state.post.name !== '' &&
					this.state.post.image !== '' && 
					this.state.post.email !== '' && 
					this.state.post.text !== '' && 
					this.state.post.secretWord !== '')
				this.setState({
					postList: [...this.state.postList, newPost],
					post: {
						id: (this.state.post.id + 1),
						name: '',
						image: '',
						email: '',
						text: '',
						secretWord: '',
						changed: false
					}
				})
		}

		const editPost = (post) => {
			let pos = -1
			this.state.postList.map((p) => {
				if (p.id === post.id) {
					return pos = p.id
				}
				else {
					return null
				}
			})
			if (pos !== -1) {

				this.setState({
					postList: [...this.state.postList.slice(0, pos), post, ...this.state.postList.slice(pos + 1)],
				})
			}
		}

		const deletePost = (post) => {
			this.setState({
				postList: this.state.postList.filter(p => p.id !== post.id)
			})
		}

    return (
			<>
				<form action="">
					<label htmlFor="">Имя пользователя</label>
					<input type="text" value={this.state.post.name} onChange={e => nameChage(e)}/>
					<label htmlFor="">Аватар пользователя</label>
					<div className='avatar_container'>
						<div className={this.state.post.image !== '' ? 'miniImage' : ''} style={{ backgroundImage: `url(${this.state.post.image})` }}></div>
						<select className={this.state.post.image === '' ? 'full-width' : 'image-width'} onChange={e => avatarChage(e)} value={this.state.post.image}>
							<option value="">Выберите аватар</option>
							<option value="https://avatars.mds.yandex.net/i?id=625a3a9169fe86503a5244a4f6fffbb8c07876f3-7762130-images-thumbs&n=13">Аватар пользователя 1</option>
							<option value="https://i.gifer.com/ZMqr.gif">Аватар пользователя 2</option>
							<option value="https://avatars.mds.yandex.net/i?id=faf51b6a1a9f2be8977410b64aebe638c4820496-9198383-images-thumbs&n=13">Аватар пользователя 3</option>
							<option value="https://avatars.mds.yandex.net/i?id=990f60a87ccd73811776eca897b829c8be685207-7545493-images-thumbs&n=13">Аватар пользователя 4</option>
							<option value="https://avatars.mds.yandex.net/i?id=f5e859e133c2776b75f2f7a9e6fdef039f369262-9220933-images-thumbs&n=13">Аватар пользователя 5</option>
						</select>
					</div>
					<label htmlFor="">Электронная почта</label>
					<input type="email" value={this.state.post.email} onChange={e => emailChage(e)}/>
					<label htmlFor="">Комментарий</label>
					<textarea value={this.state.post.text} onChange={e => textChage(e)}/>
					<label htmlFor="">Cекретное слово для удаления</label>
					<input type="password" value={this.state.post.secretWord} onChange={e => secretWordChage(e)} /> <br />
					<button onClick={e => addPost(e)}>Оставить комментарий</button>
				</form>

				<div className='separator05'/>

				<CommentList
					postList={this.state.postList}
					editPost={editPost}
					deletePost={deletePost} />
			</>
    );
  }
}

export default Comments;