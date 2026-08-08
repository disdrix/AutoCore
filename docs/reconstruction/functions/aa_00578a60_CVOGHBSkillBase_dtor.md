# Function record: CVOGHBSkillBase_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578a60` |
| **Canonical name** | `CVOGHBSkillBase_dtor` |
| **Ghidra name** | `FUN_00578a60` |
| **Address** | `0x00578a60`–`0x00578ab2` inclusive |
| **Body range** | 83 B / `0x53` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual sealed 2026-08-05 R12-026** — trio + A/B; **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00578a60_CVOGHBSkillBase_dtor.md`, `reviews/B_aa_00578a60_CVOGHBSkillBase_dtor.md` |
| **Last reviewed** | `2026-08-05` (R12-026) |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |

## Naming evidence

| Source | Value |
|---|---|
| Vtbl identity | Restores `PTR_FUN_009d3fdc` (same as ctor install) |
| Class RTTI | COL on vtbl → type_info `".?AVCVOGHBSkillBase@@"` (dualed ctor / scalar dtor) |
| Scalar sibling | `CVOGHBSkillBase_ScalarDeletingDtor` @ `0x00578de0` (vtbl[0]) always calls this, then optional free |
| Base twin pattern | `CVOGHBBase_dtor` @ `0x00508390` (complete body, no free) |
| Pattern | MSVC complete dtor body (no flags; no `operator_delete(this)`) |
| Product mangled on this VA | **Open** |

**Decision:** promote **`CVOGHBSkillBase_dtor`** (class RTTI Confirmed + complete-body role sealed; family name matches dualed `CVOGHBBase_dtor`). No `_Inferred` — same gate as parent scalar dual R11-006. Product mangled remains open.

## Purpose

Complete teardown for skill HB base class instance fields:

1. Restore `*this = PTR_FUN_009d3fdc`.
2. `operator_delete[]` owned array at `+0x6a0` (ctor: `FUN_0058ab60` → `operator_new__(0x4b0)`).
3. Free pointer-vector buffer at `+0x6b0` (no element walk) and zero begin/end/cap.
4. Tail-jump `CVOGHBBase_dtor` (base vtbl + optional owner detach).

## Signature

```c
void __thiscall CVOGHBSkillBase_dtor(void *thisHb /* ECX */);
// no stack args; JMP CVOGHBBase_dtor — does not free this
```

## Offsets

| Offset | Role | Conf |
|---|---|---|
| `+0x0` | vtbl → `PTR_FUN_009d3fdc` | **Confirmed** |
| `+0x6a0` | array heap (delete[]) | **Confirmed** layout; product English **Open** |
| `+0x6b0` | vector begin (delete buffer) | **Confirmed** |
| `+0x6b4` | vector end (zero) | **Confirmed** |
| `+0x6b8` | vector capacity (zero) | **Confirmed** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00578a60_FUN_00578a60.md`
- Annotated: `docs/reconstruction/raw/aa_00578a60_FUN_00578a60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_dtor.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00578a60.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00578a60_FUN_00578a60.md`
- Report: `docs/agents/task-dual-ab-00578a60-r12-report.md`

## Callers / callees

**CODE:** scalar dtor `0x00578de0`; thunk `0x00548f90`; 6 EH Unwind frames.  
**Callees:** `operator_delete[]`, `operator_delete`, `CVOGHBBase_dtor` / `FUN_00508390`.

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI | **Confirmed** (static assembly) |
| Class + role complete dtor | **Confirmed** |
| Product mangled / field English | **Open** |
| Runtime / bit-exact / differential | **Open** |
