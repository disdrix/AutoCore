# Function record: FUN_008aab00

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aab00` |
| **Canonical name** | `FUN_008aab00` |
| **Preferred name** | `MissionDialog_ParseMarkupToRichText_Inferred` |
| **Address** | `0x008aab00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / mission dialog chrome |
| **Completion status** | **Dual A/B sealed** (WQ7R-C 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Alias

- Preferred: `MissionDialog_ParseMarkupToRichText_Inferred`
- Reject product: `Named_npc`, `Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_008aab00`

## Purpose

Parse mission/dialog markup C-string into richtext widget paint (color tags, pause, keybind labels, plain runs). See named function record for full seal.

## Signature (decompiler-derived / sealed)

```c
// ECX = markupSrc; stack = richtextWidget*
void FUN_008aab00(char *param_1, int *param_2);
```

Body: `0x008aab00`–`0x008aaf58` exclusive (**1112 B**).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008aab00_FUN_008aab00.md`
- Annotated: `docs/reconstruction/raw/aa_008aab00_FUN_008aab00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_008aab00.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/MissionDialog_ParseMarkupToRichText_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_008aab00_MissionDialog_ParseMarkupToRichText_Inferred.md`
- Reviews: `A|B_aa_008aab00_MissionDialog_ParseMarkupToRichText_Inferred.md`

## Callers / callees

Callers (6): `FUN_008aaf60`, `FUN_008a3510` (×2), `FUN_008cc5a0`, `FUN_008cdae0`, `FUN_008dbe10`.  
Callees: `FUN_007a69d0`, `__chkstk`, `FUN_007a6de0`, `FUN_007f5120`, `FUN_007f9160`, `_strnicmp`, `_stricmp`, `sprintf`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Markup matrix + colors | High |
| Parameter semantic names | High (call sites) |
| Product English | Open |
