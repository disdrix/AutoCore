# Review A (reconstruction fidelity): `aa_00570f70` InventoryGrid_ClearItemsAndReEmptyCells_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570f70` |
| **VA** | `0x00570f70`–`0x0057100d` inclusive (**158 B** / `0x9E`) |
| **Canonical name** | `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` |
| **Ghidra name** | `FUN_00570f70` |
| **Prior scaffold** | `FUN_00570f70` (2026-07-23) |
| **Rejected misname** | sole `InventoryGrid_FreeCellArray` (partition hint; free-only / no re-alloc) |
| **Review date** | `2026-08-05` (MEGA-090 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00570f70_InventoryGrid_ClearItemsAndReEmptyCells_Inferred.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_by_address` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Full **inventory-grid clear**: destroy or queue-delete every list-held item, drain the embedded list, re-allocate a fully empty cell occupancy buffer.

```text
InventoryGrid_ClearItemsAndReEmptyCells_Inferred(grid)
  list = grid+0x2c
  List_TraversalLock(list)
  while IterateNext → item:
      item->vtbl+0x158(0)           // detach
      if item+0xa4 != 0: queue_delete(item)
      else: scalar_dtor(item, 1)
  inline TraversalUnlock(list)
  List_RemoveAll(list)
  InventoryGrid_AllocateCellArray_Inferred(grid)
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (2026-08-05) |
| Full body | `disassemble_function` + `read_memory` 158 B |
| Analyze complete | classification worker; 3 xrefs; callees sealed |
| Dualed Allocate | `aa_00570720` InventoryGrid_AllocateCellArray_Inferred |
| List family | TraversalLock `004294f0`, IterateNext `004022a0`, RemoveAll `004bc580`, Unlock twin `0040c700` |
| Callers | `005725a0`, `005876c0`, `00884720` (ECX setup via disasm) |
| Twin thin | `FUN_00570f50` RemoveAll+Allocate only |

**Not performed:** `disassemble_bytes`, Launcher, live heap dump, bit-exact diff.

---

## 3. Signature (sealed)

```c
// ECX=InventoryGrid*; void; bare RET (C3)
void __fastcall InventoryGrid_ClearItemsAndReEmptyCells_Inferred(InventoryGrid *grid);
```

| Formal | Source | Conf |
|---|---|---|
| this / grid | `MOV EBP,ECX` | **High** |
| list | `LEA EDI,[EBP+0x2c]` | **High** |
| return | void; no EAX contract | **High** |
| cleanup | `RET` (`C3`) | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live decompile ≡ assembly

| Stage | Match | Conf |
|---|---|---|
| TraversalLock(list) | `CALL 004294f0` ECX=EDI | **High** |
| Iterate loop while status==0 | `TEST/JNZ` + tail `JZ` back | **High** |
| Null payload skip | `CMP ESI,EBX / JZ` | **High** |
| vtbl+0x158(0) | `CALL [EDX+0x158]` push 0 | **High** |
| gate `item+0xa4` | `MOV ECX,[ESI+0xa4]` | **High** |
| queue vs scalar dtor | `004d4790` vs `CALL [EAX]` push 1 | **High** |
| Inline unlock list+0x28 / LeaveCS(+4) | bytes | **High** |
| List_RemoveAll(list) | `CALL 004bc580` ECX=EDI | **High** |
| AllocateCellArray(grid) | `CALL 00570720` ECX=EBP | **High** |
| No place/stamp/find | no those callees | **High** |

### 4.1 Decompiler caveat (non-blocking)

Decompiler elides ECX for List helpers (`FUN_004294f0()`, `FUN_004bc580()` bare). Assembly restores `MOV ECX,EDI` / `MOV ECX,EBP`. Clean named source uses explicit list/grid split.

### 4.2 Why unlock is required

`List_RemoveAll` throws `0x80070005` when `list+0x28 != 0`. Body clears the flag and leaves CS **before** RemoveAll — same contract as dualed `List_TraversalUnlock`.

---

## 5. Callers (sealed)

| Caller | Site | ECX |
|---|---|---|
| `FUN_005725a0` complete-dtor | `0x005725cf` | grid this (`EDI=ECX` then CALL; ECX still grid) |
| `FUN_005876c0` | `0x005876ca` | `MOV ECX,[ECX+0x35c]` |
| `FUN_00884720` | `0x0088473a` | `ECX = *(*(host+0x510)+0xce0)` |

Xrefs: **3** UNCONDITIONAL_CALL. Classification: **worker**.

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Operates on InventoryGrid (Allocate + cell +0x28 parent free) | **Yes** |
| Clears items then re-empties cells | **Yes** |
| RTTI / product string on body | **No** |
| Partition FreeCellArray as sole name | **No** (incomplete) |

→ **`InventoryGrid_ClearItemsAndReEmptyCells_Inferred`**.

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Full clear CF | **High** | live + bytes |
| list@grid+0x2c | **High** | LEA EDI |
| item+0xa4 gate | **High** | bytes |
| Re-empty via dualed Allocate | **High** | final CALL |
| Product English detach/gate | **Open** | residual |
| Runtime golden | **Open** | deferred |

---

## 8. Gaps / open (do not block accept-with-gaps)

1. Retail symbol / PDB English.  
2. Exact product meaning of vtbl+0x158 and `+0xa4`.  
3. Whether queue-delete path fully unlinks before RemoveAll (RemoveAll is residual safety).  
4. Runtime / bit-exact / differential.  
5. Parent complete-dtor `FUN_005725a0` residual (not OWN).

**No clean-vs-raw fidelity rewrite required** beyond ECX restoration already in named clean.

---

## 9. Verdict

### **accept-with-gaps**

Body is a short, high-confidence inventory clear orchestrator: live decompile ≡ raw ≡ assembly order; list/grid split sealed; dualed Allocate endpoint sealed. Gaps are product English and runtime — not CF drift.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Live decompile matches raw | **Pass** |
| Clean CF matches raw + assembly ECX | **Pass** |
| Unlock before RemoveAll | **Pass** |
| Allocate last (re-empty) | **Pass** |
| Callers ECX = grid* | **Pass** |
| Runtime / bit-exact | **Open** |
| Verdict | **accept-with-gaps** |
