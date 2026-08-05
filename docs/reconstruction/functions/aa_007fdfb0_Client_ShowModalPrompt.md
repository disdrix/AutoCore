# Function record: Client_ShowModalPrompt

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fdfb0` |
| **Canonical name** | `Client_ShowModalPrompt` |
| **Prior / Ghidra name** | `FUN_007fdfb0` |
| **Rejected alias** | `Named_VOG_DEBUG_STOP_007fdfb0` — string is null-host assert only |
| **Address** | `0x007fdfb0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client::ui` (missions-progression abandon consumer) |
| **Completion status** | **Human-refined** — dual-id store + OK/Cancel widget bind sealed; abandon Yes/No pairing **High** (UF-009) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Show a client modal prompt / message box. Writes **primary** and **secondary** modal-result codes onto the modal host object, then localizes and displays `message`.

## Signature (asm-corrected)

```c
// EAX = primaryButtonId (OK / Yes) at CALL — not in Ghidra stack prototype
void Client_ShowModalPrompt(
    void* game,              // &DAT_00d1a840
    void* message,           // text or pre-localized string
    int   secondaryButtonId, // Cancel / No; <0 => single-button (both = primary)
    int   flagA,             // typically 1
    int   flagB);            // typically 0
```

## Dual-id map (modal host = `*game+0xf40`)

| Offset | Written from | Role |
|---:|---|---|
| `+0x498` | **EAX** (primary) | OK / Yes button modal code |
| `+0x49c` | `secondaryButtonId` if `>= 0`, else EAX | Cancel / No (or same for toast) |
| `+0x514` | previous `+0x498` | backup |
| `+0x518` | previous `+0x49c` | backup |

## Abandon pairing (UF-009 sealed **High**)

| Step | Evidence |
|---|---|
| Open site sets `EAX=0x4e46`, stack secondary `0x4e47` | asm `008ae8be` / `008ae8af` in `Client_MissionDialogHandleButton` |
| Stores Yes→`+0x498`, No→`+0x49c` | asm dual-id block at `007fe02c` / `007fe060` |
| Dispatch Yes `0x4e46` → C2S `0x20B2` | `Client_UiModalDispatch` case |
| Dispatch No `0x4e47` → close only | same, dismiss family |

**Convention:** dual-button openers load **primary (often even) in EAX** and **primary+1 cancel on stack**. Decompiler views that omit EAX mislead (open “code” looks like cancel-only).

## Artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_007fdfb0_FUN_007fdfb0.md` (+ 2026-07-29 append) |
| Annotated | `raw/aa_007fdfb0_FUN_007fdfb0.annotated.md` |
| Clean | `reconstructed-exact/Client_ShowModalPrompt.cpp` |
| Prior scaffold | `reconstructed-exact/FUN_007fdfb0.cpp` |
| Dual A | `reviews/A_aa_007fdfb0_Client_ShowModalPrompt.md` |
| Dual B | `reviews/B_aa_007fdfb0_Client_ShowModalPrompt.md` |
| Chain | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| Downstream | `functions/aa_00911840_Client_UiModalDispatch.md` |
| Upstream | `functions/aa_008ae7c0_*` HandleButton |

## Confidence

| Claim | Level | Rationale |
|---|---|---|
| Dual-id store CF | **High** | asm + decompile agree |
| Abandon Yes=`0x4e46` / No=`0x4e47` | **High** | open-site EAX + stack + dispatch |
| EAX is ABI primary id | **High** | many callers `MOV EAX, imm` before CALL |
| flagA = blocker chrome (`panel+0x530`) | **High** | `FUN_008a7090` asm |
| flagB full semantics | Open | unused in this body |
| OK/Cancel widget bind | **High** | `CDlgPopup` + `CNDUICtrlButton` (see residual scratch) |
| All modal codes globally | Scaffold | only pairing convention sealed |
| Overall (UF-009 abandon + widget bind) | **High** | open-site EAX + button program path |

## Widget bind (dual residual sealed 2026-07-29)

| Role | Object | Evidence |
|---|---|---|
| Popup shell | `CDlgPopup` (`i_d_pop.xml`) at `game+0x1118` | `FUN_008a7640` / RTTI |
| OK button | `CNDUICtrlButton` @ `popup+0x550`, `i_d_pop_2d_btn_ok.xml` | `FUN_008a7240` |
| Cancel button | `CNDUICtrlButton` @ `popup+0x554`, `i_d_pop_2d_btn_cancel.xml` | same |
| Program OK | `FUN_008a7150`: `btn.vtbl+0x74(primary)` → `button+0xec` | asm after dual-id store |
| Program Cancel | `MOV EDI,EBP` then `FUN_008a7100` | asm `007fe0c1` |
| Get codes | `FUN_008a70e0` / `FUN_008a70c0` → `vtbl+0x78` | keyboard / ESC |

Scratch: `reviews/a_007fdfb0.md`.

## Open questions

- ~~Widget-level bind: which concrete button child~~ **Sealed High** — OK=`+0x550`, Cancel=`+0x554`, codes at `button+0xec`.
- Full meaning of trailing `flagB` (unused in this body; `flagA` = blocker show).
- Title path (`FUN_007a69d0` / `unaff_retaddr`) exact string source.
