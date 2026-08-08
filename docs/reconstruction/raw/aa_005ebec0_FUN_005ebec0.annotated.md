# Annotated low-level: VOGPhysics_SphereQueryCollect_Ctor_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005ebec0` |
| VA | `0x005ebec0`–`0x005ebef0` inclusive (**49 B** / `0x31`) |
| Ghidra name | `FUN_005ebec0` |
| Proposed name | `VOGPhysics_SphereQueryCollect_Ctor_Inferred` |
| System | interaction-activation |
| Partition | MEGA-070 OWN-ONLY (parent `0x004ea350` CVOGPhysicsUtils::GetObjectsInArea) |
| Date | 2026-08-05 (MEGA-070 live re-verify) |

---

## Machine-level notes

- Source: raw capture `aa_005ebec0_FUN_005ebec0.md` + MEGA-070 APPEND.
- Prefer assembly when decompiler conflicts — here **decompile ≡ disasm ≡ bytes**.
- **thiscall RET 4**: ECX = this (0xD0 query object); stack = params/shape bundle*; EAX = this.
- Derived ctor over base `FUN_005eb210` (vtbl `009dcde0` family); installs derived vtbl `009dce90`.
- Collect triad at **+0xC0/+0xC4/+0xC8** matches MSVC empty-vector capacity encoding (`0x80000000`).
- Call sites always allocate **0xD0** / pool tag **0x2C** before construction.
- Dtor peer `FUN_005ebf00` walks `this[0x30]` count and frees via allocator — confirms collect-buffer role.
- Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_005ebec0` **retired** (wrong identity).

---

## Pseudocode (annotated)

```c
// thiscall: ECX = SphereQueryCollect*, stack = params* (shape/filter bundle from caller)
// returns this in EAX; RET 4
uint32_t * __thiscall VOGPhysics_SphereQueryCollect_Ctor_Inferred(
    uint32_t *self /* ECX */,
    uint32_t params /* stack [ESP+4] */)
{
  // 1) Base physics-query object ctor (shared with non-sphere family)
  FUN_005eb210(params);   // ECX still = self (thiscall)

  // 2) Install derived vtable (collect-capable sphere query class)
  *self = (uint32_t)&PTR_FUN_009dce90;   // this+0x00

  // 3) Empty result-collect buffer (begin / count / capacity-sentinel)
  self[0x30] = 0;              // this+0xC0  begin ptr
  self[0x31] = 0;              // this+0xC4  count
  self[0x32] = 0x80000000;     // this+0xC8  capacity (empty, high-bit sentinel)

  return self;
}
```

---

## Layout (sealed writes only)

| Off | Write | Role |
|----:|-------|------|
| `+0x00` | `PTR_FUN_009dce90` | derived vtbl |
| `+0xC0` | `0` | collect buffer begin |
| `+0xC4` | `0` | collect count |
| `+0xC8` | `0x80000000` | empty capacity sentinel |

Base ctor (`FUN_005eb210`, not dualled) fills lower fields / base vtbl before step 2 overwrites vtbl.

---

## Call graph (evidence only)

```text
FUN_004ea350  CVOGPhysicsUtils::GetObjectsInArea  (param_5==2 sphere)
  ├─ FUN_006c7fa0   sphere-shape setup (MEGA-071 residual)
  ├─ alloc 0xD0 / tag 0x2C
  ├─ FUN_005ebec0   VOGPhysics_SphereQueryCollect_Ctor_Inferred  [OWN MEGA-070]
  └─ FUN_00560c90(this+0xC, …)  collect into query

FUN_005dd080  (sphere branch when *(obj+0xdd)!=0)
  ├─ FUN_006c7fa0
  ├─ alloc 0xD0
  ├─ FUN_005ebec0   [OWN]
  └─ store at obj+0xD0

FUN_005ebf00  dtor peer (not dualled)
  └─ release +0xC0 triad then base teardown
```

---

## Open questions

1. Product/PDB class name for vtbl `009dce90` (no RTTI string on vtbl DATA xrefs).
2. Full 0xD0 field map beyond base + collect triad (base ctor residual).
3. Exact type of stack `params*` (shape/filter composite from `006c7fa0` + center/radius bundle).
4. Runtime Confirmed / bit-exact / differential.

---

## Confidence

| Claim | Level |
|---|---|
| CF + thiscall RET 4 + return this | **High** |
| Collect triad +0xC0 init | **High** |
| Sphere-query collect ctor role | **High** (GetObjectsInArea mode-2 + 0xD0 + dtor) |
| Product class English | **Open** → `_Inferred` |
| Runtime | **Open** |
