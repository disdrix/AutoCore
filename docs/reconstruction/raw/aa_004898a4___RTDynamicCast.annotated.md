# Annotated low-level: __RTDynamicCast

| Field | Value |
|---|---|
| Stable ID | `aa_004898a4` |
| VA | `0x004898a4`–`0x004898a9` (**6 B**) |
| System | interaction-activation (partition R10-011; CRT helper used widely) |
| Date | 2026-08-05 (R10-011 refresh) |
| Classification | **MSVC IAT thunk** → `__RTDynamicCast` |
| Ghidra name | `__RTDynamicCast` (import symbol; not `FUN_*`) |

---

## Machine-level notes

- **Body is not game logic.** Six-byte import trampoline:
  - `FF 25 48 66 9C 00` → `jmp dword ptr [PTR___RTDynamicCast_009c6648]`
- Ghidra decompile shows a fake recursive call / “jumptable” warning — **ignore** for semantics; prefer bytes + IAT xrefs.
- Real work is MSVC RTTI `dynamic_cast` helper in the CRT (`msvcr*` family). Image only holds the IAT jump.
- Callers use **cdecl**, **5 stack args**, clean with **`ADD ESP,0x14`** (20 bytes).
- Parent dual `FUN_00938670` (`0x00938670`): cast resolved object from `CVOGClonedObjectBase` RTTI → `CVOGStore` RTTI (`isReference=0`, `VfDelta=0`).
- Partition system tag is interaction-activation because parent is interaction path; the thunk itself is **cross-cutting CRT** (skills, inventory, UI, missions, … — 100+ call sites).

---

## Pseudocode (annotated — thunk authority)

```c
/* IAT thunk only — does not implement cast math in-image */
/* jmp dword ptr [0x009C6648]  ; PTR___RTDynamicCast */

void* __cdecl __RTDynamicCast(
    void* inptr,
    long  VfDelta,
    TypeDescriptor* srcType,
    TypeDescriptor* targetType,
    int   isReference)
{
    /* tail-transfer to CRT via IAT; no local prolog/epilog */
    return /* CRT __RTDynamicCast */(inptr, VfDelta, srcType, targetType, isReference);
}
```

Ghidra raw scaffold (non-authoritative body):

```c
void __RTDynamicCast(void)
{
  /* WARNING: Treating indirect jump as call */
  __RTDynamicCast();
  return;
}
```

---

## Call-site pattern (sealed)

```text
push isReference      ; bool/int
push targetType       ; TypeDescriptor*
push srcType          ; TypeDescriptor*
push VfDelta          ; long (often 0)
push inptr            ; void* object or null
call __RTDynamicCast  ; 0x004898a4
add  esp, 14h         ; cdecl 5*4
; EAX = cast result or NULL
```

---

## Open questions / gaps

1. Exact CRT DLL version / full cast-graph implementation — external; not dualled here.
2. Exhaustive per-caller TypeDescriptor pairs (100+ sites) — role sealed; inventory of every cast pair open.
3. Runtime / bit-exact / differential of CRT path — open (Terminal false).
4. Ghidra prototype remains `void __RTDynamicCast(void)` until symbol prototype repair (out of OWN-ONLY ledger scope).
