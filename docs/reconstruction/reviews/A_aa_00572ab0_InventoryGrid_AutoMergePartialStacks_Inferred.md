# Review A (reconstruction fidelity): `aa_00572ab0` InventoryGrid_AutoMergePartialStacks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572ab0` |
| **VA** | `0x00572ab0`–`0x00572ec7` true exclusive (**1047 B**) |
| **Canonical name** | `InventoryGrid_AutoMergePartialStacks_Inferred` |
| **Ghidra name** | `FUN_00572ab0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-E) |
| **Counterpart** | `reviews/B_aa_00572ab0_InventoryGrid_AutoMergePartialStacks_Inferred.md` |
| **System** | inventory-transfer / InventoryGrid |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (prologue, mid-body, true epilogue past plate) + bulk xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Full-grid **auto-merge of underfilled stackable items**. Peers matched by **clonebase+0x34**. Max stack formula inlined (type-4 → `0x423F`, else def `+0x4BA` or 200). Fully absorbed items removed + queue-deleted. Returns dirty bool in AL. Sole caller `FUN_008c2f50` may notify via sector packet `0x204a`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W29-E) | `docs/reconstruction/raw/aa_00572ab0_FUN_00572ab0.md` |
| Annotated | `docs/reconstruction/raw/aa_00572ab0_FUN_00572ab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_AutoMergePartialStacks_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00572ab0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00572ab0_InventoryGrid_AutoMergePartialStacks_Inferred.md` |
| Max-stack peer | `aa_0040abf0` Item_CanAcceptStackQty |
| Live | decompile for loop body; **bytes** for true epilogue |

---

## 3. Signature (sealed)

```c
// __thiscall ECX=InventoryGrid*; bare RET; bool AL
uint8_t InventoryGrid_AutoMergePartialStacks_Inferred(InventoryGrid* this);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX (`8b f9`) | **High** |
| return dirty | AL (`8a 44 24 1b` then `C3`) | **High** |
| cleanup | bare `C3` (not `ret N`) | **High** |

---

## 4. Control flow fidelity

| Stage | Match | Conf |
|---|---|---|
| TraversalLock + IterateNext walk at `this+0x2c` | **Yes** | **High** |
| `Item_IsStackEligible` gate | **Yes** | **High** |
| Max-stack type4/`+0x4BA`/200 | **Yes** (bytes `be 3f 42 0f 00` / `be c8 00 00 00`) | **High** |
| Skip if qty ≥ max | **Yes** | **High** |
| Partial-map scan by `clonebase+0x34` | **Yes** | **High** |
| Residual transfer vs full absorb | **Yes** | **High** |
| Consume list + RemoveItem(1e6,1) + QueueDelete | **Yes** | **High** |
| True epilogue past Ghidra plate | **Yes** (bytes) | **High** |
| Product English name | Inferred | **Medium** |

---

## 5. Byte seals (`read_memory`)

**Prologue + early AL=0 path** @ `0x00572ab0`:
```
558bec83e4f8 … 8bf98d772c33ed3bf5 … 7515 32c0 … 8be55dc3
```

**Type-4 cap load** (multiple sites): `be 3f 42 0f 00` (MOV ESI, 0xF423F) then used as 16-bit effective **0x423F**.

**Default 200**: `be c8 00 00 00`.

**True epilogue** @ `0x00572e80`…`0x00572ec6`:
```
… 8a44241b 83c404 5f 64890d00000000 5e5d5b 8be5 5d c3
```
→ `mov al, [esp+0x1b]` dirty flag; restore ExceptionList; bare RET.

**No `disassemble_bytes` used.**

---

## 6. Gaps

1. Product C++ symbol / English method name (`_Inferred`).
2. Product meaning of sector packet `0x204a` (caller-owned).
3. Exact payload layout of partial-map value triple beyond key=item* (v1/v2 hold item* + origin packing — CF sealed, English open).
4. Full two-child erase expansion inside `StdTree_Erase_Val12` (owned elsewhere).
5. Runtime / bit-exact / differential — open.

---

## 7. Verdict

**accept-with-gaps** — merge CF, max formula, match key, ABI, and true epilogue sealed; product naming and packet semantics remain open.
