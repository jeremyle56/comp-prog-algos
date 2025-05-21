const button = document.getElementById('darkModeToggle');
const body = document.body;
const header = document.getElementById('header');

// Create icon item
const icon = (item) => {
  const img = document.createElement('img');
  img.src = `assets/${item}.svg`;
  img.alt = '';
  img.classList.add('theme-icon');
  return img;
};

// Sets the icon
const setIcon = (mode) => {
  button.innerHTML = '';
  button.appendChild(icon(mode ? 'sun' : 'moon'));
};

// Check local storage for previous preference
const saved = localStorage.getItem('dark-mode') === 'true';
if (saved) {
  body.classList.add('dark-mode');
}
setIcon(saved);

// Click Handler
button.addEventListener('click', () => {
  const isDark = body.classList.toggle('dark-mode');
  localStorage.setItem('dark-mode', isDark);
  setIcon(isDark);
});
