const loadThemes = async () => {
  try {
    const response = await fetch('themes.json');
    const themes = await response.json();

    // Set saved theme on load
    const savedTheme = localStorage.getItem('hljs-theme') || 'default';
    const themeLink = document.getElementById('hljs-theme');
    themeLink.href = `https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.11.1/styles/${savedTheme}.min.css`;

    // Create dropdown
    const dropdown = document.createElement('select');
    dropdown.className = 'form-select form-select-sm mx-3 w-auto bg-dark text-white border-white';
    dropdown.setAttribute('aria-label', 'Select Code Theme');

    // Create options
    themes.forEach((theme) => {
      const option = document.createElement('option');

      if (theme === savedTheme) {
        option.selected = 'selected';
      }

      option.value = theme;
      option.textContent = theme;
      dropdown.appendChild(option);
    });

    // Change theme on selection
    dropdown.addEventListener('change', function () {
      const selectedTheme = this.value;
      themeLink.href = `https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.11.1/styles/${selectedTheme}.min.css`;
      localStorage.setItem('hljs-theme', selectedTheme);
    });

    // Append to header flex container (aligned right)
    const headerFlex = document.querySelector('.header .d-flex');
    headerFlex.appendChild(dropdown);
  } catch (err) {
    console.error('Failed to load themes: ', err);
  }
};

loadThemes();
hljs.highlightAll();
