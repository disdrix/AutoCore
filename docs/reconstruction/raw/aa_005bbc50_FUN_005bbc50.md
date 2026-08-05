# Raw capture: FUN_005bbc50

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bbc50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bbc50` |
| **Canonical name** | `FUN_005bbc50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005bbc50(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a6bad;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  FUN_005b8340();
  pvVar1 = *(void **)(param_1 + 0x308);
  if (pvVar1 != (void *)(param_1 + 0x14)) {
    FUN_005b8340();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  FUN_005b8340();
  if (*(char *)(param_1 + 0x7fc) != '\0') {
    pvVar1 = *(void **)(param_1 + 0x6ec);
    if (pvVar1 != (void *)(param_1 + 0x3f8)) {
      FUN_005b8340();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    FUN_005b8340();
  }
  piVar3 = (int *)**(int **)(param_1 + 0xa24);
  if (piVar3 != *(int **)(param_1 + 0xa24)) {
    do {
      FUN_005be2b0(piVar3[2]);
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*(int *)(param_1 + 0xa24));
  }
  puVar2 = *(undefined4 **)(param_1 + 0xa24);
  pvVar1 = (void *)*puVar2;
  *puVar2 = puVar2;
  *(int *)(*(int *)(param_1 + 0xa24) + 4) = *(int *)(param_1 + 0xa24);
  *(undefined4 *)(param_1 + 0xa28) = 0;
  if (pvVar1 != *(void **)(param_1 + 0xa24)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  puVar2 = *(undefined4 **)(param_1 + 0xa24);
  pvVar1 = (void *)*puVar2;
  *puVar2 = puVar2;
  *(int *)(*(int *)(param_1 + 0xa24) + 4) = *(int *)(param_1 + 0xa24);
  *(undefined4 *)(param_1 + 0xa28) = 0;
  if (pvVar1 != *(void **)(param_1 + 0xa24)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 0xa24));
}
```

---

## Live re-pull (W30-S OWN-ONLY, 2026-07-29)

**Tool:** Ghidra HTTP `decompile_function` + `read_memory` + `get_function_by_address` + callers/callees. **No** `disassemble_bytes`.

**Meta:** `FUN_005bbc50` @ `005bbc50`; Ghidra body `005bbc50`–`005bbd96` exclusive (noreturn truncation on `operator_delete`).

**Caller (1):** `FUN_005be310` @ `0x005be310` (W30-R OWN) — teardown then optional freelist push.

**Callees:** `FUN_005b8340`, `FUN_005be2b0` (`ObjectMotion_SlotReleaseToFreelist_Inferred`), `operator_delete`.

**Call site freelist (bytes @ ~0x005bbd0e):** `50 B9 C0 36 B0 00 E8 …` — push payload; `mov ecx, 0x00B036C0`; call `FUN_005be2b0`.

**Entry (`read_memory` 48 B @ 0x005bbc50):** `6a ff 68 ad 6b 9a 00 64 a1 00 00 00 00 50 64 89 25 …` (MSVC SEH prolog).

**True epilogue (beyond Ghidra end; `read_memory` @ 0x005bbd90+):** after final `operator_delete` of sentinel: `83 c4 04` … zero `host+0xa24` … SEH unlink … `83 c4 10` **`c3`** (`ret`) + `cc` pad. Address of `c3` ≈ `0x005bbdc0`.

**List free loop residual:** bytes near `0x005bbd80` include `3b … 75 eb` back-edge — decompiler single-delete is **noreturn artifact**; full node walk delete exists in bytes.

**Decompile body:** unchanged vs scaffold capture (same CF). See annotated + clean for sealed interpretation.
