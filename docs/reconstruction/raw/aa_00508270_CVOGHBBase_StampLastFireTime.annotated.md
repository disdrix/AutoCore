# Annotated low-level: CVOGHBBase_StampLastFireTime

| Field | Value |
|---|---|
| Stable ID | `aa_00508270` |
| VA | `0x00508270` |
| Body | `0x00508270`–`0x00508278` |
| System | heartbeat / timed-actions |
| Date | 2026-07-29 (machine seal) |

## Machine-level notes

- Source: `read_memory` @ `0x00508270` length 16+ (body 9 bytes + INT3 pad).
- Prefer assembly when decompiler conflicts — **no conflict** here.
- Global: `g_dwClientTickMs` @ `0x00b041cc`.
- Field: `dwLastFireTickMs` @ `this+0x14`.
- Next function: `CVOGHBBase_GetRemainingSeconds` @ `0x00508280` (consumes `+0x14`).

## Bytes → ops

```
00508270  A1 CC41B000    mov  eax, dword ptr [0x00b041cc]  ; g_dwClientTickMs
00508275  89 41 14       mov  dword ptr [ecx+0x14], eax    ; this->dwLastFireTickMs
00508278  C3             ret
00508279  CC…            int3 padding
```

Hex body: `a1 cc 41 b0 00 89 41 14 c3`

## Pseudocode (annotated ≡ raw)

```c
void __fastcall CVOGHBBase_StampLastFireTime(CVOGHBBase *this /* ECX */)
{
  this->dwLastFireTickMs = g_dwClientTickMs;  // +0x14 ← [0x00b041cc]
  return;
}
```

## Call / xref notes

| Kind | Sites |
|---|---|
| Named code | `CVOGHBOKToCastAgain_OnStart` tail @ `0x0051e3a6`; `FUN_00578b30` CALL @ `0x00578c96`, `0x00578cd0` |
| Orphan code | tail JMP @ `0x005cc54a`, `0x005cc55b` (no containing function in Ghidra) |
| DATA | 28 method-table slots (see function record) |
| Callees | none |

## Open questions

- Owner name for `0x005cc54a` / `0x005cc55b` region.
- Per-class vtable slot index for DATA xrefs.
