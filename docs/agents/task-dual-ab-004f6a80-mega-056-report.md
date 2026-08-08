# Dual A/B report — MEGA-056 OWN-ONLY (`0x004f6a80`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-056**  
**Scope:** VA `0x004f6a80` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `get_function_signature`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — inventory-transfer unequip/grab gate.  
**Partition hint:** `Inventory_HasSpaceForItem` (soft; refined — space is ret=2 only).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004f6a80` Inventory_ValidateEquipmentChange_Inferred | **accept-with-gaps** — CF/ABI/RET4/status map/FindFree@+0x2b0/2 callers sealed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): HasSpace-only / item-as-this / grid-as-this / place-item / bare-RET / bool-only / unequip-private claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004f6a80` — sealed facts

1. **Body:** `0x004f6a80`–`0x004f6ed1` inclusive (**1106 B** / `0x452`); pad `CC` @ `0x004f6ed2`.
2. **ABI:** **ECX** = inventory host (`*[DAT_00d1b6d8+0x250]`); stack `item*`; **EAX** = status; **`RET 4`** all exits.
3. **Semantics:** multi-code **equipment-change pre-flight**:
   - null item → **8**
   - state `+0xa8` flag `+0xf6` → **0xf** (arena)
   - `InventoryGrid_FindFreeForItem` on **`this+0x2b0`** fail → **2** (space)
   - type dispatch `*(item+0xa8)+0x38` with TFID `+0x164/+0x168` vs host slots `+0x254…+0x270`
   - specials: town **1**, hazard **0xd**, must-swap **0xa**
   - default → **8**
4. **Callees:** `InventoryGrid_FindFreeForItem` `0x005714e0` (dualed); `__RTDynamicCast` `0x004898a4`; `FUN_004ce5f0`.
5. **Callers (2):** `Client_SendInventoryUnequip` @ `0x00862c4c`; `Client_SendInventoryGrab_Hardpoint` @ `0x00862dd5`. Nonzero → UI `0x00931db0`.
6. **Xrefs:** 2 UNCONDITIONAL_CALL only.
7. **Name:** `Inventory_ValidateEquipmentChange_Inferred` (Ghidra `FUN_004f6a80`). Partition HasSpace incomplete → refined + `_Inferred`.
8. **Decompile ≡ raw CF**; ABI/boundary sealed via `disassemble_function` + `read_memory` + call-site context.
9. **Retired:** `Named_CalleeOf_Client_SendInventoryUnequip_004f6a80` scaffold.

### Gaps

- Product English for type classes and host slot fields.  
- Residual `FUN_004ce5f0` (type 0xe only).  
- Retail symbol.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004f6a80_Inventory_ValidateEquipmentChange_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004f6a80_Inventory_ValidateEquipmentChange_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004f6a80_FUN_004f6a80.md` |
| Annotated | `docs/reconstruction/raw/aa_004f6a80_FUN_004f6a80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inventory_ValidateEquipmentChange_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004f6a80.cpp` |
| Function | `docs/reconstruction/functions/aa_004f6a80_FUN_004f6a80.md` |
| Function named | `docs/reconstruction/functions/aa_004f6a80_Inventory_ValidateEquipmentChange_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_SendInventoryUnequip  0x00862c00  [dualed inventory C2S]
  ├─ item = item->vtbl+0x3ac()
  ├─ inv  = *[DAT_00d1b6d8 + 0x250]
  ├─ FUN_004f6a80(inv, item)  Inventory_ValidateEquipmentChange_Inferred  [OWN MEGA-056]
  │     ├─ arena state+0xf6 → 0xf
  │     ├─ InventoryGrid_FindFreeForItem(inv+0x2b0)  0x005714e0  [dualed]
  │     │     └─ InventoryGrid_FindFreeSlot  0x005713a0
  │     ├─ type/TFID host slots +0x254…+0x270
  │     ├─ __RTDynamicCast (type 6)
  │     └─ FUN_004ce5f0 (type 0xe)  [residual]
  ├─ nonzero → FUN_00931db0 (message UI)  [residual]
  └─ zero → free-slot + C2S 0x203E

Client_SendInventoryGrab_Hardpoint  0x00862d90  [dualed]
  ├─ FUN_004f6a80(inv, item)  [OWN MEGA-056]
  ├─ nonzero → FUN_00931db0
  └─ zero → C2S 0x2034 inventoryType=2
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004f6a80-mega-056-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004f6a80` | Port as **equipment-change pre-flight** returning multi-code status. **ECX=inventory host**, stack item*, **RET 4**. Do **not** reduce to space-only: still require type/slot TFID (or special OK) after FindFree succeeds. Map nonzero codes through the same UI strings as `00931db0`. |
| Grid | Free-space subcheck is dualed `InventoryGrid_FindFreeForItem` on **`host+0x2b0`**, allowMerge=1, page=-1. |
| Pair with | dualed FindFreeForItem `005714e0`; dualed unequip/grab C2S builders; residual `004ce5f0`; residual message switch `00931db0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep later for this VA only:

- `VERIFICATION_MATRIX.md` / coverage / naming — **not touched** here.
