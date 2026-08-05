# Function record: MissionDialog_ParseMarkupToRichText_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aab00` |
| **Canonical name** | `MissionDialog_ParseMarkupToRichText_Inferred` |
| **Ghidra name** | `FUN_008aab00` |
| **Address** | `0x008aab00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / mission dialog chrome |
| **Classification** | worker |
| **Completion status** | **Dual A/B sealed** (WQ7R-C 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Alias / rejected plates

| Name | Status |
|---|---|
| `FUN_008aab00` | Ghidra default — keep as twin |
| `MissionDialog_ParseMarkupToRichText_Inferred` | **Preferred** structural (string + CF evidence) |
| `Named_npc` | **Reject** as product — single-tag scaffold |
| `Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_008aab00` | **Reject** as product — auto caller chain plate |

## Purpose

Parse a mission/dialog **markup C-string** and drive a **richtext widget**:

1. Copy source into a 4 KiB working buffer (`__chkstk` frame `0x204c`).
2. Scan for `[$…]` tags; flush plain runs via widget **vtbl+0x250** (AppendText).
3. Color open tags call **vtbl+0x230**(ARGB); closes call **vtbl+0x23c** (PopColor).
4. `[$pause]` → **vtbl+0x254**(0x14).
5. `[$key]…[$/key]` → resolve keybind display (`Free Look` / `DAT_00d1bbf5` table / `<%s>` fallback) then AppendText.

Not a network handler. Not journal state mutation.

## Signature (sealed)

```c
// ECX = markupSrc; stack = richtextWidget*; callers ADD ESP,4
void MissionDialog_ParseMarkupToRichText_Inferred(char *markupSrc, int *richtextWidget);
```

| Item | Value |
|---|---|
| Body | `0x008aab00`–`0x008aaf58` exclusive (**1112 B** / `0x458`) |
| Frame | `mov eax,0x204c` + `__chkstk`; epilogue `add esp,0x204c; ret` |

## Markup matrix

| Open | Close | Immediate |
|---|---|---|
| `[$imp]` | `[$/imp]` | color `0xFFFF2D00` |
| `[$npc]` | `[$/npc]` | color `0xFF256EC8` |
| `[$inst]` | `[$/inst]` | color `0xFFC5C025` |
| `[$loc]` | `[$/loc]` | color `0xFFF59623` |
| `[$emote]` | `[$/emote]` | color `0xFF29B525` |
| `[$pause]` | — | pause `0x14` |
| `[$key]` | `[$/key]` | keybind path |

## Callers (6 xrefs)

| Caller | Call site |
|---|---|
| `FUN_008aaf60` (journal chrome path) | `0x008aaff3` |
| `FUN_008a3510` / mission detail panel | `0x008a3c35`, `0x008a3f80` |
| `FUN_008cc5a0` | `0x008cc5c0` |
| `FUN_008cdae0` | `0x008cdf9b` |
| `FUN_008dbe10` | `0x008dbf2c` |

## Callees

`FUN_007a69d0`, `__chkstk`, `FUN_007a6de0`, `FUN_007f5120`, `FUN_007f9160`, `_strnicmp`, `_stricmp`, `sprintf`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008aab00_FUN_008aab00.md`
- Annotated: `docs/reconstruction/raw/aa_008aab00_FUN_008aab00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/MissionDialog_ParseMarkupToRichText_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_008aab00.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008aab00_MissionDialog_ParseMarkupToRichText_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008aab00_MissionDialog_ParseMarkupToRichText_Inferred.md`
- Scratch: `docs/reconstruction/tmp/a_008aab00.md`
- Agent report: `docs/agents/task-dual-ab-008aab00-008aa560-wq7rc-report.md`

## Confidence

| Claim | Level |
|---|---|
| Markup tag matrix + color immediates | **High** |
| ABI ECX=string, stack=widget | **High** |
| Vtbl ordinal roles (names) | **Inferred** / Tentative product English |
| Key table layout stride 0x34 / 120 slots | **High** (bounds math) |
| Runtime key table contents | **Open** (static zeros) |
| Product/PDB name | **Open** |

## Gaps

1. Product English for function and vtbl methods.
2. Exact `FUN_007f9160` side effects when non-zero (skips sprintf).
3. Runtime / bit-exact / differential.
4. Owned callees `FUN_007f5120` / `FUN_007f9160` dualed under WQ7R-G, not here.
