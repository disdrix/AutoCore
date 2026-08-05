# Review A (reconstruction fidelity): `aa_004048c0` Win32_ThrowLastErrorAsHresult_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004048c0` |
| **VA** | `0x004048c0` |
| **Body** | `0x004048c0`–`0x004048d9` (26 bytes) |
| **Canonical name** | `Win32_ThrowLastErrorAsHresult_Inferred` |
| **Prior scaffold** | `FUN_004048c0` |
| **Review date** | `2026-07-29` (W22-G dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004048c0_Win32_ThrowLastErrorAsHresult_Inferred.md` |
| **System** | `crt-com` / Win32 last-error → C++ throw |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Shared **noreturn** helper that turns the current Win32 last-error into a C++ exception:

1. `GetLastError()` via IAT `[0x009c6230]`.
2. If the code is **signed-positive**, pack as **HRESULT_FROM_WIN32**: `(err & 0xffff) | 0x80070000`.
3. `FUN_004048e0(err)` — sealed `Cxx_ThrowException_Param_Inferred` with ThrowInfo `DAT_00acc3fc`.

Parents call this after a Win32 API has already failed (e.g. `WideCharToMultiByte == 0` in `MbcsString_ConvertFromWide` @ `0x00403450`). Not a game-logic recovery path.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004048c0` |
| Bytes | `read_memory` 64 B — body hex `ff1530629c00…e806000000` |
| Bounds | `get_function_by_address` body `004048c0`–`004048d9` |
| Callees | `GetLastError`, `FUN_004048e0` |
| Callers | 7 sites (`get_function_callers`) |
| Throw leaf dual | `A_aa_004048e0_Cxx_ThrowException_Param_Inferred` |
| Parent convert dual | `A_aa_00403450_MbcsString_ConvertFromWide` |
| Raw / clean | `aa_004048c0_*`, `Win32_ThrowLastErrorAsHresult_Inferred.cpp` |

**Not performed:** Launcher, runtime throw catch, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| GetLastError then conditional pack then throw | **Confirmed** | raw ≡ live ≡ bytes |
| Pack only when `(int)err > 0` | **Confirmed** | `test eax; jle` skip |
| Mask `0xffff \| 0x80070000` | **Confirmed** | `and`/`or` immediates |
| Body **26 bytes** / noreturn | **Confirmed** | bounds + no `ret` |
| Throw via `004048e0` / `DAT_00acc3fc` | **Confirmed** | call + sealed leaf dual |
| Role = last-error HRESULT throw | **High** | CF + parent fail paths |
| Product symbol | **Open** | INFERRED |
| Exception RTTI under ThrowInfo | Open | owns `004048e0` dual residual |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
err = GetLastError();
if ((int)err > 0)
  err = (err & 0xffff) | 0x80070000;
FUN_004048e0(err);  // noreturn
```

| Stage | Match |
|---|---|
| IAT GetLastError | Yes |
| Signed >0 pack gate | Yes |
| Always call throw leaf | Yes |
| No success return | Yes |

---

## 5. Gaps / open

1. Product/PDB symbol string.
2. Full catchable-type hierarchy for `DAT_00acc3fc` (leaf dual residual).
3. Runtime / bit-exact / differential.

**Verdict:** **accept**
