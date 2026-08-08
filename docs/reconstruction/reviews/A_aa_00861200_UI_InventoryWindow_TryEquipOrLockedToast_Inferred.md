# Review A (reconstruction fidelity): `aa_00861200` UI_InventoryWindow_TryEquipOrLockedToast_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00861200` |
| **VA** | `0x00861200` |
| **Body** | `0x00861200`–`0x00861254` exclusive (**84 B** / `0x54`); RET @ `0x00861253` |
| **Canonical name** | `UI_InventoryWindow_TryEquipOrLockedToast_Inferred` |
| **Ghidra name** | `FUN_00861200` |
| **Review date** | `2026-08-05` (MEGA-125 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00861200_UI_InventoryWindow_TryEquipOrLockedToast_Inferred.md` |
| **System** | inventory-transfer |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body) + `get_xrefs_to` / `get_function_xrefs` + `get_assembly_context` (caller `008615f4`, ConfirmEquip site `00861222`) + parent create/decompile `FUN_008612b0` + dualed ConfirmEquip / SendInventoryEquipC2S records. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Inventory-window **equip leaf**: when selected item\* and window mode-slot `@+0x56c` are present, resolve via `item->vtbl[+0x3ac](mode,1)` and forward to dualed **`Client_ConfirmEquipOrCustomizeItem`** (`0x00941b20`); otherwise toast *“This equipment cannot be changed at this time.”* (chrome **`0x4e24`**) and return 0. Does **not** own the full window command (parent `FUN_008612b0`) and does **not** emit C2S equip opcodes (ConfirmEquip → `Client_SendInventoryEquipC2S`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-125 re-verify) | `docs/reconstruction/raw/aa_00861200_FUN_00861200.md` |
| Annotated | `docs/reconstruction/raw/aa_00861200_FUN_00861200.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InventoryWindow_TryEquipOrLockedToast_Inferred.cpp` |
| Twin include | `docs/reconstruction/reconstructed-exact/FUN_00861200.cpp` |
| Named record | `docs/reconstruction/functions/aa_00861200_UI_InventoryWindow_TryEquipOrLockedToast_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00861200_FUN_00861200.md` |
| Dualed child | `Client_ConfirmEquipOrCustomizeItem` @ `0x00941b20` |
| Dualed C2S | `Client_SendInventoryEquipC2S` @ `0x00931440` |
| Parent (evidence) | `FUN_008612b0` @ `0x008612b0` (CWndInventoryItem RTTI command) |
| Live body | `read_memory` 84 B + `disassemble_function` |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| ECX | item\* | entry `TEST ECX,ECX`; parent `MOV ECX,EBX` |
| EAX | inventory window\* | `MOV EAX,[EAX+0x56c]`; parent `MOV EAX,EDI` |
| stack formals | none at entry | dual-register helper |
| cleanup | bare **`RET`** | `C3` @ success `00861227` and fail `00861253` |
| return | success: ConfirmEquip EAX; fail: **AL=0** | `XOR AL,AL` before fail RET |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 84 B + pad `CC` | **Confirmed** | `read_memory` + RET @ `00861253` |
| Gate item + `window+0x56c` | **Confirmed** | decompile ≡ bytes |
| Mode `@slot+4` | **Confirmed** | `8B 40 04` |
| Resolve `vtbl[+0x3ac](mode,1)` | **Confirmed** | `FF 92 AC 03 00 00` |
| Forward `FUN_00941b20` / ConfirmEquip | **Confirmed** | CALL + dualed child ABI |
| Toast string @ `0x00a2cc74` | **Confirmed** | `read_memory` ASCII |
| Chrome id `0x4e24` | **Confirmed** | `B8 24 4E 00 00` |
| Single code caller parent equip path | **Confirmed** | xref `008615f4` only |
| Stack dual-use / caller-clean virtual | **High** | balance vs ConfirmEquip `RET 0xC`; peer 3-arg sites |
| Product window class English | **Open** | parent RTTI shows CWndInventoryItem child; sheet class residual |
| Mode / vtbl method product English | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | terminal false |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| if item==0 \|\| window+0x56c==0 → toast path | **Yes** |
| mode = \*(slot+4); resolve vtbl+0x3ac; ConfirmEquip | **Yes** |
| fail: pool → localize string → toast 0x4e24 → return 0 | **Yes** |

---

## 6. Naming gate

- Role = inventory-window **try equip** or **locked toast** leaf under equip command.
- Partition hint `UI_InventoryWindow_OnEquipCommand` fits **parent** `008612b0` more than this 84 B helper → leaf name keeps TryEquip/LockedToast.
- Product demangle incomplete → **`_Inferred`**.
- Retire string-only scaffold `Inv_This_equipment_cannot_be_changed_at_this_time_00861200` as non-canonical.

---

## 7. Gaps / open

- Exact product class of inventory window (`CNDUIWindow` subclass beyond selected-item RTTI).
- Mode dword English (1/3/4 observed in parent only).
- `vtbl[+0x3ac]` method English.
- Runtime equip / toast verification.

**Verdict:** **accept-with-gaps** — CF/ABI/string/chrome/ConfirmEquip forward sealed; product English open.
