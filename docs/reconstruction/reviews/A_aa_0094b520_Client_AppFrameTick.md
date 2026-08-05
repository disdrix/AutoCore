# Review A (reconstruction fidelity): `aa_0094b520` Client_AppFrameTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094b520` |
| **VA** | `0x0094b520` |
| **Body span** | `0094b520`–`0094b9b5` (~0x496 B) |
| **Canonical name** | `Client_AppFrameTick` (structural) |
| **Ghidra name** | `FUN_0094b520` |
| **Review date** | `2026-07-29` (W20-A OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0094b520_Client_AppFrameTick.md` |
| **System** | client / main-loop frame |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Per-frame application tick** invoked as the sole work body of the client Win32 message pump (`FUN_0094b9c0`):

1. Gate on `client+0x13` (master enable).
2. Nested timer/QPC counters on global `DAT_00d09874`.
3. Gate on `client+0xf40`; then **focus/UI poll** `FUN_0093a5c0(0)` — non-zero skips the rest.
4. Ordered subsystem fan-out under `+0xa1` / `+0xb7` / session `+0xe04` flags (HB list tick, session, load-queue test, UI event queue, optional frametime file log).
5. `Sleep(0)`; always **return 1**.

Not a frametime-only helper — the `..\logs\frametime.txt` path is a **conditional diagnostic arm**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0094b520_FUN_0094b520.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_0094b520_FUN_0094b520.annotated.md` |
| Clean plate | `docs/reconstruction/reconstructed-exact/Client_AppFrameTick.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_0094b520.cpp` |
| Function record | `docs/reconstruction/functions/aa_0094b520_Client_AppFrameTick.md` |
| Live decompile | Ghidra @ `0x0094b520` (full body; ≡ raw) |
| Bytes | `read_memory` prologue 64 B @ `0x0094b520`; epilogue @ `0x0094b9b0` |
| Caller | `FUN_0094b9c0` sole xref (decompile pump loop) |
| Related duals | FocusGate `aa_0093a5c0`, HB list tick `aa_00507950`, UI queue `aa_00946c00` |

**Not performed:** `disassemble_bytes`, Launcher, full runtime golden.

---

## 3. Prologue / epilogue seal (`read_memory`)

### Prologue @ `0x0094b520`

```text
64 a1 00 00 00 00     mov  eax, fs:[0]
6a ff                 push -1
68 33 bf 9b 00        push LAB_009bbf33
50                    push eax
b8 a4 86 01 00        mov  eax, 0x186a4
64 89 25 00 00 00 00  mov  fs:[0], esp
e8 …                  call chkstk/alloca_probe
57                    push edi
8b f9                 mov  edi, ecx            ; client*
80 7f 13 00           cmp  byte ptr [edi+0x13], 0
0f 84 50 04 00 00     je   skip_body
```

Hex (first 64 B):

```
64a1000000006aff6833bf9b0050b8a486010064892500000000e83188d5ff578bf9807f13000f8450040000a17498d00080782500538b1db0619c00568d7005
```

### Epilogue near `0x0094b9b0`

```
81 c4 b0 86 01 00     add  esp, 0x186b0
c3                    ret
```

| Claim | Evidence | Conf |
|---|---|---|
| `__fastcall` ECX client | `mov edi,ecx` | **Confirmed** |
| Outer gate `+0x13` | `cmp byte [edi+0x13],0` | **Confirmed** |
| Large SEH/chkstk frame | prologue imm `0x186a4` + epilogue `add esp,0x186b0` | **Confirmed** |
| Live decompile ≡ raw CF | full side-by-side | **Confirmed** |
| Sole caller pump `FUN_0094b9c0` | xrefs + decompile | **Confirmed** |
| Always return 1 | decompiler final `return 1` | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = client app frame tick | **High** | sole pump body + subsystem fan-out |
| Focus gate arg **0** | **High** | sealed by FocusGate dual + asm `push 0` |
| HB list `Tick(client+0xd38, 0)` | **High** | sealed by CVOGHBList_Tick dual |
| UI queue after `FUN_00944770` | **High** | DispatchUiEventQueue dual |
| Strings / LoadQueue test | **Confirmed** | image strings + decompile |
| Flag English (`+0x13/+0xa1/+0xb7`) | **Inferred structural only** | product open |
| Every nested FUN_* product name | **Partial / Open** | CF order sealed |
| Clean plate ≡ full CF | **High for CF** | types fixed-width; not bit-exact |

---

## 5. Call graph (this unit)

**Callers:** `FUN_0094b9c0` only.

**High-signal callees:** `FUN_0093a5c0(0)`, `CVOGHBList_Tick`, `FUN_00946c00`, `FUN_0094b3a0`, profile `FUN_0079a1c0/120`, `QueryPerformanceCounter`, `Sleep`, CRT file I/O, many still-FUN subsystem ticks.

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Role = app frame of main loop | **Yes** (pump caller + body) |
| Product/PDB symbol | **No** |
| String proves whole-function name | **No** (frametime / LoadQueue are sub-arms) |

**Decision:** promote structural **`Client_AppFrameTick`**. Reject `Named_frametime_txt` as primary (diagnostic arm only).

---

## 7. Gaps

1. Product/PDB name for unit and for client flag fields.
2. Full product map of un-dualed nested `FUN_*` callees.
3. Profile bucket ID English.
4. Exact float product meaning of `0x3b888889` beyond bits (~1/240).
5. Runtime ordering / multi-frame golden / differential.

**Verdict:** **accept-with-gaps** — CF + ABI + gates + sole-caller role sealed; product English residual.
