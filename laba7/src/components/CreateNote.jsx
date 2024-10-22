import React from 'react';

class CreateNote extends React.Component {
	constructor(props) {
		super(props)
		this.state = {
			note:{
					header: 'Заголовок',
					text: 'Какой-то текст, не самой маленькой длины'
			}
		}
	}

	handleAdd = (e) =>{
		e.preventDefault()

		const header = this.state.note.header
		const date = this.props.date
		const text = this.state.note.text

		const newNote = {
				header: header,
				date: date,
				text: text
		}

		if(this.state.note.header !=='' &&
			 this.props.date !== null && 
			 this.state.note.text !==''){

			this.props.setNotes(newNote)

			this.setState({note: {
					header: '',
					text: ''
			}})    
		}
	}

	changeHeader = (e) => {
		this.setState((state) => { return { note: Object.assign(state.note, { header: e.target.value }) } })
	}
	changeText = (e) => {
		this.setState((state) => { return { note: Object.assign(state.note, { text: e.target.value }) } })
	}

	deleteNote = (notesList) => {
		if (notesList.length > 0) {
			return (
				<div className="buttons">
					<button className='delete_first' onClick={this.deleteFirst}>Удалить<br/> первую</button>
					<button className='delete_all' onClick={this.deleteAll}>Удалить<br/> все</button>
					<button className='delete_last' onClick={this.deleteLast}>Удалить<br/> последнюю</button>
				</div>
			)
		}
	}

	deleteAll = () => {
		this.props.deleteNote([...this.props.notes.splice(0,0)])
	}
	deleteFirst = () => {
		this.props.deleteNote([...this.props.notes.splice(1, this.props.notes.length)])
	}
	deleteLast = () => {
		this.props.deleteNote([...this.props.notes.splice(0, this.props.notes.length - 1)])
	}

	
	render() {
		const selectedNoteDate = this.props.date
    return (
			<>
					<form className='second_form'>
						<label htmlFor="">Выбранная дата: {selectedNoteDate.toLocaleDateString()}</label><br />

						<label htmlFor="header">Заголовок заметки</label> <br />
						<input type="text" id='header' value={this.state.note.header} onChange={this.changeHeader} required /> <br />

						<label htmlFor="text">Заметка</label> <br />
						<textarea rows='5' cols='35' id='text' value={this.state.note.text} onChange={this.changeText} required /> <br />

						<input type="submit" value='Добавить заметку' onClick={e => this.handleAdd(e)} />
					</form>
					{this.deleteNote(this.props.filteredNotes)}
			</>
    );
  }
}

export default CreateNote;