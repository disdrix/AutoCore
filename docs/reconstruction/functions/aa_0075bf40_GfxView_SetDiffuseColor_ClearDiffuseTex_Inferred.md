# Function record: GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075bf40` |
| **Canonical name** | `GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred` (Inferred) |
| **Ghidra name** | `FUN_0075bf40` |
| **Address** | `0x0075bf40` |
| **Body range** | `0x0075bf40`–`0x0075bf95` exclusive (**85** B / `0x55`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | GfxView / material color worker |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | A/B reviews (2026-08-04 W37-L) |
| **Last reviewed** | `2026-08-04` |

## Alias

- `FUN_0075bf40`
- Related: `GfxView_SetNear_Inferred` (`0x0075b3b0`), far twin `FUN_0075b390`; GfxView ctor `FUN_00968a50`

## Purpose

Set GfxView packed color field at `+0x148` and mark dirty at `+0x129`. If an effect object exists at `+0x134`, resolve parameter `"DiffuseTexture"` and clear its texture bind before the color write. Always returns 0.

## Signature

```c
int __thiscall GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred(
    void *self, uint32_t color);
// ret 4; always 0
```

## Algorithm

1. If `*(self+0x134) == 0` → index = -1.
2. Else → `FUN_00752370(effect, &index, "DiffuseTexture")`.
3. If index >= 0 → `FUN_00970060(index, 0)`.
4. `*(self+0x148) = color`; `*(u8*)(self+0x129) = 1`.
5. Return 0.

## Related

- Particle fluid init `FUN_004c0a90` sets gray `0x808080` after near/far.
- Liquid child path `FUN_004c1960` sets color `0` when activating.
