# Review B (skeptical / adversarial): `aa_0090cbc0` MedalUI_RefreshPagedAchievementSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090cbc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-063) |
| **Counterpart** | `reviews/A_aa_0090cbc0_MedalUI_RefreshPagedAchievementSlots_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall **ECX**=host | **Falsified** — entry `MOV ESI,EAX`; ECX only set for vcalls; callers seed **EAX** |
| 2 | Stack formals / `RET 4` | **Falsified** — no stack args; bare **`RET`** (`C3`) both exits |
| 3 | This **is** the debug-stop helper (`Named_VOG_DEBUG_STOP_*`) | **Falsified** — `VOG_DEBUG_STOP` only on hash lock faults via `FUN_007a4480`; body is full UI rebuild |
| 4 | This awards / grants medals / completes objectives | **Falsified** — no complete/grant callees; only UI prep/count/apply; force-complete is **caller** `Client_RecvCompleteDynamicObjective` |
| 5 | Decompiler `void FUN_0090cbc0(void)` with phantom `in_EAX` means no host | **Falsified** — `in_EAX` is real ABI register this; assembly `MOV ESI,EAX` seals it |
| 6 | Page stride is 24 (full page) not 3 | **Falsified** — skip test is `pageIndex * 3` (`LEA ECX,[ECX+ECX*2]`); maxPage uses `(count-25)/3+1` |
| 7 | Slot capacity other than 24 | **Falsified** — loops `CMP …,0x18` / prep sibling clears 24 |
| 8 | `FUN_0090c700` is thiscall ECX | **Falsified** (sibling dual) — parent `MOV EDI,ESI` before CALL; prep is **EDI**-host |
| 9 | Only one caller (force-complete) | **Falsified** — **6** xrefs including achievements window init and JMP tail |
| 10 | Product RTTI name sealed here | **Fails** — no RTTI/string class name in body → `_Inferred` required |
| 11 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX host + bare RET | **High** | Wrong ABI / clobber |
| Manager `DAT_00d1b6d8` + visible gate | **High** | Spurious refresh / crash |
| Prep→count→page→fill order | **High** | Slot leaks / wrong page |
| +0x50c / +0x5a0 / +0x5a4 host fields | **High** | Wrong scroll state |
| 24 slots / stride 3 / flag 0\|1 apply | **High** | Wrong grid layout |
| Medal UI role (not grant) | **High** | Wrong port semantics |
| Product class English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

```text
// Primary force-complete site (assembly authority):
00810153  MOV  EAX,[EDI+0x1034]
00810159  MOV  EAX,[EAX+0x514]
0081015f  CALL 0x0090cbc0

// JMP tail (not CALL) — still EAX host:
0080ce84  MOV  EAX,ESI
0080ce87  JMP  0x0090cbc0

// Entry ABI:
0090cbcd  MOV  ESI,EAX

// Page math sealed:
0090cc0e  MOV  EAX,0x55555556   ; signed /3
0090cc1a  CMP  ECX,0x18         ; count > 24 branch
0090ccda  LEA  ECX,[ECX+ECX*2]  ; pageIndex * 3

// Exits:
0090cde0  RET
0090cdfe  RET                   ; last insn; next CC then 0090ce00
```

A ≡ B on live decompile + full disasm + xref assembly_context. Decompile body **unchanged** vs 2026-07-23 raw (append-only re-verify).

---

## 4. Surviving contract for AutoCore

```text
// Port as MedalUI paged achievement slot refresh orchestrator:
// - inputs: host* in EAX; no stack formals; void; bare RET
// - require DAT_00d1b6d8 + host vtbl[+0x3d8]
// - clear 24 slots (prep 0090c700 / EDI=host)
// - count via 0090c810 (EBX=manager)
// - page fields host+0x50c / +0x5a4; scrollbar +0x5a0
// - fill ≤24 from pageIndex*3: vector flag=1 then hash flag=0 via 0090c9a0
// Do NOT treat as thiscall ECX, RET 4, medal grant, or VOG_DEBUG_STOP helper.
// Do NOT invent product class names (use _Inferred).
```

---

## 5. Verdict

Adversarial pass confirms A's ABI, CF, paging constants, dual-source fill, and multi-caller surface. Rejects ECX-thiscall / RET4 / grant / debug-stop-misname overclaims. Residual product English + runtime → **accept-with-gaps**.
