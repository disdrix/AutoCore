# Review A (reconstruction fidelity): `aa_00422d10` Com_QI_ThenVtbl1c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422d10` |
| **VA** | `0x00422d10` |
| **Canonical name** | `Com_QI_ThenVtbl1c_Inferred` (structural) |
| **Ghidra name** | `FUN_00422d10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00422d10_Com_QI_ThenVtbl1c_Inferred.md` |
| **System** | COM / DB / locale bind chain |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

COM **prepare → QueryInterface → method at vtbl+0x1c** helper used on the MBCS→wide bind path.

Parent `Locale_MbcsToWideThenInvoke_Inferred` (`0x0041a810`) always calls this, then on HRESULT success (≥0) calls sibling `FUN_0041de50`.

Recovered CF (bytes + decompile):

1. `hr = FUN_00422d70(...)` — prep: teardown (`FUN_00423170`), CS enter (`FUN_00437cd0`), QI against IID `DAT_00a8601c`, method at **+0x0c**, CS leave (`FUN_0041d7b0`). Fail → return hr.
2. On success: CS enter again (`FUN_00437cd0`).
3. `hr = (**iface->vtbl)(iface, &IID_DAT_00a85fec, &out)` — classic **QueryInterface** shape (IID constant `0x00a85fec`).
4. If `hr >= 0`: `hr = (*(out->vtbl + 0x1c))(out, …)` — third arg carried in register (decompiler `unaff_ESI` / stack).
5. CS leave (`FUN_0041d7b0`).
6. Return final HRESULT.

Critical section sandwich: enter before QI, leave after method (or after failed QI path post-enter). Prep stage has its own enter/leave pair inside `FUN_00422d70`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00422d10_*`, `reconstructed-exact/FUN_00422d10.cpp` |
| Function record | `functions/aa_00422d10_FUN_00422d10.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00422d10` (2026-07-29) |
| Bytes | `read_memory` 80 B — `push 0x00a85fec`; `call [ecx]`; `call [ecx+0x1c]` |
| Prep callee | `FUN_00422d70` decompile (QI `DAT_00a8601c`, method +0xc) |
| CS helpers | `FUN_00437cd0` enter, `FUN_0041d7b0` leave (role High from pattern) |
| Parent dual | `A_aa_0041a810_Locale_MbcsToWideThenInvoke_Inferred.md` |
| Callers | `FUN_0041a810`, `FUN_0041b670`, `FUN_0041b790` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Returns HRESULT; success gate `hr >= 0` | **Confirmed** | body + parent |
| QI IID = `DAT_00a85fec` | **Confirmed** | `push 00a85fec`; only xref from this VA |
| Method slot **vtbl+0x1c** | **Confirmed** | `call [ecx+0x1c]` / decompile |
| Prep via `FUN_00422d70` before QI | **Confirmed** | first call |
| CS enter/leave around QI+method | **High** | `00437cd0` / `0041d7b0` pair |
| Used by locale MBCS bridge | **High** | parent dual |
| Exact COM interface product name | **Open** | GUID blob not named |
| Full stack formals (wide string, extra) | **Tentative** | decompiler spacebase noise; parent passes wide ptr |
| clean ≡ raw ≡ live CF | **High** | scaffold matches live |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Prep `00422d70`; fail return | Yes |
| CS enter | Yes |
| QI IID `a85fec` into local | Yes |
| On QI ok: vtbl+0x1c | Yes |
| CS leave | Yes |
| Return hr | Yes |

### Recovered CF

```c
// HRESULT Com_QI_ThenVtbl1c(IUnknown **holder /*ECX/param*/, ... wide/extra ...)
HRESULT hr = Com_Prep_QI_a8601c_Vtbl0c(...);   // FUN_00422d70
if (hr < 0) return hr;
CriticalSection_Enter(...);                      // FUN_00437cd0
hr = (*holder)->QueryInterface(IID_a85fec, &p);
if (hr >= 0)
  hr = (*(fn**)(*p + 0x1c))(p, /*args incl ESI/stack*/);
CriticalSection_Leave(...);                      // FUN_0041d7b0
return hr;
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_0041a810` | MBCS→wide then this then `0041de50` |
| Caller | `FUN_0041b670`, `FUN_0041b790` | sibling bind paths |
| Callee | `FUN_00422d70` | prep QI |
| Callee | `FUN_00437cd0` / `FUN_0041d7b0` | CS enter/leave |
| Callee | vtbl[0] / vtbl[+0x1c] | QI + bound method |

---

## 6. Gaps / open

1. Decode GUID at `0x00a85fec` / `0x00a8601c` to product interface names.
2. Exact formals past QI out-pointer (wide string binding role Probable from parent).
3. What vtbl+0x1c method does (bind column / open stream) — needs interface dual.
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — QI + +0x1c CF sealed; product interface Open.
