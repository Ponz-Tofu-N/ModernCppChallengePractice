#include <functional>
#include <vector>

namespace alg
{
// ヒープ構造を使用する。
// 標準ライブラリのヒープ構造を操作する関数を採用する。
template <typename T,
          typename Compare = std::less<typename std::vector<T>::value_type>>
class priority_queue
{
private:
  std::vector<T> queue;
  // value_type
  // vector が維持する要素に関連付けられた型
  using value_type = typename std::vector<T>::value_type;
  // const_reference
  // 要素が変更されることを許可しない配下要素への参照
  using const_reference = typename std::vector<T>::const_reference;
  // size_type
  // 符号なし整数型、コンテナのサイズを示すために使用される
  using size_type = typename std::vector<T>::size_type;

public:
  priority_queue(const std::initializer_list<T>& init)
      : queue(init.begin(), init.end())
  {
    std::make_heap(queue.begin(), queue.end(), Compare());
  };
  ~priority_queue(){};

  void push(const_reference e)
  {
    queue.push_back(e);
    std::push_heap(queue.begin(), queue.end(), Compare());
  };
  void pop()
  {
    std::pop_heap(queue.begin(), queue.end(), Compare());
    queue.pop_back();
  };
  const_reference top() { return queue.front(); }
  size_type size() const { return queue.size(); }
  bool empty() const { return queue.empty(); }
};

template <class T>
class ring_buffer;

template <typename T>
class ring_buffer_iterator
{
  using self_type = ring_buffer<T>;
  using value_type = T;
  using pointer = T*;
  using reference = T&;
  using const_reference = const T&;

private:
  self_type* rb;
  size_t pos;
  size_t head;
  bool last;

public:
  ring_buffer_iterator(self_type* _v, size_t _pos, size_t _head,
                       bool _last = false)
      : rb(_v), pos(_pos), head(_head), last(_last){};
  ~ring_buffer_iterator(){};

  const_reference operator*() const
  {
    if (last)
      throw std::out_of_range("out of range");
    return rb->buf_.at(pos);
  };
  reference operator*()
  {
    if (last)
      throw std::out_of_range("out of range");
    return rb->buf_.at(pos);
  };

  ring_buffer_iterator& operator++()
  {
    if (last || (head + 1 == rb->capacity()))
      throw std::out_of_range("out of range");

    head++;
    pos = (pos + 1) % rb->capacity();
    return *this;
  };

  ring_buffer_iterator& operator--()
  {
    if (head - 1 < 0)
      throw std::out_of_range("out of range");

    head--;
    pos--;

    if (pos < 0)
      pos += rb->capacity();

    return *this;
  };

  // イテレータは循環しない
  ring_buffer_iterator operator+(const size_t n)
  {
    if (head + n >= rb->capacity())
      throw std::out_of_range("out of range");

    int index = (pos + n) % rb->capacity();

    head += n;

    return ring_buffer_iterator(this->rb, index, head, false);
  };

  ring_buffer_iterator operator-(const size_t n)
  {
    if (head - n < 0)
      throw std::out_of_range("out of range");

    int index = (pos - n);
    if (index < 0)
      index += rb->capacity();

    head += n;

    return ring_buffer_iterator(this->rb, index, head, false);
  };

  bool operator==(const ring_buffer_iterator& it) const
  {
    return pos == it.pos;
  };
  bool operator!=(const ring_buffer_iterator& it) const
  {
    return pos != it.pos;
  };
  bool operator>(const ring_buffer_iterator& it) const { return pos > it.pos; };
  bool operator<(const ring_buffer_iterator& it) const { return pos < it.pos; };
  bool operator>=(const ring_buffer_iterator& it) const
  {
    return pos >= it.pos;
  };
  bool operator<=(const ring_buffer_iterator& it) const
  {
    return pos <= it.pos;
  };
};

template <class T>
class ring_buffer
{
  /*リングバッファのイテレータ*/
  /*最初に追加された位置(古い値)がbegin、最後に追加された位置(最新の値)の次がend*/
  using iterator = ring_buffer_iterator<T>;

private:
  // データを格納するコンテナ
  std::vector<T> buf_;
  // 現在格納されている要素数
  size_t size_ = 0;
  // 最後に挿入した要素の位置
  size_t pos_ = -1;

  // 現在のインデックスから次の位置のインデックスを返す
  size_t next_pos() { return (pos_ + 1) % buf_.capacity(); }

  size_t first_pos()
  {
    int index = pos_ - size_ + 1;
    if (index < 0)
      index += buf_.capacity();

    return index;
  }

  size_t previous_pos()
  {
    // 最後の位置を1戻す
    // pos_が―1になった時は？
    // indexを最後のindexに変換する条件
    // index==-1のときかつsize_>0のとき
    int index = pos_ - 1;
    if (index == -1 && size_ > 0)
      return index + buf_.capacity();

    return index;
  }

public:
  ring_buffer(/* args */) = delete;
  ring_buffer(const size_t n) : buf_(n) {}

  ~ring_buffer(){};

  void push(const T& element)
  {
    // size_ != バッファ容量のときインクリメント
    if (size_ != buf_.capacity())
      size_++;
    // pos_ をインクリメント -> 関数化
    pos_ = next_pos();
    // 先頭に値を代入
    buf_[pos_] = element;
  };

  void pop()
  {
    // サイズを1減らす
    size_--;

    pos_ = previous_pos();
  }

  bool full() { return size_ == buf_.capacity(); };
  bool empty() { return size_ == 0; };
  size_t size() { return size_; };
  size_t capacity() { return buf_.capacity(); };

  T& operator[](const size_t& index)
  {
    // 要素数より大きなindexへのアクセスをはじく
    if (size_ < index)
      throw std::runtime_error("invalid access. out of range.");

    // indexの値を返す
    return buf_.at(index);
  };

  bool operator==(const ring_buffer<T>& other) const
  {
    return this->buf_ == other.buf_;
  }

  iterator begin() { return iterator(this, first_pos(), 0, empty()); }
  iterator end() { return iterator(this, next_pos(), size_, true); }

  friend class ring_buffer_iterator<T>;
};

}  // namespace alg
