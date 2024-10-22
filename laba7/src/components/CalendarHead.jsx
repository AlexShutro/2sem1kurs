import React from 'react';

class Calendar extends React.Component {
	constructor(props) {
		super(props)
		this.state = {
			date: new Date()
		}

		this.setDate = props.setDate
	}

	static getDerivedStateFromProps(props) {
		return {
			selectedDays: props.selectedDays,
			noteDate: props.noteDate
		};
	}

	monthNames = [ "Январь", "Февраль", "Mарт", "Aпрель", "Mай", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" ]
	dayNames = ["пн", "вт", "ср", "чт", "пт", "сб", "вс"]

	prevMonth = () => { 
		let currentDate = new Date( this.state.date.getFullYear(), this.state.date.getMonth() - 1 ); 
		this.setDate(currentDate)
		this.setState({ date: currentDate })
	}

	nextMonth = () => { 
		let currentDate = new Date( this.state.date.getFullYear(), this.state.date.getMonth() + 1 ); 
		this.setDate(currentDate)
		this.setState({ date: currentDate })
	}

	render() {
    return (
			<>
				<thead>
					<tr>
						<td colSpan={5}>
							{this.monthNames[this.state.date.getMonth()] + " "} {this.state.date.getFullYear()}
						</td>
						<td>
							<button onClick={this.prevMonth}>
								{"<"}
							</button>
						</td>
						<td>
							<button onClick={this.nextMonth}>
								{">"}
							</button>
						</td>
					</tr>

					<tr>
						{this.dayNames.map((name) => (
							<td key={name}>
								{name}
							</td>
						))}
					</tr>
				</thead> 
			</>
    );
  }
}

export default Calendar;