# Raw capture: FUN_004bb0d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb0d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bb0d0` |
| **Canonical name** | `FUN_004bb0d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_004bb0d0(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)CVOGReaction_ResolveObjectTarget(*(undefined1 *)(param_1 + 2),*param_1,param_1[1])
  ;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x1dc))();
    return uVar2;
  }
  return 0;
}
```

---

## v2026-08-04 WQ9R-D dual seal append

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `batch_decompile` + `read_memory` + `analyze_function_complete` + xrefs |
| **Canonical (sealed)** | `Object_ResolveTfIdVtbl1dc_Inferred` |
| **Body** | `0x004bb0d0`–`0x004bb0f9` (42 B) |
| **Body hex** | `8b4424048b5004528b108a40085250e88cfdffff85c0740d8b108bc8ff92dc010000c2040033c0c20400` |
| **ABI** | ECX = resolve ctx (passthrough); stack blob*; `RET 4` |
| **Virtual** | `vtbl+0x1dc` (`FF 92 DC 01 00 00`) |
| **Callee** | `CVOGReaction_ResolveObjectTarget` @ `0x004bae70` |
| **Xrefs** | 9 |
| **Dual** | accept-with-gaps A+B |

Integrity: prior raw body preserved; this section append-only.
