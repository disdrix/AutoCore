# Review B (skeptical / adversarial): `aa_00514390` Item_CharacterMeetsUseReqs_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514390` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-O) |
| **Counterpart** | `reviews/A_aa_00514390_Item_CharacterMeetsUseReqs_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This **equips** the item / mutates inventory slots | **Falsified** — pure predicate (+ optional clear of `*(item+0x70)+0x1d` on special arm only); equip mutator is caller `004fabc0` |
| 2 | Always pure / no side effects | **Partially false** — special arm clears a byte and walks iterator; normal path is effectively pure |
| 3 | Level cap is 100 / uncapped | **Falsified** — clamp **0x50 (80)** |
| 4 | `param_3` always enables special arm | **Falsified** — needs flag≠0 **and** clone`+0x3f2&0x80` **and** char flags `+0xf5/+0xf6` |
| 5 | Early `+0x6b4` is vehicle RPM field | **Falsified in this type context** — character offset; vehicle RPM `+0x6b4` is a different object family |
| 6 | `__cdecl` / `ret` bare / single arg | **Falsified** — thiscall + **`ret 8`** |
| 7 | Stack capacity / broken-flag check | **Falsified** — those are `0040abf0` / `00513e70` family; different unit |
| 8 | Name is PDB-proven | **Unproven** — **Inferred** from callers + sealed stat getters |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ret 8 / this=item | **High** | Stack smash / wrong this |
| Early override + type 0x1a | **High** | Bypass missing in port |
| Level clamp 80 | **High** | Equip allowed at wrong levels |
| Four stat floors + sealed getters | **High** | Wrong combat reqs |
| Powerplant bit19 optional | **High** | Block/allow wrong items |
| Special arm type 0x26 | **High CF** | Use-path false deny |
| Product English / type ids | **Open** | Docs only |
| Double race vfunc purity | **Medium** | Collapsing calls if impure |

---

## 3. Cross-check against raw + bytes

```
if (ch+0x6b4 > 0 || itemType == 0x1a) return 1
if race fails (not -1 and != ch.race): return 0
if faction fails (not -1 and != ch.factionByte): return 0
if levelReq > level: return 0
if any of acc/perc/theory/tech req > have: return 0
if bit19 and pp required and capacity < need: return 0
if special-mode arm active and no type-0x26: return 0  // may clear item helper byte
return 1
```

Clean must preserve **nested short-circuit** and **optional** powerplant/special arms.

---

## 4. Surviving contract for AutoCore

```c
// Port of Item_CharacterMeetsUseReqs_Inferred
// thiscall Item*, Character* ch, int flag; ret 8; returns 0/1
bool Item_CharacterMeetsUseReqs(Item* item, Character* ch, int flag) {
  if (ch->staffOverride_0x6b4 > 0) return true;
  if (item->cloneMeta->type == 0x1A) return true;
  // race / faction wildcards (-1 / 0xFFFFFFFF)
  // level: min(reqBase+reqBonus, 80) <= ch.GetLevel()
  // acc/perc/theory/tech floors via sealed getters
  // optional powerplant capacity when item flags bit19
  // optional special-mode presence (type 0x26) when flag!=0
  return true;
}
// Do not fold equip mutation into this helper.
// Call sites pass flag 0 (equip) or 1 (use / level recheck) — preserve.
```

---

## 5. Open questions

1. Product name and item req field English.
2. Identity of type `0x1a` and iterator type `0x26`.
3. Staff field `+0x6b4` product meaning.
4. Nested dual of iterator helpers.
5. Runtime golden matrix — open.

**Verdict:** **accept-with-gaps**
