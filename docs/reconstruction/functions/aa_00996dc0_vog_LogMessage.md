# Function record: vog_LogMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_00996dc0` |
| **Canonical name** | `vog_LogMessage` |
| **Address** | `0x00996dc0` |
| **Body** | `0x00996dc0`–`0x00996e32` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `diagnostics` / errReport logging sink |
| **Completion status** | **Dual A/B sealed (wrapper)** — three-rep refreshed 2026-07-29; dispatcher residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Thin engine-wide log/assert entry: hand off to `FUN_0076d1b0` with source path, line, message (stack) and severity (**EDI**). If dispatcher returns **3**, write `c:\VOGCRASH.txt` (`errReport::Massive failure EH_Abort…`), `raise(0x16)`, `ExitProcess(3)`. Otherwise return. Call sites carry original `C:\vog\1_code\...` paths used for RE name recovery.

## Signature (machine-sealed)

```c
// cdecl — 4 stack formals; plain ret
// Severity is also placed in EDI for FUN_0076d1b0 (custom callee ABI).
void vog_LogMessage(
    const char* sourceFile,
    int         line,
    int         severity,
    const char* message);
```

**Note:** Plate historically said `fmt, ...`. **This body has no varargs handling.** Sealed call sites pass a finished detail string.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00996dc0_vog_LogMessage.md`
- Annotated: `docs/reconstruction/raw/aa_00996dc0_vog_LogMessage.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/vog_LogMessage.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00996dc0_vog_LogMessage.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00996dc0_vog_LogMessage.md`

## Callers / callees

| Direction | Notes |
|---|---|
| Callers | ~765 xrefs (coverage inventory); graphics, clone, error-handler, physics, etc. |
| Callees | `FUN_0076d1b0` @ `0x0076d1b0`; CRT `fopen`/`fprintf`/`fclose`/`raise`; Win32 `ExitProcess` |

## Confidence

| Claim | Level |
|---|---|
| Control flow (this unit) | **High** |
| cdecl 4-arg ABI + fatal gate on return 3 | **High** |
| Severity → EDI for dispatcher | **High** |
| Parameter semantic names | **High** (strings + call sites) |
| Varargs at this entry | **Falsified for this body** |
| `FUN_0076d1b0` policy | **Open** (not owned) |
