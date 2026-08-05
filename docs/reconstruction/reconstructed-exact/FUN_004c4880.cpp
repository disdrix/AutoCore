// =============================================================================
// FUN_004c4880 / Object_SetTFID_ApplyPhysMode_Rebind
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4880
// Address:   0x004c4880  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_004c4880
// System:    object / TFID / phys rebind
// Sealed:    2026-07-29 W26-F (live decompile + read_memory + analyze_function_complete)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Store a 16-byte TFID_16 (COID lo/hi + two trailing dwords) at object+0x108,
//   then if a phys/world child exists at object+8, set phys+0x28 to mode 0xB
//   (invalid/unassigned TFID) or 10 (assigned TFID) and rebind/activate via
//   WorldObj_RebindActivate_Inferred (FUN_00560e90).
//
// EVIDENCE:
//   - Sibling FUN_004c4440 names fields dwCoidLo/Hi and type TFID_16 at +0x108.
//   - Sibling FUN_004c4620 is the pure mode leaf (0xB vs 10) with identical predicate.
//   - Callee dual-sealed as WorldObj_RebindActivate_Inferred (W24-B).
//   - Sole caller FUN_00626890 after entity resolve.
//
// ABI: thiscall; RET 4; ECX=this; stack = const uint32_t src[4]
// Body: 0x004c4880–0x004c48f1 (114 B)

#include <stdint.h>

// FUN_00560e90 — WorldObj_RebindActivate_Inferred (manager thiscall residual on surface)
extern "C" void __stdcall FUN_00560e90(uint32_t phys_obj, uint32_t flag_or_unused);

extern "C" void __thiscall Object_SetTFID_ApplyPhysMode_Rebind(int self, uint32_t *src_tfid)
{
  *(uint32_t *)(self + 0x108) = src_tfid[0];
  *(uint32_t *)(self + 0x10c) = src_tfid[1];
  *(uint32_t *)(self + 0x110) = src_tfid[2];
  *(uint32_t *)(self + 0x114) = src_tfid[3];

  int phys = *(int *)(self + 8);
  if (phys != 0) {
    if (((*(uint32_t *)(self + 0x108) & *(uint32_t *)(self + 0x10c)) == 0xFFFFFFFFu) &&
        (*(char *)(self + 0x110) == '\0')) {
      *(uint32_t *)(phys + 0x28) = 0xBu;
    } else {
      *(uint32_t *)(phys + 0x28) = 10u;
    }
    FUN_00560e90((uint32_t)(*(uint32_t *)(self + 8)), 1u);
  }
}

// Ghidra twin
extern "C" void __thiscall FUN_004c4880(int param_1, uint32_t *param_2)
{
  Object_SetTFID_ApplyPhysMode_Rebind(param_1, param_2);
}
