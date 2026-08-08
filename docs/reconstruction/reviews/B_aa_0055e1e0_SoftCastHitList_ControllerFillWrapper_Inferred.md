# Review B (skeptical / adversarial): `aa_0055e1e0` SoftCastHitList_ControllerFillWrapper_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055e1e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R11-003) |
| **Counterpart** | `reviews/A_aa_0055e1e0_SoftCastHitList_ControllerFillWrapper_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Free function / no ECX this | **Falsified** — hub loads controller into **ECX** before CALL; body reads `[ECX+0xC4]` / `[ECX+0xD0]` |
| 2 | Decompiler is full truth (no local entry) | **Falsified** — `LEA ECX,[ESP+0x14]` + `MOV [ESP+0x14],0x009D27A8` before core CALL |
| 3 | Same unit as core fill `006ca890` | **Falsified** — distinct 64 B body; only wraps core; core is 172 B RET 0x14 |
| 4 | Same unit as sort `0048a060` / ctor `0040c410` | **Falsified** — hub orders ctor → **this** → sort; distinct VAs |
| 5 | Bare `RET` / wrong cleanup | **Falsified** — epilog `C2 08 00` (`RET 0x8`); 2 stack formals |
| 6 | Multiple callers / shared generic util | **Falsified** — **1** xref only (`00925c32` in hub) |
| 7 | Forwards hub payload / non-zero payload | **Falsified** — hard `PUSH 0` |
| 8 | Passes controller as core this | **Falsified** — ECX overwritten with manager load, then with local entry LEA |
| 9 | Product name without `_Inferred` | **Fails gate** — no PDB/string for method English |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 11 | Inventory / skill path, not soft-cast interact | **Falsified** — only chain is InteractWorldClickHub soft-cast list path |
| 12 | Allocates heap entry | **Falsified** — stack-only local frame; no `operator_new` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall ECX controller + RET 0x8 | **Confirmed** | Stack imbalance / wrong this |
| Local entry + vtbl install | **Confirmed** | Core this wrong → crash / miss register |
| Sole hub caller | **Confirmed** | Over-generalize system tag |
| manager@+0xC4 / related@+0xD0 | **Confirmed** | Wrong controller layout |
| Payload hard 0 | **Confirmed** | Invented hub payload path |
| Soft-cast hit-list role | **High** | Mis-tag if hub path misread |
| Entry vtbl method map | **Low** | Partial layout only |
| Product English name | **Inferred** | Doc only until string/PDB |

---

## 3. Cross-check against raw / bytes

```text
raw scaffold 2026-07-23  ≡  live decompile 2026-08-05  (CF of collapsed call)
assembly + read_memory   seals local entry / ABI / RET 0x8  (decompiler incomplete)

0055e1e0  PUSH EBP / MOV EBP,ESP / AND ESP,0xFFFFFFF0 / SUB ESP,0x50
0055e1e9  MOV EAX,[EBP+0xC]           ; backref
0055e1ec  MOV EDX,[ECX+0xD0]          ; related
0055e1f2  MOV ECX,[ECX+0xC4]          ; manager
          PUSH backref / 0 / related / soft_desc / manager
0055e201  LEA ECX,[ESP+0x14]          ; local entry this
0055e205  MOV [ESP+0x14],0x009D27A8   ; vtbl
0055e20d  MOV [ESP+0x58],0            ; entry+0x44 = 0
0055e215  CALL 0x006ca890
0055e21a  MOV ESP,EBP / POP EBP / RET 0x8   ; C2 08 00

Body: 0x0055e1e0–0x0055e21f (64 B / 0x40)
Caller: Client_InteractWorldClickHub @ 00925c32 only
Next:   0x0055e220  XOR AX,AX / RET 0x10
```

Reject ports that:

- Trust decompiler alone and omit local entry + vtbl `0x009D27A8`.
- Use bare `RET` / `RET 4` / `RET 0x14` (must be **`RET 0x8`**).
- Treat ECX as SoftCastHitEntry* on entry (it is **controller***; entry is local).
- Merge with core `006ca890`, sort `0048a060`, or ctor `0040c410`.
- Claim runtime Confirmed without Launcher evidence.
- Drop 16-byte stack alignment if bit-exact native interop is required.
- Invent non-zero payload forwarding.

---

## 4. Verdict

**accept-with-gaps** — adversarial attacks on free-fn / decompiler-as-truth / merge-with-core / wrong RET / multi-caller / heap-alloc all **falsified**. Product English + runtime remain open.
