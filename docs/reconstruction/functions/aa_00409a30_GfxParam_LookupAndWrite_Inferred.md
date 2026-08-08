# Function record: GfxParam_LookupAndWrite_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409a30` |
| **Canonical name** | `GfxParam_LookupAndWrite_Inferred` |
| **Ghidra symbol** | `FUN_00409a30` |
| **Address** | `0x00409a30` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics parameter service |
| **Completion status** | **Dual sealed** WQ9J-J 2026-08-05 — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |

## Purpose

Host-relative graphics parameter write: `service = host[+4]+0xc` → handle via vtbl+0x24(name) → write via vtbl+0x50(handle, data, -1). Primary callers push fog center float3 under name `"gWorldFogCenter"`.

## Signature

```c
// EAX host, EDX name, stack data; RET 4
void GfxParam_LookupAndWrite_Inferred(void *host, const char *name, void *data);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00409a30_FUN_00409a30.md`
- Annotated: `docs/reconstruction/raw/aa_00409a30_FUN_00409a30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GfxParam_LookupAndWrite_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00409a30.cpp`
- FUN record: `docs/reconstruction/functions/aa_00409a30_FUN_00409a30.md`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00409a30_GfxParam_LookupAndWrite_Inferred.md`, `B_aa_00409a30_GfxParam_LookupAndWrite_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI | **High** |
| Naming `_Inferred` | Inferred (string evidence is call-site name arg, not product symbol) |
| Runtime | Open |
