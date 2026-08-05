# Function record: HostBase_EnsureAuxPtrs_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00756320` |
| **Canonical name** | `HostBase_EnsureAuxPtrs_Inferred` |
| **Ghidra name** | `FUN_00756320` |
| **Address** | `0x00756320`–`0x007563bf` exclusive (**159 B** / `0x9F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / host base (`FUN_007560d0` family) |
| **Completion status** | **Dual A/B sealed (W32-Q)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Ensure host base aux pointers once:

| Slot | When | Construction |
|---|---|---|
| `host+4` | `(flags & 1) != 0` | `FUN_00986070` with EBX=`*DAT_00d1f624` |
| `host+8` | always | `operator_new(0x14)` + `FUN_00442c80` (`PTR_FUN_00a9f49c`) |

Idempotence: if `+4` **or** `+8` already non-null → return `0xFFFFFFFF` without allocating.

## Signature

```c
uint32_t __thiscall HostBase_EnsureAuxPtrs_Inferred(void *host, uint32_t flags);
// RET 4; 0 = ok, 0xFFFFFFFF = already populated
```

## Related

- Base ctor: `FUN_007560d0` (zeros slots; PalantirEnv starts here)
- Phase prelude: `PalantirEnv_InitPhases_Inferred` (`0x0048fc90`)
- Dual partner: `PalantirEnv_ApplyDefaultScalars_Inferred` (`0x0048f2d0`)

## Artifacts

See `aa_00756320_FUN_00756320.md`.
