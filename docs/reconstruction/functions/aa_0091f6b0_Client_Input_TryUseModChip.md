# Function record: Client_Input_TryUseModChip

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091f6b0` |
| **Canonical name** | `Client_Input_TryUseModChip` (INFERRED) |
| **Address** | `0x0091f6b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` (mod-chip / skill cast side-path) |
| **Completion status** | **Partial** — three-rep + dual A/B sealed 2026-07-29; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_0091f6b0` | Ghidra default |
| `Named_CalleeOf_Client_Input_DriveControlTick_0091f6b0` | Scaffold alias — keep as historical only |
| “mod chip use” | Task / string-driven nickname |

## Purpose

Attempt to use the vehicle **mod chip** from client input:

1. Gate local player + two block flags.
2. Stamp `client+0xc2c = 9999999`.
3. If `player+0x6b9` → send C2S **`0x202c`** (self TFID) without validate.
4. Else require `player+0x250` vehicle and `FUN_0040ce50` ≠ −1; else modal **"You have no mod chip!"**.
5. Else `Skill_LocalCastValidate` with skill from `FUN_0040ce50`; success → **`0x202c`**; fail → `Skill_FormatFailureMessage` + optional toast.

## Signature

```c
// __fastcall — EDX = client*; ECX unused
void __fastcall Client_Input_TryUseModChip(undefined4 unused, int client);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0091f6b0_FUN_0091f6b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0091f6b0_FUN_0091f6b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_TryUseModChip.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0091f6b0_Client_Input_TryUseModChip.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0091f6b0_Client_Input_TryUseModChip.md` |
| Agent report | `docs/agents/task-dual-ab-0091f6b0-try-use-mod-chip-report.md` |
| Scratch | `tmp/a_0091f6b0.md` |

Legacy scaffold (superseded name):  
`functions/aa_0091f6b0_FUN_0091f6b0.md`, `reconstructed-exact/FUN_0091f6b0.cpp`,  
`reconstructed-exact/Named_CalleeOf_Client_Input_DriveControlTick_0091f6b0.cpp`.

## Callers

| CALL VA | Parent | Notes |
|---|---|---|
| `0x00923666` | `Client_Input_DriveControlTick` `0x009223b0` | `DAT_00d1cafa` + edge `DAT_00d1cafb`; `EDX=client` |
| `0x008c5132` | `FUN_008c50f4` `0x008c50f4` | UI path; vtbl`+0x3d8` on `DAT_00d1b778` |

## Callees

| VA | Name | Role |
|---|---|---|
| `0x00807460` | `Client_SendSectorPacket` | C2S emit size `0x18` |
| `0x0040ce50` | `FUN_0040ce50` | Vehicle → mod-chip skill (`-1` = none); **sole caller** |
| `0x0051a790` | `Skill_LocalCastValidate` | Pre-cast gate; `0` = allow |
| `0x0054fa20` | `Skill_FormatFailureMessage` | Failure UX string |
| `0x007fdfb0` | `FUN_007fdfb0` | Modal toast host |
| `0x008f8200` | `FUN_008f8200` | Combat-log / chat toast |

## Key layouts / constants

| Symbol | Role |
|---|---|
| `DAT_00d1b6d8` | Local character |
| `player+0x250` | Vehicle ptr |
| `player+0x6b9` | Armed / bypass-validate flag (send immediately) |
| `player+0x6bb` | Hard block when ≠ 0 |
| `DAT_00d1b644+0xf5` | Global hard block when ≠ 0 |
| multi-inherit `+0x164` | Self TFID (16B) for packet |
| multi-inherit vtbl `+0x234` | Skip-busy / form char for LocalCastValidate |
| `client+0xc2c` | Written `9999999` (`0x98967f`) |
| Opcode **`0x202c`** | C2S mod-chip use (size `0x18`) |
| `FUN_0040ce50` | `vehicle+0x270` → nested `+0x3bc` skill; else `-1` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompile + full asm | **High** |
| Opcode `0x202c` both send sites | **High** (`read_memory` imm) |
| String → mod-chip purpose | **High** |
| LocalCastValidate `0` = allow | **High** (prior dual) |
| `EDX` = client (`+0xc2c`) | **High** |
| Packet +4 unwritten field meaning | **Open** |
| `+0x6b9` / `+0x6bb` / `+0xf5` English | **Tentative** |
| Product / PDB symbol | **Open** |
| Runtime / bit-exact | **Open** |
