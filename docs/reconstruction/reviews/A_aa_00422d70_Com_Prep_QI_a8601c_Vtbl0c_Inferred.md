# Review A (reconstruction fidelity): `aa_00422d70` Com_Prep_QI_a8601c_Vtbl0c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422d70` |
| **VA** | `0x00422d70` |
| **Canonical name** | `Com_Prep_QI_a8601c_Vtbl0c_Inferred` (structural) |
| **Ghidra name** | `FUN_00422d70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00422d70_Com_Prep_QI_a8601c_Vtbl0c_Inferred.md` |
| **System** | COM / DB / locale bind chain |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Prep stage** for COM bind: teardown residual, enter critical section, **QueryInterface** against IID `DAT_00a8601c`, invoke method at **vtbl+0x0c**, leave CS, return HRESULT.

Sole static caller: `Com_QI_ThenVtbl1c_Inferred` (`0x00422d10`) — runs this first; on success continues with a *different* IID (`DAT_00a85fec`) and method at **+0x1c**.

Recovered CF (bytes + decompile):

1. `FUN_00423170()` — teardown / prep residual (role High from bind-chain pattern).
2. `FUN_00437cd0()` — **CS enter**.
3. `hr = (*iface->vtbl)(iface, &IID_DAT_00a8601c, &out)` — QI shape (bytes: `push out; push a8601c; push this; call [ecx]`).
4. If `hr < 0`: CS leave (`FUN_0041d7b0`); return hr.
5. `hr = (*(out->vtbl + 0x0c))(out, 0, &DAT_00a8600c)` — method slot **+0xc** with zero middle arg + constant third.
6. CS leave; return hr.

Epilogue: **`RET 4`** (stdcall one stack formal / holder).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00422d70_*`, `reconstructed-exact/FUN_00422d70.cpp` |
| Function record | `functions/aa_00422d70_FUN_00422d70.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00422d70` (2026-07-29) |
| Bytes | `read_memory` 64 B — `push a8601c`; `call [ecx]`; success → `call […+0xc]`; `C2 04 00` |
| Parent dual | `A_aa_00422d10_Com_QI_ThenVtbl1c_Inferred.md` |
| CS helpers | `FUN_00437cd0` enter, `FUN_0041d7b0` leave |
| Callers | sole: `FUN_00422d10` @ `00422d17` |

**Not performed:** disassemble_bytes, Launcher, GUID product decode, runtime.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Returns HRESULT; fail gate `hr < 0` | **Confirmed** | body |
| QI IID = `DAT_00a8601c` | **Confirmed** | push imm + decompile |
| Method slot **vtbl+0x0c** | **Confirmed** | decompile `local_4 + 0xc` |
| CS enter before QI; leave on both paths | **High** | enter/leave pair |
| Teardown `FUN_00423170` first | **High** | first call |
| Sole caller is `00422d10` prep | **Confirmed** | bulk xrefs |
| Product interface / method English | **Open** | GUID not named |
| Exact formals past IID out-ptr | **Tentative** | middle arg 0 + `DAT_00a8600c` sealed as constants |
| clean ≡ raw ≡ live | **High** | scaffold matches |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Teardown `00423170` | Yes |
| CS enter `00437cd0` | Yes |
| QI `a8601c` | Yes |
| Fail → leave + return | Yes |
| Method +0xc; leave; return | Yes |

### Recovered CF

```c
// HRESULT Com_Prep_QI_a8601c_Vtbl0c(IUnknown **holder /* … */)
Teardown_00423170();
CriticalSection_Enter();                 // FUN_00437cd0
hr = (*holder)->QueryInterface(IID_a8601c, &p);
if (hr < 0) { CriticalSection_Leave(); return hr; }
hr = (*(fn**)(*p + 0x0c))(p, 0, &DAT_00a8600c);
CriticalSection_Leave();                 // FUN_0041d7b0
return hr;                               // RET 4
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_00422d10` | outer QI + vtbl+0x1c stage |
| Callee | `FUN_00423170` | teardown / prep |
| Callee | `FUN_00437cd0` / `FUN_0041d7b0` | CS enter / leave |
| Callee | vtbl[0] / vtbl[+0xc] | QI + bound method |

---

## 6. Gaps / open

1. Decode GUIDs at `0x00a8601c` / `0x00a8600c` to product names.
2. What vtbl+0xc does (open stream / bind column) — needs interface dual.
3. Exact owner of CS object (pattern-sealed, not named).
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — prep QI `a8601c` + method +0xc + CS sandwich sealed; product interface Open.
