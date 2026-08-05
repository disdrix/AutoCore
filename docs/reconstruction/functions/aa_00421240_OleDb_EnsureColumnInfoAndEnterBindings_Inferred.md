# Function record: OleDb_EnsureColumnInfoAndEnterBindings_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421240` |
| **Canonical name** | `OleDb_EnsureColumnInfoAndEnterBindings_Inferred` |
| **Ghidra name** | `FUN_00421240` |
| **Address** | `0x00421240`–`0x00421358` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / OLE DB accessor setup |
| **Classification** | worker (SEH parent; tail-jmp into binding-build fragments) |
| **Completion status** | **Sealed** — dual A/B W25-C 2026-07-29; **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept-with-gaps** |

## Alias

- Ghidra: `FUN_00421240`
- Chain children: `aa_00421362` AllocBindingsBuf, `aa_0042139b` BuildBindingsAllocRow, `aa_00421677` RowBufZeroAndCreateAccessor

## Purpose

OLE DB accessor **setup parent**: QI **IAccessor** on source; ensure column metadata (pre-supplied `ctx+0x14` **or** `IColumnsInfo::GetColumnInfo`); allocate temporary **`DBBINDING[colCount]`** (`colCount * 0x34`); **jmp** into sealed `OleDb_AllocBindingsBuf_EnterBuild_Inferred`.

## Signature (sealed)

```c
HRESULT __thiscall OleDb_EnsureColumnInfoAndEnterBindings_Inferred(
    IUnknown *source,   // ECX
    OleDbAccessorBuildCtx *ctx);  // stack; ret 4 on fail
// success: jmp 0x00421362 (shared SEH frame)
```

## Ctx layout (this unit)

| Off | Role | Confidence |
|---:|---|---|
| `+0x0C` | colCount | **High** |
| `+0x14` | column-info array* | **High** |
| `+0x18` | GetColumnInfo strings* | **High** |
| `+0x1C` | byte: 1=pre-supplied cols, 0=from GetColumnInfo | **High** |

## IIDs

| DAT | GUID | Interface |
|---|---|---|
| `00a860ac` | `{0C733A8C-2A1C-11CE-ADE5-00AA0044773D}` | IAccessor |
| `00a85ffc` | `{0C733A11-2A1C-11CE-ADE5-00AA0044773D}` | IColumnsInfo |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00421240_FUN_00421240.md` (+ W25-C append)
- Annotated: `docs/reconstruction/raw/aa_00421240_FUN_00421240.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/OleDb_EnsureColumnInfoAndEnterBindings_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00421240.cpp`
- Dual A/B: `reviews/A_aa_00421240_OleDb_EnsureColumnInfoAndEnterBindings_Inferred.md`, `reviews/B_aa_00421240_OleDb_EnsureColumnInfoAndEnterBindings_Inferred.md`
- Report: `docs/agents/task-dual-ab-004bcbf0-00421240-w25c-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `operator_new[]`; tail-join `FUN_00421362`; COM QI/Release |
| **Callers** | Ghidra **0** direct xrefs — gap (indirect / untyped residual) |

## Confidence

| Claim | Level |
|---|---|
| QI IAccessor + optional GetColumnInfo CF | **High** |
| IID GUID identity | **High** |
| `colCount * 0x34` temp DBBINDING alloc | **High** |
| Success **jmp** into `00421362` | **High** |
| ctx `+0x0C/+0x14/+0x18/+0x1C` roles | **High** |
| Product/PDB English | Open / Inferred |
| Direct call-site catalog | **Open** (0 Ghidra xrefs) |
| Runtime / bit-exact | Open |
