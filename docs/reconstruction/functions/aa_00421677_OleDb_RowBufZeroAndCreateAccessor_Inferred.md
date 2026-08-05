# Function record: OleDb_RowBufZeroAndCreateAccessor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421677` |
| **Canonical name** | `OleDb_RowBufZeroAndCreateAccessor_Inferred` |
| **Ghidra name** | `FUN_00421677` |
| **Address** | `0x00421677`–`0x00421732` (**187 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / OLE DB accessor finalize |
| **Completion status** | **Dual A/B sealed** (W22-N 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Zero-fill parent-allocated OLE DB row buffer, invoke CreateAccessor+free-bindings helper, clean temps / SEH / COM, return HRESULT. Null row buffer returns **E_OUTOFMEMORY** (`0x8007000E`).

## Signature (decompiler + bytes)

```c
// Ghidra surface (split fragment):
int FUN_00421677(void);  // unaff_EBX = ctx*, unaff_EBP = parent frame

// Byte epilogue:
//   ret 4  => 1 stack formal (ctx*) when entered via stdcall prologue
// Pre-entry @ 0x00421674: mov ebx, [ebp+8]
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00421677_FUN_00421677.md` (+ W22-N append)
- Annotated: `docs/reconstruction/raw/aa_00421677_FUN_00421677.annotated.md`
- Clean (named): `docs/reconstruction/reconstructed-exact/OleDb_RowBufZeroAndCreateAccessor_Inferred.cpp`
- Clean (scaffold): `docs/reconstruction/reconstructed-exact/FUN_00421677.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00421677_OleDb_RowBufZeroAndCreateAccessor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00421677_OleDb_RowBufZeroAndCreateAccessor_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00421677_FUN_00421677.md`

## Callers / callees

| Role | Name | VA |
|---|---|---|
| Caller | `FUN_0042139b` | `0x0042139b` |
| Callee | `OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred` | `0x00422830` |
| Callee | `operator_delete[]` | CRT |

## Confidence

| Claim | Level |
|---|---|
| Control flow + E_OUTOFMEMORY + zero-fill + ret 4 | **High** |
| CreateAccessor callee identity (`aa_00422830`) | **High** |
| Parameter product English names | **Probable / Tentative** |
| Types for ctx / iface | **Tentative** |
| Runtime / bit-exact | **Open** |
