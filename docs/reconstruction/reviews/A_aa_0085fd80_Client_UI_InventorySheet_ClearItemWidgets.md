# Review A (reconstruction fidelity): `aa_0085fd80` Client_UI_InventorySheet_ClearItemWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085fd80` |
| **VA** | `0x0085fd80` |
| **Canonical name** | `Client_UI_InventorySheet_ClearItemWidgets` (inferred) |
| **Ghidra symbol** | `FUN_0085fd80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_0085fd80_Client_UI_InventorySheet_ClearItemWidgets.md` |
| **System** | `inventory-transfer` (UI sheet) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bulk-remove inventory sheet item widgets** stored in the window's COID hash (`window+0x570`), under CNDHash traversal lock, then **recreate** the empty hash.

```text
// Custom EDI-this (sheet window); plain ret

hash = *(EDI + 0x570)             // EDI[0x15c]
if hash == 0: return

// TraversalLock hash (+0x1d):
if *(hash+0x1d): log "HashError:TraversalLock, already locked…" + VOG_DEBUG_STOP
*(hash+0x1d) = 1

cursor = 0
loop:
  // inline TraverseToNext (u64-node family):
  if !*(hash+0x1d): log "HashError:TraverseToNext, not locked…" + VOG_DEBUG_STOP
  node = (cursor==0) ? *(hash+0x14) : *(cursor+0x20)
  value = node ? *(node+0xc) : 0
  if value == 0: break
  window->vtbl[+0xbc](value)      // remove/detach widget (or free path)
  *(EDI + 0x500) -= 1             // EDI[0x140] widget counter

*(hash+0x1d) = 0
(*hash->vtbl)[+4]()               // hash clear/reset helper
CNDHash_Recreate-ish FUN_004138d0 // "HashError:Recreate…" family
```

Strings seal **HashError:TraversalLock** / **TraverseToNext** roles. Node layout matches inventory u64 CNDHash (`next +0x20`, value `+0xc`) — not the 0x1c skill TraverseToNext (`+0x14` next).

**Not** a network message. **Not** grid cell unstamp.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0085fd80_FUN_0085fd80.md` |
| Annotated | `docs/reconstruction/raw/aa_0085fd80_FUN_0085fd80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0085fd80.cpp` |
| Function record | `docs/reconstruction/functions/aa_0085fd80_FUN_0085fd80.md` |
| Live decompile | Ghidra `decompile` / `force_decompile` @ `0x0085fd80` — **A ≡ B ≡ raw** |
| Live bytes | `read_memory` @ `0x0085fd80` length 160 — `EDI+0x570`, strings, vtbl `0xbc` |
| Recreate | decompile `0x004138d0` (`HashError:Recreate, already locked…`) |
| Parent | `A_aa_00860700` RebuildItemWidgets (first step) |
| Add sibling | `A_aa_008605b0` AddItemWidget (insert into same `+0x570`) |
| Callers | `0x00860700`, `0x0088f410`, `0x009372c0` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EDI = sheet window | **High** | Offsets align Add/Rebuild (`+0x570`, `+0x500`) |
| Hash at `+0x570` (`[0x15c]`) | **High** | Bytes `8B 9F 70 05 00 00` |
| Lock byte `hash+0x1d` | **High** | String TraversalLock family |
| Walk head `hash+0x14`, next `node+0x20`, value `node+0xc` | **High** | Decompile ≡ insert u64 dual notes |
| Per-value `window vtbl+0xbc` | **High** | `FF 92 BC 00 00 00` |
| Decrement counter `+0x500` | **High** | `83 87 00 05 00 00 FF` |
| Unlock + vtbl+4 + `FUN_004138d0` | **High** | Tail sealed |
| Product English of vtbl+0xbc | **Probable** | Remove child / destroy widget |
| Name ClearItemWidgets | **Probable** | Role from rebuild position + CF |

---

## 4. Control flow: clean ≡ raw ≡ force

| Stage | Match |
|---|---|
| Null hash → return | **Yes** |
| Lock with already-locked log (continues) | **Yes** |
| Traverse all values; vtbl+0xbc; count-- | **Yes** |
| Unlock; hash vtbl+4; Recreate | **Yes** |
| Dual A≡B | **Yes** |
| No grid cell writes | **Yes** |

### ABI

| Slot | Role |
|---|---|
| **EDI** | Inventory sheet window* |
| stack | none |
| return | void (`ret`) |

---

## 5. Callers

| Caller | Role |
|---|---|
| `Client_UI_InventorySheet_RebuildItemWidgets` | Clear before re-collect/add |
| `FUN_0088f410` | Related sheet teardown/open |
| `FUN_009372c0` | Related UI path |

---

## 6. Gaps

1. Exact product name of window vtbl+0xbc.
2. Whether Recreate preserves capacity vs full free (`FUN_004138d0` body open detail).
3. Runtime widget count vs hash size after clear.
4. Class identity of sheet window (cargo/trade/locker share offsets).

**Verdict:** **accept-with-gaps** — hash drain + lock strings + counter **sealed**.
