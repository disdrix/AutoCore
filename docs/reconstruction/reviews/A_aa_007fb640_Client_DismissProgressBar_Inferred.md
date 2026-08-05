# Review A (reconstruction fidelity): `aa_007fb640` Client_DismissProgressBar_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb640` |
| **VA** | `0x007fb640` |
| **Canonical name (claim)** | `Client_DismissProgressBar_Inferred` |
| **Ghidra** | `FUN_007fb640` |
| **Aliases** | `Named_CalleeOf_Client_RecvSkillStatusEffect_007fb640` (parent-seed only) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007fb640_Client_DismissProgressBar_Inferred.md` |
| **System** | skills-abilities / client-ui (shared progress chrome) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Dismiss / hide the client timed progress-bar widget** at `client+0x1120`.

Sequence when the bar is present and a visibility probe succeeds:

1. Optional **detach** from a UI host at `client+0xf38` when `bar+0x2b0 != 0` (`host.vtbl+0xb0(bar)`).
2. **Tail-call** `bar.vtbl+0x440` (hide/dismiss implementation — `JMP`, not `CALL`).

Silent no-op when the bar pointer is null or the `+0x3d8` probe returns false.

Sibling of `Client_ShowTimedProgressBar_Inferred` (`0x007fb690`), which always calls this first to clear prior chrome before reprogramming title/status/colors/rate.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007fb640_FUN_007fb640.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_007fb640_FUN_007fb640.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007fb640.cpp` |
| Function record | `docs/reconstruction/functions/aa_007fb640_FUN_007fb640.md` |
| Live Ghidra | `decompile_function` + `disassemble_function` + `read_memory` + xrefs/callers |
| Sibling dual | `reviews/A_aa_007fb690_*` / `B_aa_007fb690_*` |
| Call sites | 5 UNCONDITIONAL_CALL xrefs (see §4) |

---

## 3. Signature / ABI

```c
// ESI = Client*  (register convention; decompiler recovers as unaff_ESI)
// no stack formals; plain RET
void Client_DismissProgressBar_Inferred(void /* ESI=client */);
```

### Image (disasm + `read_memory` @ `0x007fb640`, 2026-07-29)

```
007fb640  CMP  dword ptr [ESI + 0x1120], 0
007fb647  JZ   0x007fb687                 ; no-op
007fb649  MOV  ECX, [ESI + 0x1120]         ; bar
007fb64f  MOV  EAX, [ECX]
007fb651  CALL dword ptr [EAX + 0x3d8]     ; bool probe (AL)
007fb657  TEST AL, AL
007fb659  JZ   0x007fb687                 ; probe false → no-op
007fb65b  MOV  EAX, [ESI + 0x1120]
007fb661  CMP  dword ptr [EAX + 0x2b0], 0
007fb668  JZ   0x007fb679                 ; skip detach
007fb66a  MOV  ECX, [ESI + 0xf38]          ; host/manager
007fb670  MOV  EDX, [ECX]
007fb672  PUSH EAX                        ; bar
007fb673  CALL dword ptr [EDX + 0xb0]      ; detach
007fb679  MOV  ECX, [ESI + 0x1120]
007fb67f  MOV  EAX, [ECX]
007fb681  JMP  dword ptr [EAX + 0x440]     ; tail-call dismiss/hide
007fb687  RET
```

Hex head (`read_memory` 80B): `83be2011000000`…`ffa040040000c3` — seals `CMP [ESI+0x1120]`, `CALL [vtbl+0x3d8]`, `JMP [vtbl+0x440]`, plain `RET`.

| Claim | Match | Confidence |
|---|---|---|
| ESI = client; all `[ESI+disp]` | **Yes** | **Confirmed** |
| Zero stack args / plain `RET` | **Yes** | **Confirmed** |
| Gate `client+0x1120` | **Yes** | **Confirmed** |
| Probe `bar.vtbl+0x3d8` → AL | **Yes** | **High** |
| Conditional detach via `client+0xf38` / `+0xb0` when `bar+0x2b0` | **Yes** | **High** |
| Final dismiss is **tail JMP** `+0x440` | **Yes** | **Confirmed** |
| Decompiler “jumptable” warning | **Misleading** | **Confirmed** — single indirect JMP, not a switch table |

---

## 4. Callers (xrefs)

| Caller VA | Symbol / role | Site |
|---|---|---|
| `0x007fb690` | `Client_ShowTimedProgressBar_Inferred` — **always first** (`MOV ESI,EAX` then `CALL`) | `0x007fb693` |
| `0x00811170` | `Client_RecvSkillStatusEffect` — dismiss on status path | `0x0081130e` |
| `0x007fe8d0` | UseItem objective UI path — dismiss after string/helper work | `0x007fea0f` |
| `0x0080be70` | Switch dispatcher **case 3** → bare dismiss (`MOV ESI,EDI` then `CALL`) | `0x0080bea8` |
| `0x0091edd0` | `"Contact Interrupted!"` toast path; clears `param+0xc24` then dismiss | `0x0091ee11` |

Multi-caller: **not** skill-status-only. Shared client UI dismiss leaf.

---

## 5. Control flow: clean ≡ raw ≡ live asm

| Stage | Match |
|---|---|
| Null bar → RET | **Yes** |
| Probe false → RET | **Yes** |
| Optional host detach then dismiss | **Yes** |
| Tail JMP (no return after dismiss when taken) | **Yes** |
| No network send / no skill state machine | **Yes** |
| No stack formals | **Yes** |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Progress-bar dismiss leaf | **High** | sibling show always prefixes; multi dismiss sites |
| `client+0x1120` = bar widget | **High** | shared with show dual |
| `+0x3d8` = bool can-dismiss / is-active probe | **High** (role); English open | same slot family as inventory cursor pane probes |
| `bar+0x2b0` attachment flag/parent link | **High** as gate; English open | |
| `client+0xf38` host + `vtbl+0xb0` detach | **High** structural | distinct from show's attach host `+0xf40` |
| `vtbl+0x440` hide/dismiss | **High** role; product name open | complements show `+0x43c` reset / `+0xcc` show |
| Product class / vtbl English | **Open** | ProgressBar / NDUI* |
| Runtime / bit-exact / image diff | **Open** | deferred |

---

## 7. Gaps / open

1. Product class name for widget at `client+0x1120`.
2. English names for `vtbl+0x3d8`, `+0x440`, host `+0xb0`.
3. Precise meaning of `bar+0x2b0` (parent ptr vs flag vs slot).
4. Relationship of dismiss host `+0xf38` vs show attach host `+0xf40` (sibling dual uses `+0xf40` only).
5. Runtime pixel hide / focus side-effects.

**Verdict:** **accept-with-gaps** — ABI (ESI client, 0 stack), CF, and shared dismiss role sealed; product symbols open.
