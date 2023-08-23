// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++, C#, and Java:
// https://pvs-studio.com

#include "fstream"
#include "iostream"
#include "string"
#include "vector"

#include "time.h"
#include <memory>

class FileProcessor {
public:
  virtual void processFile(std::string filePath) noexcept(false) {
    throw "Not implemented";
  }
};

class IdentityFileProcessor : public FileProcessor {
public:
  // Performs identity transformation and cannot throw
  virtual void encodeFile(std::string fileContent) noexcept {}
};

class FileEncoder : public FileProcessor {
public:
  virtual void processFile(std::string filePath) override {
    std::ifstream in{filePath};
    std::string fileContent;
    in >> fileContent;

    encodeFile(fileContent);
  }

  static void encodeFile(const std::string &fileContent) noexcept(false) {
    std::cout << "encoding file with content: " << fileContent;
  }
};

class FileCompressor : public FileProcessor {
public:
  FileCompressor(const std::string &p1, const std::string &p2)
      : param1(p1), param2(p2), compressionParams(param1 + param2) {}

  FileCompressor(FileCompressor &&fc)
      : param1(std::move(fc.param1)), param2(std::move(fc.param2)),
        compressionParams(std::move(fc.compressionParams)) {}

  FileCompressor &operator=(FileCompressor &&fc) {
    if (this == &fc) {
      return *this; // Self-assignment, nothing to do
    }

    param1 = std::move(fc.param1);
    param2 = std::move(fc.param2);
    compressionParams = std::move(fc.compressionParams);

    return *this;
  }

  virtual void processFile(std::string filePath) noexcept(false) override {
    std::ifstream in{filePath};
    std::string fileContent;
    in >> fileContent;

    compressFile(fileContent);
  }

  void compressFile(const std::string &fileContent) const noexcept(false) {
    std::cout << "compressing file with content: " << fileContent
              << " using params " << compressionParams;
  }

private:
  std::string param1;
  std::string param2;
  std::string compressionParams;
};

class FileEncryptor : public FileProcessor {
public:
  FileEncryptor(FileEncryptor &&other) noexcept
      : encryptionKey(std::move(other.encryptionKey)) {
    srand(time(NULL));
    encryptionKey = std::make_unique<char[]>(16);
    for (int i = 0; i < 16; i++) {
      // Generate printable key
      encryptionKey[i] = rand() % 64 + 0x20;
    }
  }

  // Copy constructor
  FileEncryptor(const FileEncryptor &other) { copyFrom(other); }

  // Assignment operator
  FileEncryptor &operator=(FileEncryptor &&other) noexcept {
    if (this != &other) {
      encryptionKey = std::move(other.encryptionKey);
      // clearKey(); TODO, я пока понятия не имею что с этим делать и надо ли
      // вообще )))
    }
    return *this;
  }

  ~FileEncryptor() { clearKey(); }

  virtual void processFile(std::string filePath) noexcept(false) override {
    std::ifstream in{filePath};
    std::string fileContent;
    in >> fileContent;

    encryptFile(fileContent);
  }

  void clearKey() {
    std::cout << "Clearing encryption key";
    if (!encryptionKey)
      throw "No encryption key";

    encryptionKey.reset(); // This will automatically release the memory
  }

  void encryptFile(const std::string &fileContent) const noexcept(false) {

    std::cout << "encrypting file with content: " << fileContent
              << " using key " << encryptionKey.get();
  }

private:
  void copyFrom(const FileEncryptor &other) {
    encryptionKey = std::make_unique<char[]>(16);
    std::copy(other.encryptionKey.get(), other.encryptionKey.get() + 16,
              encryptionKey.get());
  }
  std::unique_ptr<char[]> encryptionKey;
};

static_assert(std::is_nothrow_move_constructible<FileEncryptor>::value,
              "FileEncryptor should be noexcept MoveConstructible");

class FileProcessorFactorySingleton {
public:
  static FileProcessorFactorySingleton &getInstance() {
    if (instance == nullptr) {
      instance = new FileProcessorFactorySingleton();
    }

    return *instance;
  }

  static FileProcessor *createFileProcessor(const std::string &mode) {
    if (mode == "encode") {
      return new FileEncoder();
    }
    if (mode == "identity") {
      return new IdentityFileProcessor();
    }
    if (mode == "compress") {
      return new FileCompressor("Hello", "World");
    }
    if (mode == "encrypt") {
      return new FileEncryptor();
    }

    return nullptr;
  }

private:
  FileProcessorFactorySingleton() = default;
  static FileProcessorFactorySingleton *instance;
};

FileProcessorFactorySingleton *FileProcessorFactorySingleton::instance =
    nullptr;

int main(int argc, char *argv[])

{
  const std::string mode = argv[1];
  FileProcessor *fp =
      FileProcessorFactorySingleton::getInstance().createFileProcessor(mode);
  try {
    std::vector<std::string> filesToProcess;
    for (int i = 2; i < argc; ++i) {
      filesToProcess.push_back(argv[i]);
    }

    for (auto file : filesToProcess) {
      fp->processFile(file);
    }

    if (fp) {
      delete fp;
    }

    return 1;

  } catch (...) {
    if (fp) {
      delete fp;
    }
    std::cout << "Sometihing wrong";
    return 0;
  }
}
