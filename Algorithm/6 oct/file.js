const fs = require('fs');
const path = require('path');

function searchInFile(filePath, searchStr) {
    try {
        const fileData = fs.readFileSync(filePath, 'utf8');
        const lines = fileData.split('\n');
        
        for (let lineNumber = 1; lineNumber <= lines.length; lineNumber++) {
            if (lines[lineNumber - 1].includes(searchStr)) {
                console.log(`Found at line ${lineNumber} in file ${filePath}`);
                break;
            }
        }
    } catch (error) {
        console.error(`Error: Unable to open file ${filePath}`);
    }
}

function searchInDirectory(directoryPath, searchString) {
    fs.readdirSync(directoryPath).forEach((entry) => {
        const entryPath = path.join(directoryPath, entry);
        if (fs.statSync(entryPath).isDirectory()) {
            searchInDirectory(entryPath, searchString);
        } else if (entryPath.endsWith('.txt')) {
            searchInFile(entryPath, searchString);
        }
    });
}

const searchDirectory = 'file'; // Replace with your directory path
const searchString = 'salam'; // Replace with your search string

searchInDirectory(searchDirectory, searchString);
