# Dual A/B report — W19-T OWN-ONLY (`0x00580a20`, `0x00931440`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W19-T  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module:** `autoassault.exe` base `0x400000`  
**Owned VAs:** `0x00580a20`, `0x00931440` **only**  
**Tools:** Ghidra `decompile_function` + `read_memory` (+ function meta / callers / xrefs). **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits (`ACTIVE_WORK` / `CHANGE_LOG` / `COVERAGE_LEDGER` / `WORK_QUEUE` / `RESUME`).

---

## Verdicts

| VA | Canonical name | Verdict |
|---|---|---|
| `0x00580a20` | `StatusFlag_GetDisplayName` | **accept** |
| `0x00931440` | `Client_SendInventoryEquipC2S` | **accept-with-gaps** |

---

## VA `0x00580a20` — StatusFlag_GetDisplayName

### Sealed facts

1. **ABI:** single stack arg (`mov eax,[esp+4]`); returns `const char*` in EAX; plain **`RET` (`C3`)**. Body `0x00580a20`–`0x00580ac0`.
2. **Role:** pure status-flag **key → English display name** leaf (not “Weapons Disabled” only).
3. **CF:** range ladder + switch for low powers; exact mid/high keys; default **`"in a world of hurt"`**.
4. **Table (Confirmed):**

   | Key | String |
   |---:|---|
   | `0x01` | GM Frozen |
   | `0x02` | Stunned |
   | `0x04` | Locked Down |
   | `0x08` | Silenced |
   | `0x10` | Weapons Disabled |
   | `0x20` | GM Chat Banned |
   | `0x40` | Afraid |
   | `0x80` | Confused |
   | `0x200` | Blind |
   | `0x1000` | Slowed |
   | `0x2000` | Immune to death |
   | `0x4000` | Speeding |
   | `0x10000` | Zombied |
   | default | in a world of hurt |

5. **Callers:** `Client_CastBlockFeedback` `0x0093b7f0` (keys `2` / `0x80` / `0x40`); `FUN_00618c80` (11+ sites).
6. **Callees:** none (leaf).
7. **Live decompile ≡** 2026-07-23 raw (no CF delta).
8. **Rename:** scaffold `Combat_Weapons_Disabled` superseded (single-case plate misname).

### Gaps

1. Product/RTTI C++ symbol.  
2. Dead mid-band keys inventory.  
3. Runtime toast golden per key.  
4. Dual of `FUN_00618c80` (not OWN).

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00580a20_StatusFlag_GetDisplayName.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00580a20_StatusFlag_GetDisplayName.md` |
| Function record | `docs/reconstruction/functions/aa_00580a20_StatusFlag_GetDisplayName.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00580a20_FUN_00580a20.md` (superseded) |
| Clean | `docs/reconstruction/reconstructed-exact/StatusFlag_GetDisplayName.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00580a20.cpp`, `Combat_Weapons_Disabled.cpp` |
| Raw named | `docs/reconstruction/raw/aa_00580a20_StatusFlag_GetDisplayName.md` |
| Annotated named | `docs/reconstruction/raw/aa_00580a20_StatusFlag_GetDisplayName.annotated.md` |
| Raw scaffold + re-verify append | `docs/reconstruction/raw/aa_00580a20_FUN_00580a20.md` |

**Sibling context (not owned):** `Client_CastBlockFeedback` `0x0093b7f0`; `FUN_00618c80`.

---

## VA `0x00931440` — Client_SendInventoryEquipC2S

### Sealed facts

1. **ABI (bytes):** **EAX = item\***, **ECX = client\***, stack **mode** byte; always return **0**; **`RET 4`**. Body `0x00931440`–`0x009314ec`.
2. **Role:** C2S **emit only** after parent equip/customize pre-gates (not a validator).
3. **CF:**
   ```
   type = *(*(item+0xa8)+0x38)
   if type == 0xe:
     pack opcode 0x2053 + COID lo/hi @ item+0x160/0x164
     if client+0xc78: vtbl+0x18(-1, buf, 0x10, 0); return 0
   else:
     pack opcode 0x203c + 16B @ item+0x160..+0x16c + mode
     if client+0xc78: vtbl+0x18(-1, buf, 0x40, 0)
   return 0
   ```
4. **Packet sizes:** type `0xe` → **0x10**; else → **0x40**. Buffer bases sealed via `lea` after arg pushes.
5. **0x203c relative layout (written fields):** `+0x00` opcode; `+0x08..+0x17` four dwords from item; `+0x38` = 0; `+0x3b` = mode.
6. **Callers:** `Client_ConfirmEquipOrCustomizeItem` `0x00941b20` @ `0x00941d31`; `Client_SendInventoryDrop_Hardpoint` `0x00863430` @ `0x008634e9` (type 0xe, mode=1).
7. **Live decompile ≡** 2026-07-23 raw (no CF delta).
8. **Opcode context:** AutoCore `InventoryEquip = 0x203C`, `VehicleSwitch = 0x2053` (product English for type 0xe residual).

### Gaps

1. Full C2S `0x203c` zero-pad field dictionary.  
2. Product English / clonebase class for type `0xe`.  
3. Net object class at `client+0xc78` / vtbl `+0x18`.  
4. Runtime capture both shapes.  
5. C2S vs S2C shared-opcode framing residual.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00931440_Client_SendInventoryEquipC2S.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00931440_Client_SendInventoryEquipC2S.md` |
| Function record | `docs/reconstruction/functions/aa_00931440_Client_SendInventoryEquipC2S.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00931440_FUN_00931440.md` (superseded) |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendInventoryEquipC2S.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00931440.cpp`, `Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_00931440.cpp` |
| Raw named | `docs/reconstruction/raw/aa_00931440_Client_SendInventoryEquipC2S.md` |
| Annotated named | `docs/reconstruction/raw/aa_00931440_Client_SendInventoryEquipC2S.annotated.md` |
| Raw scaffold + re-verify append | `docs/reconstruction/raw/aa_00931440_FUN_00931440.md` |

**Sibling context (not owned):** `Client_ConfirmEquipOrCustomizeItem` `0x00941b20`; `Client_SendInventoryDrop_Hardpoint` `0x00863430`; S2C InventoryEquip builder family.

---

## Dual A/B summary

| VA | Review A | Review B | Agreement |
|---|---|---|---|
| `0x00580a20` | accept | accept | CF/string table/ABI sealed; reject Weapons-Disabled-only / thiscall |
| `0x00931440` | accept-with-gaps | accept-with-gaps | Emit CF/opcodes/ABI sealed; reject validator / single-opcode; field-map residual |

---

## Evidence tools used (both VAs)

- `ghidra-mcp__decompile_function`
- `ghidra-mcp__read_memory` (entry + tails + string pool for status names)
- `ghidra-mcp__get_function_by_address` (body bounds)
- `ghidra-mcp__get_function_callers` / `get_xrefs_to`
- Context decompiles of callers (**read-only**, no writes outside owned VAs)

**Not used:** `disassemble_bytes`, Launcher, parent ledgers.

---

## AutoCore impact

- **Status UI / cast-block:** use `StatusFlag_GetDisplayName` keys (not dense enums); callers may remap status **bits** → keys (e.g. bit 8 → key 2 Stunned). Server wire path does not need this leaf.
- **Inventory equip C2S:** after client gates, send **`0x203c` (0x40)** with item TFID + mode, or **`0x2053` (0x10)** for clone type `0xe` with COID only. Do not treat this unit as the equip validator. Align sector handlers with both opcodes.

---

## This report

`docs/agents/task-dual-ab-w19t-00580a20-00931440-report.md`

Absolute roots: `C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.
