# Function record: Client_NpcMissionDialog_InitRuntimeFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab0a0` |
| **Canonical name** | `Client_NpcMissionDialog_InitRuntimeFields_Inferred` |
| **Ghidra name** | `FUN_008ab0a0` |
| **Address** | `0x008ab0a0`–`0x008ab33d` (670 B / `0x29E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Dual** | R11-035 2026-08-05 **accept-with-gaps** |
| **Parent** | `Client_NpcMissionDialogHost_Ctor_Inferred` (`0x008ac3f0`) |
| **Classification** | leaf |
| **Terminal** | false |

## Signature

```c
// thiscall: ECX = NpcMissionDialogHost*
// no stack args; plain RET; leaf (no callees)
void Client_NpcMissionDialog_InitRuntimeFields_Inferred(NpcMissionDialogHost *host);
```

## Semantics (sealed)

1. Zero host scalar/chrome/list widget pointer fields (`+0x4b4..`, `+0x680..+0x700`, `+0x510`, `+0x644`, …).
2. Init **4×** reward/chrome banks: TFID pairs at `+0x558+i*8` = `(−1,−1)`; zeros at `+0x698/+0x6a8/+0x6b8/+0x6c8 + i*4`.
3. Init **8×** response banks: TFID pairs at `+0x518+i*8` = `(−1,−1)`; widgets `+0x708+i*4` = `0`; extra `+0x578/+0x57c` = `−1`.
4. Write three float4 defaults:
   - `+0x594 = (0, 0, 0, 0.6)` — `DAT_00a0f71c`
   - `+0x584 = (0, 1.0, 0, 0.157)` — `g_flOne`, `DAT_00aaa7e8`
   - `+0x5a4 = (0, 1.0, 0, 0.549)` — `g_flOne`, `DAT_00aaa7e4`
5. Clear turn-in flag `*(u8*)(host+0x64c) = 0`.

## Xrefs

- CALL: `FUN_008ac3f0` @ `008ac505` (`MOV ECX,EDI` @ `008ac4bb`)
- DATA: `0x00a4a8c8` (vtbl+0x3AC → this)

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008ab0a0_FUN_008ab0a0.md` |
| Annotated | `docs/reconstruction/raw/aa_008ab0a0_FUN_008ab0a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_NpcMissionDialog_InitRuntimeFields_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008ab0a0.cpp` |
| Ghidra record | `docs/reconstruction/functions/aa_008ab0a0_FUN_008ab0a0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_008ab0a0_Client_NpcMissionDialog_InitRuntimeFields_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008ab0a0_Client_NpcMissionDialog_InitRuntimeFields_Inferred.md` |
| Report | `docs/agents/task-dual-ab-008ab0a0-r11-report.md` |

## Gaps

- Product/PDB method name (vtbl+0x3AC).
- Float4 bank product English.
- Runtime / bit-exact / differential.
