import React from 'react';

class CommentsInfo extends React.Component {

	render() {
		if (this.props.flag === true)
			return (
				<div className='info_Menu'>
					Имя: {this.props.post.name}<br />
					Дата: ({this.props.post.date})<br />
					Почта: {this.props.post.email}<br />
					{this.props.post.changed !== false ? 'изменено' : null}
				</div>
			)
  }
}

export default CommentsInfo;