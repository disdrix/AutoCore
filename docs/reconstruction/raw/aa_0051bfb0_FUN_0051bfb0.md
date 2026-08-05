# Raw capture: FUN_0051bfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051bfb0` |
| **Canonical name** | `FUN_0051bfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0051bfb0(int param_1)



{

  int iVar1;

  void *pvVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  uint uVar5;

  

  uVar5 = 0;

  do {

    puVar4 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x10) + uVar5 * 4) + 4);

    while (puVar4 != (undefined4 *)0x0) {

      pvVar2 = (void *)puVar4[2];

      puVar3 = (undefined4 *)puVar4[3];

      *puVar4 = &PTR_FUN_009ce0a8;

      if (pvVar2 != (void *)0x0) {

        FUN_00604e30();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

      puVar4[2] = 0;

      *puVar4 = *(undefined4 *)(param_1 + 0x20);

      *(undefined4 **)(param_1 + 0x20) = puVar4;

      puVar4 = puVar3;

    }

    iVar1 = uVar5 * 4;

    uVar5 = uVar5 + 1;

    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + iVar1) + 4) = 0;

  } while (uVar5 <= *(uint *)(param_1 + 8));

  return;

}
```


---

## W25-F live seal (2026-07-29) — dual A/B OWN

| Field | Value |
|---|---|
| **Agent** | W25-F OWN-ONLY dual A/B |
| **Tools** | Ghidra `decompile_function` + `read_memory` + `get_function_by_address` / xrefs / callees (**no** `disassemble_bytes`) |
| **Program** | `autoassault.exe` @ `0x400000` |
| **Body** | `0x0051bfb0`–`0x0051c021` (**0x72** B; trailing int3 pad after `ret`) |
| **Live ≡ raw (2026-07-23)** | **Yes** — surface CF identical |
| **Canonical (sealed)** | `CNDHash_ReclaimAll_ValueOwning_009ce0a8` (**Inferred**) |
| **Rejected aliases** | `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0051bfb0` |

### Live decompile (2026-07-29)

```c
void __fastcall FUN_0051bfb0(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  uVar5 = 0;
  do {
    puVar4 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x10) + uVar5 * 4) + 4);
    while (puVar4 != (undefined4 *)0x0) {
      pvVar2 = (void *)puVar4[2];
      puVar3 = (undefined4 *)puVar4[3];
      *puVar4 = &PTR_FUN_009ce0a8;
      if (pvVar2 != (void *)0x0) {
        FUN_00604e30();
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar2);
      }
      puVar4[2] = 0;
      *puVar4 = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 **)(param_1 + 0x20) = puVar4;
      puVar4 = puVar3;
    }
    iVar1 = uVar5 * 4;
    uVar5 = uVar5 + 1;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + iVar1) + 4) = 0;
  } while (uVar5 <= *(uint *)(param_1 + 8));
  return;
}
```

### `read_memory` @ `0x0051bfb0` (0x72 body bytes)

```
51 53 55 8B E9 33 C9 56 33 C0 57 89 44 24 10 90
8B 55 10 8B 14 82 8B 7A 04 3B F9 74 3A 8D 49 00
8B F7 8B 5E 08 3B D9 8B 7F 0C C7 06 A8 E0 9C 00
74 16 8B CB E8 47 8E 0E 00 53 E8 33 D8 F6 FF
8B 44 24 14 83 C4 04 33 C9 3B F9 89 4E 08 8B 55 20
89 16 89 75 20 75 C9 8B 55 10 8B 14 82 83 C0 01
89 4A 04 3B 45 08 89 44 24 10 76 A4 5F 5E 5D 5B 59 C3
```

### Byte-derived CF notes

- Prolog: `push ecx; push ebx; push ebp; mov ebp,ecx` — **ECX = this** (`__thiscall` / `__fastcall`).
- Stamp imm: `C7 06 A8 E0 9C 00` → node vtbl **`0x009ce0a8`**.
- Value path: `MOV ECX,EBX; CALL FUN_00604e30; PUSH EBX; CALL operator_delete; ADD ESP,4` — **`operator_delete` RETURNS** (Ghidra noreturn warning is **false**).
- Freelist: `MOV EDX,[EBP+0x20]; MOV [ESI],EDX; MOV [EBP+0x20],ESI`.
- Outer loop: `JBE` vs mask at `this+0x08` (**inclusive** `0..mask`).
- Epilogue: `pop edi; pop esi; pop ebp; pop ebx; pop ecx; ret` — **plain `ret`**.
- Sole xref-from: `CNDHash_FreeBuckets` (`FUN_0051d150`) @ `0x0051d15a`.

### Nested value teardown (callee residual — not owned)

`FUN_00604e30(value)` thiscall clears nested heap fields at value `+4/+8/+0xC/+0x10` via `operator_delete` each, then zeros them; parent then deletes the value object itself. Distinguishes this stamp from plain-owning reclaim siblings (`009cefec` / `009cefe4`) that only `operator_delete(value)`.
