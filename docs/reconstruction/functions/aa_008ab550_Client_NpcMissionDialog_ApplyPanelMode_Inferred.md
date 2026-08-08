# Function record: `Client_NpcMissionDialog_ApplyPanelMode_Inferred` (`FUN_008ab550`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab550` |
| **Canonical name** | `Client_NpcMissionDialog_ApplyPanelMode_Inferred` |
| **Ghidra name** | `FUN_008ab550` |
| **Address** | `0x008ab550`–`0x008ab799` (**586 B** / `0x24A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B sealed** MEGA-051 2026-08-05 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual A/B** | `reviews/A_aa_008ab550_Client_NpcMissionDialog_ApplyPanelMode_Inferred.md` · `reviews/B_aa_008ab550_Client_NpcMissionDialog_ApplyPanelMode_Inferred.md` |

## Alias

| Alias | Note |
|---|---|
| `FUN_008ab550` | Ghidra default |
| `Mission_Select_a_Mission` / `_008ab550` | **Retired** (string-only; understated modes 0/1/2) |

## Purpose

NPC mission dialog **panel-mode applicator**:

| Mode | Effect |
|---|---|
| **0** | Hide multi/single chrome; clear `+0x670`; hide title |
| **1** | Show `+0x6f8/+0x6fc`; TFID slots `+0x678/+0x67c = −1` (single-mission present path) |
| **2** | Same chrome path as 1 in this unit |
| **3** | Multi-mission fill: title `+0x6dc` ← `"Select a Mission:"` (localize + scale + color + layout); hide single-mission chrome |

Always ends with residual `FUN_008ab340` (ESI=dialog) to clear list-row vectors.

## Signature (sealed)

```c
// ECX = dialog*; EAX = panelMode {0,1,2,3}; void; plain RET (C3)
void Client_NpcMissionDialog_ApplyPanelMode_Inferred(void *dialog, int panelMode);
```

**Decompiler lag (corrected):** Ghidra shows mode as `in_EAX` after `FUN_007a69d0`. Assembly: entry **EAX→EDI** (mode), locale return **→EBP**, store `dialog+0x648 = EDI`.

## Key fields (dialog host)

| Offset | Role |
|---|---|
| `+0x648` | Panel mode store |
| `+0x670` | Cleared on mode 0/3 |
| `+0x678` / `+0x67c` | TFID-like pair → `−1` on mode 1/2 |
| `+0x580` | Flag cleared on mode 0/3 |
| `+0x6dc` | Title widget (mode-3 fill) |
| `+0x6e4` / `+0x6e8` / `+0x68c` / `+0x690` | Chrome hide targets |
| `+0x698..+0x6d4` | 4×4 widget grid hide |
| `+0x6f8` / `+0x6fc` | Alternate chrome (show 1/2; hide 0/3) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008ab550_FUN_008ab550.md`
- Annotated: `docs/reconstruction/raw/aa_008ab550_FUN_008ab550.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_NpcMissionDialog_ApplyPanelMode_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_008ab550.cpp`
- FUN record: `docs/reconstruction/functions/aa_008ab550_FUN_008ab550.md`
- Report: `docs/agents/task-dual-ab-008ab550-mega-051-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `Client_ShowNpcMissionDialogUI` (EAX=3 multi, EAX=1 single); `FUN_0093e450` (EAX=0) |
| Callees | `Locale_GetInstance_Inferred` (`007a69d0`) [dualed]; `StringPool_ApplyModeAndRingStore_Inferred` (`007a6de0`) [dualed]; `FUN_008ab340` [MEGA-105 residual]; widget vtbl `+4/+0x1b0/+0x1d8/+0x15c/+0x34c` |

## Related (not owned)

| VA | Role |
|---|---|
| `0x009438f0` | Parent `Client_ShowNpcMissionDialogUI` |
| `0x0093e450` | Dialog interact case-0 caller |
| `0x008ab340` | List-row clear (MEGA-105) |
| `0x007a69d0` / `0x007a6de0` | Locale + string pool (dualed) |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / mode table / string fill | **High** (dual A/B 2026-08-05) |
| Caller EAX framing 3/1/0 | **High** |
| Product class / method demangle | **Inferred** |
| Mode 1 vs 2 English distinction | **Open** |
| Runtime viewport scale | **Open** |
| Runtime / bit-exact | **Open** |
