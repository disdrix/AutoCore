// =============================================================================
// vog_LogMessage
// -----------------------------------------------------------------------------
// Stable ID: aa_00996dc0
// Address:   0x00996dc0  (autoassault.exe, image base 0x400000)
// Body:      0x00996dc0 – 0x00996e32
// System:    diagnostics / errReport
// Generated: 2026-07-23 scaffold; 2026-07-29 dual A/B machine re-seal
// Exactness: Behavior-preserving rewrite of decompiler + machine control flow.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Thin wrapper: real non-fatal logging lives in FUN_0076d1b0 (0x0076d1b0).
 * - cdecl, 4 stack formals; plain ret (C3).
 * - Severity is loaded into EDI before calling the dispatcher (custom callee ABI;
 *   callee indexes a severity table via EDI). Decompiler call line omits EDI.
 * - status == 3 → c:\VOGCRASH.txt + raise(SIGABRT=0x16) + ExitProcess(3).
 * - This body has no va_list / varargs walk; call sites pass a finished message.
 * - Call-site source paths (C:\vog\1_code\...) recover original class/file names.
 */

// FUN_0076d1b0 — errReport dispatcher (not owned by this unit).
// Stack: (sourceFile, line, message); severity arrives in EDI.
extern "C" int FUN_0076d1b0(const char* sourceFile, int line, const char* message);

void vog_LogMessage(const char* sourceFile, int line, int severity, const char* message)
{
  int status;
  FILE* crashFile;

  // Machine sequence (abbrev):
  //   edi = severity;
  //   push message; push line; push sourceFile; call FUN_0076d1b0; add esp, 0xC
  status = FUN_0076d1b0(sourceFile, line, message); /* + EDI=severity */

  if (status == 3) {
    crashFile = fopen("c:\\VOGCRASH.txt", "w");
    if (crashFile != nullptr) {
      fprintf(crashFile,
              "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",
              sourceFile, line, severity, message);
      fclose(crashFile);
    }
    raise(0x16); /* SIGABRT */
    /* WARNING: Subroutine does not return */
    ExitProcess(3);
  }
  return;
}
