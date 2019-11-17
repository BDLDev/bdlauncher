#pragma once

#include <deque>
#include <map>
#include <stack>
#include <string>
#include <vector>

namespace Json {

class StaticString {
public:
  explicit StaticString(const char *czstring)
      : c_str_(czstring) {}
  operator const char *() const { return c_str_; }
  const char *c_str() const { return c_str_; }

private:
  const char *c_str_;
};

struct ValueConstIterator;
struct ValueIterator;
enum ValueType {
  nullValue = 0, ///< 'null' value
  intValue,      ///< signed integer value
  uintValue,     ///< unsigned integer value
  realValue,     ///< double value
  stringValue,   ///< UTF-8 string value
  booleanValue,  ///< bool value
  arrayValue,    ///< array value (ordered list)
  objectValue    ///< object value (collection of name/value pairs).
};

using UInt        = unsigned;
using UInt64      = unsigned long long;
using Int         = int;
using Int64       = long long;
using LargestInt  = Int64;
using LargestUInt = UInt64;
using ArrayIndex  = unsigned;

enum CommentPlacement {
  commentBefore = 0,      ///< a comment placed on the line before a value
  commentAfterOnSameLine, ///< a comment just after a value on the same line
  commentAfter,           ///< a comment on the line after a value (only make sense for
  /// root value)
  numberOfCommentPlacement
};

class Value {
  friend class ValueIteratorBase;

public:
  class CZString {
  public:
    enum DuplicationPolicy { noDuplication = 0, duplicate, duplicateOnCopy };
    CZString(ArrayIndex index);
    CZString(char const *str, unsigned length, DuplicationPolicy allocate);
    CZString(CZString const &other);
    ~CZString();
    CZString &operator=(const CZString &other);
    bool operator<(CZString const &other) const;
    bool operator==(CZString const &other) const;
    ArrayIndex index() const;
    const char *c_str() const;
    bool isStaticString() const;

  private:
    void swap(CZString &other);
    struct StringStorage {
      unsigned policy_ : 2;
      unsigned length_ : 30; // 1GB max
    };
    char const *cstr_;
    union {
      ArrayIndex index_;
      StringStorage storage_;
    };
  };

  using iterator       = ValueIterator;
  using const_iterator = ValueConstIterator;
  using ObjectValues   = std::map<CZString, Value>;

public:
  Value(ValueType type = nullValue);
  Value(Int value);
  Value(UInt value);
  Value(Int64 value);
  Value(UInt64 value);
  Value(double value);
  Value(const char *value);                  ///< Copy til first 0. (NULL causes to seg-fault.)
  Value(const char *begin, const char *end); ///< Copy all, incl zeroes.
  Value(const StaticString &value);
  Value(const std::string &value);
  Value(bool value);
  Value(const Value &other);
  ~Value();

  static Value null;

  void swap(Value &other);
  ValueType type() const;

  Value &operator=(const Value &other);

  bool operator<(const Value &other) const;
  bool operator<=(const Value &other) const;
  bool operator>=(const Value &other) const;
  bool operator>(const Value &other) const;
  bool operator==(const Value &other) const;
  bool operator!=(const Value &other) const;
  int compare(const Value &other) const;

  const char *asCString() const;
  std::string asString(std::string const &) const;
  Int asInt(Int) const;
  UInt asUInt(UInt) const;
  Int64 asInt64(Int64) const;
  UInt64 asUInt64(UInt64) const;
  LargestInt asLargestInt(LargestInt) const;
  LargestUInt asLargestUInt(LargestUInt) const;
  float asFloat(float) const;
  double asDouble(double) const;
  bool asBool(bool) const;

  bool isNull() const;
  bool isBool() const;
  bool isInt() const;
  bool isInt64() const;
  bool isUInt() const;
  bool isUInt64() const;
  bool isIntegral() const;
  bool isDouble() const;
  bool isNumeric() const;
  bool isString() const;
  bool isArray() const;
  bool isObject() const;
  bool isConvertibleTo(ValueType other) const;

  ArrayIndex size() const;
  bool empty() const;
  void clear();
  void resize(ArrayIndex newSize);
  Value &operator[](ArrayIndex index);
  Value &operator[](int index);
  const Value &operator[](ArrayIndex index) const;
  const Value &operator[](int index) const;
  Value get(ArrayIndex index, const Value &defaultValue) const;
  bool isValidIndex(ArrayIndex index) const;
  Value &append(const Value &value);

  Value &operator[](const char *key);
  const Value &operator[](const char *key) const;
  Value &operator[](const std::string &key);
  const Value &operator[](const std::string &key) const;
  Value &operator[](const StaticString &key);
  Value get(const char *key, const Value &defaultValue) const;
  Value get(const std::string &key, const Value &defaultValue) const;
  void removeMember(const char *key);
  void removeMember(const std::string &key);
  bool isMember(const char *key) const;
  bool isMember(const std::string &key) const;

  const_iterator begin() const;
  const_iterator end() const;

  iterator begin();
  iterator end();

  Value &resolveReference(const char *key);

private:
  union ValueHolder {
    LargestInt int_;
    LargestUInt uint_;
    double real_;
    bool bool_;
    char *string_; // actually ptr to unsigned, followed by str, unless
                   // !allocated_
    ObjectValues *map_;
  } value_;
  ValueType type_ : 8;
};

class ValueIteratorBase {
public:
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef unsigned int size_t;
  typedef int difference_type;
  typedef ValueIteratorBase SelfType;

  bool operator==(const SelfType &other) const { return isEqual(other); }
  bool operator!=(const SelfType &other) const { return !isEqual(other); }
  difference_type operator-(const SelfType &other) const { return other.computeDistance(*this); }

  Value key() const;
  UInt index() const;
  char const *memberName() const;

protected:
  Value &deref() const;
  void increment();
  void decrement();
  difference_type computeDistance(const SelfType &other) const;
  bool isEqual(const SelfType &other) const;
  void copy(const SelfType &other);

private:
  Value::ObjectValues::iterator current_;
  bool isNull_;

public:
  ValueIteratorBase();
  explicit ValueIteratorBase(const Value::ObjectValues::iterator &current);
};
class ValueConstIterator : public ValueIteratorBase {
  friend class Value;

public:
  typedef const Value value_type;
  // typedef unsigned int size_t;
  // typedef int difference_type;
  typedef const Value &reference;
  typedef const Value *pointer;
  typedef ValueConstIterator SelfType;

  ValueConstIterator();
  ValueConstIterator(ValueIterator const &other);

private:
  explicit ValueConstIterator(const Value::ObjectValues::iterator &current);

public:
  SelfType &operator=(const ValueIteratorBase &other);
  SelfType operator++(int);
  SelfType operator--(int);
  SelfType &operator--();
  SelfType &operator++();

  reference operator*() const;
  pointer operator->() const;
};

class ValueIterator : public ValueIteratorBase {
  friend class Value;

public:
  typedef Value value_type;
  typedef unsigned int size_t;
  typedef int difference_type;
  typedef Value &reference;
  typedef Value *pointer;
  typedef ValueIterator SelfType;

  ValueIterator();
  explicit ValueIterator(const ValueConstIterator &other);
  ValueIterator(const ValueIterator &other);

private:
  explicit ValueIterator(const Value::ObjectValues::iterator &current);

public:
  SelfType &operator=(const ValueIteratorBase &other);
  SelfType operator++(int);
  SelfType operator--(int);
  SelfType &operator--();
  SelfType &operator++();
};

class Features {
public:
  static Features all();
  static Features strictMode();
  Features();
  bool strictRoot_;
  bool allowNumericKeys_;
};

class Reader {
public:
  typedef char Char;
  typedef const Char *Location;
  struct StructuredError {
    ptrdiff_t offset_start;
    ptrdiff_t offset_limit;
    std::string message;
  };
  Reader();
  Reader(const Features &features);

  bool parse(const std::string &document, Value &root, bool collectComments = true);
  bool parse(const char *beginDoc, const char *endDoc, Value &root, bool collectComments = true);
  bool parse(const char *beginDoc, unsigned long long length, Value &root, bool collectComments = true);
  bool parse(std::istream &is, Value &root, bool collectComments = true);

private:
  enum TokenType {
    tokenEndOfStream = 0,
    tokenObjectBegin,
    tokenObjectEnd,
    tokenArrayBegin,
    tokenArrayEnd,
    tokenString,
    tokenNumber,
    tokenTrue,
    tokenFalse,
    tokenNull,
    tokenArraySeparator,
    tokenMemberSeparator,
    tokenComment,
    tokenError
  };

  class Token {
  public:
    TokenType type_;
    Location start_;
    Location end_;
  };

  class ErrorInfo {
  public:
    Token token_;
    std::string message_;
    Location extra_;
  };
  typedef std::deque<ErrorInfo> Errors;

  bool readToken(Token &token);
  void skipSpaces();
  bool match(Location pattern, int patternLength);
  bool readComment();
  bool readCStyleComment();
  bool readCppStyleComment();
  bool readString();
  void readNumber();
  bool readValue();
  bool readObject(Token &token);
  bool readArray(Token &token);
  bool decodeNumber(Token &token);
  bool decodeNumber(Token &token, Value &decoded);
  bool decodeString(Token &token);
  bool decodeString(Token &token, std::string &decoded);
  bool decodeDouble(Token &token);
  bool decodeDouble(Token &token, Value &decoded);
  bool decodeUnicodeCodePoint(Token &token, Location &current, Location end, unsigned int &unicode);
  bool decodeUnicodeEscapeSequence(Token &token, Location &current, Location end, unsigned int &unicode);
  bool addError(const std::string &message, Token &token, Location extra = 0);
  bool recoverFromError(TokenType skipUntilToken);
  bool addErrorAndRecover(const std::string &message, Token &token, TokenType skipUntilToken);
  Value &currentValue();
  Char getNextChar();
  void getLocationLineAndColumn(Location location, int &line, int &column) const;
  void addComment(Location begin, Location end, CommentPlacement placement);
  void skipCommentTokens(Token &token);

  typedef std::stack<Value *> Nodes;
  Nodes nodes_;
  Errors errors_;
  std::string document_;
  Location begin_;
  Location end_;
  Location current_;
  Location lastValueEnd_;
  Value *lastValue_;
  std::string commentsBefore_;
  Features features_;
  bool collectComments_;
};

class Writer {
public:
  virtual ~Writer();
  virtual std::string write(const Value &root) = 0;
};

class FastWriter : public Writer {
public:
  FastWriter();
  ~FastWriter() override {}

  void enableYAMLCompatibility();
  void dropNullPlaceholders();
  void omitEndingLineFeed();

public:
  std::string write(const Value &root) override;

private:
  void writeValue(const Value &value);
  std::string document_;
  bool yamlCompatibilityEnabled_;
  bool dropNullPlaceholders_;
  bool omitEndingLineFeed_;
};

class StyledWriter : public Writer {
public:
  StyledWriter();
  ~StyledWriter() override {}

public:
  std::string write(const Value &root) override;

private:
  void writeValue(const Value &value);
  void writeArrayValue(const Value &value);
  bool isMultilineArray(const Value &value);
  void pushValue(const std::string &value);
  void writeIndent();
  void writeWithIndent(const std::string &value);
  void indent();
  void unindent();
  void writeCommentBeforeValue(const Value &root);
  void writeCommentAfterValueOnSameLine(const Value &root);
  static bool hasCommentForValue(const Value &value);
  static std::string normalizeEOL(const std::string &text);

  typedef std::vector<std::string> ChildValues;

  ChildValues childValues_;
  std::string document_;
  std::string indentString_;
  unsigned int rightMargin_;
  unsigned int indentSize_;
  bool addChildValues_;
};

class StyledStreamWriter {
public:
  StyledStreamWriter(const std::string &indentation = "\t");
  ~StyledStreamWriter() {}

public:
  void write(std::ostream &out, const Value &root);

private:
  void writeValue(const Value &value);
  void writeArrayValue(const Value &value);
  bool isMultilineArray(const Value &value);
  void pushValue(const std::string &value);
  void writeIndent();
  void writeWithIndent(const std::string &value);
  void indent();
  void unindent();
  void writeCommentBeforeValue(const Value &root);
  void writeCommentAfterValueOnSameLine(const Value &root);
  static bool hasCommentForValue(const Value &value);
  static std::string normalizeEOL(const std::string &text);

  typedef std::vector<std::string> ChildValues;

  ChildValues childValues_;
  std::ostream *document_;
  std::string indentString_;
  unsigned int rightMargin_;
  std::string indentation_;
  bool addChildValues_ : 1;
  bool indented_ : 1;
};

} // namespace Json