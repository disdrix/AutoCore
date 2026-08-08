# Dual A/B report — MEGA-001 OWN-ONLY (`0x00520dc0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-001**  
**Scope:** VA `0x00520dc0` (`aa_00520dc0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `analyze_control_flow` + callers/xrefs + `get_bulk_xrefs` + `search_strings` + callee batch decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual seal — inventory-transfer nested under named manager; plate **CVOGCharacter_CleanupDraggingObject**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00520dc0` CVOGCharacter_CleanupDraggingObject | **accept-with-gaps** — CF/ABI/RET4/AL-bool/plate name/cargo+locker place/equip fallback sealed; callers + status English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): decompiler item-as-this / always-equip / vehicle-only `+0xCD0` / scaffold-name claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00520dc0` — sealed facts

1. **Body:** `0x00520dc0`–`0x00520f39` inclusive (**378 B** / `0x17A`); `CC` pad follows.
2. **ABI:** **ECX** = `CVOGCharacter* this`; stack **4 B present** (unread); **AL** bool; **`RET 4`** both exits.
3. **Semantics:**
   - Profiler enter plate `"CVOGCharacter::CleanupDraggingObject"` @ `0x009cf0b0`.
   - `drag = *(this+0xCD0)`; null → leave, return **0**.
   - Place path A: cargo grid `*( *(this+0x250)+0x2B0 )` via `InventoryGrid_FindFreeForItem` (`1`, `-1`) + qty vcall `+0x25C` + `InventoryGrid_PlaceItemFootprint`.
   - Place path B: locker `*(this+0xCBC)` same pair.
   - Else: `Character_TryEquipItem(*(this+0x250), drag, &out)`; if `out==0` and code ∈ `{0,1,0xA,0xD,0xF}` → `FUN_00502e90(host, drag)`.
   - Always `*(this+0xCD0)=0`; leave; return **1**.
4. **Callees:** `00786a00`, `00786990`, `005714e0`×2, `00571620`×2, item vcall `+0x25C`×2, `004fabc0`, `00502e90`.
5. **Callers:** live Ghidra **0** code xrefs (gap).
6. **Name:** `CVOGCharacter_CleanupDraggingObject` (Ghidra `FUN_00520dc0`). Product plate sealed — **no** `_Inferred`.
7. **Decompiler ≠ assembly** on callee `this` bindings — clean uses assembly authority.

### Gaps

- Direct callers / unread stack-arg producers.  
- TryEquip status-code product English for equip-switch gate.  
- Cross-layout `+0xCD0` naming residual (other units claim vehicle on different hosts).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00520dc0_CVOGCharacter_CleanupDraggingObject.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00520dc0_CVOGCharacter_CleanupDraggingObject.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00520dc0_FUN_00520dc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00520dc0_FUN_00520dc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_CleanupDraggingObject.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00520dc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00520dc0_FUN_00520dc0.md` |
| Function named | `docs/reconstruction/functions/aa_00520dc0_CVOGCharacter_CleanupDraggingObject.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGCharacter_CleanupDraggingObject  [0x00520dc0]  OWN MEGA-001
  ├─ Profiler_EnterNamedZone / Leave          [dualed]
  ├─ InventoryGrid_FindFreeForItem ×2         [0x005714e0 dualed]
  │     this = cargo *( *(char+0x250)+0x2B0 ) | locker *(char+0xCBC)
  ├─ item vtbl+0x25C (qty) ×2
  ├─ InventoryGrid_PlaceItemFootprint ×2      [0x00571620 dualed]
  ├─ Character_TryEquipItem                   [0x004fabc0 dualed]
  │     this = *(char+0x250)
  └─ FUN_00502e90  menu_equip_* switch        [residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00520dc0-mega-001-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00520dc0` | Port as **`CVOGCharacter::CleanupDraggingObject`**. **thiscall RET 4** (dummy stack dword if calling from raw asm); **bool AL**. Place cargo then locker before equip fallback. **Do not** trust raw Ghidra decompile for FindFree/Place/TryEquip `this` — grids/host are ECX, drag is stack. Clear `+0xCD0` only after non-null drag path. |
| Pair with | dualed FindFree `005714e0`, Place `00571620`, TryEquip `004fabc0`, profiler enter/leave; residual equip switch `00502e90`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history (name already listed historically; dual seal now)
- `systems/*` inventory-transfer residual tables
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00520dc0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + disassemble_function + callers/xrefs + control-flow + string. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean sources use product name; machine twin retained; ABI/this-binding corrections from assembly.
- Odd behavior preserved: unread stack dword; TryEquip-then-conditional-equip-switch; 0 Ghidra callers.
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
