# Function record: Com_LoaderCtx_NestedTeardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041a8e0` |
| **Canonical name** | `Com_LoaderCtx_NestedTeardown_Inferred` |
| **Ghidra name** | `FUN_0041a8e0` |
| **Address** | `0x0041a8e0` |
| **Body range** | `0x0041a8e0`–`0x0041a988` (169 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `crt-com` / DB-WAD loader context nested teardown |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes sealed; product nested type open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0041a8e0_Com_LoaderCtx_NestedTeardown_Inferred.md`, `reviews/B_aa_0041a8e0_Com_LoaderCtx_NestedTeardown_Inferred.md` (2026-07-29 W22-M) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0041a8e0`
- Prior scaffold: `Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a8e0`
- Parent: `Com_LoaderCtx_Teardown_Inferred` (`0x0041a3e0`) nested arm

## Purpose

Nested teardown of a COM/DB loader context after the parent releases `*(ctx+0x24)`:

1. If `*(ctx+0x10)` non-null: `OleDb_ReleaseAccessorHandleArray` then `AdoRowsetHolder_Teardown`.
2. Always `AdoRowsetHolder_Teardown` on holder at `&ctx+0x10`.
3. Defensive `IUnknown::Release` on `*(ctx+0x14)` and `*(ctx+0x10)`.
4. If `*(ctx+0x0C)` non-null: `delete` nested `+0x0C` buffer, optional `free(*p)`, zero three dwords, `delete p`.

## Signature

```c
void __stdcall Com_LoaderCtx_NestedTeardown_Inferred(void *ctx);  /* ret 4 */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0041a8e0_FUN_0041a8e0.md`
- Annotated: `docs/reconstruction/raw/aa_0041a8e0_FUN_0041a8e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Com_LoaderCtx_NestedTeardown_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0041a8e0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0041a8e0_FUN_0041a8e0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0041a8e0-004220c0-w22m-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller | `0x0041a3e0` | `Com_LoaderCtx_Teardown_Inferred` @ `0x0041a428` |
| Caller | `0x009bd840` | SEH unwind |
| Callee | `0x00422de0` | `OleDb_ReleaseAccessorHandleArray_Inferred` |
| Callee | `0x0041bf70` | `AdoRowsetHolder_Teardown_Inferred` (×2) |
| Callee | vtbl+8 | `IUnknown::Release` |
| Callee | `0x00489822` | `operator_delete` (×2) |
| Callee | IAT `0x009c6524` | `free` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from bytes | **High** (decompile tail incomplete; bytes win) |
| `ret 4` stdcall | **Confirmed** |
| Offsets `+0x10`/`+0x14`/`+0x0C` | **High** |
| Product name of nested `+0x0C` object | Open / Tentative |
| Parameter semantic names | Probable (loader ctx from parent dual) |
