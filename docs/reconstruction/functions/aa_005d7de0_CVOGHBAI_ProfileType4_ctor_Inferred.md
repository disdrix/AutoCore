# Function record: CVOGHBAI_ProfileType4_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7de0` |
| **Canonical name** | `CVOGHBAI_ProfileType4_ctor_Inferred` |
| **Ghidra name** | `FUN_005d7de0` |
| **Address** | `0x005d7de0` |
| **Body range** | `0x005d7de0`–`0x005d7df8` (**25 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | npc-ai / HBAI / profile-type-4 |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (W28-K) |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_005d7de0_CVOGHBAI_ProfileType4_ctor_Inferred.md`, `reviews/B_aa_005d7de0_CVOGHBAI_ProfileType4_ctor_Inferred.md` |
| **Last reviewed** | `2026-07-29` |

## Purpose

Thin type-4 HBAI ctor: `FUN_005d1990(this, owner)` then `*this = PTR_FUN_009db08c`. Factory size **0xC0**.

## Signature

```c
void * __thiscall CVOGHBAI_ProfileType4_ctor_Inferred(void *self, void *pOwner);
```

## Artifacts

- See `aa_005d7de0_FUN_005d7de0.md` for full table.
- Clean: `reconstructed-exact/CVOGHBAI_ProfileType4_ctor_Inferred.cpp`
