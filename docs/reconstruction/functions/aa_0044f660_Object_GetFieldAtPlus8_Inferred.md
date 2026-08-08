# Function record: Object_GetFieldAtPlus8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044f660` |
| **Canonical name** | `Object_GetFieldAtPlus8_Inferred` |
| **Ghidra name** | `FUN_0044f660` |
| **Address** | `0x0044f660` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities partition seed / shared polymorphic util leaf |
| **Parent dual** | `0x00416110` `Class_00a9bbe8_CompleteDtor_Inferred` |
| **Completion status** | **Dual sealed (R10-027)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC thiscall virtual/shared leaf: return `*(uint32_t*)(this + 8)`. Paired with setter `0x00416150` on parent vftable `0x00a9bbe8`. Not exclusive to that class — 10 DATA embeds.

## Signature

```c
uint32_t __fastcall Object_GetFieldAtPlus8_Inferred(void *self /* ECX */);
// RET (no stack cleanup)
```

## Vftable `0x00a9bbe8` (evidence)

| Slot | VA | Role |
|---|---|---|
| +0 | `0x00416150` | set `this+8` from stack |
| +4 | `0x0044f660` | **this** — get `*(this+8)` |
| +8 | `0x005ffc80` | empty |
| +12 | `0x004320b0` | sd-dtor style |

## Port note

```csharp
// uint GetFieldAtPlus8(IntPtr self)  // ECX thiscall, plain RET
// return ReadUInt32(self + 8);
```

Do **not** invent product field names. Do **not** treat as exclusive to skills-abilities domain (partition seed only).

## Artifacts

See `aa_0044f660_FUN_0044f660.md` for full path list.
