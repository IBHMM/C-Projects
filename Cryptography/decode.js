const fs = require('fs');
const path = require('path');

const text = "We will fail the exam";
let seed = 353;
let coded = "";

fs.writeFile('./data/coded.txt', `Seed: ${seed} \n`, err => {
    !err && console.error(err);
})

for(let i = 0; i < text.length; i ++){
    const c = (text.charCodeAt(i) + seed)%255;
    seed = (32*seed + 10) % 1000000;
    coded += String.fromCodePoint(c);
}

function make_message(seed, text){
    let message = "";
    for(let i = 0; i < text.length; i ++){
        let c = (text.charCodeAt(i) - seed)%255;
        if(c < 0){
            c += 255;
        }
        message += String.fromCodePoint(c);
        seed = (32*seed + 10) % 1000000;
    }
    return message;
}

function control(message){
    let c_e_i_o_t = 0,  c_j_x_z= 0;
    for(let i = 0; i < message.length; i ++){
       if(  message[i] == 'e' || message[i] == 'E' ||
            message[i] == 'i' || message[i] == 'I' ||
            message[i] == 'o' || message[i] == 'O' ||
            message[i] == 't' || message[i] == 'T' )
        {
            c_e_i_o_t += 1;
        }
        if( message[i] == 'j' || message[i] == 'J' ||
            message[i] == 'x' || message[i] == 'X' ||
            message[i] == 'z' || message[i] == 'Z' )
            {
                c_j_x_z += 1;
            }
    }
    
    if(c_e_i_o_t >= c_j_x_z){
        return 'prefered';
    }else if(c_e_i_o_t < c_j_x_z){
        return 'not_prefered';
    }
}

fs.appendFile('./data/coded.txt', `Code: ${coded}`, err => {
    !err && console.error(err);
});

for(let i = 0; i < 10000; i++){ 
    let message = make_message(i, coded);
    const path = `./data/allmessages/${control(message)}/messages.txt`;

    fs.appendFileSync(path, `Seed: ${i}\n`, 'utf8' ,err => {
        !err && console.error(err);
    });

    fs.appendFileSync(path, `${message}\n`, 'utf8' ,err => {
        !err && console.error(err);
    });
}
