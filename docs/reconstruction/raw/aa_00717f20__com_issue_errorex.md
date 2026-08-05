# Raw capture: _com_issue_errorex

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717f20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717f20` |
| **Canonical name** | `_com_issue_errorex` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Library Function - Single Match
    void __stdcall _com_issue_errorex(long,struct IUnknown *,struct _GUID const &)
   
   Library: Visual Studio 2003 Debug */

void _com_issue_errorex(long param_1,IUnknown *param_2,_GUID *param_3)

{
  HRESULT HVar1;
  int iVar2;
  IErrorInfo *local_c;
  int *local_8;
  
  local_c = (IErrorInfo *)0x0;
  if ((param_2 != (IUnknown *)0x0) &&
     (HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_00a14020,&local_8), -1 < HVar1)
     ) {
    iVar2 = (**(code **)(*local_8 + 0xc))(local_8,param_3);
    (**(code **)(*local_8 + 8))(local_8);
    if ((iVar2 == 0) && (HVar1 = GetErrorInfo(0,&local_c), HVar1 != 0)) {
      local_c = (IErrorInfo *)0x0;
    }
  }
  (*(code *)PTR_FUN_00af8b20)(param_1,local_c);
  return;
}
```
