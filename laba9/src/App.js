import { tableList } from './sortTable.data'
import "./styles/global.css"
import SortTable from "./components/SortTable"
import Catalog from "./components/Catalog"

function App() {
  return (
   <div className="App">
			<SortTable />
			<div className='separator05' />
			<Catalog productList={tableList} />
   </div>
  );
}

export default App;