# Review B (skeptical / adversarial): `aa_007f72e0` ActionMap_TrySetSlotBind

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f72e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W21-P) |
| **Counterpart** | `reviews/A_aa_007f72e0_ActionMap_TrySetSlotBind.md` |
| **Scratch** | `tmp/a_007f72e0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Plain `__fastcall` only (2 register args) | **Falsified** — AL/BL/SI/DX formals + 2 stack args; decomp phantoms |
| 2 | Always overwrites binds | **Falsified** — flag must be 0 or return 0 |
| 3 | Single key slot layout for all modes | **Falsified** — 4 offset tables |
| 4 | `CONCAT31` return is meaningful HRESULT | **Overstated** — body sets **AL=1/0**; upper bits leftover address math |
| 5 | Has callees / non-leaf | **Falsified** — leaf |
| 6 | Only InitDefaultKeybinds uses it | **Falsified** — also keymap.ini loader with BL=0/1 dual pass |
| 7 | Mode names known (UI/drive/…) | **Unproven** — offsets sealed; names Tentative |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mode switch + JT | **High** | Wrong table writes |
| Bounds / stride 0x34 | **High** | OOB / corrupt ActionMap |
| Flag gate | **High** | Clobber user custom binds |
| BL lane dual offsets | **High** | Primary/alt swap |
| ABI `RET 8` + registers | **High** | Stack smash |
| Mode product names | **Tentative** | Docs only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
mode = stack1; base = stack0; idx = AL; lane = BL; key = SI; mod = DX
if mode>3: AL=0; ret 8
jt[mode]:
  if idx >= max: fail
  slot = base + idx*0x34
  if flag != 0: fail
  write primary or alt pair; clear 2 bytes; AL=1; ret 8
fail: AL=0; ret 8
```

Caller seal:

- InitDefaultKeybinds: `push mode; push edi; xor bl,bl; mov esi,DIK; mov al,idx; call` ×74.
- keymap.ini: two calls (BL=0 then BL=1) per parsed line.

Live decompile ≡ raw. Clean plate carries tables.

---

## 4. Surviving contract for AutoCore

```
// ActionMap bind write (client only)
ok = ActionMap_TrySetSlotBind(idx, lane, key, mod, actionMap, mode)
// if !ok: either OOB mode/index OR slot already customized
// lane 0 → primary DIK pair; lane !=0 → alt pair
// never force-overwrite customized slots

// Port: keep flag gate or user keybinds will be wiped on re-init.
// Defaults path (InitDefaultKeybinds) relies on flag==0 before first write.
```

---

## 5. Verdict

Adversarial pass **confirms** A. No CF/ABI residual that blocks port → **accept**.
