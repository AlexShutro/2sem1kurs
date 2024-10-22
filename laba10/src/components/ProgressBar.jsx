import React from 'react';
import "../styles/progressBar.css";
import PropTypes from 'prop-types';


class ProgressBar extends React.Component {
  render() {
    return (
      <div className='progressBar'>
        <div className={(this.props.trust === 0 ? 'bar-0' :
          this.props.trust === 1 ? 'bar-20' :
            this.props.trust === 2 ? 'bar-40' :
              this.props.trust === 3 ? 'bar-60' :
                this.props.trust === 4 ? 'bar-80' :
                  this.props.trust === 5 ? 'bar-100' :
                    this.props.trust === 6 ? 'bar-120' : '')}>
        </div>
      </div>
    );
  }
}


 

export default ProgressBar;
