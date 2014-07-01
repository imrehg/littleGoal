# littleGoal: World Cup match notifier with littleBits

Get notified of game results as they happen with a littleBits setup connected
to the Internet.

Full writeup is posted on Instructables: [littleGoal World Cup Match Notifier][instructables].

[instructables]: http://www.instructables.com/id/littleGoal-World-Cup-Match-Notifier/ "LittleGoal: World Cup Match Notifier"

## Ingredients

Parts needed:

* a few littleBits modules:
 * 1 x Arduino module
 * 2 x servo module
 * 1 x lights module
 * 1 x power + wall plug
 * optional: buzzer module, wire modules, fork module for connection
* Computer connected to the network
* mechanical setup for the flags

## Usage

The detailed setup is in the Instructables link above. Short version:

* Flash the Arduino code to the Arduino at Heart module
* Connect the servos to the team0/team1 pins (home/away)
* Connect the lights module to the sign pin
* Install node modules for the littleGoal server, copy `config.json.example` to `config.json`
* Get a Kimonolabs API key, find your match ID on the [Unofficial World Cup API][wcapi], add these to the `config.json`
* Run the server with `npm start`

[wcapi]: https://www.kimonolabs.com/worldcup/explorer "The (un)official World Cup API"

## License

The MIT License (MIT)

Copyright (c) 2014 Gergely Imreh  <imrehg@gmail.com> and Taipei Hackerspace

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
