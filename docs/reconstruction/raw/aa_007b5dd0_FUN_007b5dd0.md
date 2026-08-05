# Raw capture: FUN_007b5dd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b5dd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007b5dd0` |
| **Canonical name** | `FUN_007b5dd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_007b5dd0(undefined4 *param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b327c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00759860();
  local_4 = 0;
  *param_1 = &PTR_FUN_00a960ac;
  puVar4 = param_1 + 0x41;
  iVar5 = 3;
  do {
    *(undefined1 *)((int)puVar4 + 2) = 0xff;
    *(undefined1 *)((int)puVar4 + 1) = 0xff;
    *(undefined1 *)puVar4 = 0xff;
    *(undefined1 *)((int)puVar4 + 3) = 0xff;
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined1 *)((int)param_1 + 0x1e6) = 0xff;
  *(undefined1 *)((int)param_1 + 0x1e5) = 0xff;
  *(undefined1 *)(param_1 + 0x79) = 0xff;
  *(undefined1 *)((int)param_1 + 0x1e7) = 0xff;
  param_1[0x7a] = &PTR_FUN_00a964ac;
  param_1[0x82] = 0;
  param_1[0x81] = 0;
  param_1[0x83] = 0;
  *(undefined1 *)(param_1 + 0x84) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7b));
  param_1[0x7a] = &PTR_FUN_00a964b8;
  local_4 = CONCAT31(local_4._1_3_,1);
  puVar4 = param_1 + 0x8a;
  iVar5 = 3;
  do {
    *(undefined1 *)((int)puVar4 + 2) = 0xff;
    *(undefined1 *)((int)puVar4 + 1) = 0xff;
    *(undefined1 *)puVar4 = 0xff;
    *(undefined1 *)((int)puVar4 + 3) = 0xff;
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  _DAT_00d17954 = _DAT_00d17954 + 1;
  *(undefined1 *)(param_1 + 0x2e) = 0;
  *(undefined1 *)((int)param_1 + 0xb9) = 0;
  *(undefined1 *)((int)param_1 + 0xba) = 1;
  *(undefined1 *)(param_1 + 0x2f) = 0;
  *(undefined1 *)((int)param_1 + 0xbb) = 0;
  *(undefined1 *)((int)param_1 + 0xbd) = 0;
  *(undefined1 *)((int)param_1 + 0xbe) = 0;
  *(undefined1 *)((int)param_1 + 0xbf) = 0;
  *(undefined1 *)((int)param_1 + 0xc1) = 0;
  *(undefined1 *)((int)param_1 + 0xc2) = 0;
  *(undefined1 *)((int)param_1 + 0xc3) = 0;
  *(undefined1 *)(param_1 + 0x31) = 0;
  *(undefined1 *)((int)param_1 + 0xc5) = 0;
  *(undefined1 *)((int)param_1 + 0xc6) = 0;
  *(undefined1 *)((int)param_1 + 199) = 0;
  *(undefined1 *)(param_1 + 0x32) = 0;
  *(undefined1 *)((int)param_1 + 0xc9) = 1;
  *(undefined1 *)((int)param_1 + 0xca) = 1;
  *(undefined1 *)((int)param_1 + 0xcb) = 0;
  *(undefined1 *)(param_1 + 0x33) = 0;
  *(undefined1 *)((int)param_1 + 0xce) = 1;
  *(undefined1 *)((int)param_1 + 0xcd) = 0;
  *(undefined1 *)((int)param_1 + 0xcf) = 1;
  *(undefined1 *)(param_1 + 0x34) = 0;
  *(undefined1 *)((int)param_1 + 0xd1) = 0;
  *(undefined1 *)((int)param_1 + 0xd2) = 0;
  *(undefined1 *)((int)param_1 + 0xd3) = 0;
  *(undefined1 *)(param_1 + 0x35) = 0;
  *(undefined1 *)((int)param_1 + 0xd5) = 0;
  *(undefined1 *)((int)param_1 + 0xd6) = 0;
  *(undefined1 *)((int)param_1 + 0xd7) = 0;
  *(undefined1 *)(param_1 + 0x36) = 0;
  *(undefined1 *)((int)param_1 + 0xd9) = 1;
  *(undefined1 *)((int)param_1 + 0xda) = 0;
  param_1[0xac] = 0;
  param_1[0xa6] = 0;
  param_1[0xa5] = 0;
  param_1[0xad] = 0;
  param_1[0x9d] = 0;
  param_1[0x9e] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa9] = 0;
  param_1[0xaa] = 0;
  param_1[0xa2] = 0;
  param_1[0xa7] = 0;
  param_1[0xa8] = 0;
  puVar3 = operator_new(0x20);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_00afa268);
    _DAT_00afa270 = g_flOne / (float)_DAT_00afa268;
    QueryPerformanceCounter((LARGE_INTEGER *)(puVar3 + 0x10));
    QueryPerformanceCounter((LARGE_INTEGER *)(puVar3 + 0x18));
    *(undefined4 *)(puVar3 + 8) = 0;
    *puVar3 = 1;
    *(undefined4 *)(puVar3 + 0xc) = 0;
  }
  fVar1 = g_flOne;
  param_1[0xae] = puVar3;
  param_1[0x3b] = 0xffffffff;
  param_1[0x37] = 0xffffffff;
  param_1[0x39] = 0xffffffff;
  param_1[0x38] = 0xffffffff;
  param_1[0x47] = 0xffffffff;
  param_1[0x5c] = 0;
  param_1[0x3a] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x88] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x48] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5d] = 0;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  uVar2 = DAT_00afa130;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x67] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  *(undefined1 *)(param_1 + 0x72) = 0;
  param_1[0x75] = 0;
  param_1[0x73] = 0;
  param_1[0x76] = fVar1;
  param_1[0x74] = fVar1;
  *(undefined1 *)(param_1 + 0x77) = 0;
  param_1[0x78] = 1;
  param_1[0x79] = DAT_00afdf0c;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x4d] = uVar2;
  uVar2 = DAT_00a0f71c;
  param_1[0x4c] = fVar1;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = uVar2;
  param_1[0x51] = 0;
  param_1[0x3d] = 0;
  param_1[0x8f] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = fVar1;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  uVar2 = DAT_00aaa6fc;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  param_1[0x9c] = 0;
  param_1[0x86] = 0;
  param_1[0x85] = 0;
  param_1[0x87] = 4;
  param_1[0xa3] = 0;
  param_1[0xa4] = param_2;
  param_1[0x3d] = param_1[0x3d] | 1;
  param_1[0x89] = 0;
  param_1[0x8a] = _DAT_00d1e7a0;
  param_1[0x8b] = _DAT_00d1e7a4;
  param_1[0x8c] = _DAT_00d1e7d0;
  param_1[0xaf] = 0;
  param_1[0xb0] = uVar2;
  param_1[0xb1] = 0;
  *(undefined1 *)((int)param_1 + 0x2c9) = 1;
  *(undefined1 *)(param_1 + 0xb2) = 0;
  *(undefined1 *)((int)param_1 + 0x2ca) = 0;
  *(undefined1 *)((int)param_1 + 0x2cb) = 0;
  puVar4 = param_1 + 0xb6;
  iVar5 = 10;
  do {
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[-1] = 0;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[-2] = 0;
    *(undefined1 *)(puVar4 + -3) = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4 = puVar4 + 10;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar4 = param_1 + 0x117;
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  ExceptionList = local_c;
  return param_1;
}
```
