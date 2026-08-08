# Dual A/B report — R11-020 OWN-ONLY (`0x006226a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-020**  
**Scope:** VA `0x006226a0` (`aa_006226a0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including sibling ctor `0x006223c0`); invent product method English; wipe raw.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + RTTI type_info. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-020**.  
**Work item:** Residual dual seal — skills-abilities; parent score `0x005788d0` (`CVOGHBSkillBase_ctor`); unit is **OnKill multi-target HB fanout** (not a ctor).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006226a0` CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred | **accept-with-gaps** — RTTI OnKill / vtbl+0x2c / RET0x18 / table+Resolve+HB pipeline sealed; method English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): subclass-ctor / free-helper / ret4 / free-Resolve / always-start / return-0-on-miss / generic-SkillBase claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x006226a0` — sealed facts

1. **Body:** `0x006226a0`–`0x006227a7` inclusive (**0x108** / 264 B); pad `CC` before next @ `0x006227b0`.
2. **ABI:** virtual **`__thiscall`** (ECX=OnKill this **unused**) + **6 stack args**; **`RET 0x18`**; EAX=**1** at sentinel only.
3. **Class:** RTTI **`CVOGHBSkill_OnKill`** — COL `0x00aae288` → type_info `0x00af1dc8` (`.?AVCVOGHBSkill_OnKill@@`) on vtbl `PTR_FUN_009d16e4`.
4. **Dispatch:** sole xref DATA @ `0x009d1710` = **vtbl+0x2c**. No direct CALL callers.
5. **Semantics:** multi-target fanout:
   - Walk `TargetEntry` stride **0x10** (`idLo`, `idHi`, `type@+8`).
   - Sentinel `(-1,-1,0)` → return 1.
   - Resolve: `__thiscall CVOGReaction_ResolveObjectTarget(*(world+0xe4e8), type, idLo, idHi)`.
   - Hit: `new(0x6c0)` → `CVOGHBSkillBase_ctor(source, skill, world, target, tfid16, arg7)` → vtbl=`PTR_FUN_009d16e4`.
   - Owner@+0x18 set → `CVOGHBList_Enqueue(*(world+0xe4ec))` + `CVOGHBBase_Start`; else vtbl[0](1).
6. **Callees:** Resolve `0x004bae70`, `operator_new`, base ctor `0x005788d0`, Enqueue `0x005078f0`, Start `0x005081c0`, scalar dtor via vtbl.
7. **Sibling (not owned):** ctor `FUN_006223c0` @ `0x006223c0` installs same vtbl; peer pattern `Skill_HB_SpawnEntities_Execute_Inferred` @ `0x00615020` (different class, same vtbl+0x2c role).
8. **Name:** `CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred` (Ghidra `FUN_006226a0`). Method English open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/Resolve thiscall/ctor ECX sealed via `disassemble_function` + `read_memory` (decompiler CONCAT31 / dropped reaction this are presentation only).
10. **Partition parent** `0x005788d0` is wave score parent (base ctor); **live structural role** is OnKill **execute/fanout**, not ctor. Parent caller list that tags this VA as "subclass ctor" is incorrect for this unit.

### Gaps

- Product method English (class RTTI Confirmed).  
- Target-table producer / virtual call site outside DATA install.  
- Unused ECX rationale.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006226a0_CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_006226a0_CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_006226a0_FUN_006226a0.md` |
| Annotated | `docs/reconstruction/raw/aa_006226a0_FUN_006226a0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006226a0.cpp` |
| Function | `docs/reconstruction/functions/aa_006226a0_FUN_006226a0.md` |
| Function named | `docs/reconstruction/functions/aa_006226a0_CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
PTR_FUN_009d16e4  CVOGHBSkill_OnKill vtbl  [RTTI Confirmed]
  COL @ 0x00aae288 → ".?AVCVOGHBSkill_OnKill@@"
  +0x00  FUN_00651190          scalar deleting dtor
  +0x2c  FUN_006226a0          CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred  [OWN R11-020]
         └─ CVOGReaction_ResolveObjectTarget (world+0xe4e8)
         └─ operator_new(0x6c0)
         └─ CVOGHBSkillBase_ctor (0x005788d0)  [dualed parent]
         └─ install PTR_FUN_009d16e4
         └─ CVOGHBList_Enqueue(world+0xe4ec) + CVOGHBBase_Start

FUN_006223c0  OnKill subclass ctor  [NOT OWN — R11-019]
  └─ CVOGHBSkillBase_ctor + install same vtbl

Skill_HB_SpawnEntities_Execute_Inferred (0x00615020)  [dualed peer pattern]
  └─ different class PTR_FUN_009d0ec4; same vtbl+0x2c multi-work role — do not merge
```

Partition host "skills-abilities" / parent `0x005788d0` names the **score cluster**, not this leaf's product role (OnKill fanout).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-006226a0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006226a0` | Port as **`CVOGHBSkill_OnKill` vtbl+0x2c multi-target HB spawn**. Six stack args, **RET 0x18**, return **1** at sentinel. Resolve via **world+0xe4e8**; list **world+0xe4ec**. HB size **0x6c0**. |
| Distinct from | Subclass ctor `006223c0`; SpawnEntities Execute `00615020` (other class). |
| Pair with | dualed `CVOGHBSkillBase_ctor` `005788d0`; ResolveObjectTarget `004bae70`; Enqueue/Start. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred` @ `0x006226a0` / `aa_006226a0`.
- Correct parent note: this VA is **not** a subclass ctor; it is OnKill **vtbl+0x2c fanout** that *calls* the base ctor.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x006226a0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + RTTI. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses RTTI class + structural method `_Inferred`.
- Odd behavior preserved: unused ECX this; unbounded loop until sentinel; null-new would fault; always return 1.
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
