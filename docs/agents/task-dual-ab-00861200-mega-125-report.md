# Dual A/B report — MEGA-125 OWN-ONLY (`0x00861200`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-125**  
**Scope:** VA `0x00861200` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (parent `008612b0` evidence-only).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_xrefs_to` / `get_function_xrefs` + `get_assembly_context` + parent create/decompile `FUN_008612b0` + callee context (`00941b20`, locale/toast). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual partition — inventory-transfer; parent dual context `0x00941b20`; hint `UI_InventoryWindow_OnEquipCommand`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00861200` UI_InventoryWindow_TryEquipOrLockedToast_Inferred | **accept-with-gaps** |

Path A (fidelity): CF/ABI/RET/string/chrome `0x4e24`/ConfirmEquip forward/single parent caller sealed; product window/mode/vtbl English open → **accept-with-gaps**.  
Path B (adversarial): full-OnEquip-merge / direct-C2S / ECX=window / always-toast / unequip-merge / runtime-Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Scaffold status (pre-MEGA-125)

| Artifact | Pre | MEGA-125 action |
|---|---|---|
| Raw capture | present (2026-07-23 scaffold) | **Appended** live re-verify (body/ABI/callers) |
| Annotated | scaffold | **Refreshed** |
| Clean named cpp | string scaffold only | **Replaced** with meaningful `_Inferred` unit |
| FUN twin | scaffold body | **Twin include** of named unit |
| FUN function record | partial scaffold | **Updated** |
| Named function record | missing | **Created** |
| Review A / B | missing | **Created** |
| Report | missing | this file |

---

## VA `0x00861200` — sealed facts

1. **Body:** `0x00861200`–`0x00861254` exclusive (**84 B** / `0x54`); **RET** @ `0x00861253`; pad `CC`.
2. **ABI:** **ECX** = item\*; **EAX** = inventory window\*; no stack formals; bare **`RET`** both exits.
3. **Semantics:**
   - Ready: `window+0x56c != 0` and item non-null → `mode = *(slot+4)` → `item->vtbl[+0x3ac](mode,1)` → **`Client_ConfirmEquipOrCustomizeItem`** (`FUN_00941b20`, client `DAT_00d1a840`, confirmFlag=1).
   - Blocked: localize `"This equipment cannot be changed at this time."` @ `0x00a2cc74` → toast/modal **`FUN_007fdfb0`** with chrome **`0x4e24`** → **return 0** (`XOR AL,AL`).
4. **Stack note:** ConfirmEquip is dualed **EAX=client\***, stack **item\*/mode/confirmFlag**, **`RET 0xC`**. This unit pushes mode+flag before resolve virtual; balance implies **caller-clean** `vtbl[+0x3ac]` so `[resolved, mode, 1]` remains for ConfirmEquip (peer sites push three args explicitly).
5. **Callers (code):** **1** — `FUN_008612b0` @ `0x008615f4` (`MOV ECX,EBX; MOV EAX,EDI; CALL`).
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Callees:** item `vtbl[+0x3ac]`; `FUN_00941b20`; `FUN_007a69d0`; `FUN_007a6de0`; `FUN_007fdfb0`.
8. **Name:** `UI_InventoryWindow_TryEquipOrLockedToast_Inferred` (Ghidra `FUN_00861200`). Partition hint OnEquipCommand maps primarily to **parent** `008612b0`; leaf keeps TryEquip/LockedToast + `_Inferred`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + parent call-site context.

### Gaps

- Product English for inventory window class / mode dword / `vtbl[+0x3ac]` method.  
- Parent `FUN_008612b0` full dual residual (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00861200_UI_InventoryWindow_TryEquipOrLockedToast_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00861200_UI_InventoryWindow_TryEquipOrLockedToast_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00861200_FUN_00861200.md` |
| Annotated | `docs/reconstruction/raw/aa_00861200_FUN_00861200.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InventoryWindow_TryEquipOrLockedToast_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00861200.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_00861200_FUN_00861200.md` |
| Function named | `docs/reconstruction/functions/aa_00861200_UI_InventoryWindow_TryEquipOrLockedToast_Inferred.md` |
| Legacy string scaffold | `docs/reconstruction/reconstructed-exact/Inv_This_equipment_cannot_be_changed_at_this_time_00861200.cpp` (retired; not canonical) |

---

## Chain context (not dualled here; evidence only)

```text
FUN_008612b0  inventory window command (CWndInventoryItem RTTI; modes @ +0x56c)
  ├─ mode 4 → FUN_00861280 + close vtbl[+0x33c]
  ├─ special types 8 / 0x32 → other handlers
  ├─ store / use / interact branches ...
  └─ FUN_00861200  UI_InventoryWindow_TryEquipOrLockedToast_Inferred  [OWN MEGA-125]
        ├─ item vtbl[+0x3ac](mode,1)
        └─ FUN_00941b20  Client_ConfirmEquipOrCustomizeItem  [dualed]
              └─ FUN_00931440  Client_SendInventoryEquipC2S  [dualed]
                    opcodes 0x203c / 0x2053
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00861200-mega-125-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00861200` | Port as **inventory-window equip leaf**: dual-register **ECX=item\***, **EAX=window\***; if mode-slot `@+0x56c` live → resolve `vtbl[+0x3ac]` → **ConfirmEquip**; else toast locked string with chrome **`0x4e24`**, return 0. Bare RET. |
| Do not | Treat as full OnEquip command; emit equip C2S here; assume ECX=window; invent mode/vtbl product English; claim runtime Confirmed. |
| Pair with | dualed `Client_ConfirmEquipOrCustomizeItem` `00941b20`; dualed `Client_SendInventoryEquipC2S` `00931440`; residual parent `FUN_008612b0` if command surface is needed. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` row  
- `NAMING_REGISTRY.md` entry + rename-history line  
- `systems/inventory-transfer.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER / ACTIVE_WORK  
