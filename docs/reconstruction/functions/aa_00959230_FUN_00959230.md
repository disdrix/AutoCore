# Function record: Client_RegisterDebugSlashCommands

| Field | Value |
|---|---|
| **Stable ID** | `aa_00959230` |
| **Canonical name** | `Client_RegisterDebugSlashCommands` |
| **Address** | `0x00959230` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00959230`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_RegisterDebugSlashCommands`

## Purpose

Registers client debug slash commands (castskill, debugmissions, quickbar, etc.).

## String evidence

`"debugmissions" / "debugcompleteobjective" / "castskill" / "quickbar"`

## Signature (decompiler-derived)

```c
void Client_RegisterDebugSlashCommands(void)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00959230_FUN_00959230.md`
- Annotated: `docs/reconstruction/raw/aa_00959230_FUN_00959230.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_RegisterDebugSlashCommands.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00959230.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
