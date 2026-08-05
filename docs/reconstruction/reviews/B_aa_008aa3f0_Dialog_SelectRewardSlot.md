# Review B (skeptical / adversarial): `FUN_008aa3f0` @ `0x008aa3f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa3f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008aa3f0_Dialog_SelectRewardSlot.md` |
| **Verdict** | **accept-with-gaps** on ABI + TFID selection + dual callers; **needs-more-evidence** on vtbl/style product names |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is ECX `__thiscall` | **Falsified** — prologue `MOV EDI,EAX`; callers `MOV EAX,host` before CALL | **Survives as EAX this** |
| 2 | Only auto-select single-reward path | **Falsified** — second xref `0x008aed23` in event dispatch on click | **Survives as dual caller** |
| 3 | Auto-select always runs from chrome | **Falsified (caller)** — chrome only when count==1 **and** `+0x64c≠0` | **Survives with conditions** |
| 4 | This function checks turn-in flag | **Falsified** — no `+0x64c` read in body | **Survives: callers gate** |
| 5 | Click path selects without turn-in | **Falsified (caller)** — `FUN_008aec40` requires `+0x64c≠0` and `msg==8` | **Survives: claim-mode only** |
| 6 | Slot index from control id is `id-0x9c40` | **Falsified** — `LEA EAX,[EBX+0xFFFF63BE]` = `id-0x9c42` | **Survives: 0x9c42 base** |
| 7 | Widget loop uses stride 8 | **Falsified** — `ADD ESI,4`; TFID uses `*8` | **Survives: widgets×4, TFID×8** |
| 8 | Selected style uses same blob as unselected | **Falsified** — unselected `+0x594`, selected `+0x5a4` | **Survives as two blobs** |
| 9 | `DAT_00a1419b` is “must choose” text | **Falsified** — first byte `0x00` empty; chrome uses it to **clear** multi-offer hint | **Survives as clear** |
| 10 | Function validates slot ∈ [0,3] | **Falsified** — no clamp; trusts callers | **Survives as unbounded index** |
| 11 | Null-safe widget walk | **Falsified** — unconditional `*widget` deref for all 4 | **Survives as assume-present** |
| 12 | Sends CompleteObjective / packet | **Falsified** — only local fields + UI vtbl | **Survives: pure client select** |
| 13 | Scaffold alias from parent banner is product name | **Overstated** | **Demote to Tentative** |
| 14 | `vtbl+0x158` proven “set color” | **Overstated** — ordinal only; hover path also uses `+0x158` with `+0x584` | **Tentative product** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX = dialog host | **High** | All offsets on wrong object |
| Stack slot index | **High** | Wrong reward COID on turn-in |
| TFID copy `+0x558[slot]→+0x578` | **High** | CompleteObjective wrong reward |
| 4-widget unselected then selected style | **High** structure | Cosmetic only if wrong ordinal |
| Clear hint via empty string | **High** | Stuck “must choose” after pick |
| Two callers only | **High** | Missed selection writer |
| Turn-in gate location (callers) | **High** | Offer path incorrectly selects |
| Style blob field layout `+0x594/+0x5a4` | **Open** | Port mis-implements chrome |
| Vtbl method product names | **Tentative** | Docs mislabel |
| Behavior if slot OOB / null widget | **Open** | Crash / corrupt select |

---

## 3. Cross-check against raw / asm

### 3.1 Authoritative spine

```
// entry: EAX=dialog, [esp+4]=slot (before pushes)
dialog = EAX
slot   = stack arg
dialog+0x578 = *(dialog + 0x558 + slot*8)
dialog+0x57c = *(dialog + 0x55c + slot*8)
for i in 0..3:
  w = *(dialog + 0x698 + i*4)
  w->vtbl[0x158/4](0, dialog+0x594)   // unselected style
  w->vtbl[0x34c/4]()
w = *(dialog + 0x698 + slot*4)
w->vtbl[0x158/4](0, dialog+0x5a4)     // selected style
w->vtbl[0x34c/4]()
if dialog+0x708:
  (*+0x708)->vtbl[0x308/4](&DAT_00a1419b)  // empty → clear hint
```

### 3.2 Prologue seal (bytes @ `0x008aa3f0`)

| Bytes | Decode |
|---|---|
| `53 55 56 57` | push EBX EBP ESI EDI |
| `8B F8` | `MOV EDI, EAX` (host) |
| `8B 44 24 14` | `MOV EAX, [ESP+0x14]` (slot) |
| `8B 8C C7 58 05 00 00` | `MOV ECX, [EDI+EAX*8+0x558]` |
| `89 8F 78 05 00 00` | `MOV [EDI+0x578], ECX` |
| `8B 94 C7 5C 05 00 00` | `MOV EDX, [EDI+EAX*8+0x55c]` |
| `89 97 7C 05 00 00` | `MOV [EDI+0x57c], EDX` |
| `8D AF 94 05 00 00` | `LEA EBP, [EDI+0x594]` |
| `8D B7 98 06 00 00` | `LEA ESI, [EDI+0x698]` |
| `BB 04 00 00 00` | `MOV EBX, 4` |
| `… FF 90 58 01 00 00` | `CALL [EAX+0x158]` |
| `… FF 92 4C 03 00 00` | `CALL [EDX+0x34c]` |

### 3.3 Call-site seal

| Site | Parent | Prep | Arg |
|---|---|---|---|
| `0x008aa968` | `FUN_008aa760` | `PUSH 0`; `MOV EAX,EDI` | slot **0** (after count==1, `+0x64c≠0`) |
| `0x008aed23` | `FUN_008aec40` | `LEA EAX,[EBX-0x9c42]`; `PUSH EAX`; `MOV EAX,ESI` | slot **id−0x9c42** (msg==8, `+0x64c≠0`) |

### 3.4 What this unit is **not**

| Non-claim | Why |
|---|---|
| Packet / CompleteObjective send | No network callees |
| Turn-in eligibility | No `+0x64c` / inventory checks |
| Reward resolve / icon load | Owned by `FUN_008aa760` |
| Hover highlight only | Hover uses `+0x584` style in dispatcher, not this fn |
| Multi-slot simultaneous selection | Overwrites single `+0x578` pair |

---

## 4. Residual attacks still open

1. **Style blob contents** at `+0x594` / `+0x5a4` (colors, alpha, borders) — not typed.
2. **Whether `vtbl+0x158` first arg `0` is a flags enum** — constant only.
3. **Crash if reward widgets null** after partial chrome fill — static risk.
4. **Offer-mode click** never reaches this function (caller gate); offer selection state remains −1 until turn-in chrome rebuild — intentional but not re-proven live.

---

## 5. Parent gap closure

| Parent gap (aa_008aa760 B) | This dual |
|---|---|
| “Multi-reward click → selection writer **Open**” | **Sealed:** `FUN_008aec40` → `FUN_008aa3f0(id-0x9c42)` |
| Auto-select only single turn-in | **Confirmed** caller; this unit is shared select primitive |

---

## 6. Verdict rationale

Adversarial checks confirm EAX ABI, dual callers, TFID selection, and empty-hint clear. Remaining uncertainty is UI product naming and runtime null/OOB → **accept-with-gaps**, not reject.
