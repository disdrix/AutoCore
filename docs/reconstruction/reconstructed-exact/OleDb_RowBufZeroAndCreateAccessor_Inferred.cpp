// =============================================================================
// OleDb_RowBufZeroAndCreateAccessor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00421677
// Address:   0x00421677–0x00421732  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB accessor finalize
// Generated: 2026-07-29 W22-N dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + byte CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   After parent FUN_0042139b allocates ctx->rowBuf, zero-fill it, call
//   OleDb_IAccessor_CreateAccessor_FreeBindings (FUN_00422830), free temp
//   bindings, release COM iface, return HRESULT. Null rowBuf => E_OUTOFMEMORY.
//
// ABI:
//   Outer shape: 1 stack formal (ctx*), ret 4. Ghidra entry assumes EBX=ctx
//   (pre-entry 0x00421674: mov ebx,[ebp+8]). Shared parent EBP frame.
//
// CALLEES:
//   FUN_00422830 OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred
//   operator_delete[]
//
// CALLERS:
//   FUN_0042139b only
// =============================================================================

#include <cstdint>

// Custom-ABI callee — see aa_00422830 dual for register/stack contract.
extern "C" int FUN_00422830(/* EAX iface-ish, ECX count-ish, EDX bindings,
                               stack formals */);

extern "C" void operator_delete__(void* p); // operator_delete[]

// Context object fields used by this unit (byte-sealed offsets).
struct OleDbAccessorFinalizeCtx_Inferred {
  uint32_t field00;     // +0x00 pushed into CreateAccessor stack
  uint32_t _pad04;
  void*    rowBuf;      // +0x08 zero-filled; null => E_OUTOFMEMORY
  uint32_t field0c;     // +0x0c -> ECX for CreateAccessor (cBindings Probable)
  void*    auxBuf;      // +0x10 freed on fail paths
};

// Shared parent frame slots (offsets from EBP) — not a complete typedef.
//   [ebp-0x24] = row byte size
//   [ebp-0x1c] = temporary bindings / staging (deleted after create)
//   [ebp-0x18] = COM iface* (Release via vtbl+8)
//   [ebp-0x0c] = prior ExceptionList
//   [ebp-0x04] = SEH try level

#ifndef E_OUTOFMEMORY
#define E_OUTOFMEMORY ((int)0x8007000E)
#endif

// Ghidra symbol retained for xref continuity.
extern "C" int FUN_00421677(void);

// Named plate — register/frame contract as sealed (not portable C ABI).
int OleDb_RowBufZeroAndCreateAccessor_Inferred(
    OleDbAccessorFinalizeCtx_Inferred* ctx,
    /* parent frame via EBP: */
    void* tempBindings,      // [ebp-0x1c]
    uint32_t rowByteSize,    // [ebp-0x24]
    int* comIface /*IUnknown-ish*/, // [ebp-0x18]
    void* priorExceptionList, // [ebp-0x0c]
    int* sehTryLevel,        // [ebp-0x04]
    void** pExceptionList    // &ExceptionList
) {
  void* row = ctx->rowBuf;
  if (row == nullptr) {
    operator_delete__(tempBindings);
    operator_delete__(ctx->auxBuf);
    *sehTryLevel = -1;
    ctx->auxBuf = nullptr;
    if (comIface != nullptr) {
      // (*(code**)(*comIface + 8))(comIface)  — IUnknown::Release
      (*(void(__stdcall**)(int*))(*(uint32_t*)comIface + 8))(comIface);
    }
    *pExceptionList = priorExceptionList;
    return E_OUTOFMEMORY;
  }

  // Zero-fill row buffer (rep stosd + rep stosb).
  {
    uint8_t* p = reinterpret_cast<uint8_t*>(row);
    uint32_t n = rowByteSize;
    while (n >= 4) {
      *reinterpret_cast<uint32_t*>(p) = 0;
      p += 4;
      n -= 4;
    }
    while (n--) {
      *p++ = 0;
    }
  }

  // FUN_00422830 custom ABI — decompiler collapses args; bytes set:
  //   push rowByteSize; push ctx->field00;
  //   EAX=[ebp-0x18], ECX=ctx->field0c, EDX=tempBindings
  int hr = FUN_00422830();

  operator_delete__(tempBindings);

  if (hr < 0) {
    operator_delete__(ctx->auxBuf);
    ctx->auxBuf = nullptr;
  }

  *sehTryLevel = -1;
  if (comIface != nullptr) {
    (*(void(__stdcall**)(int*))(*(uint32_t*)comIface + 8))(comIface);
  }
  *pExceptionList = priorExceptionList;
  return hr;
}

// Scaffold entry matching Ghidra void(void) surface (frame via unaff regs).
int FUN_00421677(void) {
  // Real body is frame/register-bound; see annotated + named plate above.
  // Kept for symbol parity with Ghidra FUN_00421677.
  return OleDb_RowBufZeroAndCreateAccessor_Inferred(
      /*ctx*/ nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr);
}
