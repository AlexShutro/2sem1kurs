import React from 'react';
import "../styles/note.css"
import CreateNote from './CreateNote';
import NotesList from './NotesList';

class Notes extends React.Component {
	constructor(props) {
		super(props)
		this.state = {
			note: {
				header: 'Заголовок',
				text: 'Какой-то текст, не самой маленькой длины'
			}
		}
	}

	render() {
		if(this.props.date !== null)
			var filteredNotes = this.props.notes.filter(note => note.date.valueOf() === this.props.date.valueOf())

		if (this.props.date)
			return (
				<div className='note_container'>
					<CreateNote
						setNotes={this.props.setNotes}
						notes={this.props.notes}
						deleteNote={this.props.deleteNote}
						date={this.props.date}
						filteredNotes={filteredNotes} />
					<NotesList
						notes={filteredNotes} />
					
				</div>
			);
		else return null
  }
}

export default Notes;