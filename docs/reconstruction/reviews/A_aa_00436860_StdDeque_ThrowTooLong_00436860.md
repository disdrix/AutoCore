# Review A (reconstruction fidelity): `aa_00436860` StdDeque_ThrowTooLong_00436860

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436860` |
| **VA** | `0x00436860`–`0x004368aa` (**75 B**) |
| **Canonical name** | `StdDeque_ThrowTooLong_00436860` |
| **Prior scaffold** | `FUN_00436860` |
| **Review date** | `2026-07-29` (W29-C dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00436860_StdDeque_ThrowTooLong_00436860.md` |
| **System** | `containers` / MSVC STL deque |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Shared **deque length-overflow throw** helper (MSVC `deque::_Xlen` class):

1. SEH frame (`LAB_009bc919`).
2. `basic_string` from plate `"deque<T> too long"` @ `0x00a31520`.
3. `FUN_00401a40` → exception + vftable `PTR_FUN_009c7634`.
4. `_CxxThrowException(..., &DAT_00acc388)` — **noreturn**.

Not a capacity calculator; parents call only after max-size checks fail (CircularPtrBuf / GuardedVector map grow).

Compact clone vs `StdDeque_ThrowTooLong_0051b5f0` (112 B) — folds exception construction into `FUN_00401a40`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00436860` |
| Bytes | `read_memory` 128 B @ entry — SEH + plate push + IAT + `FUN_00401a40` + throw |
| String | `read_memory` @ `0x00a31520` → `"deque<T> too long"` |
| ThrowInfo | `read_memory` @ `0x00acc388` |
| Bounds | `get_function_by_address` body `00436860`–`004368aa` |
| Callers | `analyze_function_complete` → 4 call sites |
| Raw / clean | `aa_00436860_*`, `StdDeque_ThrowTooLong_00436860.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| No formals / always throws | **Confirmed** | single block; throw call last; pad `CC` after |
| Plate string exact | **Confirmed** | `read_memory` ASCII |
| Message → exception → throw | **Confirmed** | decompile ≡ bytes |
| ThrowInfo `DAT_00acc388` | **Confirmed** | push imm in body |
| Body **75 bytes** | **Confirmed** | bounds + byte count |
| Role = deque max-size overflow | **High** | string + parent size guards (W18-E / W28-B) |
| Product symbol `_Xlen` | **Inferred** | MSVC convention; no PDB |
| Exception C++ type name | Open | owns vftable RTTI |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install | Yes (bytes; clean documents) |
| basic_string("deque\<T\> too long") | Yes |
| FUN_00401a40 → vftable 009c7634 | Yes |
| _CxxThrowException(ex, ThrowInfo) | Yes |
| No success return | Yes |

---

## 5. Gaps / open

1. Full MSVC exception type hierarchy behind `PTR_FUN_009c7634` / ThrowInfo.
2. Product/PDB symbol string.
3. Runtime / bit-exact / differential.
4. Merge with other `"deque<T> too long"` clones only if byte-equality proven — **not** claimed here.

**Verdict:** **accept**
