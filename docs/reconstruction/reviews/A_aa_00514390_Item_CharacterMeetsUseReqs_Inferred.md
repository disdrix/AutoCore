# Review A (reconstruction fidelity): `aa_00514390` Item_CharacterMeetsUseReqs_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514390` |
| **VA** | `0x00514390` |
| **Body** | `0x00514390`–`0x005145a3` (532 bytes) |
| **Canonical name** | `Item_CharacterMeetsUseReqs_Inferred` (Ghidra `FUN_00514390`; **Inferred**) |
| **Review date** | `2026-07-29` (W20-O dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00514390_Item_CharacterMeetsUseReqs_Inferred.md` |
| **System** | inventory / equip / use gates |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Purpose

Boolean **item-vs-character requirement gate** used by equip, level-up revalidation, and use-item paths. Returns 1 if the character may use/equip the item under current rules; else 0.

Not a stack-capacity check, not a transfer helper, not the equip mutator itself (`Character_TryEquipItem` is a caller).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00514390_FUN_00514390.md` |
| Annotated | `docs/reconstruction/raw/aa_00514390_FUN_00514390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_CharacterMeetsUseReqs_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00514390.cpp` |
| Function record | `docs/reconstruction/functions/aa_00514390_FUN_00514390.md` |
| Live decompile | `decompile_function` @ `0x00514390` ≡ raw |
| Machine | `read_memory` 512 B @ `0x00514390` + tail @ `0x00514590` |
| Callers | `get_function_callers` / xrefs |
| Sealed callees | `aa_004c4070`, `aa_004c41c0`, `aa_004c4140` (accuracy / perception / theory) |

---

## 3. Byte / ABI seal

```
00514390  56 57                 push esi / edi
          8B 7C 24 0C           mov  edi, [esp+0xC]     ; character
          8B F1                 mov  esi, ecx           ; item
...
          B0 01 / 32 C0         success / fail AL
          C2 08 00              ret  8                  ; two stack dwords
0051459c  5B 5F B0 01 5E C2 08 00   success epilogue
005145a4  CC…                   padding / next function
```

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall` item + ch + flag; **`ret 8`** | **High** | prolog ECX→esi; `[esp+0xC]` ch; `C2 08 00` |
| Early accept: ch`+0x6b4`>0 or type`0x1a` | **High** | decomp + `cmp` imm `0x1a` / offset `0x6b4` |
| Level clamp imm **0x50** | **High** | `BB 50 00 00 00` / compare `0x51` |
| Stat shorts `+0xec/+0xee/+0xf2/+0xf0` | **High** | loads + calls to sealed getters |
| Bit 19 of `item+0x17c` | **High** | `shr edx,13; test dl,1` |
| Special type imm **0x26** | **High** | `cmp [eax+0x62c],0x26` |
| Side-effect clear `*(item+0x70)+0x1d=0` | **High** | `mov byte ptr [ecx+0x1d],0` on special arm |
| Body 532 B | **High** | last `ret 8` ends `0x005145a3` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Early override / type 0x1a → 1 | **Yes** |
| Race vfunc+0x14 vs char+0x532; -1 wild | **Yes** |
| Faction clone+0x3e0 vs char+0x531; -1 wild | **Yes** |
| Level min(sum,0x50) ≤ vtbl+0x27c | **Yes** |
| Acc / Perc / Theory / Tech floors | **Yes** |
| Optional powerplant bit19 + FUN_0052ada0 | **Yes** |
| Optional special arm flag+0x80+type0x26 | **Yes** |
| Return 1/0 | **Yes** |

---

## 5. Caller usage (context)

| Caller | Role |
|---|---|
| `FUN_004fabc0` Character_TryEquipItem | equip gate |
| `FUN_00533220` SetLevelWithFlags | re-check equipped gear (flag 1) |
| `FUN_0092fb30` / `FUN_00941d50` / UI sites | use / confirm paths |

---

## 6. Gaps

1. Product/PDB English name — open (`_Inferred`).
2. Product names for item req shorts and type ids `0x1a` / `0x26`.
3. Full dual of `FUN_00402c40` / `FUN_00411900` / `FUN_0052ada0` — out of OWN.
4. Whether race vfunc is called twice intentionally (side effects) — decomp shows two calls when first ≠ -1 path evaluates second compare.
5. Runtime / differential golden — open.

**Verdict:** **accept-with-gaps** — ABI, CF stages, constants, sealed getter callees, and side-effect on special arm sealed static; product English and nested iter duals remain open.
