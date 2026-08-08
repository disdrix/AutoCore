# Review B (skeptical / adversarial): `aa_005204f0` Character_SumCommodityTierMaxCapacities (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005204f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Agent** | R13-033 OWN-ONLY |
| **Counterpart** | `reviews/A_aa_005204f0_Character_SumCommodityTierMaxCapacities_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Places / mutates inventory | No stores; only CALL parent + ADD | **Falsified** — pure compute |
| 2 | Pure cdecl / no this | `MOV EBX,ECX` + `MOV ECX,EBX` before CALL | **Falsified** — thiscall ECX |
| 3 | Same ABI as parent (`ret 4`) | Exit is `C3` not `C2 04 00`; no entry stack args | **Falsified** — ret 0 |
| 4 | Pure fastcall (tier in EDX) | Tier from ESI, pushed to stack for parent | **Falsified** |
| 5 | Loop is tiers 1..5 only | ESI starts 0; bound `< 6` (CMP ESI,6) | **Falsified** — includes tier 0 |
| 6 | Tier 0 contributes non-zero | Parent default for tier∉1..5 is 0 (dualed R12-018) | **Falsified** as non-zero |
| 7 | Same plate as sibling `005226e0` | Sibling starts tier=1, bound `<5`; different CF | **Falsified** — do not merge |
| 8 | Same as free-score `00522780` | Free-score is float used/max/score for **one** tier | **Falsified** |
| 9 | Same as five-row used sum `005244e0` | That sums **used costs**, not max capacities | **Falsified** |
| 10 | Same as single-tier max `00520340` | This is a **wrapper sum**, parent is leaf formula | **Falsified** — do not merge |
| 11 | Decompiler `void`/no-this surface is ABI | Bytes prove ECX this + int return via EDI→EAX | **Falsified as void/cdecl** |
| 12 | Has static callers (must be live) | xrefs + LE data-ptr search empty | **Fails as proven-live** — orphan residual |
| 13 | Product name final / Runtime Confirmed | No PDB; no Launcher | **Fails** — `_Inferred`; Terminal **false** |
| 14 | Scaffold bare `FUN_*` is enough | Dual requires named Inferred plate | **Reject** as final registry name without `_Inferred` |

---

## 2. Residual risks

| Risk | If wrong | Mitigation |
|---|---|---|
| Orphan = dead code | Port unused | Still correct CF; pair with sibling 1..5 sum when wiring product |
| Dynamic dispatch missed | Missing call-site story | `search_byte_patterns` LE ptr empty; re-scan if new tables found |
| Parent English wrong | Wrong aggregate story | Parent dual sealed formula; this only sums |
| Someone merges with `005226e0` | Duplicate plate / wrong loop | Keep distinct names; document 0..5 vs 1..5 |

---

## 3. Confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF / bound 6 / thiscall / ret 0 | **High** | Wrong port loop/ABI |
| Role as Σ max capacities | **High** | Wrong composition |
| Effective ≡ sibling 1..5 total | **High** (math) | — |
| Name English | **Open** | Registry rename later |
| Liveness / callers | **Open** | Dead-code prune decision |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```
// __thiscall Character* this; ret 0
// no stack args
int Character_SumCommodityTierMaxCapacities_Inferred(ch);
// sum = 0
// for tier in 0..5: sum += Character_CalcCommodityTierMaxCapacity_Inferred(ch, tier)
// return sum
// (tier 0 always 0 via parent default)
```

Cross-check:

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean Character_SumCommodityTierMaxCapacities_Inferred.cpp
005204f5  MOV EBX, ECX            ; this
005204f7  XOR ESI, ESI            ; tier = 0
00520500  PUSH ESI                ; tier arg
00520501  MOV ECX, EBX
00520503  CALL FUN_00520340       ; max for tier
00520508  ADD ESI, 1
0052050b  ADD EDI, EAX            ; sum
0052050d  CMP ESI, 6
00520510  JL  00520500
00520517  RET                     ; C3
body 40 B @ 0x005204f0–0x00520517
```

Reject ports that:

- Drop thiscall / invent stack args / use `ret 4`.
- Loop only 1..5 and claim this VA (that is `005226e0`).
- Claim tier 0 is a valid non-zero capacity contribution without parent evidence.
- Merge with free-score `00522780`, row-cost `00522710`, five-row used sum `005244e0`, or single-tier max `00520340`.
- Claim runtime Confirmed without Launcher evidence.
- Claim static callers exist without new xref evidence.

**Verdict:** **accept-with-gaps.**
