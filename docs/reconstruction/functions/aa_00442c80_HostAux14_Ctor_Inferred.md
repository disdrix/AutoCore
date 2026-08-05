# Function record: HostAux14_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00442c80` |
| **Canonical name** | `HostAux14_Ctor_Inferred` |
| **Ghidra name** | `FUN_00442c80` |
| **Address** | `0x00442c80` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / host-base aux |
| **Wave** | W33-S OWN-ONLY dual |
| **Completion status** | **Reviewed** — dual A/B **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Construct the small **0x14** host-aux object used as `host+8` after `HostBase_EnsureAuxPtrs_Inferred`. Structural name from size + EnsureAuxPtrs consumer + vtbl `PTR_FUN_00a9f49c`. No product plate string in body.

## Signature

```c
void *HostAux14_Ctor_Inferred(void *self); // stack self*; RET 4; returns self
```

## Artifacts

See `aa_00442c80_FUN_00442c80.md` for full paths. Twin clean: `HostAux14_Ctor_Inferred.cpp`.

## Related

- `HostBase_EnsureAuxPtrs_Inferred` (`0x00756320`, W32-Q) — sole caller
- Base zero of slots: `FUN_007560d0`
- Peer phase enables that re-call EnsureAuxPtrs: `ParticleFluidPhase_Init_Inferred` (`0x004c2080`, this dual)
