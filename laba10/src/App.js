import { tableList } from './sortTable.data'
import "./styles/global.css"
import Catalog from "./components/Catalog"
import SignUpForm from "./components/SignUpForm"

function App() {
  return (
		<div className="App">
			<SignUpForm />
			<div className='separator05' />
			<Catalog productList={tableList} />
   </div>
  );
}

export default App;