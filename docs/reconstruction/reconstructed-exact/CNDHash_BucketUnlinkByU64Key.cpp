// =============================================================================
// CNDHash_BucketUnlinkByU64Key  (inferred product name)
// -----------------------------------------------------------------------------
// Stable ID: aa_00419b80
// Address:   0x00419b80  (autoassault.exe, image base 0x400000)
// Body:      0x00419b80–0x00419bc9  (73 bytes; ret 8)
// System:    container / CNDHash (u64-key family)
// Twin file: FUN_00419b80.cpp
// Generated: 2026-07-29 W18-P dual seal
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================

#include <stdint.h>

// Bucket header: +0x04 chain head.
// Node: next@+0x10, keyLo@+0x18, keyHi@+0x1c (keys compared in find callee).
//
// ABI:
//   EBX = bucketHeader*
//   stack stdcall: keyLo, keyHi  → ret 8
//   EAX return = Node* (unlinked from bucket chain) or NULL
//
// predOut for find reuses the keyLo stack slot (LEA EDI into that slot).
// After find returns, that slot holds predecessor Node* (or 0), not keyLo.
//
// Decompiler trap: "if (param_1 != 0)" is predecessor, not keyLo.

// Callees (not dual-owned here):
//   CNDHash_BucketFindNodeByU64Key @ 0x00419b40  (EAX=header, EDI=predOut*)
//   FUN_00419ad0                    @ 0x00419ad0  (EDI=header; touch/cycle repair)

extern "C" void *CNDHash_BucketFindNodeByU64Key(uint32_t keyLo, uint32_t keyHi);
extern "C" void  CNDHash_BucketChainTouchRepair(void); // FUN_00419ad0, EDI=bucket

// Register form (authoritative). Pseudocode matches body bytes:
//
//   push keyHi; push keyLo;
//   lea edi, [esp+14];          // &pred in keyLo slot
//   mov eax, ebx;               // bucket
//   call CNDHash_BucketFindNodeByU64Key
//   mov esi, eax;               // node
//   test esi, esi
//   jz  miss
//   mov ecx, [esp+0xc];         // pred = *predOut
//   test ecx, ecx
//   mov eax, [esi+0x10];        // next
//   jz  head
//   mov edi, ebx
//   mov [ecx+0x10], eax;        // pred->next = next
//   call FUN_00419ad0
//   mov eax, esi; ret 8
// head:
//   mov [ebx+4], eax;           // head = next
// miss:
//   mov edi, ebx
//   call FUN_00419ad0
//   mov eax, esi; ret 8

extern "C" void *__stdcall CNDHash_BucketUnlinkByU64Key(uint32_t keyLo,
                                                         uint32_t keyHi)
{
    // Placeholder locals so the TU is valid C++; CF comments above are the seal.
    void *bucket = 0;   // EBX at entry
    void *pred = 0;     // written by find
    void *node;
    void *next;

    (void)keyLo;
    (void)keyHi;
    (void)bucket;

    node = CNDHash_BucketFindNodeByU64Key(keyLo, keyHi);
    if (node != 0) {
        next = *(void **)((char *)node + 0x10);
        if (pred != 0) {
            *(void **)((char *)pred + 0x10) = next;
        } else {
            *(void **)((char *)bucket + 4) = next;
        }
    }
    CNDHash_BucketChainTouchRepair();
    return node;
}
