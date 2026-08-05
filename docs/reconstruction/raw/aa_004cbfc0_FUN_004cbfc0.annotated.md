# Annotated low-level: Vector_InsertN_0x10

| Field | Value |
|---|---|
| Stable ID | `aa_004cbfc0` |
| VA | `0x004cbfc0`–`0x004cc21c` |
| Ghidra | `FUN_004cbfc0` |
| Canonical | `Vector_InsertN_0x10` |
| System | MSVC STL vector insert (16-byte POD elements) |
| Date | 2026-07-29 (W25-M seal) |
| Tools | decompile + analyze_function_complete + read_memory; no disassemble_bytes |

---

## Machine-level notes

- SEH registration `LAB_009a1e20` + levels 0/2 around realloc/fill — standard MSVC vector insert.
- Element stride sealed by **`>> 4`** / **`* 0x10`** throughout; value snapshot is **4 dwords**.
- Max size **`0x0fffffff`** elements (= `0xffffffff / 0x10`); overflow calls `FUN_004cb1d0` with product string **`vector<T> too long`** → confirms STL vector.
- Geometric grow **`cap + (cap >> 1)`** (1.5×) with forced fit when still short.
- Decompiler warning that `operator_delete` "does not return" is **false**; pointer rewrites after delete are real.

## Vector layout

| Offset | Field |
|---|---|
| `+0x00` | (unused here / possible cookie or other) |
| `+0x04` | `T* begin` |
| `+0x08` | `T* end` |
| `+0x0c` | `T* capacity_end` |

`size = (end - begin) >> 4`, `capacity = (cap_end - begin) >> 4`.

## Annotated control flow

```
snapshot value → local 16-byte temp (4 dwords)
if count == 0: restore SEH; return

size = (end-begin)>>4
if size + count would overflow 0x0fffffff: throw vector<T> too long

if size + count > capacity:
  new_cap = cap + cap/2  (or 0 on overflow of that)
  if new_cap < size+count: new_cap = size+count
  buf = operator_new(new_cap * 0x10)
  // SEH level 0
  mid = uninitialized_copy(begin, insertAt, buf)           // FUN_005dd920
  uninitialized_fill_n(mid, count, value)                  // FUN_00608720
  uninitialized_copy(insertAt, end, mid + count*0x10)      // FUN_005dd920
  delete old begin
  begin = buf; end = buf + (size+count)*0x10; cap_end = buf + new_cap*0x10
  return

// capacity enough
if (end - insertAt)/0x10 < count:
  // insert range reaches/past old end: move tail forward, fill new hole + old tail zone
  ... FUN_005dd920 / FUN_0041d5a0 / FUN_004cb2e0 ...
else:
  // pure interior insert: shift tail by count, assign hole
  ... FUN_005dd920 / FUN_0051b6e0 / FUN_004cb2e0 ...
```

## Signature (sealed)

```c
void __thiscall Vector_InsertN_0x10(
    Vector16* this,
    void* insertAt,       // T*
    unsigned count,
    const void* value);   // const T* (16 bytes); ret 0xc
```

## Call sites (role)

Used as shared 16-byte vector grow/insert helper (TFID-sized and similar POD). Documented parent dual `aa_006061e0` (CVOGHBWakeupSkill_ctor) inserts at vector base `this+0x65c`.

## Open / residual

- Product `T` name (TFID vs other 16-B POD) per call site.
- Exact English for `FUN_004cb2e0` / `FUN_0051b6e0` / `FUN_0041d5a0` (roles sealed; names open).
- Runtime / bit-exact / differential: open.
