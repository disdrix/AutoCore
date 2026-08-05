# Function record: Client_Input_ApplyRandomUpPhysicsKick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091d460` |
| **Canonical name** | `Client_Input_ApplyRandomUpPhysicsKick_Inferred` |
| **Address** | `0x0091d460`–`0x0091d655` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` |
| **Completion status** | **Partial** — three-rep refined + dual A/B accept-with-gaps (2026-07-29); runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Notes |
|------|-------|
| `FUN_0091d460` | Ghidra default / prior scaffold |
| `Named_CalleeOf_Client_Input_DriveControlTick_0091d460` | Xref-seed scaffold plate |
| `Client_Input_ApplyRandomUpPhysicsKick_Inferred` | Dual A/B 2026-07-29 — mostly-up random physics kick |

## Purpose

From `Client_Input_DriveControlTick` edge path: if local vehicle exists, has physics, drive not suppressed (`+0x101==0`), and component vfunc `+0x198` is false, build a **mostly upward** unit direction with random X/Z in **≈±0.3**, scale by **`12 / mass`**, and apply via **`FUN_00404cb0`** (physics `this` = `entity+0x8`, body vfunc **`+0x5c`**). Does **not** write drive axes.

## Signature (sealed CF)

```c
void Client_Input_ApplyRandomUpPhysicsKick_Inferred(void);
// no stack args; plain RET
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0091d460_FUN_0091d460.md`
- Annotated: `docs/reconstruction/raw/aa_0091d460_FUN_0091d460.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_Input_ApplyRandomUpPhysicsKick_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0091d460_Client_Input_ApplyRandomUpPhysicsKick_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0091d460_Client_Input_ApplyRandomUpPhysicsKick_Inferred.md`
- Prior scaffolds: `FUN_0091d460.cpp`, `Named_CalleeOf_Client_Input_DriveControlTick_0091d460.cpp`

## Callers / callees

| Direction | Address | Name / role |
|-----------|---------|-------------|
| Caller (sole) | `0x009223b0` | `Client_Input_DriveControlTick` (site ~`0x00923646`; ActionMap `DAT_00d1be2e`/`be2f` + 5s/`[0x1ad]` rate) |
| Callee | `0x007a4330` | RNG host getter (Ghidra: `CVOGReaction_RandomUnitScalar`) ×2 |
| Callee | `0x00404cb0` | Physics apply shell → body **vtbl+0x5c** |

## Key constants

| Addr | Value | Role |
|------|-------|------|
| `0x00aaaaf0` | ≈ 0.6/65535 | u16 scale |
| `0x00a0f714` | 0.3 | random center (`g_flOverheatCoolFrac` shared) |
| `0x00aaaad0` | 12.0 | magnitude |
| `0x00a0f2a0` | 1.0 | `g_flOne` |
| `0x00afda50` | (0,1,0,0) | base up float4 |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + asm | **High** |
| Physics thiscall ECX = `entity+8` | **High** |
| Mostly-up ±0.3 XZ + 12/mass | **High** |
| Not drive-axis producer | **High** |
| Product / bind English name | **Open** (`_Inferred`) |
| `FUN_00404cb0` vfunc English | **Open** (other VA) |
