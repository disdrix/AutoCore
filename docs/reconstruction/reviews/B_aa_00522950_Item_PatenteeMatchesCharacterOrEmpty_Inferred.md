# Review B (skeptical / adversarial): `aa_00522950` Item_PatenteeMatchesCharacterOrEmpty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522950` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-108) |
| **Counterpart** | `reviews/A_aa_00522950_Item_PatenteeMatchesCharacterOrEmpty_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Mission_Mission_Object helper / mission system | **Falsified** — 0 mission xrefs; 4 RE/item-hover callers only |
| 2 | This VA **is** `UI_ItemHover_FormatCraftStatus` | **Falsified** — partition host is `0x0085ce20` (dualed ItemHover RE/tinker/gadget); this is a **leaf gate** |
| 3 | `item+0x101` is craft-discipline requirement | **Falsified** — sibling prints `"Patented By: "` + field; no discipline format string here |
| 4 | Full RE eligibility (broken/stack/recipe) | **Falsified** — parents check broken bit, type `0x1a`, stack, `FUN_00599dd0` recipe separately |
| 5 | `__cdecl` / no stack cleanup / ECX=item | **Falsified** — `RET 4`; callers load **character** into ECX and **PUSH item** |
| 6 | Empty patented-by means fail | **Falsified** — empty length → `JZ` success path → `mov al,1` |
| 7 | Case-sensitive compare | **Falsified** — `_stricmp` IAT, not `strcmp` |
| 8 | Returns full int status codes | **Falsified** — AL 0/1 only; three boolean exits |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body 98 B / RET 4 thiscall | **Confirmed** | Stack imbalance / wrong end |
| ECX=character, stack=item | **Confirmed** | Wrong object for name fetch |
| Empty-or-stricmp gate | **Confirmed** | Wrong RE block logic |
| Patented-by field English | **High** | Mis-document field if UI string is shared for another role |
| vtbl+0x160 = character name | **Probable** | Wrong accessor if slot is title/guild/etc. |
| Product function name | **Low** | Doc only (`_Inferred`) |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean Item_PatenteeMatchesCharacterOrEmpty_Inferred.cpp

8B 44 24 04 85 C0 75 05 32 C0 C2 04 00     ; item null → false RET4
56 8D B0 01 01 00 00 …                     ; ESI = item+0x101
… 74 2A                                    ; empty → success
8B 41 04 8B 50 04 8B 44 0A 04 8D 4C 0A 04
FF 90 60 01 00 00                          ; call [eax+0x160]
50 56 FF 15 78 66 9C 00 83 C4 08           ; _stricmp cdecl
… 32 C0 … C2 04 00                         ; mismatch false
… B0 01 … C2 04 00                         ; true

Callers:
  0085cee3  MOV ECX,[d1b6d8]; PUSH ESI; CALL 522950
  0093d507  MOV ECX,[ESI+0xe98]; PUSH EBP; CALL 522950
  0084797c  MOV ECX,[ESP+14]; PUSH ESI; CALL 522950
  0052e699  MOV ECX,EDI; (PUSH ESI); CALL 522950
```

Reject ports that:

- Treat this as mission UI / Mission_Mission_Object.
- Put item in ECX or omit `RET 4`.
- Use case-sensitive compare or skip empty short-circuit.
- Fold broken/recipe/stack gates into this leaf.
- Claim this function formats tooltip text (parents do).

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: bool Character::ItemPatenteeMatchesOrEmpty(Item* item)
// Port: gate Reverse-Engineer UI/action when item is patented by someone else.

bool ItemPatenteeMatchesCharacterOrEmpty(Character character, Item item)
{
    if (item is null) return false;
    string patentedBy = item.PatentedByName; // offset +0x101 C-string
    if (string.IsNullOrEmpty(patentedBy)) return true;
    return string.Equals(patentedBy, character.Name, StringComparison.OrdinalIgnoreCase);
}
```

Parents still apply broken-bit, cargo, stack, craft-material, and recipe checks.

---

## 5. Verdict

Path B attacks on mission naming, host mis-identity, discipline-field claim, full-RE merge, and ABI errors are **falsified**. Structural empty-or-name-match gate **holds**. Product English for vtbl+0x160 and final symbol remain open → **accept-with-gaps**.
