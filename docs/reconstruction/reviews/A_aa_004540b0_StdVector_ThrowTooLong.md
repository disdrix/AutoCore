# Review A (reconstruction fidelity): `aa_004540b0` StdVector_ThrowTooLong

| Field | Value |
|---|---|
| **Stable ID** | `aa_004540b0` |
| **VA** | `0x004540b0` |
| **Body** | `0x004540b0`–`0x004540fa` (75 bytes) |
| **Canonical name** | `StdVector_ThrowTooLong` |
| **Prior scaffold** | `FUN_004540b0` |
| **Review date** | `2026-07-29` (W19-B dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004540b0_StdVector_ThrowTooLong.md` |
| **System** | `containers` / MSVC STL vector |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Shared **vector length-overflow throw** helper (MSVC `vector::_Xlen` class):

1. SEH frame.
2. `basic_string` from plate `"vector<T> too long"` @ `0x00a15830`.
3. `FUN_00401a40` — exception object from string.
4. `_CxxThrowException(..., &DAT_00acc388)` — **noreturn**.

Not a capacity calculator; parents call it only after max-size checks fail.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `decompile_function` @ `0x004540b0` |
| Bytes | `read_memory` 80 B @ entry — SEH + string push + IAT ctor + `00401a40` + throw |
| String | `read_memory` @ `0x00a15830` → `"vector<T> too long"` |
| ThrowInfo | `read_memory` @ `0x00acc388` |
| Callers | `get_function_callers` / `get_function_xrefs` (100+) |
| Callees | `get_function_callees` — `FUN_00401a40`, `_CxxThrowException` |
| Raw / clean | `aa_004540b0_*`, `StdVector_ThrowTooLong.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| No formals / always throws | **Confirmed** | single block; throw call last |
| Plate string exact | **Confirmed** | `read_memory` ASCII |
| Message → exception → throw | **Confirmed** | decompile ≡ bytes |
| ThrowInfo `DAT_00acc388` | **Confirmed** | push imm in body |
| Role = vector max-size overflow | **High** | string + parent size guards (`0x3fffffff` style) |
| Product symbol `_Xlen` | **Inferred** | MSVC convention; no PDB |
| Exception C++ type name | Open | owns `FUN_00401a40` / RTTI |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install | Yes (bytes; clean documents) |
| basic_string("vector\<T\> too long") | Yes |
| FUN_00401a40(msg) | Yes |
| _CxxThrowException(ex, ThrowInfo) | Yes |
| No success return | Yes |

---

## 5. Gaps / open

1. Full MSVC exception type hierarchy behind `FUN_00401a40` / `ThrowInfo`.
2. Product/PDB symbol string.
3. Runtime / bit-exact / differential.

**Verdict:** **accept**
