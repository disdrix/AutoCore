# Raw capture: Creature_GetPerception

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c41c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c41c0`–`0x004c428e` |
| **Canonical name** | `Creature_GetPerception` |
| **Ghidra name** | `FUN_004c41c0` |
| **System** | `skills-abilities` / character stats |
| **Capture timestamp** | `2026-07-29` (W18-H dual A/B) |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Body matches scaffold `aa_004c41c0_FUN_004c41c0.md` (2026-07-23) + live re-verify |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_004c41c0(int param_1)

{
  short sVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  
  sVar1 = *(short *)(param_1 + 0x142);
  sVar3 = sVar1;
  if (199 < sVar1) {
    sVar3 = 200;
  }
  if ((int)sVar3 + (int)*(short *)(param_1 + 0x14a) < 0xfa) {
    if (199 < sVar1) {
      sVar1 = 200;
    }
    iVar4 = (int)sVar1 + (int)*(short *)(param_1 + 0x14a);
  }
  else {
    iVar4 = 0xfa;
  }
  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1dc))();
  if ((int)((-(uint)(iVar2 != 0) & 0x65) - 100) < iVar4) {
    sVar1 = *(short *)(param_1 + 0x142);
    sVar3 = sVar1;
    if (199 < sVar1) {
      sVar3 = 200;
    }
    if ((int)sVar3 + (int)*(short *)(param_1 + 0x14a) < 0xfa) {
      if (199 < sVar1) {
        sVar1 = 200;
      }
      return (int)sVar1 + (int)*(short *)(param_1 + 0x14a);
    }
    return 0xfa;
  }
  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1dc))();
  return (-(uint)(iVar4 != 0) & 0x65) - 100;
}
```

---

## Byte seal (read_memory)

| Region | Bytes / note |
|---|---|
| Entry | `56 8B F1` push esi; mov esi,ecx |
| Base load | `66 8B 86 42 01 00 00` mov ax,[esi+0x142] |
| Cap 200 | `66 3D C8 00` / `BA C8 00 00 00` |
| Bonus | `0F BF 8E 4A 01 00 00` movsx ecx,[esi+0x14a] |
| Cap 250 | `81 FA FA 00 00 00` / `BF FA 00 00 00` |
| Vtbl call | `FF 92 DC 01 00 00` call [edx+0x1DC] |
| thr encode | `F7 D8 1B C0 83 E0 65 83 C0 9C` (= add -100) |
| Tail | score RETs + thr RET + `CC` pad; body end `0x004c428e` |

