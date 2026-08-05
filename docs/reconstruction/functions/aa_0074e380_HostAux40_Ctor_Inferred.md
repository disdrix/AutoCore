# Function record (named): HostAux40_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e380` |
| **Semantic name** | `HostAux40_Ctor_Inferred` |
| **Ghidra name** | `FUN_0074e380` |
| **Address** | `0x0074e380`–`0x0074e3d6` exclusive (**86 B** / `0x56`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / host-base aux (+4 via PoolHost 0x40) |
| **Naming basis** | Peer of `HostAux14_Ctor_Inferred` (host+8); sole consumer chain `PoolHost_Acquire0x40` → `HostBase_EnsureAuxPtrs` host+4; embeds `NestedHash_Ctor_Sentinel0xC` @ +0x14 |
| **Status** | Dual sealed W35-R (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See dual report W35-R and scaffold `aa_0074e380_FUN_0074e380.md`.

## Signature

```c
void *HostAux40_Ctor_Inferred(void *self); // stack self*; RET 4; returns self
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W35-R.
