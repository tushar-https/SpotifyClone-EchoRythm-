const songs = [
  { songName: 'Baby Don\'t Hurt Me', artist: 'Artist 1', url: 'url_to_song_1.mp3' },
  { songName: 'Atmosphere', artist: 'Artist 2', url: 'url_to_song_2.mp3' },
  { songName: 'Alibi (feat. Rudimental)', artist: 'Artist 3', url: 'url_to_song_3.mp3' },
  { songName: 'Ameno (Techno Mix)', artist: 'Artist 4', url: 'url_to_song_4.mp3' },
  { songName: 'Baby again.', artist: 'Artist 5', url: 'url_to_song_5.mp3' }
]; // Your array of song objects

let audioElement = new Audio();
let currentSongIndex = -1;

function listSongs() {
  let songList = document.getElementById('songList');
  songList.innerHTML = '';
  songs.forEach((song, index) => {
      let listItem = document.createElement('li');
      listItem.innerHTML = `${song.songName} -  
          <lord-icon
              id="playPauseIcon${index}"
              src="https://cdn.lordicon.com/jctchmfs.json"
              trigger="hover"
              colors="primary:#d1e3fa"
              style="width:28px;height:28px;cursor:pointer;">
          </lord-icon>`;
      songList.appendChild(listItem);

      let icon = document.getElementById(`playPauseIcon${index}`);
      icon.addEventListener('click', () => playPauseSong(index));
  });
}

function playPauseSong(index) {
  if (index === currentSongIndex && !audioElement.paused) {
      // Pause the current song
      audioElement.pause();
      return;
  }

  if (currentSongIndex !== -1) {
      // Reset the previous icon if there was a song playing
      let previousIcon = document.getElementById(`playPauseIcon${currentSongIndex}`);
      previousIcon.setAttribute('src', 'https://cdn.lordicon.com/jctchmfs.json');
      previousIcon.setAttribute('trigger', 'hover');
  }

  currentSongIndex = index;
  let icon = document.getElementById(`playPauseIcon${index}`);
  if (audioElement.src !== songs[index].url) {
      // Change the icon to pause and play the new song
      icon.setAttribute('src', 'https://cdn.lordicon.com/wloilxuq.json');
      icon.setAttribute('trigger', 'hover');
      audioElement.src = songs[index].url;
      audioElement.play();
  } else {
      // Toggle between play and pause for the current song
      if (audioElement.paused) {
          icon.setAttribute('src', 'https://cdn.lordicon.com/wloilxuq.json');
          icon.setAttribute('trigger', 'hover');
          audioElement.play();
      } else {
          icon.setAttribute('src', 'https://cdn.lordicon.com/jctchmfs.json');
          icon.setAttribute('trigger', 'hover');
          audioElement.pause();
      }
  }
}

listSongs();
