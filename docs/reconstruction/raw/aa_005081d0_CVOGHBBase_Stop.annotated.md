# Annotated low-level: CVOGHBBase_Stop

| Field | Value |
|---|---|
| Stable ID | `aa_005081d0` |
| VA | `0x005081d0`–`0x005081df` |
| System | heartbeat / timed-actions |
| Date | 2026-07-29 (dual residual; prior 2026-07-23 scaffold) |

## Machine-level notes

- Source: raw capture + live `decompile_function` / `read_memory` (2026-07-29).
- **fDormant** is byte at **`this+0x21`** (not a bitfield in this path).
- **OnEnd** is **`*( *this + 0x10 )`** via **`jmp [eax+0x10]`** (tail-call). Decompiler warning “Could not recover jumptable” is noise.
- Calling convention: **thiscall/fastcall ECX this**, **no stack args**, epilogue **`C3 ret`**.
- Sibling **Start** at `0x005081c0`: inverse dormant clear + `jmp [eax+4]` OnStart.
- Prefer bytes when decompiler names drift; CF here is 1:1 with bytes.

## Byte map

| VA | Bytes | Meaning |
|---|---|---|
| `005081d0` | `80 79 21 00` | `cmp byte [ecx+0x21], 0` |
| `005081d4` | `75 09` | `jnz` → bare ret (already stopped) |
| `005081d6` | `8B 01` | `mov eax, [ecx]` vtbl |
| `005081d8` | `C6 41 21 01` | `mov byte [ecx+0x21], 1` |
| `005081dc` | `FF 60 10` | `jmp [eax+0x10]` OnEnd |
| `005081df` | `C3` | `ret` (idle path) |

## Pseudocode (annotated)

```c
void __fastcall CVOGHBBase_Stop(CVOGHBBase *this)
{
  /* +0x21 fDormant; ctor sets 1; Start clears 0 */
  if (this->fDormant == false) {
    this->fDormant = true;
    /* tail-call OnEnd — not a multi-way jumptable */
    (**(code **)((int)this->pVTable + 0x10))();
    return;
  }
  return;
}
```

## Cross-unit contracts (context only)

- **Start**: clear dormant + OnStart (`vtbl+4`); this unit is the inverse arm.
- **TryFire**: period due + still dormant → status Inactive (2); no OnHeartBeat.
- **Dequeue/Remove**: separate; Stop does not unlink from pending list.

## Open questions

- Exhaustive Stop-without-Remove / Remove-without-Stop call-site matrix.
- Product PDB name for vtbl+0x10 slot (OnEnd INFERRED).
