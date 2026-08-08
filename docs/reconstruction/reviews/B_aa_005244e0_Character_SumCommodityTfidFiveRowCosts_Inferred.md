# Review B (skeptical / adversarial): `aa_005244e0` Character_SumCommodityTfidFiveRowCosts (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005244e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Agent** | R11-001 OWN-ONLY |
| **Counterpart** | `reviews/A_aa_005244e0_Character_SumCommodityTfidFiveRowCosts_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Places / mutates inventory | No stores; only calls dualed read-only cost leaf | **Falsified** — pure accum |
| 2 | Decompiler signature is full ABI | Bare `int(uint*)`, no this | **Falsified** — ECX=this (`mov ebp,ecx`); **`ret 4`** |
| 3 | Pure cdecl / caller cleans | `C2 04 00` | **Falsified** — callee cleans 4 bytes |
| 4 | Pure fastcall / two register args | Table from stack `[esp+0x14]` | **Falsified** |
| 5 | Always calls cost for all 5 rows | Head-null `jz` skips call | **Falsified as always** — null head contributes **0** (not base-1) |
| 6 | Null TFID is `lo \| hi == -1` | Bytes use `AND` | **Falsified as OR** — AND; still only true when both are `0xFFFFFFFF` |
| 7 | Stride is 8 B (one TFID) or 5 dwords | `ADD EDI, 0x28` | **Falsified** — **40 B** per row |
| 8 | Outer rowIndex drives cost weight | Callee dual: stack arg0 **dead**; weight uses **slot index within row** | **Falsified as outer-index weight** — push is still present |
| 9 | Same as free-score sibling `00522780` | Different body (sum ints vs float free formula) | **Falsified** — do not merge |
| 10 | Same as single-row `00522710` | Wrapper only; no FindByCoid / type gate here | **Falsified** — multi-row driver |
| 11 | Sum starts at 1 | `XOR EBX,EBX` | **Falsified** — starts at **0** (per-row base-1 only when callee runs) |
| 12 | Product name final | No string/RTTI | **Gap** — `_Inferred` required |
| 13 | Runtime Confirmed | No Launcher | **Fails** — Terminal **false** |
| 14 | Scaffold Named_CalleeOf_* | Deep chain plate | **Reject** as canonical |

---

## 2. Residual risks

| Risk | If wrong | Mitigation |
|---|---|---|
| No live callers | Dead code or indirect call only | Document gap; CF still sealed |
| Outer 5 ≠ tiers 1..5 | Wrong product mapping | Body has no tier id; only indices 0..4 |
| Table not Character-owned | Wrong ownership story | thiscall this still required for cargo grid inside callee |
| Callee changes | Cost formula drift | Parent dual sealed 2026-08-04 |

---

## 3. Confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF / stride / null gate / ABI | **High** | Wrong port loop |
| Callee wiring | **High** | Wrong cost composition |
| Name English | **Open** | Registry rename later |
| Callers | **Open** | Dead-code risk |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```
// __thiscall Character* this; ret 4
// stack[0] = table of 5 rows × 0x28 (each row 5 TFID pairs)
int Character_SumCommodityTfidFiveRowCosts_Inferred(ch, table);
// sum=0; for i=0..4:
//   row = table + i*10 dwords
//   if (row[0] & row[1]) == 0xFFFFFFFF: continue
//   sum += Character_SumCommodityTfidRowCost_Inferred(ch, i, row)
// return sum
```

Cross-check:

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean Character_SumCommodityTfidFiveRowCosts_Inferred.cpp
005244ea  MOV EBP, ECX
005244fe  CALL 00522710          ; E8 0D E2 FF FF
00524508  ADD EDI, 0x28
00524516  RET 4                  ; C2 04 00
```

Reject ports that:

- Drop thiscall / use `ret` without stack cleanup / use `ret 8`.
- Always invoke the row cost (including null-head rows).
- Use OR for null TFID, or stride ≠ 0x28, or loop count ≠ 5.
- Treat outer rowIndex as the cost weight inside the row formula.
- Merge with free-score `00522780` or single-row `00522710`.
- Claim runtime Confirmed without Launcher evidence.

**Verdict:** **accept-with-gaps.**
