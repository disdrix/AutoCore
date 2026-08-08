# Review B (skeptical / adversarial): `aa_00522780` Character_CalcCommodityTierFreeScore (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522780` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Agent** | R10-036 OWN-ONLY |
| **Counterpart** | `reviews/A_aa_00522780_Character_CalcCommodityTierFreeScore_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Mutates inventory / places items | No stores to grids/items; pure FPU return | **Falsified** — read-only score |
| 2 | Decompiler drops thiscall | `mov esi,ecx`; callees reloaded with ECX=this; `ret 8` | **Falsified as cdecl** — **thiscall+ret8** |
| 3 | Returns void / int | Dual exit `fld`/`fmul` float paths | **Falsified** — float score |
| 4 | Formula is `free` alone | Bytes: `level*scale + (base + free*2)` then `*0.01` | **Survives** — composite score |
| 5 | `base + free*2` is compiler noise | `lea eax,[ecx+eax*2]` then `fiadd` | **Survives** — keep exact |
| 6 | Scales are inventable product names only | `read_memory` IEEE values sealed | **Values sealed**; English labels open |
| 7 | `DAT_00a0f718` is steer-only constant | Same 0.01 float reused elsewhere | **Shared global**; role here = final score scale |
| 8 | `FUN_00520340` is “used” not max | Called after cost sum; `max - used`; js if negative | **Survives as max** (name still open) |
| 9 | Multiple callers / public API | Single xref `FUN_00522860` | **Survives** — private worker |
| 10 | Product name final | No string/RTTI on body | **Gap** — `_Inferred` required |
| 11 | Scaffold Named_CalleeOf_* | Mission-UI chain label only | **Reject** as canonical |

---

## 2. Residual risks

| Risk | If wrong | Mitigation |
|---|---|---|
| `+0x599` not character level | Wrong level term | Shared with `FUN_00520340` case loads; high CF |
| Max helper semantics misnamed | Port confusion | Keep `FUN_00520340` until dualed; formula still sealed |
| Score product meaning (UI weight vs craft) | Wrong feature name | `_Inferred` + gaps; do not invent product plate |
| x87 vs SSE intermediate rounding | Bit-exact float mismatch | Terminal false; CF sealed |

---

## 3. Confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF / formula / ABI | **High** | Score mismatch |
| Tier tables | **High** | Wrong base/scale |
| Parent used cost | **High** | Wrong free |
| Name English | **Open** | Registry rename later |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```
// __thiscall Character* this; ret 8
// stack[0] = tier 1..5; stack[1] = TFID row (5 pairs)
float Character_CalcCommodityTierFreeScore_Inferred(ch, tier, row);
// used = SumCommodityTfidRowCost(ch, tier, row)
// max  = FUN_00520340(ch, tier)
// free = max - used; if free < 0 or tier∉1..5 → 0
// return ( *(u8*)(ch+0x599) * scale[tier] + (base[tier] + free*2) ) * 0.01f
// base = {50,40,30,20,10}; scale = {2.5,2.0,1.5,1.0,0.5}
```

**Verdict:** **accept-with-gaps.**
