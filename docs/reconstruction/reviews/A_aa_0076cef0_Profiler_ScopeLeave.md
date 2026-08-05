# Review A (reconstruction fidelity): `aa_0076cef0` Profiler_ScopeLeave

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cef0` |
| **VA** | `0x0076cef0` |
| **Body** | `0x0076cef0` only (**1** byte `c3`) |
| **Canonical name** | `Profiler_ScopeLeave` |
| **Prior / alias** | `FUN_0076cef0` |
| **Review date** | `2026-07-29` (W19-D OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0076cef0_Profiler_ScopeLeave.md` |
| **System** | client instrumentation / profiler |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Profiler scope leave stub** — single-byte `RET` with zero side effects.

Roles (xref / sibling evidence, not body logic):

1. **Leave twin** of `Profiler_ScopeEnter` @ `0x0076cf00` (adjacent leaf: `8b 41 04 c2 04 00`).
2. Mass CALL sites across AI, drive, physics step, terrain, spawn — instrumentation sandwich.
3. Physics docs already tag the pair as profiler enter/leave to **ignore for ports**.

Product English / PDB spelling open (`ScopeLeave` vs `ScopeExit`). Structural name **`Profiler_ScopeLeave`** matches sealed enter dual naming.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076cef0_FUN_0076cef0.md` |
| Annotated | `docs/reconstruction/raw/aa_0076cef0_FUN_0076cef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Profiler_ScopeLeave.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0076cef0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076cef0_Profiler_ScopeLeave.md` |
| Live decompile | empty `return;` |
| Live bytes | `c3` then `cc` pad; next fn enter |
| Sibling dual | W18-G `aa_0076cf00` Profiler_ScopeEnter |

---

## 3. Byte seal (`read_memory` @ `0x0076cef0`)

```
c3                 ret
cc cc cc …         int3 pad (not body)
8b 41 04 c2 04 00  next function Profiler_ScopeEnter @ 0x0076cf00
```

| Claim | Evidence | Conf |
|---|---|---|
| Body is pure `ret` | hex `c3` only | **High** |
| No stack cleanup in callee | not `c2 xx 00` | **High** |
| No stores / no callees | 1-byte body | **High** |
| Decompile ≡ raw ≡ bytes | all empty return | **High** |
| Distinct from enter `0x0076cf00` | adjacent, different bytes | **High** |
| High fan-in leave role | ≥100 CALL xrefs + physics pair docs | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| single `return;` | **Yes** |
| No invented domain work | **Yes** |
| No invented `ret N` | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Empty leaf body | **High** | sealed |
| Profiler leave role | **High** | twin + fan-in + docs |
| Not gameplay / physics math | **High** | |
| Product spelling | **Low–Med** | residual |
| Runtime / bit-exact | Open | |

---

## 6. Gaps

1. Product/PDB symbol spelling.
2. Exhaustive caller census beyond ≥100 sample (not needed for body seal).
3. Runtime / bit-exact — open.

**Verdict:** **accept** — 1-byte leave stub sealed.
