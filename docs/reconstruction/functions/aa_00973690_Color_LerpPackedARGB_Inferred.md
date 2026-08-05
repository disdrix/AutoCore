# Function record: Color_LerpPackedARGB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00973690` |
| **Canonical name** | `Color_LerpPackedARGB_Inferred` |
| **Ghidra** | `FUN_00973690` |
| **Address** | `0x00973690`–`0x0097376e` (**222 B**) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | graphics / color |
| **Wave** | W28-F dual seal 2026-07-29 |
| **Verdict** | **accept** |

## Signature

```c
// ECX = dest packed color; stack (t, c0, c1); ret 0x0C
void __fastcall Color_LerpPackedARGB_Inferred(uint32_t *dest, float t, uint32_t c0, uint32_t c1);
```

## Sealed behavior

1. `t' = clamp(t, 0.0, g_flOne)` with `g_flOne@0x00a0f2a0 = 1.0f`.
2. Channel-wise lerp of `c0→c1` as `0xAARRGGBB` (integer delta → float).
3. `FUN_00973590(R,G,B,A)` with `EAX=dest` packs/clamps 0..255 into `*dest`.

## Port notes

- Preserve **ECX dest** (in-place write); do not treat as pure stack-only cdecl.
- Preserve **ret 0x0C** / three stack formals.
- Integer cast on channel delta before float multiply matches retail SSE `cvtsi2ss` path.
- Nested pack helper may clamp; do not double-clamp differently without dual of `00973590`.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00973690_FUN_00973690.md` |
| Annotated | `docs/reconstruction/raw/aa_00973690_FUN_00973690.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Color_LerpPackedARGB_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00973690.cpp` |
| A/B | `reviews/A_aa_00973690_Color_LerpPackedARGB_Inferred.md`, `B_…` |
