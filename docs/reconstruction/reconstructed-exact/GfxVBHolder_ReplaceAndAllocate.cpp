// =============================================================================
// GfxVBHolder_ReplaceAndAllocate
// -----------------------------------------------------------------------------
// Purpose:  Replace the vertex-buffer implementation pointer at holder+4 with a
//           pool-allocated gfxVertexBufferImpl instance, adjust refcounts, then
//           invoke gfxVertexBufferImpl allocate (FUN_0099a8e0). Returns allocate
//           status in EAX (HRESULT-style; callers test < 0).
//
// Address:  0x00414c20  (autoassault.exe, image base 0x400000)
// Body:     0x00414c20–0x00414cc0 (161 bytes through final ret imm)
// Stable:   aa_00414c20
// System:   graphics / gfxVertexBufferImpl
// Ghidra:   FUN_00414c20
//
// ABI:      __thiscall holder; 4 stack args; ret 0x10
//           ECX = holder*; holder+4 = current VB impl*
// Pool:     DAT_00d218e0 via FUN_00414cd0
// Ctor:     FUN_00999960 (vtbl PTR_FUN_00aa161c)
// Allocate: FUN_0099a8e0 (plate gfxVertexBufferImpl.cpp)
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned / INFERRED.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W21-L seal).
// =============================================================================

/* GfxVBHolder_ReplaceAndAllocate — holder VB slot replace + allocate.

   Algorithm:
     1. Install SEH (LAB_009bf04b).
     2. Pop node from global freelist DAT_00d218e0 (FUN_00414cd0).
     3. If non-null: construct as gfxVertexBufferImpl (FUN_00999960).
     4. If new non-null: refcount++ at +4; if count==1 call vtbl+4.
     5. If old at holder+4 non-null: refcount--; if 0 call vtbl+8.
     6. Store new at holder+4.
     7. Call FUN_0099a8e0(new, a,b,c,d); return its EAX.

   Callers: CVOGTerrainChunk_BuildVertexBuffer, CVOGTacArc_InitializeMesh,
   gfxGeometryPiece Serialize/Unserialize, many mesh/VB setup paths. */

#include <stdint.h>

extern int __fastcall Freelist_PopNode_00414cd0(void *freelist_head);
extern void *__thiscall gfxVertexBufferImpl_Ctor_00999960(void *node);
extern int __thiscall gfxVertexBufferImpl_Allocate_0099a8e0(
    void *vb_this,
    uint32_t arg0,
    uint32_t arg1,
    uint32_t arg2,
    uint32_t arg3);

/* Global freelist head used by this unit (bytes: mov ecx, 0x00d218e0). */
extern void *DAT_00d218e0;

int __thiscall GfxVBHolder_ReplaceAndAllocate(void *holder,
                                              uint32_t arg0,
                                              uint32_t arg1,
                                              uint32_t arg2,
                                              uint32_t arg3)
{
  int *new_vb;
  int *old_vb;
  int pool_node;

  /* SEH frame omitted (compiler frame); active through body. */

  pool_node = Freelist_PopNode_00414cd0(&DAT_00d218e0);
  if (pool_node == 0) {
    new_vb = 0;
  } else {
    new_vb = (int *)gfxVertexBufferImpl_Ctor_00999960((void *)pool_node);
  }

  if (new_vb != 0) {
    new_vb[1] = new_vb[1] + 1;
    if (new_vb[1] == 1) {
      /* vtbl+4 first-ref hook */
      ((void (__thiscall *)(int *))(*(uint32_t *)(*new_vb + 4)))(new_vb);
    }
  }

  old_vb = *(int **)((uint8_t *)holder + 4);
  if (old_vb != 0) {
    old_vb[1] = old_vb[1] - 1;
    if (old_vb[1] == 0) {
      /* vtbl+8 release */
      ((void (__thiscall *)(int *))(*(uint32_t *)(*old_vb + 8)))(old_vb);
    }
  }

  *(int **)((uint8_t *)holder + 4) = new_vb;
  return gfxVertexBufferImpl_Allocate_0099a8e0(new_vb, arg0, arg1, arg2, arg3);
}
