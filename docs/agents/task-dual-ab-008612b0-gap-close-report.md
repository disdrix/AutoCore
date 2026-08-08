# Dual A/B report — gap-close OWN-ONLY (`0x008612b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **gap-close**  
**Scope:** VA `0x008612b0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (children dualed earlier are evidence only).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_xrefs_to` / `get_function_xrefs` + `get_function_callees` + `get_function_by_address` + `analyze_control_flow` + RTTI/string reads. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** inventory.jsonl gap-close — VA live in Ghidra, missing from inventory; full dual seal.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008612b0` UI_InventoryWindow_OnItemClickDispatch_Inferred | **accept-with-gaps** |

Path A (fidelity): CF/ABI/`RET 0x8`/RTTI/string/opcode `0x2027`/vtable install/child dual chain sealed; product English open → **accept-with-gaps**.  
Path B (adversarial): equip-only-merge / store-only-merge / code-caller / ECX=item / bare-RET / always-success / runtime-Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Scaffold status (pre gap-close)

| Artifact | Pre | Gap-close action |
|---|---|---|
| Raw capture | **missing** | **Created** |
| Annotated | missing | **Created** |
| Clean named cpp | missing | **Created** |
| FUN twin | missing | **Created** |
| FUN function record | missing | **Created** |
| Named function record | missing | **Created** |
| Review A / B | missing | **Created** |
| inventory.jsonl row | **missing** (gap) | **not edited** (OWN-ONLY; parent merge) |
| Report | missing | this file |

---

## VA `0x008612b0` — sealed facts

1. **Body:** `0x008612b0`–`0x00861676` exclusive (**966 B** / `0x3C6`); **`RET 0x8`** @ `0x00861673`; pad `CC`.
2. **ABI:** **ECX** = inventory window this\*; **two opaque stack formals**; cleanup **`RET 0x8`**; return **AL** bool.
3. **Install:** DATA xref only — vtable dword @ **`0x00a64b00`** = `0x008612b0`. **No** code callers.
4. **Semantics (high level):**
   - Early: `DAT_00d1b6d8+0xcd0` busy **or** `window+0x4b8` null → `FUN_0085f220` path.
   - RTTI: selected child `CNDUIWindow` → **`CWndInventoryItem`** (type strings `@0x00afe1ac` / `@0x00aff3ac`).
   - Mode `@*(window+0x56c)+4`: **1 / 3 / 4** (cascade SUB).
   - Mode 4 → `FUN_00861280` + close `vtbl[+0x33c](0)`.
   - Store (`DAT_00d1bdfa`): dualed **`Item_IsWantedByStore_Inferred`** → toast *“The store does not want that item.”* chrome **`0x4e24`** **or** C2S **`0x2027`** size **`0x40`** via dualed **`Client_SendSectorPacket`**.
   - Non-store: UseObject / special flag / use-by-coid / types **8** & **`0x32`** skill-target / dualed equip leaf **`UI_InventoryWindow_TryEquipOrLockedToast_Inferred`** (`0x00861200`).
5. **CF metrics:** 41 BB, 284 insns, 29 calls, 10 returns, cyclomatic **37**.
6. **Name:** `UI_InventoryWindow_OnItemClickDispatch_Inferred` (Ghidra `FUN_008612b0`). Partition hint OnEquipCommand is parent-of-equip only — under-states store/use/skill branches.
7. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` (decompiler showed incomplete `__fastcall` / bare returns).

### Gaps

- Product English for inventory **host** window class / mode dword / stack formals / close+resolve vtbl methods.  
- Residual callees `0085f220`, `00861280`, `00524520`, `0093a330` product names.  
- Full store packet field map beyond opcode/size/TFID/IsBuy (cross-ref topic extraction).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008612b0_UI_InventoryWindow_OnItemClickDispatch_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008612b0_UI_InventoryWindow_OnItemClickDispatch_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008612b0_FUN_008612b0.md` |
| Annotated | `docs/reconstruction/raw/aa_008612b0_FUN_008612b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InventoryWindow_OnItemClickDispatch_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008612b0.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_008612b0_FUN_008612b0.md` |
| Function named | `docs/reconstruction/functions/aa_008612b0_UI_InventoryWindow_OnItemClickDispatch_Inferred.md` |

---

## Chain context (children dualed earlier; evidence)

```text
FUN_008612b0  UI_InventoryWindow_OnItemClickDispatch_Inferred  [OWN gap-close]
  vtable @ 0x00a64b00
  ├─ early → FUN_0085f220  [residual]
  ├─ mode 4 → FUN_00861280  [residual]
  ├─ store DAT_00d1bdfa:
  │     Item_IsWantedByStore_Inferred (00513770)  [dualed]
  │     toast "The store does not want that item." chrome 0x4e24
  │     OR Client_SendSectorPacket 0x2027 / 0x40  [dualed 00807460]
  ├─ Client_SendUseObject_IfInteractable (00930d70)  [dualed]
  ├─ Client_UseInventoryItemByCoid (00941f50)  [dualed]
  ├─ Client_PromptSkillTargetSelect (0093bac0) types 8 / 0x32  [dualed]
  └─ UI_InventoryWindow_TryEquipOrLockedToast_Inferred (00861200)  [MEGA-125 dualed]
        └─ Client_ConfirmEquipOrCustomizeItem (00941b20)  [dualed]
              └─ Client_SendInventoryEquipC2S (00931440)  [dualed]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008612b0-gap-close-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008612b0` | Port as **inventory-window selected-item action virtual**: **ECX=window**, **`RET 0x8`**, **AL** bool. RTTI-cast selected `@+0x4b8` to `CWndInventoryItem`; mode `@*(+0x56c)+4`. Dispatch store sell **`0x2027`**, UseObject, skill-target, equip leaf — do **not** flatten to equip-only. |
| Do not | Assume code callers; bare RET; ECX=item; invent mode/host English; claim runtime Confirmed; merge with equip C2S sender. |
| Pair with | dualed equip leaf `00861200`; dualed `Item_IsWantedByStore` `00513770`; dualed `Client_SendSectorPacket` `00807460`; dualed UseObject / UseByCoid / PromptSkillTargetSelect. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `inventory.jsonl` row (gap that motivated this seal)  
- `VERIFICATION_MATRIX.md` row  
- `NAMING_REGISTRY.md` entry + rename-history line  
- `systems/inventory-transfer.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER / ACTIVE_WORK  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x008612b0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + control-flow + RTTI/string. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Clean sources use meaningful name + FUN twin include.  
- Odd behavior preserved: multi-exit AL bool; vtable-only install; mode-3 client flag gate; store reject toast; soft-success template word 8.  
- `_Inferred` where product host/mode/formals English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
