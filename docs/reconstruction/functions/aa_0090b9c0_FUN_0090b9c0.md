# Function record: Client_SetAnnouncementLabelTextures

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090b9c0` |
| **Canonical name** | `Client_SetAnnouncementLabelTextures` |
| **Address** | `0x0090b9c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0090b9c0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_SetAnnouncementLabelTextures`

## Purpose

Sets announce-window label textures (mission/level/item/medal .dds).

## String evidence

`"i_d_announce_wnd_label_mission.dds" (+ level/item/medal)`

## Signature (decompiler-derived)

```c
void __fastcall Client_SetAnnouncementLabelTextures(int *param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0090b9c0_FUN_0090b9c0.md`
- Annotated: `docs/reconstruction/raw/aa_0090b9c0_FUN_0090b9c0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_SetAnnouncementLabelTextures.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0090b9c0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
