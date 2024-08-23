#!/usr/bin/node

const request = require('request');

// Fetches a character's name from the given URL.

function fetchCharacter(url) {
    return new Promise((resolve, reject) => {
        request(url, (error, response, body) => {
            if (error) {
                return reject(error);
            }
            resolve(JSON.parse(body).name);
        });
    });
}

// Retrieves and prints the names of all characters in a Star Wars movie.

async function getCharacterNames(movieId) {
    const movieUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

    request(movieUrl, async (error, response, body) => {
        if (error) {
            console.error(error);
            return;
        }

        const movieData = JSON.parse(body);
        const characterUrls = movieData.characters;

        for (const url of characterUrls) {
            try {
                const name = await fetchCharacter(url);
                console.log(name);
            } catch (err) {
                console.error(err);
            }
        }
    });
}

// Extract the movie ID from the command-line arguments
const movieId = process.argv[2];

// Check if a movie ID was provided
if (!movieId) {
    console.error('Please provide a movie ID as a command-line argument.');
    process.exit(1);
}

// Call the main function to get and print character names
getCharacterNames(movieId);
