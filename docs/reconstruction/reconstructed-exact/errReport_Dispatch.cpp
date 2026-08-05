// =============================================================================
// errReport_Dispatch
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d1b0
// Address:   0x0076d1b0  (autoassault.exe, image base 0x400000)
// Body:      0x0076d1b0 – 0x0076d245
// System:    diagnostics / errReport
// Generated: 2026-07-23 scaffold; 2026-07-29 dual A/B machine re-seal (W17-F)
// Exactness: Behavior-preserving rewrite of decompiler + machine control flow.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Real non-fatal logging sink behind vog_LogMessage (aa_00996dc0).
 * - Retail ABI: cdecl, 3 stack formals + severity in EDI; plain ret (C3).
 *   Portable signature below lifts EDI into an explicit parameter for readability.
 * - Severity label = *(const char**)(0x00afa2c0 + severity*4):
 *     0 DEBUG, 1 INFO, 2 WARNING, 3 ERROR, 4 ASSERTION FAILED, 5 FATAL.
 * - Manager singleton FUN_0076d140() → &DAT_00d1f888.
 * - mgr+8==0: default FUN_0076d020(line, severity, label, message) with ESI=sourceFile.
 * - else: reverse-walk circular handler list at mgr+4; max of handler vtbl+4 votes
 *   when handler.threshold <= severity; handler args =
 *   (sourceFile, line, severity, label, message).
 * - Return policy:
 *     if maxVote >= 2: return maxVote
 *     else if severity > 4: return 3   // FATAL+ abort gate
 *     else return maxVote
 * - vog_LogMessage aborts only on return == 3.
 *
 * Decomp defects fixed vs raw FUN_0076d1b0:
 * - arity 3+EDI (not 2); 5-arg handler call; ESI sourceFile into default sink.
 */

// Light-touch callees (not owned by this dual):
//   FUN_0076d140 — get errReport manager singleton
//   FUN_0076d020 — default console/ODS formatter/sink
//   (FUN_0076d020 also consumes ESI = sourceFile — custom register ABI)

extern "C" void* FUN_0076d140(void);
extern "C" int   FUN_0076d020(int line, int severity, const char* label, const char* message);

// Table @ 0x00afa2c0 — six severity label pointers (read_memory sealed).
// Indices: 0 DEBUG, 1 INFO, 2 WARNING, 3 ERROR, 4 ASSERTION FAILED, 5 FATAL.
#define ERRREPORT_SEVERITY_LABEL_TABLE ((const char* const*)0x00afa2c0)

// Portable form (severity explicit). Retail call sites place severity in EDI and
// pass only (sourceFile, line, message) on the stack.
int errReport_Dispatch(const char* sourceFile, int line, int severity, const char* message)
{
  const char* severityLabel;
  int maxVote;
  void* mgr;
  void* listHead;
  void* endNode;
  void* cur;
  void* prevNode;
  void* handler;
  void** handlerVtbl;
  int (*handlerReport)(const char*, int, int, const char*, const char*);
  int vote;

  severityLabel = ERRREPORT_SEVERITY_LABEL_TABLE[severity];
  maxVote = 0;
  mgr = FUN_0076d140();

  if (*(int*)((unsigned char*)mgr + 8) == 0) {
    /* Machine: mov esi, sourceFile; then push message,label,severity,line */
    maxVote = FUN_0076d020(line, severity, severityLabel, message);
  } else {
    listHead = *(void**)((unsigned char*)mgr + 4);
    endNode = *(void**)listHead; /* sentinel->_Next */
    cur = listHead;              /* start at sentinel; walk _Prev */

    if (cur != endNode) {
      do {
        prevNode = *(void**)((unsigned char*)cur + 4);
        handler = *(void**)((unsigned char*)prevNode + 8);
        /* Machine: cmp edi, [handler+4]; jl skip  ⇒ require severity >= threshold */
        if (severity >= *(int*)((unsigned char*)handler + 4)) {
          handlerVtbl = *(void***)handler;
          handlerReport = (int (*)(const char*, int, int, const char*, const char*))handlerVtbl[1];
          /* vtbl+4 == index 1: cdecl (sourceFile, line, severity, label, message) */
          vote = handlerReport(sourceFile, line, severity, severityLabel, message);
          if (maxVote < vote) {
            maxVote = vote;
          }
        }
        cur = *(void**)((unsigned char*)cur + 4);
      } while (cur != endNode);
    }
  }

  if (maxVote >= 2) {
    return maxVote;
  }
  if (severity > 4) {
    return 3; /* FATAL+ */
  }
  return maxVote;
}

/*
 * Retail entry shape (matches vog_LogMessage handoff):
 *
 *   ; EDI = severity
 *   push message
 *   push line
 *   push sourceFile
 *   call errReport_Dispatch_Retail  ; only 3 stack args
 *   add  esp, 0xC
 *
 * int errReport_Dispatch_Retail(const char* sourceFile, int line, const char* message);
 * // severity = EDI
 */
