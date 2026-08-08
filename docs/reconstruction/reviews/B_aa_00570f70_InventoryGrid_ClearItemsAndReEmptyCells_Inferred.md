# Review B (skeptical / adversarial): `aa_00570f70` InventoryGrid_ClearItemsAndReEmptyCells_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570f70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00570f70_InventoryGrid_ClearItemsAndReEmptyCells_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | MEGA-090 modern pair; supersedes 2026-07-23 scaffold-only |
| **Verdict** | **accept-with-gaps** on CF + ABI + list/grid split; **reject** free-only / stack-arg / cell-free-without-realloc / retail-name overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is only `InventoryGrid_FreeCellArray` (free `+0x28` and return) | **Falsified** — no direct `operator_delete` of cells; ends in **Allocate** (free-inside-alloc + empty fill); item walk first |
| 2 | Does not destroy items | **Falsified** — vtbl+0x158 + scalar dtor / `FUN_004d4790` per payload |
| 3 | ECX is the List host, not the grid | **Falsified** — `MOV EBP,ECX`; `LEA EDI,[EBP+0x2c]`; Allocate uses EBP; CompleteDtor passes grid this |
| 4 | Stack args / `RET 4` | **Falsified** — bare `RET` (`C3`); no stack formals |
| 5 | Same as thin twin `00570f50` | **Falsified** — twin is RemoveAll+Allocate only; this unit adds TraversalLock walk + per-item teardown |
| 6 | Leaves TraversalLock held into RemoveAll | **Falsified** — inline unlock before `004bc580` (RemoveAll would throw if locked) |
| 7 | Walks a tree/map, not a list | **Falsified** — callees are List_TraversalLock / IterateNext / RemoveAll family |
| 8 | Name is retail / PDB sealed | **Fail** — `_Inferred` only; no RTTI/string |
| 9 | Decompiler alone seals List ECX | **Overstated** — decomp drops ECX; **assembly** seals `MOV ECX,EDI` |
| 10 | Ready for bit-exact / Confirmed runtime | **Fail** — no Launcher; open |
| 11 | `item+0xa4` English is sealed | **Fail** — gate sealed as branch only; product meaning open |
| 12 | Places or stamps cells during clear | **Falsified** — no Place/Find/CanPlace callees |

---

## 2. Decisive dataflow (assembly-backed)

```text
EBP = ECX                    // InventoryGrid*
EDI = EBP+0x2c               // List*
List_TraversalLock(EDI)
cursor = 0
while IterateNext(EDI, &cursor, &item) == 0:
  if item:
    item->vtbl[0x158/4](0)
    if *(item+0xa4) != 0: FUN_004d4790(item)
    else: item->vtbl[0](1); item=null
if *(EDI+0x28): *(EDI+0x28)=0; LeaveCS(EDI+4)
List_RemoveAll(EDI)
InventoryGrid_AllocateCellArray_Inferred(EBP)
RET
```

Live body hex (158 B) and disassembly match 2026-07-23 raw CF order.

---

## 3. Caller ECX attack

| Caller | Attack: wrong this? | Result |
|---|---|---|
| `005725a0` | maybe list? | **No** — CALL with grid EDI/ECX; after return loads `grid+0x28` cells |
| `005876c0` | host not grid? | **No** — `MOV ECX,[ECX+0x35c]` then CALL; null-check first |
| `00884720` | host+0x510 object? | **No** — loads `*(+0x510)+0xce0` (cargo grid slot per inventoryType map) into ECX |

---

## 4. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clear CF + unlock-before-RemoveAll | **High** | hang / E_ACCESSDENIED throw |
| list@+0x2c / cells@+0x28 split | **High** | wrong object free |
| Re-empty via Allocate (not bare free) | **High** | leak or null cells mid-path |
| Twin 00570f50 distinction | **High** | wrong clear strength on cargo vs char |
| vtbl+0x158 / +0xa4 product English | **Open** | misnamed detach/queue |
| Retail symbol | **Open** | cosmetic |
| Runtime item-count golden | **Open** | residual parity |

---

## 5. Naming attack

| Candidate | Attack | Result |
|---|---|---|
| `InventoryGrid_FreeCellArray` | free-only | **Reject as sole name** — incomplete |
| `InventoryGrid_RemoveAll` | list only | **Reject** — also Allocate + item walk |
| `List_ClearDestroy` | list this | **Reject** — ECX is grid |
| `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` | long | **Accept** with `_Inferred` honesty |

---

## 6. Gaps that remain (honest)

1. No runtime Confirmed.  
2. No bit-exact / differential.  
3. Product English for detach virtual and `+0xa4`.  
4. Parent `FUN_005725a0` / cargo host layouts residual (not OWN).  
5. Queue-delete vs immediate-dtor production semantics residual.

---

## 7. Verdict

### **accept-with-gaps**

Adversarial path **falsifies** free-only naming, stack-arg ABI, list-as-ECX, and twin-collapse. Fidelity of CF/ABI/list-grid split stands. Residual gaps are English + runtime — same class as dualed Allocate sibling.

Path A (fidelity) and Path B (adversarial) **agree**: **accept-with-gaps**.
