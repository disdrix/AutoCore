# Function record: AnimSlot_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ed90` |
| **Canonical name** | `AnimSlot_Ctor` (Inferred) |
| **Ghidra name** | `FUN_0074ed90` |
| **Address** | `0x0074ed90`–`0x0074ee31` (162 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client visual / animation slot |
| **Completion status** | **dual-sealed** W24-R 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf default-init for 0x78-byte anim slots. Rate `+0x3c=1.0`, mode `+0x4c=1`. Twin of production path used by `Object_LoadOrReplaceAnimSlot` / asset type `0x41`.

## Signature

```c
void __fastcall AnimSlot_Ctor(AnimSlot *slot /* ECX */);
```

## Artifacts

See `aa_0074ed90_FUN_0074ed90.md` for full table + A/B paths.
