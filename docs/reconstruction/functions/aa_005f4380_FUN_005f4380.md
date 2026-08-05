# Function record: GameUtils_ParseRagDollBoneCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f4380` |
| **Canonical name** | `GameUtils_ParseRagDollBoneCount_Inferred` |
| **Ghidra name** | `FUN_005f4380` |
| **Address** | `0x005f4380`–`0x005f441a` (**155 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | GameUtils / ragdoll buffer parse |
| **Completion status** | **Reviewed** — dual A/B accept W27-H (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_005f4380`
- Prior scaffold mis-tag: `Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_005f4380` — **superseded** (caller is `GameUtils_createRagDoll`, not skybox).
- Inferred name from sole caller plate `GameUtils::createRagDoll` + return used as bone count.

## Purpose

SEH-framed ragdoll-buffer parse wrapper: build two short-lived containers, run `FUN_005f4230` token walk, tear down, return bone/slot count for `GameUtils_createRagDoll` limit checks.

## Signature (sealed)

```c
// cdecl; EAX = count
uint32_t FUN_005f4380(uint32_t param_1, uint32_t param_2, int param_3,
                      uint32_t param_4, uint32_t param_5);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005f4380_FUN_005f4380.md` (+ W27-H append)
- Annotated: `docs/reconstruction/raw/aa_005f4380_FUN_005f4380.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GameUtils_ParseRagDollBoneCount_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005f4380.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005f4380_GameUtils_ParseRagDollBoneCount_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005f4380_GameUtils_ParseRagDollBoneCount_Inferred.md`

## Callers / callees

| Direction | Symbols |
|---|---|
| Callers (1) | `GameUtils_createRagDoll` / `FUN_005f44c0` @ `0x005f45af` |
| Callees (5) | `FUN_005f3120`, `FUN_005f3160`, `FUN_005f4230`, `FUN_00646d90`, `FUN_00646dd0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live ≡ bytes | **High** |
| cdecl + SEH + 155 B body | **High** |
| Sole caller createRagDoll + count role | **High** |
| 5-formal arity (vs parent 2-arg surface) | **High** (bytes) |
| Parameter product English | **Tentative** |
| Nested helper semantics | **Probable** (decompile only; not OWN) |
