# Raw capture: FUN_0085fcc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085fcc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0085fcc0` |
| **Canonical name** | `FUN_0085fcc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0085fcc0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *unaff_ESI;
  int *local_4;
  
  if (unaff_ESI[0x15c] != 0) {
    local_4 = (int *)0x0;
    FUN_00413a60(param_1,param_2,&local_4);
    piVar1 = local_4;
    if (local_4 != (int *)0x0) {
      (**(code **)(*local_4 + 0x3ac))();
      FUN_007fbb70();
      (**(code **)(*unaff_ESI + 0xbc))(piVar1);
      unaff_ESI[0x140] = unaff_ESI[0x140] + -1;
    }
  }
  return;
}
```

---

## Re-verify 2026-07-29 (append-only; dual A/B)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Live decompile** | Identical CF to 2026-07-23 body above |
| **Epilogue** | `c2 08 00` → `ret 8` (stdcall 2 dwords) |
| **Prolog hash gate** | `8b be 70 05 00 00` → `mov edi, [esi+0x570]` |
| **Count** | `83 86 00 05 00 00 ff` → `add dword [esi+0x500], -1` |
| **Imm host** | `b8 40 a8 d1 00` → `mov eax, 0x00d1a840` before `FUN_007fbb70` |
| **Inferred name** | `Client_UI_InventorySheet_RemoveByCoid` |
| **Dual** | `reviews/A_aa_0085fcc0_…` + `reviews/B_aa_0085fcc0_…` |

Original raw body above remains authoritative for decompiler text; bytes seal register ABI.
