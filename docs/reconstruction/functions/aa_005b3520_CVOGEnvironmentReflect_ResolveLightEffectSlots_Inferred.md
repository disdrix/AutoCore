# Function record: CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3520` |
| **Canonical name** | `CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred` |
| **Ghidra name** | `FUN_005b3520` |
| **Address** | `0x005b3520` |
| **Body range** | `0x005b3520`–`0x005b357a` inclusive (**91 B** / `0x5B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / CVOGEnvironmentReflect |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (W37-F) |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | A/B reviews under `docs/reconstruction/reviews/` |
| **Last reviewed** | `2026-08-04` |

## Purpose

Once-only copy of nested Palantir light **effect cores** (`light+0x8c`) into Reflect host slots `+0x154` (dir) and `+0x150` (hemi), then bind hemi core onto aux via `FUN_0074e310([self+4], core)`.

## Signature

```c
void __thiscall CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred(
    CVOGEnvironmentReflect* this);
```

## Algorithm

```
if (self+0x154 != 0) return
parent = *(self+0x15c)
host = *(parent+0xe894)
if (host+0x108 == 0) return
if (host+0x104 != 0) return          // byte-sealed residual gate
self+0x154 = *(*(host+0x108)+0x8c)
host = *(parent+0xe894)              // reload
self+0x150 = *(*(host+0x104)+0x8c)
FUN_0074e310(*(self+4), self+0x150 value)
```

## Artifacts

See scaffold record `aa_005b3520_FUN_005b3520.md` for full paths.
