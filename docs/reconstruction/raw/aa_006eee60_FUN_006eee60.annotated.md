# Annotated low-level: FUN_006eee60

| Field | Value |
|---|---|
| Stable ID | `aa_006eee60` |
| VA | `0x006eee60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006eee60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
char * FUN_006eee60(undefined4 param_1)

{
  switch(param_1) {
  default:
    return "unknown";
  case 1:
    return "HK_SHAPE_CONVEX";
  case 2:
    return "HK_SHAPE_COLLECTION";
  case 3:
    return "HK_SHAPE_BV_TREE";
  case 4:
    return "HK_SHAPE_SPHERE";
  case 5:
    return "HK_SHAPE_TRIANGLE";
  case 6:
    return "HK_SHAPE_BOX";
  case 7:
    return "HK_SHAPE_CAPSULE";
  case 8:
    return "HK_SHAPE_CONVEX_VERTICES";
  case 9:
    return "HK_SHAPE_MULTI_SPHERE";
  case 10:
    return "HK_SHAPE_LIST";
  case 0xb:
    return "HK_SHAPE_TRIANGLE_COLLECTION";
  case 0xc:
    return "HK_SHAPE_MULTI_RAY";
  case 0xd:
    return "HK_SHAPE_HEIGHT_FIELD";
  case 0xe:
    return "HK_SHAPE_SAMPLED_HEIGHT_FIELD";
  case 0xf:
    return "HK_SHAPE_TRI_PATCH";
  case 0x10:
    return "HK_SHAPE_SPHERE_REP";
  case 0x11:
    return "HK_SHAPE_BV";
  case 0x12:
    return "HK_SHAPE_PLANE";
  case 0x13:
    return "HK_SHAPE_MOPP";
  case 0x15:
    return "HK_SHAPE_TRANSFORM";
  case 0x16:
    return "HK_SHAPE_PHANTOM_CALLBACK";
  case 0x17:
    return "HK_SHAPE_UTILITY_CONVEX_SWEEP";
  case 0x18:
    return "HK_SHAPE_USER0";
  case 0x19:
    return "HK_SHAPE_USER1";
  case 0x1a:
    return "HK_SHAPE_USER2";
  case 0x1b:
    return "HK_SHAPE_USER3";
  case 0x1c:
    return "HK_SHAPE_USER4";
  case 0x1d:
    return "HK_SHAPE_USER5";
  case 0x1e:
    return "HK_SHAPE_USER6";
  case 0x1f:
    return "HK_SHAPE_USER7";
  case 0xffffffff:
    return "HK_SHAPE_ALL";
  }
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
