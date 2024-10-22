import React, {useEffect, useState} from 'react';
import bel from '../../../UI/bel.png'
import rus from '../../../UI/rus.png'
import ucr from '../../../UI/ucr.png'
import lt from  '../../../UI/lt.png'
import lv from  '../../../UI/lv.png'
import pl from  '../../../UI/pl.png'

const SwitchFlag = ({id}) => {
    const [img, setImg] = useState(bel)

    useEffect(() => {
        switch (id){
            case 1:
                setImg(bel)
                break
            case 2:
                setImg(rus)
                break
            case 3:
                setImg(ucr)
                break
            case 4:
                setImg(pl)
                break
            case 5:
                setImg(lt)
                break
            case 6:
                setImg(lv)
                break;
            default:
                break;
        }
    }, [id])


    return (
        <img src={img} alt={'err'}/>
    );
};

export default SwitchFlag;