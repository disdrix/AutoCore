# Review B (skeptical / adversarial): `aa_00525cc0` Vehicle_SetActivePowerSlot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00525cc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00525cc0_Vehicle_SetActivePowerSlot_Inferred.md` |
| **Verdict** | **accept-with-gaps** on slot domain +0xD64 + force gate; **reject** overclaims on cast result product meanings, sealed rank args, and retail “PowerSlot” name |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Accepts any int slot | Reject outside [-1,2] | **Falsified unbounded** |
| 2 | Same-slot always no-ops | force==1 re-runs path | **Falsified absolute no-op** |
| 3 | Always casts on set | Continent +0x7e==0 stores without cast | **Falsified** |
| 4 | Missing skill → reject | Returns 1 without store failure | **Falsified as hard fail** |
| 5 | Cast codes fully product-named | 0 / 0x11 only machine-sealed | **Hold** |
| 6 | Decompiler `unaff_DI` is real API | Classic Ghidra junk register | **Do not trust** without asm |
| 7 | Retail PowerSlot name | No string | **Hold `_Inferred`** |
| 8 | Bit-exact sealed | Residual cast paths | **Fail** complete |

---

## 2. Surviving contract

```
Active slot index lives at vehicle+0xD64 ∈ {-1,0,1,2}.
Set transitions may tear down / cast skills when world gate +0x7e set.
force=1 re-applies even if slot unchanged.
```

**Verdict:** **accept-with-gaps**
