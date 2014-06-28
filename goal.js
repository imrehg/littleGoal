var SerialPort = require("serialport").SerialPort
var request = require("request");
var nconf = require("nconf");

var serialPort = new SerialPort("/dev/ttyACM0", {
  baudrate: 9600
});

nconf.argv()
       .env()
       .file({ file: 'config.json' });


url = "http://worldcup.kimonolabs.com/api/matches/"+nconf.get('MATCHID')+"?apikey="+nconf.get('APIKEY');
request.get({url: url, json: true}, 
function(err, response, body) {
  console.log(body);
  console.log(body.status);
});

//#serialPort.on("open", function () {
//#  console.log('open');
//#  serialPort.write("1\n", function(err, results) {
//#    console.log('err ' + err);
//#    console.log('results ' + results);
//#  });
//#});

