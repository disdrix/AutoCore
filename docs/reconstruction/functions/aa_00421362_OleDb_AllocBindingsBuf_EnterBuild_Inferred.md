# Function record: OleDb_AllocBindingsBuf_EnterBuild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421362` |
| **Canonical name** | `OleDb_AllocBindingsBuf_EnterBuild_Inferred` |
| **Ghidra name** | `FUN_00421362` |
| **Address** | `0x00421362` |
| **Body range** | `0x00421362`–`0x00421391` (Ghidra); success **jmp** `0x0042139b` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | COM / OLE DB accessor setup |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + alloc sealed; product English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00421362_OleDb_AllocBindingsBuf_EnterBuild_Inferred.md`, `reviews/B_aa_00421362_OleDb_AllocBindingsBuf_EnterBuild_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W24-F) |

## Alias

- `FUN_00421362` (Ghidra)
- Prior scaffold system `unknown`
- Parent-seed incomplete if present

## Purpose

SEH-split fragment after parent `FUN_00421240` allocates a temp binding-record buffer (`colCount * 0x34`). If that temp is null, fail with **E_OUTOFMEMORY** (Release COM iface, restore ExceptionList). Otherwise raise SEH try level to **4**, `operator_new[]` a `colCount`-sized buffer into **`ctx+0x10`**, and **jmp** into `OleDb_BuildBindingsAllocRow_Inferred` (`FUN_0042139b`) which builds DBBINDING records and continues to CreateAccessor finalize.

## Signature

```c
// Machine: shared parent EBP/SEH frame; EBX=ctx* (pre-entry mov ebx,[ebp+8])
// Success: jmp 0x0042139b (not call+ret). Fail: shared epilogue ret 4, EAX=HRESULT
// Ghidra surface: undefined4 FUN_00421362(void) with unaff_EBX / unaff_EBP
HRESULT OleDb_AllocBindingsBuf_EnterBuild_Inferred(/* shared frame */);
```

## Algorithm

1. SEH try level `[ebp-4] = 0`.
2. If temp bindings `[ebp-0x1c] == 0` → SEH=-1; optional COM Release on `[ebp-0x18]`; restore ExceptionList; return `0x8007000E`.
3. SEH try level = 4; `ctx[+0x10] = operator_new[](ctx[+0x0c])`.
4. **jmp** `FUN_0042139b` (build bindings + row alloc + finalize chain).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00421362_FUN_00421362.md`
- Annotated: `docs/reconstruction/raw/aa_00421362_FUN_00421362.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/OleDb_AllocBindingsBuf_EnterBuild_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00421362.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00421362-004d8a10-w24f-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Caller** | `FUN_00421240` @ `0x00421240` (1 xref) — OLE DB column-info / binding setup parent |
| **Callees** | CRT `operator_new[]`; tail-join `FUN_0042139b` (`aa_0042139b`) |

## Confidence

| Claim | Level |
|---|---|
| Null temp → E_OUTOFMEMORY cleanup | **High** |
| SEH levels 0 / 4 / −1 | **High** |
| `new[]([ebx+0xc])` → `[ebx+0x10]` | **High** |
| Success **jmp** into `0042139b` | **High** |
| Shared frame with build + finalize | **High** |
| Role as OLE DB binding setup gate | **High** (use); product type **Inferred** |
| Product/PDB symbol | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_0042139b` OleDb_BuildBindingsAllocRow_Inferred (continuation)
- `aa_00421677` OleDb_RowBufZeroAndCreateAccessor_Inferred (finalize)
- Parent `FUN_00421240` (QI + temp alloc of `colCount*0x34`)
