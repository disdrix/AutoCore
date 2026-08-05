# Review A (reconstruction fidelity): `aa_004a6820` StdVector_ThrowTooLong_B_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a6820` |
| **VA** | `0x004a6820`–`0x004a6890` exclusive (**112 B**) |
| **Canonical name** | `StdVector_ThrowTooLong_B_Inferred` |
| **Ghidra name** | `FUN_004a6820` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-Q) |
| **Counterpart** | `reviews/B_aa_004a6820_StdVector_ThrowTooLong_B_Inferred.md` |
| **System** | containers / MSVC STL vector |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Shared **vector length-overflow throw** helper (MSVC `vector::_Xlen` class), **B path**:

1. SEH frame (`LAB_009a11a2`).
2. `basic_string` from plate `"vector<T> too long"` @ `0x00a15830`.
3. `exception::exception` + string copy + vtbls `009c7628` / `009c7634`.
4. `_CxxThrowException(..., &DAT_00acc388)` — **noreturn**.

Not a capacity calculator; parents call it only after max-size checks fail (e.g. W34-R `StdVector_InsertN_BasicStringW`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004a6820` |
| Bytes | `read_memory` full 112 B body |
| String | `read_memory` @ `0x00a15830` → `"vector<T> too long"` |
| ThrowInfo | push imm `0x00acc388` in body |
| Callers | `get_function_callers` — 4 sites |
| Twin | W19-B `aa_004540b0` `StdVector_ThrowTooLong` |
| Raw / clean | `aa_004a6820_*`, `StdVector_ThrowTooLong_B_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| No formals / always throws | **Confirmed** | single block; throw call last |
| Plate string exact | **Confirmed** | `read_memory` ASCII |
| Message → exception → throw | **Confirmed** | decompile ≡ bytes |
| ThrowInfo `DAT_00acc388` | **Confirmed** | push imm in body |
| Role = vector max-size overflow | **High** | string + parent overflow arms |
| Distinct from `004540b0` wrap path | **High** | IAT exception vs `FUN_00401a40` |
| Product symbol `_Xlen` | **Inferred** | MSVC convention; no PDB |
| Exception C++ type name | Open | RTTI / vtbl English |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install | Yes (bytes; clean documents) |
| basic_string("vector\<T\> too long") | Yes |
| exception + string copy + vtbls | Yes |
| _CxxThrowException(ex, ThrowInfo) | Yes |
| No success return | Yes |

---

## 5. Gaps / open

1. Full MSVC exception type hierarchy behind IAT exception / RTTI.  
2. Product/PDB symbol string.  
3. Why two throw helpers exist (link units / template instantiations) — residual.  
4. Runtime / bit-exact / differential.

---

## Verdict

**accept-with-gaps** — noreturn overflow throw sealed; B-path construction differs from W19-B twin.
