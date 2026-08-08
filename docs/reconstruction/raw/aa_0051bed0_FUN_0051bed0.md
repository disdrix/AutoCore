# Raw capture: FUN_0051bed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051bed0` |
| **Canonical name** | `FUN_0051bed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0051bed0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0051bed0(*(undefined4 *)((int)param_1 + 8));
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return;
}
```

---

## Re-verify append - 2026-08-04 WQ9G-D OWN dual

| Field | Value |
|---|---|
| **Tool** | Ghidra `batch_decompile` / `analyze_function_complete` + `read_memory` + callers/xrefs (**no** `disassemble_bytes`) |
| **Live == original raw CF (decomp plate)** | **Yes** — same right-recurse + delete surface; left-walk restored from bytes |
| **Body** | `0x0051bed0`–`0x0051bf05` exclusive (**53 B** / `0x35`); Ghidra inclusive end `0x0051bf04`; `CC` pad after `ret 4` |
| **ABI bytes** | Stack `node*`; preserves EBX/ESI/EDI; threads ECX unused (`mov ebx,ecx`); **`ret 4`** (`C2 04 00`) |
| **isnil** | `cmp byte ptr [node+0x15], 0` — isnil@+0x15 family (same as dualed `Map_EraseRange_Isnil15_B`) |
| **Byte-correct free algebra** | MSVC free-subtree: while not isnil: free(right@+8); left=`*node`; `operator_delete(node)`; node=left. Decompiler drops left-walk (false-noreturn on `operator_delete`). |
| **Callees** | self (right recurse); `operator_delete` |
| **Callers** | self @ `0x0051bee7`; sole external **`Map_EraseRange_Isnil15_B` / `FUN_0051d940`** full-clear @ `0x0051d95c` |
| **Promoted name** | `Map_FreeSubtree_Isnil15_B` — free helper for dualed `Map_EraseRange_Isnil15_B`; twin CF of dualed `Map_FreeSubtree_Isnil15` @ `0x0051be50` (different VA/callers — do not alias) |
