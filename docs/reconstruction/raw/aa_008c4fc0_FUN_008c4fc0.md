# Raw capture: FUN_008c4fc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c4fc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008c4fc0` |
| **Canonical name** | `Client_CastFirstHardpointSkillFlag200_Inferred` (INFERRED) / `FUN_008c4fc0` |
| **System** | skills-abilities / host hardpoint cast |
| **Capture timestamp** | `2026-07-23` (scaffold); **WQ8R-F live re-decompile 2026-08-04** |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008c4fc0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  undefined4 local_4;
  
  if ((DAT_00d1b6d8 != 0) && (*(char *)(DAT_00d1b6d8 + 0x6b8) != '\0')) {
    iVar2 = 0;
    if ((*(char *)(DAT_00d1b6d8 + 0x30c) == '\0') ||
       (iVar3 = *(int *)(DAT_00d1b6d8 + 0x250), iVar3 == 0)) {
      iVar3 = *(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xb4 + DAT_00d1b6d8);
    }
    else {
      iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xb4 + iVar3);
    }
    if (iVar3 != 0) {
      local_8 = 0;
      local_4 = 0;
      FUN_004294f0();
      iVar1 = FUN_004022a0(&local_4,&local_8);
      while (iVar1 == 0) {
        if ((((local_8 != 0) && (*(int *)(local_8 + 0x1c) == 1)) &&
            (iVar1 = __RTDynamicCast(local_8,0,&CVOGHBBase::RTTI_Type_Descriptor,
                                     &CVOGHBSkillBase::RTTI_Type_Descriptor,0), iVar1 != 0)) &&
           (*(char *)(iVar1 + 0x140) != '\0')) {
          iVar2 = iVar1 + 0x24;
          break;
        }
        iVar1 = FUN_004022a0(&local_4,&local_8);
      }
      if (*(char *)(iVar3 + 0x28) != '\0') {
        *(undefined1 *)(iVar3 + 0x28) = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));
      }
      if ((iVar2 != 0) && ((*(uint *)(iVar2 + 0x614) & 0x200) != 0)) {
        Client_CastSkillFromQuickBarSlot(*(undefined4 *)(iVar2 + 0x5fc));
      }
    }
  }
  return;
}
```

---

## WQ8R-F live append (2026-08-04)

### Meta

| Field | Value |
|---|---|
| Body | `0x008c4fc0`–`0x008c50ca` (last insn `RET` @ `0x008c50ca`) |
| Size | **267 B** |
| Callers | **1** — `FUN_008c50f4` @ `0x008c510f` (UNCONDITIONAL_CALL) |
| Callees | `List_TraversalLock` `0x004294f0`, `List_IterateNext` `0x004022a0`, `__RTDynamicCast`, `LeaveCriticalSection`, `Client_CastSkillFromQuickBarSlot` `0x009418e0` |
| Live decompile | ≡ 2026-07-23 raw body (no CF drift) |

### Entry / list / cast bytes (read_memory)

```
008c4fc0  A1 D8 B6 D1 00          mov  eax, [DAT_00d1b6d8]
008c4fc5  83 EC 08                sub  esp, 8
008c4fc8  85 C0                   test eax, eax
… gate player+0x6b8 (imm 0x6b8) …
… host list MI+0xb4 on player OR vehicle@+0x250 …
008c502x  E8 ..                   call List_TraversalLock (ECX=list)
008c50xx  E8 ..                   call List_IterateNext
… filter +0x1c==1, RTDynamicCast CVOGHBBase→CVOGHBSkillBase, +0x140 ≠ 0 …
008c50a8  F7 85 14 06 00 00 00 02 00 00   test [ebp+0x614], 0x200
008c50b2  7E 11                            jle  skip_cast   ; ZF→skip when bit clear
008c50b4  8B 8D FC 05 00 00                mov  ecx, [ebp+0x5fc]
008c50ba  51                               push ecx          ; skillId
008c50bb  BE 40 A8 D1 00                   mov  esi, &DAT_00d1a840  ; client
008c50c0  E8 1B C8 07 00                   call Client_CastSkillFromQuickBarSlot
008c50c5  5E 5D 83 C4 08 C3                pop esi; pop ebp; add esp,8; ret
```

### Full body hex (267 B)

```
a1d8b6d10083ec0885c00f84f700000080b8b8060000000f84ea0000005533ed80b80c030000005674198b885002000085c9740f8b41048b50048bb40ab4000000eb0d8b48048b51048bb402b400000085f60f84ad0000008bcec744240800000000c744240c00000000e8c144b6ff8d442408508d4c2410518bcee860d2b3ff85c0754c8b44240885c0742a83781c0175246a0068ec8caf0068988daf006a0050e83e48bcff83c41485c0740980b8400100000075178d542408528d442410508bcee819d2b3ff85c074b9eb038d6824807e2800740ec646280083c60456ff15b8619c0085ed741df78514060000000200007e118b8dfc05000051be40a8d100e81bc807005e5d83c408c3
```

### Parent context (not owned)

`FUN_008c50f4` (`0x008c50f4`): if `player+0x6b8 && !player+0x6b9` → **this unit**; else if `DAT_00d1b778` vtbl`+0x3d8` → `Client_Input_TryUseModChip` (`0x0091f6b0`). Preceding bytes @ `0x008c50d0` gate cmd `(class=8, id=0x9c40)` into that UI path (Ghidra may not define a separate function).
