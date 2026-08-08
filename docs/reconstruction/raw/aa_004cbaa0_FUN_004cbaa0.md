# Raw capture: FUN_004cbaa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbaa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cbaa0` |
| **Canonical name** | `FUN_004cbaa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cbaa0(int param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  piVar4 = param_4;
  piVar6 = *(int **)(param_1 + 4);
  piVar3 = param_3;
  if ((param_3 == (int *)*piVar6) && (param_4 == piVar6)) {
    FUN_004cb550(piVar6[1]);
    *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
    *param_2 = **(undefined4 **)(param_1 + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x29) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x29) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x29);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x29);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x29);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x29);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004cb740(&param_3,piVar3);
    piVar3 = piVar6;
  }
  *param_2 = piVar3;
  return;
}
```

---

## Re-verify (2026-08-04 WQ9F-C OWN dual)

| Field | Value |
|---|---|
| **Tool** | Ghidra `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs (**no** `disassemble_bytes`) |
| **Live decompile CF** | **≡ raw 2026-07-23** (full-clear fast path + partial successor loop + single erase) |
| **Body** | `0x004cbaa0`–`0x004cbb54` exclusive (**180 B** / `0xB4`); Ghidra body end `004cbb53` |
| **ABI** | `__thiscall` ECX=map shell*; stack `Node** outIt`, `Node* first`, `Node* last`; **RET 0x0C** (`C2 0C 00`) both exits |
| **Entry hex** | `53 8B 5C 24 10 56 8B 74 24 10 57 8B F9` |
| **Full-clear epilogue** | `5F 5E 89 10 5B C2 0C 00` (`*outIt` after head reset; ret 12) |
| **Partial epilogue** | `8B 44 24 10 5F 89 30 5E 5B C2 0C 00` (`*outIt = last/current`; ret 12) |
| **Pad** | `CC` after `C2 0C 00` |
| **isnil** | successor walk uses `+0x29` immediates |
| **Full clear** | if `first == *head` (begin) && `last == head` (end): `FUN_004cb550(head->parent)`; reset parent/left/right to head; size=0; `*outIt=*head` |
| **Partial** | while first!=last: successor (isnil29); `FUN_004cb740(&first, node)` (=`StdTree_EraseAndRebalance_Isnil29_Inferred`) |
| **Free callee** | `FUN_004cb550` (isnil29 free-subtree residual) |
| **Erase callee** | dualed WQ9E-E `StdTree_EraseAndRebalance_Isnil29_Inferred` @ `0x004cb740` |
| **Xrefs (6 UNCONDITIONAL_CALL)** | `0x004cc3e2` (`FUN_004cc3d0`), `0x004ca113` (`FUN_004c9f80`), `0x004ea63f`/`0x004ea94d`/`0x004eabd1` (`FUN_004ea350` ×3), `0x005dd8cb` |
| **Do not merge** | `Map_EraseRange` `0x0051c7c0`; `Map_EraseRange_B` `0x0051d880`; isnil15/1d/Val12 range twins (different free/erase callees) |
| **Name promote** | `StdTree_EraseRange_Isnil29_Inferred` |
