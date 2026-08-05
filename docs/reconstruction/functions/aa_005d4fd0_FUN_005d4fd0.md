# Function record: FUN_005d4fd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4fd0` |
| **Canonical name** | `FUN_005d4fd0` |
| **Inferred name** | `Object_UnloadGraphics_Entry_Inferred` |
| **Address** | `0x005d4fd0`–`0x005d5025` exclusive (**85 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / object graphics lifecycle |
| **Completion status** | **Dual reviewed** W37-AB — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |
| **Terminal coverage** | false |

## Purpose

Vtable-installed logged unload-graphics entry: resolve name → log `"UnloadGraphics on %s (%d)"` → `Object_UnloadGraphics_Inferred` → tail base `vtbl+4`.

## Signature

```c
void __fastcall Object_UnloadGraphics_Entry_Inferred(void* mi_this); // ECX; tail JMP
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005d4fd0_FUN_005d4fd0.md`
- Annotated: `docs/reconstruction/raw/aa_005d4fd0_FUN_005d4fd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_UnloadGraphics_Entry_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005d4fd0.cpp`
- Named record: `docs/reconstruction/functions/aa_005d4fd0_Object_UnloadGraphics_Entry_Inferred.md`
- Dual A/B: `reviews/A_aa_005d4fd0_Object_UnloadGraphics_Entry_Inferred.md`, `reviews/B_aa_005d4fd0_Object_UnloadGraphics_Entry_Inferred.md`

## Callers / callees

| Kind | Targets |
|------|---------|
| Callees | vcall `+0x160`, `FUN_007a4480`, `FUN_005825d0`, tail vfunc `+4` |
| CODE callers | none |
| DATA xrefs | 8 vtable installs |

## Confidence

| Claim | Level |
|---|---|
| Control flow / body hex | High |
| UnloadGraphics log role | High (string) |
| Calls W31-T core | High |
| Tail JMP (not RET) | High (bytes `FF 60 04`) |
| Format `%d` second arg | Residual gap |
| Product vfunc English | Open |
