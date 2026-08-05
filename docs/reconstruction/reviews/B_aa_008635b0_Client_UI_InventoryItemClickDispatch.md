# Review B (skeptical / adversarial): `aa_008635b0` Client_UI_InventoryItemClickDispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_008635b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008635b0_Client_UI_InventoryItemClickDispatch.md` |
| **Verdict** | **needs-more-evidence** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only routes grab vs drop hardpoint | **Overstated** — customize modal + global stash imply async confirm path not fully sealed |
| 2 | `char+0xcd0` means “store cursor empty” | **Inferred label** — used as zero-check only |
| 3 | All inventory clicks go here | **Unproven** — grid grab/drop use other UI units |
| 4 | Finished exact | **Scaffold** |

---

## 2. Surviving contract

```
if no local host: noop
if no resolved item OR store UI not ready:
  if char+0xcd0==0: SendInventoryGrab_Hardpoint
else if cursor + FUN_00862860:
  maybe permanent-customize confirm
  SendInventoryDrop_Hardpoint
```

---

## 3. Open questions

Confirm callback wiring; interaction with DropToGrid/FromGrid; runtime.

**Verdict:** Routing skeleton only; do not treat as full inventory click system.
