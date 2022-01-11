
template <class T> int binary_tree<T>::height() const {
  // Call recursive helper function on root
  return height(root_.get());
}

template <class T> int binary_tree<T>::height(const node *subRoot) const {
  // Base case
  if (!subRoot)
    return -1;

  // Recursive definition
  auto left = height(subRoot->left.get());
  auto right = height(subRoot->right.get());
  return std::max(left, right) + 1;
}

template <class T> void binary_tree<T>::printLeftToRight() const {
  // Call recursive helper function on the root
  printLeftToRight(root_.get());

  // Finish the line
  std::cout << std::endl;
}

template <class T>
void binary_tree<T>::printLeftToRight(const node *subRoot) const {
  // Base case - null node
  if (!subRoot)
    return;

  // Print left subtree
  printLeftToRight(subRoot->left.get());

  // Print this node
  std::cout << subRoot->elem << ' ';

  // Print right subtree
  printLeftToRight(subRoot->right.get());
}

template <class T> void binary_tree<T>::mirror() {
  mirror(root_.get());
  /// @todo your code here
}
template <class T> void binary_tree<T>::mirror(node *subroot) {
  if (!subroot)
    return;
  mirror(subroot->left.get());
  mirror(subroot->right.get());
  std::swap(subroot->left, subroot->right);
}
template <class T> bool binary_tree<T>::isOrdered() const {
  /// @todo your code here
  return isOrdered(root_.get());
}

template <class T> bool binary_tree<T>::isOrdered(node *subRoot) const {
  if (!subRoot) {
    return true;
  }
  if (subRoot->left && subRoot->left->elem > subRoot->elem) {
    return false;
  }
  if (subRoot->right && subRoot->right->elem < subRoot->elem) {
    return false;
  }
  if (!isOrdered(subRoot->left.get()) || !isOrdered(subRoot->right.get())) {
    return false;
  }
  return true;
}

template <class T> void binary_tree<T>::printPaths() const {
  std::vector<T> v;
  printPaths(root_.get(), v);
  /// @todo your code here
}
template <class T>
void binary_tree<T>::printPaths(node *subRoot, std::vector<T> v) const {
  if (!subRoot) {
    return;
  }
  v.push_back(subRoot->elem);

  printPaths(subRoot->left.get(), v);
  if (!subRoot->left && !subRoot->right) {
    std::cout << "Path:";
    for (auto &value : v) {
      std::cout << " " << value;
    }
    std::cout << std::endl;
  }
  printPaths(subRoot->right.get(), v);
  v.pop_back();
}

template <class T> uint64_t binary_tree<T>::sumDistances() const {
  /// @todo your code here
  uint64_t temp = 0;
  return sumDistances(root_.get(), temp);
}
template <class T>
uint64_t binary_tree<T>::sumDistances(node *subRoot, uint64_t temp) const {
  if (!subRoot) {
    return 0;
  }
  auto sum = temp + sumDistances(subRoot->left.get(), temp + 1) +
             sumDistances(subRoot->right.get(), temp + 1);
  return sum;
}
