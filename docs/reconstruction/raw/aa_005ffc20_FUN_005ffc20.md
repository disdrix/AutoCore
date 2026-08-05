# Raw capture: FUN_005ffc20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ffc20` |
| **Canonical name** | `FUN_005ffc20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005ffc20(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x1d4))();
    if ((iVar1 != 0) && (*(int *)(param_1 + 0x10) < 1)) {
      uVar2 = 1;
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x210))(0,1);
      FUN_005208e0(uVar2);
    }
  }
  FUN_005081f0();
  return;
}
```

---

## 2026-07-29 reconfirm (W17-K OWN-ONLY dual)

| Field | Value |
|---|---|
| **Tool** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Program** | `autoassault.exe` base `0x400000` |
| **Body end** | tail-jmp `FUN_005081f0` (empty `ret` stub) |
| **Live decompile** | ≡ raw body above |
| **Canonical (RTTI)** | `CVOGHBToken_OnEnd` |
| **RTTI** | `.?AVCVOGHBToken@@` @ type_info `0x00af4660`; vtbl slot `+0x14` @ `0x009dde40` |

### Machine seal (`read_memory` @ `0x005ffc20`, 80 B)

Hex:  
`56 8b f1 8b 4e 18 85 c9 74 2f 8b 01 ff 90 d4 01 00 00 85 c0 74 23 83 7e 10 00 7f 1d 8b 48 04 8b 51 04 8d 4c 02 04 8b 01 6a 01 6a 00 ff 90 10 02 00 00 8b c8 e8 87 0c f2 ff 8b ce 5e e9 8f 85 f0 ff`

| Claim | Evidence | Conf |
|---|---|---|
| ECX → ESI this | `56 8b f1` | **High** |
| Gate `this+0x18` non-null | `8b 4e 18; 85 c9; 74 2f` | **High** |
| vcall related `+0x1d4` | `ff 90 d4 01 00 00` | **High** |
| Gate result + `this+0x10 < 1` | `85 c0; 74 23; 83 7e 10 00; 7f 1d` | **High** |
| MI adjust + vcall `+0x210` | `8d 4c 02 04; 6a 01; 6a 00; ff 90 10 02 00 00` | **High** |
| `FUN_005208e0` (flag `+0x529`=1) | `8b c8; e8 …` → `0x005208e0` | **High** |
| Tail `jmp FUN_005081f0` empty | `e9 8f 85 f0 ff` | **High** |
| DATA-only xref (vtbl) | `0x009dde40` | **High** |

### ABI note (stack framing for `005208e0`)

Machine order: `push 1; push 0; call [vtbl+0x210]; mov ecx,eax; call FUN_005208e0`.  
`FUN_005208e0` is `__thiscall` + 1 stack char (`ret 4`). Same framing as `VehicleNet_UnpackGhostVehicle` @ `0x005f9920` (`push value; push 0; vcall 0x210; SetFlag`). Decompiler may show `(0,1)` as both vcall args; end effect sealed: **character `+0x529 = 1`** with net dirty mask `0x100`.
