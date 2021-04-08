#!/usr/bin/node
const request = require('request');
const films = {
  url: 'https://swapi-api.hbtn.io/api/films/' + process.argv[2]
};

request(films, async function (err, res, body) {
  if (err) {
    console.log(err);
  }
  for (const character of JSON.parse(body).characters) {
    await new Promise((resolve, reject) => {
      request(character, function (err, res, body) {
        if (err) {
          reject(err);
        }
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
