# Raw capture: Client_EncryptAndPrepareAuthRequest

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728e50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00728e50` |
| **Canonical name** | `Client_EncryptAndPrepareAuthRequest` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4
Client_EncryptAndPrepareAuthRequest
          (int param_1,char *param_2,char *param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  char *pcVar4;
  undefined4 uVar5;
  void *pvVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  undefined1 local_4c [16];
  undefined1 local_3c [16];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 uStack_1e;
  undefined2 local_1c;
  undefined2 uStack_1a;
  undefined2 local_18;
  undefined2 uStack_16;
  undefined2 local_14;
  undefined2 uStack_12;
  undefined2 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Prepares credentials for EMSG_Login_Request. Encrypts username (14 bytes) and
                       password (16 bytes) in 8-byte blocks using standard DES in ECB mode with key
                       'TEST\0\0\0\0'. Note that only the first 24 bytes of the 30-byte credentials
                       buffer are encrypted (Block 0: 0..7, Block 1: 8..15, Block 2: 16..23),
                       leaving the last 6 bytes of the password unencrypted. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009af56c;
  local_c = ExceptionList;
  iVar9 = 0;
  if ((*(int **)(param_1 + 0x30) == (int *)0x0) || (**(int **)(param_1 + 0x30) == -1)) {
    ExceptionList = &local_c;
    FUN_0046e280(local_4c);
    local_4 = 1;
    bVar3 = false;
    bVar2 = true;
  }
  else {
    ExceptionList = &local_c;
    FUN_0067ba30(local_3c);
    local_4 = 0;
    bVar3 = true;
    bVar2 = false;
  }
  FUN_00727c00("Login","AuthServer");
  local_4 = 0;
  if (bVar2) {
    FUN_0067b110();
  }
  local_4 = 0xffffffff;
  if (bVar3) {
    FUN_0067b110();
  }
  if ((((param_2 == (char *)0x0) || (*param_2 == '\0')) || (param_3 == (char *)0x0)) ||
     (*param_3 == '\0')) {
    uVar5 = FUN_0076cec0(&param_5,"Invalid name or password");
    uVar10 = 0xc4;
  }
  else {
    pcVar4 = param_2;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if ((int)pcVar4 - (int)(param_2 + 1) < 0xf) {
      pcVar4 = param_3;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      if ((int)pcVar4 - (int)(param_3 + 1) < 0x11) {
        pvVar6 = operator_new(0x38);
        local_4 = 2;
        if (pvVar6 != (void *)0x0) {
          iVar9 = FUN_0071e420();
        }
        local_4 = 0xffffffff;
        local_2c = 0;
        local_28 = 0;
        local_24 = 0;
        local_20 = 0;
        uStack_1e = 0;
        local_1c = 0;
        uStack_1a = 0;
        local_18 = 0;
        uStack_16 = 0;
        local_14 = 0;
        uStack_12 = 0;
        local_10 = 0;
        strncpy((char *)&local_2c,param_2,0xe);
        uStack_1e = (undefined2)*(undefined4 *)param_3;
        local_1c = (undefined2)((uint)*(undefined4 *)param_3 >> 0x10);
        uStack_1a = (undefined2)*(undefined4 *)(param_3 + 4);
        local_18 = (undefined2)((uint)*(undefined4 *)(param_3 + 4) >> 0x10);
        uStack_16 = (undefined2)*(undefined4 *)(param_3 + 8);
        local_14 = (undefined2)((uint)*(undefined4 *)(param_3 + 8) >> 0x10);
        uStack_12 = (undefined2)*(undefined4 *)(param_3 + 0xc);
        local_10 = (undefined2)((uint)*(undefined4 *)(param_3 + 0xc) >> 0x10);
        puVar8 = &local_2c;
        iVar7 = 3;
        do {
          DES_EncryptBlock8(puVar8);
          puVar8 = puVar8 + 2;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        *(undefined4 *)(iVar9 + 0x10) = local_2c;
        *(undefined4 *)(iVar9 + 0x14) = local_28;
        *(undefined4 *)(iVar9 + 0x18) = local_24;
        *(undefined2 *)(iVar9 + 0x1c) = local_20;
        *(uint *)(iVar9 + 0x1e) = CONCAT22(local_1c,uStack_1e);
        *(uint *)(iVar9 + 0x22) = CONCAT22(local_18,uStack_1a);
        *(uint *)(iVar9 + 0x26) = CONCAT22(local_14,uStack_16);
        *(uint *)(iVar9 + 0x2a) = CONCAT22(local_10,uStack_12);
        *(undefined4 *)(iVar9 + 0x30) = param_4;
        *(undefined2 *)(iVar9 + 0x34) = (undefined2)param_5;
        param_5 = iVar9;
        FUN_0046ebf0();
        ExceptionList = local_c;
        return 0;
      }
      uVar5 = FUN_0076cec0(&param_5,"Password string too long");
      uVar10 = 0xd2;
    }
    else {
      uVar5 = FUN_0076cec0(&param_5,"Username string too long");
      uVar10 = 0xcb;
    }
  }
  vog_LogMessage("C:\\vog\\1_code\\palantir\\infrastruct\\Auth\\authClientLib\\AuthClientImpl.cpp",
                 uVar10,3,uVar5);
  ExceptionList = local_c;
  return 0xffffffff;
}
```
