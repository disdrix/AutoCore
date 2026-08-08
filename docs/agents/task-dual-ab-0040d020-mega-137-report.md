# Dual A/B report — MEGA-137 OWN-ONLY (`0x0040d020`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-137**  
**Scope:** VA `0x0040d020` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-137 residual dual seal — pick ray/dist scale demoted pure math leaf.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040d020` Math_Vec3Length_Inferred | **accept-with-gaps** — CF/ABI/RET/leaf/xrefs sealed; product name + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): squared-length / 2D / scale-merge / normalize / thiscall / exclusive-pick / CRT-sqrt claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0040d020` — sealed facts

1. **Body:** `0x0040d020`–`0x0040d03e` inclusive (**31 B** / `0x1F`); pad `CC` before `FUN_0040d040`.
2. **ABI:** **`__cdecl`**; stack floats `x,y,z` @ `[esp+4/8/c]`; **ST0** return; plain **`RET`**.
3. **Semantics:** Euclidean **3-float length** leaf:
   - `FLD`/`FMUL` each component; two `FADDP`; `FSQRT`; `RET`.
   - No callees; no globals; no scale.
4. **Callees:** none.
5. **Callers (3 UNCONDITIONAL_CALL / 2 funcs):**
   - `Client_InteractClickPickTarget` `0x009247b0` @ `0x009249c0`, `0x00924c76` — `length(hit−camera)`; then `* _DAT_00aaacbc` (**0.015f**, caller-side).
   - `FUN_005ba440` `0x005ba440` @ `0x005bad63` — path/segment node delta length.
6. **Xrefs:** 3 UNCONDITIONAL_CALL (matches callers).
7. **Name:** `Math_Vec3Length_Inferred` (Ghidra `FUN_0040d020`). Product open → `_Inferred`. Retire `Named_CalleeOf_Client_InteractClickPickTarget_0040d020`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product / PDB English.  
- IEEE NaN/−0 edges (static only).  
- Residual caller `FUN_005ba440` product role (out of OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d020_Math_Vec3Length_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040d020_Math_Vec3Length_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040d020_FUN_0040d020.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d020_FUN_0040d020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_Vec3Length_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d020.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_InteractClickPickTarget_0040d020.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d020_FUN_0040d020.md` |
| Function named | `docs/reconstruction/functions/aa_0040d020_Math_Vec3Length_Inferred.md` |

---

## Instruction seal

```text
0040d020  D9 44 24 04          FLD   dword [esp+0x4]
0040d024  D8 4C 24 04          FMUL  dword [esp+0x4]
0040d028  D9 44 24 08          FLD   dword [esp+0x8]
0040d02c  D8 4C 24 08          FMUL  dword [esp+0x8]
0040d030  DE C1                FADDP
0040d032  D9 44 24 0C          FLD   dword [esp+0xc]
0040d036  D8 4C 24 0C          FMUL  dword [esp+0xc]
0040d03a  DE C1                FADDP
0040d03c  D9 FA                FSQRT
0040d03e  C3                   RET
```

Hex: `d9442404d84c2404d9442408d84c2408dec1d944240cd84c240cdec1d9fac3`

---

## Chain context (not dualled; evidence only)

```text
Client_InteractClickPickTarget  (0x009247b0)  [prior dual / residual parent]
  ├─ delta = hit_pos − camera(DAT_00d17944+0x228/22c/230)
  ├─ FUN_0040d020  Math_Vec3Length_Inferred  [OWN MEGA-137]
  └─ scale *= _DAT_00aaacbc  (0.015f)  [caller, not OWN]

FUN_005ba440  (0x005ba440)  [residual]
  └─ FUN_0040d020  (path/segment node delta length)  [OWN MEGA-137]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040d020-mega-137-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040d020` | Port as **`sqrt(x*x+y*y+z*z)`** pure leaf. **`__cdecl`**, three floats, return float. Do **not** bake pick `0.015` scale into this helper. Keep distinct from squared-length or normalize. |
| Pair with | dualed/parent `Client_InteractClickPickTarget` `009247b0`; residual `FUN_005ba440`; scale constant `DAT_00aaacbc`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY` / coverage ledgers as applicable  
- Do **not** claim runtime Confirmed without harness
