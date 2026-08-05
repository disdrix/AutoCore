# Function record: ObjectMotion_IntegrateStep_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b1100` |
| **Canonical name** | `ObjectMotion_IntegrateStep_Inferred` |
| **Ghidra name** | `FUN_004b1100` |
| **Address** | `0x004b1100` |
| **Body span** | `004b1100`–`004b18e5` (**2021 B / `0x7E5`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object motion / reaction entity pose |
| **Convention** | `__thiscall` + **`ret 0xC`** (3 stack args); void |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; nested force helpers residual |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Dual A/B** | `reviews/A_aa_004b1100_ObjectMotion_IntegrateStep_Inferred.md`, `reviews/B_aa_004b1100_ObjectMotion_IntegrateStep_Inferred.md` (2026-07-29 W24-C) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Integrate one motion step on a motion slot: free / attach / path branches, orientation post-modes, optional host velocity.

## Signature

```c
// thiscall; ret 0xC
void __thiscall ObjectMotion_IntegrateStep_Inferred(
    int *motion_slot,
    int enable_heightfield_y,
    undefined4 ctx_flag,
    float dt);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b1100_FUN_004b1100.md`
- Annotated: `docs/reconstruction/raw/aa_004b1100_FUN_004b1100.annotated.md`
- Clean (mirror): `docs/reconstruction/reconstructed-exact/FUN_004b1100.cpp`
- Named: `docs/reconstruction/reconstructed-exact/ObjectMotion_IntegrateStep_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004b1100_FUN_004b1100.md`
- Review A/B: dual files above

## Callers / callees (sealed-relevant)

| Dir | VA | Name |
|---|---|---|
| Caller | `0x004b4620` | `FUN_004b4620` (site `0x004b48e8`) |
| Caller | `0x005bc120` | `FUN_005bc120` (site `0x005bc2ba`) |
| Callee | `0x004e8590` | `Math_QuatInverseRotateDelta_Inferred` |
| Callee | `0x004e8320` | quat peer (not dualed here) |
| Callee | `0x004cd220` | heightfield Y sample family |
| Callee | `0x005c36f0` / `005c4040` / `005c2de0` / `005c2030` | force helpers |
| Callee | `0x005c4e30` | attach sample |
| Callee | `0x004b49a0` | path point transform |
| Callee | `0x0076e240` / `0076e5e0` / `0076f5f0` / `0099b8b0` | vec/quat helpers |

## Confidence

| Claim | Level |
|---|---|
| CF skeleton ≡ live decompile | **High / Confirmed** |
| ABI ret 0xC | **Confirmed** |
| Role motion integrate | **High** |
| Nested force helper product names | **Open** |
| Product C++ name | **Inferred** |
| Runtime / differential | **Open** |

## Prior scaffold alias

`Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b1100` — rejected as role label.
