# Raw capture: FUN_004bcae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bcae0` |
| **Canonical name** | `FUN_004bcae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004bcae0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    puVar3 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 4);
    while (puVar3 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)puVar3[3];
      *puVar3 = &PTR_FUN_009cb358;
      if ((undefined4 *)puVar3[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)puVar3[2])(1);
      }
      puVar3[2] = 0;
      *puVar3 = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 **)(param_1 + 0x20) = puVar3;
      puVar3 = puVar2;
    }
    iVar1 = uVar4 * 4;
    uVar4 = uVar4 + 1;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + iVar1) + 4) = 0;
  } while (uVar4 <= *(uint *)(param_1 + 8));
  return;
}
```

---

## W37-G re-verify (2026-08-04) — append only

| Field | Value |
|---|---|
| **Tools** | `batch_decompile`, `analyze_function_complete`, `get_function_by_address`, `read_memory` (95 B). **No** `disassemble_bytes`. |
| **Body** | `0x004bcae0`–`0x004bcb3e` inclusive (**95 B** / `0x5F`); bare `C3` then `CC` pad |
| **Live decompile** | ≡ raw 2026-07-23 CF (ECX this/fastcall; buckets `0…mask` incl.; value dtor vtbl(1); freelist push `+0x20`; clear heads) |
| **Callers** | 1: `FUN_004bcc60` (`CNDHash_FreeBuckets_009cb450`, W31-M) @ `0x004bcc6a` |
| **Callees** | none static (virtual delete via value vtbl only) — Ghidra classification **leaf** |
| **Twin (not owned)** | `FUN_004e2bd0` (W37-J): value @ `node+0xC`, next @ `node+0x10`, stamp `009cb360` |

### Full body hex (95 B)

```
53 55 56 33 c0 57 8b d9 33 ed 8d 9b 00 00 00 00
8b 4b 10 8b 14 a9 8b 7a 04 3b f8 74 2c 8d 49 00
8b f7 8b 4e 08 3b c8 8b 7f 0c c7 06 58 b3 9c 00
74 08 8b 01 6a 01 ff 10 33 c0 3b f8 89 46 08 8b
4b 20 89 0e 89 73 20 75 d7 8b 53 10 8b 0c aa 83
c5 01 89 41 04 3b 6b 08 76 b6 5f 5e 5d 5b c3
```
