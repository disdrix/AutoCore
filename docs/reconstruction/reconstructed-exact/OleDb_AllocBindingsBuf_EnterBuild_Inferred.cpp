// =============================================================================
// OleDb_AllocBindingsBuf_EnterBuild_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00421362
// Address:   0x00421362–0x00421391  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB accessor setup
// Generated: 2026-07-29 W24-F dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + byte CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   SEH-split fragment after parent FUN_00421240 allocates temp binding records
//   (colCount * 0x34) into [ebp-0x1c]. If that pointer is null, fail with
//   E_OUTOFMEMORY after COM Release on [ebp-0x18]. Otherwise set SEH level 4,
//   operator_new[](ctx->colCount) into ctx+0x10, and JMP into
//   OleDb_BuildBindingsAllocRow_Inferred (FUN_0042139b).
//
// ABI:
//   Shared parent EBP/SEH with FUN_0042139b + FUN_00421677.
//   Pre-entry 0x0042135f: mov ebx,[ebp+8]  (ctx*).
//   Success: jmp 0x0042139b (not call+ret).
//   Fail: shared epilogue ret 4, EAX = HRESULT 0x8007000E.
//
// CALLEES: operator_new[]; tail-join FUN_0042139b
// CALLERS: FUN_00421240 only
// =============================================================================

#include <cstdint>

#ifndef E_OUTOFMEMORY
#define E_OUTOFMEMORY ((int)0x8007000E)
#endif

extern "C" void* operator_new__(unsigned size);
extern "C" int FUN_0042139b(void);  // OleDb_BuildBindingsAllocRow_Inferred (jmp target)

// Offsets sealed from live decompile + bytes (product type name open).
struct OleDbAccessorBuildCtx_Inferred {
  void*    gateObj;      // +0x00
  uint32_t _pad04;       // +0x04
  void*    rowBuf;       // +0x08  (filled later by 0042139b)
  uint32_t colCount;     // +0x0c  size arg for this unit's new[]
  void*    auxOrStatus;  // +0x10  THIS unit stores allocation here
};

// Ghidra surface: undefined4 FUN_00421362(void) with unaff_EBX/unaff_EBP.
// Named plate documents CF with explicit shared-frame slots.
int OleDb_AllocBindingsBuf_EnterBuild_Inferred(
    OleDbAccessorBuildCtx_Inferred* ctx,   // EBX / [ebp+8]
    void* tempBindings,                    // [ebp-0x1c]  parent: colCount*0x34
    int* comIface,                         // [ebp-0x18]
    void* priorExceptionList,              // [ebp-0x0c]
    uint32_t& sehTryLevel,                 // [ebp-4]
    void*& exceptionList                   // FS:[0] / ExceptionList
) {
  sehTryLevel = 0;

  // --- null temp-bindings fail (parent new[] of colCount*0x34 failed) ---
  if (tempBindings == nullptr) {
    sehTryLevel = 0xFFFFFFFFu;
    if (comIface != nullptr) {
      // IUnknown::Release via vtbl+8
      (*(void(__stdcall**)(int*))(*(uint32_t*)comIface + 8))(comIface);
    }
    exceptionList = priorExceptionList;
    return E_OUTOFMEMORY;  // shared epilogue; ret 4
  }

  // --- allocate per-column aux/status into ctx+0x10; enter build ---
  sehTryLevel = 4;  // machine: mov byte [ebp-4], 4
  ctx->auxOrStatus = operator_new__(ctx->colCount);

  // Bytes: EB 09 → jmp 0x0042139b (tail-join; not CALL)
  return FUN_0042139b();
}

// Scaffold alias
extern "C" int FUN_00421362(void);
