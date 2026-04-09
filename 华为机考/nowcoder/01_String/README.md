# 牛客网字符串题目

## 题目列表

| 题号 | 文件名 | 题目 | 算法/思路 |
|------|--------|------|-----------|
| HJ1 | `HJ1.py` | 最后一个单词长度 | split + 索引 |
| HJ2 | `HJ2.py` | 统计子串 | count |
| HJ3 | `HJ3.py` | 分组输出 | ljust + 8位分组 |
| HJ4 | `HJ4_count_ascii.py` | 统计ASCII字符 | ord + 过滤 |
| HJ5 | `HJ5.py` | 句子逆序 | s[::-1] |
| HJ6 | `HJ6_reverse_sentence.py` | 单词倒排 | split + 反转 + join |
| HJ7 | `HJ7_remove_least_freq_chars.py` | 删除出现最少字符 | Counter |
| HJ8 | `HJ8_count_chars.py` | 统计字符 | 分类计数 |
| HJ9 | `HJ9_first_k_chars.py` | 取前k个字符 | 切片 |
| HJ12 | `HJ12_longest_digit_substring.py` | 最长数字子串 | 正则/列表处理 |
| HJ13 | `HJ13_first_unique_char.py` | 第一个只出现一次的字符 | Counter |
| HJ14 | `HJ14_sort_strings.py` | 字符串排序 | sort |
| HJ15 | `HJ15.py` | 字符串变换 | 偏移 + 大小写互换 |
| HJ16 | `HJ16_palindrome.py` | 最长回文子串 | 中心扩展法 |

## 常用技巧

- **字符串反转**: `s[::-1]`
- **单词分割**: `s.split()`
- **字符统计**: `Counter(s)`
- **ASCII转换**: `ord()`, `chr()`
- **正则提取**: `re.findall(r'\d+', s)`
- **字符串填充**: `s.ljust(width, '0')`
