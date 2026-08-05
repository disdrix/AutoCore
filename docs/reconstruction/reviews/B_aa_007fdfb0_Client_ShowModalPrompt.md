# Review B (skeptical / adversarial): `aa_007fdfb0` Client_ShowModalPrompt

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fdfb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007fdfb0_Client_ShowModalPrompt.md` |
| **Chain** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **Verdict** | **accept** on abandon Yes/No pairing + OK/Cancel widget bind; **accept-with-gaps** on `flagB` / bit-exact |
| **Residual scratch** | `reviews/a_007fdfb0.md` |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Ghidra 3-arg prototype is complete | Callers set **EAX** immediately before CALL; prologue `MOV EDI,EAX` stores to `+0x498` | **Prototype incomplete — attack holds** |
| 2 | Open code `0x4e47` is the Yes id | Asm: `EAX=0x4e46`, stack `0x4e47`; Yes case is `0x4e46` | **Falsified** |
| 3 | Pairing only “adjacent by coincidence” | Explicit `MOV EAX,0x4e46` at abandon open; same EAX/stack+1 pattern at `0x4e2c/0x4e2d`, `0x4e5a/0x4e5b` | **Attack fails — pattern intentional** |
| 4 | `+0x498` might be Cancel | Would map Yes click → cancel case; contradicts sealed dispatch send on `0x4e46` | **Attack fails for abandon** |
| 5 | `VOG_DEBUG_STOP` names the API | Only null `game+0x1118` assert | **Reject that name** |
| 6 | Single-button path unused | `param_3 < 0` copies EAX to both slots; many toasts use `-1` | **Holds as real path** |
| 7 | Decompiler `in_EAX` is phantom noise | Prologue + every dual opener load imm into EAX | **Not phantom** |
| 8 | Need runtime CE to seal pairing | Static open store + static dispatch is enough for abandon | **Runtime optional, not required for High** |

---

## 2. What would still drop confidence

| Gap | Impact if wrong | Status |
|---|---|---|
| Physical OK widget reads secondary instead of primary | Invert Yes/No labels | **Falsified:** asm programs OK with primary first, then `MOV EDI,EBP` before Cancel program; codes live at each `button+0xec` |
| Another writer overwrites ids before click | Wrong case | Not observed; modal closed/replaced first via `FUN_007fc360` |
| flagA/flagB change dual-id meaning | Different pairing | Asm stores ids **before** flag helpers; `flagA` only toggles blocker chrome |

None of these remain open at a level that blocks **High** for abandon Yes=`0x4e46` / No=`0x4e47` or widget bind.

---

## 3. Adversarial confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| Abandon Yes id `0x4e46` | **High** | Wire wrong UI event in tests |
| Abandon No id `0x4e47` | **High** | Accidental FailMission on dismiss |
| Dual-id offsets `+0x498`/`+0x49c` | **High** | Mis-document host layout |
| Global “always primary+1 = cancel” | **High for observed openers** / not universal proof for every modal | Over-generalize outside 0x4eXX band |
| Full show path / localization | **Probable** | Wrong toast text only |

---

## 4. Residual

1. ~~Formal widget class that binds OK/Cancel~~ **Sealed High:** `CNDUICtrlButton` on `CDlgPopup` (`+0x550` OK / `+0x554` Cancel); `vtbl+0x74`/`+0x78` ↔ `button+0xec`. Host dual-id `+0x498`/`+0x49c` remains parallel fallback. See `reviews/a_007fdfb0.md`.
2. Complete `flagB` matrix (non-blocking; unused in this body). `flagA` sealed as blocker chrome.
3. Runtime abandon click observation (nice-to-have; static path sealed).

---

## 5. Surviving contract

```
// Open abandon confirm
EAX = 0x4e46;  // Yes
Client_ShowModalPrompt(&g_client, msg, /*No*/0x4e47, 1, 0);
// host+0x498 == 0x4e46, host+0x49c == 0x4e47

// On modal primary action (param_2 == 8):
//   code 0x4e46 → C2S FailMission 0x20B2
//   code 0x4e47 → close only
```

**UF-009: sealed High for abandon pairing.** Do not re-open on adjacency alone.
