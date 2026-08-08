# Dual A/B report — MEGA-007 OWN-ONLY (`0x00589d90`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-007**  
**Scope:** VA `0x00589d90` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `get_function_by_address` + parent/sibling decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-007 / skills-abilities residual under skill HB parent `0x0061b6f0`.  
**Hint consumed:** `Skill_HB_ApplyShieldPool` → sealed as `Skill_HB_ApplyShieldPool_Inferred` (product symbol open).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00589d90` Skill_HB_ApplyShieldPool_Inferred | **accept-with-gaps** — CF/ABI/RET/cdecl-3arg/ADD ESP 0xC/shield +0x144+0x148/fraction band [-1,1]/resolve chain/3 xrefs sealed; product English + orphan site + virtual slot names open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall / SetCurrentShield-merge / HP-merge / heat-merge / always-absolute / always-fraction / void-return claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00589d90` — sealed facts

1. **Body:** `0x00589d90`–`0x00589e5c` inclusive (**205 B** / `0xCD`); pad `CC` after last `RET`.
2. **ABI:** **cdecl**; stack `fallbackHost*`, `preferredHost*`, `float amount`; return **EAX** int delta; bare **`RET`** (`C3`). Callers **`ADD ESP,0xC`**.
3. **Semantics:** skill-HB **shield pool apply**:
   - Prefer `preferredHost` → `vtbl+0x19c` → MI component LEA; on fail use `preferredHost+0xAC`, else `fallbackHost` same chain.
   - `component->vtbl+0x1d4` → combat pool.
   - If `amount ∈ [DAT_00aaa668=-1.0f, g_flOne=1.0f]`: delta = `(int)(max * amount)`; else `(int)amount` via `CVTTSS2SI`.
   - `new = clamp(cur + delta, 0, max)`; store `pool+0x144`; return `new - cur` if changed else 0.
4. **Constants:** `read_memory` seals `-1.0f` @ `0x00aaa668`, `1.0f` @ `0x00a0f2a0`.
5. **Field plate:** current `+0x144`, max `+0x148` — same ints as dualed `Vehicle_SetCurrentShield` (`0x00419140`), different ABI/role.
6. **Callees:** **none** direct (virtual indirect only).
7. **Callers (2 bound + 1 orphan site):**
   - `FUN_0061b6f0` @ `0x0061b88f` (HB tick; period `+0x6c4` × shield amount float `+0x144` on HB)
   - `FUN_00618270` @ `0x006185fb` (peer apply)
   - site `0x0061be96` UNCONDITIONAL_CALL (no enclosing function bound)
8. **Xrefs:** 3 `UNCONDITIONAL_CALL`.
9. **Name:** `Skill_HB_ApplyShieldPool_Inferred` (Ghidra `FUN_00589d90`). Product map open → `_Inferred`. No `Named_CalleeOf_*` scaffold existed to retire.
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product / PDB symbol English.  
- Virtual slot English (`vtbl+0x19c`, `vtbl+0x1d4`).  
- Orphan site `0x0061be96` function plate.  
- Packaging helper `FUN_00578270` product role (out of OWN scope).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00589d90_Skill_HB_ApplyShieldPool_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00589d90_Skill_HB_ApplyShieldPool_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00589d90_FUN_00589d90.md` |
| Annotated | `docs/reconstruction/raw/aa_00589d90_FUN_00589d90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_ApplyShieldPool_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00589d90.cpp` |
| Function | `docs/reconstruction/functions/aa_00589d90_FUN_00589d90.md` |
| Function named | `docs/reconstruction/functions/aa_00589d90_Skill_HB_ApplyShieldPool_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0061b6f0  skill HB tick / status apply  [parent dual context; not OWN]
  ├─ FUN_005787a0  Skill_HB_RescheduleStatus     [MEGA-004]
  ├─ FUN_00589bc0  Skill_HB_ApplyHeatDelta       [MEGA-005]
  ├─ FUN_00589c70  Skill_HB_ApplyHpDelta         [MEGA-006]
  ├─ FUN_00589d90  Skill_HB_ApplyShieldPool_Inferred  [OWN MEGA-007]
  ├─ FUN_0058cc40  Skill_HB_ApplyShortAndFloater [MEGA-008]
  └─ FUN_0058d8e0  Skill_HB_ApplyMultiArgEffect  [MEGA-009]

FUN_00618270  peer apply path
  └─ FUN_00589d90  [OWN MEGA-007]

Vehicle_SetCurrentShield  0x00419140  [field plate twin; absolute set]
  └─ same +0x144 / +0x148 ints; different ABI
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00589d90-mega-007-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00589d90` | Port as **cdecl shield-pool apply** helper. Args: fallback host, preferred host, float amount. Return **int applied delta**. When `amount ∈ [-1,1]` treat as **fraction of max shield**; else trunc absolute. Clamp current to `[0, max]` at pool `+0x144`/`+0x148`. **Caller cleans 12 bytes**. |
| Do **not** | Merge with `Vehicle_SetCurrentShield` (thiscall absolute void), HP apply `00589c70`, or heat apply `00589bc0`. |
| Pair with | skill HB tick `0061b6f0`; peer `00618270`; field plate `00419140`; sibling apply helpers MEGA-005/006/008/009. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
**Not written by this agent.**
