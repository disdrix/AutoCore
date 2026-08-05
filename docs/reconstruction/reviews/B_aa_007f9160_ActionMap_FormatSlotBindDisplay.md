# Review B (skeptical / adversarial): `aa_007f9160` ActionMap_FormatSlotBindDisplay

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f9160` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ7R-G) |
| **Counterpart** | `reviews/A_aa_007f9160_ActionMap_FormatSlotBindDisplay.md` |
| **Scratch** | `tmp/a_007f9160.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `__thiscall` with `this` = buffer only | **Incomplete** — ECX=out **and** EAX=ActionMap*, EDX=mode, 2 stack args, **RET 8** |
| 2 | Tip id in EAX (`in_EAX` phantom) | **Falsified** — EAX is ActionMap base; tip/index is stack0 (`MOV AL,[ESP+0xC]` pre-GetSlot) |
| 3 | Display order key+mod | **Falsified** — first name call uses **mod in EAX→EDX**, second uses **key in ESI→EDX** → **mod+key** |
| 4 | Lane offsets are absolute ActionMap fields | **Overstated** — relative to GetSlot **primary-key** pointer (mode bases already applied) |
| 5 | Always succeeds if slot exists | **Falsified** — both key and mod zero → AL=0 |
| 6 | Mission-dialog wire logic | **Falsified** — client string helper only; no 0x206D/0x206C packing |
| 7 | Owns GetSlot | **Out of scope** — `FUN_007f7240` not dualed here; contract cited only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 8 + 5-arg ABI | **High** | Stack smash / wrong bind |
| Lane primary/alt offsets | **High** | Shows wrong binding |
| mod+key order | **High** | UI reads as `A+SHIFT` |
| `+` separator | **High** | Join char wrong |
| Mode names | **Tentative** | Docs only |
| Which global → EAX at each caller | **Medium** | Wrong table |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against bytes + sibling

```
007f9160: push ebx; push eax(base); mov al,[esp+0xc](index); mov ebx,ecx; call 007f7240
after RET4: cmp [esp+0xc],0  → lane flag
lane0: mov si,[eax]; mov ax,[eax+0x2a]
lane1: mov si,[eax+2]; mov ax,[eax+0x2c]
both:  mov edx,eax; call 007f5120; store '+'; mov edx,esi; call 007f5120; al=1; ret 8
```

Sibling `ActionMap_TrySetSlotBind`: key1−key0 = 2, mod0−key0 = 0x2A, mod1−key0 = 0x2C for every mode — matches.

Callers: interact prompt tips `0xC`/`0x1E`; attack HUD slots 8/9; `FUN_008aab00` token path (WQ-007 residual list).

---

## 4. Surviving contract for AutoCore

```
// Client ActionMap bind display
ok = ActionMap_FormatSlotBindDisplay(out, idx, lane, actionMap, mode)
// out gets "" on fail; "KEY" or "MOD+KEY" on success
// lane 0 primary pair; lane!=0 alt pair
// no server packet side effects
```

---

## 5. Verdict

Adversarial pass confirms A after correcting decompiler phantoms via `read_memory`. **accept**.
