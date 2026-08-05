# Annotated low-level: StdVector_InsertN_Dword_CountEcx_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_00419880` |
| VA | `0x00419880` |
| Body | `0x00419880`–`0x00419ac4` (0x245 bytes) |
| Canonical name | `StdVector_InsertN_Dword_CountEcx_Inferred` |
| Prior scaffold | `FUN_00419880` |
| System | util / container (generic) |
| Date | 2026-07-29 (W23-D dual seal) |

## Machine-level notes

- **Role:** MSVC-style `std::vector<T>::_Insert_n` for **4-byte** elements (generic dword bag).
- **ABI (differs from twin `0x004073a0`):** **ECX = count**; stack `vec*`, `where*` (insert iterator), `value*`; **`ret 0x0C`**. Twin is true thiscall on vector with count on stack.
- **Triad:** begin `+4`, end `+8`, capEnd `+0xc`. Size/cap = `(ptr-begin)>>2`. Max elems `0x3fffffff`.
- **Growth:** if `cap < size+count`: `newCap = cap + (cap>>1)` (1.5x) else 0 on overflow of that add; floor to `size+count`; `operator_new(newCap*4)`; copy prefix (`FUN_0040c7c0`), fill (`FUN_004651d0`), copy suffix; delete old; rewrite triad.
- **In-place:** capacity remains -> either shift-to-end + fill hole, or `memmove` mid-shift + fill.
- **Overflow:** `FUN_00418130` / `vector<T> too long` (rel32 Confirmed @ `0x004198e4` -> `0x00418130`).
- **Not domain logic** — multi-caller (mission journal, UI, freelist, etc.).

## Control flow (annotated)

```
val = *value
cap = begin? (capEnd-begin)>>2 : 0
if count==0: return
size = begin? (end-begin)>>2 : 0
if 0x3fffffff - size < count: ThrowTooLong()
if cap < size+count:
  newCap = cap + (cap>>1)  // or 0 if would overflow max
  if newCap < size+count: newCap = size+count
  p = new(newCap*4)
  relocate prefix to where; fill count*val; relocate suffix
  delete old; begin=p; end=p+(size+count)*4; capEnd=p+newCap*4
  return
// in-place arms...
```
