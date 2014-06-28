var SerialPort = require("serialport").SerialPort
var request = require("request");
var nconf = require("nconf");

nconf.argv()
       .env()
       .file({ file: 'config.json' });

var serialPort = new SerialPort(nconf.get('SERIALPORT'), {
  baudrate: 9600
});

url = "http://worldcup.kimonolabs.com/api/matches/"+nconf.get('MATCHID')+"?apikey="+nconf.get('APIKEY');
//url = "http://localhost:8000/test";

/* Global variables, bad stuff! :P */
status = "";
homeScore = 0;
awayScore = 0;

var getScore = function() {

 request.get({url: url, json: true},
   function(err, response, body) {

   if (!err) {
     console.log(body);
     var instatus = body.status
       , inhomeScore = body.homeScore
       , inawayScore = body.awayScore
       ;
     if (status != instatus) {
       status = instatus;
       sendInfo("2");
     } else if (homeScore != inhomeScore) {
       homeScore = inhomeScore;
       sendInfo("0");
     } else if (awayScore != inawayScore) {
       awayScore = inawayScore;
       sendInfo("1");
     }
   }

   setTimeout(
    function(){
      getScore();
   }, 5 * 1000);

 });
}

var sendInfo = function(data) {
  serialPort.write(data+"\n", function(err, results) {
    console.log('err ' + err);
    console.log('results ' + results);
  });
}

getScore();
