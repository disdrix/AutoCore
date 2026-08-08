# Function record: Ui_ResolveEntityNameColor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930fc0` |
| **Canonical name** | `Ui_ResolveEntityNameColor_Inferred` |
| **Ghidra name** | `FUN_00930fc0` |
| **Address** | `0x00930fc0`–`0x009313bf` (**1023 B**) |
| **Module** | `autoassault.exe` (base `0x400000`) |
| **System** | client UI / entity label color |
| **Dual** | A/B **accept-with-gaps** (WQ9D-J 2026-08-04) |
| **Bit-for-bit / runtime** | Open |

## Purpose

Store name/label ARGB for an entity vs local player. Specials: purple (`sub+0x6b4>0`), gray dead (`0040b1b0`), lime owner TFID, level-band RGB; else `FUN_00930f40` palette.

## Signature

```c
void __thiscall Ui_ResolveEntityNameColor_Inferred(
    void *entity /*ECX*/,
    void *clientCtx /* +0xe98 local */,
    uint32_t *outArgb,
    char flagAllowSelfStyle,
    char flagForcePalette);
// ret 16 (C2 10 00)
```

## Sealed constants

| Value | Role |
|---|---|
| `0xFFC364EB` | marked purple |
| `0xFFEBEBEB` | dead gray |
| `0xDFCAFF0B` | owner lime (α=0xDF) |
| `255.0f` @ `0x00aaa6f8` | RGB scale |

## See also

Scaffold record `aa_00930fc0_FUN_00930fc0.md`; dual reviews A/B; clean `Ui_ResolveEntityNameColor_Inferred.cpp`.
