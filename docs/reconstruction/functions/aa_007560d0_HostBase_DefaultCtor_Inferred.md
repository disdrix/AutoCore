# Function record (named): HostBase_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007560d0` |
| **Semantic name** | `HostBase_DefaultCtor_Inferred` |
| **Ghidra name** | `FUN_007560d0` |
| **Address** | `0x007560d0`–`0x0075617f` exclusive (**175 B** / `0xAF`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / shared host base |
| **Naming basis** | Multi-caller first-stage ctor (PalantirEnv, UI host `new(0x80)`, phase objects); structural host base with fog-default float4 + hard-kill interpolate; not product demangle |
| **Status** | Dual sealed W32-O (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See `aa_007560d0_FUN_007560d0.md`.

## Signature

```c
void *__fastcall HostBase_DefaultCtor_Inferred(void *self /*ECX*/);
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W32-O.
