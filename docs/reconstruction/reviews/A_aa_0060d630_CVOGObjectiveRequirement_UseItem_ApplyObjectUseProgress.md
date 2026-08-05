# Review A (reconstruction fidelity): `aa_0060d630` CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d630` |
| **VA** | `0x0060d630` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress` |
| **Review date** | `2026-08-04` (WQ7R-H dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060d630_CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress.md` |
| **System** | missions-progression |
| **Scratch** | `tmp/a_0060d630.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

UseItem requirement **apply** on matched object-use (events 9/10 via `FUN_0060df70`): if local and not yet eval-complete, optional give @+0x28, **progress slot += 1.0**, re-eval; optional inventory remove / world destroy; on complete **GiveMission(@+0x4c)** + give @+0x48.

WQ-007 residual: **caller of `CVOGReaction_GiveMission`**.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra HTTP `decompile_function(0x0060d630)` 2026-08-04 |
| Entry/exit image | `read_memory` @`0x0060d630` / `@0x0060d7d0` → `ret 0x0C`, AL 0/1 |
| Callers | `get_function_callers` → sole `FUN_0060df70` |
| Callees | GiveMission, RemoveInventoryItem, FUN_005310a0, FUN_007a4480, FUN_004d0e90 |
| RTTI | vtable `009dfc1c` COL→`.?AVCVOGObjectiveRequirement_UseItem@@` |
| Sibling duals | UseItem_Eval / InitActive / MatchTargetCore |
| Raw / clean / record | `raw/`, `reconstructed-exact/`, `functions/aa_0060d630_*` |

**Not performed:** `disassemble_bytes`; Launcher runtime.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range + `ret 0x0C` + AL bool | **High** | image epilogue |
| Class UseItem | **High** | RTTI + sibling vtable map |
| Sole caller `FUN_0060df70` events 9/10 | **High** | callers + decompile |
| Local gate `+0x7e` | **High** | same family as InitActive |
| Slot index byte @req+0x08; += 1.0 | **High** | Eval twin uses same formula |
| GiveMission when re-eval true + id≠−1 | **High** | direct call |
| Fail-give log string @`0x009e00a0` | **High** | xrefs only this + InitActive |
| World-object destroy via third arg | **Probable** | decompiler `unaff_EBX` hole |
| Product English for all flags @+0x1c..+0x32 | **Tentative** | pattern-matched |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Local / eval-done / host-payload early outs | **Yes** |
| Give @+0x28 + log | **Yes** |
| Slot += 1 + re-eval | **Yes** |
| Remove/destroy arms | **Yes** (object ptr residual) |
| GiveMission + give @+0x48 | **Yes** |
| return 1 success path | **Yes** |

---

## 5. Gaps

1. `unaff_EBX` → seal world-object register from image mid-body.
2. Event 9 vs 10 product meaning.
3. `FUN_005310a0` full inventory authority story.
4. Runtime observation.

**Verdict:** **accept-with-gaps** — CF + GiveMission residual + UseItem identity sealed; object-ptr local + flag English residual.
