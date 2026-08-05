# NAMING_REGISTRY conflict scan — wave3 (OWN ONLY meta)

| Field | Value |
|-------|-------|
| Date | 2026-07-29 |
| Role | Meta — naming registry conflict scan (wave3) |
| Source | `docs/reconstruction/NAMING_REGISTRY.md` (full file, **381** lines) |
| Scope | same-VA → two names; same name → two VAs |
| Production units | **not** rewritten |
| Registry edit | **none** (no clear same-VA conflict) |
| WORK_QUEUE / RESUME | **not** edited |
| Prior pass | `WAVE_2026-07-29_naming_scan_wave2.md` (same registry snapshot size; reconfirmed) |

## Method

1. Parse all table rows in `NAMING_REGISTRY.md` (canonical tables, inventory/skills batches, string-literal / plate address-first batches, chain-note tables, 2026-07-29 append sections).
2. Extract `(canonical name, VA)` for code/data addresses in range **`0x00400000`–`0x02000000`** (function image VAs + `DAT_*` globals). Skip pure field offsets (`entity+0x…`, `char+0x…`) and tiny immediates (`0xC7`, packet sizes).
3. Aggregate:
   - **same-VA two names:** one VA maps to ≥2 distinct canonical names
   - **name two VAs:** one canonical name maps to ≥2 distinct VAs (function-body VAs only; RTTI/vtable extras called out separately)
4. Treat multi-row **relists of the same name at the same VA** as intentional (batch + residual / chain notes), not conflicts.
5. Secondary column-only parser (`tmp/check_naming_registry_conflicts.py`) confirms zero primary VA conflicts and zero opcode/field conflicts.
6. Cross-check **wave3 partition map** VAs (`WAVE_2026-07-29_wave3_partition_map.md`) for accidental dual-name registration.

Script scratch (not durable): `tmp/naming_conflict_scan.py`, `tmp/check_naming_registry_conflicts.py`, `tmp/wave3_va_check.py`.

## Headline results

| Check | Count | Verdict |
|-------|------:|---------|
| Extracted name↔VA pairs (primary scanner) | 243 | — |
| Unique names | 224 | — |
| Unique VAs | 224 | — |
| Secondary parser bindings | 337 | includes field/opcode kinds |
| Unique code/data VAs (secondary) | 227 | — |
| **Same-VA two names** | **0** | **clean** |
| **Name two VAs** (function-body) | **0** | **clean** |
| Same name + same VA relisted (OK) | 15 | not conflicts |
| Opcode-constant multi-name | 0 true | noise only (see below) |
| Field parent+offset multi-name | 0 | clean |

**No clear same-VA conflict. Registry not modified.**

## Same-VA two names

**None.**

Every extracted function/data VA maps to exactly one canonical name across all registry sections.

## Name two VAs

**None** for function-body dual mapping.

### Intentional multi-address type / RTTI citations (not conflicts)

These bind **one type/ctor name** to function VA **plus** RTTI metadata addresses cited on the same row. Not two code entry points for one name.

| Canonical name | Addresses | Why OK |
|----------------|-----------|--------|
| `CVOGHBSkillBase_ctor` | fn `0x005788d0`; COL `0x00aaede0`; type_info `0x00af8cec` | Residual row cites RTTI evidence next to ctor VA |
| `CVOGObjectiveRequirement_Collect` | RTTI `0x00afe9ac`; vtable `0x009e12c4` | Type row: RTTI + vtable pair |

## Intentional relists (same name, same VA — not conflicts)

Append-only / chain-note / residual duplicates of an already-registered binding. Binding is consistent.

| Canonical name | VA | Sample lines |
|----------------|-----|--------------|
| `pendingAbandonMissionId` | `DAT_00d1b4b4` | 53, 98, 109 |
| `Client_UiModalDispatch` | `0x00911840` | 51, 99 |
| `Client_RecvFailMission` | `0x0080b100` | 52, 100, 113 |
| `CVOGReaction_FailMission` | `0x0052da30` | 33, 114 |
| `Client_InteractClickPickTarget` | `0x009247b0` | 68, 120 |
| `Client_SendUseObject` | `0x00916740` | 66, 122 |
| `Client_SendUseObject_IfInteractable` | `0x00930d70` | 67, 123 |
| `Client_UpdateNpcInteractIcons` | `0x0091b8d0` | 69, 129 |
| `CVOGCharacter_FindActiveObjectiveIdForInteract` | `0x00524520` | 70, 125, 368 |
| `CVOGCharacter_FindActiveObjectiveIdForPick` | `0x005245d0` | 71, 126, 369 |
| `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` | `0x004f8b80` | 173, 377 |
| `Skill_FilterTargetForResolveList_Inferred` | `0x0054ff00` | 170, 378 |
| `Skill_ApplyEffectsOnTarget_Inferred` | `0x005538a0` | 172, 379 |
| `CNDDoubleList_InvokePredicateAndRemove_Inferred` | `0x004e2600` | 174, 380 |
| `CVOGHBSkillBase_ctor` | `0x005788d0` | 169, 381 |

## Wave3 partition VA cross-check

Against `WAVE_2026-07-29_wave3_partition_map.md` work targets: registry mentions that exist are **single-name**; most targets are **not yet registered** (expected — dual work in progress).

| VA | Registry status |
|----|-----------------|
| `0x008ab8f0` | single: `Client_MissionDialog_FlushPreparedResponse` |
| `0x0092ce90` | single: `Client_RefreshMissionRelatedUi` |
| `0x0093bac0` | single: `Client_PromptSkillTargetSelect` |
| `0x0059d880` | mention only in EvaluatePending notes as `FUN_0059d880` (CompleteCount load) — **not** a second canonical row for another name |
| Remaining wave3 partition VAs | **0** registry hits |

No same-VA dual-name introduced by wave3 targets.

## Non-findings / false positives (constants only)

A naive “any `0x…` in the row” scrape of Notes/evidence cells produces **not** naming conflicts:

| Noise | Why discarded |
|-------|----------------|
| `0x2030` appears near both `Client_QuickBarActivateSkillSlot` and `Client_RequestCastSkill` | Shared **opcode** in role notes; two distinct function VAs |
| `OPCODE_C2S_FAIL_MISSION` row also mentions `0x4e46` | Modal **case id**, not the opcode VA; constant remains `0x20B2` |
| `OPCODE_C2S_MISSION_DIALOG_RESPONSE` row also mentions `0x20` | Packet **size**, not a second opcode |

Opcode/constant multi-alias on one row (e.g. `OPCODE_C2S_FAIL_MISSION` aliases `OPCODE_S2C_FAIL_MISSION`, `0x20B2`) is **one value with aliases**, not two VAs for one name.

### Supersede / alias notes (not live duals)

- L381: `CVOGHBSkillBase_ctor` **supersedes** mistaken scaffold `CVOGHBSkillCast_ctor_Inferred` at `0x005788d0` — old scaffold is **not** a second canonical row.
- `FUN_00524520` / `Named_VOG_DEBUG_STOP` → canonical `CVOGCharacter_FindActiveObjectiveIdForInteract` (aliases only).
- `Client_RecvCompleteDynamicObjective` notes “was misnamed RecvObjectiveState” — distinct VA `0x0080ff00` vs true `Client_RecvObjectiveState` `0x00809460`.

## Out of scope / limits

- Plate-driven batches in the registry are **samples**; full address maps under `docs/reconstruction/coverage/plate_domain_rename_*.txt` were **not** re-scanned as part of this registry-only meta pass.
- Field offsets (`+0x618`, etc.) are type-relative, not function VAs; not scored as same-VA conflicts.
- Ghidra symbol state vs registry not live-checked this pass (registry self-consistency only).
- No production dual/unit rewrites.

## Action

| Item | Action |
|------|--------|
| Same-VA two names | **None — no fix** |
| Name two VAs | **None — no fix** |
| Registry rewrite | **Skipped** (no clear same-VA conflict) |
| WORK_QUEUE / RESUME | **Not edited** |
| Production dual/units | **Not touched** |

**Wave3 meta verdict:** `NAMING_REGISTRY.md` remains **conflict-clean** for same-VA dual names and name→two-function-VA bindings under the stated rules. Wave3 partition targets do not introduce registry duals.
