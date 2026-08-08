# Review B (skeptical / adversarial): `aa_005140d0` UI_ItemRarity_WriteBgraFromIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005140d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_005140d0_UI_ItemRarity_WriteBgraFromIndex_Inferred.md` |
| **Work item** | R12-016 OWN-ONLY |
| **Verdict** | **accept-with-gaps** on CF/ABI/palette/role; product English residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is the rarity **name** loader / table | Body has no CALL, no `DAT_00b04214` | **Falsified** — pure palette; table is `005129b0` |
| 2 | This is tooltip appender `00847240` | Different VA; parent **calls** this | **Falsified** |
| 3 | `__thiscall` / ECX = this | Entry uses `[ESP+4]`/`[ESP+8]` only; no ECX | **Falsified** — **cdecl** sealed |
| 4 | `void` return (decompiler) ⇒ discardable EAX | Parent casts return to `undefined4*` and `*puVar9` | **Return=out survives** |
| 5 | Channel order RGBA in memory | Stores `[0]=B-ish case2 0xFF`, `[2]=R-ish 0x28` → blue as LE dword `0xFF2828FF` | **BGRA memory sealed** |
| 6 | Same unit as `Ui_NameColorPalette_WriteArgb` | Different VA, ABI (ECX/EAX vs stack), palette | **Falsified** — sibling only |
| 7 | `Named_CalleeOf_Mission_Mission_Object_*` | Parent dual retired mission name; this is color leaf | **Reject scaffold name** |
| 8 | Index is item **type** class | Parent passes `blob+0x4b8` (rarity); type gate is separate (`+0x38 != 4`) | **Rarity index survives** |
| 9 | Product name without `_Inferred` | No RTTI / string / PDB in body | **`_Inferred` required** |
| 10 | Runtime Confirmed | No Launcher / CE this wave | **Not claimed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Six + default color immediates | **High** | Wrong rarity tint in UI |
| cdecl out+index / bare RET / EAX=out | **High** | Wrong call ABI |
| Leaf (no callees) | **High** | Spurious dependency graph |
| Role = rarity UI color | **High** | Mis-merge with name table / tooltip |
| Product tier English (Common/…) | **Open** | Doc only |
| Runtime / bit-exact | **Open** | Unverified live |

---

## 3. Cross-check raw + live bytes

```
005140d0  movsx eax, word ptr [esp+8]
005140d5  cmp eax, 5
005140d8  ja  default_cyan          ; 0x00514156
005140da  jmp dword ptr [eax*4 + 0x0051416c]
; cases: mov eax,[esp+4]; write BGRA; ret (C3)
```

JT dwords (LE): `005140e1, 005140f4, 00514106, 0051411a, 0051412e, 00514142`.

Live 2026-08-05 decompile ≡ 2026-07-23 raw switch body.  
`read_memory` confirms immediates and `C3` exits; pad `8B FF` then JT then `CC`.

Parent call shape (dualed `00847240`, not re-owned):

```text
FUN_005140d0(&stack_color, (int16)blob[0x4b8])
textHost.vfunc+0x22c(rarityName, *colorDword)
```

---

## 4. Surviving contract

```c
// cdecl
uint8_t* UI_ItemRarity_WriteBgraFromIndex_Inferred(uint8_t out[4], int16_t rarityIndex);
// writes palette[clamp_or_default(rarityIndex)]; returns out
// rarityIndex typically clone-base blob+0x4b8
```

Parents must push `(index, out)` in cdecl order and may load `*(uint32_t*)EAX` after return.

---

## 5. Residual risks

- Product English for indices 0..5 (table strings residual with `DAT_00b04214`).
- Whether negative indices intentionally hit default (MOVSX + unsigned JA after CMP 5 → yes for `<0`).
- Non-tooltip callers (`008becd0`, `008b6590`, …) not dualled — may pass non-rarity indices; body still pure map.
- No runtime Confirmed.

---

## 6. Verdict

**accept-with-gaps** — adversarial pass falsifies thiscall, name-table merge, tooltip-merge, mission scaffold name, and Runtime Confirmed; CF/ABI/palette/role stand with `_Inferred` product English open.
