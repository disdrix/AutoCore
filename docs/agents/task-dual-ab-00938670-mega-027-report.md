# Dual A/B report — MEGA-027 OWN-ONLY (`0x00938670`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-027**  
**Scope:** VA `0x00938670` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-027**.  
**Work item:** residual dual seal — **SetLongitudinal(0)+HB/flag109 interact** open **CVOGStore**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00938670` Client_Interact_OpenCVOGStore_Inferred | **accept-with-gaps** — CF/ABI/ESI-this/RET10/RTTI-CVOGStore/park triple/0x2024/dialog 0xB·0xC/2 callers sealed; product dialog English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Named_CalleeOf-final / ECX-thiscall / cdecl-bare-RET / always-park / UseObject-0x2072 / inventory-UI / single-caller / always-dialog-0xB claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00938670` — sealed facts

1. **Body:** `0x00938670`–`0x009387dc` inclusive (**365 B** / `0x16D`); pad `CC` @ `0x009387de`.
2. **ABI:** **ESI** = client controller (live-in); stack **TFID_16** (4 dwords); void; **`RET 0x10`** (`C2 10 00`). **Not** ECX-thiscall.
3. **Semantics:**
   - If vehicle entity `*( *(ESI+0xe98)+0x250 )`: `SetFlag_109(1)`, `SetHandbrake(1)`, `SetLongitudinalInput(0)`.
   - Resolve TFID; `__RTDynamicCast` **ClonedObjectBase → CVOGStore** (TDs `0x00af8e10` / `0x00afe0c8`).
   - Already-open early-outs on dialog hosts `+0x105c` / `+0x1060` (vtbl`+0x3d8` + bound-store cmp).
   - C2S packet **opcode 0x2024**, size **0x18**, via `ESI+0xc78` vtbl`+0x18`.
   - Stamp TFID; open dialog **0x0B** or **0x0C** via `FUN_007fef20(ECX=ESI, idx, 1, 0)` selected by `store+0x4e5`.
4. **Callers (2):** `Client_InteractClickPickTarget` @ `0x00924f8c` (type **0x16**, `ESI=0xd1a840`); `FUN_00946c00` @ `0x00947057` (case **3**, `ESI=EBX`).
5. **Xrefs:** 2× UNCONDITIONAL_CALL.
6. **Callees:** `VehicleEntity_SetFlag_109`, `VehicleEntity_SetHandbrake`, `VehicleEntity_SetLongitudinalInput`, `Object_ResolveFromTFID`, `__RTDynamicCast`, `FUN_007fef20`, virtuals.
7. **Name:** `Client_Interact_OpenCVOGStore_Inferred` (Ghidra `FUN_00938670`). Scaffold `Named_CalleeOf_Client_InteractClickPickTarget_00938670` **retired**.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.
9. **System:** `interaction-activation`.

### Gaps

- Product English for dialog indices **0x0B** / **0x0C**.  
- Product English for `CVOGStore+0x4e5` subtype flag.  
- Product name for `FUN_007fef20` dialog open hub.  
- Full 0x2024 field map (0x18 layout middle dword).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00938670_Client_Interact_OpenCVOGStore_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00938670_Client_Interact_OpenCVOGStore_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00938670_FUN_00938670.md` |
| Annotated | `docs/reconstruction/raw/aa_00938670_FUN_00938670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Interact_OpenCVOGStore_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00938670.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_InteractClickPickTarget_00938670.cpp` |
| Function | `docs/reconstruction/functions/aa_00938670_FUN_00938670.md` |
| Function named | `docs/reconstruction/functions/aa_00938670_Client_Interact_OpenCVOGStore_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_InteractClickPickTarget  0x009247b0  [dualed parent]
  └─ type switch *(clone+0xa8)+0x38
        case 0x16:
          MOV ESI, DAT_00d1a840
          FUN_00938670(tfid)  Client_Interact_OpenCVOGStore_Inferred  [OWN MEGA-027]

FUN_00946c00  sector event dispatcher  [residual]
  └─ case 3:
        MOV ESI, EBX
        FUN_00938670(tfid)  [OWN MEGA-027]

FUN_00938670
  ├─ VehicleEntity_SetFlag_109 / SetHandbrake / SetLongitudinalInput  [dualed vehicle]
  ├─ Object_ResolveFromTFID
  ├─ __RTDynamicCast → CVOGStore
  ├─ communicator vtbl+0x18  send 0x2024
  └─ FUN_007fef20  open dialog 0xB|0xC  [residual dialog hub]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00938670-mega-027-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00938670` | Port as **client store interact open**. **ESI=client**, stack **TFID_16**, **RET 0x10**. Park vehicle when entity present (flag109/HB/long=0). RTTI-require **CVOGStore**. Emit **C2S 0x2024** size 0x18. Open dialog **0x0B** or **0x0C** by `store+0x4e5`. Keep already-open same-store early-out. |
| Pair with | dualed `Client_InteractClickPickTarget` `0x009247b0`; residual dialog hub `0x007fef20`; vehicle park setters `0x004f3630` / `0x004f3620` / `0x004f5650`; sector dispatcher `0x00946c00`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/interaction-activation` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00938670`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly context + RTTI strings. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine twin `FUN_00938670.cpp` updated; `Named_CalleeOf_*` retired.  
- Odd behavior preserved: ESI-this (not ECX); park only if entity; dual dialog 0xB/0xC; re-check `+0x4e5` mid-function.  
- `_Inferred` where product UI English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
