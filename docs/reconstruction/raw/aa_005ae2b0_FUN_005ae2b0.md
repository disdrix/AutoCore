# Raw capture: FUN_005ae2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae2b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ae2b0` |
| **Canonical name** | `FUN_005ae2b0` |
| **System** | util / container (MSVC `_Tree` / map head node) |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005ae2b0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 6) = 1;
  *(undefined1 *)((int)puVar1 + 0x19) = 0;
  return;
}
```

---

## Live re-decompile (2026-07-29, W16-G)

Tool: Ghidra MCP `decompile_function` @ `0x005ae2b0` program `autoassault.exe`.

**Body ≡ original raw.** Decompiler still types return as `void`; callers assign EAX → real return is node pointer.

```c
void FUN_005ae2b0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 6) = 1;
  *(undefined1 *)((int)puVar1 + 0x19) = 0;
  return;
}
```

### Bytes (`read_memory` 80 B @ `0x005ae2b0`)

```
6A 1C E8 .. .. .. .. 83 C4 04 85 C0 74 06 C7 00 00 00 00 00
8D 48 04 85 C9 74 06 C7 01 00 00 00 00
8D 48 08 85 C9 74 06 C7 01 00 00 00 00
C6 40 18 01
C6 40 19 00
C3
```

- `push 0x1C` / `operator_new` / `add esp,4` (cdecl new).
- Zero dword links at `+0`, `+4`, `+8` under null-ish checks.
- `mov byte [eax+0x18], 1` (color = black).
- `mov byte [eax+0x19], 0` (isnil = false; map ctors flip head isnil to 1).
- Plain **`C3`** ret; **EAX** holds node* for callers.
