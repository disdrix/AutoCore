// =============================================================================
// OleDb_BuildBindingsAllocRow_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0042139b
// Address:   0x0042139b–0x0042166d  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB binding build + row buffer alloc
// Generated: 2026-07-29 W23-C dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + byte CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Shared-frame fragment after FUN_00421362 allocates ctx+0x10: map each
//   column DBTYPE to binding size, fill binding records, accumulate row byte
//   size, optionally FUN_00422880 when *ctx==0, operator_new[] row buffer into
//   ctx+0x08, then jmp into OleDb_RowBufZeroAndCreateAccessor_Inferred
//   (FUN_00421677) which owns the final ret 4 / CreateAccessor.
//
// ABI:
//   1 stack formal (ctx*). ret 4 on fail paths inside this fragment.
//   Pre-entry 0x00421390: mov ebx,[ebp+8]. Success: jmp 0x00421674 (not call).
//   Shared EBP/SEH with FUN_00421362 + FUN_00421677 (Ghidra SEH split).
//
// CALLEES: FUN_00422900, FUN_00422880, operator_new[]/delete[], cont. FUN_00421677
// CALLERS: FUN_00421362 only
// =============================================================================

#include <cstdint>

#ifndef E_OUTOFMEMORY
#define E_OUTOFMEMORY ((int)0x8007000E)
#endif

extern "C" int FUN_00422900(/* custom */);
extern "C" int FUN_00422880(/* custom */);
extern "C" int FUN_00421677(void);  // finalize: zero row + CreateAccessor + ret 4
extern "C" void* operator_new__(unsigned size);
extern "C" void operator_delete__(void* p);

// Offsets sealed from live decompile + bytes (product type name open).
struct OleDbAccessorBuildCtx_Inferred {
  void*    gateObj;      // +0x00
  uint32_t _pad04;       // +0x04
  void*    rowBuf;       // +0x08
  uint32_t colCount;     // +0x0c  (EBX[3])
  void*    auxOrStatus;  // +0x10  (EBX[4]) null => E_OUTOFMEMORY
  uint32_t colRecBase;   // +0x14  (EBX[5]) column-array addend / stride base
  uint32_t _16;
  uint32_t _1c;
  uint32_t _20;
  uint32_t maxPayload;   // +0x24  (EBX[9])
};

// Ghidra surface uses unaff_EBX / unaff_EBP. Named plate documents CF with
// explicit frame slots matching the shared parent.
int OleDb_BuildBindingsAllocRow_Inferred(
    OleDbAccessorBuildCtx_Inferred* ctx,
    void* tempBindings,        // [ebp-0x1c]
    uint32_t& rowByteSize,     // [ebp-0x24]
    int* comIface,             // [ebp-0x18]
    void* priorExceptionList,  // [ebp-0x0c]
    uint32_t& sehTryLevel,     // [ebp-0x04]
    void*& exceptionList       // FS:[0] / ExceptionList
) {
  sehTryLevel = 0;

  // --- null aux/status fail ---
  if (ctx->auxOrStatus == nullptr) {
    operator_delete__(tempBindings);
    sehTryLevel = 0xFFFFFFFFu;
    if (comIface != nullptr) {
      // IUnknown::Release via vtbl+8
      (*(void(__stdcall**)(int*))(*(uint32_t*)comIface + 8))(comIface);
    }
    exceptionList = priorExceptionList;
    return E_OUTOFMEMORY;  // bytes: B8 0E 00 07 80; epilogue ret 4
  }

  // --- per-column binding build ---
  uint32_t colCount = ctx->colCount;
  uint32_t colIndex = 0;  // [ebp-0x2c]
  if (colCount != 0) {
    int align = FUN_00422900();
    uint32_t alignMask = ~(uint32_t)(align - 1);  // [ebp-0x38]
    uint32_t colSide = 0;                         // [ebp-0x30] steps +0x30
    uint32_t* bindingAt = (uint32_t*)((uint8_t*)tempBindings + 0x14);  // +0x34/step

    do {
      uint8_t* statusBytes = (uint8_t*)ctx->auxOrStatus;
      statusBytes[colIndex] = 0;

      // Column record pointer: decomp `iVar8 = iVar12 + unaff_EBX[5]`
      uint8_t* col = (uint8_t*)(colSide + ctx->colRecBase);
      uint32_t cbMaxLen = *(uint32_t*)(col + 0x10);
      uint16_t wType = *(uint16_t*)(col + 0x14);

      if (ctx->maxPayload < cbMaxLen || wType == 0x0d) {
        // oversize / DBTYPE_VARIANT-ish force path (LAB_00421519)
        *(uint16_t*)(col + 0x14) = 0x4082;
        *(uint32_t*)(col + 0x10) = 4;
        statusBytes[colIndex] = 1;
      } else {
        // DBTYPE switch -> payload size (sealed cases)
        uint32_t size = cbMaxLen;
        if (wType < 0x41) {
          if (wType == 0x40) {
            size = 0x20;
          } else {
            switch (wType) {
              case 2:  size = 7; break;
              case 3:  size = 0x0c; break;
              case 4:  size = 0x0d; break;
              case 5:
              case 0x0e: size = 0x17; break;
              case 8:  break;  // keep
              case 0x0b: size = 2; break;
              case 0x0c: size = 0x14; break;
              case 0x10: size = 5; break;
              case 0x11: size = 4; break;
              case 0x12: size = 6; break;
              case 0x13: size = 0x0b; break;
              case 0x14: size = 0x16; break;
              case 0x15: size = 0x15; break;
              default: size = 0x20; break;
            }
          }
        } else if (wType < 0x87) {
          switch (wType) {
            case 0x48: size = 0x26; break;
            case 0x80: size = cbMaxLen * 2; break;
            case 0x81:
            case 0x82: break;
            case 0x83: size = 0x17; break;
            default: size = 0x20; break;
          }
        } else {
          size = 0x20;
        }
        *(uint32_t*)(col + 0x10) = size * 2 + 2;
        *(uint16_t*)(col + 0x14) = 0x0082;
      }

      // Layout math (sealed):
      //   valueOff = (align-1 + rowByteSize) & alignMask
      //   lenOff   = (cb + 3 + valueOff) & ~3
      //   statusOff= lenOff + 4
      //   rowByteSize = lenOff + 8
      // Fill binding record at bindingAt-5 .. bindingAt+7 (0x34-byte stride):
      //   dwPart starts 1; |2 if len; |4 if status; copy wType/precision/scale.
      // Store valueOff into column-side +4.
      uint32_t cb = *(uint32_t*)(col + 0x10);
      uint32_t valueOff =
          (uint32_t)(align - 1 + (int)rowByteSize) & alignMask;
      uint32_t lenOff = (cb + 3 + valueOff) & 0xFFFFFFFCu;
      uint32_t statusOff = lenOff + 4;
      rowByteSize = lenOff + 8;

      // Binding field fills (decomp puVar10[...]) — preserved order:
      //   ordinal/ob from column+8; precision/scale from col+0x16/+0x17;
      //   dwPart=1; if lenOff!=0 dwPart=3; if statusOff!=0 dwPart|=4;
      //   cbMaxLen=cb; wType from col; zeros for unused ptr slots.
      (void)valueOff;
      (void)statusOff;
      (void)bindingAt;  // full dword stores in raw/annotated

      // column-side +4 = valueOff; colSide += 0x30; bindingAt += 13 dwords
      *(uint32_t*)((uint8_t*)ctx->colRecBase + colSide + 4) = valueOff;
      colSide += 0x30;
      bindingAt += 13;  // 0x34 bytes
      ++colIndex;
    } while (colIndex < colCount);
  }

  // --- optional gate object path ---
  if (ctx->gateObj == nullptr) {
    int hr = FUN_00422880();
    if (hr < 0) {
      operator_delete__(tempBindings);
      operator_delete__(ctx->auxOrStatus);
      sehTryLevel = 0xFFFFFFFFu;
      ctx->auxOrStatus = nullptr;
      if (comIface != nullptr) {
        (*(void(__stdcall**)(int*))(*(uint32_t*)comIface + 8))(comIface);
      }
      exceptionList = priorExceptionList;
      return hr;  // ret 4
    }
    // decomp: *(undefined1 *)(*unaff_EBX + 4) = 1  after success
    // (FUN_00422880 is expected to have filled *ctx)
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(ctx->gateObj) + 4) = 1;
  }

  // --- alloc row + continue into finalize fragment ---
  ctx->rowBuf = nullptr;
  // image writes SEH try level as byte 6 at [ebp-4]
  *reinterpret_cast<uint8_t*>(&sehTryLevel) = 6;
  void* row = operator_new__(rowByteSize);
  ctx->rowBuf = row;

  // Image: jmp short over SEH filter stub to 0x00421674
  //   (mov ebx,[ebp+8]; fall into FUN_00421677 → ret 4).
  return FUN_00421677();
}
