import React from 'react';
import Notes from "./Notes"
import CalendarHead from "./CalendarHead"
import CalendarBody from "./CalendarBody"

class Calendar extends React.Component {
	constructor() {
		super()

		this.state = {
			date: new Date(),
			selectedDays: [],
			noteDate: null,
			noteDates:[],
			notes: []
		}
	}

	selectDays = (day) => { 
		for (let i = 0; i < this.state.selectedDays.length; i++) { 
				if (day.valueOf() === this.state.selectedDays[i].valueOf()) {
					if (this.state.noteDate !== null && day.valueOf() === this.state.noteDate.valueOf()) { 
						this.setState({
							selectedDays: [...this.state.selectedDays.slice(0, i), ...this.state.selectedDays.slice(i + 1),],
							noteDate: null
						})
						return 
					} else { 
						this.setState({noteDate: day})
						return; 
					} 
				} 
		} 
		
		this.setState((state) => {return { selectedDays: [...state.selectedDays, day] } })
	} 

	setCurrentDate = (setDate) => {
		this.setState({ date: setDate })
	}

	setNotes = (newNote) => {
		this.setState({
			notes: [...this.state.notes, newNote]
		})
	}
	

	render() {

		const deleteNote = (newNotes) => {
			if (this.state.notes.length < 2)
				this.setState({
					noteDate: null
				})
			this.setState({
				notes: newNotes
			})
			
		}
    return (
			<>
				<table className="item">
					<CalendarHead setDate={this.setCurrentDate} />
					<CalendarBody
						date={this.state.date}
						setSelectedDays={this.selectDays}
						selectedDays={this.state.selectedDays}
						noteDate={this.state.noteDate} />
				</table>
				<div>
					<Notes
						noteDate={this.state.noteDate}
						date={this.state.noteDate}
						notes={this.state.notes}
						setNotes={this.setNotes}
						deleteNote={deleteNote} />
				</div>
			</>
    );
  }
}

export default Calendar;