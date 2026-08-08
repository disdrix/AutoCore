# Review B (skeptical / adversarial): `aa_008ab550` Client_NpcMissionDialog_ApplyPanelMode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-051) |
| **Counterpart** | `reviews/A_aa_008ab550_Client_NpcMissionDialog_ApplyPanelMode_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure `__fastcall` with only ECX; mode is return of `FUN_007a69d0` | **Falsified** — `MOV EDI,EAX` **before** locale call; locale → **EBP**; mode store uses **EDI** |
| 2 | Stack formals / `RET 4` | **Falsified** — no stack args; plain `C3` both exits |
| 3 | Only handles multi-mission ("Select a Mission" exclusive) | **Falsified** — modes 0/1/2 also; string path is **mode==3 only** |
| 4 | Thiscall on locale for whole function | **Falsified** — locale is only `this` for `FUN_007a6de0` inside mode-3 block |
| 5 | Title widget always shown | **Falsified** — `show(title, mode != 0)`; mode 0 hides |
| 6 | Always shows `+0x6f8/+0x6fc` | **Falsified** — only mode 1/2 show; 0/3 hide |
| 7 | `FUN_008ab340` is thiscall with explicit arg | **Falsified** — `CALL` with **ESI=dialog** (unaff_ESI in its decompile); no stack arg |
| 8 | Product name sealed from RTTI | **Fails** — string + parent graph only → `_Inferred` |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 10 | `DAT_00d1e818/1c` are compile-time non-zero scale bases | **Falsified for static image** — `read_memory` shows **0**; runtime viewport |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX dialog + EAX mode + plain RET | **High** | Wrong ABI / register smash |
| Mode table 0/3 hide vs 1/2 show | **High** | Wrong chrome visibility |
| Mode-3 "Select a Mission:" fill | **High** | Wrong multi-mission UI |
| Locale vs mode register split | **High** | Mis-port of decompiler lag |
| Caller EAX framing 3/1/0 | **High** | Wrong entry modes |
| Widget English / mode1≠mode2 | **Med** (open) | Naming only |
| FUN_008ab340 semantics | **Med** (not OWN) | List clear side effects |
| Runtime scale | **Open** | Matrix policy |

---

## 3. Cross-check

```text
// Call sites (assembly authority via get_assembly_context):
//   0094396b  MOV EAX,3 ; 00943970 MOV ECX,EBX ; CALL 008ab550  // multi-active
//   00943a65  MOV EAX,1 ; 00943a6a MOV ECX,EBX ; CALL 008ab550  // single present
//   0093e61f  XOR EAX,EAX ; 0093e621 MOV ECX,EBX ; CALL 008ab550 // dialog case 0
// Entry: 55 56 57 8B F8 8B F1 E8 <Locale>
// Exit:  CALL 008ab340 ; 5F 5E 5D C3
// String @ 00a4aba0: "Select a Mission:"
// Floats: aaa67c≈1/1600, aaa678≈1/1200; d1e818/1c static 0
```

A ≡ B on live decompile + full disasm + xref assembly_context + constant bytes.

---

## 4. Surviving contract for AutoCore

```text
// Port as NPC mission dialog panel-mode applicator:
// - inputs: dialog* (ECX), panelMode (EAX ∈ {0,1,2,3}), plain RET
// - store mode at dialog+0x648
// - mode 0/3: hide single-mission/response chrome; clear +0x670 / +0x580
// - mode 1/2: +0x678/+0x67c = -1; show +0x6f8/+0x6fc
// - mode 3: title +0x6dc ← "Select a Mission:" via Locale+StringPool; scale; color; layout
// - always FUN_008ab340 with ESI=dialog
// Do not treat mode as Locale return; do not invent stack args; do not invent RTTI name.
```

---

## 5. Verdict

Adversarial pass confirms A's ABI, mode table, mode-3 multi-mission fill, and caller framing. Rejects decompiler `in_EAX`/locale-as-mode, stack-arg, and "select-only" overclaims. Residual product English + `FUN_008ab340` dual + runtime scale → **accept-with-gaps**.
