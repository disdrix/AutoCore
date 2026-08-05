# Function record: PalantirEnv_ApplyDefaultScalars_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048f2d0` |
| **Canonical name** | `PalantirEnv_ApplyDefaultScalars_Inferred` |
| **Ghidra name** | `FUN_0048f2d0` |
| **Address** | `0x0048f2d0`–`0x0048f361` exclusive (**145 B** / `0x91`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir env host |
| **Completion status** | **Dual A/B sealed (W32-Q)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Apply default float/scalar bank on the **0x198** Palantir env host after child@`+0x100` exists (ctor tail) or on later re-apply (`parent+0xE894`). Optionally reset child via `FUN_00497c80`.

## Signature

```c
void __thiscall PalantirEnv_ApplyDefaultScalars_Inferred(void *env);
```

## Layout writes

| Offset | Value | Source |
|---|---|---|
| `+0x100` | (read only) child* | if non-null → `FUN_00497c80` |
| `+0x10c` | **100.0f** | `DAT_00aaa7ac` |
| `+0x110` | **200.0f** | `DAT_00aaa884` |
| `+0x60` | ~0.215646f | `_DAT_009c774c` |
| `+0x64` | ~0.254894f | `DAT_009c7748` |
| `+0x68` | ~0.254894f | `DAT_009c7748` |
| `+0x6c` | **1.0f** | `g_flOne` @ `0x00a0f2a0` |
| `+0x178` | **0** | immediate |

## Related

- Ctor peer: `PalantirEnv_Ctor_Inferred` (`0x00492dd0`, W31-P)
- Phase peer: `PalantirEnv_InitPhases_Inferred` (`0x0048fc90`, W31-P) — also zeros `+0x178`
- Child ctor: `FUN_00497920` (W32-P partition)
- Dual partner: `HostBase_EnsureAuxPtrs_Inferred` (`0x00756320`)

## Artifacts

See `aa_0048f2d0_FUN_0048f2d0.md`.
