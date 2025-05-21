const code = {
  introduction: ['template', 'codeforces_template', 'binary_search', 'coordinate_compression'],
  data_structures: [
    'order_statistic_tree_(Set)',
    'order_statistic_tree_(Map)',
    'union_find',
    'sparse_table',
    'range_tree',
  ],
  dynamic_programming: ['knapsack', 'bitsets', 'travelling_sales_person'],
  graph_algorithms: [
    'breath_first_search',
    'depth_first_search',
    'bridge_finding',
    'directed_cycle_detection',
    'tree_representation',
    'binary_lifting',
    `kosaraju's_algorithm`,
    'topological_sort',
    'compute_SCC_DAG',
    `kruskal's_algorithm`,
    `prim's_algorithm`,
    `shortest_path_algorithms/dijkstra's_algorithm`,
    'shortest_path_algorithms/bellman_ford',
    'shortest_path_algorithms/finding_negative_cycles',
    'shortest_path_algorithms/floyd_warshall',
  ],
  flow_networks: [`dinic's_algorithm`, 'min-cut'],
  mathematics: [
    'fast_exponentiation',
    'primality_testing',
    'prime_factorization',
    'sieve_of_eratosthenes',
    'GCD',
    'extended_euclidean_algorithm',
    'matrices',
    'combinations',
  ],
  computational_geometry: [
    'cross_product',
    'three_points_collinear',
    'segment-segment_intersection',
    'polygon_area_(Trapezoidal Rule)',
    'polygon_area_(Cross Product)',
    'convex_hull',
    'half_plane_intersection',
  ],
  // miscellaneous: [],
};

/**
 * Converts strings to title case.
 *
 * @param {string} s
 * @returns
 */
const titleCase = (s) =>
  s
    .replace(/^[-_]*(.)/, (_, c) => c.toUpperCase())
    .replace(/[-_]+(.)/g, (_, c) => ' ' + c.toUpperCase());

// Where all the content will go
const contentDiv = document.getElementById('content');

// Handles logic for all content to above div
Object.entries(code).forEach(([category, files]) => {
  // Create div for category
  const categoryContainer = document.createElement('div');
  categoryContainer.id = `${category}-div`;

  // Create heading for category
  const categoryHeading = document.createElement('h3');
  categoryHeading.textContent = titleCase(category);
  categoryContainer.appendChild(categoryHeading);

  let subCategory = category.substring(0, category.indexOf('/'));
  let subCategoryContainer;

  // Iterate through all files of current category
  files.forEach((file, index) => {
    // If subcategory is new
    if (subCategory !== file.substring(0, file.indexOf('/'))) {
      subCategory = file.substring(0, file.indexOf('/'));

      subCategoryContainer = document.createElement('div');
      subCategoryContainer.id = `${subCategory}-div`;

      subCategoryHeading = document.createElement('h4');
      subCategoryHeading.textContent = titleCase(subCategory);
      subCategoryContainer.appendChild(subCategoryHeading);
    }

    // Create div for current file
    let fileContainer = document.createElement('div');
    fileContainer.id = `${file}-div`;

    // Create heading for current file
    const fileHeading = document.createElement(`${file.includes('/') ? 'h5' : 'h4'}`);
    fileHeading.textContent = titleCase(file.substring(file.lastIndexOf('/') + 1));
    fileContainer.appendChild(fileHeading);

    // Get file contains and place in pre code block
    fetch(`../code/${category}/${file}.cpp`)
      .then((res) => res.text())
      .then((contents) => {
        const pre = document.createElement('pre');
        pre.className = 'language-cpp';

        const codeElement = document.createElement('code');
        codeElement.textContent = contents;

        pre.appendChild(codeElement);
        fileContainer.appendChild(pre);

        document.querySelectorAll('pre code:not(.hljs)').forEach((block) => {
          hljs.highlightElement(block);
        });
      });

    // Handle adding code and header to correct div
    if (subCategory) {
      subCategoryContainer.appendChild(fileContainer);
      if (index === files.length - 1) {
        categoryContainer.appendChild(subCategoryContainer);
      }
    } else {
      categoryContainer.appendChild(fileContainer);
    }
  });

  contentDiv.appendChild(categoryContainer);
});
