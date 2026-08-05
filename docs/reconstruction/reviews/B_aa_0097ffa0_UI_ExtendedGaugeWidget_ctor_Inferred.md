# Review B (skeptical / adversarial): `aa_0097ffa0` UI_ExtendedGaugeWidget_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0097ffa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0097ffa0_UI_ExtendedGaugeWidget_ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same as `UI_DataGaugeWidget_ctor` `0097dfe0` | **Falsified** — different vtbl, larger init, 0x4f8 vs 0x4bc |
| 2 | Loads balance XML itself | **Falsified** — ctor only; CreateChildWidgets loads XML after |
| 3 | Trade-only | **Falsified** — many UI callers |
| 4 | Skips base gauge ctor | **Falsified** — always `00863f10` first |

## Surviving contract

```text
p = operator_new(0x4f8);
UI_ExtendedGaugeWidget_ctor(p);
// attach + ReloadInterface("…gauge….xml")
```

**Verdict:** **accept-with-gaps.** Accept A.
