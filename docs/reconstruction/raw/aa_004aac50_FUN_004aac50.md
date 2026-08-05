# Raw capture: FUN_004aac50

| Field | Value |
|---|---|
| **Stable ID** | `aa_004aac50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004aac50` |
| **Canonical name** | `FUN_004aac50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004aac50(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_150;
  void *local_14c;
  float local_148;
  float local_144;
  undefined1 local_140 [4];
  undefined **local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined1 local_110 [260];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a12e0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_14c = operator_new(8);
  local_4 = 0;
  if (local_14c == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0096f530();
  }
  *(undefined4 *)(param_1 + 0x394) = uVar1;
  local_4 = 0xffffffff;
  FUN_00989e00(local_140,"NDDiffTerrainLayered.fx");
  FUN_009701d0(local_140);
  FUN_004a8fd0(*(undefined1 *)(param_1 + 0x1c),local_110);
  local_13c = &PTR_FUN_009caec8;
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0x101;
  local_128 = 1;
  local_124 = 0;
  local_120 = DAT_00aaa688;
  local_11c = 0;
  local_118 = 1;
  local_4 = 1;
  local_114 = 6;
  FUN_0096ef70();
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00989e00(&local_14c,local_110);
  iVar2 = FUN_0096f3e0(&local_14c,&local_13c);
  if (-1 < iVar2) {
    FUN_00970140("DiffuseTexture",local_150);
    local_148 = (float)*(int *)(param_1 + 0x10) * *(float *)(param_1 + 0x18);
    local_144 = (float)*(int *)(param_1 + 0x14) * *(float *)(param_1 + 0x18);
    FUN_00442640("fEdgeMaxX",&local_148);
    FUN_00442640("fEdgeMaxZ",&local_144);
    *(undefined1 *)(param_1 + 0x398) = 1;
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0096efd0();
  ExceptionList = local_c;
  return;
}
```
