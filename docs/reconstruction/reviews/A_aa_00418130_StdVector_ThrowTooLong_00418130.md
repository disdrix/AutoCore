# Review A (reconstruction fidelity): `aa_00418130` StdVector_ThrowTooLong_00418130

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418130` |
| **VA** | `0x00418130` |
| **Body** | `0x00418130`–`0x0041817a` (75 bytes) |
| **Canonical name** | `StdVector_ThrowTooLong_00418130` |
| **Prior scaffold** | `FUN_00418130` |
| **Review date** | `2026-07-29` (W20-G dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00418130_StdVector_ThrowTooLong_00418130.md` |
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

Sibling clone of sealed `StdVector_ThrowTooLong` @ `0x004540b0` (same plate/ThrowInfo/IAT; EH-state store ordering differs slightly). Not a capacity calculator; parents call it only after max-size checks fail (e.g. toast insert `0x1af286b` bound).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00418130` |
| Bytes | `read_memory` 80 B @ entry — SEH + string push + IAT ctor + `00401a40` + throw |
| String | `read_memory` @ `0x00a15830` → `"vector<T> too long"` |
| ThrowInfo | `read_memory` @ `0x00acc388` |
| Bounds | `get_function_by_address` body `00418130`–`0041817a` |
| Callers | `get_function_callers` (31 listed) |
| Raw / clean | `aa_00418130_*`, `StdVector_ThrowTooLong_00418130.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| No formals / always throws | **Confirmed** | single block; throw call last |
| Plate string exact | **Confirmed** | `read_memory` ASCII |
| Message → exception → throw | **Confirmed** | decompile ≡ bytes |
| ThrowInfo `DAT_00acc388` | **Confirmed** | push imm in body |
| Body **75 bytes** | **Confirmed** | bounds + byte count |
| Role = vector max-size overflow | **High** | string + parent size guards |
| Sibling of `004540b0` | **High** | same plate/ThrowInfo/IAT; order delta only |
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
4. Merge with `004540b0` only if byte-equality proven — **not** equal (EH-state ordering).

**Verdict:** **accept**
