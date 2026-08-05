# Raw capture: FUN_005adfa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005adfa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005adfa0` |
| **Canonical name** | `FUN_005adfa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005adfa0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x19);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x19);
  }
  return;
}
```

---

## W28-O re-verify (2026-07-29) — append only

| Field | Value |
|---|---|
| **Tools** | `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_xrefs` — **no** `disassemble_bytes` |
| **Live decompile** | ≡ 2026-07-23 raw body (void / walk-into-nil presentation) |
| **Body exclusive end** | `0x005adfba` (Ghidra function end) |
| **Size** | **26** B (`0x1A`) |
| **Epilogue** | `C3` (`ret`) — **cdecl**, not `ret 4` |
| **Pad** | `CC` × ≥6 after body |

### Body hex (authoritative)

```
8b442404 8b08 80791900 750e 8d642400 8bc1 8b08 80791900 74f6 c3
```

### Byte-level CF (overrides decompiler)

```
mov eax, [esp+4]          ; node*
mov ecx, [eax]            ; left = node->left
cmp byte ptr [ecx+0x19], 0
jne  done                 ; if left isnil → return original node
loop:
  mov eax, ecx            ; node = left
  mov ecx, [eax]          ; left = node->left
  cmp byte ptr [ecx+0x19], 0
  je   loop
done:
  ret                     ; EAX = last non-nil = Tree_min
```

**Decompiler defect:** marks `void`, walks as if returning the nil sentinel, and always advances to `*node` first. Callers consume EAX (`head->left = FUN_005adfa0(repl)`). **Bytes + caller use are authority.**

### Callers (6) — shared Val12 erase leftmost fixup

`FUN_004188e0`, `FUN_004e4130`, `FUN_005399f0`, `FUN_00573250`, `FUN_005ae990`, `FUN_005e15a0`

### Sealed name

`StdTree_Min_Val12` (MSVC `_Tree_min` / leftmost non-nil of subtree; Val12 isnil@+0x19)
