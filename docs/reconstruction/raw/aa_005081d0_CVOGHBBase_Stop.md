# Raw capture: CVOGHBBase_Stop

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005081d0` |
| **Canonical name** | `CVOGHBBase_Stop` |
| **Prior scaffold name** | `FUN_005081d0` |
| **System** | heartbeat / timed-actions |
| **Capture timestamp** | `2026-07-23` (scaffold); rename seal `2026-07-29` |
| **Tool** | Ghidra MCP `batch_decompile` (original); re-verify `decompile_function` + `read_memory` |
| **Integrity** | Do not overwrite the original raw body block; append versioned sections only |

---

## Raw pseudocode (authoritative decompile — original scaffold form)

```c
void __fastcall FUN_005081d0(int *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    *(undefined1 *)((int)param_1 + 0x21) = 1;
                    /* WARNING: Could not recover jumptable at 0x005081dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x10))();
    return;
  }
  return;
}
```

---

## Re-verify 2026-07-29 (append only)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Live decompile name** | Still `FUN_005081d0` in database (not yet renamed in Ghidra) |
| **Bytes** | `80 79 21 00 75 09 8B 01 C6 41 21 01 FF 60 10 C3` @ `0x005081d0` (16 B) |
| **Body range** | `0x005081d0`–`0x005081df` |
| **ABI** | ECX this; bare `ret`; no stack args |
| **Canonical reconstruction name** | `CVOGHBBase_Stop` (inverse of sealed `CVOGHBBase_Start` @ `0x005081c0`) |

### Typed CF (names cleaned; CF = raw)

```c
void __fastcall CVOGHBBase_Stop(CVOGHBBase *this)
{
  if (this->fDormant == false) {
    this->fDormant = true;
    /* WARNING: jumptable — noise; single tail-jmp vtbl+0x10 */
    (**(code **)((int)this->pVTable + 0x10))();
    return;
  }
  return;
}
```

### Byte map

| VA | Bytes | Meaning |
|---|---|---|
| `005081d0` | `80 79 21 00` | `cmp byte [ecx+0x21], 0` |
| `005081d4` | `75 09` | `jnz` → bare ret (already dormant) |
| `005081d6` | `8B 01` | `mov eax, [ecx]` vtbl |
| `005081d8` | `C6 41 21 01` | `mov byte [ecx+0x21], 1` |
| `005081dc` | `FF 60 10` | `jmp [eax+0x10]` OnEnd |
| `005081df` | `C3` | `ret` (idle path) |
