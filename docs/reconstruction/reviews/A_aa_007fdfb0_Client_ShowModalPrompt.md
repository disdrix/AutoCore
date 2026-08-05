# Review A (reconstruction fidelity): `aa_007fdfb0` Client_ShowModalPrompt

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fdfb0` |
| **VA** | `0x007fdfb0` |
| **Canonical name (claim)** | `Client_ShowModalPrompt` |
| **Ghidra** | `FUN_007fdfb0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007fdfb0_Client_ShowModalPrompt.md` |
| **Chain** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **Verdict** | **accept** for dual-id store + abandon Yes/No pairing + OK/Cancel widget bind (**High**); **accept-with-gaps** for `flagB` / full show path |
| **Residual scratch** | `reviews/a_007fdfb0.md` (2026-07-29 widget bind seal) |

---

## 1. Purpose

Open a modal prompt: clear prior modal, program **two** modal-result codes on the host UI object, show message text. Downstream `Client_UiModalDispatch` switches on those codes when the user clicks.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `decompile_function` / `analyze_function_complete` `0x007fdfb0` |
| Dual-id asm | `get_assembly_context` at `007fe02c`..`007fe060` |
| Abandon open asm | `008ae8ab`..`008ae8c3` (`MOV EAX,0x4e46` / `PUSH 0x4e47`) |
| Peer dual callers | `0080fb5c` (`0x4e2c`/`0x4e2d`), `008638f0` (`0x4e5a`/`0x4e5b`) |
| Dispatch | `FUN_00911840` cases `0x4e46` / `0x4e47` |
| Clean | `reconstructed-exact/Client_ShowModalPrompt.cpp` |

---

## 3. Sealed control flow (dual ids)

1. `FUN_007fc360()` — dismiss existing modal.
2. Require `*game+0xf40` modal host live.
3. Backup `host+0x498` → `+0x514`; write **EAX** → `+0x498` (primary).
4. Backup `host+0x49c` → `+0x518`.
5. If `param_3 < 0`: `+0x49c = EAX` (single-button). Else `+0x49c = param_3` (secondary).
6. Message panel at `game+0x1118`: localize / `FUN_008a6fd0(message)` / show; else `"VOG_DEBUG_STOP"`.
7. Optional chrome flags at `game+0xf38` / `+0x31d8`.

---

## 4. Abandon Yes/No (UF-009)

| Fact | Confidence |
|---|---|
| Open: `EAX=0x4e46`, stack secondary `0x4e47` | **High** (asm) |
| Store: `+0x498=0x4e46`, `+0x49c=0x4e47` | **High** |
| Click Yes → case `0x4e46` → C2S `0x20B2` | **High** (dispatch dual) |
| Click No → case `0x4e47` → close only | **High** |
| Decompiler call site omitted EAX | **High** (systematic) |

**Pairing confidence: High.** Prior “Probable from adjacency” residual is closed by open-site `MOV EAX,0x4e46`.

---

## 5. Pairing convention (broader)

Dual-button openers consistently:

```
MOV EAX, <primary>     ; often N (even in 0x4eXX band)
PUSH <primary+1>       ; cancel / secondary
CALL Client_ShowModalPrompt
```

Single-button / toast: `param_3 = -1`, both slots = EAX (e.g. `0x4e24`).

---

## 6. Confidence table

| Claim | Level | Notes |
|---|---|---|
| Function shows modal + dual codes | **High** | |
| `+0x498` primary / `+0x49c` secondary | **High** | store order + callers |
| Abandon Yes=`0x4e46` No=`0x4e47` | **High** | UF-009 |
| Name `Client_ShowModalPrompt` | **High** | better than VOG_DEBUG_STOP |
| flagA = blocker at `panel+0x530` | **High** | `FUN_008a7090` |
| flagB semantics | Open | unused in body |
| Widget child bind source | **High** | `CNDUICtrlButton` OK `+0x550` / Cancel `+0x554`; code `@button+0xec` |

---

## 7. Widget bind (residual sealed)

1. Popup `CDlgPopup` built by `FUN_008a7240` with OK/Cancel from `i_d_pop_2d_btn_{ok,cancel}.xml`.
2. ShowModalPrompt programs OK with primary (`FUN_008a7150`), then `MOV EDI,EBP` and programs Cancel (`FUN_008a7100`).
3. Button `vtbl+0x74` / `+0x78` = set/get `this+0xec` (`0x0040cc80` / `0x0040cc70`).
4. Keyboard/ESC read button codes then `vtbl+0x338(8, code)` → dispatch.

Scratch: `reviews/a_007fdfb0.md`.

---

## 8. Verdict

**Accept** the dual-id assignment, abandon pairing, and OK/Cancel widget bind at **High**. Prefer product name `Client_ShowModalPrompt`. `flagB` and bit-exact remain open; they do not affect UF-009.
