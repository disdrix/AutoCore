# Function record: Object_UnloadGraphics_Entry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4fd0` |
| **Canonical name** | `Object_UnloadGraphics_Entry_Inferred` |
| **Ghidra name** | `FUN_005d4fd0` |
| **Address** | `0x005d4fd0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / object graphics lifecycle |
| **Wave** | W37-AB |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal coverage** | false |

## Purpose

Logged vtable entry that wraps `Object_UnloadGraphics_Inferred` with a name-bearing log line and chains to the next base method via tail JMP.

## Signature

```c
// __thiscall; ECX = MI object*; void; ends in tail JMP [*(this-0x40)+4]
void __fastcall Object_UnloadGraphics_Entry_Inferred(void* mi_this);
```

## Naming basis

- **Inferred** from embedded string `"UnloadGraphics on %s (%d)"` and sole CODE-call relationship to W31-T `Object_UnloadGraphics_Inferred`.
- No product demangle sealed.

## Artifacts

See `aa_005d4fd0_FUN_005d4fd0.md`.
