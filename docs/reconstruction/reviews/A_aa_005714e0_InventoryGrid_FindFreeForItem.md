# Review A (reconstruction fidelity): `aa_005714e0` InventoryGrid_FindFreeForItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_005714e0` |
| **VA** | `0x005714e0` |
| **Canonical name** | `InventoryGrid_FindFreeForItem` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile) |
| **Counterpart** | `reviews/B_aa_005714e0_InventoryGrid_FindFreeForItem.md` |
| **Residual scratch** | `reviews/a_005714e0.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Item-aware free-space / placement-origin probe** on an inventory grid. Does **not** place or stamp cells.

Given grid `this`, an `item`, two out-bytes, optional stack-merge enable, and page index:

1. Null item → **0**.
2. Item type class **4** (`*(item+0xa8)+0x38`) → write `(0,0)`, return **1** (no footprint).
3. If `allowStackMerge`: try stack-eligible peer with capacity; on hit write **peer's** grid X/Y, return **1**.
4. Else / miss → **`InventoryGrid_FindFreeSlot`** with clonebase InvSize `(+0x406,+0x407)` and **passthrough** `pageIndex`.

**Calling convention:** MSVC `__thiscall` — grid in `ECX` (saved to `EBX`); five stack args; `ret 0x14`.

| Slot | Role | Evidence |
|------|------|----------|
| `this` (ECX) | `InventoryGrid*` | Prologue `mov ebx,ecx`; call sites `mov ecx,[…+0x2b0/+0x35c]` |
| stack0 | `Item*` | Null test; `+0xa8` type/blob |
| stack1 | `uint8_t* outX` | Written on all success paths |
| stack2 | `uint8_t* outY` | Written on all success paths |
| stack3 | `char allowStackMerge` | Gates stack block |
| stack4 | `char pageIndex` | Passed unchanged to FindFreeSlot |

**Returns:** `u32`/`bool` **1** hit / **0** miss.

**Side effects:** out-bytes only. No cell mutation, no network.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005714e0_FUN_005714e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005714e0_FUN_005714e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_FindFreeForItem.cpp` |
| Function record | `docs/reconstruction/functions/aa_005714e0_InventoryGrid_FindFreeForItem.md` |
| Live re-decompile | Ghidra `batch_decompile` @ `0x005714e0` — **≡ raw body** |
| Prologue / epilogue bytes | Ghidra `read_memory` @ `0x005714e0`, `0x00571580` |
| FindFreeSlot dual | `aa_005713a0` residual + A/B (formula sealed) |
| Call sites | HandleButton, SerializeAddItem, Unequip, `FUN_00588290`, … |
| Asm context | `get_assembly_context` on xrefs (`0x004faef9`, `0x005883f4`, …) |

**Not performed:** `disassemble_bytes`, Launcher, live CE, bit-exact image diff.

---

## 3. Relation to FindFreeSlot (fidelity seal)

Fallthrough is **not** a reimplementation of first-fit. Bytes:

```text
; after InvSize loads from clonebase +0x406/+0x407
mov ecx, ebx          ; restore grid this
call 0x005713a0       ; InventoryGrid_FindFreeSlot
; sizeX, sizeY, outX, outY, pageIndex already on stack
```

So every FindFreeSlot seal (Y-outer X-inner, CanPlace, free `(lo&hi)==-1`, page band, index `height*x+y`) applies **unchanged** when the wrapper reaches fallthrough.

Wrapper-only CF:

| Path | Result |
|------|--------|
| Type 4 | Success (0,0) — **bypasses** FindFreeSlot |
| Stack hit | Success at **existing** peer XY — **bypasses** FindFreeSlot |
| Else | FindFreeSlot(InvSizeX, InvSizeY, outs, pageIndex) |

---

## 4. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| Null item → 0 | **Yes** |
| Type 4 → (0,0)/1 | **Yes** |
| allowStack gate | **Yes** |
| `FUN_00513e70` → peer find → capacity → peer XY | **Yes** |
| Fallthrough FindFreeSlot | **Yes** |
| Return FindFree result | **Yes** |

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Function boundary / size | High (`005714e0`–`005715cb`) |
| thiscall + 5 stack args | **High / Sealed** |
| Relation to `0x005713a0` | **High / Sealed** |
| InvSize / page passthrough | **High / Sealed** |
| Type-4 short-circuit CF | **High / Sealed** |
| Stack-merge CF skeleton | **High** |
| Type-4 product taxonomy | Tentative / Open |
| Vfunc symbolic names | Probable |
| Overall | **Probable / accept-with-gaps** |

---

## 6. Verdict

### **accept-with-gaps**

**Accept:** Live body matches raw; prologue/epilogue seal thiscall + direct FindFreeSlot tail; dual residual documents formula handoff.

**Gaps:** type-4 meaning, full caller arg matrix, runtime/diff, stack-helper deep duals deferred to their owners.
