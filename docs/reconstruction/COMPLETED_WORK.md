# Completed Work

Entries are append-only. Incomplete or partially verified units stay in `WORK_QUEUE.md` / `ACTIVE_WORK.md`.

---

## Partial — FindActiveObjectiveIdForPick (2026-07-29)

| Field | Value |
|-------|-------|
| Units | `aa_005245d0` / `0x005245d0` `CVOGCharacter_FindActiveObjectiveIdForPick` |
| Duals | A/B accept-with-gaps; three-rep; Ghidra rename |
| Contrast | Sibling `aa_00524520` (+0x40); this unit `FUN_0059da10` (+0x44) |
| Not complete | Runtime; +0x44 implementers; character ECX per site |

---

## Partial — Collect_Action + Deliver + FindActiveObjectiveId (2026-07-29)

| Field | Value |
|-------|-------|
| Units | `aa_00611f20` Collect_Action; `aa_00611290`/`aa_00610f20` Deliver cargo; `aa_00524520` FindActiveObjectiveIdForInteract; `aa_0059d9c0` MatchTargetEvaluators |
| Duals | A/B for each |
| Tests | 65 OK recon suite |
| Not complete | Full kill-loot CF in clean (raw holds); runtime; name Inferred on Deliver |

---

## Partial — collect bridge + interaction + modal + ValidateTarget (2026-07-29 continue)

| Field | Value |
|-------|-------|
| Units | `aa_005711c0` CountItemsByCbid; `aa_00611940` Collect_Eval; `aa_00916740`/`aa_00930d70` UseObject; `aa_007fdfb0` ShowModalPrompt; `aa_00553650` ValidateTarget; grab/drop dual refresh; `aa_00536540` Prerequisites |
| Systems | inventory-transfer, missions-progression, interaction-activation, skills-abilities |
| Dual reviews | A/B for each important unit advanced |
| Tests | `inventory_collect_bridge` + mission_dialog + coverage suite |
| Not complete | Full 26k deep duals; runtime; Collect_Action; soft-steer |

---

## Partial — C2S 0x206E seal + abandon→FailMission (2026-07-29)

| Field | Value |
|-------|-------|
| Units | `aa_008ab8f0` FlushPreparedResponse; `aa_008abd70` Prepare; `aa_008ae7c0` HandleButton (fill); `aa_00911840` abandon modal slice; `aa_0052da30` FailMission; `aa_0080b100` RecvFailMission |
| System | missions-progression |
| Representations | raw + annotated + reconstructed-exact + function record for flush; abandon extract; FailMission strengthen |
| Dual reviews | A/B for flush, abandon slice, FailMission, RecvFailMission; chains `CHAIN_2026-07-29_*.md` |
| Not claimed complete | Runtime, differential, bit-exact; modal Yes/No pairing fully proven; full UiModalDispatch switch |
| Tests | `experiments/mission_dialog_c2s.py` + `test_mission_dialog_c2s.py` (17); suite 44 OK |
| Artifacts | See function records `aa_008ab8f0_*`, `aa_00911840_*`, `aa_0052da30_*` |

---

## Partial — CompleteObjective vertical (2026-07-23)

| Field | Value |
|-------|-------|
| Units | `aa_00533f90` CompleteObjective; `aa_0059dde0` ComputeObjectiveXp; `aa_0059df20` ComputeObjectiveCredits; `aa_0080ff00` RecvCompleteDynamicObjective; `aa_00809460` RecvObjectiveState |
| System | missions-progression |
| Representations | raw + annotated + reconstructed-exact + function record for each |
| Dual reviews | CompleteObjective + ComputeObjectiveXp (reconstruction accept-with-gaps; skeptical needs-more-evidence) |
| Not claimed complete | Runtime, differential, bit-exact; FUN_* callee map; table payloads; req type-3 enum |
| Artifacts | See function records under `functions/aa_00533f90_*`, `aa_0059dde0_*`, `aa_0059df20_*`, `aa_0080ff00_*`, `aa_00809460_*` |

---

## Bootstrap — durable reconstruction state (2026-07-23)

| Field | Value |
|-------|-------|
| Work | Create/populate required top-level state files and directories |
| Result | `PROJECT_STATE`, queue, registries, matrix, resume, architecture index |
| Prior art | `physics/**` preserved and indexed; not erased |
| Status | Done for bootstrap scope |

---

## Partial — input-drive-control map + SetSteerInput unit (2026-07-23)

| Field | Value |
|-------|-------|
| IDs | WQ-001 (map partial), WQ-002 (unit partial after reviews) |
| System map | `systems/input-drive-control.md` |
| Unit | `aa_004f5620` |
| Representations | raw + annotated + reconstructed-exact + function record |
| Reviews | `reviews/aa_004f5620_reconstruction_review.md` (accept-with-gaps); `reviews/aa_004f5620_skeptical_review.md` (needs-more-evidence on full package) |
| Experiments | `experiments/vehicle_entity_set_steer_input.py` + unittest |
| Not claimed complete | Runtime, differential, full DriveControlTick, wobj type, suppress-bit meanings |
| Post-review fixes | Suppress naming (not lock); sign convention caller-only; UF-006..008 |
