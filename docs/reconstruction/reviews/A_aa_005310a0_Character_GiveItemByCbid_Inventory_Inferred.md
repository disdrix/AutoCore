# Review A (reconstruction fidelity): `aa_005310a0` Character_GiveItemByCbid_Inventory_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005310a0` |
| **VA** | `0x005310a0`–`0x00531247` inclusive (**424 B** / `0x1A8`) |
| **Canonical name** | `Character_GiveItemByCbid_Inventory_Inferred` |
| **Ghidra name** | `FUN_005310a0` |
| **Prior scaffold** | `FUN_005310a0` / `Named_CalleeOf_CVOGObjectiveRequirement_UseItem_InitActive_005310a0` / plate `Inv_Invalid_CBID_bad_item` |
| **Review date** | `2026-08-05` (MEGA-003 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005310a0_Character_GiveItemByCbid_Inventory_Inferred.md` |
| **System** | missions-progression (UseItem give-by-cbid) + inventory-transfer |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `analyze_control_flow` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Character **grant N items by CBID into inventory**:

```text
Character_GiveItemByCbid_Inventory_Inferred(this, cbid, count) -> bool
  char* = dual_base(this)+0xa8
  if char[+0x7e] == 0: return true
  remaining = count
  first = 0
  loop:
    item = CVOGReaction_GiveItemByCbid(cbid, 0)
    if !item: log "Invalid CBID: %d (bad item)"; return false
    item.vtbl+8(cbid, char*, 1)
    stamp serial from char[+0xe6e0] via FUN_00512160
    zero-pose transform (g_flOne)
    owner hooks vtbl+0x2a4 / +0x218
    first-item: FUN_00513e70 may set remaining=1 else inv_flag=1
    item.vtbl+0x260(flag); Client_SendInventoryAddItem(this, item, flag)
    remaining--
  return true
```

Parents include dualed-context **UseItem** requirement init/progress and craft/outpost grant helpers. Factory is dualed `CVOGReaction_GiveItemByCbid` (construct only); bag insert is `Client_SendInventoryAddItem`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005310a0_FUN_005310a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005310a0_FUN_005310a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_GiveItemByCbid_Inventory_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005310a0.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_005310a0_FUN_005310a0.md` |
| Function named | `docs/reconstruction/functions/aa_005310a0_Character_GiveItemByCbid_Inventory_Inferred.md` |
| Live | decompile + full body disassembly + xrefs (8) + string @ `0x009cfea4` |

---

## 3. Signature (sealed)

```c
// ECX = character dual-base this; stack cbid, count; AL bool; RET 8
uint8_t __thiscall Character_GiveItemByCbid_Inventory_Inferred(
    void *this_char,
    int cbid,
    int count);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** → EDI | **High** (assembly `MOV EDI,ECX`) |
| cbid | stack `[ESP+4]` entry → `[ESP+0x2c]` post-prologue | **High** |
| count | stack `[ESP+8]` entry → `[ESP+0x30]` / remaining `@[ESP+0x14]` | **High** |
| cleanup | **`RET 8`** (`C2 08 00`) ×2 | **High** |
| return | **AL** `1` / `0` | **High** |

**Note:** Decompiler surface shows `(this, cbid)` only and `while(factory)` — **falsified by assembly**. Clean uses assembly arity/loop.

---

## 4. Control flow (clean ≡ assembly ≡ corrected raw)

| Stage | Match | Conf |
|---|---|---|
| Dual-base char fetch + gate `+0x7e` | **Yes** | **High** |
| Early success if gate clear | **Yes** | **High** |
| Count-down loop / factory null fail | **Yes** (asm) | **High** |
| vtbl+8 init; serial inc @ `+0xe6e0`; `FUN_00512160` | **Yes** | **High** |
| Transform zero-pose + `g_flOne` @ `0x00a0f2a0` | **Yes** | **High** |
| Owner hooks `+0x2a4` / `+0x218` | **Yes** | **High** |
| First-item `FUN_00513e70` collapse / flag=1 | **Yes** | **High** |
| `Client_SendInventoryAddItem` thiscall | **Yes** | **High** |
| Fail log string @ `0x009cfea4` | **Yes** | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (state-mutating grant) |
| External callers | **6** functions / **8** UNCONDITIONAL_CALL |
| Primary parents | `CVOGObjectiveRequirement_UseItem_InitActive` `0x0060d540`; `FUN_0060d630` |
| Other parents | craft `FUN_00531570` / `FUN_005316c0`; outpost `FUN_00607a00`; objective `FUN_00610e60` |
| Callees | `CVOGReaction_GiveItemByCbid`, `FUN_00512160`, `FUN_00513e70`, `Client_SendInventoryAddItem`, `FUN_007a4480`, item vtbl slots |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Caller product strings `"Failed to give item %d..."` | **Yes** |
| Fail string `"Invalid CBID: %d (bad item)"` | **Yes** |
| Named factory + inventory send callees | **Yes** |
| UseItem parent plate | **Yes** |
| PDB / RTTI character class demangle | **No** → **`_Inferred`** |
| Vtable method English | **No** (slots by offset) |

Promote **`Character_GiveItemByCbid_Inventory_Inferred`**. Retire `Named_CalleeOf_*` scaffold and log-only plate alias.

---

## 7. Gaps

1. Product English for character dual-base class (CVOGCharacter vs shell).  
2. Named item vtable methods at `+8`, `+0x1cc`, `+0x2a4`, `+0x218`, `+0x260`.  
3. Full bind/trade-lock semantics of `FUN_00513e70` vs inventory notify flag.  
4. Runtime / bit-exact / differential (Terminal **false**).

**Verdict:** **accept-with-gaps** — ABI/CF/callers sealed; product class + vtbl English open.
