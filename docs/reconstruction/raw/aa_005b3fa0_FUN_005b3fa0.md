# Raw capture: FUN_005b3fa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3fa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b3fa0` |
| **Canonical name** | `FUN_005b3fa0` |
| **System** | host object / list populate worker |
| **Capture timestamp** | `2026-08-04` |
| **Tool** | Ghidra MCP `batch_decompile` / `decompile_function` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall
FUN_005b3fa0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,float param_5,
            int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  int local_1dc;
  int local_1cc;
  int local_1c8;
  float local_1c4;
  float local_1c0;
  float local_1b8;
  int local_1ac;
  float local_1a8;
  int local_1a4;
  float local_1a0;
  undefined4 local_19c;
  float local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  uint local_188;
  undefined4 local_184;
  uint local_178;
  undefined4 local_174;
  float local_158;
  float local_150;
  float local_14c;
  float local_144;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a684b;
  local_1c = ExceptionList;
  if (param_6 != 0) {
    ExceptionList = &local_1c;
    *(undefined4 *)(param_1 + 0x20) = param_2;
    *(undefined4 *)(param_1 + 0x24) = param_4;
    *(undefined4 *)(param_1 + 0x28) = param_3;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    local_1a4 = param_1;
    FUN_004f1e20(1,1);
    FUN_00764030();
    local_14 = 0;
    uVar2 = FUN_004eb1c0(&local_1c8);
    iVar3 = FUN_00764830(uVar2);
    if (-1 < iVar3) {
      fVar6 = local_14c - local_158;
      local_1c4 = local_144 - local_150;
      local_1c8 = (int)ROUND(fVar6);
      local_1ac = (int)ROUND(local_1c4);
      fVar7 = local_1c4 * DAT_00a0f298;
      local_14 = 0xffffffff;
      local_1a8 = fVar7;
      FUN_00763f60();
      local_1c0 = fVar6 * DAT_00a0f298;
      iVar3 = (int)ROUND(*(float *)(param_1 + 0x20) * param_5);
      iVar1 = (int)ROUND(*(float *)(param_1 + 0x28) * param_5);
      local_1dc = 0;
      local_1b8 = fVar7;
      if (0 < iVar3) {
        do {
          local_1cc = 0;
          iVar5 = param_1;
          if (0 < iVar1) {
            local_178 = local_178 & 0xffffff00;
            local_18c = 0xffffffff;
            local_19c = param_4;
            local_194 = 0;
            local_190 = 0xffffffff;
            local_188 = local_178;
            local_184 = local_174;
            local_1a0 = local_1c0;
            do {
              iVar5 = *(int *)(param_1 + 0x14);
              local_198 = local_1b8;
              iVar4 = FUN_005b4470(iVar5,*(undefined4 *)(iVar5 + 4),&local_1a0);
              FUN_005b43d0(1);
              local_1cc = local_1cc + local_1ac;
              local_1b8 = local_1b8 + local_1c4;
              *(int *)(iVar5 + 4) = iVar4;
              **(int **)(iVar4 + 4) = iVar4;
              iVar5 = local_1a4;
            } while (local_1cc < iVar1);
          }
          local_1dc = local_1dc + local_1c8;
          local_1c0 = local_1c0 + fVar6;
          local_1b8 = local_1a8;
          param_1 = iVar5;
        } while (local_1dc < iVar3);
      }
      FUN_004eb010();
      ExceptionList = local_1c;
      return 1;
    }
    FUN_004eb010();
    local_14 = 0xffffffff;
    FUN_00763f60();
  }
  ExceptionList = local_1c;
  return 0;
}
```

---

## Re-verify (W37-L OWN-ONLY dual) — 2026-08-04

| Field | Value |
|---|---|
| **Tools** | Ghidra `decompile_function` / `batch_decompile` + `analyze_function_complete` + `read_memory` + `get_function_by_address` + callers. **No** `disassemble_bytes`. |
| **Image** | `autoassault.exe` base `0x400000` |
| **Body** | `0x005b3fa0`–`0x005b4255` exclusive (**693** B / `0x2B5`); pad `CC` after `C2 14 00` |
| **ABI** | thiscall: **ECX = this**; five stack args; status in **AL/EAX**; **`ret 0x14`** |
| **Constant** | `DAT_00a0f298` = `0x3f000000` = **0.5f** (`read_memory`) |
| **Bytes notes** | `movss` store order: `+0x20←[ebp+8]`, `+0x24←[ebp+0x10]`, `+0x28←[ebp+0xC]`, `+0x2c←0`; list base `ADD EBX,0x10` before insert; early and final fail/success epilogues both `ret 0x14` |
| **Callees** | `FUN_004f1e20`, `FUN_00764030`, `FUN_004eb1c0`, `FUN_00764830`, `FUN_00763f60`, `FUN_005b4470`, `FUN_005b43d0`, `FUN_004eb010` |
| **Callers (2)** | `FUN_004cd8f0` @ `0x004cd97a`; `FUN_005b4260` @ `0x005b42cc` |
| **Semantic name** | `Obj_PopulateListAt10_ScaledGridFill_Inferred` |

### Full body hex (`read_memory` @ `0x005b3fa0`, 693 B)

```
558bec83e4f06aff684b689a0064a100000000506489250000000081ecc801000053568b751885f68bd957895c244c0f8483000000f30f104508f30f114320f30f104510f30f114324f30f10450c6a01f30f1143280f57c06a018bcef30f11432ce81adef3ff8d8c2480000000e81e001b008d442428508bcec78424e001000000000000e89771f3ff508d8c2484000000e8fa071b0085c07d378bcee8cf6ff3ff8d8c2480000000c78424dc010000ffffffffe808ff1a0032c08b8c24d401000064890d000000005f5e5b8be55dc21400f30f108424a4000000f30f5c842498000000f30f1144241cf30f108424ac000000f30f5c8424a0000000f30f1144242cd944241cdb5c2428d944242cdb5c2444f30f590598f2a0008d8c2480000000f30f11442418f30f11442448c78424dc010000ffffffffe884fe1a00f30f104c2418f30f1044241cf30f105320f30f590598f2a000f30f114c2438f30f104d14f30f59d1f30f11442430f30f11542414d9442414db5c2418f30f105328f30f59d1f30f11542414d9442414db5c242033c039442418894424140f8ef6000000eb0ff30f10442430eb078da42400000000837c242000c7442424000000000f8ea80000008b54247c83c9fff30f11442450f30f10451083c8ffc644247800894c24648b4c2478f30f114424540f57c0f30f1144245c89442460894c24688954246c83c3108b73048b4e04f30f104424388d4424505051568bcbf30f11442464e8ad0200006a018bcb8bf8e8020200008b44242403442444f30f104424383b442420f30f5844242c897e048b5704893af30f11442438894424247ca9f30f104424308b4424148b75188b5c244c03442428f30f5844241c3b442418f30f11442430f30f10442448f30f11442438894424140f8c0cffffff8bcee8d46df3ff8b8c24d40100005f5eb00164890d000000005b8be55dc21400
```
