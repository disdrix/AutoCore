# Function record: Client_DebugListMissionsStatus

| Field | Value |
|---|---|
| **Stable ID** | `aa_009572e0` |
| **Canonical name** | `Client_DebugListMissionsStatus` |
| **Address** | `0x009572e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_009572e0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_DebugListMissionsStatus`

## Purpose

DEBUG list: missions still to complete and currently active.

## String evidence

`"Missions Still To Complete" / "Missions Currently Active"`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ Client_DebugListMissionsStatus(uint32_t /* width from decompiler */ param_1,char *param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009572e0_FUN_009572e0.md`
- Annotated: `docs/reconstruction/raw/aa_009572e0_FUN_009572e0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_DebugListMissionsStatus.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_009572e0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
