# Review A (reconstruction fidelity): `aa_00847240` UI_ItemTooltip_AppendTypeMetaLines_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00847240` |
| **VA** | `0x00847240` |
| **Body** | `0x00847240`–`0x008479f0` (**1968** / `0x7B0` bytes; plain `ret` / `c3` ×2) |
| **Canonical name** | `UI_ItemTooltip_AppendTypeMetaLines_Inferred` |
| **Ghidra name** | `FUN_00847240` |
| **Prior alias** | `Mission_Mission_Object_00847240` (**retired** — string-weak) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B, **R11-029**) |
| **Counterpart** | `reviews/B_aa_00847240_UI_ItemTooltip_AppendTypeMetaLines_Inferred.md` |
| **System** | `inventory-transfer` (client item tooltip / detail UI) |
| **Partition parent** | `0x00513fc0` `Item_RequiresBindOrTradeLock` (score parent; live customize callee) |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `get_function_by_address`, `get_function_callers`, `get_function_xrefs`, `get_function_labels`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **item tooltip type + meta line builder**:

1. Map item type-class (`holder+0x38`) and type-6 subtype (`blob+0x3f4`) to English labels; special-case weapons (`0xc`) with mount flags / spray / explosion.
2. Append rarity name + color (table `DAT_00b04214`, index `blob+0x4b8`) after `", "`.
3. Optionally (`showMeta`) append customize-on-equip / customized-for, not-tradable, charges.
4. Append non-empty patentee (`item+0x101`) as `"Patented By: "`.
5. Append RE / memorize restriction lines via dualed `FUN_00522950`.
6. Return a small **line-count delta** for layout.

**Not** a network handler. **Not** equip C2S. **Not** mission-only logic.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw (+ re-verify) | `raw/aa_00847240_FUN_00847240.md` | R11-029 append ≡ live decompile |
| Annotated | `raw/aa_00847240_FUN_00847240.annotated.md` | stage map sealed |
| Clean scaffold | `reconstructed-exact/FUN_00847240.cpp` | plate updated; decomp surface |
| Named clean | `reconstructed-exact/UI_ItemTooltip_AppendTypeMetaLines_Inferred.cpp` | stage CF |
| Retired scaffold | `reconstructed-exact/Mission_Mission_Object_00847240.cpp` | retired stub |
| Function records | `functions/aa_00847240_*.md` | dual sealed |
| Live decompile | Ghidra `0x00847240` | ≡ raw CF |
| Entry bytes | `read_memory` @ `00847240` | `sub esp,0x18c` + ESI=item |
| Epilogue | `read_memory` @ `008479d0` | two `C3`; `ADD EAX,1/2` |
| Call sites | `00843db0` / `0084bdf0` | `push 1; push item; call; add esp,8` |
| Strings | decompile + `DAT_00a32888`/`00a34230` | sealed |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range / size 1968 | **Confirmed** | `get_function_by_address` end `008479f0` |
| cdecl stack `(item, showMeta)` | **Confirmed** | caller `ADD ESP,8` |
| EDI = text host | **Confirmed** | callers load EDI; body `*EDI+0x250/224/22c` |
| Type/subtype string map | **Confirmed** | decompile literals |
| Rarity table stride 0x48 | **Confirmed** | decompile |
| Customize gate = dualed `00513fc0` | **Confirmed** | call @ `0084778b` |
| Patentee field `item+0x101` | **Confirmed** | dualed with `00522950` family |
| RE / memorize restriction lines | **Confirmed** | strings + `FUN_00522950` |
| Role tooltip type/meta builder | **Confirmed** | callers + strings |
| Product PDB / RTTI name | **Open** | `_Inferred` |
| Weapon flag product English | **Tentative** | bits sealed; names from UI strings only |
| Owner name chain product | **Open** | vfunc offsets only |
| Bit-exact full body | **Open** | large; stage seal |
| Runtime path | **Open** | terminal false |

---

## 4. Control flow: clean ≡ raw ≡ live (stages)

| Stage | Raw/live | Named clean |
|------:|----------|-------------|
| S1 setup | `FUN_007a69d0`; cache session | same |
| S2 type switch | full case table + weapon | same labels / weapon stub note |
| S3 append type | vfunc +0x250 | `Text_Append` |
| S4 rarity | skip type4; table+color | same |
| S5 meta | `00513fc0` / 4be / charges | same |
| S6 patentee | +0x101 | same |
| S7 RE/mem | `00522950` | same |
| S8 return | +1 / +2 | same |

No CF conflict between 2026-07-23 raw and 2026-08-05 live decompile.

---

## 5. Gaps (accept-with-gaps)

- Original symbol / panel class RTTI for EDI text host.
- Full weapon mount matrix product names beyond UI strings.
- Exact layout consumer of return line-count.
- Runtime / differential / bit-exact.

---

## 6. Verdict

**accept-with-gaps** — CF, ABI, callers, string map, dualed customize/RE callees, and role sealed; product demangle and full bit-exact open.
