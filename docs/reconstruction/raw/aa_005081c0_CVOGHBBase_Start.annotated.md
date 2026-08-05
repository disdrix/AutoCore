# Annotated low-level: CVOGHBBase_Start

| Field | Value |
|---|---|
| Stable ID | `aa_005081c0` |
| VA | `0x005081c0`–`0x005081cf` |
| System | heartbeat / timed-actions |
| Date | 2026-07-29 (residual; prior 2026-07-23) |

## Machine-level notes

- Source: raw capture + live `decompile_function` / `read_memory` (2026-07-29).
- **fDormant** is byte at **`this+0x21`** (not a bitfield in this path).
- **OnStart** is **`*( *this + 4 )`** via **`jmp [eax+4]`** (tail-call). Decompiler warning “Could not recover jumptable” is noise.
- Calling convention: **thiscall/fastcall ECX this**, **no stack args**, epilogue **`C3 ret`**.
- Sibling **Stop** at `0x005081d0`: inverse dormant set + `jmp [eax+0x10]` OnEnd.
- Prefer bytes when decompiler names drift; CF here is 1:1 with bytes.

## Byte map

| VA | Bytes | Meaning |
|---|---|---|
| `005081c0` | `80 79 21 00` | `cmp byte [ecx+0x21], 0` |
| `005081c4` | `74 09` | `jz` → bare ret (already started) |
| `005081c6` | `8B 01` | `mov eax, [ecx]` vtbl |
| `005081c8` | `C6 41 21 00` | `mov byte [ecx+0x21], 0` |
| `005081cc` | `FF 60 04` | `jmp [eax+4]` OnStart |
| `005081cf` | `C3` | `ret` (idle path) |

## Pseudocode (annotated)

```c
void __fastcall CVOGHBBase_Start(CVOGHBBase *this)
{
  /* +0x21 fDormant; ctor sets 1 */
  if (this->fDormant != false) {
    this->fDormant = false;
    /* tail-call OnStart — not a multi-way jumptable */
    (**(code **)((int)this->pVTable + 4))();
    return;
  }
  return;
}
```

## Cross-unit contracts (context only)

- **TryFire**: period due + still dormant → status Inactive (2); no OnHeartBeat.
- **Enqueue**: separate; Start does not schedule into pending list.
- **OKToCastAgain_OnStart**: subclass stamps casting flag (not base Start).

## Open questions

- Exhaustive Start-without-Enqueue / Enqueue-without-Start call-site matrix.
- Product PDB name for vtbl+4 slot.
