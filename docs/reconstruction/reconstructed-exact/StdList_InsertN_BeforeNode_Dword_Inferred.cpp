// =============================================================================
// StdList_InsertN_BeforeNode_Dword_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004034c0
// Address:   0x004034c0–0x00403522 inclusive (99 B / 0x63)
// Module:    autoassault.exe (image base 0x400000)
// System:    shared MSVC std::list (nested under missions-progression debug path)
// Generated: 2026-08-05 MEGA-134 dual (live Ghidra asm + decompile)
// Exactness: Behavior-preserving rewrite of sealed control flow / ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prior scaffold names RETIRED:
//   FUN_004034c0
//   Named_CalleeOf_Named_CalleeOf_Client_DebugListMissionsStatus_004034c0
// =============================================================================
//
// PURPOSE
//   Insert `count` copies of a dword value immediately before list node `where`.
//   Implements the grow half of list resize when the sole caller FUN_00402dd0
//   needs more elements: where = sentinel head ⇒ N× push_back of *val.
//
// ABI (SEALED — disassemble_function + call site 0x00402de6)
//   ECX          = const uint32_t* val
//   [ESP+4]      = list*          (+4 = head/sentinel*, +8 = size)
//   [ESP+8]      = where node*
//   [ESP+0xC]    = count
//   return       = void
//   cleanup      = RET 0xC
//
// CALLEE
//   FUN_004040f0  list thiscall insert-one-before:
//     FUN_00418700  BuyNode 0xC (Next, Prev, dword value)
//     FUN_00404840  Incsize(+1), max 0x3fffffff, "list<T> too long"
//
// READABILITY
//   - SEH frame LAB_009bd210 preserved as comment only (not port-critical).
//   - Loop is count-down; early-out when count == 0 (unsigned JBE).
// =============================================================================

#include <cstdint>

struct ListNodeDword {
    ListNodeDword *next; // +0
    ListNodeDword *prev; // +4
    uint32_t value;      // +8
};

struct StdListDword {
    void *unk0;            // +0 (allocator / pad — unused here)
    ListNodeDword *head;   // +4 sentinel
    uint32_t size;         // +8
};

// FUN_004040f0 — not dualled in MEGA-134; signature from its live asm.
extern "C" void __thiscall FUN_004040f0(
    StdListDword *list /*ECX*/,
    ListNodeDword *where,
    const uint32_t *val);

extern "C" void __fastcall StdList_InsertN_BeforeNode_Dword_Inferred(
    const uint32_t *val /*ECX*/,
    StdListDword *list /*stack1 — see note*/,
    ListNodeDword *where,
    uint32_t count)
{
    // Retail uses a custom layout: ECX=val*, three stdcall stack args, RET 0xC.
    // Represented here with explicit formals matching sealed slots.
    // SEH: LAB_009bd210 / FS:[0] — omitted in port-facing body.

    for (; count != 0; --count) {
        FUN_004040f0(list, where, val);
    }
}

// -----------------------------------------------------------------------------
// Byte-faithful entry shape (for reviewers correlating to disassembly):
//
//   MOV EBX, ECX              ; val*
//   MOV ESI, [EBP+10h]        ; count
//   MOV EDI, [EBP+0Ch]        ; where
// loop:
//   TEST ESI, ESI / JBE done
//   PUSH EBX / PUSH EDI
//   MOV ECX, [EBP+8]          ; list*
//   CALL FUN_004040f0
//   SUB ESI, 1 / JMP loop
// done:
//   RET 0Ch
// -----------------------------------------------------------------------------
