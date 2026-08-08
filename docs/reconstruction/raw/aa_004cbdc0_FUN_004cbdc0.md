# Raw capture: FUN_004cbdc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbdc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cbdc0` |
| **Canonical name** | `FUN_004cbdc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cbdc0(int param_1,byte param_2)

{
  if (*(char *)(param_1 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:Recreate, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  FUN_004cba60();
  *(byte *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(int *)(param_1 + 8) = 1 << (param_2 & 0x1f);
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_004cb410();
  return;
}
```

---

## Re-verify 2026-08-04 (WQ9D-A OWN-ONLY dual seal)

| Field | Value |
|---|---|
| **Tools** | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + assembly_context. **No** `disassemble_bytes`. |
| **Live decompile** | **Identical** to 2026-07-23 raw body above. |
| **Body** | `0x004cbdc0`–`0x004cbe14` inclusive last byte of `ret 4` (**85 B** / `0x55`); `CC` pad @ `0x004cbe15+`. Ghidra body end `004cbe14`. |
| **Entry bytes** | `56 8B F1` (`push esi; mov esi,ecx`) → **thiscall** ECX=hash. |
| **Exit** | `5E C2 04 00` (`pop esi; ret 4`) — stack arg log2 cleaned. |
| **Lock gate** | `cmp byte ptr [esi+0x1d],0` / `jz` skip logs; else push string `0x00a64c48` + `0x00a15844` → `FUN_007a4480` ×2; **no early return**. |
| **Post-lock** | `call FUN_004cba60` (ECX=esi); `mov cl,[esp+8]`; `mov eax,1; shl eax,cl`; store log2 `@+0x1c`, zero `@+0x18` and `@+0x14`, store count `@+8`; `call FUN_004cb410`. |
| **Callers** | `FUN_00518e30` @ `0x00518e55` (ECX=`[owner+0x70]`, push log2); `FUN_004c8f00` @ `0x004c902c` (ECX=MI load `…+0x74`, **push 2**). |
| **Strings** | `"HashError:Recreate, already locked for traversal"` @ `0x00a64c48`; `"VOG_DEBUG_STOP"` @ `0x00a15844`. |
| **Named** | `SkillCNDHash_Recreate_Inferred` (skill-family CNDHash; vtbl peer ctor `009ce1b8`; **not** inventory `CNDHash_Recreate` `0x004138d0`). |
