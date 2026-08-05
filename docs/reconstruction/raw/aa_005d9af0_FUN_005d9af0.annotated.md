# Annotated low-level: Drive_CollisionListener_PlayCollisionEffect

| Field | Value |
|---|---|
| Stable ID | `aa_005d9af0` |
| VA | `0x005d9af0`–`0x005d9e94` |
| Ghidra | `FUN_005d9af0` |
| Canonical | `Drive_CollisionListener_PlayCollisionEffect` |
| System | drive / collision / client FX |
| Date | 2026-07-29 (W23-G dual seal) |

## Machine-level notes

- **String seal:** `"CollisionListener::PlayCollisionEffect"` @ `0x009db524`.
- **ABI seal:** `__thiscall` + `RET 0x14` (5 stack dwords). ECX = listener; stack3 = game object* (null-checked first).
- **this+4:** lazy `FxMaster*` (`operator_new(8)` + `FUN_004a1620` ctor + `FUN_004a6390` LoadMasterFromXML).
- **go+0xA8:** clonebase*; gate on clonebase+0x88 (prebound FX handle).
- **Callers:** contact hub `0x005da0a0` (flag=1), per-body prep `0x005d9ea0` (flag=0).
- Prefer bytes when decompiler omits formals or profiler string.

## Control flow (annotated)

```c
// __thiscall RET 0x14
void Drive_CollisionListener_PlayCollisionEffect(
    int this_listener,          // ECX; FxMaster* @ +4
    float *vec3_a,              // [ebp+8]
    uint32_t arg1,              // [ebp+c]
    uint32_t arg2,              // [ebp+10]
    int *gameObject,            // [ebp+14]  — Ghidra in_stack_00000010
    int8_t allowCreate)         // [ebp+18]  — Ghidra in_stack_00000014
{
  // SEH frame LAB_009a71fa
  if (gameObject == 0) return;  // before profiler

  FUN_0076cf00("CollisionListener::PlayCollisionEffect");
  int *clonebase = *(int **)((char *)gameObject + 0xA8);
  FUN_004eb3b0();               // bind/resolve against clonebase FX side

  if (*(int *)((char *)clonebase + 0x88) == 0) {
create_path:
    if (allowCreate == 0) goto leave;
    if (*(int *)(this_listener + 4) == 0) {
      void *p = operator_new(8);
      *(int *)(this_listener + 4) = p ? FUN_004a1620(/*FxMasterCatalog_Ctor*/) : 0;
      FUN_004a6390(/*LoadMasterFromXML*/);
    }
    if (*(int *)(this_listener + 4) == 0) goto leave;
    if (FUN_004a16d0(/*LoadEventVariant*/) == 0) goto leave;
  } else {
    FUN_004eb3b0();
    if (FUN_004a16d0() == 0) goto create_path;
  }

  // World / frame samples
  (**(code **)(*gameObject + 0x1C8))();
  (**(code **)(*gameObject + 0x1C8))();

  // Effect param math: uses vec3_a[0..2], constants 2.0f / 1.0f, more vec math
  FUN_004b7550(/*key*/1, /*float3*/…);  // NDSpecialFX_SetParamFloat3ByKey
  FUN_004b7550(/*key*/2, …);
  FUN_004b7550(/*key*/3, …);

  (**(code **)(*gameObject + 0xF8))(0, 1, fx_ctx);
  FUN_004b7e50(0, 0, 0);

leave:
  FUN_0076cef0();
  return;
}
```

## Offsets

| Offset | Meaning | Conf |
|---|---|---|
| this+4 | FxMaster* lazy slot | High |
| go+0xA8 | clonebase* | High |
| clonebase+0x88 | prebound FX / event handle | High |
| vtbl+0x1C8 | GO world/frame query | High |
| vtbl+0xF8 | GO FX attach/play | High |

## Open residual

- English names for stack1/stack2 beyond call-site wiring.
- Full float pipeline algebra (bit-exact) — constants 2.0 / 1.0 sealed; intermediate matrix residual.
- Nested callee contracts owned on their VAs (`004a1620`, `004a6390`, `004a16d0`, `004b7550`, `004b7e50`, `004eb3b0`).
