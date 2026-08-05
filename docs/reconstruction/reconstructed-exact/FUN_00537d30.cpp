// =============================================================================
// HashList_IntegrityWalkRepair_Inferred (FUN_00537d30)
// -----------------------------------------------------------------------------
// Stable ID: aa_00537d30
// Address:   0x00537d30  (autoassault.exe, image base 0x400000)
// System:    container / hash-list integrity
// Generated: 2026-07-29 dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Dual: reviews/A_aa_00537d30_* + B_aa_00537d30_*
// String:    "HashListError: Went to node we already touched! Attempting repair!" @ 0x00a64710
// =============================================================================

// FUN_007a4480(severity, fmt, ...) declared elsewhere.

void __fastcall FUN_00537d30(int list /* ECX */)
{
  int cur;
  int prev;

  cur = *(int *)(list + 4);
  if (*(int *)(list + 4) == 0) {
    return;
  }

  do {
    prev = cur;
    *(unsigned char *)(prev + 4) = 1;
    cur = *(int *)(prev + 0xc);
    if (cur == 0) {
      for (cur = *(int *)(list + 4); cur != 0; cur = *(int *)(cur + 0xc)) {
        *(unsigned char *)(cur + 4) = 0;
      }
      return;
    }
  } while (*(char *)(cur + 4) == '\0');

  FUN_007a4480(1, "HashListError: Went to node we already touched! Attempting repair!");
  *(unsigned int *)(prev + 0xc) = 0; // sever
  cur = *(int *)(list + 4);
  if (cur != 0) {
    do {
      *(unsigned char *)(cur + 4) = 0;
      cur = *(int *)(cur + 0xc);
    } while (cur != 0);
    return;
  }
  return;
}
