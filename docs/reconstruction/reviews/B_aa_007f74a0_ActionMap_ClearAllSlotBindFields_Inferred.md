# Review B (skeptical / adversarial): `aa_007f74a0` ActionMap_ClearAllSlotBindFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f74a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-019) |
| **Counterpart** | `reviews/A_aa_007f74a0_ActionMap_ClearAllSlotBindFields_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `void` / no args / decompiler truth | **Partially overstated** — decompiler shows `void(void)` + `unaff_ESI`; live caller seals **ESI=ActionMap*** |
| 2 | ECX-thiscall | **Falsified** — entry uses `LEA ECX,[ESI+…]`; ECX is cursor |
| 3 | Writes default DIK codes | **Falsified** — only stores 0; defaults live in parent `InitDefaultKeybinds` after return |
| 4 | Clears entire ActionMap / ctor-zero | **Falsified** — only 7 bind fields × 151 slots; other map fields untouched |
| 5 | Has callees / non-leaf | **Falsified** — leaf; no CALL |
| 6 | Multiple callers | **Falsified (static)** — single UNCONDITIONAL_CALL @ `0x007f8725` |
| 7 | Stride 0x1a bytes (halfword misread) | **Falsified** — `ADD ECX,0x34`; decomp `+0x1a` is halfword units |
| 8 | Mode product names known | **Unproven** — counts/offsets sealed; English Tentative |
| 9 | Same as TrySetSlotBind | **Falsified** — sibling *writes* binds gated by flag; this *zeros* fields unconditionally |
| 10 | `RET 4` / stack cleanup | **Falsified** — bare `C3` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Four banks + counts | **High** | Partial clear / OOB |
| Stride 0x34 | **High** | Corrupt adjacent slots |
| 7 field offsets | **High** | Leave stale binds / flags |
| ESI ABI + bare RET | **High** | Wrong map / stack smash |
| Sole InitDefaultKeybinds caller | **High** (static) | Miss alternate entry |
| Mode product English | **Tentative** | Docs only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
map = ESI
banks = [(0x32,5), (0x136,6), (0x26e,0x78), (0x1ace,0x14)]
for (cur, n) in banks:
  ECX=map+cur; EDX=n; EAX=0
  do:
    zero u16@-0x2a,-0x2c,-2,0 and u8@-0x28,-0x27,-0x26 relative ECX
    ECX+=0x34; EDX--
  while EDX
RET
```

Caller seal:

```
007f8720  PUSH EBX
007f8721  PUSH EBP
007f8722  PUSH ESI
007f8723  MOV  ESI, EDI        ; EDI = ActionMap*
007f8725  CALL 0x007f74a0      ; clear all slot bind fields
007f872a  XOR  EAX, EAX
007f872c  CMP  byte [EDI+0x40], AL   ; first flag-gated default write
...
```

Live decompile ≡ raw CF. Offsets cross-check dualed `ActionMap_TrySetSlotBind` kMax/kKey/kMod/kFlag/kCl tables exactly.

---

## 4. Surviving contract for AutoCore

```
// ActionMap clear prologue (client only)
// ESI = actionMap base; no stack args; void
ActionMap_ClearAllSlotBindFields(actionMap)
// zeros primary+alt DIK/mod, flag, 2 status bytes for all slots in 4 mode banks
// does NOT write defaults; does NOT free; does NOT touch non-bind fields

// Port order for InitDefaultKeybinds:
//   1) ClearAllSlotBindFields(map)   // this VA
//   2) flag-gated default DIK stores + TrySetSlotBind fills
// Skipping step 1 leaves stale customized flags → defaults silently skipped.
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/offsets/caller. Residual product mode English + runtime → **accept-with-gaps**. No CF/ABI residual that blocks port.
