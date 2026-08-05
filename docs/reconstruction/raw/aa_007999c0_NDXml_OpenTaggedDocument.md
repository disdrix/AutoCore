# Raw capture: NDXml_OpenTaggedDocument

| Field | Value |
|---|---|
| **Stable ID** | `aa_007999c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007999c0` |
| **Canonical name** | `NDXml_OpenTaggedDocument` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* NDXml_OpenTaggedDocument
   
   Open an XML document by file path with a tag/namespace string (e.g. "XML", "NDSpecialFX").
   Copies path into this+0x10, then NDXml_LoadDocumentFromPath.
   On success: load BSTR path into IXMLDOMDocument (vtable+0xdc) and query child count.
   
   Crash chain frame: often immediately above 0x007B6DB0.
   Params dump often show 0x00A9650C = "XML" for UI, or script name for FX. */

int __thiscall NDXml_OpenTaggedDocument(int param_1,char *param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int *piVar2;
  bool bVar3;
  char *pcVar4;
  void *pvVar5;
  void *this;
  BSTR bstrString;
  int iVar6;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b1404;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(void **)(param_1 + 0x10) != (void *)0x0) {
    ExceptionList = &pvStack_c;
    operator_delete__(*(void **)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  pcVar4 = param_2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pvVar5 = operator_new__((uint)(pcVar4 + (2 - (int)(param_2 + 1))));
  *(void **)(param_1 + 0x10) = pvVar5;
  iVar6 = (int)pvVar5 - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[iVar6] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  pcVar4 = *(char **)(param_1 + 0x10);
  pvVar5 = *(void **)(param_1 + 4);
  this = (void *)FUN_007b6a20();
  bVar3 = NDXml_LoadDocumentFromPath(this,pvVar5,pcVar4);
  if (bVar3) {
    if (param_4 == 0) {
      bstrString = (BSTR)0x0;
    }
    else {
      bstrString = (BSTR)FUN_004234e0(param_4,0xffffffff);
      if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_004048e0(0x8007000e);
      }
    }
    iVar6 = (**(code **)(**(int **)(param_1 + 4) + 0xdc))
                      (*(int **)(param_1 + 4),bstrString,(undefined4 *)(param_1 + 8));
    if (iVar6 == 0) {
      piVar2 = *(int **)(param_1 + 8);
      iVar6 = (**(code **)(*piVar2 + 0x20))(piVar2,param_1 + 0xc);
    }
    if (*(int *)(param_1 + 0xc) < 1) {
      iVar6 = 1;
    }
    SysFreeString(bstrString);
    ExceptionList = unaff_ESI;
    return iVar6;
  }
  ExceptionList = puStack_8;
  return 1;
}
```

---

## v2026-07-29 dual A/B append (do not alter body above)

Live Ghidra re-decompile @ `0x007999c0` **≡** authoritative raw body (same CF).

| Fact | Evidence |
|---|---|
| Body range | `get_function_by_address` → `007999c0`–`00799ae0` |
| Epilogue | `read_memory` tail: **`C2 08 00`** (`RET 8`) on success and fail |
| ABI | `__thiscall(this, pszPath, pszTag)` — decompiler `param_3` is SEH phantom |
| Entry | `8B F1` (`mov esi, ecx`); path via stack; tag via stack |
| Call sites | UI push `"XML"`@`00a9650c`; FX push `"NDSpecialFX"`@`009ca178`; then path; `lea ecx, this` |
| Callees | `FUN_007b6a20`, `NDXml_LoadDocumentFromPath`, `new[]`/`delete[]`, `FUN_004234e0`, `FUN_004048e0`, `SysFreeString` |
| Callers (6) | `NDUIWindow_InitFromInterfaceXml`, `NDSpecialFX_LoadFromScriptName`, `FUN_004a6390`, `FUN_004a6670`, `FUN_00547920`, `FUN_005abba0` |

Dual reviews: `reviews/A_aa_007999c0_NDXml_OpenTaggedDocument.md`, `reviews/B_aa_007999c0_NDXml_OpenTaggedDocument.md`.
