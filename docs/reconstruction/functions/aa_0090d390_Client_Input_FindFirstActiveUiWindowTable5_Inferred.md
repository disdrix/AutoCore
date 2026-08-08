# Function record: Client_Input_FindFirstActiveUiWindowTable5_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090d390` |
| **Canonical name** | `Client_Input_FindFirstActiveUiWindowTable5_Inferred` |
| **Ghidra name** | `FUN_0090d390` |
| **Address** | `0x0090d390`–`0x0090d3c4` inclusive (**53 B** / `0x35`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` |
| **Dual** | MEGA-096 OWN-ONLY 2026-08-05 |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

## Purpose

Scan `DAT_00d09a38[5]` (exclusive end `0x00d09a4c`) for the first non-null UI window* whose `vtbl+0x3d8` returns non-zero. Return that pointer, else NULL.

Primary chain (ESC cancel):

```text
Client_Input_OnKeyDown_MatchAction
  ESC + client.vtbl+0x3d8 + flag+0x50d clear
    → Client_Input_FindFirstActiveUiWindowTable5_Inferred  [OWN]
    → if nonzero: Client_Input_DismissUiWindowTable5_Inferred (0x0090dab0)
```

## Signature

```c
// no stack args; plain RET (C3); EAX = window* or 0
void* Client_Input_FindFirstActiveUiWindowTable5_Inferred(void);
```

## Evidence summary

| Fact | Source |
|---|---|
| Body 53 B / both exits `C3` | `read_memory` + `disassemble_function` |
| Table 5 dwords / index CMP 5 | disasm `CMP ESI,5` + sibling end `0xd09a4c` |
| Active gate `vtbl+0x3d8` | `CALL [EAX+0x3d8]` + `TEST AL` |
| 2 call sites | xrefs `0091106a`, `0092cf32` |
| Decompile ≡ raw CF | live re-verify MEGA-096 |

## Gaps

- Product English for the five UI window classes (init sizes per MEGA-097).
- Product name of `vtbl+0x3d8` / `vtbl+0x94` methods.
- Runtime Confirmed / bit-exact / differential.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0090d390_FUN_0090d390.md` |
| Annotated | `docs/reconstruction/raw/aa_0090d390_FUN_0090d390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_FindFirstActiveUiWindowTable5_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0090d390.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0090d390_FUN_0090d390.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0090d390_Client_Input_FindFirstActiveUiWindowTable5_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0090d390_Client_Input_FindFirstActiveUiWindowTable5_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0090d390-mega-096-report.md` |
