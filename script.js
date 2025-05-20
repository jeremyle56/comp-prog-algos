const code = {
  introduction: [],
  searching: [],
  data_structures: [],
  dynamic_programming: [],
  graph_algorithms: [],
  network_flow: [],
  mathematics: [],
  computational_geometry: [],
};

const contentDiv = document.getElementById('content');

fetch('code/introduction/template.cpp')
  .then((res) => res.text())
  .then((text) => console.log(text));

// data.forEach((item) => {
//   const heading = document.createElement('h5');
//   heading.textContent = item.heading;

//   const pre = document.createElement('pre');
//   const code = document.createElement('code');
//   code.textContent = item.code;

//   pre.appendChild(code);
//   contentDiv.appendChild(heading);
//   contentDiv.appendChild(pre);
// });
