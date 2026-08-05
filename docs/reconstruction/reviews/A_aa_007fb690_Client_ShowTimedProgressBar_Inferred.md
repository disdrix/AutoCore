# Review A (reconstruction fidelity): `aa_007fb690` Client_ShowTimedProgressBar_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb690` |
| **VA** | `0x007fb690` |
| **Canonical name (claim)** | `Client_ShowTimedProgressBar_Inferred` |
| **Ghidra** | `FUN_007fb690` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007fb690_Client_ShowTimedProgressBar_Inferred.md` |
| **System** | skills-abilities / client-ui |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Show/configure the client timed progress-bar widget (`client+0x1120`): dismiss prior bar, optional host attach (`client+0xf40`), program title + status + 3 colors + start + max 1.0 + fill rate + show + refresh. Shared chrome for skill charge activation and other timed ops.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007fb690_FUN_007fb690.md` (freeze + 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_007fb690_FUN_007fb690.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007fb690.cpp` |
| Function record | `docs/reconstruction/functions/aa_007fb690_FUN_007fb690.md` |
| Live Ghidra | `decompile_function` + `disassemble_function` + `analyze_function_complete` + `read_memory` |
| Call sites | RequestCast `0x00941817`, QB gauge `0x00825799`, string census on other xrefs |
| Residual | `reviews/a_007fb690.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EAX = client; `MOV ESI,EAX` prologue | **Confirmed** | disasm |
| stdcall `RET 0x20` (8 stack dwords) | **Confirmed** | epilogue |
| Gate `+0x1120` and `+0xf40` both non-null | **High** | dual JZ to shared exit |
| Host attach when `**+0xf40 != 0`: `+0x3ec`, `+0x3f4(1)`, `+0xa8(bar)` | **High** | disasm block |
| Title `vtbl+0x468(arg2,1)` / status `+0x46c(arg3,1)` | **High** | |
| Colors via `+0x15c(0,&arg5)`, `(1,&arg4)`, `(2,&arg6)` | **Confirmed** | LEA slots |
| Max `+0x450(1.0f)` literal `0x3f800000` | **Confirmed** | |
| Rate `+0x460((g_flOne - arg0)/arg1)` | **Confirmed** | MOVSS/SUBSS/DIVSS; `g_flOne` @ `0xa0f2a0` |
| Show `+0xcc(1)` then refresh `+0x34c` | **High** | |
| Sibling dismiss `FUN_007fb640` first | **High** | |
| RequestCast: charge×0.001 + `"...Activating Skill..."` + `0xFF400000` | **High** | call-site asm + string |
| Multi-use (Working/INC/Training/Crafting) | **High** | other site strings |
| Product widget / vtbl English names | **Open** | role sealed |
| Clean ≡ raw CF (with asm formal recovery) | **High** | decompiler alone insufficient |

---

## 4. Control flow: clean ≡ raw ≡ live asm

| Stage | Match |
|---|---|
| `FUN_007fb640` then dual gate | **Yes** |
| Optional host attach | **Yes** |
| Reset → title → status → colors → start → max → rate → extra → show → refresh | **Yes** |
| Early return if bar or host null | **Yes** |
| No network send in this body | **Yes** |

---

## 5. Gaps / open

1. Product class name for `client+0x1120` widget (ProgressBar / NDUI*).
2. English names for vtbl slots (`+0x43c` reset, `+0x468` title, `+0x460` rate, etc.).
3. Whether `startOrMode` is always normalized 0..1 (cast path uses 0).
4. Color channel domain (ARGB vs material id) — dwords sealed, semantics open.
5. Runtime / bit-exact / image diff deferred.

**Verdict:** **accept-with-gaps** — ABI + rate formula + RequestCast status-chrome role sealed; product names open.
