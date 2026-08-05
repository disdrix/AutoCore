# Annotated low-level: WorldObj_UnbindLinks_Inferred (FUN_0055fbf0)

| Field | Value |
|---|---|
| Stable ID | `aa_0055fbf0` |
| VA | `0x0055fbf0`–`0x0055fd72` (**386 B**) |
| System | world-object / manager unbind |
| Date | 2026-07-29 (W26-D re-seal; scaffold 2026-07-23) |
| Ghidra name | `FUN_0055fbf0` |
| Canonical (inferred) | `WorldObj_UnbindLinks_Inferred` |

## Machine-level notes

- **ABI:** `__thiscall`; **ECX** = manager; stack `Object* obj`; epilogue **`ret 4`** (both exits); void.
- **Role (caller-sealed):** first step of rebind (`FUN_00560e90`: unbind → bind `0055fa40` → flag) and of remove/defer (`FUN_00561450` unbind chain). Prior duals label this **unbind / remove links**.
- **Always runs:** `FUN_0062d960(*(manager+0x234))` at entry; `FUN_0055f4c0` on a stack-local alloc descriptor before every return (fastcall cleanup of temp buffer / heap bookkeeping via `DAT_00b05060`).
- **Gate:** `*(obj+0xc) != 0` **and** virtual call `(*(**(manager+0xc4))+0xc)(obj+0x1c, &queryOut)` producing count `iStack_34 > 0`.
- **Branch `*(obj+0x40)`:**
  - **0:** simple `FUN_006297e0(0,0, queryOut.a, queryOut.count)` then exit cleanup.
  - **≠0:** install stack vtable object `PTR_FUN_009d2820` at `*(manager+0x138)+0x24`; optional base `*(manager+0xd0)+8`; `FUN_006caaa0(0,0,a,count,base)`; restore slot to `manager+0x138+0x100`; loop collected entries → `FUN_006297e0` + zero `entry+0x90`; if capacity signed ≥0 free via `(*DAT_00b05060+0x14)(buf, cap*4, 0x12)`.
- **Callees (OWN sealed list):** `FUN_0062d960`, `FUN_006297e0`, `FUN_006caaa0`, `FUN_0055f4c0`, vcall `*(mgr+0xc4)+0xc`, allocator vcall. Analyze also lists `FUN_005b3300` (growth; decompiler unreachable-block warning at `0x0055fcee`).
- **Callers:** `FUN_00560e90`, `FUN_00561450`, `FUN_005614f0`, `FUN_00561370` (5 xrefs).

## Pseudocode (annotated)

```c
// thiscall; ret 4; void
void __thiscall WorldObj_UnbindLinks_Inferred(int manager /*ECX*/, int obj /*stack*/)
{
  uint32_t out_a;     // local_38
  int out_count;      // iStack_34
  // ... stack callback object + temp vector for complex path ...

  FUN_0062d960(*(uint32_t *)(manager + 0x234));

  if (*(int *)(obj + 0xc) != 0 &&
      ((**(code **)(**(int **)(manager + 0xc4) + 0xc))(obj + 0x1c, &out_a), out_count > 0)) {
    if (*(char *)(obj + 0x40) == 0) {
      FUN_006297e0(0, 0, out_a, out_count);
    } else {
      // complex: setup PTR_FUN_009d2820 callback on *(manager+0x138)+0x24
      // FUN_006caaa0(...); restore slot; for each hit FUN_006297e0 + clear +0x90
      // optional free tag 0x12 via DAT_00b05060
    }
  }
  FUN_0055f4c0(/* stack alloc descriptor */);
}
```

## Open residual

- Product English for manager class / query interface at `manager+0xc4`.
- Full contracts of nested `0062d960` / `006297e0` / `006caaa0` / `0055f4c0` (not OWN; W26-E owns bind twin `0055fa40`).
- Runtime / bit-exact — open.
- Exact semantics of `obj+0x40` flag (simple vs complex unbind path).
