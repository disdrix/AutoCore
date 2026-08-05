# Review B (skeptical / adversarial): `aa_00504f60` Vehicle_UnequipEquippedItem_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00504f60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00504f60_Vehicle_UnequipEquippedItem_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF (class map + ABI sealed; helper product residual) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is character inventory grid unequip | ECX=vehicle from `char+0x250`; vehicle slot clears | **Falsified** as grid-only |
| 2 | Type field is on item directly | Load `item+0xa8` then `+0x38` | **Falsified as direct** |
| 3 | All classes play `menu_unequip_weapon` | Class 6 uses `menu_unequip_item`; 10/0x10/0x1c no string here | **Falsified** |
| 4 | Class 0xc always succeeds | Bits 2/0x10/4 all clear → return null | **Falsified** |
| 5 | Returns raw item* always | COM adjust `*( *(obj+4)+4 ) + 4 + obj` then iface | **Falsified as raw only** |
| 6 | Same as S2C UnequipNotify body | Notify **calls** this for local vehicle path; non-local has separate switch | **Partial** — shared helpers, different demux |
| 7 | `ret 0` / cdecl | `ret 4` after thiscall | **Falsified** |
| 8 | Wheelset/armor cleared inline with fe* helpers | Routed through `FUN_005034a0(2/3)` | **Survives as indirection** — still unequip path |
| 9 | Hidden third caller | 2 UNCONDITIONAL_CALL | **Falsified** |
| 10 | `+0x1d5\|=4` is NetObject mask | Mask uses separate NetObject `SetMaskBits`; this is vehicle byte flag | **Falsified as net mask** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall vehicle + item, ret 4 | **High** | Wrong port |
| Class switch 6/10/0xc/0x10/0x1c | **High** | Wrong slot clear |
| Weapon slot bits → fe110 index 0/1/2 | **High** | Wrong hardpoint |
| Melee subtype 9 → fe800 | **High** | Melee left equipped |
| Ornament 10 vs race 0xb | **High** | Race/ornament mixup |
| Return iface COM tearoff | **High** | Cursor apply fails |
| FUN_005034a0 internal map | **Probable** | PP/wheel/armor residual |
| +0x1d5 bit English | **Open** | Flag consumer unknown |
| Runtime | **Open** | Unverified live |

---

## 3. Cross-check live prologue

```
00504f60  push ebx
00504f61  push esi
00504f62  mov  esi, ecx              ; vehicle this
00504f64  mov  ecx, [esp+0xc]        ; item*
00504f68  xor  ebx, ebx
00504f6a  cmp  ecx, ebx
00504f6c  jnz  cont
00504f6e  pop  esi
00504f6f  xor  eax, eax
00504f71  pop  ebx
00504f72  ret  4
cont:
00504f75  or   byte [esi+0x1d5], 4
00504f7c  mov  eax, [ecx+0xa8]       ; clonebase
00504f82  mov  edx, [eax+0x38]       ; type
00504f85  add  edx, -6
00504f88  cmp  edx, 0x16
...
```

---

## 4. Surviving contract for AutoCore

```c
// MSVC __thiscall
IUnknownish* Vehicle_UnequipEquippedItem(Vehicle* self, Item* equipped);
// null if unsupported / failed clear; else detached interface ready for hand (vtbl+0x2ac etc.)
```

Must mirror equip class map when porting unequip; do not invent grid writes here.

---

## 5. Verdict

**accept-with-gaps** — adversarial probes seal vehicle thiscall and class/subtype CF against string-only naming (`Inv_menu_unequip_*` is evidence, not full role). Keep helper product names open.
