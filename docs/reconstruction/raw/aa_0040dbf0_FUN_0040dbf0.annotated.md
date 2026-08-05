# Annotated low-level: FUN_0040dbf0

| Field | Value |
|---|---|
| Stable ID | `aa_0040dbf0` |
| VA | `0x0040dbf0` |
| System | util / container (std::vector&lt;dword&gt;) |
| Date | 2026-07-29 (W16-G dual seal) |
| Structural name | `StdVector_InsertOne_RebindIt_Thiscall_Inferred` |

---

## Machine-level notes

- Source: raw capture for `aa_0040dbf0` + live `decompile_function` + `read_memory` (2026-07-29).
- **Role:** insert **exactly one** dword into MSVC vector triad, then **rebind** an out-iterator so it survives realloc.
- **Twin:** `aa_00466da0` (`StdVector_InsertOne_RebindIt_Inferred`) — same CF, custom EDI/EBX ABI, calls `FUN_00456960`. This unit is standard **thiscall** + `ret 0x0C`, calls `FUN_004073a0` (`StdVector_InsertN_Dword_Inferred`).
- Prefer bytes for ABI: decompiler drops `this` on the insert-N call and may look like 3-arg free function.

### Layout (vector host `this`)

| Offset | Field |
|---|---|
| `+0x04` | begin (`T*`) |
| `+0x08` | end |
| `+0x0c` | capacity_end (touched only inside `FUN_004073a0`) |

Element stride **4** (`>> 2` / `* 4`).

### ABI (sealed)

| Slot | Role |
|---|---|
| **ECX** | `vector*` host |
| stack0 | `dword**` / `T**` out-iterator holder |
| stack1 | insert position (`T*` into buffer; push_back passes `end`) |
| stack2 | `const dword*` / `const T*` value source (`*value` filled once by insert-N) |
| return | void (writes `*outIt` only); **`ret 0x0C`** |

### Control flow

1. `begin = *(this+4)`.
2. If `begin == 0` **or** `(end-begin)>>2 == 0` → saved **index = 0**; else `index = (pos - begin) >> 2`.
3. `FUN_004073a0(this, pos, count=1, value*)` — may realloc.
4. `*outIt = *(this+4) + index*4` — rebased iterator after possible begin move.

### Parent use

`CVOGReaction_FailMissionNotify` (`0x004149d0`) is a classic push_back:

- Fast path when `size < capacity`: `*end++ = *value`.
- Slow path: `FUN_0040dbf0(&stack_value_holder, end, value)` with `this = vector`.

---

## Pseudocode (annotated)

```c
// __thiscall + ret 0x0C  |  ECX = vector*
// outIt written; insert exactly one element at pos
void __thiscall FUN_0040dbf0(
    int this_vec,      // +4 begin, +8 end, +0xC capEnd
    int *outIt,        // written with pointer to inserted element
    int pos,           // insert iterator (absolute ptr into buffer)
    undefined4 value)  // const T*  (Ghidra types as undefined4; treated as ptr by callee)
{
  int begin = *(int *)(this_vec + 4);
  int index;
  if ((begin == 0) || ((*(int *)(this_vec + 8) - begin) >> 2 == 0)) {
    index = 0;
  } else {
    index = (pos - begin) >> 2;
  }
  // live bytes: push value; push 1; push pos; mov ecx,this; call FUN_004073a0
  FUN_004073a0(/*this*/ this_vec, pos, /*count*/ 1, value);
  *outIt = *(int *)(this_vec + 4) + index * 4;
  return; // ret 0x0C
}
```

---

## Open questions

- Product / RTTI symbol for this exact helper (structural name kept).
- Element domain varies by caller (dword bag); FailMissionNotify is one push_dword site only.
- Full grow policy sealed on callee dual `aa_004073a0` (not re-owned here).
