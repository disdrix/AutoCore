# Function record: CVOGHBSkillBase_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578de0` |
| **Canonical name** | `CVOGHBSkillBase_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_00578de0` |
| **Address** | `0x00578de0`–`0x00578dfe` exclusive |
| **Body range** | 30 B / `0x1E` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual sealed 2026-08-05 R11-006** — trio + A/B; **accept** |
| **Dual A/B** | `reviews/A_aa_00578de0_CVOGHBSkillBase_ScalarDeletingDtor.md`, `reviews/B_aa_00578de0_CVOGHBSkillBase_ScalarDeletingDtor.md` |
| **Last reviewed** | `2026-08-05` (R11-006) |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |

## Naming evidence

| Source | Value |
|---|---|
| Vtbl slot 0 | `PTR_FUN_009d3fdc+0` → this VA (`read_memory` LE `E08D5700`) |
| Ctor dual | `CVOGHBSkillBase_ctor` @ `0x005788d0` installs same vtbl; RTTI `".?AVCVOGHBSkillBase@@"` |
| Complete dtor sibling | `FUN_00578a60` (restores same vtbl; no free) |
| Pattern | MSVC scalar deleting dtor (`flags&1` → `operator_delete`; `ret 4`) |
| Base twin | `CVOGHBBase_ScalarDeletingDtor` @ `0x00508630` (same ABI shape) |

**Decision:** promote **`CVOGHBSkillBase_ScalarDeletingDtor`** (class RTTI Confirmed + role sealed; product mangled open — no `_Inferred`).

## Purpose

MSVC scalar deleting destructor for skill HB base class:

1. `FUN_00578a60(this)` — complete teardown (owned buffers + base dtor).
2. If `(flags & 1)` → `operator_delete(this)`.
3. Return `this`.

## Signature

```c
void *__thiscall CVOGHBSkillBase_ScalarDeletingDtor(void *thisHb /* ECX */, uint8_t flags);
// ret 4; EAX = this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00578de0_FUN_00578de0.md`
- Annotated: `docs/reconstruction/raw/aa_00578de0_FUN_00578de0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_ScalarDeletingDtor.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00578de0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00578de0_FUN_00578de0.md`
- Report: `docs/agents/task-dual-ab-00578de0-r11-report.md`

## Callers / callees

**CODE callers:** none.  
**DATA:** `0x009d3fdc` vtbl[0].  
**Callees:** `FUN_00578a60`, `operator_delete`.

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI | **Confirmed** |
| Class + vtbl[0] role | **Confirmed** |
| Product mangled | **Open** |
