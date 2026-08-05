# Review B (skeptical / adversarial): `aa_0085fd80` Client_UI_InventorySheet_ClearItemWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085fd80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0085fd80_Client_UI_InventorySheet_ClearItemWidgets.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Clears **grid cells** / inventory model | Domain skim | **Falsified** — only hash widgets + counter |
| 2 | Uses skill TraverseToNext `0x00411900` body (next+0x14) | String family | **Falsified** — inlined walk uses **next+0x20**, value **+0xc** |
| 3 | Already-locked aborts clear | Fatal lock | **Falsified** — logs then **continues** with lock=1 |
| 4 | Is List_TraversalLock list family | List vs Hash | **Falsified** — CNDHash `+0x1d` lock, not list `+0x28` |
| 5 | ECX thiscall | ABI | **Falsified** — **EDI** window (unaff_EDI) |
| 6 | Leaves hash full of stale nodes | Skip recreate | **Falsified** — vtbl+4 + `FUN_004138d0` after unlock |
| 7 | Name string-proven | Inflation | **Not sealed** — role Probable |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI window + hash `+0x570` | **High** | Wrong container |
| u64 node walk offsets | **High** | Skip/double free |
| vtbl+0xbc per value | **High** | Leak widgets |
| Counter `--` at `+0x500` | **High** | UI badge drift |
| Soft already-locked | **High** | Port that returns early leaves stale icons |
| vtbl+0xbc English | **Med** | Doc |

---

## 3. Cross-check raw ≡ force

```text
hash = window[0x570]
if !hash: return
// lock +0x1d (log if already)
for each hash value V:
  window.vtbl[0xbc](V)
  window.widgetCount[0x500]--
unlock; hash.vtbl[4](); Recreate(hash)
```

Parent Rebuild: **Clear** → CollectPageCellKeys → AddItemWidget each → refresh.

---

## 4. Surviving contract

```
Client_UI_InventorySheet_ClearItemWidgets(window@EDI):
  drain COID hash widgets; zero logical count; recreate empty hash
// does not touch InventoryGrid cells
```

**Port tests:** must not use skill-hash next+0x14; must not treat as list TraversalLock; already-locked is non-fatal log.

**Verdict:** **accept-with-gaps** — model-clear and wrong-node-layout attacks **fail**.
