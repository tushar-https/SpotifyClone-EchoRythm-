

async function getSongs() {
  let a = await fetch("http://127.0.0.1:5500/songs/")
  let response = await a.text();
  console.log(response)
  let div = document.createElement("div")
  div.innerHTML=response;
  // let tds = div.getElementsByTagName("td")
  // let songs=[]
  // for (let index = 0; index < tds.length; index++) {
  //   const element = tds[index];
  //   if (element.href.endsWith(".mp3")) {
  //       songs.push(element.href)
  //   }
  // }
  // return songs
}

async function main(){
    let songs=await getSongs()
    console.log(songs);
}
main()