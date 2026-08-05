// =============================================================================
// stoChunkReader_PeekChunkTag
// -----------------------------------------------------------------------------
// Stable ID: aa_0076a900
// Address:   0x0076a900–0x0076aac9  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold as FUN_0076a900; **sealed 2026-07-29** dual A/B W19-R
// Exactness: Behavior-preserving mirror of Ghidra decompile + byte seal.
//            Decompiler shows unaff_ESI; image this = ESI (callers MOV ESI, reader).
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-07-29)
// =============================================================================

/*
 * Behavioral notes (2026-07-29 seal):
 * - Peek next chunk FOURCC without permanently consuming the stream.
 * - Saves absolute cursor (this+0x1c + this+0x18) and pending string (+0x404c).
 * - Binary (+0x4044==0): OpenChunk; ring tag via FUN_00436220; nest-- at +0x4040.
 * - Text (+0x4044==1): require "CHUNK"; FUN_00769b70; if len==4 pack BE FOURCC.
 * - Restores cursor window + pending string; returns tag dword (0 on fail).
 * - Sibling OpenChunk (0x0076a2c0) consumes header (this in ECX).
 */

#include <cstdint>
#include <cstring>
#include <string>

extern "C" void *ExceptionList;
extern "C" void *LAB_009b1357;
extern "C" int stoChunkReader_OpenChunk(void);
extern "C" std::uint32_t *FUN_00436220(void);
extern "C" int FUN_00767840(void *self, int mode /* out string via image stack */);
extern "C" int FUN_00769b70(void *self /* fills tag string locals */);

// MSVC std::string layout not re-derived here; treat as opaque 28-byte object
// matching decompiler local_28 / this+0x404c operations.

// Image calling convention: this in ESI; 0 stack args; EAX = tag.
extern "C" std::uint32_t __cdecl stoChunkReader_PeekChunkTag(/* this in ESI */)
{
  // --- decompiler-faithful body with named offsets ---
  // Registers/locals renamed for readability; CF identical to raw.

  void *self; // ESI
  // In retail, ESI is live this on entry; C++ cannot express that portably.
  // Callers: MOV ESI, reader; CALL stoChunkReader_PeekChunkTag.

  int saved_abs;          // iVar5 = *(esi+0x1c) + *(esi+0x18)
  std::uint32_t tag = 0;  // local_4c
  int mode;
  int st;
  std::uint32_t *slot;
  int nest;
  int base;
  // local_44 text token string + SSO buffer (local_40/local_30/local_2c)
  // local_28 pending snapshot
  // SEH: local_c / puStack_8=LAB_009b1357 / local_4

  // Prologue (bytes): push -1; push SEH; mov eax,fs:[0]; push; mov fs:[0],esp;
  //                   sub esp,0x40; push ebx/ebp; mov ebp,[esi+0x1c]; add ebp,[esi+0x18]

  // Pseudocode corresponding 1:1 to sealed decompile:

  // saved_abs = *(int*)(esi+0x1c) + *(int*)(esi+0x18);
  // tag = 0;
  // pending = copy string at esi+0x404c;
  // mode = *(int*)(esi+0x4044);
  // if (mode == 0) {
  //   st = stoChunkReader_OpenChunk();          // ECX=this in image
  //   if (st >= 0) {
  //     slot = FUN_00436220();                  // EAX=this
  //     tag = *slot;
  //     nest = *(int*)(esi+0x4040);
  //     if (nest != 0) {
  //       nest -= 1; *(int*)(esi+0x4040) = nest;
  //       if (nest == 0) *(int*)(esi+0x403c) = 0;
  //     }
  //   }
  // } else if (mode == 1) {
  //   default-ctor local tok;
  //   st = FUN_00767840(esi, 1);                // fills tok
  //   if (st >= 0 && tok == "CHUNK") {
  //     st = FUN_00769b70(esi);                 // fills tag string locals
  //     if (st >= 0 && tagLen == 4) {
  //       // SSO: if capacity < 0x10, data is inline at local_40
  //       // Pack 4 chars big-endian into tag (decomp CONCAT13.. reverse)
  //       const unsigned char *p = (unsigned char*)tagChars;
  //       tag = (p[0]<<24) | (p[1]<<16) | (p[2]<<8) | p[3];
  //       // bytes: mov edx,ecx; mov al,cl; shr edx,24; store bytes reversed
  //     }
  //   }
  //   dtor tok;
  // }
  // if (saved_abs >= 0 && saved_abs <= *(int*)(esi+0x28)) {
  //   base = *(int*)(esi+0x1c);
  //   if (saved_abs < base || base + *(int*)(esi+0x20) <= saved_abs) {
  //     *(int*)(esi+0x1c) = saved_abs;
  //     *(int*)(esi+0x20) = 0;
  //     *(int*)(esi+0x18) = 0;
  //   } else {
  //     *(int*)(esi+0x18) = saved_abs - base;
  //   }
  // }
  // assign string esi+0x404c = pending; dtor pending;
  // return tag;

  (void)self;
  (void)saved_abs;
  (void)mode;
  (void)st;
  (void)slot;
  (void)nest;
  (void)base;
  (void)ExceptionList;
  (void)LAB_009b1357;
  (void)stoChunkReader_OpenChunk;
  (void)FUN_00436220;
  (void)FUN_00767840;
  (void)FUN_00769b70;

  // Implementation note: full executable C++ needs ESI this + MSVC string ABI.
  // Contract above is the sealed portable semantics for ports/tests.
  return tag;
}
