# Review A (reconstruction fidelity): `aa_004bc530` CNDHash_TraverseToNext_ListNext20

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc530` |
| **VA** | `0x004bc530`–`0x004bc57d` inclusive (**78 B** / `0x4E`) |
| **Canonical name** | `CNDHash_TraverseToNext_ListNext20` |
| **Ghidra name** | `FUN_004bc530` |
| **Prior scaffold** | `FUN_004bc530` / `Named_VOG_DEBUG_STOP_004bc530` |
| **Rejected misname** | `Named_VOG_DEBUG_STOP_004bc530` (assert string only) |
| **Review date** | `2026-08-05` (MEGA-029 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004bc530_CNDHash_TraverseToNext_ListNext20.md` |
| **System** | container / CNDHash (interaction-activation via parent `FUN_004bae00`) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**CNDHash ordered-list iterator step** under an already-held traversal lock, for the **node-next@+0x20 / payload@+0x0c** family:

```text
payload = CNDHash_TraverseToNext_ListNext20(hash, &cursor)
  if !hash.lockedForTraversal (+0x1d): log HashError:TraverseToNext…; // continue
  if cursor==0: cursor = hash.listHead (+0x14)
  else:         cursor = cursor->listNext (+0x20)
  return cursor ? cursor->payload (+0xc) : 0
```

Does **not** set/clear the lock, mutate membership, or touch freelist/buckets. Companion of `FUN_00402c40` (TraversalLock) and parent shell `FUN_004bae00` (lock → traverse → unlock).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw scaffold CF |
| Full body | `disassemble_function` + `read_memory` @ `0x004bc530` |
| Strings | `0x00a27c9c` TraverseToNext error; `0x00a15844` VOG_DEBUG_STOP |
| Callers | sole `FUN_004bae00` @ `0x004bae24` / `0x004bae4e` |
| Lock companion | `FUN_00402c40` (sets `+0x1d=1`) |
| Twin | dualed `CNDHash_TraverseToNext` `0x00411900` (next+0x14 / payload+8) |
| Clean | `reconstructed-exact/CNDHash_TraverseToNext_ListNext20.cpp` |

---

## 3. Signature (sealed)

```c
// ECX=hash this; stack cursor*; EAX=payload|0; RET 4
uint32_t __thiscall CNDHash_TraverseToNext_ListNext20(
    CNDHash *this,
    /* node* */ uint32_t *cursor);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → ESI (`MOV ESI,ECX`) | **Confirmed** |
| cursor | stack `[ESP+8]` after PUSH ESI | **Confirmed** |
| return | EAX = `*(node+0xc)` or 0 | **Confirmed** |
| cleanup | `RET 4` (`C2 04 00`) ×2 exits | **Confirmed** |
| callees | `FUN_007a4480` ×2 cdecl (`ADD ESP,0x10`) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Lock check `this+0x1d == 0` | `CMP byte [ESI+0x1d],0` / `JNZ` skip log | **Confirmed** |
| Dual log + fall-through | two PUSH/CALL; no early RET | **Confirmed** |
| Cursor null → seed head `this+0x14` | `MOV EAX,[ESI+0x14]` ×2 path | **Confirmed** |
| Cursor non-null → advance `node+0x20` | `MOV EAX,[EAX+0x20]` | **Confirmed** |
| Non-null node → return `node+0xc` | `MOV EAX,[EAX+0xc]` | **Confirmed** |
| Null node → `XOR EAX,EAX` | end-of-list | **Confirmed** |
| No membership / lock mutation | no stores to lock or links except cursor out | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (CNDHash iterator step) |
| External callers | **1** function, **2** UNCONDITIONAL_CALL sites |
| Site role | parent `FUN_004bae00` dual-hash walk (slots `+4` / `+8`) under TraversalLock |
| Callees | `FUN_007a4480` only |
| Shared strings | TraverseToNext HashError; VOG_DEBUG_STOP |

### Caller ABI (evidence)

| Site | ECX (hash) | After call |
|---|---|---|
| `0x004bae24` | `[ESI+4]` | `[hash+0x1d] = 0`; `RET 8` |
| `0x004bae4e` | `[ESI+8]` | `[hash+0x1d] = 0`; `RET 8` |

Parent calls `FUN_00402c40` (lock) immediately before each site.

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Product string `HashError:TraverseToNext…` | **Yes** (names the operation) |
| Shared CNDHash lock/assert family | **Yes** (`TraversalLock` companion; VOG_DEBUG_STOP) |
| Layout disambiguation vs dualed twin `00411900` | **Yes** (next+0x20 / payload+0xc) |
| Exact COList stamp / table English | **No** (offsets sealed; stamp open) |

**Decision:** promote **`CNDHash_TraverseToNext_ListNext20`**.  
Reject `Named_VOG_DEBUG_STOP_*`. Do **not** merge with `CNDHash_TraverseToNext` `0x00411900`.

---

## 7. Gaps

- Runtime / bit-exact / differential (no Launcher).
- Product stamp / exact table brand for this 0x28-node family.
- Parent shell `FUN_004bae00` residual (not OWN).
- Full sibling map (insert/remove/recreate) for this layout family.

---

## 8. Verdict

Fidelity path accepts CF/ABI/string-role with layout disambiguation sealed; residual stamp/runtime → **accept-with-gaps**.
