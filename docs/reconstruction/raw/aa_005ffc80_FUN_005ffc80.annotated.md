# Annotated low-level: FUN_005ffc80 / EmptyStub_Ret4

| Field | Value |
|---|---|
| Stable ID | `aa_005ffc80` |
| VA | `0x005ffc80` |
| Body | `0x005ffc80`–`0x005ffc82` inclusive (**3 B** / `c2 04 00`); exclusive end `0x005ffc83` |
| Canonical name | `EmptyStub_Ret4` |
| System | shared / multi-domain nop leaf |
| Date | 2026-08-05 (R11-009 dual seal; prior scaffold 2026-07-23) |

## Machine-level notes

- Source: raw capture for `aa_005ffc80` + live re-verify R11-009.
- Prefer assembly when decompiler conflicts: decompiler shows bare `void` return; bytes are **`RET 0x4`**.
- Zero side effects — no loads, stores, or callees.
- Mass **DATA** vtable reuse; sole analyzed **CALL** is `FUN_0064d9f0` (nop before 8-dword field copy).
- Distinct from `EmptyRet` (`0x0056f570`, bare `c3`) and neighbor `FUN_005ffc90` (real work).

## Pseudocode (machine-corrected)

```c
// Machine ABI: callee cleans 4 stack bytes. Ignores ECX/this and stack arg.
// Decompiler displays void FUN_005ffc80(void) { return; } — CF empty, ABI incomplete.
void EmptyStub_Ret4(/* stack: 1 dword ignored */)
{
  return; /* ret 4 */
}
```

## ABI seal

| Item | Value | Evidence |
|---|---|---|
| Body bytes | `c2 04 00` | `read_memory` |
| Stack cleanup | 4 bytes (1 dword) | `RET 0x4` / `disassemble_function` |
| this / ECX | ignored | no body loads |
| Return value | undefined / untouched | no `mov eax` |
| Callees | none | analyze + body |

## Open questions

- Product / PDB symbol for this shared empty.
- Exhaustive DATA-slot census (100+ hits; CF seal does not need it).
- Whether every DATA site is a true vtbl slot vs other pointer tables (sample sites confirmed as vtbls).
