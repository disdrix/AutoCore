# Review A (reconstruction fidelity): `aa_0051aed0` Object_PlayPickupSpecialFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aed0` |
| **VA** | `0x0051aed0`–`0x0051b1b9` |
| **Canonical name** | `Object_PlayPickupSpecialFX` |
| **Ghidra name** | `FUN_0051aed0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W25-J) |
| **Counterpart** | `reviews/B_aa_0051aed0_Object_PlayPickupSpecialFX.md` |
| **System** | client / special-fx / item-pickup |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + xrefs; string table of `generic_pickup_*` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On a world object, select and load pickup SpecialFX script names from clone-base **type** and **rarity**, activate/attach them via host cascade + object vtbl `+0xF8`, optionally play mission-complete-audio host, and for type-tag `+0x3F4==8` recolor MatAmbient/Diffuse/Emissive from paint-id lookup.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051aed0_FUN_0051aed0.md` (+ W25-J append) |
| Annotated | `docs/reconstruction/raw/aa_0051aed0_FUN_0051aed0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_PlayPickupSpecialFX.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_0051aed0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051aed0_Object_PlayPickupSpecialFX.md` |
| Live | `decompile_function` `0x0051aed0`; `read_memory` entry/tail + `0x00aaa7a8` |

---

## 3. Signature

```c
// Ghidra: void __thiscall FUN_0051aed0(int *param_1, char param_2, char param_3)
// Bytes: mov ebx,ecx … ret 8
void __thiscall Object_PlayPickupSpecialFX(void *this, char bPlayAudio, char bForceQuestFx);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B D9` at entry | **High** |
| `ret 8` (two stack bytes/chars) | tail `C2 08 00` | **High** |
| void | no EAX result path | **High** |
| clone at `this+0xA8` | `param_1[0x2a]` | **High** |

---

## 4. Control flow (sealed)

1. Optional related-object prep via vtbl `+0x1CC` → nested `+0xFC`.
2. Base FX name: if `bForceQuestFx` **or** type `clone+0x38==4` → `generic_pickup_quest`; else switch type (gadget/commodity/tinkering/money/default±enhanced).
3. Load base with `NDSpecialFX_LoadFromScriptName(name, 4, 0)`. If def short `+0x3F4==0x10`, reload as `generic_pickup_trick_material`.
4. If rarity short `def+0x4B8 > 1`, load rarity overlay script.
5. If primary non-null: activate host (`FUN_004b8dc0(1,0)`), attach rare then primary via vtbl `+0xF8`; if audio table `+600` and `bPlayAudio`, `FUN_004b7e50`.
6. If `def+0x3F4==8` and related gfx present: paint-id `this+0xC8` → RGB×(1/255) into MatAmbient/Diffuse/Emissive + `FUN_0096f660`.

| Stage | Match | Conf |
|---|---|---|
| Type / quest / trick material string map | **Yes** (literals in body) | **High** |
| Rarity overlay map | **Yes** | **High** |
| Attach order rare→primary | **Yes** | **High** |
| Paint path scale 1/255 | **Yes** (`DAT_00aaa7a8` bytes) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr | Bytes | Decode |
|---|---|---|
| `0x0051aed0` | `83 EC 10 53 55 56 8B D9` | prolog; EBX=this |
| vtbl call | `FF 90 CC 01 00 00` | call [eax+0x1CC] |
| tail | `5F 5E 5D 5B 83 C4 10 C2 08 00` | epilogue; **ret 8** |
| `0x00aaa7a8` | `81 80 80 3B` | float ≈1/255 |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | Site | Args |
|---|---|---|
| `CLoadNode__initSelection` | `0x005c69aa` | `(1, 0)` |
| `FUN_00585e00` | `0x00585fe1` | `(distNear, flag)` |

Callees: `NDSpecialFX_LoadFromScriptName`, `FUN_004b8dc0`, object vtbl `+0xF8/+0x60/+0x1CC`, `Client_GetMissionCompleteAudioTable`, `FUN_004b7e50`, `VehiclePaintColor_LookupById_Inferred` (`FUN_00519d20`), `FUN_009700f0`×3, `FUN_0096f660`.

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI thiscall + ret 8 + void | **High** |
| Script-name domain / type+rarity map | **High** |
| Role name `Object_PlayPickupSpecialFX` | **High** domain / **Open** product C++ spelling |
| Exact English for vtbl slots / +0x3F4 tag | **Partial** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product class/method name (not plate-string sealed).
2. Semantic of vtbl `+0x60` enhanced gate and `+0x1CC` related object.
3. Full meaning of def shorts `+0x3F4` / `+0x4B8` beyond observed branch labels.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF + strings + ABI sealed; product method English open.
