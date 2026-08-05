# Review A (reconstruction fidelity): `aa_004022a0` List_IterateNext

| Field | Value |
|---|---|
| **Stable ID** | `aa_004022a0` |
| **VA** | `0x004022a0` |
| **Canonical name** | `List_IterateNext` (registry) |
| **Ghidra symbol** | `FUN_004022a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_004022a0_List_IterateNext.md` |
| **System** | `inventory-transfer` / shared `client::list` |
| **Parent batch** | Grab/Drop/AddItem/Equip nested residual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Advance a locked list cursor by one node** under the list's critical section:

```
thiscall List_IterateNext(list* this, int* cursor, void** outPayload) → uint
```

| Return | Meaning |
|--------|---------|
| `0` | Node available: `*cursor` advanced, `*outPayload` = node payload (`node+4`) |
| `1` | Exhausted (or empty start): cursor/payload cleared or start-empty |
| `0x80070005` | Not traversal-locked (`list+0x28==0`) **or** `TryEnterCriticalSection` failed |

Companion: `List_TraversalLock` (`0x004294f0`) sets `+0x28` and holds CS. This unit **re-enters CS via TryEnter**, walks `node+8` next, **LeaveCriticalSection** each success path.

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | Ghidra `batch_decompile` `0x004022a0` (2026-07-29) ≡ raw |
| Live bytes | `read_memory` @ `0x004022a0` — SEH prologue + `list+0x28` gate |
| Raw / clean / function record | `raw/aa_004022a0_*`, `reconstructed-exact/FUN_004022a0.cpp`, `functions/aa_004022a0_*` |
| Registry | `NAMING_REGISTRY.md` → `List_IterateNext` |
| Callers (inventory) | `InventoryGrid_FindItemByCoid` `0x00571010`, `Inv_lootpickup` `0x00945540`, many grid/UI walks |
| Sibling lock | dual `A_aa_004294f0_List_TraversalLock` |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| SEH frame (`LAB_009bc110`) | **Yes** |
| Require `*(list+0x28) != 0` else `0x80070005` | **Yes** |
| `TryEnterCriticalSection(list+4)` fail → `0x80070005` | **Yes** |
| `*cursor==0` (start): set cursor=`list+0x1c` head, payload=`head+4` or 0; return `(head==0)` | **Yes** |
| Else next = `*cursor+8`; if non-null: advance cursor, payload=`next+4`, return `0` | **Yes** |
| Else clear cursor/payload, return `1` (end) | **Yes** |
| Leave CS on all success paths | **Yes** |
| No membership mutation | **Yes** |

### Layout (sealed offsets)

| Off | Role |
|----:|------|
| `list+4` | `CRITICAL_SECTION` |
| `list+0x1c` | head node ptr |
| `list+0x28` | traversal-lock flag (must be set) |
| `node+4` | payload out |
| `node+8` | next node |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Role = iterate-next under TraversalLock | **High** (registry + callers + CF) |
| Return codes 0 / 1 / `0x80070005` | **High** |
| Node layout `+4` payload / `+8` next | **High** |
| Inventory find-by-COID / loot walks depend on this | **High** |
| Product English name of list class | **Open** |
| Runtime / bit-exact | **Open** |

---

## 5. Gaps

1. Full product type name of list manager.
2. Why TryEnter (vs rely on lock already held) — re-entrancy / timeout policy open.
3. Runtime golden walk.

**Verdict:** **accept-with-gaps** — shared list iterator leaf for cargo walks sealed.
