# Review A (reconstruction fidelity): `aa_0051b5f0` StdDeque_ThrowTooLong_0051b5f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b5f0` |
| **VA** | `0x0051b5f0` |
| **Body** | `0x0051b5f0`–`0x0051b65f` (112 bytes) |
| **Canonical name** | `StdDeque_ThrowTooLong_0051b5f0` |
| **Prior scaffold** | `FUN_0051b5f0` |
| **Review date** | `2026-07-29` (W21-E dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051b5f0_StdDeque_ThrowTooLong_0051b5f0.md` |
| **System** | `containers` / MSVC STL deque |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Shared **deque length-overflow throw** helper (MSVC `deque::_Xlen` class):

1. SEH frame.
2. `basic_string` from plate `"deque<T> too long"` @ `0x00a31520`.
3. `exception::exception` + vftable `PTR_FUN_009c7628`.
4. Message copy-construct + vftable `PTR_FUN_009c7634`.
5. `_CxxThrowException(..., &DAT_00acc388)` — **noreturn**.

Not a capacity calculator; parents call it only after max-size checks fail (e.g. deque map grow `FUN_0051c3b0` when `mapsize+grow` would exceed `0x0FFFFFFF`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0051b5f0` |
| Bytes | `read_memory` 120 B @ entry — SEH + plate push + IAT + throw |
| String | `read_memory` @ `0x00a31520` → `"deque<T> too long"` |
| ThrowInfo | `read_memory` @ `0x00acc388` |
| Bounds | `get_function_by_address` body `0051b5f0`–`0051b65f` |
| Callers | `get_function_callers` → `FUN_0051c3b0` |
| Raw / clean | `aa_0051b5f0_*`, `StdDeque_ThrowTooLong_0051b5f0.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| No formals / always throws | **Confirmed** | single block; throw call last |
| Plate string exact | **Confirmed** | `read_memory` ASCII |
| Message → exception → throw | **Confirmed** | decompile ≡ bytes |
| ThrowInfo `DAT_00acc388` | **Confirmed** | push imm in body |
| Body **112 bytes** | **Confirmed** | bounds + byte count |
| Role = deque max-size overflow | **High** | string + parent size guards |
| Product symbol `_Xlen` | **Inferred** | MSVC convention; no PDB |
| Exception C++ type name | Open | owns vftable RTTI |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install | Yes (bytes; clean documents) |
| basic_string("deque\<T\> too long") | Yes |
| exception::exception + vftable swap | Yes |
| _CxxThrowException(ex, ThrowInfo) | Yes |
| No success return | Yes |

---

## 5. Gaps / open

1. Full MSVC exception type hierarchy behind `PTR_FUN_009c7634` / ThrowInfo.
2. Product/PDB symbol string.
3. Runtime / bit-exact / differential.
4. Merge with other `"deque<T> too long"` clones only if byte-equality proven — **not** claimed here.

**Verdict:** **accept**
