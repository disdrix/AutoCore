# Function record: CVOGHB_SlewFacingYaw_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6b80` |
| **Canonical name** | `CVOGHB_SlewFacingYaw_ctor_Inferred` |
| **Ghidra name** | `FUN_005d6b80` |
| **Address** | `0x005d6b80` |
| **Body range** | `0x005d6b80`–`0x005d6c0f` (**144 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / creature facing |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (W28-K) |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_005d6b80_CVOGHB_SlewFacingYaw_ctor_Inferred.md`, `reviews/B_aa_005d6b80_CVOGHB_SlewFacingYaw_ctor_Inferred.md` |
| **Last reviewed** | `2026-07-29` |

## Purpose

Secondary facing-slew period HB ctor (size **0x28**, vtbl `009daee8`): base ctor → install vtbl → pulse **30 ms** → schedule sentinel −1000 → stash raw owner → attach MI-adjusted owner → zero `owner+0x11c` → one `CVOGCreature_SlewFacingYaw_Inferred(owner, 30)`.

## Signature

```c
void * __thiscall CVOGHB_SlewFacingYaw_ctor_Inferred(void *self, void *pOwnerRaw);
```

## Artifacts

- See `aa_005d6b80_FUN_005d6b80.md` for full table.
- Clean: `reconstructed-exact/CVOGHB_SlewFacingYaw_ctor_Inferred.cpp`
