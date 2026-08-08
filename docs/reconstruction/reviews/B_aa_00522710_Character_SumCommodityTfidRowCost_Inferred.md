# Review B (skeptical / adversarial): `aa_00522710` Character_SumCommodityTfidRowCost (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522710` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Agent** | WQ8R-J OWN-ONLY |
| **Counterpart** | `reviews/A_aa_00522710_Character_SumCommodityTfidRowCost_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Places / mutates inventory | No stores to grid/items | **Falsified** — pure accum |
| 2 | Decompiler signature is full ABI | Bare 2-arg, no this | **Falsified** — ECX=this; `ret 8` |
| 3 | Stack arg0 is used | Load of `[esp+0x14]` | **Falsified** — never loaded |
| 4 | Type 0x1A is "container/bag" | Enum Commodity=26 | **Falsified as container** — **Commodity** |
| 5 | Null TFID is `lo\|hi==-1` | Bytes use `lo & hi` | **Falsified as OR** — AND; still only true when both are `0xFFFFFFFF` |
| 6 | FindByCoid uses Character as this | ECX reloaded from +0x250/+0x2B0 | **Falsified** — grid this |
| 7 | Always walks all 5 slots | Early return on miss/non-commodity | **Falsified as always** |
| 8 | Cost is plain Σ capacity | Adds **slot index i** | **Survives** — odd but byte-true; do not "simplify" away |
| 9 | Subblob+0x4C8 == def+0x4C8 tier | Path is `*(def+0x3C)+0x4C8` | **Not equated** without extra proof |
| 10 | Product name final | No string/RTTI | **Gap** — `_Inferred` required |
| 11 | Scaffold Named_CalleeOf_* | Deep callee chain only | **Reject** as canonical |

---

## 2. Residual risks

| Risk | If wrong | Mitigation |
|---|---|---|
| `+0x250/+0x2B0` not always cargo | Wrong grid on non-player this | Matches invType1 pattern; only 2 callers |
| Multi-match COIDs | First-fit only (callee) | Same as FindByCoid seal |
| Subblob null | Crash on `*(def+0x3C)+0x4C8` | Retail assumes non-null commodity sub |
| Adding `i` is compiler artifact | Wrong port formula | Raw bytes `add eax,esi` — keep |

---

## 3. Confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF / formula / ABI | **High** | Cost mismatch |
| Commodity gate | **High** | Wrong type filter |
| Dead stack arg0 | **High** | Fake param use |
| Name English | **Open** | Registry rename later |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```
// __thiscall Character* this; ret 8
// stack[0] unused; stack[1] = TFID row of 5 pairs
int Character_SumCommodityTfidRowCost_Inferred(ch, unused, row);
// grid = *(*(ch+0x250)+0x2B0)
// accum=1; for i=0..4: skip null TFID; FindByCoid; require type 0x1A;
//         else return; accum += *(u8*)(*(def+0x3C)+0x4C8) + i
// return accum
```

**Verdict:** **accept-with-gaps.**
