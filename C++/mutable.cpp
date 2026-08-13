class Example {
public:
    Example(int v) : value(v) {}

    int getValue() const {
        ++accessCount;      // OK: mutable 成员可在 const 函数中修改
        return value;
    }

    int getAccessCount() const {
        return accessCount; // 可读取，但不能修改非 mutable 成员
    }

private:
    int value;              // 普通成员，const 函数中不可修改
    mutable int accessCount = 0; // 记录访问次数
};