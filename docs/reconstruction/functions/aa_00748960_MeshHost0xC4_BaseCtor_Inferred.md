# Function record: MeshHost0xC4_BaseCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00748960` |
| **Canonical name** | `MeshHost0xC4_BaseCtor_Inferred` |
| **Address** | `0x00748960` |
| **Body** | `0x00748960`–`0x00748aaf` (**336 B** / `0x150`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | mesh / host graphics (0xC4 shell) |
| **Completion status** | **Dual A/B complete** (2026-07-29 W36-H) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_00748960` |

## Purpose

Placement-construct a **0xC4** multi-vtbl mesh/host object: primary/secondary/tertiary vtbls, two 8-byte vector-ctored subobjects, zeroed mid-fields, **+FLT_MAX** and **−FLT_MAX** float triples (AABB-style extremes), nested subobject at `+0x78`, and flag byte `\|0x81` at `+0xBC`. Returns `self`.

## Signature

```c
uint32_t * __fastcall MeshHost0xC4_BaseCtor_Inferred(uint32_t *self /* ECX */);
```

| Slot | Source | Conf |
|---|---|---|
| self | ECX thiscall/fastcall | **High** |
| return | EAX = self | **High** |
| object size | **0xC4** (callers `operator_new(0xC4)`) | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00748960_FUN_00748960.md`
- Annotated: `docs/reconstruction/raw/aa_00748960_FUN_00748960.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/MeshHost0xC4_BaseCtor_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00748960.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00748960_FUN_00748960.md`
- Dual A: `docs/reconstruction/reviews/A_aa_00748960_MeshHost0xC4_BaseCtor_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00748960_MeshHost0xC4_BaseCtor_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| ABI ECX + return this + size 0xC4 | **High** |
| Multi-vtbl + FLT_MAX pairs + flag 0x81 | **High** |
| Product class English | Open |
| Flag bit semantics | Open |
