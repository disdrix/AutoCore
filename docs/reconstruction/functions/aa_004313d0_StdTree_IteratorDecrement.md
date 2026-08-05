# Function record: StdTree_IteratorDecrement

| Field | Value |
|---|---|
| **Stable ID** | `aa_004313d0` |
| **Canonical name** | `StdTree_IteratorDecrement` |
| **Ghidra name** | `FUN_004313d0` |
| **Address** | `0x004313d0`–`0x00431420` (**80 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `client::stdtree` (MSVC `_Tree` predecessor) |
| **Completion status** | **Dual sealed (W22-O)** — raw/annotated/clean + A/B reviews |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Name confidence** | **INFERRED** (algorithm + insert callers; no plate string) |

## Purpose

In-place **predecessor** step for a red-black / MSVC tree iterator (`node**`):

1. If current is **nil** (header/`end`): `*it = node->right` (rightmost).
2. Else if **left** non-nil: leftmost? no — go **left**, then walk **right** to rightmost of left subtree.
3. Else climb **parent** while still the **left** child; assign the non-nil parent.

## Signature (sealed)

```c
// EDX = node**; ECX unused; plain ret; void
void StdTree_IteratorDecrement(Node **it /*EDX*/);
```

| Offset | Field |
|---|---|
| `+0x00` | left |
| `+0x04` | parent |
| `+0x08` | right |
| `+0x2d` | `_Isnil` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004313d0_FUN_004313d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004313d0_FUN_004313d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_IteratorDecrement.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004313d0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_004313d0_FUN_004313d0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004313d0_StdTree_IteratorDecrement.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004313d0_StdTree_IteratorDecrement.md` |

## Callers / callees

**Callees:** none.

**Callers:** `StdMap_StringKey_InsertOrFind` (`0x004309c0` @ `0x00430a42`), `FUN_0044d9f0`, `FUN_00401c50`, `FUN_004303c0`.

## Confidence

| Claim | Level |
|---|---|
| Predecessor CF / nil@`+0x2d` / LPR layout | **Confirmed** |
| EDX = `node**` in-place | **Confirmed** |
| Product English / template name | **Inferred** |
| Runtime | Open |

## Related

- `aa_004309c0` StdMap_StringKey_InsertOrFind (uses this after goLeft)
- `aa_004cb270` StdTree_IteratorIncrement_Inferred (successor; nil @ `+0x29`)
