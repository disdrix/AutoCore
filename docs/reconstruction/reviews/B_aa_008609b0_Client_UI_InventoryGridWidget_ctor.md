# Review B (skeptical / adversarial): `aa_008609b0` Client_UI_InventoryGridWidget_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_008609b0` |
| **VA** | `0x008609b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008609b0_Client_UI_InventoryGridWidget_ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Rebuilds item widgets | **Falsified** | That is `FUN_00860700` after XML bind |
| 2 | Sets owner inventory | **Falsified** | Trade sets `+0x56c` after return; ctor zeros it |
| 3 | Base NDUI only | **Falsified** | Calls container `FUN_00792d20`, then grid vtbl |
| 4 | Network grab/drop | **Falsified** | No packet helpers |
| 5 | Shared with sheet rebuild entry | **Falsified** | Different VA; rebuild dual already sealed |

---

## 2. Surviving contract

```
grid = InventoryGridWidget_ctor(mem 0x578):
  container base ctor
  grid vtbl + zero bind/flags
  return
// caller: bind inv*, load XML, RebuildItemWidgets, optional SetOwnerFlag
```

**Verdict:** **accept-with-gaps**
