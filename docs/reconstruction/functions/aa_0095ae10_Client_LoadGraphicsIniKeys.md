# Function record: Client_LoadGraphicsIniKeys

| Field | Value |
|---|---|
| **Stable ID** | `aa_0095ae10` |
| **Canonical name** | `Client_LoadGraphicsIniKeys` |
| **Address** | `0x0095ae10` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0095ae10`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_LoadGraphicsIniKeys`

## Purpose

Loads large graphics/UI INI key table including SET_NEW_MISSION_ACTIVE and FULL_QUICKBAR_RED.

## String evidence

`"SET_NEW_MISSION_ACTIVE" / "FULL_QUICKBAR_RED" / CINCAM_* keys`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ Client_LoadGraphicsIniKeys(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0095ae10_FUN_0095ae10.md`
- Annotated: `docs/reconstruction/raw/aa_0095ae10_FUN_0095ae10.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_LoadGraphicsIniKeys.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0095ae10.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
