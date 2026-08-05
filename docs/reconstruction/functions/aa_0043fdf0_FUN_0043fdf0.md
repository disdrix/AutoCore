# Function record: FUN_0043fdf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043fdf0` |
| **Canonical name** | `NestedHash_Ctor_Sentinel0xC_Inferred` (Ghidra `FUN_0043fdf0`) |
| **Address** | `0x0043fdf0`–`0x0043fe51` (**98 B** / `0x62`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared nested hash/map shell |
| **Wave** | W34-F OWN-ONLY dual 2026-07-29 |
| **Completion status** | **accept-with-gaps** — ABI/layout/sentinel+buckets/flags + 3 callers sealed; product English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Canonical: `NestedHash_Ctor_Sentinel0xC_Inferred`
- Ghidra: `FUN_0043fdf0`
- **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Incompatible_0043fdf0`

## Purpose

Placement constructor for a **0x28** nested hash/map shell: circular sentinel node (**0x0C** via `StdList_AllocSentinel_0xC`), size0, 9-bucket pointer table filled with that sentinel (`PtrVecShell_InitFill`), flags `+0x20/+0x24 = 1`.

## Signature (bytes-sealed)

```c
// stdcall 1 formal; RET 4; returns self in EAX
// decompiler: int FUN_0043fdf0(int param_1)
NestedHash_Sentinel0xC* NestedHash_Ctor_Sentinel0xC_Inferred(NestedHash_Sentinel0xC* self /*stack*/);
```

## Callers / callees

| Role | Target | Notes |
|---|---|---|
| Caller | `FUN_0074e380` @ `0x0074e3ba` | outer 0x40; nested at +0x14 |
| Caller | `FUN_0096eec0` @ `0x0096eeea` | shell at object base |
| Caller | `FUN_00996bc0` @ `0x00996c02` | nested at +0x28 |
| Callee | `FUN_004933f0` | `StdList_AllocSentinel_0xC_Inferred` (W32-P) |
| Callee | `FUN_004646e0` | `PtrVecShell_InitFill_Inferred` (W33-B); count **9** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0043fdf0_FUN_0043fdf0.md`
- Annotated: `docs/reconstruction/raw/aa_0043fdf0_FUN_0043fdf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NestedHash_Ctor_Sentinel0xC_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0043fdf0.cpp`
- Named record: `docs/reconstruction/functions/aa_0043fdf0_NestedHash_Ctor_Sentinel0xC_Inferred.md`
- Review A: `docs/reconstruction/reviews/A_aa_0043fdf0_NestedHash_Ctor_Sentinel0xC_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0043fdf0_NestedHash_Ctor_Sentinel0xC_Inferred.md`
- Agent report: `docs/agents/task-dual-ab-00463bd0-0043fdf0-w34f-report.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| Stack this + RET 4 + return self | **High** |
| Layout +8 / +0xc / +0x10 / +0x20 / +0x24 | **High** |
| Sentinel node size 0x0C | **High** (W32-P sealed) |
| Product class English | **Low** (Inferred only) |
| Flag semantics | **Med** |
