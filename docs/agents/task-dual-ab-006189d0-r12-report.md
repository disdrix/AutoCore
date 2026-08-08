# Dual A/B report — R12-040 OWN-ONLY (`0x006189d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-040**  
**Scope:** VA `0x006189d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual `0x00618180` edits.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-040**.  
**Work item:** Residual dual wave R12 — skills-abilities; parent dual `0x00618180` (`CVOGHBSkill_Common_ctor`).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006189d0` CVOGHBSkill_Common_SpawnPerTargetHB_Inferred | **accept-with-gaps** — RTTI Common + vtbl+0x2c + CF/ABI + spawn pipeline + bool return sealed; product method English residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): ctor-identity / free-helper / always-return-1 / free-Resolve / always-start / invent product English / Runtime Confirmed claims **falsified**; no CF rejects.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x006189d0` — sealed facts

1. **Body:** `0x006189d0`–`0x00618be2` (Ghidra); **530 B** / `0x212`; pad `CC`; terminal **`ret 0x18`** @ `0x00618be0`.

2. **ABI:** virtual **`__thiscall`** surface (ECX = Common HB `this`, **unused** in body) + **6 stack dwords**; **`EAX = (spawnCount != 0)`** via `setne`.

3. **Identity (Confirmed):**
   - RTTI **`.?AVCVOGHBSkill_Common@@`** (type_info `0x00af2918` via COL `0x00ab1820`)
   - Installed on vtbl **`PTR_FUN_009e1f2c`**
   - Sole xref **DATA** @ **`0x009e1f58`** = **vtbl+0x2c**
   - No direct CALL callers

4. **Name:** `CVOGHBSkill_Common_SpawnPerTargetHB_Inferred` — class **Confirmed**, method role **High** structural / English **Inferred**. Supersedes scaffold-only `FUN_006189d0` product claim. **Never Runtime Confirmed.**

5. **High-level CF:**
   1. `Rng_CloneSeededTable_Inferred(param_6)` → ushort slice
   2. Loop `index` over `param_4 + index*0x10` until sentinel `{-1,-1,type0}`
   3. Chance gate `FUN_00589b80(*(skill+0xe4), slice[index])` — non-zero skip
   4. `CVOGReaction_ResolveObjectTarget` thiscall `ECX=*(world+0xe4e8)` (bytes seal; decompiler drops this)
   5. On hit: `operator_new(0x6d0)` → `RandomUnitScalar` → `FUN_007a4120` → **`CVOGHBSkill_Common_ctor(..., flag=0, scale=1.0f)`**
   6. Owner@+0x18 null → vtbl[0](1); else `CVOGHBList_Enqueue(*(world+0xe4ec))` + `CVOGHBBase_Start`; `spawnCount++`
   7. Self-target skip via source vtbl+0x19c; else target event **0x14** / source event **0x15** (vtbl+0x238)
   8. Sentinel: `delete[]` slice; return `spawnCount != 0`

6. **Callees:** `0x0058ab60`, `0x00589b80`, `0x004bae70`, `operator_new`/`operator_delete[]`, `CVOGReaction_RandomUnitScalar`, `0x007a4120`, **`0x00618180`**, `0x005078f0`, `0x005081c0`.

7. **Callers:** **none direct** — vtbl dispatch only.

8. **Decompile ≡ raw CF**; Resolve-this + bool-return sealed by bytes (decompiler presentation gaps closed).

### Gaps

1. Product design English for method beyond structural Execute/spawn role.  
2. Formal types for skill blob / world / target-table producer.  
3. Product meaning of chance `skill+0xe4` and scale `DAT_009d4d20` (`0x3b808081`).  
4. Product names for events `0x14`/`0x15` and helpers `FUN_00589b80` / `FUN_007a4120`.  
5. Full Common vtbl slot catalog (other slots not owned).  
6. Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006189d0_CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_006189d0_CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R12 re-verify append) | `docs/reconstruction/raw/aa_006189d0_FUN_006189d0.md` |
| Annotated | `docs/reconstruction/raw/aa_006189d0_FUN_006189d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006189d0.cpp` |
| Function named | `docs/reconstruction/functions/aa_006189d0_CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.md` |
| Function scaffold | `docs/reconstruction/functions/aa_006189d0_FUN_006189d0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_006189d0_CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_006189d0_CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.md` |
| This report | `docs/agents/task-dual-ab-006189d0-r12-report.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBSkill_Common_ctor       0x00618180  [parent dual R11-014 — not edited]
  installs PTR_FUN_009e1f2c
  ↑
CVOGHBSkill_Common vtbl PTR_FUN_009e1f2c
  +0x2c  0x006189d0  CVOGHBSkill_Common_SpawnPerTargetHB_Inferred  [OWN R12-040]
         └─ Rng_CloneSeededTable_Inferred (0x0058ab60)
         └─ FUN_00589b80 chance gate
         └─ CVOGReaction_ResolveObjectTarget (world+0xe4e8)
         └─ operator_new(0x6d0) + CVOGHBSkill_Common_ctor (flag 0, scale 1.0f)
         └─ CVOGHBList_Enqueue(world+0xe4ec) + CVOGHBBase_Start
         └─ events 0x14/0x15 via object vtbl+0x238

Peer patterns (other partitions — do not merge):
  CVOGHBSkill_Master_Execute              0x00614c80  (vtbl+0x2c, always ret 1)
  CVOGHBSkill_OnKill_SpawnPerTargetHB_*   0x006226a0  (vtbl+0x2c, base ctor 0x6c0)
  Skill_HB_SpawnEntities_Execute_*        0x00615020  (different class/vtbl)
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006189d0` | Port as **`CVOGHBSkill_Common` vtbl+0x2c multi-target Common HB spawn**. Six stack args, **RET 0x18**, return **bool any-started**. Chance gate + events 0x14/0x15. Child size **0x6d0** via **Common_ctor** with **flag 0 / scale 1.0f**. Resolve via **world+0xe4e8**; list **world+0xe4ec**. |
| Distinct from | Common ctor `00618180`; Master/OnKill/SpawnEntities Execute peers. |
| Pair with | dualed `CVOGHBSkill_Common_ctor` `00618180`; ResolveObjectTarget; Enqueue/Start; Rng_CloneSeededTable. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGHBSkill_Common_SpawnPerTargetHB_Inferred` @ `0x006189d0` / `aa_006189d0`.
- Correct parent note: this VA is **not** a subclass ctor; it is Common **vtbl+0x2c fanout** that *calls* the Common ctor.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-006189d0-r12-report.md` |
