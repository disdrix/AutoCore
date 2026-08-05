# Function record: OleDb_CommandExecuteIRowset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421aa0` |
| **Canonical name** | `OleDb_CommandExecuteIRowset_Inferred` |
| **Address** | `0x00421aa0` |
| **Body** | `0x00421aa0`–`0x00421b4f` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / OLE DB command execute |
| **Completion status** | **Dual A/B complete** (2026-07-29 W18-D) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_00421aa0` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_bActiveObj_00421aa0` |

## Purpose

Optional `ICommandProperties::SetProperties` when EBX (property-set pointer) is non-null, then `ICommand::Execute` requesting **IID_IRowset** into `*ppRowset` (caller passes `&ctx->+0x10`). On success, if `*(ctx+0x10)` non-null, QI for **IID_IRowsetChange** into `ctx+0x14` (HRESULT ignored).

## Signature (byte-recovered)

```c
// EAX = ctx; EBX = rgPropertySets (nullable)
// __stdcall, 4 stack args, ret 0x10
HRESULT OleDb_CommandExecuteIRowset_Inferred(
    void **ppRowset,         // typically &ctx->field_0x10
    void *pParams,           // optional DBPARAMS-like
    void *pcRowsAffected,    // null → stack scratch
    int cPropertySets);      // 0 → 1 when props path runs
```

## IID seal

| DAT | GUID | Interface |
|---|---|---|
| `00a860e8` | `{0C733A79-2A1C-11CE-ADE5-00AA0044773D}` | IID_ICommandProperties |
| `00a8608c` | `{0C733A7C-2A1C-11CE-ADE5-00AA0044773D}` | IID_IRowset |
| `00a860f8` | `{0C733A05-2A1C-11CE-ADE5-00AA0044773D}` | IID_IRowsetChange |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00421aa0_FUN_00421aa0.md`
- Annotated: `docs/reconstruction/raw/aa_00421aa0_FUN_00421aa0.annotated.md`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00421aa0.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/OleDb_CommandExecuteIRowset_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00421aa0_OleDb_CommandExecuteIRowset_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00421aa0_OleDb_CommandExecuteIRowset_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00421aa0_FUN_00421aa0.md`

## Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller (sole) | `FUN_0041de50` Com_BindContinuation_Inferred | post-QI bind execute |
| Callee | `FUN_00437cd0` ComPtr_ClearSlot | zero out slot |
| Callee | `FUN_0041d7b0` ComPtr_ReleaseIfNonNull | Release QI iface |
| Callee | vtbl[0] / vtbl+0x10 | QI / SetProperties / Execute |

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile + bytes | High |
| IID product identities | Confirmed (GUID catalog) |
| SetProperties on QI iface not param_1 | High (bytes) |
| Execute = ICommand slot +0x10 | High |
| Canonical name product-final | Inferred / structural |
| Dual review | Present |
