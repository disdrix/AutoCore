# Function record: OleDb_BuildBindingsAllocRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042139b` |
| **Canonical name** | `OleDb_BuildBindingsAllocRow_Inferred` |
| **Ghidra name** | `FUN_0042139b` |
| **Address** | `0x0042139b`–`0x0042166d` (**722 B** Ghidra span) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / OLE DB binding build + row alloc |
| **Completion status** | **Dual A/B sealed** (W23-C 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Build per-column OLE DB-style bindings from column metadata, accumulate row byte size, allocate the row buffer at `ctx+0x08`, then continue into `OleDb_RowBufZeroAndCreateAccessor_Inferred` (`FUN_00421677`) for zero-fill + CreateAccessor. Null `ctx+0x10` returns **E_OUTOFMEMORY**.

## Signature (decompiler + bytes)

```c
// Ghidra surface (SEH-split fragment):
int FUN_0042139b(void);  // unaff_EBX = ctx*, unaff_EBP = parent frame

// Byte epilogue on fail paths:
//   ret 4  => 1 stack formal (ctx*)
// Pre-entry @ 0x00421390: mov ebx, [ebp+8]
// Success: jmp 0x00421674 → FUN_00421677 → ret 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0042139b_FUN_0042139b.md` (+ W23-C append)
- Annotated: `docs/reconstruction/raw/aa_0042139b_FUN_0042139b.annotated.md`
- Clean (named): `docs/reconstruction/reconstructed-exact/OleDb_BuildBindingsAllocRow_Inferred.cpp`
- Clean (scaffold): `docs/reconstruction/reconstructed-exact/FUN_0042139b.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0042139b_OleDb_BuildBindingsAllocRow_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0042139b_OleDb_BuildBindingsAllocRow_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0042139b_FUN_0042139b.md`

## Callers / callees

| Role | Name | VA |
|---|---|---|
| Caller | `FUN_00421362` | `0x00421362` |
| Callee | `FUN_00422900` | alignment helper |
| Callee | `FUN_00422880` | gate path when `*ctx==0` |
| Callee | `operator_new[]` / `operator_delete[]` | CRT |
| Continuation | `OleDb_RowBufZeroAndCreateAccessor_Inferred` | `0x00421677` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + E_OUTOFMEMORY + ret 4 + jmp-into-finalize | **High** |
| DBTYPE size-map cases + binding stride 0x34 / col side 0x30 | **High** |
| Role as OLE DB binding builder | **High** |
| Product type / formal English names | **Probable / Tentative** |
| Full binding field typedef | **Tentative** |
| Runtime / bit-exact | **Open** |
