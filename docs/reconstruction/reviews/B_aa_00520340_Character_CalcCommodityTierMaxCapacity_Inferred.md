# Review B (skeptical / adversarial): `aa_00520340` Character_CalcCommodityTierMaxCapacity (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520340` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Agent** | R12-018 OWN-ONLY |
| **Counterpart** | `reviews/A_aa_00520340_Character_CalcCommodityTierMaxCapacity_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Places / mutates inventory | No stores; only CRT floor + FPU | **Falsified** — pure compute |
| 2 | Pure cdecl / no this | Cases use `[ECX+0x599]` | **Falsified** — thiscall ECX |
| 3 | Caller cleans stack / `ret` only | All exits `C2 04 00` | **Falsified** — callee cleans 4 |
| 4 | Pure fastcall (tier in EDX) | Tier from `[EBP+8]` | **Falsified** |
| 5 | Banker's ROUND / nearby-even | Bytes: CRT floor then FISTP with **OR AH,0xC** (chop) | **Falsified as ROUND** — floor+truncate |
| 6 | ceil / round-half-up | floor IAT present | **Falsified** |
| 7 | Tier 0 is valid non-zero capacity | Switch after `tier-1`; 0 → default 0 | **Falsified** |
| 8 | Scales are 1.0 / linear tier index | Floats 3.5/2.8/2.1/1.4/0.7 | **Falsified** |
| 9 | Same as free-score `00522780` | Free-score is float used/max/score | **Falsified** — do not merge |
| 10 | Same as row cost `00522710` | No FindByCoid / grid | **Falsified** |
| 11 | Same as five-row sum `005244e0` | Different body (capacity leaf vs multi-row used sum) | **Falsified** — partition parent ≠ merge |
| 12 | Uses float level at +0x599 | `MOVZX` byte | **Falsified as float load** |
| 13 | Product name final / Runtime Confirmed | No PDB; no Launcher | **Fails** — `_Inferred`; Terminal **false** |
| 14 | Scaffold Named_CalleeOf_* | Deep chain plate | **Reject** as canonical |

---

## 2. Residual risks

| Risk | If wrong | Mitigation |
|---|---|---|
| +0x599 not "level" | Wrong product story | Still correct load site; free-score dual same byte |
| "Complexity" ≠ capacity English | Wrong registry name | Keep `_Inferred`; UI string is display only |
| Scale globals shared/repurposed | Wrong constant ownership | Per-case absolute addresses sealed |
| Negative level impossible | floor of negative | byte load → non-negative |

---

## 3. Confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF / scales / floor / ABI | **High** | Wrong port formula |
| Role as max for free-score / UI | **High** | Wrong composition |
| Name English | **Open** | Registry rename later |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```
// __thiscall Character* this; ret 4
// stack[0] = tier (1..5)
int Character_CalcCommodityTierMaxCapacity_Inferred(ch, tier);
// if tier ∉ {1..5}: return 0
// level = *(uint8_t*)(ch + 0x599)
// return (int)floor(level * {3.5,2.8,2.1,1.4,0.7}[tier])
```

Cross-check:

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean Character_CalcCommodityTierMaxCapacity_Inferred.cpp
00520349  MOV EAX, [EBP+8]          ; tier
0052034c  ADD EAX, -1
00520352  JA  005204c6              ; default 0
00520358  JMP [EAX*4 + 0x5204d0]    ; cases
0052035f  MOVZX EAX, byte [ECX+0x599]
00520370  FMUL dword [0x009da8a4]   ; 3.5f
00520379  CALL [0x009c6598]         ; floor
0052038a  OR  AH, 0xC               ; chop for FISTP
005203a3  RET 4                     ; C2 04 00
DAT scales: 3.5 / 2.8 / 2.1 / 1.4 / 0.7
```

Reject ports that:

- Drop thiscall / use `ret` without stack cleanup / use `ret 8`.
- Use ceil, nearby-even ROUND, or omit floor.
- Treat tier 0 as non-zero capacity.
- Use wrong scale table or wrong +0x599 width.
- Merge with free-score `00522780`, row-cost `00522710`, or five-row sum `005244e0`.
- Claim runtime Confirmed without Launcher evidence.

**Verdict:** **accept-with-gaps.**
