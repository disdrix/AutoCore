# Function record: Object_DoFullInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516be0` |
| **Canonical name** | `Object_DoFullInit_Inferred` |
| **Ghidra name** | `FUN_00516be0` |
| **Address** | `0x00516be0` |
| **Body** | `0x00516be0` – `0x00516c30` (80 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / load-init |
| **Classification** | helper / vtable method (shared) |
| **Completion status** | **accept-with-gaps** — Dual A/B W24-G 2026-07-29; CF sealed High |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Object **full-init** epilogue: optionally run `vtbl+0x100` based on related-object flag `+0x2ac`, always run `vtbl+0x48`, then refresh active skill effects unless clonebase type is **0x12** or **0x14**.

## Signature (decompiler + byte sealed)

```c
void __thiscall Object_DoFullInit_Inferred(void *thisObj);
// ECX = this; void; no stack args (pop esi; ret)
```

| Item | Value |
|---|---|
| Convention | `__thiscall` / ECX this (Ghidra may label `__fastcall`) |
| Return | void |
| Direct callees | `FUN_00516a00` (`Object_RefreshActiveSkillEffects_Inferred`) |
| Virtual callees | `+0x1d4`, `+0x100`, `+0x48` |

## Algorithm

```
related = vtbl[+0x1d4]()
if related == null OR *(related + 0x2ac) == 0:
    vtbl[+0x100]()
vtbl[+0x48]()
type = *(clonebase(this[+0xa8]) + 0x38)
if type != 0x12 && type != 0x14:
    Object_RefreshActiveSkillEffects_Inferred(this, 1)
```

## Related

| VA / slot | Role |
|---|---|
| `0x00516a00` | Skill effect refresh (param `1` = all active) |
| `0x005c78a0` | `CLoadNode::_initFull` caller |
| `vtbl+0x1d4` | Related body/parent/vehicle getter (prior art) |
| types `0x12`/`0x14` | Skip skill refresh |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00516be0_FUN_00516be0.md`
- Annotated: `docs/reconstruction/raw/aa_00516be0_FUN_00516be0.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_00516be0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/Object_DoFullInit_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00516be0_Object_DoFullInit_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00516be0_Object_DoFullInit_Inferred.md`
- Report: `docs/agents/task-dual-ab-w24g-00512460-00516be0-report.md`

## Callers / callees

**Callees:** `FUN_00516a00`; virtuals `+0x1d4`, `+0x100`, `+0x48`.

**Callers:** `FUN_005c78a0` (`CLoadNode::_initFull`), `FUN_0053e0d0`, `FUN_00581b30`, `FUN_005d5140`; DATA/vtable installs at `009ce300`, `009d3478`, `009d4200`, `009dbcb0`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / gates / offsets | **High** |
| ECX this, void | **High** |
| Skill refresh callee + param `1` | **High** |
| Name “DoFullInit” role | **High** (caller string + `_initFull`) |
| Product names of virtuals / `+0x2ac` | **Tentative** |
| Type 0x12/0x14 English labels | **Probable** (prior interact docs; not re-sealed here) |
