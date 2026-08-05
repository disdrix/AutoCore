# Function record: Client_DebugDumpMissionsAndObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_00954670` |
| **Canonical name** | `Client_DebugDumpMissionsAndObjectives` |
| **Address** | `0x00954670` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00954670`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_DebugDumpMissionsAndObjectives`

## Purpose

DEBUG dump of missions/objectives and instanced completed missions.

## String evidence

`"Mission(%d)(%S) Objective(%d)(%d)(%S)" / "Instanced Completed Missions:"`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ __thiscall Client_DebugDumpMissionsAndObjectives(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00954670_FUN_00954670.md`
- Annotated: `docs/reconstruction/raw/aa_00954670_FUN_00954670.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_DebugDumpMissionsAndObjectives.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00954670.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
