# Annotated low-level: Object_PlayPickupSpecialFX (`FUN_0051aed0`)

| Field | Value |
|---|---|
| Stable ID | `aa_0051aed0` |
| VA | `0x0051aed0`–`0x0051b1b9` |
| Canonical | `Object_PlayPickupSpecialFX` |
| System | client / special-fx / item-pickup |
| Date | 2026-07-29 (W25-J) |

## Machine-level notes

- Source: live `decompile_function` + raw capture; append seal on raw.
- **ABI:** thiscall; EBX=this; stack `(bPlayAudio, bForceQuestFx)`; **`ret 8`**.
- **No `disassemble_bytes`.** Entry/tail via `read_memory` only.
- Clonebase: `this+0xA8` (`[0x2a]`). Def: `clone+0x3C`.
- Type dword `clone+0x38`; rarity `def+0x4B8`; type-tag `def+0x3F4`.
- RGB scale `DAT_00aaa7a8` ≈ **1/255**.

## Pseudocode (annotated)

```c
// thiscall object*; char bPlayAudio; char bForceQuestFx; ret 8
void Object_PlayPickupSpecialFX(int *self, char bPlayAudio, char bForceQuestFx)
{
  // 1) Optional related-object prep (vtbl+0x1CC → nested +0xFC)
  // 2) Base script from type / force-quest / trick-material override
  // 3) Rarity overlay if short > 1
  // 4) Activate host + attach rare then primary (vtbl+0xF8)
  // 5) Optional audio if table+600 && bPlayAudio
  // 6) Optional paint MatAmbient/Diffuse/Emissive when tag==8
  // See raw body for authoritative CF; clean named plate for readable port.
}
```

## Callers

| Site | Function | Notes |
|---|---|---|
| `0x005c69aa` | `CLoadNode__initSelection` | `(1, 0)` |
| `0x00585fe1` | `FUN_00585e00` | distance + helper flag |

## Dual

- A/B: accept-with-gaps (W25-J)
- Clean: `reconstructed-exact/Object_PlayPickupSpecialFX.cpp`
