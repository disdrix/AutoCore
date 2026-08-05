# Raw capture: FUN_0098acc0 / NDAssetImage_FlipHorizontal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098acc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0098acc0` |
| **Body** | `0x0098acc0`–`0x0098ae77` |
| **Canonical name** | `NDAssetImage_FlipHorizontal` (sealed 2026-07-29 W20-L; prior scaffold `FUN_0098acc0`) |
| **System** | client assets / `NDAssetImage` (TGA origin normalize) |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0098acc0(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 *puVar9;
  int unaff_EDI;
  int local_10;
  
  if (*(int *)(unaff_EDI + 4) == 0) {
    return 0;
  }
  puVar2 = operator_new(0x1b8);
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  *puVar2 = &PTR_FUN_00a9bcac;
  FUN_004320d0();
  FUN_00432260(unaff_EDI,0,0,1);
  sVar1 = *(short *)(unaff_EDI + 0x16);
  iVar4 = ((uint)(sVar1 == 0x18) * 2 + 1) * (*(int *)(unaff_EDI + 0xc) + -1);
  iVar8 = puVar2[0xd];
  puVar5 = (undefined1 *)(*(int *)(unaff_EDI + 0x34) + iVar4);
  if (sVar1 == 8) {
    local_10 = 0;
    if (0 < *(int *)(unaff_EDI + 0x10)) {
      do {
        iVar6 = 0;
        puVar3 = puVar5;
        if (-1 < iVar4) {
          do {
            *(undefined1 *)(iVar6 + iVar8) = *puVar3;
            iVar6 = iVar6 + 1;
            puVar3 = puVar3 + -1;
          } while (iVar6 <= iVar4);
        }
        puVar5 = puVar5 + *(int *)(unaff_EDI + 0x30);
        iVar8 = iVar8 + *(int *)(unaff_EDI + 0x30);
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)(unaff_EDI + 0x10));
    }
  }
  else if (sVar1 == 0x18) {
    local_10 = 0;
    if (0 < *(int *)(unaff_EDI + 0x10)) {
      do {
        if (-1 < iVar4) {
          puVar3 = (undefined1 *)(iVar8 + 1);
          puVar9 = puVar5 + 2;
          uVar7 = (iVar4 + 3U) / 3;
          do {
            puVar3[-1] = puVar9[-2];
            *puVar3 = puVar9[-1];
            puVar3[1] = *puVar9;
            puVar3 = puVar3 + 3;
            puVar9 = puVar9 + -3;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        puVar5 = puVar5 + *(int *)(unaff_EDI + 0x30);
        iVar8 = iVar8 + *(int *)(unaff_EDI + 0x30);
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)(unaff_EDI + 0x10));
    }
  }
  else {
    iVar8 = 0;
    if (0 < *(int *)(unaff_EDI + 0x10)) {
      do {
        iVar6 = 0;
        if (-1 < iVar4) {
          do {
            FUN_00433530();
            FUN_004337d0(iVar8);
            iVar6 = iVar6 + 1;
          } while (iVar6 <= iVar4);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(unaff_EDI + 0x10));
    }
  }
  FUN_00433390();
  FUN_00432580(unaff_EDI);
  (**(code **)*puVar2)(1);
  return 1;
}
```

---

## W20-L re-verify append (2026-07-29)

**Tools:** `decompile_function` @ `0x0098acc0`; `read_memory` entry 256 B + mid/tail 256 B @ `0x0098adc0`; `get_function_by_address` (body `0098acc0`–`0098ae77`); `get_function_callers` / `get_function_callees`. **No** `disassemble_bytes`.

### Live decompile

Live Ghidra decompile **≡** 2026-07-23 raw body above (no CF delta). `unaff_EDI` remains the image `this`.

### Entry / epilogue bytes (`read_memory`)

```
0098acc0: 83 EC 10              SUB  ESP, 0x10
0098acc3: 83 7F 04 00           CMP  dword [EDI+4], 0
0098acc7: 75 06                 JNZ  have
0098acc9: 32 C0                 XOR  AL, AL
0098accb: 83 C4 10              ADD  ESP, 0x10
0098acce: C3                    RET
...
0098acd0+: PUSH ESI; PUSH 0x1B8; CALL operator_new; ...
           MOV [ESI], PTR_FUN_00a9bcac   ; vtbl imm 0x00a9bcac
           CALL FUN_004320d0; CALL FUN_00432260(EDI,0,0,1)
           MOV AX,[EDI+0x16]; CMP AX,0x18 / 8 bpp branches
...
tail:     CALL FUN_00433390          ; ESI = temp image
          PUSH EDI; MOV EBX,ESI
          CALL FUN_00432580          ; transfer temp → original
          MOV EAX,[EBX]; PUSH 1; MOV ECX,EBX; CALL [EAX]  ; scalar delete temp
          MOV AL,1; ADD ESP,0x10; RET
```

Hex head: `83ec10837f0400750632c083c410c35668b8010000e8…c706acbca900…`

### Caller context (not owned)

Sole direct caller: **`NDAssetImage_LoadTGA`** `0x004347d0` — after row decode, if TGA image-descriptor **bit4** (`0x10`, right→left) call this; bit5+32bpp calls sibling `NDAssetImage_FlipVertical` `0x004332e0`.

### Sealed interpretation

Horizontal flip / right-origin normalize of `NDAssetImage` for TGA bit4. Allocates temp object size **`0x1b8`**, bpp-aware reverse-copy into temp `+0x34`, post-process via `FUN_00433390` / `FUN_00432580`, destroys temp, returns success in **AL**.
