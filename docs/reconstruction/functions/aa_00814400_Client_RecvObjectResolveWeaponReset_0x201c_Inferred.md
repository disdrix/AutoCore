# Function record: Client_RecvObjectResolveWeaponReset_0x201c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00814400` |
| **Canonical name** | `Client_RecvObjectResolveWeaponReset_0x201c_Inferred` |
| **Ghidra symbol** | `FUN_00814400` |
| **Address** | `0x00814400`–`0x00814466` (102 B exclusive end) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client net / combat weapon state |
| **Wire** | S2C **`0x201C`** |
| **Completion status** | **partial** — dual A/B accept-with-gaps (W24-Q 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Body sealed via `read_memory`; package / runtime open |

## Alias

| Name | Notes |
|---|---|
| `FUN_00814400` | Ghidra default |
| `Named_CalleeOf_Client_PacketDispatch_00814400` | Weak parent-seed alias (superseded) |

## Purpose

S2C **0x201C** handler:

1. Resolve world object from packet TFID/type (`+0x90/+0x94/+0x98`) via `CVOGReaction_ResolveObjectTarget` (host `*(game+0xD34)`).
2. If absent → create path `FUN_008120d0`; if present → sector-update `FUN_00811e00`.
3. If object non-null and `vtbl+0x1E0` returns a weapon: clear fire-flag pair, run `Weapon_FireHelper` with **suppressFire=1**.

## Signature

```c
// Dispatch-custom registers (not portable C ABI):
//   EDI = packet body*
//   EBX = game/client ctx*
void Client_RecvObjectResolveWeaponReset_0x201c_Inferred(void);
```

## Machine body (summary)

```
load [edi+0x98/0x94/0x90]; this=[ebx+0xd34]
call CVOGReaction_ResolveObjectTarget
jz create (FUN_008120d0) else update (FUN_00811e00)
if obj: weapon = vtbl+0x1e0(); if weapon: SetFireFlagPair(0); FireHelper(&DAT_00d1a680,1)
ret
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00814400_FUN_00814400.md` |
| Annotated | `docs/reconstruction/raw/aa_00814400_FUN_00814400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvObjectResolveWeaponReset_0x201c_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00814400.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00814400_Client_RecvObjectResolveWeaponReset_0x201c_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00814400_Client_RecvObjectResolveWeaponReset_0x201c_Inferred.md` |

## Callers / callees

**Callees:** `CVOGReaction_ResolveObjectTarget`, `FUN_008120d0`, `FUN_00811e00`, `FUN_0056a260`, `FUN_0056d160`.

**Callers (live xrefs 2026-07-29):**

| Function | Entry | Call site | Opcode |
|---|---|---|---|
| `Client_PacketDispatch` | `0x00815710` | `0x00815774` | **0x201C** |

## Related (not owned)

| Unit | VA | Relation |
|---|---|---|
| `FUN_00814470` | `0x00814470` | Sibling resolve/create for **0x201A** (no weapon tail) |
| `Weapon_SetFireFlagPair_Inferred` | `0x0056a260` | Fire clear |
| `Weapon_FireHelper_Inferred` | `0x0056d160` | Suppress-fire helper path |
| `FUN_008120d0` | `0x008120d0` | Allocate new object from packet CBID |
| `FUN_00811e00` | `0x00811e00` | ProcessSectorUpdate path |

## Confidence

| Claim | Level |
|---|---|
| Control flow / bytes / plain ret | **High** |
| Opcode 0x201C sole caller | **High** |
| Packet +0x90/+0x94/+0x98 resolve inputs | **High** |
| Create-or-update then optional weapon reset | **High** |
| FireHelper suppress=1 (not primary fire emit) | **High** (sibling dual) |
| Name / product packet English | **Probable** / open |
| `vtbl+0x1E0` / `DAT_00d1a680` product meaning | **Medium** / open |
| Runtime wire differential | **Open** |
