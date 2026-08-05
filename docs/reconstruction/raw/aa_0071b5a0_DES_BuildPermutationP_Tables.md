# Raw capture: DES_BuildPermutationP_Tables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071b5a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071b5a0` |
| **Canonical name** | `DES_BuildPermutationP_Tables` |
| **Prior scaffold** | `FUN_0071b5a0` |
| **System** | auth |
| **Capture timestamp** | `2026-07-23` (scaffold); live re-verify `2026-07-29` W19-Q |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Integrity** | Do not overwrite the original raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile — 2026-07-23 capture; live ≡ 2026-07-29)

```c
void FUN_0071b5a0(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int local_c;
  uint local_8;
  int local_4;
  
  puVar7 = &DAT_00d11658;
  for (iVar3 = 0x400; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_4 = 0;
  local_c = 0;
  do {
    uVar4 = 0;
    do {
      local_8 = 0;
      uVar6 = 3;
      uVar8 = 2;
      uVar5 = 1;
      do {
        uVar2 = (int)*(char *)(uVar5 + 0xafcd47) - 1;
        if (((int)uVar2 >> 3 == local_4) &&
           ((*(uint *)(&DAT_00afcd68 + (uVar2 & 7) * 4) & uVar4) != 0)) {
          pbVar1 = (byte *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)local_8 >> 3));
          *pbVar1 = *pbVar1 | (&DAT_00afcd68)[(local_8 & 7) * 4];
        }
        if (((int)((int)(char)(&DAT_00afcd48)[uVar5] - 1U) >> 3 == local_4) &&
           ((*(uint *)(&DAT_00afcd68 + ((int)(char)(&DAT_00afcd48)[uVar5] - 1U & 7) * 4) & uVar4) !=
            0)) {
          pbVar1 = (byte *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)uVar5 >> 3));
          *pbVar1 = *pbVar1 | (&DAT_00afcd68)[(uVar5 & 7) * 4];
        }
        if (((int)((int)(char)(&DAT_00afcd48)[uVar8] - 1U) >> 3 == local_4) &&
           ((*(uint *)(&DAT_00afcd68 + ((int)(char)(&DAT_00afcd48)[uVar8] - 1U & 7) * 4) & uVar4) !=
            0)) {
          pbVar1 = (byte *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)uVar8 >> 3));
          *pbVar1 = *pbVar1 | (&DAT_00afcd68)[(uVar8 & 7) * 4];
        }
        if (((int)((int)(char)(&DAT_00afcd48)[uVar6] - 1U) >> 3 == local_4) &&
           ((*(uint *)(&DAT_00afcd68 + ((int)(char)(&DAT_00afcd48)[uVar6] - 1U & 7) * 4) & uVar4) !=
            0)) {
          pbVar1 = (byte *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)uVar6 >> 3));
          *pbVar1 = *pbVar1 | (&DAT_00afcd68)[(uVar6 & 7) * 4];
        }
        local_8 = local_8 + 4;
        uVar5 = uVar5 + 4;
        uVar8 = uVar8 + 4;
        uVar6 = uVar6 + 4;
      } while ((int)uVar5 < 0x21);
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 0x100);
    local_c = local_c + 0x100;
    local_4 = local_4 + 1;
  } while (local_c < 0x400);
  return;
}
```

---

## Live re-verify — 2026-07-29 (W19-Q dual seal)

| Check | Result |
|---|---|
| `decompile_function` @ `0x0071b5a0` | **Byte-identical body** to raw above |
| Entry `read_memory` @ `0x0071b5a0` len 80 | `83 ec 0c 53 55 56 57 33 c0 33 db b9 00 04 00 00 bf 58 16 d1 00 f3 ab ...` — `rep stosd` clear of **0x400** dwords at `DAT_00d11658` |
| `read_memory` @ `0x00afcd48` len 32 | FIPS DES **P** (1-based): `10 07 14 15 1d 0c 1c 11 01 0f 17 1a 05 12 1f 0a 02 08 18 0e 20 1b 03 09 13 0d 1e 06 16 0b 04 19` |
| `read_memory` @ `0x00afcd68` | Bit masks dwords: `0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01` |
| `read_memory` @ `0x00d11658` len 64 | **All zero** (BSS / runtime-filled) |
| Xrefs | Sole caller: `DES_InitializeCipher` @ `0x0071c070` |
