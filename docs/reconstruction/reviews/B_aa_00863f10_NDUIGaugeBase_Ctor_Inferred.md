# Review B (skeptical / adversarial): `aa_00863f10` NDUIGaugeBase_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00863f10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00863f10_NDUIGaugeBase_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Full gauge product ctor (final vtbl) | **Falsified** — subclasses overwrite vtbl (`00a62454` / `00a61e44`) |
| 2 | Allocates widget | **Falsified** — in-place ctor only |
| 3 | Parent cookie non-zero | **Falsified** — `007b5dd0(this, 0)` |
| 4 | Same size for all gauges | **Falsified** — 0x4bc vs 0x4f8 subclass extents |

## Surviving contract

```text
NDUIWindow_BaseCtor(this, 0);
*this = PTR_FUN_00a61a1c;
// seed +0x488..+0x4a4 gauge defaults
return this;
```

**Verdict:** **accept-with-gaps.** Accept A.
