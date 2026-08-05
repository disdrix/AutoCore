# Review A (reconstruction fidelity): `aa_004138d0` CNDHash_Recreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004138d0` |
| **VA** | `0x004138d0` |
| **Canonical name** | `CNDHash_Recreate` (string-sealed; inventory u64 hash family) |
| **Prior alias** | `FUN_004138d0`, `Named_VOG_DEBUG_STOP_004138d0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — rebuild nested residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004138d0_CNDHash_Recreate.md` |
| **System** | container / inventory-transfer (sheet widget hash) |
| **Live tools** | Ghidra `force_decompile`, `read_memory`, callees/callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Recreate** an inventory-family **CNDHash** table at a new power-of-two size:

```text
// Custom registers (not pure thiscall):
//   EAX = hash*
//   BL  = log2(bucket_count)  → stored at hash+0x1c; size = 1 << (BL & 0x1f)

if (*(hash+0x1d) != 0):  // traversal lock
  log "HashError:Recreate, already locked for traversal"
  log "VOG_DEBUG_STOP"
  // continue (does not abort)

CNDHash_DestroyBucketTable(hash)     // FUN_00413e20 — zero count, freelist nodes, free table
*(hash+0x1c) = BL
*(hash+8)    = 1 << (BL & 0x1f)      // provisional bucket COUNT
*(hash+0x18) = 0                     // ordered-list tail
*(hash+0x14) = 0                     // ordered-list head
CNDHash_AllocBucketTable(hash)       // FUN_00413d80 — then *(hash+8)-- → MASK
```

**Sole sealed caller in rebuild path:** `Client_UI_InventorySheet_ClearItemWidgets` (`0x0085fd80`) after walk-detach + hash vtbl+4 clear — empty hash ready for AddItemWidget reinsert.

**Not** a network path. **Not** widget destroy (caller already detached values).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `force_decompile` ≡ batch A/B |
| Entry bytes | `read_memory` `0x004138d0`: `56 8B F0` (`push esi; mov esi,eax`) then lock cmp `[esi+0x1d]` |
| Strings | `"HashError:Recreate, already locked for traversal"`, `"VOG_DEBUG_STOP"` |
| Callees | `00413e20` Destroy, `00413d80` Alloc, `007a4480` log |
| Caller | `0085fd80` ClearItemWidgets (sole) |
| Parent dual | `A_aa_0085fd80` / rebuild `A_aa_00860700` |
| Sibling insert | `A_aa_00413920_CNDHash_Insert_u64` (same lock byte +0x1d, mask at +8) |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **EAX** | hash* | entry `mov esi,eax` |
| **BL** | log2 bucket count | `mov [esi+0x1c], bl`; `shl eax,cl` with `cl=bl` |
| ECX | *not* this | no `mov esi,ecx` |
| stack | none | plain `ret` |
| return | void | — |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Lock log-only (continue) | **Yes** |
| Destroy old table | **Yes** |
| Store log2 + power-of-two count | **Yes** |
| Clear ordered list head/tail | **Yes** |
| Alloc new buckets (ends with mask = count−1) | **Yes** |

### Post-condition on `hash+8`

After full Recreate: `*(hash+8) = (1 << log2) - 1` (bit mask). Insert duals use `keyLo & *(hash+8)` — **High**.

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = hash recreate / rebucket | **High** (string + CF) |
| EAX/BL ABI | **High** (entry bytes) |
| Lock is non-fatal log | **High** |
| Nested Destroy/Alloc semantics | **High** (bodies dualled same batch) |
| Product English beyond Recreate | **Open** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps**
