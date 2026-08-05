# Function record: Client_UpdateObjectiveDisplayHud

| Field | Value |
|---|---|
| **Stable ID** | `aa_008066f0` |
| **Canonical name** | `Client_UpdateObjectiveDisplayHud` |
| **Address** | `0x008066f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_008066f0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_UpdateObjectiveDisplayHud`

## Purpose

Refreshes objective HUD strings (level/money/objective display labels).

## String evidence

`"Objective Display"`

## Signature (decompiler-derived)

```c
void __fastcall Client_UpdateObjectiveDisplayHud(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008066f0_FUN_008066f0.md`
- Annotated: `docs/reconstruction/raw/aa_008066f0_FUN_008066f0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_UpdateObjectiveDisplayHud.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_008066f0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
