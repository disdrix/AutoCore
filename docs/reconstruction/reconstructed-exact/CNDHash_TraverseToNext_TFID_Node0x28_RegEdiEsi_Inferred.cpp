// =============================================================================
// CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c6b0
// Address:   0x0040c6b0  (autoassault.exe, image base 0x400000)
// Body:      0x0040c6b0–0x0040c6f0 inclusive (65 B / 0x41); pad CC → 0x0040c700
// System:    interaction-activation / CNDHash
// Seal:      MEGA-112 2026-08-05 — decompile_function + force_decompile +
//            analyze_function_complete + callers/xrefs + disassemble_function +
//            read_memory + parent Client_UpdateNpcInteractIcons call sites.
// Exactness: Behavior-preserving CF; custom EDI/ESI ABI documented.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================

#include <cstdint>

// Logger (FUN_007a4480) — level + C-string; cdecl (ADD ESP,0x10 for two calls).
extern "C" void FUN_007a4480(int level, const char *msg);

// 16-byte object id (parent types return as TFID_16*).
struct TFID_16 {
  uint32_t dwCoidHi;
  uint32_t dwCoidLo;
  // remaining 8 B not read by this leaf
  uint32_t _pad[2];
};

// 0x28-class CNDHash ordered-list node (u64-key family).
// Only list-next @ +0x20 and payload @ +0xc are touched here.
struct CndHashNode0x28 {
  uint32_t _unk00[3];     // +0x00 .. +0x0b
  TFID_16 *payload;       // +0x0c  (value returned)
  uint32_t _unk10[4];     // +0x10 .. +0x1f
  CndHashNode0x28 *next;  // +0x20  list-next
  // ... remainder of 0x28
};

// CNDHash shell fields used by TraverseToNext.
struct CndHash {
  uint32_t _unk00[5];     // +0x00 .. +0x13
  CndHashNode0x28 *head;  // +0x14  ordered-list head
  uint32_t _unk18;        // +0x18
  uint8_t _unk1c;         // +0x1c
  uint8_t locked;         // +0x1d  TraversalLock flag
};

// ---------------------------------------------------------------------------
// Retail ABI (machine):
//   in  EDI = CndHash *hash
//   in  ESI = CndHashNode0x28 **pCursor
//   out EAX = TFID_16 *payload  (or 0)
//   stack: none cleaned (plain RET / c3) — NOT thiscall, NOT ret 4
// Decompiler prints: undefined4 FUN_0040c6b0(void) with unaff_EDI / unaff_ESI.
// Parent: Client_UpdateNpcInteractIcons (0x0091b8d0) ×2:
//   MOV EDI, *[DAT_00d1b644 + 0xe8f4]; LEA ESI, [esp+cursor]; CALL 0040c6b0
// ---------------------------------------------------------------------------

// Portable CF reconstruction (registers expressed as parameters):
TFID_16 *CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred(
    CndHash *hash, CndHashNode0x28 **pCursor)
{
  if (hash->locked == 0) {
    FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    // fall-through — unlocked traverse is logged, not aborted
  }

  CndHashNode0x28 *node;
  if (*pCursor == nullptr) {
    *pCursor = hash->head;
    node = hash->head;
  } else {
    node = (*pCursor)->next;  // node+0x20
    *pCursor = node;
  }

  if (node != nullptr) {
    return node->payload;  // node+0xc
  }
  return nullptr;
}

// Ghidra symbol surface twin (unaff_EDI/unaff_ESI form):
//   reconstructed-exact/FUN_0040c6b0.cpp
