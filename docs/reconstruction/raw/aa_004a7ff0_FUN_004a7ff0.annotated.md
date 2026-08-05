# Annotated low-level: FUN_004a7ff0

| Field | Value |
|---|---|
| Stable ID | `aa_004a7ff0` |
| VA | `0x004a7ff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004a7ff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004a7ff0(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    if ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 0) {
      iVar1 = (param_3 - iVar1) / 0x1c;
      goto LAB_004a8039;
    }
  }
  iVar1 = 0;
LAB_004a8039:
  FUN_004a7ad0(param_3,1,param_4);
  *param_2 = *(int *)(param_1 + 4) + iVar1 * 0x1c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.

---

## W37-W annotated append (2026-08-04)

### Sealed identity

| Field | Value |
|---|---|
| Structural name | `StdVector_InsertOne_RebindIt_BasicStringW` (**Inferred**) |
| Body | `0x004a7ff0`–`0x004a8063` exclusive (**115 B**) |
| ABI | `__thiscall` ECX=`vector*`; stack `outIt*`, `where*`, `value*`; **RET 0x0C** |
| Stride | **0x1c** (`basic_string<wchar_t>` MSVC layout) |
| Callee | `StdVector_InsertN_BasicStringW` (`0x004a7ad0`) with **count=1** |
| Caller | `FUN_004a8100` push_back slow path @ `0x004a817d` |

### Machine notes

- Magic imul `0x92492493` + shift for signed `/ 0x1c` on both size and index.
- Rebind: `lea edx,[esi*8]; sub edx,esi; lea ecx,[eax+edx*4]` → `begin + index*28`.
- Do **not** treat Ghidra's `FUN_004a7ad0(param_3,1,param_4)` as free-function — bytes `mov ecx,edi` before call.
- Empty/null begin → index 0 (insert still runs).

### Open residual

- Product STL demangle English.
- Runtime / bit-exact after realloc.
