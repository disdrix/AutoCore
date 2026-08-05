# Function record: Skill_ApplyBoundStatusMotionIfPresent_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2f20` |
| **Canonical name** | `Skill_ApplyBoundStatusMotionIfPresent_Inferred` |
| **Ghidra symbol** | `FUN_004c2f20` |
| **Address** | `0x004c2f20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **dual A/B accept-with-gaps** — 2026-07-29 W21-H; CF + ABI + sole caller sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_004c2f20`
- Prior scaffold: `Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_004c2f20` (discard as role-vague)
- Prior record: `functions/aa_004c2f20_FUN_004c2f20.md`

## Purpose

Thin **gate + tail** wrapper used from skill apply-effects: when a caster **vtbl+0x214** binding object has a non-null pointer at **`+0x1FC`**, forward **`(sub, skillId)`** into **`FUN_005d0d60`** (status/motion table apply). Otherwise return immediately.

## Signature (machine-sealed)

```c
void __thiscall Skill_ApplyBoundStatusMotionIfPresent_Inferred(
    void *boundObj /* ECX */,
    int skillId /* [esp+4], RET 4 */);
// Body 0x004c2f20–0x004c2f31; CC pad after
```

Decompiler may show `__fastcall` / omit stack arg / zero-arg callee — **do not trust**; use bytes.

## Layout (this = boundObj from caster vtbl+0x214)

| Off | Use |
|---:|---|
| `+0x1FC` | Controller / sub-object pointer; null → no-op; non-null → `this` for `FUN_005d0d60` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c2f20_FUN_004c2f20.md` (+ 2026-07-29 append)
- Annotated: `docs/reconstruction/raw/aa_004c2f20_FUN_004c2f20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_ApplyBoundStatusMotionIfPresent_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_004c2f20.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004c2f20_Skill_ApplyBoundStatusMotionIfPresent_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004c2f20_Skill_ApplyBoundStatusMotionIfPresent_Inferred.md`

## Callers / callees

**Callees:** `FUN_005d0d60` (tail JMP).

**Callers (1):** `Skill_ApplyEffectsOnTarget_Inferred` (`0x005538a0`) site `0x00553936`.

## Confidence

| Claim | Level |
|---|---|
| CF: null gate on +0x1FC → ret / else tail | **High** |
| ABI: thiscall + 1 stack dword + RET 4 | **High** (bytes) |
| Tail JMP to `0x005d0d60` with ECX replaced | **High** |
| skillId formal role | **High** (caller pushes skill+0x5FC) |
| Product type names for boundObj / +0x1FC | **Tentative** (`_Inferred`) |
| Runtime / bit-exact | Open |
