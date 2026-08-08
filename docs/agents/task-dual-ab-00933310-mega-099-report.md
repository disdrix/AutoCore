# Dual A/B report — MEGA-099 OWN-ONLY (`0x00933310`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-099**  
**Scope:** VA `0x00933310` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` + `get_function_by_address` + `get_function_signature` + `get_function_hash` + `batch_decompile` (callers/callee). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — inventory-transfer; partition hint `Client_UI_RefreshInventoryWindows`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00933310` Client_UI_RefreshInventoryWindows_Inferred | **accept-with-gaps** — CF/ABI/RET0x14/EAX-item-key/client+0xF14/callee/5 call sites sealed; product English + payload/UI depth open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): decompiler-void / ECX-thiscall / EAX=client / window-walk / RET4 / sole-RecvInventory parent / product-without-Inferred claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00933310` — sealed facts

1. **Body:** `0x00933310`–`0x0093336f` inclusive (**96 B** / `0x60`).
2. **ABI:** **EAX** = item/object*; **CL** = u8 flag; stack `client, a1, a2, a3, a4`; void; **`RET 0x14`**.
3. **Semantics:** pack value (uint key = EAX) + fold stack/CL fields → **insert-or-find** into **`client+0xF14`** via `StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred` (`0x00402b30`). Pair discarded.
4. **Callees:** `0x00402b30` only (MEGA-040 dualed).
5. **Callers / xrefs:** **5** UNCONDITIONAL_CALL:
   - `Client_RecvInventoryUseItemResponse` @ `0x008102de`
   - `FUN_00810170` @ `0x00810209`
   - `FUN_0080d570` @ `0x0080d750`, `0x0080d8d3`
   - `FUN_0080d930` @ `0x0080daec`
6. **Site constants:** all five sites use `(client, 1, 0, -1, -1)` + `CL=0`; EAX from remove/item path.
7. **Shared map:** same **client+0xF14** shell as `Client_NotifyActiveMissionChanged` direct `00402b30` sites.
8. **Name:** `Client_UI_RefreshInventoryWindows_Inferred` (Ghidra `FUN_00933310`). Product English open → `_Inferred`. Scaffold `Named_CalleeOf_Client_RecvInventoryUseItemResponse_00933310` **retired**.
9. **Decompile ≡ raw CF** (single insert); **ABI from disasm + read_memory + call-site context** (decompiler void form rejected).
10. **Hash:** `a04b98d42bef5dfd0234a2fbaae83339f2d6cccd70eb691f4bd712d07fe98c30`.

### Gaps

- Product English for map T / payload fields beyond uint key.  
- Uninit local `[ESP+0xc]` folded into value (odd; preserved).  
- Whether visible UI refresh is insert buynode side-effect vs deferred map consumer.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00933310_Client_UI_RefreshInventoryWindows_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00933310_Client_UI_RefreshInventoryWindows_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00933310_FUN_00933310.md` |
| Annotated | `docs/reconstruction/raw/aa_00933310_FUN_00933310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_RefreshInventoryWindows_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00933310.cpp` |
| Function | `docs/reconstruction/functions/aa_00933310_FUN_00933310.md` |
| Function named | `docs/reconstruction/functions/aa_00933310_Client_UI_RefreshInventoryWindows_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_RecvInventoryUseItemResponse  0x00810280
  count<1:
    InventoryGrid_RemoveItemByCoid → item*
    FUN_007fee30 (UI sheet cleanup mode 4)
    Client_UI_RefreshInventoryWindows_Inferred  [OWN MEGA-099]
  Client_RefreshOpenMissionUiWindows  0x0093a940

FUN_0080d570 / FUN_0080d930  (tinker / gadget S2C)
  InventoryGrid_RemoveItem / Contains paths
  Client_UI_RefreshInventoryWindows_Inferred  [OWN MEGA-099]
  Client_RefreshOpenMissionUiWindows

Client_NotifyActiveMissionChanged  0x00944770
  LEA EAX,[client+0xF14]; CALL 00402b30   [same map; direct]
    StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred  [dualed MEGA-040]
      ↑ also sole callee of 00933310
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00933310-mega-099-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00933310` | Port as **thin inventory UI map insert wrapper**: EAX=item*, CL=flag, stack `(client, a1, a2, a3, a4)`, **`RET 0x14`**. Map at **`client+0xF14`**. Delegate to isnil31 uint InsertOrFind (`00402b30`). Do **not** model as ECX thiscall or as a window-list walker. Site defaults: `(1,0,-1,-1)` + CL=0. |
| Pair with | dualed `00402b30`; `Client_RecvInventoryUseItemResponse` `00810280`; `Client_RefreshOpenMissionUiWindows` `0093a940`; residual tinker/gadget parents `0080d570` / `0080d930` / `00810170`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage ledgers when integrating MEGA-099  
- retire residual `Named_CalleeOf_*_00933310` index rows in favor of `Client_UI_RefreshInventoryWindows_Inferred`  
- `systems/inventory-transfer` residual tables  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00933310`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + callee dual cross-check. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (EAX item key; RET 0x14; map +0xF14).  
- Odd behavior preserved: uninit local folded into value; insert pair discarded; decompiler void form rejected.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
