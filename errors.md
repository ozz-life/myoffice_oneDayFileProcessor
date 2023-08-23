fileProcessor.cpp:42:51: error: Found an exit path from function with non-void return type that has missing return statement [missingReturn]
  FileCompressor &operator=(FileCompressor &&fc) {}

fileProcessor.cpp:127:5: error: Found an exit path from function with non-void return type that has missing return statement [missingReturn]
    }

fileProcessor.cpp:70:20: error: Array 'encryptionKey[16]' accessed at index 16, which is out of bounds. [arrayIndexOutOfBounds]
      encryptionKey[i] = rand() % 64 + 0x20;

fileProcessor.cpp:72:18: error: Array 'encryptionKey[16]' accessed at index 16, which is out of bounds. [arrayIndexOutOfBounds]
    encryptionKey[16] = 0;

fileProcessor.cpp:41:3: warning: inconclusive: Member variable 'FileCompressor::compressionParams' is not assigned in the move constructor. Should it be moved? [missingMemberCopy]
  FileCompressor(FileCompressor &&fc) {}
  ^
fileProcessor.cpp:41:3: warning: inconclusive: Member variable 'FileCompressor::param1' is not assigned in the move constructor. Should it be moved? [missingMemberCopy]
  FileCompressor(FileCompressor &&fc) {}
  ^
fileProcessor.cpp:41:3: warning: inconclusive: Member variable 'FileCompressor::param2' is not assigned in the move constructor. Should it be moved? [missingMemberCopy]
  FileCompressor(FileCompressor &&fc) {}
  ^

fileProcessor.cpp:45:19: warning: inconclusive: Member variable 'FileCompressor::compressionParams' is not assigned a value in 'FileCompressor::operator='. [operatorEqVarError]
  FileCompressor &operator=(FileCompressor &&fc) {
                  ^
fileProcessor.cpp:45:19: warning: inconclusive: Member variable 'FileCompressor::param1' is not assigned a value in 'FileCompressor::operator='. [operatorEqVarError]
  FileCompressor &operator=(FileCompressor &&fc) {
                  ^
fileProcessor.cpp:45:19: warning: inconclusive: Member variable 'FileCompressor::param2' is not assigned a value in 'FileCompressor::operator='. [operatorEqVarError]
  FileCompressor &operator=(FileCompressor &&fc) {
                  ^
fileProcessor.cpp:73:15: style: inconclusive: Member variable 'FileCompressor::compressionParams' is in the wrong place in the initializer list. [initializerList]
  std::string compressionParams;
              ^
fileProcessor.cpp:41:9: note: Member variable 'FileCompressor::compressionParams' is in the wrong place in the initializer list.
        compressionParams(param1 + param2) {}
        ^
fileProcessor.cpp:73:15: note: Member variable 'FileCompressor::compressionParams' is in the wrong place in the initializer list.
  std::string compressionParams;

fileProcessor.cpp:82:5: warning: Class 'FileEncryptor' does not have a copy constructor which is recommended since it has dynamic memory/resource allocation(s). [noCopyConstructor]
    encryptionKey = new char[16];
    ^
fileProcessor.cpp:82:5: warning: Class 'FileEncryptor' does not have a operator= which is recommended since it has dynamic memory/resource allocation(s). [noOperatorEq]
    encryptionKey = new char[16];
    ^

fileProcessor.cpp:31:8: performance: inconclusive: Technically the member function 'FileEncoder::encodeFile' can be static (but you may consider moving to unnamed namespace). [functionStatic]
  void encodeFile(std::string fileContent) noexcept(false) {
       ^

fileProcessor.cpp:67:8: style: inconclusive: Technically the member function 'FileCompressor::compressFile' can be const. [functionConst]
  void compressFile(std::string fileContent) noexcept(false) {

fileProcessor.cpp:119:8: style: inconclusive: Technically the member function 'FileEncryptor::encryptFile' can be const. [functionConst]
  void encryptFile(std::string fileContent) noexcept(false) {
       ^

fileProcessor.cpp:146:18: performance: inconclusive: Technically the member function 'FileProcessorFactorySingleton::createFileProcessor' can be static (but you may consider moving to unnamed namespace). [functionStatic]
  FileProcessor *createFileProcessor(std::string mode) {
                 ^

fileProcessor.cpp:111:16: style: Virtual function 'clearKey' is called from destructor '~FileEncryptor()' at line 101. Dynamic binding is not used. [virtualCallInConstructor]
  virtual void clearKey() {
               ^
fileProcessor.cpp:101:22: note: Calling clearKey
  ~FileEncryptor() { clearKey(); }
                     ^
fileProcessor.cpp:111:16: note: clearKey is a virtual function
  virtual void clearKey() {

fileProcessor.cpp:23:16: style: The function 'processFile' overrides a function in a base class but is not marked with a 'override' specifier. [missingOverride]
  virtual void processFile(std::string filePath) noexcept(false) {
               ^
fileProcessor.cpp:10:16: note: Virtual function in base class
  virtual void processFile(std::string filePath) noexcept(false) {
               ^
fileProcessor.cpp:23:16: note: Function in derived class
  virtual void processFile(std::string filePath) noexcept(false) {
               ^

fileProcessor.cpp:59:16: style: The function 'processFile' overrides a function in a base class but is not marked with a 'override' specifier. [missingOverride]
  virtual void processFile(std::string filePath) noexcept(false) {
               ^
fileProcessor.cpp:10:16: note: Virtual function in base class
  virtual void processFile(std::string filePath) noexcept(false) {
               ^
fileProcessor.cpp:59:16: note: Function in derived class
  virtual void processFile(std::string filePath) noexcept(false) {

fileProcessor.cpp:103:16: style: The function 'processFile' overrides a function in a base class but is not marked with a 'override' specifier. [missingOverride]
  virtual void processFile(std::string filePath) noexcept(false) {
               ^
fileProcessor.cpp:10:16: note: Virtual function in base class
  virtual void processFile(std::string filePath) noexcept(false) {
               ^
fileProcessor.cpp:103:16: note: Function in derived class
  virtual void processFile(std::string filePath) noexcept(false) {

fileProcessor.cpp:31:38: performance: Function parameter 'fileContent' should be passed by const reference. [passedByValue]
  static void encodeFile(std::string fileContent) noexcept(false) {
                                     ^
fileProcessor.cpp:38:30: performance: Function parameter 'p1' should be passed by const reference. [passedByValue]
  FileCompressor(std::string p1, std::string p2)
                             ^
fileProcessor.cpp:38:46: performance: Function parameter 'p2' should be passed by const reference. [passedByValue]
  FileCompressor(std::string p1, std::string p2)
                                             ^
fileProcessor.cpp:67:33: performance: Function parameter 'fileContent' should be passed by const reference. [passedByValue]
  void compressFile(std::string fileContent) const noexcept(false) {
                                ^
fileProcessor.cpp:120:32: performance: Function parameter 'fileContent' should be passed by const reference. [passedByValue]
  void encryptFile(std::string fileContent) const noexcept(false) {
                               ^
fileProcessor.cpp:147:57: performance: Function parameter 'mode' should be passed by const reference. [passedByValue]
  static FileProcessor *createFileProcessor(std::string mode) {

fileProcessor.cpp:31:39: style: Parameter 'fileContent' can be declared as reference to const [constParameter]
  static void encodeFile(std::string &fileContent) noexcept(false) {
                                      ^
fileProcessor.cpp:67:34: style: Parameter 'fileContent' can be declared as reference to const [constParameter]
  void compressFile(std::string &fileContent) const noexcept(false) {
                                 ^
fileProcessor.cpp:120:33: style: Parameter 'fileContent' can be declared as reference to const [constParameter]
  void encryptFile(std::string &fileContent) const noexcept(false) {
                                ^
fileProcessor.cpp:147:58: style: Parameter 'mode' can be declared as reference to const [constParameter]
  static FileProcessor *createFileProcessor(std::string &mode) {

fileProcessor.cpp:73:15: style: inconclusive: Member variable 'FileCompressor::compressionParams' is in the wrong place in the initializer list. [initializerList]
  std::string compressionParams;
              ^
fileProcessor.cpp:41:9: note: Member variable 'FileCompressor::compressionParams' is in the wrong place in the initializer list.
        compressionParams(param1 + param2) {}
        ^
fileProcessor.cpp:73:15: note: Member variable 'FileCompressor::compressionParams' is in the wrong place in the initializer list.
  std::string compressionParams;
              ^

----------

fileProcessor.cpp:26:68: error: expected identifier before ‘false’
   26 |   virtual void processFile(std::string filePath) noexcept override(false) {
      |                                                                    ^~~~~
fileProcessor.cpp:26:68: error: expected ‘,’ or ‘...’ before ‘false’
fileProcessor.cpp:26:11: error: ‘processFile’ declared as function returning a function
   26 |   virtual void processFile(std::string filePath) noexcept override(false) {
      |           ^~~~

fileProcessor.cpp:60:68: error: expected identifier before ‘false’
   60 |   virtual void processFile(std::string filePath) noexcept override(false) {
      |                                                                    ^~~~~
fileProcessor.cpp:60:68: error: expected ‘,’ or ‘...’ before ‘false’

fileProcessor.cpp: In constructor ‘FileCompressor::FileCompressor(FileCompressor&&)’:
fileProcessor.cpp:46:61: error: expected identifier before ‘{’ token
   46 |         compressionParams(std::move(fc.compressionParams)), {}
      |                      

fileProcessor.cpp:136:66: error: static assertion failed: FileCompressor should be noexcept MoveConstructible
  136 | static_assert(std::is_nothrow_move_constructible<FileEncryptor>::value,
      |               ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~
fileProcessor.cpp: In static member function ‘static FileProcessor* FileProcessorFactorySingleton::createFileProcessor(const std::string&)’:

fileProcessor.cpp: In member function ‘void FileEncryptor::clearKey()’:
fileProcessor.cpp:119:14: error: type ‘class std::unique_ptr<char []>’ argument given to ‘delete’, expected pointer
  119 |     delete[] encryptionKey;
      |              ^~~~~~~~~~~~~

fileProcessor.cpp: In static member function ‘static FileProcessor* FileProcessorFactorySingleton::createFileProcessor(const std::string&)’:
fileProcessor.cpp:159:33: error: cannot bind non-const lvalue reference of type ‘std::string&’ {aka ‘std::__cxx11::basic_string<char>&’} to an rvalue of type ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’}
  159 |       return new FileCompressor("Hello", "World");
      |                      

fileProcessor.cpp:163:32: error: no matching function for call to ‘FileEncryptor::FileEncryptor()’
  163 |       return new FileEncryptor();
      |                            