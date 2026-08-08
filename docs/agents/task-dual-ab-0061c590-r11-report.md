# Dual A/B report — R11-015 OWN-ONLY (`0x0061c590`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-015**  
**Scope:** VA `0x0061c590` only. Dual A/B + raw append + annotated + clean named + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent ledger ownership of `0x005788d0`.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → R11-015  
**System:** skills-abilities  
**Parent (context only):** `0x005788d0` `CVOGHBSkillBase_ctor`  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0061c590` CVOGHBSkill_XP_ApplyToTargetList_Inferred | **accept** — RTTI class Confirmed; multi-target arm CF/ABI/vtbl/resolve-ctx/Enqueue sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): ctor-merge / OnHeartBeat-merge / decompiler-only Resolve / period-field-merge / multi-CALL / size-0x6d0 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).  
**Terminal:** false.

---

## VA `0x0061c590` — sealed facts

1. **Body:** `0x0061c590`–`0x0061c6af` inclusive (**288 B** / `0x120`); SEH `LAB_009a879b`.
2. **ABI:** **six** stack formals; **`ret 0x18`**; **EAX = 1** on sentinel exit. Body does not use inbound ECX as object `this`.
3. **Class:** **`CVOGHBSkill_XP`** — RTTI **Confirmed** `.?AVCVOGHBSkill_XP@@` via COL `0x00aade00` → type_info `0x00af29ec` on vtbl **`PTR_FUN_009d119c`**.
4. **Vtbl placement:** this VA at **vtbl+0x2C** (`0x009d11c8`) — sole inbound xref (**DATA**). No UNCONDITIONAL_CALL callers.
5. **Loop:** index over **`param_4`** stride **0x10**; sentinel `{0xFFFFFFFF,0xFFFFFFFF, mode==0}` → return 1.
6. **Resolve:** `CVOGReaction_ResolveObjectTarget` with **ECX = `*(param_3+0xe4e8)`** (bytes; decompiler omits this), stack `(bGlobal, coidLo, coidHi)`.
7. **Spawn:** `operator_new(0x6c0)` → **`CVOGHBSkillBase_ctor`** (`0x005788d0`) with `(source, skillBlob, world, resolvedTarget, tfid16, arg7)` → install **`009d119c`**.
8. **Period:** `HB[+0x08] = skillBlob[+0x1c]`; then **`CVOGHBBase_SetPeriodAndCounter(hb, -1000, true)`**.
9. **Accept path:** if `pOwner != null` → **`CVOGHBList_Enqueue(*(world+0xe4ec))`** + **`CVOGHBBase_Start`**; else **vtbl[0](1)** scalar delete.
10. **Name:** `CVOGHBSkill_XP_ApplyToTargetList_Inferred` — class Confirmed, method role **Inferred**. Ghidra: `FUN_0061c590`.

### Gaps

- Product/PDB method name for vtbl+0x2C.  
- Producer of the TFID row table / max rows.  
- Whether virtual dispatchers pass unused ECX this.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0061c590_CVOGHBSkill_XP_ApplyToTargetList_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0061c590_CVOGHBSkill_XP_ApplyToTargetList_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R11-015 append) | `docs/reconstruction/raw/aa_0061c590_FUN_0061c590.md` |
| Annotated | `docs/reconstruction/raw/aa_0061c590_FUN_0061c590.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_XP_ApplyToTargetList_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_0061c590.cpp` |
| Function named | `docs/reconstruction/functions/aa_0061c590_CVOGHBSkill_XP_ApplyToTargetList_Inferred.md` |
| Function scaffold | `docs/reconstruction/functions/aa_0061c590_FUN_0061c590.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0061c590_CVOGHBSkill_XP_ApplyToTargetList_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0061c590_CVOGHBSkill_XP_ApplyToTargetList_Inferred.md` |
| This report | `docs/agents/task-dual-ab-0061c590-r11-report.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBSkillBase_ctor  0x005788d0     [parent; RTTI CVOGHBSkillBase; not OWN]
  └─ FUN_0061c590 / CVOGHBSkill_XP_ApplyToTargetList_Inferred  [OWN R11-015]
        ├─ CVOGReaction_ResolveObjectTarget  0x004bae70  (ctx @ world+0xe4e8)
        ├─ operator_new(0x6c0) + XP vtbl 009d119c
        ├─ CVOGHBBase_SetPeriodAndCounter(-1000, true)
        ├─ CVOGHBList_Enqueue(world+0xe4ec) + CVOGHBBase_Start
        └─ vtbl[0] scalar dtor on reject

Sibling vtbl slots (not OWN):
  +0x0C  FUN_0061c940   XP virtual (convoy/personal branches)
  +0x38  FUN_0061c7c0   debug: conversion_percent (personal xp %)
  +0x3C  FUN_0061c830   debug: op_scalar_1 (convoy xp %)

Factory / table context (not OWN):
  FUN_00548990   new(0x6c0)+default skill base+XP vtbl
  FUN_0054a640   skill-type registry index 0x0f → XP vtbl
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0061c590` | Port as **XP skill multi-target arm**: resolve each 16B TFID row, spawn **0x6c0** `CVOGHBSkill_XP` HB, **always-ready −1000** period after blob pulse copy, Enqueue on **world+0xe4ec**. |
| Preserve | Resolve ctx **+0xe4e8** (not the list); accept polarity via **pOwner**; sentinel terminator; **ret 0x18**. |
| Do not | Merge with Virus/SpawnEntities ctors; invent CALL parents; claim runtime Confirmed. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may later lockstep:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history
- `systems/skills-abilities.md` residual tables
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0061c590`); no Launcher; no parent ledger edits; no `disassemble_bytes`; raw append-only.
