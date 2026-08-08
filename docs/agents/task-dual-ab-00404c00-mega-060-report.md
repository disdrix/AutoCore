# Dual A/B report — MEGA-060 OWN-ONLY (`0x00404c00`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-060**  
**Scope:** VA `0x00404c00` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `read_memory` + `disassemble_function` + callers/xrefs + `get_function_by_address` + caller decompile samples. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-060 / missions-progression residual under Mission Inventory plate (body is math leaf).  
**Hint consumed:** `Mission_Look_in_your_Mission_Inventory` → **parent consumer** `0x008a8770`, not this VA.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00404c00` Math_Vec3_Length_Sqrt_Inferred | **accept-with-gaps** — CF/ABI/RET/ST0/FSQRT/float3@ECX/5 xrefs sealed; product symbol English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-identity / 2D-length / normalize / stack-arg / CRT-sqrt claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00404c00` — sealed facts

1. **Body:** `0x00404c00`–`0x00404c20` inclusive (**33 B** / `0x21`); pad `CC` before sibling `FUN_00404c30` @ `0x00404c30`.
2. **ABI:** **ECX** = `const float*` (x@0 y@4 z@8); no stack args; return **ST0**; bare **`RET`** (`C3`).
3. **Semantics:** Euclidean length  
   `sqrt(v[0]² + v[1]² + v[2]²)` via x87 `FLD/FMUL/FADDP/FSQRT`.
4. **Callees:** **none** (inline `FSQRT`).
5. **Callers (4 / 5 sites):**  
   - `FUN_00500560` @ `0x00501257`  
   - `FUN_005a75f0` @ `0x005a77e0`  
   - `FUN_005ba440` @ `0x005bace8`  
   - `FUN_008a8770` (`Mission_Look_in_your_Mission_Inventory`) @ `0x008a8cd0`, `0x008a8d5e`
6. **Xrefs:** 5 `UNCONDITIONAL_CALL`.
7. **Name:** `Math_Vec3_Length_Sqrt_Inferred` (Ghidra `FUN_00404c00`).  
   Retired: `Named_CalleeOf_Mission_Look_in_your_Mission_Inventory_00404c00`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product symbol English (local `Math_*` vs historical D3DX-style).  
- Shared engine Vec3 type plate.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00404c00_Math_Vec3_Length_Sqrt_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00404c00_Math_Vec3_Length_Sqrt_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00404c00_FUN_00404c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00404c00_FUN_00404c00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_Vec3_Length_Sqrt_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00404c00.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Mission_Look_in_your_Mission_Inventory_00404c00.cpp` |
| Function | `docs/reconstruction/functions/aa_00404c00_FUN_00404c00.md` |
| Function named | `docs/reconstruction/functions/aa_00404c00_Math_Vec3_Length_Sqrt_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_008a8770  Mission_Look_in_your_Mission_Inventory  [parent plate; not OWN]
  ├─ FUN_00404c00  Math_Vec3_Length_Sqrt_Inferred  [OWN MEGA-060]  ×2
  └─ (other callees residual / out of scope)

FUN_00500560 / FUN_005a75f0 / FUN_005ba440
  └─ FUN_00404c00  (shared length leaf)  [OWN MEGA-060]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00404c00-mega-060-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00404c00` | Port as **float3 Euclidean length** leaf. **ECX = vec***, return float, **no stack cleanup**. Prefer `MathF.Sqrt(x*x+y*y+z*z)`. Do **not** name or implement as mission inventory. Keep distinct from normalize and from parent `0x008a8770`. |
| Pair with | consumers that build deltas then length; mission UI distance gates in `008a8770`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
**Not written by this agent.**
