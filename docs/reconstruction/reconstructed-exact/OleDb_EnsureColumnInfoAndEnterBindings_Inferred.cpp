// =============================================================================
// OleDb_EnsureColumnInfoAndEnterBindings_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00421240
// Address:   0x00421240–0x00421358  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB accessor setup
// Generated: 2026-07-29 W25-C dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + byte CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00421240
// =============================================================================
//
// PURPOSE:
//   Parent of the sealed binding-build chain:
//     QI IAccessor on source; ensure column info (pre-supplied or via IColumnsInfo::
//     GetColumnInfo); allocate temp DBBINDING[colCount] (stride 0x34); JMP into
//     OleDb_AllocBindingsBuf_EnterBuild_Inferred (aa_00421362) on the shared SEH frame.
//
// ABI:
//   __thiscall — ECX = IUnknown* source; stack ctx*; fail ret 4 (HRESULT).
//   Success: jmp 0x00421362 (not call+ret). Decompiler may show call FUN_00421362.
//
// IIDs (read_memory sealed):
//   DAT_00a860ac = IID_IAccessor   {0C733A8C-2A1C-11CE-ADE5-00AA0044773D}
//   DAT_00a85ffc = IID_IColumnsInfo {0C733A11-2A1C-11CE-ADE5-00AA0044773D}
//
// CALLEES: operator_new[]; tail-join FUN_00421362; COM QI/Release
// CALLERS (Ghidra): none listed — residual gap
// =============================================================================

#include <cstdint>

#ifndef HRESULT
using HRESULT = int32_t;
#endif

extern "C" void* operator_new__(unsigned size);
extern "C" HRESULT FUN_00421362(void);  // OleDb_AllocBindingsBuf_EnterBuild_Inferred (jmp)

// IID blobs live at DAT_* in image; referenced by address in body.
extern "C" const char DAT_00a860ac[];  // IID_IAccessor
extern "C" const char DAT_00a85ffc[];  // IID_IColumnsInfo

struct OleDbAccessorBuildCtx_Inferred {
  void*    gateObj;               // +0x00  (child chain)
  uint32_t _pad04;                // +0x04
  void*    rowBuf;                // +0x08
  uint32_t colCount;              // +0x0c
  void*    auxOrStatus;           // +0x10  (filled by 00421362)
  void*    colInfo;               // +0x14  DBCOLUMNINFO* / void*
  void*    strings;               // +0x18  OLECHAR* from GetColumnInfo
  uint8_t  columnsPreSupplied;    // +0x1c  1=already set; 0=from GetColumnInfo
};

// Clean plate documents CF; SEH ExceptionList mechanics omitted for readability.
// Success path is a machine jmp into FUN_00421362 with shared EBP (EBX=ctx at pre-entry).
HRESULT __thiscall OleDb_EnsureColumnInfoAndEnterBindings_Inferred(
    void* source /* IUnknown* */,
    OleDbAccessorBuildCtx_Inferred* ctx)
{
  void* pAcc = nullptr;
  // QueryInterface(IID_IAccessor, &pAcc) via (*source->vtbl)(source, &DAT_00a860ac, &pAcc)
  auto** srcVtbl = *reinterpret_cast<void***>(source);
  auto qi = reinterpret_cast<HRESULT(__stdcall*)(void*, const void*, void**)>(srcVtbl[0]);
  HRESULT hr = qi(source, &DAT_00a860ac, &pAcc);
  if (hr < 0) {
    if (pAcc) {
      auto** v = *reinterpret_cast<void***>(pAcc);
      reinterpret_cast<uint32_t(__stdcall*)(void*)>(v[2])(pAcc);  // Release @ vtbl+8
    }
    return hr;
  }

  if (ctx->colInfo != nullptr) {
    ctx->columnsPreSupplied = 1;
  } else {
    void* pCols = nullptr;
    hr = qi(source, &DAT_00a85ffc, &pCols);
    if (hr >= 0) {
      auto** cv = *reinterpret_cast<void***>(pCols);
      // GetColumnInfo @ vtbl+0x0C
      auto getColInfo = reinterpret_cast<HRESULT(__stdcall*)(void*, uint32_t*, void**, void**)>(
          cv[3]);
      hr = getColInfo(pCols, &ctx->colCount, &ctx->colInfo, &ctx->strings);
      if (hr >= 0) {
        ctx->columnsPreSupplied = 0;
        if (pCols) {
          reinterpret_cast<uint32_t(__stdcall*)(void*)>(cv[2])(pCols);
        }
        // fall through to alloc
      } else {
        if (pCols) {
          reinterpret_cast<uint32_t(__stdcall*)(void*)>(cv[2])(pCols);
        }
        if (pAcc) {
          auto** v = *reinterpret_cast<void***>(pAcc);
          reinterpret_cast<uint32_t(__stdcall*)(void*)>(v[2])(pAcc);
        }
        return hr;
      }
    } else {
      if (pAcc) {
        auto** v = *reinterpret_cast<void***>(pAcc);
        reinterpret_cast<uint32_t(__stdcall*)(void*)>(v[2])(pAcc);
      }
      return hr;
    }
  }

  // SEH try level = 2 on machine path; temp = new[](colCount * 0x34)
  void* tempBindings = operator_new__(ctx->colCount * 0x34u);
  (void)tempBindings;  // lives at [ebp-0x1C] for child fragment
  // Bytes: EB 09 → jmp 0x00421362 (shared frame; pAcc kept for finalize)
  return FUN_00421362();
}

extern "C" HRESULT __thiscall FUN_00421240(void* source, OleDbAccessorBuildCtx_Inferred* ctx)
{
  return OleDb_EnsureColumnInfoAndEnterBindings_Inferred(source, ctx);
}
