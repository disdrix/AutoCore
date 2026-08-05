# Raw capture: FUN_005b2ba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2ba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b2ba0` |
| **Canonical name** | `FUN_005b2ba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005b2ba0(int param_1)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  while (iVar2 != 0) {
    if ((*(int *)(param_1 + 0x10) != 0) &&
       (iVar2 = *(int *)(param_1 + 0x10) + -1, *(int *)(param_1 + 0x10) = iVar2, iVar2 == 0)) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    iVar2 = *(int *)(param_1 + 0x10);
  }
  iVar2 = *(int *)(param_1 + 8);
  while (iVar2 != 0) {
    pvVar1 = *(void **)(*(int *)(param_1 + 4) + -4 + iVar2 * 4);
    iVar2 = iVar2 + -1;
    if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
  }
  if (*(void **)(param_1 + 4) == (void *)0x0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 4));
}
```

---

## W37-D re-verify (2026-08-04)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `batch_decompile` + `read_memory` + `analyze_function_complete` |
| **Live decompile** | ≡ scaffold body (2026-07-23) |
| **Body** | `0x005b2ba0`–`0x005b2c05` inclusive (**102 B** / `0x66`); pad `CC` |
| **Full hex** | `53568bf133db395e10741eeb038d49008b46103bc3740d83c0ff3bc38946107503895e0c395e1075e7578b7e083bfb761b8b46048b44b8fc83ef013bc3740950e83d6cedff83c4043bfb77e58b46043bc35f740950e8286cedff83c404895e08895e045e5bc3` |
| **ABI** | ECX = `GuardedVectorHeader*`; plain `RET` (`C3`); void |
| **Callees** | `operator_delete` @ `0x00489822` (×2 sites) |
| **Callers** | 28 functions (AssPreloader locals, dtor chains, etc.) |
| **Bytes refine** | After map `operator_delete`, always `capacity=0` and `pages=0` (decompiler drops these stores on non-null path due to false "does not return") |

