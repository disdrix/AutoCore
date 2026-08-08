# Function record: Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c50f4` |
| **Canonical name** | `Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred` (**INFERRED**) |
| **Address** | `0x008c50f4` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / input-drive-control (UI OnCommand → host cast or mod-chip) |
| **Completion status** | **Partial** — three-rep + dual A/B sealed **gap-close 2026-08-05**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (not run; no Launcher) |
| **Inventory note** | Live Ghidra VA was missing from `inventory.jsonl` at dual start |

## Alias

| Name | Notes |
|---|---|
| `FUN_008c50f4` | Ghidra default / scaffold |
| “parent of host cast / UI mod-chip path” | Sibling dual shorthand (`aa_008c4fc0`, `aa_0091f6b0`) |

## Purpose

Specialized UI command body for **`(cmdClass=8, cmdId=0x9c40)`**:

1. If local player `+0x6b8` (host) and not `+0x6b9` (enhanced) → `Client_CastFirstHardpointSkillFlag200_Inferred`.
2. Else if `DAT_00d1b778` and `vtbl+0x3d8` → `Client_Input_TryUseModChip`.
3. If `self+0x514` child widget present → float get `vtbl+0x3c8` then set `vtbl+0x3b0`.
4. Always return **handled** (`AL=1`).

## Signature

```c
// Logical thiscall — gate @ 0x008c50d0 + body @ 0x008c50f4
// Ghidra defines only the body; gate is not a separate function.
// Body expects ESI=self with ESI already pushed; ends POP ESI; RET 8.
bool __thiscall Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred(
    void* self,      // ECX at gate → ESI in body
    int cmdClass,    // stack; matched == 8 before entry
    int cmdId);      // stack; matched == 0x9c40 before entry
// Returns 1. RET 8.
```

## Body

| Field | Value |
|---|---|
| Start | `0x008c50f4` |
| End exclusive | `0x008c516A` |
| Size | **118 B** (`0x76`) |
| Epilogue | `MOV AL,1; POP ESI; RET 8` |
| Pad | `CC×6` → next @ `0x008c5170` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008c50f4_FUN_008c50f4.md` |
| Annotated | `docs/reconstruction/raw/aa_008c50f4_FUN_008c50f4.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_008c50f4.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_008c50f4_Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008c50f4_Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred.md` |
| Agent report | `docs/agents/task-dual-ab-008c50f4-gap-close-report.md` |

Scaffold record: `functions/aa_008c50f4_FUN_008c50f4.md`.

## Callers / entry

| Kind | VA | Notes |
|---|---|---|
| CONDITIONAL_JUMP | `0x008c50e5` | Gate `JZ` when `(class,id)==(8,0x9c40)` |
| CALL | *(none)* | No Ghidra CALL xrefs |

Gate stub (context, not owned): `0x008c50d0` — thiscall trampoline; non-match → `FUN_0087b500`.

## Callees

| VA | Name | Role |
|---|---|---|
| `0x008c4fc0` | `Client_CastFirstHardpointSkillFlag200_Inferred` | Host path when `+0x6b8 && !+0x6b9` |
| `0x0091f6b0` | `Client_Input_TryUseModChip` | Else path; EDX=`DAT_00d1b778` after vtbl`+0x3d8` |
| (virtual) | `DAT_00d1b778` vtbl`+0x3d8` | Bool probe before mod-chip |
| (virtual) | widget@`self+0x514` vtbl`+0x3c8` / `+0x3b0` | Float get / set |

## Key layouts / constants

| Symbol | Role |
|---|---|
| `DAT_00d1b6d8` | Local character |
| `player+0x6b8` | Host-mode gate |
| `player+0x6b9` | Enhanced / armed — diverts to mod-chip branch |
| `DAT_00d1b778` | UI global for probe + TryUseModChip EDX |
| `self+0x514` | Optional child widget pointer |
| cmd class **8** | Gate match |
| cmd id **`0x9c40`** | Gate match (close-id family elsewhere) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile ≡ raw | **High** |
| ESI this + RET 8 ABI (bytes) | **High** |
| Jump-in entry; no CALL sites | **High** |
| Host vs mod-chip flag split | **High** |
| Callee dual identities | **High** |
| Product UI class / cmd English | **Tentative** / **Open** |
| Widget product type | **Open** |
| Runtime / bit-exact | **Open** |

## Dual A/B

| Review | Verdict |
|---|---|
| A (fidelity) | **accept-with-gaps** |
| B (adversarial) | **accept-with-gaps** |
| **Unit verdict** | **accept-with-gaps** |
