# Raw capture: UI_QuickBarSlotButton_SetSelected

| Field | Value |
|---|---|
| **Stable ID** | `aa_00826780` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00826780` |
| **Ghidra name (pre-rename)** | `FUN_00826780` |
| **Canonical name** | `UI_QuickBarSlotButton_SetSelected` (INFERRED) |
| **System** | client UI / quickbar |
| **Capture timestamp** | `2026-07-29` |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Function bounds

| Field | Value |
|---|---|
| Entry | `0x00826780` |
| Body | `0x00826780`–`0x0082685e` (Ghidra); last insn ends `ret 4` before `CC` pad |
| Signature (Ghidra) | `undefined FUN_00826780(void)` → corrected by bytes to thiscall + 1 stack arg |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_00826780(int param_1,char param_2)

{
  int iVar1;
  
  if (param_2 == '\0') {
    if ((*(char *)(param_1 + 0x4fc) != '\0') && (*(int **)(param_1 + 0x56c) != (int *)0x0)) {
      (**(code **)(**(int **)(param_1 + 0x56c) + 4))(0);
    }
    if (*(int **)(param_1 + 0x564) != (int *)0x0) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x564) + 0x164))(0);
      *(undefined1 *)(iVar1 + 3) = 0xff;
      (**(code **)(**(int **)(param_1 + 0x564) + 0x34c))();
    }
    if (*(int *)(&DAT_00d1da38 + *(int *)(param_1 + 0x504) * 4) == *(int *)(param_1 + 0x500)) {
      *(undefined4 *)(&DAT_00d1da38 + *(int *)(param_1 + 0x504) * 4) = 0xffffffff;
    }
    *(undefined1 *)(param_1 + 0x4fc) = 0;
  }
  else if ((*(int *)(param_1 + 0x548) != 0) && (*(int *)(param_1 + 0x548) != 6)) {
    __RTDynamicCast(*(undefined4 *)(param_1 + 0x88),0,&gfxUIWindow::RTTI_Type_Descriptor,
                    &CDlgQuickBar::RTTI_Type_Descriptor,0);
    FUN_0089fef0();
    if (*(int **)(param_1 + 0x56c) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x56c) + 4))(1);
    }
    *(undefined4 *)(&DAT_00d1da38 + *(int *)(param_1 + 0x504) * 4) =
         *(undefined4 *)(param_1 + 0x500);
    *(char *)(param_1 + 0x4fc) = param_2;
    return;
  }
  return;
}
```

---

## `read_memory` @ `0x00826780` (224 B, includes trailing `CC`)

```
53 8A 5C 24 08 84 DB 56 8B F1 74 68 8B 86 48 05 00 00 85 C0 0F 84 C0 00 00 00
83 F8 06 0F 84 B7 00 00 00 8B 86 88 00 00 00 6A 00 68 B4 E3 AF 00 68 90 E1 AF 00
6A 00 50 E8 E7 30 C6 FF 83 C4 14 E8 2B 97 07 00 8B 8E 6C 05 00 00 85 C9 74 07
8B 01 6A 01 FF 50 04 8B 8E 04 05 00 00 8B 96 00 05 00 00 89 14 8D 38 DA D1 00
88 9E FC 04 00 00 5E 5B C2 04 00 80 BE FC 04 00 00 00 74 11 8B 8E 6C 05 00 00
85 C9 74 07 8B 01 6A 00 FF 50 04 8B 8E 64 05 00 00 85 C9 74 1C 8B 11 6A 00
FF 92 64 01 00 00 C6 40 03 FF 8B 8E 64 05 00 00 8B 01 FF 90 4C 03 00 00
8B 86 04 05 00 00 8B 0C 85 38 DA D1 00 3B 8E 00 05 00 00 75 0B
C7 04 85 38 DA D1 00 FF FF FF FF 88 9E FC 04 00 00 5E 5B C2 04 00 CC
```

---

## Decode (machine)

| Bytes | Instruction | Note |
|---|---|---|
| `53` | `push ebx` | |
| `8A 5C 24 08` | `mov bl, [esp+8]` | stack arg `fSelected` (char) |
| `84 DB` | `test bl, bl` | |
| `56` | `push esi` | |
| `8B F1` | `mov esi, ecx` | **this** = ECX |
| `74 68` | `jz` → clear path | `fSelected == 0` |
| … | select path | gate `+0x548`, RTTI cast, clear-others, highlight |
| `C2 04 00` | `ret 4` | one stack dword |
| clear path | … | unhighlight, alpha, clear global, `+0x4fc=0` |
| `C2 04 00` | `ret 4` | |
| `CC` | int3 pad | |

---

## Call graph (this capture)

| Direction | Targets |
|---|---|
| **Callees** | `__RTDynamicCast` (`0x004898a4`), `FUN_0089fef0` (`0x0089fef0`); virtuals on `this+0x56c` (`vtbl+4`), `this+0x564` (`vtbl+0x164`, `vtbl+0x34c`) |
| **Callers (xrefs)** | `FUN_00826860`, `QuickBar_ClearActiveSlot_INFERRED` (`0x008274c0`), `FUN_00827460`, `FUN_00827670`, `FUN_008283a0`, `FUN_008285a0`, `QuickBar_BuildSkillButtonWidgets` (`0x00829490`), `FUN_0089fef0`, `FUN_008a0210`, `FUN_008a0ed0`, `FUN_008a16b0` |

---

## Related globals / RTTI

| Symbol | Role |
|---|---|
| `DAT_00d1da38` | `int[10]` page → selected **column** index (`-1` = none) |
| `gfxUIWindow::RTTI` @ `0x00afe190` | source type for cast |
| `CDlgQuickBar::RTTI` @ `0x00afe3b4` | dest type for cast |
| `this+0x88` | parent window pointer used as cast source |

---

## Capture notes

- Decompiler correctly shows **thiscall** + `param_2` char; epilogue **`ret 4`** seals one stack arg.
- Select path: `__RTDynamicCast` result is left in **EAX** and consumed as `in_EAX` by `FUN_0089fef0` (walks `CDlgQuickBar` slot array at `+0x63c`, clears other selected buttons).
- Gate on select: `*(this+0x548) != 0 && != 6` — slot payload **kind** (sibling clear path zeros kind@`+0x548`).
- **Not** wire QuickBarUpdate `0x2062`; **not** skill cast; client chrome only.
