# Function record: FUN_004cbdc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbdc0` |
| **Canonical name** | `FUN_004cbdc0` (Ghidra); prefer named `SkillCNDHash_Recreate_Inferred` |
| **Address** | `0x004cbdc0`–`0x004cbe14` (**85 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (WQ9D-A 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md`, `B_aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9D-A OWN-ONLY) |

## Alias

- Ghidra: `FUN_004cbdc0`
- Scaffold: `Named_VOG_DEBUG_STOP_004cbdc0` (**do not promote**)
- Named: `SkillCNDHash_Recreate_Inferred`

## Purpose

Recreate skill-family CNDHash bucket table at new log2 size. Soft-logs if traversal-locked then continues; destroy + realloc via `FUN_004cba60` / `FUN_004cb410`.

## Signature

```c
void __thiscall FUN_004cbdc0(void *hash, unsigned char log2);
// stack cleanup: ret 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cbdc0_FUN_004cbdc0.md`
- Annotated: `docs/reconstruction/raw/aa_004cbdc0_FUN_004cbdc0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/SkillCNDHash_Recreate_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004cbdc0.cpp`
- Function named: `docs/reconstruction/functions/aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | `FUN_004cba60`, `FUN_004cb410`, `FUN_007a4480` ×2 |
| **Callers** | `FUN_00518e30` (`Object_CreateOrRecreateSkillHash_Inferred`), `FUN_004c8f00` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| thiscall + ret 4 | **High** |
| Role recreate / rebucket | **High** |
| Product English class | **Open** |
