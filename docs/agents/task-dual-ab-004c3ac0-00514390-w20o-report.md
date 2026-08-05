# Dual A/B report — W20-O OWN `0x004c3ac0` + `0x00514390`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x004c3ac0`, `0x00514390`. Dual A/B + artifacts.  
**Agent:** W20-O  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c3ac0` CVOGObject_GetActivePositionPtr_Inferred | **accept** — **48-byte leaf position source selector sealed** (mask `7`; `+0x240` / phys `*(+0x3c)+0xb0` / embed `+0x84`) |
| `aa_00514390` Item_CharacterMeetsUseReqs_Inferred | **accept-with-gaps** — **532-byte thiscall req predicate sealed** (`ret 8`; level clamp 80; four sealed stat getters; special arm residual) |

---

## Sealed facts — `0x004c3ac0`

1. **ABI:** `uint8_t *__fastcall CVOGObject_GetActivePositionPtr_Inferred(void *self)` — ECX=self, bare **`ret`**.
2. **Body:** `0x004c3ac0`–`0x004c3aef` (**48 bytes**). Leaf.
3. **Algorithm:** if `(this+typeOff+0xb8)&7==0` → `this+0x240`; else if `*(this+8)` → `*( *(this+8)+0x3c ) + 0xb0`; else `this+typeOff+0x84`.
4. **Mask contrast:** reader **`7`**; sibling writer `004c3a40` uses **`0xC7`**.
5. **Name:** `CVOGObject_GetActivePositionPtr_Inferred` — role-sealed **INFERRED**.
6. **Callers:** `FUN_005cd3b0`×2, `FUN_005cedf0`×2, `FUN_005d2800`, `FUN_0060a230`, `FUN_009190d0`.

---

## Sealed facts — `0x00514390`

1. **ABI:** `uint32_t __thiscall Item_CharacterMeetsUseReqs_Inferred(Item *item, void *ch, uint32_t flag)` — ECX=item, **`ret 8`**, AL 0/1.
2. **Body:** `0x00514390`–`0x005145a3` (**532 bytes**).
3. **Early 1:** `ch+0x6b4 > 0` OR item type **`0x1a`**.
4. **Gates:** race (`vtbl+0x14` vs `+0x532`, -1 wild); faction (`clone+0x3e0` vs `+0x531`, -1 wild); level `min(sum,0x50)`; acc/perc/theory/tech floors; optional powerplant bit19; optional special type **`0x26`** when flag≠0.
5. **Side effect:** special arm clears `*(item+0x70)+0x1d`.
6. **Name:** `Item_CharacterMeetsUseReqs_Inferred` — **INFERRED**.
7. **Callers:** TryEquip, SetLevelWithFlags, use/UI paths.

---

## Gaps

1. Product/PDB English symbols for both.
2. Phys object type behind `this+8` / `*(phys+0x3c)` for position getter.
3. Type ids `0x1a` / `0x26` and staff field English for req predicate.
4. Nested dual of `FUN_00402c40` / `FUN_00411900` / `FUN_0052ada0`.
5. Runtime / bit-exact / differential — open.

---

## Files

### `aa_004c3ac0` CVOGObject_GetActivePositionPtr_Inferred

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004c3ac0_CVOGObject_GetActivePositionPtr_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004c3ac0_CVOGObject_GetActivePositionPtr_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004c3ac0_FUN_004c3ac0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_GetActivePositionPtr_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_004c3ac0.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_004c3ac0_FUN_004c3ac0.md` |
| Annotated | `docs/reconstruction/raw/aa_004c3ac0_FUN_004c3ac0.annotated.md` |
| Scratch | `tmp/a_004c3ac0.md` |

### `aa_00514390` Item_CharacterMeetsUseReqs_Inferred

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00514390_Item_CharacterMeetsUseReqs_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00514390_Item_CharacterMeetsUseReqs_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00514390_FUN_00514390.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_CharacterMeetsUseReqs_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00514390.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_00514390_FUN_00514390.md` |
| Annotated | `docs/reconstruction/raw/aa_00514390_FUN_00514390.annotated.md` |
| Scratch | `tmp/a_00514390.md` |

| Report | `docs/agents/task-dual-ab-004c3ac0-00514390-w20o-report.md` |

---

## AutoCore impact

- **GetActivePositionPtr:** when reading pose, honor the three-way select; do not always use `+0x240`. Phys path is `*(phys+0x3c)+0xb0`, not `phys+0xEC`. Pair with gated local writer (`0x004c3a40`, mask `0xC7`).
- **MeetsUseReqs:** port as pure-ish equip/use predicate with level floor **80**, four combat-stat floors, optional powerplant and special-mode arms. Keep `flag` semantics; do not merge equip mutation into this helper. Staff override at character `+0x6b4` must short-circuit true.
