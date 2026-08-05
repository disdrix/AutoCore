# Review A (reconstruction fidelity): `aa_0089bc30` UI_RefinePanel_RebuildCommodityList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0089bc30` |
| **VA** | `0x0089bc30` |
| **Canonical name** | `UI_RefinePanel_RebuildCommodityList_Inferred` |
| **Prior names** | `FUN_0089bc30`, `Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_0089bc30` |
| **Review date** | `2026-07-29` (dual A/B — OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0089bc30_UI_RefinePanel_RebuildCommodityList_Inferred.md` |
| **System** | `inventory-transfer` (refinery UI) |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Rebuild the **refinery commodity pick list** on the refine UI host:

```text
// param_1 = refine UI host
if (!DAT_00d1b570 || !DAT_00d1b6d8 || !host+0x56c || !host+0x568) return;

if (host+0x538 != 0):   // reverse-refine inventory walk
  build temp list via FUN_004023f0 + FUN_00572060(0x1a, …) twice
  for each node payload:
    RTTI cast clonebase → SCloneBaseCommodity
    if commodity+0x4d0 != -1:
      qty = item.vtbl+0x25c(1)
      FUN_0089a260(host, clonebase, qty, 1)
  FUN_00403430(); return

// forward: iterate catalog hash
FUN_00402c40(); entry = FUN_00411900(&it)
while entry:
  ensure entry+0x3c def (FUN_004f1e20 if null)
  if entry+0x38 == 0x1a:   // commodity type tag
    FUN_00522060(entry, &qty, 0, host+0x538)
    FUN_0089a260(host, entry, qty, flag)
  next FUN_00411900
*(DAT_00d1b570+0xf14)+0x1d = 0   // clear dirty bit on catalog side
```

Populates list rows via shared helper `FUN_0089a260`. Sibling of bind display `0x0089b090` / qty sync `0x0089c330` under parent `FUN_0089c6c0`.

---

## 2. Calling convention

| Slot | Role | Evidence |
|------|------|----------|
| Stack this | Refine UI host | `PUSH EDI; CALL 0x0089bc30` @ `0x0089c72a` |
| Return | `void` | |
| SEH | `LAB_009ad24b` | Prologue |

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / record | `aa_0089bc30_*` / `FUN_0089bc30.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x0089bc30` |
| Live bytes | `read_memory` `0x0089bc30` — SEH + load `DAT_00d1b570` |
| Callers | 1× `FUN_0089c6c0` @ `0x0089c72a` |
| RTTI | `SCloneBaseObject` → `SCloneBaseCommodity` (reverse path) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Global + host widget null gate (`+0x56c`/`+0x568`) | **Yes** |
| Reverse branch on `host+0x538` | **Yes** |
| Type filter `entry+0x38 == 0x1a` | **Yes** |
| Always ends `FUN_0089a260` per accepted row | **Yes** |
| Catalog dirty clear `+0xf14+0x1d` on forward path only | **Yes** |
| Reverse path early return (no dirty clear) | **Yes** |

### Offsets

| Offset | Role |
|--------|------|
| host `+0x538` | reverse mode flag (byte) |
| host `+0x568` / `+0x56c` | required UI child hosts |
| entry `+0x38` | type (commodity `0x1a`) |
| entry `+0x3c` | def blob |
| commodity `+0x4d0` | product key gate (reverse list) |
| `DAT_00d1b570+0xf10` | (sibling units) clone hash |
| `DAT_00d1b570+0xf14+0x1d` | rebuild dirty flag |

---

## 5. Naming / gaps

| Claim | Confidence |
|---|---|
| Role = rebuild refine commodity list | **High** |
| Type `0x1a` = commodity | **Probable** (RTTI + refine parent) |
| Name `_Inferred` | **Probable** |
| `FUN_0089a260` row-insert English | **Open** |
| Runtime | **Open** |

---

## 6. Verdict

**accept-with-gaps** — dual branch CF sealed; product type enum residual.
