import React from 'react';
import CommentsDel from './CommentsDel';
import CommentsEdit from './CommentsEdit';
import CommentsInfo from './CommentsInfo'

class CommentList extends React.Component {
	constructor() {
		super()
		this.state = {
			hover: false
		}
	}

	render() {
		const changeFlag = () => {
			this.setState((state) => {
				return {
					hover: !state.hover
				}
			})
		}

		if (this.props.postList.length === 0)
			return <div className='comments_container'><h1>Список комментариев пуст</h1></div>
		else
			return (
				<div className='comments_container'>
					<h1>Комментарии</h1>
					{
						this.props.postList.map((post) => {
							return (
								<>
									<div className="separator02" />
									<div className='onePost' key={post.id}>
										<div className='commentHead'>
											<div className='miniImage' style={{ backgroundImage: `url(${post.image})` }}></div>
											<h3 onMouseEnter={changeFlag} onMouseLeave={changeFlag}>{post.name} <span>&#9660;</span></h3>
										</div>
										<span>{post.text}</span>
										<span className='edited'>{post.changed !== false ? ' (изменено)' : null}</span>
										<CommentsInfo post={post} flag={this.state.hover}></CommentsInfo>
										<div className='commentButtons'>
											<CommentsDel post={post} secret={post.secretWord} deletePost={this.props.deletePost}>Удалить комментарий</CommentsDel>
											<CommentsEdit post={post} editPost={this.props.editPost}>Изменить комментарий</CommentsEdit>
										</div>
									</div>
								</>
							)
						})
					}
				</div>
			)
  }
}

export default CommentList;