# Review B (skeptical / adversarial): `aa_0041a9b0` Com_Cursor_ClearSlotAndFetch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041a9b0` |
| **VA** | `0x0041a9b0` |
| **Canonical name** | `Com_Cursor_ClearSlotAndFetch_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0041a9b0_Com_Cursor_ClearSlotAndFetch_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is skill-only | Many `007d*`/`007e*` callers | **Falsified** exclusivity |
| 2 | Always binds fields | Gate `hr >= 0` | **Falsified** always-bind |
| 3 | Always clears slot | Only if `EDI+0xC != 0` | **Falsified** always-clear |
| 4 | Returns void useful status | Body `ret` after optional `0041c000`; parent compares to 0 | **Gap** — status provenance soft |
| 5 | `0041c000` fully understood | Not dualled in this batch | **Accepted residual** |

---

## 2. Surviving contract

```
cursor in EDI:
  optional clear of slot +0xC via vtbl+0x18
  hr = vtbl+0x1C(cursor, 0)
  if hr >= 0: FUN_0041c000(0, 1)  // field bind
```

AutoCore skill-def ingest should model **iterate rows + bind columns**, not COM vtbl offsets.

**Verdict:** **accept-with-gaps**
