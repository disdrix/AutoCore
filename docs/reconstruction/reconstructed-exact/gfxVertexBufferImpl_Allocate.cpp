// =============================================================================
// gfxVertexBufferImpl_Allocate
// -----------------------------------------------------------------------------
// Purpose:  Allocate device/system vertex-buffer resources for an already
//           constructed gfxVertexBufferImpl. Releases prior allocation state,
//           stores count/callback/format fields, calls device allocate helper,
//           logs plate failure, optionally invokes a callback, and updates
//           global VB budget counters.
//
// Address:  0x0099a8e0  (autoassault.exe, image base 0x400000)
// Body:     0x0099a8e0–0x0099a9a4 (196 bytes through final ret imm)
// Stable:   aa_0099a8e0
// System:   graphics / gfxVertexBufferImpl
// Ghidra:   FUN_0099a8e0
//
// ABI:      __thiscall self; 4 stack args; ret 0x10
//           ECX = gfxVertexBufferImpl*
// Prep:     FUN_0099a820 (free prior resources)
// Device:   FUN_00986a60(DAT_00d1f634, self, arg2) + format in EDX
// Plate:    gfxVertexBufferImpl.cpp:0x66 / "Failed to Allocate Vertex Buffer"
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned / INFERRED.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W22-L seal).
// =============================================================================

/* gfxVertexBufferImpl_Allocate

   Algorithm:
     1. FUN_0099a820 — tear down any prior device VB state for this.
     2. this+0x18 = vertexCount; this+0x1c = callback*.
     3. FUN_00447ea0 — init sub-region at this+0x24.
     4. this+0x34/+0x38 = formatDesc+0x10/+0x14.
     5. status = FUN_00986a60(deviceGlobal, this, strideOrUsage).
     6. On status < 0: zero fields; FUN_0044c3c0(0,0); log; return -1.
     7. On success: if callback, status = callback->vtbl[0](callback, this).
     8. If stats global: bump byte budget, vertex tally, buffer count.
     9. return status (ret 0x10).

   Callers: GfxVBHolder_ReplaceAndAllocate (0x00414c20),
            gfxVertexBufferImpl_Unserialize (0x0099aa20). */

#include <stdint.h>

extern void FUN_0099a820(void); /* ESI-this free prior resources */
extern void FUN_00447ea0(void); /* ESI = this+0x24 subobject init */
extern int FUN_00986a60(void *device, void *vb, uint32_t arg2);
extern void FUN_0044c3c0(int a, int b);
extern void vog_LogMessage(const char *file, int line, int level, const char *msg);

extern void *DAT_00d1f634; /* device / allocate context global */
extern int *DAT_00d1f614;  /* graphics stats singleton (or null) */

int __thiscall gfxVertexBufferImpl_Allocate(void *self,
                                            uint32_t vertexCount,
                                            void *formatDesc,
                                            uint32_t strideOrUsage,
                                            void *callback)
{
  int status;
  int *stats;
  int strideBytes;

  FUN_0099a820();

  *(uint32_t *)((uint8_t *)self + 0x18) = vertexCount;
  *(void **)((uint8_t *)self + 0x1c) = callback;
  FUN_00447ea0();

  *(uint32_t *)((uint8_t *)self + 0x34) =
      *(uint32_t *)((uint8_t *)formatDesc + 0x10);
  *(uint32_t *)((uint8_t *)self + 0x38) =
      *(uint32_t *)((uint8_t *)formatDesc + 0x14);

  status = FUN_00986a60(DAT_00d1f634, self, strideOrUsage);
  if (status < 0) {
    *(uint32_t *)((uint8_t *)self + 0x18) = 0;
    *(uint32_t *)((uint8_t *)self + 0x1c) = 0;
    *(uint32_t *)((uint8_t *)self + 0x34) = 0;
    *(uint32_t *)((uint8_t *)self + 0x38) = 0;
    FUN_0044c3c0(0, 0);
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferImpl.cpp",
        0x66, 3, "Failed to Allocate Vertex Buffer");
    return -1;
  }

  if (callback != 0) {
    /* ECX = callback; push self; call *[callback] */
    status = (*(int (__thiscall **)(void *, void *))(*(uint32_t *)callback))(
        callback, self);
  }

  stats = DAT_00d1f614;
  if (stats != 0) {
    strideBytes = *(int *)(*(int *)((uint8_t *)self + 0x10) + 8);
    *(int *)((uint8_t *)stats + 0x388) +=
        strideBytes * *(int *)((uint8_t *)self + 0x18);
    *(int *)((uint8_t *)stats + 0x338) +=
        *(int *)((uint8_t *)self + 0x18);
    *(int *)((uint8_t *)stats + 0x334) += 1;
  }
  return status;
}
