# Annotated low-level: FUN_004cd8f0 → Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004cd8f0` |
| VA | `0x004cd8f0`–`0x004cd991` exclusive (**161 B**) |
| System | host owned 0x30 grid-list object replace + populate |
| Date | 2026-08-04 (W38-S) |
| Named | `Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred` |

## Machine-level notes

- **Authority:** `read_memory` body + decompile CF. **No** `disassemble_bytes`.
- **ABI:** thiscall; ECX=host; 4 stack args; void; **`ret 0x10`**.
- **Decompile gap:** populate call shows bare `FUN_005b3fa0(args…)` — bytes set **ECX = new 0x30 object** before call.
- Pairs with sealed W30-O ctor `FUN_005b3f60` and W37-L populate `FUN_005b3fa0`.

## Host layout (relevant)

| Offset | Role |
|---|---|
| `+0xe4f8` | nested object* (scale source: `*(nested+0x18)`) |
| `+0xe4fc` | owned **0x30** grid-list object* (replaced here) |

## Control flow

```
SEH prolog (LAB_009a1eb7)
if host.e4fc != null:
  host.e4fc->vtbl[0](1)   // scalar-deleting dtor
  host.e4fc = null
p = operator_new(0x30)
if p: obj = FUN_005b3f60(p) else obj = null   // default ctor
host.e4fc = obj
// ECX = obj (bytes)
FUN_005b3fa0(dim_a, dim_b, dim_c, *(host.e4f8 + 0x18) /*scale*/, ctx)
SEH epilog; ret 0x10
```

## Pseudocode (annotated)

```c
// __thiscall host; stack (float a, float b, float c, void *ctx); ret 0x10
void Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred(
    void *host, float dim_a, float dim_b, float dim_c, void *ctx)
{
  void **slot = (void **)((char *)host + 0xe4fc);
  if (*slot) {
    ((void (__thiscall *)(void *, int))**(void ***)*slot)(*slot, 1);
    *slot = 0;
  }
  void *p = operator_new(0x30);
  void *obj = p ? Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20(p) : 0;
  *slot = obj;
  float scale = *(float *)(*(char **)((char *)host + 0xe4f8) + 0x18);
  // ECX = obj
  Obj_PopulateListAt10_ScaledGridFill_Inferred(obj, dim_a, dim_b, dim_c, scale, ctx);
}
```

Note: scale typed float by W37-L populate contract; raw load is dword from `nested+0x18`.

## Open / residual

- Product English for host class and nested `+0xe4f8` object.
- Zero Ghidra callers — live entry path undiscovered statically.
- Runtime / bit-exact / differential.
- OOM path: `host+0xe4fc = null` then populate still called with ECX=0 (bytes call after store) — risk if populate assumes non-null this.
