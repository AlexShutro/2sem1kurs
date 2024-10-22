import React from 'react';

class CalendarBody extends React.Component {
	constructor(props) {
		super(props);
		this.state = {
			selectedDays: [],
			noteDate: null
		}

		this.setSelectedDays = props.setSelectedDays
		this.currentDate = new Date()
	}

	static getDerivedStateFromProps(props) {
		return {
			date: props.date,
			selectedDays: props.selectedDays,
			noteDate: props.noteDate
		};
	}

	startDay = (date) => {
		let startDay;
		date.getDay() === 0 ? (startDay = 6) : (startDay = date.getDay() - 1);
			return startDay;
	} 

	oneMonth = (date) => {
		let fullMonth = []
		let day = 1 - this.startDay(date)
		let month = date.getMonth()
		let year = date.getFullYear();

		for (let i = 0; i < 6; i++) {
			fullMonth[i] = [];
			for (let j = 0; j < 7; j++) {
				fullMonth[i][j] = new Date(year, month, day++);
			}
		}
		return fullMonth;
	} 

	selectDays = (weekDate) => { 
		this.setSelectedDays(weekDate); 
	}

	render() {
		const newDate = new Date(this.state.date.getFullYear(), this.state.date.getMonth(), 1); 
		const styleTd = (weekDate) => {
			if (newDate.getMonth() !== weekDate.getMonth())
				return "NotCurrentMounthDate"
			if (this.state.noteDate !== null && this.state.noteDate.getDate() === weekDate.getDate() && this.state.noteDate.getMonth() === weekDate.getMonth() && this.state.noteDate.getFullYear() === weekDate.getFullYear())
				return "selectedNoteDay"
			for (let i = 0; i < this.state.selectedDays.length; i++) { 
				if (this.state.selectedDays[i].getDate() === weekDate.getDate() && this.state.selectedDays[i].getMonth() === weekDate.getMonth() && this.state.selectedDays[i].getFullYear() === weekDate.getFullYear())
					return "selectedDate"	
				} 
			if (weekDate.getDate() === this.currentDate.getDate() && weekDate.getMonth() === this.currentDate.getMonth() && weekDate.getFullYear() === this.currentDate.getFullYear())
				return "todayDate"
		}

		return (
			<>
				<tbody>
					{this.oneMonth(newDate).map((week, index1) => (
						<tr key={index1}>
							{week.map((weekDate, index2) => (
								<td
									key={index2}
									onClick={(e) => {
										if (newDate.getMonth() === weekDate.getMonth())
										this.selectDays(weekDate)
									}} 
									className={styleTd(weekDate)}>
									{weekDate.getDate()}
								</td>
							))}
						</tr>
					))}
				</tbody>
			</>
		)
  }
}

export default CalendarBody;