# Raw capture: FUN_0051bbc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bbc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051bbc0` |
| **Canonical name** | `FUN_0051bbc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0051bbc0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x29) == '\0') {
    FUN_0051bbc0(*(undefined4 *)((int)param_1 + 8));
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return;
}
```

---

## Re-verify append — 2026-08-04 WQ9E-H OWN-ONLY

**Tools:** `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (64 B). **No** `disassemble_bytes`.

| Claim | Result |
|---|---|
| Live decompile | **Incomplete** — right recurse + false noreturn only; **left-walk missing** |
| Bytes authority | Full free-subtree: right recurse, delete, left iterate |
| Body | `0x0051bbc0`–`0x0051bbf4` inclusive (**53 B**); `C2 04 00`; pad `CC` |
| ABI | ECX threaded (`MOV EBX,ECX`); stack node*; **RET 4** |
| isnil | `+0x29` (`80 7F 29 00` / `80 7E 29 00`) |
| left / right | left `@+0` (`8B 36`); right `@+8` (`8B 46 08`) |
| Caller | `Map_EraseRange` @ `0x0051c7dc` |
| Canonical name | `Map_FreeSubtree_Isnil29` |

### Full body hex (53 B)

```
53 56 57 8B 7C 24 10 80 7F 29 00 8B D9 8B F7 75 1E
8B 46 08 50 8B CB E8 E4 FF FF FF 8B 36 57 E8 3E DC F6 FF
83 C4 04 80 7E 29 00 8B FE 74 E2 5F 5E 5B C2 04 00
```

### Byte-corrected CF (authoritative)

```
if (*(uint8_t*)(node+0x29) != 0) ret 4;
for (;;) {
  Map_FreeSubtree_Isnil29(tree_base, *(node+8)); // right
  left = *node;
  operator_delete(node);
  node = left;
  if (*(uint8_t*)(node+0x29) != 0) break;
}
ret 4;
```
