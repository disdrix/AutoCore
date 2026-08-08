# Review B (skeptical / adversarial): `aa_005226e0` Character_SumCommodityTierMaxCapacities (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005226e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Agent** | R13-034 OWN-ONLY |
| **Counterpart** | `reviews/A_aa_005226e0_Character_SumCommodityTierMaxCapacities_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Places / mutates inventory | No stores; only CALL max + ADD | **Falsified** — pure compute |
| 2 | Pure cdecl / no this | `MOV EBX,ECX` + `MOV ECX,EBX` before CALL | **Falsified** — thiscall ECX |
| 3 | Callee cleans stack / `ret 4` here | Epilog `C3` only; pushes cleaned by **callee** `FUN_00520340` | **Falsified as ret4 on this** — this unit is **RET** |
| 4 | Pure fastcall (tier in EDX) | Tier via `PUSH ESI` only | **Falsified** |
| 5 | Same as sibling `FUN_005204f0` (0..5) | This loop: seed 0, `tier=i+1`, while `<5` → **1..5** only | **Falsified** — do not merge |
| 6 | Same as free-score `00522780` | Free-score is float used/max/score for one tier | **Falsified** |
| 7 | Same as row cost `00522710` | No FindByCoid / grid | **Falsified** |
| 8 | Same as five-row used sum `005244e0` | Different body (max sum vs multi-row used) | **Falsified** |
| 9 | Sums tiers 0..4 (0-based product) | Bytes: `LEA ESI,[EAX+1]` then compare to 5 | **Falsified** — 1..5 |
| 10 | Multiplies capacities / float score | `ADD EDI,EAX` integer only | **Falsified** — integer sum |
| 11 | Has static callers / public API | `xref_count=0`; no data ptr | **Survives as gap** — not a CF failure |
| 12 | Product name final / Runtime Confirmed | No PDB; no Launcher | **Fails** — `_Inferred`; Terminal **false** |
| 13 | Scaffold Named_CalleeOf_* | Deep chain plate | **Reject** as canonical |
| 14 | Decompiler void signature is authoritative | Analyze `undefined FUN_005226e0(void)` | **Falsified as no-this** — bytes seal thiscall |

---

## 2. Residual risks

| Risk | If wrong | Mitigation |
|---|---|---|
| Dead code (zero xrefs) | Port unused path | Still correct CF; leaf dual sealed; keep unit for family completeness |
| Product uses sibling 0..5 sum instead | Wrong total | Distinguish `005204f0` (R13-033) |
| Max leaf English / +0x599 | Wrong product story | Owned by parent dual; sum wrapper CF independent |
| Indirect call not recovered | Missed consumer | Gap only; no invented callers |

---

## 3. Confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF / loop / ABI / sole callee | **High** | Wrong port sum |
| Role as Σ max capacity | **High** | Wrong composition |
| Name English | **Open** | Registry rename later |
| Live consumers | **Open** | — |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```
// __thiscall Character* this; RET (C3); no stack args
int Character_SumCommodityTierMaxCapacities_Inferred(ch);
// sum = 0
// for tier = 1..5:
//   sum += Character_CalcCommodityTierMaxCapacity_Inferred(ch, tier)
// return sum
```

Cross-check:

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 CF ≡ clean Character_SumCommodityTierMaxCapacities_Inferred.cpp
005226e5  MOV EBX, ECX              ; this
005226f0  LEA ESI, [EAX+1]          ; tier = i+1
005226f3  PUSH ESI
005226f4  MOV ECX, EBX
005226f6  CALL 0x00520340           ; max capacity leaf
005226fb  ADD EDI, EAX              ; sum +=
005226ff  CMP EAX, 5
00522702  JL  005226f0              ; while tier < 5
00522709  RET                       ; C3
Body 42 B; pad CC; callers 0
```

Reject ports that:

- Drop thiscall / invent stack args / use `ret 4` or `ret 8` on **this** unit.
- Loop tiers 0..5 or 0..4 (sibling / off-by-one).
- Multiply, float-score, or mutate inventory.
- Merge with free-score `00522780`, row-cost `00522710`, five-row used `005244e0`, or sibling `005204f0`.
- Claim runtime Confirmed without Launcher evidence.
- Claim invented static callers.

**Verdict:** **accept-with-gaps.**
