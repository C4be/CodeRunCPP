# Компилятор и флаги
CXX := c++
CXXFLAGS := -std=c++20 -Wall -Wextra
LDFLAGS := 
GTEST_FLAGS := -lgtest -lgtest_main -pthread

# Пути к GTest (на macOS — через brew)
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    GTEST_INC := $(shell brew --prefix googletest)/include
    GTEST_LIB := $(shell brew --prefix googletest)/lib
    CXXFLAGS += -I$(GTEST_INC)
    LDFLAGS += -L$(GTEST_LIB)
else
    # Linux defaults (нужен установленный libgtest-dev)
    CXXFLAGS += -I/usr/include/gtest
endif

# Файлы проекта
APP_NAME := trip
SRC := $(APP_NAME).cpp main.cpp
INCLUDE := $(APP_NAME).hpp
TEST_SRC := test_$(APP_NAME).cpp $(APP_NAME).cpp

# Каталоги и цели
BUILD_DIR := build
TARGET := $(BUILD_DIR)/$(APP_NAME)
TEST_TARGET := $(BUILD_DIR)/test_$(APP_NAME)

# Создание каталога для сборки
$(shell mkdir -p $(BUILD_DIR))

# Цель по умолчанию
.PHONY: all
all: test

# Сборка основного приложения
$(TARGET): $(SRC) $(INCLUDE)
	@echo "Building main application..."
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -I. $(SRC) -o $@

# Сборка тестов
$(TEST_TARGET): $(TEST_SRC) $(INCLUDE)
	@echo "Building tests..."
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -I. $(TEST_SRC) -o $@ $(GTEST_FLAGS)

# Псевдонимы
.PHONY: build
build: $(TARGET)

.PHONY: test-build
test-build: $(TEST_TARGET)

.PHONY: test
test: test-build
	@echo "Running tests..."
	@$(TEST_TARGET)

.PHONY: clean
clean:
	@echo "Cleaning build artifacts..."
	@rm -rf $(BUILD_DIR)

.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all        - Build and run tests (default)"
	@echo "  build      - Build main application"
	@echo "  test       - Build and run tests"
	@echo "  test-build - Build tests only"
	@echo "  clean      - Remove build artifacts"
	@echo "  help       - Show this help message"
