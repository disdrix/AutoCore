# Annotated low-level: CVOGHBAICreatureBase_ctor

| Field | Value |
|---|---|
| Stable ID | a_005d3c40 |
| VA | 0x005d3c40 |
| System | unknown |
| Date | 2026-07-23 |
| Refined | manager-pass industrial |

## Purpose (manager refine)

Creature AI base ctor.

## Named callees (decompiler)

- CVOGHBAICreatureBase_ctor
- CVOGHBAIBase_ctor

## Machine-level notes

- Source: raw capture for a_005d3c40.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.
- Manager refine: case table + callees extracted; full dual review still open.

## Pseudocode (annotated copy of raw)

`c
undefined4 * __thiscall
CVOGHBAICreatureBase_ctor(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  CVOGHBAIBase_ctor(param_2,param_3);
  *param_1 = &PTR_LAB_009dab50;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  return param_1;
}
`

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Dual independent reconstruction review for this manager unit.
