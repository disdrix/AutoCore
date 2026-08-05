# NAMING_REGISTRY conflict scan — wave2 (Adversarial B)

| Field | Value |
|-------|-------|
| Date | 2026-07-29 |
| Role | Adversarial B — naming only |
| Source | `docs/reconstruction/NAMING_REGISTRY.md` (full file, 381 lines) |
| Scope | same-VA → two names; same name → two VAs |
| Production units | **not** rewritten |
| Registry edit | **none** (no clear same-VA conflict) |
| WORK_QUEUE / RESUME | **not** edited |

## Method

1. Parse all table rows in `NAMING_REGISTRY.md` (canonical tables, inventory/skills batches, string-literal / plate address-first batches, chain-note tables, 2026-07-29 append sections).
2. Extract `(canonical name, VA)` for code/data addresses in range **`0x00400000`–`0x02000000`** (function image VAs + `DAT_*` globals). Skip pure field offsets (`entity+0x…`, `char+0x…`) and tiny immediates (`0xC7`, packet sizes).
3. Aggregate:
   - **same-VA two names:** one VA maps to ≥2 distinct canonical names
   - **name two VAs:** one canonical name maps to ≥2 distinct VAs
4. Treat multi-row **relists of the same name at the same VA** as intentional (batch + residual sections), not conflicts.
5. Sample recent dual-related renames (2026-07-29 residual / Collect–Deliver–Interact append) for consistency with earlier registry rows.

Script scratch (not durable): `tmp/naming_conflict_scan.py`.

## Headline results

| Check | Count | Verdict |
|-------|------:|---------|
| Extracted name↔VA pairs | 243 | — |
| Unique names | 224 | — |
| Unique VAs | 224 | — |
| **Same-VA two names** | **0** | **clean** |
| **Name two VAs** | **0** | **clean** |
| Same name + same VA relisted (OK) | 15 | not conflicts |

**No clear same-VA conflict. Registry not modified.**

## Same-VA two names

**None.**

Every extracted VA maps to exactly one canonical name across all registry sections.

## Name two VAs

**None.**

Every extracted canonical name maps to exactly one VA / `DAT_*` across all registry sections.

## Intentional relists (same name, same VA — not conflicts)

These are append-only / chain-note duplicates of an already-registered binding. Binding is consistent.

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

## Sample — recent dual renames (2026-07-29)

Cross-check of residual / objective append rows against earlier skills / interact batches:

| Canonical name | VA | Status vs prior row |
|----------------|-----|---------------------|
| `CVOGObjectiveRequirement_Collect_Action` | `0x00611f20` | new unique bind |
| `CVOGObjectiveRequirement_Deliver_OnInventoryEvent_Inferred` | `0x00611290` | new unique bind |
| `CVOGObjectiveRequirement_Deliver_CargoReady_Inferred` | `0x00610f20` | new unique bind |
| `CVOGCharacter_FindActiveObjectiveIdForInteract` | `0x00524520` | matches L70 |
| `CVOGCharacter_FindActiveObjectiveIdForPick` | `0x005245d0` | matches L71 |
| `CVOGObjective_MatchTargetEvaluators` | `0x0059d9c0` | new unique bind |
| `CVOGObjective_MatchTargetEvaluators_Slot44` | `0x0059da10` | new unique bind |
| `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` | `0x004f8b80` | matches skills batch |
| `Skill_FilterTargetForResolveList_Inferred` | `0x0054ff00` | matches skills batch |
| `Skill_ApplyEffectsOnTarget_Inferred` | `0x005538a0` | matches skills batch |
| `CNDDoubleList_InvokePredicateAndRemove_Inferred` | `0x004e2600` | matches skills batch |
| `CVOGHBSkillBase_ctor` | `0x005788d0` | matches skills batch L169 |

### Supersede note (not a live conflict)

L381 notes **`CVOGHBSkillBase_ctor` supersedes** mistaken scaffold `CVOGHBSkillCast_ctor_Inferred` at `0x005788d0`. The old scaffold name is **not** retained as a second canonical row for that VA. No same-VA dual-name repair required.

Historical aliases recorded only in Notes / Aliases columns (not second canonicals):

- `FUN_00524520` / `Named_VOG_DEBUG_STOP` → canonical `CVOGCharacter_FindActiveObjectiveIdForInteract`
- `Client_RecvCompleteDynamicObjective` Notes: “was misnamed RecvObjectiveState” (distinct VA `0x0080ff00` vs true `Client_RecvObjectiveState` `0x00809460`)

## Non-findings / false positives (constants only)

A naive “any `0x…` in the row” scrape of Notes/evidence cells produces **not** naming conflicts:

| Noise | Why discarded |
|-------|----------------|
| `0x2030` appears near both `Client_QuickBarActivateSkillSlot` and `Client_RequestCastSkill` | Shared **opcode** in role notes; two distinct function VAs |
| `OPCODE_C2S_FAIL_MISSION` row also mentions `0x4e46` | Modal **case id**, not the opcode VA; constant remains `0x20B2` |
| `OPCODE_C2S_MISSION_DIALOG_RESPONSE` row also mentions `0x20` | Packet **size**, not a second opcode |

Opcode/constant multi-alias intentionally documented on one row (e.g. `OPCODE_C2S_FAIL_MISSION` aliases `OPCODE_S2C_FAIL_MISSION`, `0x20B2`) is **one value with aliases**, not two VAs for one name.

## Out of scope / limits

- Plate-driven batches in the registry are **samples**; full address maps live under `docs/reconstruction/coverage/plate_domain_rename_*.txt` and were **not** re-scanned as part of this registry-only adversarial pass.
- Field offsets (`+0x618`, etc.) are type-relative, not function VAs; not scored as same-VA conflicts.
- Ghidra symbol state vs registry not live-checked this pass (registry self-consistency only).

## Action

| Item | Action |
|------|--------|
| Same-VA two names | **None — no fix** |
| Name two VAs | **None — no fix** |
| Registry rewrite | **Skipped** (no clear same-VA conflict) |
| Production dual/units | **Not touched** |

**Adversarial B verdict:** `NAMING_REGISTRY.md` is **conflict-clean** for wave2 dual-related and full-file name↔VA bindings under the stated rules.
