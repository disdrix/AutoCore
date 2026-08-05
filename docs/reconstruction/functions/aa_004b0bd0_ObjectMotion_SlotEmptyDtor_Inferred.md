# Function record: ObjectMotion_SlotEmptyDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b0bd0` |
| **Canonical name** | `ObjectMotion_SlotEmptyDtor_Inferred` |
| **Ghidra name** | `FUN_004b0bd0` |
| **Address** | `0x004b0bd0`–`0x004b0bd1` exclusive (**1** B / `0x1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object motion / reaction slot freelist |
| **Completion status** | **Sealed** — dual A/B W30-R 2026-07-29; **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept** |

## Naming evidence

| Source | Value |
|---|---|
| Sole caller | `ObjectMotion_SlotReleaseToFreelist_Inferred` (`FUN_005be2b0`) ×2 (child + node) |
| Body | single-byte `ret` — no work |
| Product mangled on this VA | **No** |

**Decision:** promote **`ObjectMotion_SlotEmptyDtor_Inferred`** (role sealed as empty dtor stub of slot freelist release; product English residual → `_Inferred`). Not the mass-shared `EmptyRet` @ `0x0056f570`.

## Signature

```c
// thiscall shape at call sites; body ignores this; bare ret; void
void ObjectMotion_SlotEmptyDtor_Inferred(void /*this*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b0bd0_FUN_004b0bd0.md`
- Annotated: `docs/reconstruction/raw/aa_004b0bd0_FUN_004b0bd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ObjectMotion_SlotEmptyDtor_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004b0bd0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004b0bd0_ObjectMotion_SlotEmptyDtor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004b0bd0_ObjectMotion_SlotEmptyDtor_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_004b0bd0_FUN_004b0bd0.md`

## Confidence

| Claim | Level |
|---|---|
| Body 1 B `c3` | **Confirmed** (`read_memory`) |
| Empty — no side effects | **Confirmed** (decomp ≡ bytes) |
| Sole caller SlotRelease | **Confirmed** (xrefs) |
| Product English | **Inferred** |
| Runtime | **Open** |
