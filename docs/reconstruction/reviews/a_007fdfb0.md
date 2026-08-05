# Dual residual: `0x007fdfb0` Client_ShowModalPrompt

| Field | Value |
|-------|-------|
| Stable ID | `aa_007fdfb0` |
| Address | `0x007fdfb0` |
| Owner | dual residual only (no WORK_QUEUE / RESUME) |
| Date | 2026-07-29 |
| Prior dual | A/B accept — UF-009 Yes/No pairing **High**; open: **OK/Cancel widget class source bind**, flag matrix |

## Residual questions (from dual A/B + matrix)

1. Formal widget class that binds OK → primary (`+0x498` / EAX) and Cancel → secondary (`+0x49c` / stack)
2. Complete `flagA` / `flagB` matrix (non-blocking for abandon)
3. Runtime abandon click observation (nice-to-have; static sealed)

## Seal: OK/Cancel widget bind (**High**)

### Popup shell = `CDlgPopup` (`i_d_pop`)

| Fact | Evidence | Conf |
|------|----------|------|
| Popup ctor reloads `i_d_pop.xml` | `FUN_008a7640` → `NDUIWindow_ReloadInterface("i_d_pop.xml")`; vtbl `PTR_FUN_00a4c0c4` | **High** |
| RTTI | `.?AVCDlgPopup@@` @ `0x00afea04` | **High** |
| Client slot | `game+0x1118` / `DAT_00d1b958` is this popup (message panel used by ShowModalPrompt) | **High** |

### Child build = `FUN_008a7240`

| Slot | Offset | Resource | Class / ctor |
|------|--------|----------|--------------|
| OK button | `popup+0x550` (`[0x154]`) | `i_d_pop_2d_btn_ok.xml` | `CNDUICtrlButton` via `FUN_0079c860` (size `0x4cc`) |
| Cancel button | `popup+0x554` (`[0x155]`) | `i_d_pop_2d_btn_cancel.xml` | same |
| Message text | `popup+0x544` (`[0x151]`) | `i_d_pop_2d_wnd_message.xml` | `CNDUIWindow` family |
| Blocker | `popup+0x530` (`[0x14c]`) | `i_d_pop_2d_wnd_blocker.xml` | window |

RTTI: `.?AVCNDUICtrlButton@@` @ `0x00aff5c0`. Button vtbl base `PTR_FUN_00a97c34`.

### Code program path inside `Client_ShowModalPrompt` (live asm)

```
; dual-id on modal host (*game+0xf40) — already sealed UF-009
MOV [host+0x498], EDI          ; primary (EAX at call)
; if secondary>=0: [host+0x49c]=EBP else =EDI

; message panel = game+0x1118
CALL panel.vtbl+0x43c
MOV  DL, flagA
CALL FUN_008a7090              ; store flagA @ panel+0x4fc; show/hide blocker +0x530
; title localize + panel.vtbl+0x444
MOV  ESI, panel
CALL FUN_008a7150              ; OK:   button@+0x550 ← EDI (primary)
MOV  ESI, panel
MOV  EDI, EBP                  ; *** switch EDI to secondary ***
CALL FUN_008a7100              ; Cancel: button@+0x554 ← EDI (secondary)
CALL FUN_008a6fd0(message)
CALL panel.vtbl+0x34c          ; show
```

### Button helpers (asm-authoritative)

| Helper | Address | Behavior |
|--------|---------|----------|
| `FUN_008a7150` | `0x008a7150` | If `ESI+0x550`: `btn->vtbl+0x74(EDI)` set code; show if `EDI>=0` else hide (`vtbl+0xcc`); `vtbl+0x34c` refresh |
| `FUN_008a7100` | `0x008a7100` | Same for `ESI+0x554` |
| `FUN_008a70e0` | `0x008a70e0` | Return OK `btn->vtbl+0x78()` else `-1` |
| `FUN_008a70c0` | `0x008a70c0` | Return Cancel `btn->vtbl+0x78()` else `-1` |

### `CNDUICtrlButton` result-code field

| Vtbl | Impl | Effect |
|------|------|--------|
| `+0x74` | `0x0040cc80` | `*(this+0xec) = arg` (stdcall 1 arg) |
| `+0x78` | `0x0040cc70` | `return *(this+0xec)` |

**Contract:** primary modal code is written to **OK button `+0xec`**; secondary to **Cancel button `+0xec`**. Parallel host dual-id remains at modal host `+0x498`/`+0x49c` (keyboard/fallback consumers).

### Dispatch path (read side)

| Path | Behavior | Conf |
|------|----------|------|
| Key bind 4 (primary) | `FUN_008a70e0` → else host/`this[0x126]` (`+0x498`) → `vtbl+0x338(8, code)` | **High** (`FUN_009114f0`) |
| Key bind 5 (secondary) | `FUN_008a70c0` → else `this[0x127]` (`+0x49c`) → `vtbl+0x338(8, code)` | **High** |
| ESC while popup visible | `FUN_008a70c0` → `DAT_00d1b958.vtbl+0x338(8, code)` + `FUN_007fc360` | **High** (`Client_Input_OnKeyDown_MatchAction`) |
| Popup `vtbl+0x338` | `FUN_007a8310` bubbles to parent `vtbl+0x338` | **High** |
| Abandon cases | `Client_UiModalDispatch` `0x4e46`/`0x4e47` + action `8` | **High** (prior dual) |

**Conclusion:** Widget-level OK/Cancel bind is **sealed High**. Physical buttons are `CNDUICtrlButton` children of `CDlgPopup`, programmed by ShowModalPrompt with primary→OK and secondary→Cancel. Invert-labels attack from dual B is falsified by explicit `MOV EDI,EBP` before Cancel program + OK programmed with primary first.

## Flag args (partial seal)

| Arg | Stack (5-arg `__stdcall` RET `0x14`) | Use in body |
|-----|--------------------------------------|-------------|
| `flagA` | 4th stack dword | `FUN_008a7090`: `panel+0x4fc = flagA`; show/hide **blocker** child `panel+0x530` via `vtbl+0xcc` |
| `flagB` | 5th stack dword | **Not consumed in this function body** after dual-id/show path (no direct load found in `0x007fdfb0` listing) |

Abandon open uses `(flagA, flagB) = (1, 0)` → blocker shown. Full global matrix of flagB remains **open / non-blocking**.

## Residual after this pass

| Item | Status |
|------|--------|
| OK/Cancel widget class + source bind | **Sealed High** (`CNDUICtrlButton` on `CDlgPopup` `+0x550`/`+0x554`; code at `button+0xec`) |
| Primary→OK / secondary→Cancel program order | **Sealed High** (asm `MOV EDI,EBP` before `FUN_008a7100`) |
| Host dual-id `+0x498`/`+0x49c` | **Already High** (UF-009) |
| `flagA` = blocker chrome | **High** for observed path |
| `flagB` full semantics | Open (unused in this body) |
| Runtime abandon click | Optional; static path sealed |
| Bit-exact / image diff | Open (matrix policy) |

## Artifacts touched by residual owner

- This scratch: `docs/reconstruction/reviews/a_007fdfb0.md`
- Duals: `A_aa_007fdfb0_Client_ShowModalPrompt.md`, `B_aa_007fdfb0_Client_ShowModalPrompt.md`
- Function record: `functions/aa_007fdfb0_Client_ShowModalPrompt.md`
- Clean plate comment: `reconstructed-exact/Client_ShowModalPrompt.cpp` (widget bind note)
- `VERIFICATION_MATRIX` open-issues cell for `aa_007fdfb0`
- **Not** WORK_QUEUE / RESUME
- **Not** other function owners
