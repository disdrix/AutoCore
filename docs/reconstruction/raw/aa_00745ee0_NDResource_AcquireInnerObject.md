# Raw capture: NDResource_AcquireInnerObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00745ee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00745ee0` |
| **Canonical name** | `NDResource_AcquireInnerObject` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* NDResource_AcquireInnerObject  (thiscall)
   
   Bump refcount at this+0x10, optionally take critical section (this+0x20).
   If this+0x8 is null, Release this via vtable+8.
   Returns pointer at this+8 (inner resource).
   
   Caller NDXml_LoadDocumentFromPath then does:
     inner = AcquireInnerObject()
     iface = *(inner+4)
     iface->Release()   // crash PC 0x007B6DB0 when iface/vtable stale */

int __fastcall NDResource_AcquireInnerObject(int *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  float10 fVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ac157;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 8);
  ExceptionList = &pvStack_c;
  if ((char)param_1[0xe] != '\0') {
    ExceptionList = &pvStack_c;
    EnterCriticalSection(lpCriticalSection);
  }
  local_4 = 0;
  param_1[4] = param_1[4] + 1;
  fVar2 = (float10)FUN_0076c330();
  param_1[7] = (int)(float)fVar2;
  if ((char)param_1[0xe] != '\0') {
    EnterCriticalSection(lpCriticalSection);
  }
  iVar1 = param_1[2];
  if ((char)param_1[0xe] != '\0') {
    LeaveCriticalSection(lpCriticalSection);
  }
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 8))();
  }
  iVar1 = param_1[2];
  if ((char)param_1[0xe] != '\0') {
    LeaveCriticalSection(lpCriticalSection);
  }
  ExceptionList = pvStack_c;
  return iVar1;
}
```

---

## Live re-decompile append (2026-07-29)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` x3 + `read_memory` + callers/xrefs |
| **Integrity** | Authoritative 2026-07-23 body above unchanged; this section is versioned corroboration |
| **Three-rep stability** | All three decompiles identical to raw body |
| **Body range** | `0x00745ee0`-`0x00745f70` |
| **Xrefs** | 18 `UNCONDITIONAL_CALL` |
| **Dual A/B** | `reviews/A_aa_00745ee0_NDResource_AcquireInnerObject.md`, `reviews/B_aa_00745ee0_NDResource_AcquireInnerObject.md` |

### Byte notes (sealed)

- `add dword [esi+0x10],1` — refcount++
- `call FUN_0076c330` / `fstp dword [esi+0x1c]` — float last-touch (decompiler `(int)(float)` is FPU store noise)
- Lock flag `byte [esi+0x38]`; CS at `esi+0x20`
- Nested Enter x2 / Leave x2 when flag set (Enter IAT `0x009c61bc`, Leave IAT `0x009c61b8`)
- Null-inner: `call [vtbl+8]` then re-load `[esi+8]`; return EAX = inner
- Plain `ret` (no stack args)

### Live pseudocode (rep 1-3, identical)

Same control flow as authoritative raw block above (`NDResource_AcquireInnerObject` @ `0x00745ee0`).