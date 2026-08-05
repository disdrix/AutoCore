# Raw capture: FUN_007ed3b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ed3b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ed3b0` |
| **Canonical name** | `FUN_007ed3b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x007edab6) */
/* WARNING: Removing unreachable block (ram,0x007eda48) */
/* WARNING: Removing unreachable block (ram,0x007ed9da) */
/* WARNING: Removing unreachable block (ram,0x007ed971) */
/* WARNING: Removing unreachable block (ram,0x007ed8fb) */
/* WARNING: Removing unreachable block (ram,0x007ed888) */
/* WARNING: Removing unreachable block (ram,0x007ed840) */
/* WARNING: Removing unreachable block (ram,0x007ed862) */
/* WARNING: Removing unreachable block (ram,0x007ed88e) */
/* WARNING: Removing unreachable block (ram,0x007ed8c5) */
/* WARNING: Removing unreachable block (ram,0x007ed8cb) */
/* WARNING: Removing unreachable block (ram,0x007ed901) */
/* WARNING: Removing unreachable block (ram,0x007ed936) */
/* WARNING: Removing unreachable block (ram,0x007ed93c) */
/* WARNING: Removing unreachable block (ram,0x007ed977) */
/* WARNING: Removing unreachable block (ram,0x007ed9a4) */
/* WARNING: Removing unreachable block (ram,0x007ed9aa) */
/* WARNING: Removing unreachable block (ram,0x007ed9e0) */
/* WARNING: Removing unreachable block (ram,0x007eda11) */
/* WARNING: Removing unreachable block (ram,0x007eda17) */
/* WARNING: Removing unreachable block (ram,0x007eda4e) */
/* WARNING: Removing unreachable block (ram,0x007eda7f) */
/* WARNING: Removing unreachable block (ram,0x007eda85) */
/* WARNING: Removing unreachable block (ram,0x007edabc) */
/* WARNING: Removing unreachable block (ram,0x007edad8) */

int __thiscall FUN_007ed3b0(char *param_1,int *param_2,undefined4 param_3,undefined2 *param_4)

{
  int iVar1;
  undefined2 uStack_190;
  undefined1 uStack_18b;
  undefined1 uStack_18a;
  undefined1 uStack_189;
  int *piStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  wchar_t *pwStack_17c;
  undefined4 uStack_178;
  int iStack_174;
  undefined4 uStack_170;
  undefined4 *puStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  int iStack_158;
  BSTR pOStack_154;
  undefined2 uStack_150;
  undefined2 uStack_14c;
  undefined2 uStack_148;
  undefined2 uStack_144;
  undefined2 uStack_140;
  wchar_t awStack_13c [20];
  wchar_t awStack_114 [66];
  wchar_t awStack_90 [66];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b0db4;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    return -0x7fffbffc;
  }
  ExceptionList = &local_c;
  iVar1 = FUN_007e59d0();
  if (-1 < iVar1) {
    iStack_158 = *param_2;
    if (DAT_00d1793c == '\0') {
      puStack_16c = &uStack_184;
      uStack_184 = 0;
      uStack_180 = 0;
      pwStack_17c = (wchar_t *)0x0;
      uStack_178 = 0;
      iStack_174 = 0;
      uStack_170 = 0;
      uStack_164 = 0;
      uStack_168 = 0;
      uStack_160 = 0;
      uStack_15c = 0;
      uStack_4 = 0;
      FUN_004230d0();
      iVar1 = FUN_00422fb0();
      if (-1 < iVar1) {
        iVar1 = FUN_0041a810(&uStack_184,param_1 + 0x28,0,0);
      }
      pwStack_17c = awStack_114;
      if (((((iVar1 < 0) || (iVar1 = FUN_004231d0(), iVar1 < 0)) ||
           (iVar1 = FUN_004231d0(), iVar1 < 0)) ||
          (((iVar1 = FUN_004231d0(), iVar1 < 0 || (iVar1 = FUN_004231d0(), iVar1 < 0)) ||
           ((iVar1 = FUN_004231d0(), iVar1 < 0 ||
            ((iVar1 = FUN_004231d0(), iVar1 < 0 || (iVar1 = FUN_004231d0(), iVar1 < 0)))))))) ||
         ((iVar1 = FUN_004231d0(), iVar1 < 0 ||
          ((((iVar1 = FUN_004231d0(), iVar1 < 0 || (iVar1 = FUN_004231d0(), iVar1 < 0)) ||
            (iVar1 = FUN_004231d0(), iVar1 < 0)) || (iStack_174 == 0)))))) {
        FUN_00423170();
        FUN_007a4480(1);
      }
      else {
        iVar1 = FUN_0041a9b0();
        if (iVar1 != 0) {
          FUN_0041a990();
          FUN_00423170();
          FUN_007a4480(1);
          uStack_4 = 0xffffffff;
          FUN_0041a3e0();
          ExceptionList = local_c;
          return 0;
        }
        *(undefined1 *)(param_4 + 7) = uStack_189;
        *(undefined1 *)(param_4 + 6) = uStack_18b;
        *(undefined1 *)((int)param_4 + 0xd) = uStack_18a;
        wcscpy(param_4 + 8,awStack_114);
        wcscpy(param_4 + 0x49,awStack_90);
        *param_4 = uStack_148;
        param_4[1] = uStack_140;
        param_4[2] = uStack_150;
        param_4[3] = uStack_14c;
        param_4[4] = uStack_144;
        param_4[5] = uStack_190;
        FUN_0041a990();
        FUN_00423170();
      }
      uStack_4 = 0xffffffff;
      FUN_0041a3e0();
    }
    else {
      FUN_00423670();
      uStack_4 = 1;
      _itow(iStack_158,awStack_13c,10);
      FUN_00422eb0();
      lstrlenW(L"\']");
      iVar1 = FUN_00422ee0();
      if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_004048e0();
      }
      FUN_00419ca0();
      uStack_4._0_1_ = 2;
      if (DAT_00d1e56c == 0) {
        _com_issue_error(-0x7fffbffd);
      }
      uStack_4._0_1_ = 1;
      FUN_00419ed0();
      uStack_4 = CONCAT31(uStack_4._1_3_,4);
      if (piStack_188 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      iVar1 = FUN_00419ff0();
      if (0 < iVar1) {
        if (piStack_188 == (int *)0x0) {
          _com_issue_error(-0x7fffbffd);
        }
        (**(code **)(*piStack_188 + 0x1c))();
      }
      uStack_4 = CONCAT31(uStack_4._1_3_,1);
      if (piStack_188 != (int *)0x0) {
        (**(code **)(*piStack_188 + 8))();
      }
      SysFreeString(pOStack_154);
    }
    ExceptionList = local_c;
    return 0;
  }
  ExceptionList = local_c;
  return iVar1;
}
```
