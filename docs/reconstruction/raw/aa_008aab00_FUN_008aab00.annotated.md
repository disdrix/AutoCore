# Annotated low-level: MissionDialog_ParseMarkupToRichText_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_008aab00` |
| VA | `0x008aab00` |
| Ghidra | `FUN_008aab00` |
| Inferred name | `MissionDialog_ParseMarkupToRichText_Inferred` |
| System | `missions-progression` / mission dialog chrome |
| Date | 2026-08-04 (WQ7R-C) |

## Machine-level notes

- Live Ghidra decompile ≡ scaffold raw (WQ7R-C re-verify).
- Body `0x008aab00`–`0x008aaf58` exclusive (**1112 B** / `0x458`); `__chkstk` frame `0x204c`.
- **ABI:** ECX = markup C-string; stack arg = richtext widget* (`ADD ESP,4` at all 6 call sites). Decompiler `__thiscall` label is misleading — ECX is **not** a C++ this for a class method of the widget.
- Null-check both args; early return if either null.
- Copies source into local 4 KiB working buffer (`local_1000` / decompiler split), then scans for `[$…]` tags.
- Role: mission/dialog **rich-text markup → widget paint** helper (colors, pause, keybind names). Not a wire handler.

## Param / local renames

| Raw | Meaning | Evidence |
|---|---|---|
| `param_1` / ECX / ESI | markup source C-string | callers LEA/MOV ECX to string; `mov esi,ecx` |
| `param_2` / stack / EBP | richtext UI widget* | vtbl calls +0x230/+0x23c/+0x250/+0x254; callers push widget |
| `local_2000` | append-run text buffer (4 KiB) | flushed via +0x250 |
| `local_2040` | sprintf staging for key display (64) | `"%s"` / `"<%s>"` |
| `local_204c` | run length cursor | reset on tag flush |
| `iVar7` | scan index into working copy | tag length advances |
| `DAT_00d1bbf5` | keybind name table (stride 0x34) | scan until `<0xd1d455` |
| `FUN_007a69d0` | locale/string-table ensure | shared bootstrap |
| `FUN_007a6de0` | localize C-string | `"Free Look"`, table entries |
| `FUN_007f5120` | Free Look key display string | only Free Look match arm |
| `FUN_007f9160` | key index → display ready? | `(index, 0)` |

## Markup matrix

| Open | Close | Color / action |
|---|---|---|
| `[$imp]` | `[$/imp]` | SetColor `0xFFFF2D00` / PopColor |
| `[$npc]` | `[$/npc]` | SetColor `0xFF256EC8` / PopColor |
| `[$inst]` | `[$/inst]` | SetColor `0xFFC5C025` / PopColor |
| `[$loc]` | `[$/loc]` | SetColor `0xFFF59623` / PopColor |
| `[$emote]` | `[$/emote]` | SetColor `0xFF29B525` / PopColor |
| `[$pause]` | — | Pause `0x14` |
| `[$key]` | `[$/key]` | keybind resolve → AppendText |

Unknown `[$` start: treat first char as plain text (goto accumulate).

## Pseudocode (annotated)

```c
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

// ECX = markupSrc; stack = richtextWidget*
void MissionDialog_ParseMarkupToRichText_Inferred(char *markupSrc, int *richtextWidget)
{
  // null-guard both
  // FUN_007a69d0(); locale ensure
  // strcpy working[4096] <- markupSrc
  // scan:
  //   if "[$" tag: flush run via widget->vtbl[0x250]
  //     match open/close color tags, pause, key
  //   else: accumulate plain char into run
  // final flush if run non-empty
}
```

See raw capture for full decompiler body (authoritative).

## Open questions

- Product English / PDB name for this helper.
- Exact product names of vtbl +0x230/+0x23c/+0x250/+0x254.
- Runtime contents of `DAT_00d1bbf5` key table.
- Whether `FUN_007f9160` writes into `local_2040` or a side buffer (CF: non-zero skips sprintf).
