# Review A (reconstruction fidelity): `aa_00573040` List_PushBack_u64_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573040` |
| **VA** | `0x00573040` |
| **Canonical name** | `List_PushBack_u64_Inferred` |
| **Prior alias** | `FUN_00573040`, `Named_VOG_DEBUG_STOP_00573040` |
| **Review date** | `2026-07-29` (OWN-ONLY dual — rebuild nested residual) |
| **Counterpart** | `reviews/B_aa_00573040_List_PushBack_u64_Inferred.md` |
| **System** | container / inventory-transfer (collect-page COID list) |
| **Live tools** | Ghidra `force_decompile`, entry bytes, parent Collect dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Append a 64-bit key** (two dwords) to a thread-safe doubly-linked list under the list's critical section.

```text
// __thiscall list*, keyLo, keyHi  →  0 on success
// SEH frame LAB_009a4f00

EnterCriticalSection(list+4)          // CS at +4 (param_1+1)
if *(byte*)(list+0x28) != 0:          // param_1[10] traversal-busy
  log "VOG_DEBUG_STOP"
  throw 0x80070005                    // E_ACCESSDENIED

node = list->vtbl[+4](0, 0)           // allocate node
if node == 0: throw 0x8007000e        // E_OUTOFMEMORY

if head (list+0x1c) == 0: head = node
node+0x14 = old_tail                  // prev toward head
if old_tail: old_tail+0x10 = node     // next toward tail
node+0x08 = keyLo
node+0x0c = keyHi
count (list+0x24)++
tail (list+0x20) = node
LeaveCriticalSection
return 0
```

**Sole sealed caller:** `InventoryGrid_CollectPageCellKeys` (`0x00571260`) — insert COID only when not already in list.

Parent: `Client_UI_InventorySheet_RebuildItemWidgets` collect phase.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `force_decompile` A≡B |
| Entry | `55 8B EC` … `8B F1` (`mov esi,ecx` thiscall) |
| Parent dual | `A_aa_00571260_InventoryGrid_CollectPageCellKeys` |
| Sibling iterate | `A_aa_00413be0_List_IterateNext_u64` |
| Lock sibling | `A_aa_004294f0_List_TraversalLock` |

---

## 3. List field map (this unit)

| Offset | Index | Role |
|-------:|------:|------|
| +0 | [0] | vtbl |
| +4 | [1] | CRITICAL_SECTION start |
| +0x1c | [7] | head node* |
| +0x20 | [8] | tail node* |
| +0x24 | [9] | count |
| +0x28 | [10] | busy/lock byte (throw if set) |

Node: key `@+8/+0xc`, next `@+0x10`, prev `@+0x14` (tail-append orientation).

---

## 4. Confidence

| Claim | Conf |
|---|---|
| thiscall list; stack keyLo/keyHi | **High** |
| Tail append + count++ | **High** |
| CS enter/leave | **High** |
| Busy → E_ACCESSDENIED; OOM → E_OUTOFMEMORY | **High** |
| Returns **0** (HRESULT-style success) | **High** |
| Product name | **Inferred** |
| Node allocator vtbl+4 English | **Open** |

**Verdict:** **accept-with-gaps**
