# Function record: Map_LowerBoundFindByCharKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402210` |
| **Canonical name** | `Map_LowerBoundFindByCharKey` |
| **Address** | `0x00402210` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (shared char-key map find) |
| **Completion status** | **Dual-reviewed** — raw/annotated/clean + A/B reviews (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Leaf MSVC-style **ordered-tree exact find** for a **char** key. Walks from map end/head at `this+4`, nil flag **`node+0x21`**, char key at **`node+0x0C`**. Writes hit node or end into `*pOutIt`. Read-only.

## Signature (ABI-corrected)

```c
// __thiscall, ret 8 (two stack args). Decompiler phantom 3rd formal omitted.
void __thiscall Map_LowerBoundFindByCharKey(void *this, void *pOutIt, void *pKey /* char* */);
```

Ghidra still may display:

```c
void __thiscall Map_LowerBoundFindByCharKey(void *this, void *pMap, void *pOutIt, char *pKey);
```

with names swapped and an unused third stack formal — **not** the true ABI.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00402210_Map_LowerBoundFindByCharKey.md`
- Annotated: `docs/reconstruction/raw/aa_00402210_Map_LowerBoundFindByCharKey.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_LowerBoundFindByCharKey.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00402210_Map_LowerBoundFindByCharKey.md`
- Review B: `docs/reconstruction/reviews/B_aa_00402210_Map_LowerBoundFindByCharKey.md`

## Callers / callees

- **Callees:** none (leaf).
- **Callers (Ghidra):** `FUN_0059a940`, `NPC_TryCastSkillFromSet`, `FUN_00616d10`, `FUN_00620ff0`, `FUN_007eaf20` (×2 sites), `FUN_00845030`, `FUN_00955eb0`; additional xref sites `0x006165b0`, `0x00616bb0`, `0x00620e90`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **Confirmed** |
| `ret 8` / two stack args | **Confirmed** |
| Nil `+0x21`, key char `+0x0C`, L+0 / R+8 | **Confirmed** |
| Exact-match gate (not pure lower_bound) | **Confirmed** |
| Parameter semantic names vs decompiler labels | **High** (ABI-fixed) |
| Full node value layout / product STL name | **Open** |
