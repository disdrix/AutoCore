# Dual A/B report — R11-011 OWN-ONLY (`0x00614c80`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-011**  
**Scope:** VA `0x00614c80` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual `0x005788d0` edits.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callees` / `get_function_xrefs` / `get_xrefs_to` / `get_bulk_xrefs` + `read_memory` + `list_strings`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Residual dual wave R11 — undualed callee of dualed `CVOGHBSkillBase_ctor`; partition system skills-abilities; parent `0x005788d0`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00614c80` CVOGHBSkill_Master_Execute | **accept-with-gaps** — CF/ABI/RTTI class/vtbl+0x2c/catalog type 3/fan-out Enqueue+Start sealed; product method English + formal types + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void/cdecl/multi-caller/ctor-identity/0x6d0-SpawnEntities-vtbl/return-0/CONCAT-Resolve claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00614c80` — sealed facts

1. **Body:** `0x00614c80`–`0x00614d87` inclusive (**264 B** / `0x108`); pad `CC`.
2. **ABI:** **`__thiscall`** `ECX` = Master HB `this`; **6 stack dwords**; **`RET 0x18`**; returns **`1` in EAX** always (sentinel path and fall-through).
3. **Class:** RTTI **Confirmed** `.?AVCVOGHBSkill_Master@@` (COL `0x00aadb2c` → type_info `0x00af28ac`) on vtbl **`PTR_FUN_009d0e6c`**.
4. **Slot:** This VA is **vtbl+0x2c** (DATA sole xref `0x009d0e98`). Peer convention = Execute (cf. SpawnEntities execute dual).
5. **Catalog:** `SkillElementFactory_RegisterCatalog` type id **3** — `new(0x6c0)` + `CVOGHBSkillBase_DefaultCtor` + stamp Master vtbl.
6. **Semantics:** Index `0..99` over **stride-0x10** target table (arg4):
   - Sentinel `{id0=-1, id1=-1, type=0}` → return 1.
   - Else `CVOGReaction_ResolveObjectTarget(*(map+0xe4e8), type, id0, id1)`.
   - On hit: `new(0x6c0)` → `CVOGHBSkillBase_ctor(..., resolvedTarget, ...)` → stamp `PTR_FUN_009d0e6c`.
   - Owner `child+0x18` null → `vtbl[0](1)` destroy; else `Enqueue(*(map+0xe4ec))` + `CVOGHBBase_Start`.
7. **Callees (direct):** Resolve `0x004bae70`, `operator_new`, `CVOGHBSkillBase_ctor` `0x005788d0`, Enqueue `0x005078f0`, Start `0x005081c0`.
8. **Callers:** **none direct** — vtbl dispatch only.
9. **Name:** `CVOGHBSkill_Master_Execute` (Ghidra `FUN_00614c80`). Class RTTI Confirmed; “Execute” High via slot convention.
10. **Decompile ≡ raw CF**; ABI/epilogue/vtbl/RTTI sealed via `read_memory` (no `disassemble_bytes`).

### Gaps

- Product/PDB method English beyond vtbl+0x2c convention.  
- Full C++ types for stack formals / target-table producer.  
- Type of resolve context `*(map+0xe4e8)`.  
- Child same-vtbl fan-out product design intent.  
- Runtime / bit-exact / differential.  
- Parent ctor / factory residual (not owned).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00614c80_CVOGHBSkill_Master_Execute.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00614c80_CVOGHBSkill_Master_Execute.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00614c80_FUN_00614c80.md` |
| Annotated | `docs/reconstruction/raw/aa_00614c80_FUN_00614c80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Master_Execute.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00614c80.cpp` |
| Function | `docs/reconstruction/functions/aa_00614c80_FUN_00614c80.md` |
| Function named | `docs/reconstruction/functions/aa_00614c80_CVOGHBSkill_Master_Execute.md` |

---

## Chain context (not dualled; evidence only)

```text
SkillElementFactory_RegisterCatalog  0x0054a640  [dualed]
  type id 3 → new(0x6c0) + DefaultCtor + PTR_FUN_009d0e6c (Master prototype)

CVOGHBSkill_Master vtbl PTR_FUN_009d0e6c
  +0x00  FUN_00651190  scalar deleting dtor
  +0x2c  0x00614c80    CVOGHBSkill_Master_Execute  [OWN R11-011]

  Execute:
    foreach targetTable entry:
      ResolveObjectTarget → CVOGHBSkillBase_ctor 0x005788d0 [parent dualed]
        → stamp Master vtbl → Enqueue(map+0xe4ec) → Start

Contrast (not this VA):
  Skill_HB_SpawnEntities_*  vtbl 009d0ec4 / size 0x6d0 / catalog id 0xa
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00614c80-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00614c80` | Port as **`CVOGHBSkill_Master` virtual execute** (element type **3**). **thiscall** + **6 stack args**, **`RET 0x18`**, always return **1**. Fan-out: resolve table entries → child Master HB `0x6c0` → Enqueue+Start. Preserve sentinel `{-1,-1,type0}`, cap **100**, stride **0x10**, owner-null destroy path. Do **not** confuse with SpawnEntities execute (`0x00615020`, size `0x6d0`, vtbl `009d0ec4`). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).
