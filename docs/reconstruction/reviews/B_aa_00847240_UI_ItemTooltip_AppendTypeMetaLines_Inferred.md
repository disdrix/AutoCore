# Review B (skeptical / adversarial): `aa_00847240` UI_ItemTooltip_AppendTypeMetaLines_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00847240` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00847240_UI_ItemTooltip_AppendTypeMetaLines_Inferred.md` |
| **System** | `inventory-transfer` |
| **Work item** | R11-029 OWN-ONLY dual seal |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; **reject** mis-names and overclaims below |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Product name is `Mission_Mission_Object` | **Falsified** — `"Mission Object"` is only type-class **4**; body handles weapons, armor, craft, gadgets, etc. |
| 2 | Function is a mission-progression handler | **Falsified** — no mission packet/state callees; pure UI string append |
| 3 | Function is only a callee of `Item_RequiresBindOrTradeLock` parent chain | **Falsified** — partition parent is score parent; **this** unit **calls** `00513fc0`; live callers are `00843a60` and `UI_ItemDetailPanel_Refresh` |
| 4 | Decompiler `unaff_EDI` means EDI is unused / undefined | **Falsified** — both callers load EDI before call; body consistently uses `*EDI+0x250/224/22c` as text host |
| 5 | ABI is thiscall (ECX=item) | **Falsified** — item on stack; callers `ADD ESP,8`; prologue loads ESI from `[esp+0x19c]` |
| 6 | Function emits equip / bind C2S | **Falsified** — no network callees; only UI append + predicates |
| 7 | Function **sets** Customized / NotTradable / charges | **Falsified** — read-only display; customize need is dualed probe `00513fc0` |
| 8 | `"Patented By: "` proves craft-discipline field | **Falsified** — dualed `00522950` seals `item+0x101` as **patentee name** string |
| 9 | Return value is success/failure bool | **Falsified** — asm `ADD EAX,1` / `ADD EAX,2` line-count style; early path uses patented flag + 1 |
| 10 | Type `0xc` always prints `"Gadget"` | **Falsified** — `0x8` is Gadget; `0xc` is weapon detail path |
| 11 | Rarity index at `blob+0x4b8` is bind threshold (≥2) | **Related but distinct** — same short field used as **rarity table index** here; bind probe uses `>=2` threshold in `00513fc0` — different consumers, same offset |
| 12 | Ready for bit-exact / runtime Confirmed | **Fail** — static stage seal only; terminal false |

---

## 2. Decisive dataflow — sealed contract

```
// cdecl; EDI = UiTextHost* (caller-live)
// stack: Item* item, char showMeta
// RET C3; EAX = line_count_delta

FUN_007a69d0()
session = DAT_00d1b6d8
holder  = item[0x2a]          // +0xA8
type    = *(holder+0x38)
blob    = *(holder+0x3c)

// type English or weapon detail → TextHost.Append(+0x250)
// if type != 4:
//   Append ", "
//   ensure rarity table; AppendColor2(name, FUN_005140d0(rarity=blob+0x4b8))
// if showMeta && type != 4:
//   if Item_RequiresBindOrTradeLock(coid): Customizes On Equip / Customized For
//   if blob+0x4be: Not Tradable
//   if charges(item+0x180): unlimited or N charges
// if item+0x101 non-empty: Patented By (color 0xffaedeff)
// if session:
//   if !PatenteeMatches: Cannot be Reverse Engineered (0xffff2020) → return +2
//   else if item+0x100: Cannot be Memorized → return +2
// return patented_flag + 1
```

**Byte-backed (not decompiler-only):**

- Entry: `81 EC 8C 01 00 00` frame; `8B B4 24 9C 01 00 00` ESI=arg0.
- Call site `0084be00`: `6A 01 50 E8 … 83 C4 08`.
- Call site `00843dc1`: `6A 01 56 E8 …` (same arity).
- Exit A: `83 C0 02 5B 81 C4 8C 01 00 00 C3`.
- Exit B: `8B 44 24 10 5E 5D 83 C0 01 5B 81 C4 8C 01 00 00 C3`.
- `DAT_00a32888` bytes = `"Item"`; `DAT_00a34230` = `", "`.

---

## 3. Relation attack: “is this the detail panel / stats builder / bind probe?”

| Unit | VA | Attack note |
|------|-----|-------------|
| `UI_ItemDetailPanel_Refresh_Inferred` | `0x0084b890` | **Caller** — layout/refresh; this unit is one text stage |
| `UI_BuildItemTooltipStats` | (dualed) | Sibling stats block — **do not merge** |
| `Item_RequiresBindOrTradeLock` | `0x00513fc0` | **Callee** predicate for customize line only |
| `Item_PatenteeMatchesCharacterOrEmpty_*` | `0x00522950` | **Callee** for RE eligibility display |
| `FUN_00843a60` | `0x00843a60` | Equipped-compare panel caller |
| This unit | `0x00847240` | Type + meta **text lines only** |

---

## 4. Naming attack

| Name | Result |
|------|--------|
| `Mission_Mission_Object_00847240` | **Reject** — single-string overfit |
| `UI_ItemDetailPanel_Refresh` | **Reject** — that is `0084b890` |
| `Item_RequiresBindOrTradeLock` | **Reject** — that is `00513fc0` |
| `UI_ItemTooltip_AppendTypeMetaLines_Inferred` | **Accept** as inferred role name (PDB open) |

---

## 5. Residual risks

- EDI text-host class / vtbl product names open.
- Weapon flag matrix English beyond UI strings.
- Whether return delta is consumed as line count vs widget index — layout callers residual.
- No runtime Confirmed.

---

## 6. Verdict

**accept-with-gaps** — adversarial pass falsifies mission-only name, thiscall, setter/packet, and merge-with-panel claims; CF/ABI/role stand.
