# Unresolved Findings

| ID | Finding | Related | Severity | Status |
|----|---------|---------|----------|--------|
| UF-001 | Exact type/class of drive-axis gate object at pointer chain unknown | aa_004f5620 | Medium | open |
| UF-002 | Individual meanings of bits in suppress flags `0xC7` mask unknown; "lock" label unproven | aa_004f5620 | Medium | open |
| UF-003 | Full semantic map of DriveControlTick camera/skill/airborne branches incomplete | aa_009223b0 | Low–Med | **partial** — camera look locals vs steer **sealed High** 2026-07-29 strengthen (storage/gate/domain/consumer + bind matrix; dual `*_camera_refresh`); skills/airborne/component names/mode-table semantics still open |
| UF-004 | Threading model for input tick not verified | input-drive-control | Low | open |
| UF-005 | Whether any caller bypasses setters with direct +0x618 stores without gate | input-drive-control | Med | open (NPC proportional path noted as inlining gate in prior notes) |
| UF-006 | Soft L/R polarity vs hard L/R: SoftL DAT→-0.5 SoftR→+0.5 inverts hard L=+1 R=-1 if ActionMap labels match DATs | aa_009223b0 | Medium | **body sealed High 2026-07-29** (decompile + image push `0x00922c48`/`0x00922cf8`); **label residual open** — bind/runtime; do not invent fix |
| UF-007 | NPC drive-controller inline gate parenthesization may differ from SetSteerInput three-load chain | aa_004fc650 vs aa_004f5620 | Medium | **sealed High (static) 2026-07-29** — live decompile both: identical three-load `*(*(*(this+4)+4)+0xb0+this)`; expanded bits `1\|2\|4\|0x40\|0x80` ≡ mask `0xC7`; form-only (AND-of-clears vs masked cmp). Dual A/B + function record strengthened. Residual type/bits remain UF-001/UF-002 |
| UF-008 | Intermediate nulls on p0/p1 not handled (fault) — only final wobj null is allow path | aa_004f5620 | Low | documented |
| UF-009 | FUN_007fdfb0 Yes/No button id assignment for abandon modal (prompt 0x4e47 vs confirm 0x4e46) not fully proved | aa_007fdfb0 / aa_008ae7c0 / aa_00911840 | Medium | **sealed High (2026-07-29)** — open-site `MOV EAX,0x4e46` + stack `0x4e47`; store `+0x498`/`+0x49c`; dispatch cases match. Widget bind also **High**: `CNDUICtrlButton` OK/Cancel on `CDlgPopup` (`+0x550`/`+0x554`, code `@button+0xec`) — `reviews/a_007fdfb0.md` |
| UF-010 | Exact UI lifecycle that invokes FlushPreparedResponse vtable slot — HideMissionDialogIfOpen does not call it; only DATA vtable xref `0x00a4a95c` | aa_008ab8f0 | Medium | **sealed High (static) wave3** — invoker `FUN_007fca10` → visible `vtbl+0x3d8` → `vtbl+0x440` → Flush `0x008ab8f0`; callers `FUN_008aec40` (`0x9c40` close + response success) / `FUN_008af020`; Hide uses `+0x107c` not Flush. Runtime still open |
| UF-011 | Whether cancel-close clears dialog+0x650 before flush (stale 0x206E risk) | aa_008ab8f0 | Medium | **sealed High (static) 2026-07-29** — Flush does **not** clear `+0x650` after send; cancel `0x9c40` → `FUN_007fca10` → Flush with **no** pre-clear; Prepare-on-show leaves `0x206E`; close can emit **unfilled** body. Dual A/B residual + function record. Residual: runtime wire capture / server tolerance only |
| UF-012 | Client_RecvFailMission opcode dispatch case not re-sealed this run | aa_0080b100 | Medium | **sealed High (2026-07-29 dual residual)** — sole xref `0x00815d97` case `0x20b2`; call site `MOV EAX,ESI; MOV ECX,EBP`; full body image: FailMission thiscall + return ignored; `FUN_005307e0` thiscall; missionId `[EAX+0x10]`; EAX clobber after FailMission; UI `POP EDI; JMP [vtbl+0x448]`. Remaining (out of framing): `FUN_005307e0` product dual / `DAT_00d1ad10`/`FUN_0092fd00` semantics / runtime |
| UF-013 | CHAIN_2026-07-29_s2c_2031 residual still lists `0x005538a0` product name open | aa_00811170 / skills-abilities | Low | **closed 2026-07-29 wave2** — chain now prefers `Skill_ApplyEffectsOnTarget_Inferred`; PDB product still open |
| UF-014 | Dual A_aa_005711c0 callers still label `0x00611290` as “Collect type-4” | aa_005711c0 vs inventory_collect chain | Medium | **sealed High (2026-07-29)** — dual A/B + residual `a_005711c0` + function record callers rewritten: Deliver OnInventoryEvent (req type 3 / event type 4), not Collect; name remains `CVOGObjectiveRequirement_Deliver_OnInventoryEvent_Inferred` |
| UF-015 | missions-progression open Q / next-work still list UF-009 pairing Probable and full 0x206E packing open | missions-progression vs CHAIN 206e + abandon | Medium | **closed 2026-07-29 wave2** — next-work abandon line High UF-009; residual runtime only; Prepare+Flush sealed |
| UF-016 | CHANGE_LOG 0x206E/abandon seal bullet residual “modal Yes/No pairing Probable” | CHANGE_LOG vs UF-009 | Low | **closed 2026-07-29 wave2** — top CHANGE_LOG note supersedes stale Probable bullets |
| UF-017 | HandleButton dual residual still open on abandon e2e and state-2 modal code only `0x4e47` | aa_008ae7c0 vs abandon chain / aa_007fdfb0 | Medium | **closed 2026-07-29 (static, dual A+B + function record)** — open-site `MOV EAX,0x4e46` + stack `0x4e47`; e2e pointer `CHAIN_2026-07-29_abandon_failmission.md`; residual **runtime only** |

## Contradiction log

| ID | Item | Status |
|----|------|--------|
| CX-001 | Soft-band polarity vs hard steer labels | Open residual (UF-006); body ±0.5 sealed; not a SetSteerInput body bug |
| CX-002 | drive-controller-spec inline wobj chain vs SetSteerInput three loads | **Resolved** (UF-007 sealed); prefer live three-load form; loose `+4+this+0xb0` notes are doc ambiguity not binary fork |
| CX-003 | CHAIN s2c_2031 “FUN_005538a0 name open” vs dual/map `_Inferred` rename | **Resolved** (UF-013 closed); prefer dual/map `_Inferred` |
| CX-004 | CountItems dual “Collect type-4 @ 0x00611290” vs inventory_collect Deliver correction | **Resolved** (UF-014 sealed High); duals + function record match chain: Deliver OnInventoryEvent |
| CX-005 | missions-progression / CHANGE_LOG Probable pairing tails vs UF-009 High + sealed chains | **Resolved** (UF-015, UF-016 closed) |
| CX-006 | HandleButton dual residual abandon lag vs abandon chain seal | **Resolved static** (UF-017 closed); runtime still open |

Prior physics note correction (deadband still gated via callee) is already recorded in `physics/verified/fn_004f5620_setSteerInput.md` and adopted.
