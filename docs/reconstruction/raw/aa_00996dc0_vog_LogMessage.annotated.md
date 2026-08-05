# Annotated low-level: vog_LogMessage

| Field | Value |
|---|---|
| Stable ID | `aa_00996dc0` |
| VA | `0x00996dc0` |
| Body | `0x00996dc0`–`0x00996e32` |
| System | `diagnostics` |
| Date | `2026-07-29` (three-rep refresh + dual A/B) |

## Machine-level notes

- Source: raw capture + 2026-07-29 `read_memory` re-seal for `aa_00996dc0`.
- Prefer machine when decompiler drops the **EDI = severity** handoff.
- Non-fatal logging is **not** in this wrapper; it lives in `FUN_0076d1b0` (not owned).
- Call-site paths under `C:\vog\1_code\...` are the primary RE naming ore.

## Pseudocode (annotated)

```c
/* vog_LogMessage — thin fatal-gate wrapper around errReport dispatcher.
   Formals (cdecl stack): sourceFile, line, severity, message.
   Custom handoff: severity also in EDI for FUN_0076d1b0. */

void vog_LogMessage(
    undefined4 sourceFile,   /* param_1 — const char* */
    undefined4 line,         /* param_2 — int */
    undefined4 severity,     /* param_3 — int; also EDI → sink */
    undefined4 message)      /* param_4 — const char* detail (not va_list here) */

{
  int status;
  FILE *crashFile;
  
  /* Machine: mov edi, severity; push message; push line; push sourceFile */
  status = FUN_0076d1b0(sourceFile, line, message);  /* severity via EDI */
  if (status == 3) {
    crashFile = fopen("c:\\VOGCRASH.txt", "w");
    if (crashFile != (FILE *)0x0) {
      fprintf(crashFile,
              "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",
              sourceFile, line, severity, message);
      fclose(crashFile);
    }
    raise(0x16);           /* SIGABRT */
    /* WARNING: Subroutine does not return */
    ExitProcess(3);
  }
  return;
}
```

## Open questions

- Full `FUN_0076d1b0` return-code policy and handler table `@ 0x00afa2c0` (sibling).
- Severity enum labels beyond integer used as table index / fprintf field.
- Confirm no alternate entry that truly consumes varargs into this VA (machine: none).
