import React from 'react';

class NotesList extends React.Component {
	render() {
    return (
			<>
				{
						this.props.notes.map((note, id) => {
							if (id < 8)
								return (
									<div className="note" key={id} >
										<h3> {note.header} </h3>
										<h6> {note.date.toLocaleDateString()} </h6>
										<p>{note.text}</p>
									</div>
								)
							else
								return (
									<div className="note much" key={id} >
										<h3> {note.header} </h3>
										<p>{note.text}</p>
									</div>
								)
						})
					}
			</>
    );
  }
}

export default NotesList;