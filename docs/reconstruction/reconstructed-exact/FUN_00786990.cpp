// =============================================================================
// Profiler_Leave  (scaffold name: FUN_00786990)
// -----------------------------------------------------------------------------
// Stable ID: aa_00786990
// Address:   0x00786990  (autoassault.exe, image base 0x400000)
// System:    client instrumentation / profiler scope
// Generated: 2026-07-23 scaffold; strengthened 2026-07-29 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler + live assembly CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Pop one nested QPC profiler scope on the global manager (DAT_00afa27c).
//   Pair: Profiler_Enter FUN_00786a00 (push name, start timer, set current).
//   SearchAutoMissions / CleanupDragging / ServerCreateFromPacket call this as
//   profile leave only — not mission business logic.
//
// CALLING CONVENTION:
//   ECX = Profiler* manager; no stack formals; RET.
//
// READABILITY:
//   - Enable gate: manager+0x175
//   - Thread slots: manager+0x4c, stride 0xC, current @ +8
//   - Node: timer* @ +4, parent* @ +8, hierarchicalTotal @ +0x28
//   - FUN_00780690 requires ESI = timer block (asm-sealed; decompiler unaff_ESI)
//
// Dual: docs/reconstruction/reviews/A_aa_00786990_Profiler_Leave.md
//       docs/reconstruction/reviews/B_aa_00786990_Profiler_Leave.md
// =============================================================================

// External helpers (other units; names Probable / scaffold)
int  FUN_007866e0(void *profiler);           // ensure thread slot → index
void FUN_00780690(void);                     // ESI = timer*; QPC accumulate
// MSVC helper: 64-bit / 64-bit → 32-bit quotient in EAX (@ 0x006a3f00)
unsigned __alldiv(unsigned numLo, unsigned numHi, unsigned denLo, unsigned denHi);

void __fastcall Profiler_Leave(void *profiler /* ECX */)
{
  int idx;
  int *node;
  int *timer;
  int scaled;
  int parent;
  void *slots;

  if (*(char *)((char *)profiler + 0x175) == '\0') {
    return;
  }

  idx = FUN_007866e0(profiler);
  slots = *(void **)((char *)profiler + 0x4c);
  node = *(int **)((char *)slots + 8 + idx * 0xc);

  // ASM: MOV ESI, [node+4]; CALL FUN_00780690
  timer = *(int **)((char *)node + 4);
  // register ESI = timer (required by accumulate helper)
  FUN_00780690();

  timer = *(int **)((char *)node + 4);
  scaled = (int)__alldiv(
      *(unsigned *)((char *)timer + 0x8),
      *(unsigned *)((char *)timer + 0xc),
      *(unsigned *)((char *)timer + 0x10),
      *(unsigned *)((char *)timer + 0x14));
  *(int *)((char *)node + 0x28) = *(int *)((char *)node + 0x28) + scaled;

  parent = *(int *)((char *)node + 0x8);
  if (parent != 0) {
    idx = FUN_007866e0(profiler);
    slots = *(void **)((char *)profiler + 0x4c);
    *(int *)((char *)slots + idx * 0xc + 8) = parent;
  }
  return;
}

// Alias retained for xref continuity:
//   void __fastcall FUN_00786990(int param_1)  == Profiler_Leave
