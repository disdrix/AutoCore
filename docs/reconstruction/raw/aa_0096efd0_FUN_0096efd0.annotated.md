# Annotated low-level: FUN_0096efd0

| Field | Value |
|---|---|
| Stable ID | `aa_0096efd0` |
| VA | `0x0096efd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0096efd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0096efd0(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009ac21a;
  pvStack_c = ExceptionList;
  local_4 = 0;
  iVar2 = *param_1;
  ExceptionList = &pvStack_c;
  if (iVar2 != 0) {
    piVar1 = (int *)(iVar2 + 8);
    ExceptionList = &pvStack_c;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*(int *)(iVar2 + 4) + 8))();
    }
    *param_1 = 0;
  }
  local_4 = 0xffffffff;
  iVar2 = *param_1;
  if (iVar2 != 0) {
    piVar1 = (int *)(iVar2 + 8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*(int *)(iVar2 + 4) + 8))();
    }
  }
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.

# W38-P re-verify append (2026-08-04)

## Annotated CF (bytes)

MSVC SEH-wrapped dtor for a 4-byte refcounted handle:

1. **Try (state 0):** if `payload = *handle` non-null → `--payload->refcount@+8`; on zero call `payload->iface@+4` method at vtbl+8 with this=`payload+4`; then `*handle = 0`.
2. **Cleanup (state -1):** same release **without** nulling — only runs if EH unwind sees incomplete destroy; after successful try, `*handle` is already 0 so this is a no-op on the happy path.

Decompiler appears to "double-release" — that is the SEH state machine, not two live releases on one path.

## Callers (sample, real CODE)

| Site | Pattern |
|------|---------|
| `CVOGTacArc_dtor_helper` | dual teardown after mesh free |
| `FUN_004c0a90` / `004c1cb0` | stack temp handle after `00970140` |
| `FUN_0075b550` | GfxView field `+0x13c` |
| `FUN_00583170` | paint asset temp |
| Many `Unwind@009a****` | EH cleanup registrations |

## Confidence

| Claim | Level |
|-------|-------|
| Body 107 B / `ret` | Confirmed |
| ECX = handle* | Confirmed |
| rc@+8, iface@+4, vtbl+8 | Confirmed |
| SEH dual-shape | Confirmed |
| Product payload RTTI | Open |
