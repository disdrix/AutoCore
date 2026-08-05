# Review B (skeptical / adversarial): `aa_0088ef70` UI_InvSheet_ApplySelectionTint_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0088ef70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0088ef70_UI_InvSheet_ApplySelectionTint_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF (color + widgets sealed) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Greys whenever vehicle null without char host | Requires `DAT_00d1b6d8 != 0` **and** `+0xcd0==0` | **Falsified as hostless grey** |
| 2 | Default color is black / zero | `DAT_00afdf0c` = `0xFFFFFFFF` | **Falsified** |
| 3 | Hardcoded grey only path | Default path always loads DAT first | **Falsified as grey-only** |
| 4 | ECX thiscall | ESI register this | **Falsified** |
| 5 | Same function as vehicle hardpoint refresh | Different VA; different offsets (`0x5b4/0x5b8` vs `0x588…`) | **Falsified** |
| 6 | Touches three or more widgets | Exactly two null-checked slots | **Falsified** |
| 7 | `vtbl+0x15c` is set text | Called with color dword pointer; sibling UI uses +0x15c for color elsewhere | **Probable color** — text would take char* |
| 8 | Always called for every UI frame | Only when callers set ESI and invoke after open checks | **Falsified as per-frame** |
| 9 | Hidden fourth caller | 3 UNCONDITIONAL_CALL | **Falsified** |
| 10 | Product name Confirmed | Inferred only | **Gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI sheet this | **High** | Wrong host |
| Default 0xFFFFFFFF / grey 0xFF414141 | **High** | Wrong theme |
| Gate char host + vehicle null | **High** | Grey when no player |
| Widgets +0x5b4 / +0x5b8 | **High** | Miss chrome |
| vtbl +0x15c / +0x34c sequence | **High** | Stale color |
| Widget English | **Open** | Doc |
| Channel order product | **Open** | If engine swaps channels |
| Runtime | **Open** | |

---

## 3. Cross-check live body

```
0088ef70  push eax                      ; local ARGB slot
0088ef71  mov  eax, [DAT_00afdf0c]      ; 0xFFFFFFFF
0088ef76  mov  [esp], eax
0088ef79  mov  eax, [DAT_00d1b6d8]
0088ef7e  test eax, eax
0088ef80  jz   after_grey
0088ef82  cmp  dword [eax+0xcd0], 0
0088ef89  jnz  after_grey
0088ef8b  mov  al, 0x41
0088ef8d  mov  [esp+2], al
0088ef91  mov  [esp+1], al
0088ef95  mov  [esp], al
0088ef98  mov  byte [esp+3], 0xFF       ; 0xFF414141
after_grey:
0088ef9c  cmp  dword [esi+0x5b4], 0
...
0088efe0  cmp  dword [esi+0x5b8], 0
...
0088effx  pop  ecx
0088effx  ret
```

---

## 4. Surviving contract for AutoCore

```c
// custom: sheet in ESI
void UI_InvSheet_ApplySelectionTint(InvSheet* sheet /*ESI*/);
// color = white; if local char && no selected vehicle → 0xFF414141
// apply to sheet+0x5b4 and +0x5b8 if present
```

Do not grey when `DAT_00d1b6d8` is null. Do not merge with `0x008800e0` hardpoint refresh.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks seal color constants and dual-widget CF; keep widget product names open.
