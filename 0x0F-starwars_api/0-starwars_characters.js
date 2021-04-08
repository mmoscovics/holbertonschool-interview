#!/usr/bin/node
const request = require('request');
const films = {
  url: 'https://swapi-api.hbtn.io/api/films/' + process.argv[2]
};

request(films, async function (err, res, body) {
  if (err) {
    console.log(err);
  }
  const json = JSON.parse(body);
  for (const character of json.characters) {
    await new Promise(function (resolve, reject) {
      request(character, function (err, res, body) {
        if (err) {
          reject(err);
        } else {
          console.log(JSON.parse(body).name);
          resolve();
        }
      });
    });
  }
});
