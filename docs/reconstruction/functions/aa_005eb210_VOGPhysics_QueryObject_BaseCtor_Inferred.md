# Function record: VOGPhysics_QueryObject_BaseCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb210` |
| **Canonical name** | `VOGPhysics_QueryObject_BaseCtor_Inferred` |
| **Ghidra name** | `FUN_005eb210` |
| **Address** | `0x005eb210`–`0x005eb2ac` (157 B / `0x9D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition parent** | `0x005ebec0` `VOGPhysics_SphereQueryCollect_Ctor_Inferred` |
| **Completion status** | **Dual sealed (R11-008)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Signature

```c
uint32_t * __thiscall VOGPhysics_QueryObject_BaseCtor_Inferred(
    uint32_t *self /* ECX */,
    uint32_t *params /* stack */);
// RET 4; EAX = self
// Base object core size: 0xC0 (derived add collect triad @ +0xC0 → 0xD0)
```

## Semantics (sealed)

```text
BaseQueryCtor(self, params):
  FUN_00581190(self, params[1], 2)          // sub-init on self; mode 2
  triadA(+0x3C) = {0, 0, 0x80000000}
  triadB(+0x48) = {0, 0, 0x80000000}
  self[+0x2C] = self
  *self = PTR_FUN_009dcde0                  // base vtbl
  float8(+0x60) = 0; W slots <- DAT_009dcddc (~1e30)
  self[+0x28] = params[0]
  self[+0x14] = &self[+0x60]
  self[+0x54] = vcall(object* @ +0xC, slot +0x14)
  FUN_005eb040(self+0x80, params+0x20)      // 16 dwords
  return self
```

## Naming rationale

- Family: `VOGPhysics_*Query*Ctor*` matches dualed derived `VOGPhysics_SphereQueryCollect_Ctor_Inferred`.
- Role: **base** ctor only — no collect triad at +0xC0 (that is derived).
- `_Inferred`: product/PDB class English for vtbl `009dcde0` open (sole DATA xref = this ctor).

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005eb210_FUN_005eb210.md` |
| Annotated | `docs/reconstruction/raw/aa_005eb210_FUN_005eb210.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_QueryObject_BaseCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005eb210.cpp` |
| FUN record | `docs/reconstruction/functions/aa_005eb210_FUN_005eb210.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_005eb210_VOGPhysics_QueryObject_BaseCtor_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005eb210_VOGPhysics_QueryObject_BaseCtor_Inferred.md` |
| Report | `docs/agents/task-dual-ab-005eb210-r11-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 4 / return this | **High** |
| Base-of-collect-ctors role | **High** (both 0xD0 derived call sites) |
| Offset map for written fields | **High** |
| Product English / full type map | **Open** |
| Runtime | **Open** |
