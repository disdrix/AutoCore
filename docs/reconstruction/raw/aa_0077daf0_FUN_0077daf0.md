# Raw capture: FUN_0077daf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077daf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0077daf0` |
| **Canonical name** | `FUN_0077daf0` / structural `BitStream_readString` |
| **System** | net / TNL BitStream string |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0077daf0(int param_1)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int unaff_ESI;
  uint uVar4;
  int iVar5;
  uint local_4;
  
  if (DAT_00d17a28 == '\0') {
    FUN_0077d520();
  }
  uVar4 = *(uint *)(unaff_ESI + 0x18);
  if (*(uint *)(unaff_ESI + 0x2c) < uVar4) {
    *(undefined1 *)(unaff_ESI + 0x1c) = 1;
  }
  else {
    bVar1 = *(byte *)((uVar4 >> 3) + *(int *)(unaff_ESI + 0xc));
    *(uint *)(unaff_ESI + 0x18) = uVar4 + 1;
    if ((bVar1 & (byte)(1 << ((byte)uVar4 & 7))) != 0) {
      uVar4 = 0;
      local_4 = 0;
      BitStream_readBits(8,&local_4);
      local_4 = local_4 & 0xff;
      if (local_4 != 0) {
        do {
          iVar5 = 0;
          do {
            uVar3 = *(uint *)(unaff_ESI + 0x18);
            if (*(uint *)(unaff_ESI + 0x2c) < uVar3) {
              *(undefined1 *)(unaff_ESI + 0x1c) = 1;
LAB_0077dba3:
              sVar2 = *(short *)(DAT_00d1eab0 + 4 + iVar5 * 8);
            }
            else {
              bVar1 = *(byte *)((uVar3 >> 3) + *(int *)(unaff_ESI + 0xc));
              *(uint *)(unaff_ESI + 0x18) = uVar3 + 1;
              if ((bVar1 & (byte)(1 << ((byte)uVar3 & 7))) == 0) goto LAB_0077dba3;
              sVar2 = *(short *)(DAT_00d1eab0 + 6 + iVar5 * 8);
            }
            iVar5 = (int)sVar2;
          } while (-1 < iVar5);
          *(undefined1 *)(param_1 + uVar4) = *(undefined1 *)(DAT_00d1eabc + iVar5 * -0xc + -7);
          uVar4 = uVar4 + 1;
        } while (uVar4 < local_4);
      }
      *(undefined1 *)(local_4 + param_1) = 0;
      return 1;
    }
  }
  local_4 = 0;
  BitStream_readBits(8,&local_4);
  uVar4 = local_4 & 0xff;
  BitStream_readBits(uVar4 * 8,param_1);
  *(undefined1 *)(uVar4 + param_1) = 0;
  return 1;
}
```

---

## Live re-decompile (W20-K dual seal 2026-07-29)

**Tool:** Ghidra MCP `decompile_function` @ `0x0077daf0` program `autoassault.exe`  
**Also:** `read_memory` body `0x0077daf0` length 550; globals `DAT_00d17a28`, `DAT_00d1eab0`, `DAT_00d1eabc` (BSS zeros in static image); freq seed `@0x00a1ea68` (partial non-zero)  
**Body range:** `0x0077daf0`–`0x0077dc13` (`get_function_by_address`)  
**Xrefs to:** `0x0042baa6`, `0x0042bb12` in `BitStream_readStringCached` (`FUN_0042ba90`) only  
**Live CF:** **≡** 2026-07-23 raw (cosmetic surface only)

### Live byte seals (entry / dual epilogues)

| Site | Hex | Meaning |
|---|---|---|
| entry | `51 80 3D 28 7A D1 00 00` | PUSH ECX; CMP byte `[DAT_00d17a28],0` |
| stack dest | `8B 5C 24 0C` | MOV EBX,`[ESP+0C]` → stack `char* out` |
| ESI this | uses `[ESI+0x18]`/`[ESI+0x2c]`/`[ESI+0xc]` without load | **ESI = BitStream\*** (caller convention) |
| Huffman epilogue | `C6 04 18 00 5F B0 01 5B 59 C3` | NUL-term; MOV AL,1; POP*; **RET** |
| Raw epilogue | `C6 04 1F 00 5F B0 01 5B 59 C3` | same **RET** (caller cleans 4) |
| tree ptr | `A1 B0 EA D1 00` | MOV EAX,`[DAT_00d1eab0]` |
| alpha ptr | `8B 15 BC EA D1 00` | MOV EDX,`[DAT_00d1eabc]` |

### Live pseudocode

Identical to authoritative block above (re-decompile 2026-07-29).
