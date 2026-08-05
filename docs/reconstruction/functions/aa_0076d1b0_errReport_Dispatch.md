# Function record: errReport_Dispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076d1b0` |
| **Canonical name** | `errReport_Dispatch` (INFERRED) |
| **Address** | `0x0076d1b0` |
| **Body** | `0x0076d1b0`–`0x0076d245` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | diagnostics / errReport |
| **Completion status** | **Dual A/B sealed** — 2026-07-29 W17-F |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_0076d1b0`
- Legacy scaffold: `Named_CalleeOf_Named_gfxView_0076d1b0`
- Sibling wrapper: `vog_LogMessage` @ `0x00996dc0` (dual sealed)
- Prefer **`errReport_Dispatch`** paths for dual seal

## Purpose

errReport **severity dispatcher**:

1. Label severity via table `@ 0x00afa2c0` (`DEBUG`…`FATAL`).
2. Default sink (`FUN_0076d020`) when manager flag `+8 == 0`.
3. Else max-vote across registered handlers (threshold-filtered).
4. Force return **3** when severity **> 4** and no strong handler vote (`>=2`).
5. `vog_LogMessage` treats **3** as process abort (`VOGCRASH.txt` / `SIGABRT` / `ExitProcess(3)`).

## Signature (machine-sealed)

```c
// cdecl; severity in EDI; plain ret
int errReport_Dispatch(const char* sourceFile, int line, const char* message);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0076d1b0_FUN_0076d1b0.md`
- Annotated: `docs/reconstruction/raw/aa_0076d1b0_FUN_0076d1b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/errReport_Dispatch.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0076d1b0_errReport_Dispatch.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0076d1b0_errReport_Dispatch.md`
- Legacy clean: `docs/reconstruction/reconstructed-exact/FUN_0076d1b0.cpp` (superseded)

## Callers / callees

| Direction | Notes |
|---|---|
| Callers | `vog_LogMessage`, graphics/error paths (`FUN_0072cee0`, `FUN_00759de0`, `FUN_00967150`, …); coverage ~44 xrefs |
| Callees | `FUN_0076d140` (mgr singleton), `FUN_0076d020` (default sink), handler `vtbl+4` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + return policy | **High** (machine) |
| 3 stack args + EDI severity | **High** |
| Severity label table | **High** (`read_memory` strings) |
| Handler 5-arg shape | **High** (push order) |
| Product type names for handlers | **Tentative** |
| Return-2 semantic | **Open** |
