# Function record: ObjectMotion_SlotReleaseToFreelist_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005be2b0` |
| **Canonical name** | `ObjectMotion_SlotReleaseToFreelist_Inferred` |
| **Ghidra name** | `FUN_005be2b0` |
| **Address** | `0x005be2b0`–`0x005be2e9` exclusive (**57** B / `0x39`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object motion / reaction slot freelist |
| **Completion status** | **Sealed** — dual A/B W28-I 2026-07-29; **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept** |

## Naming evidence

| Source | Value |
|---|---|
| Callers | `ObjectMotion_SlotListTick_Inferred` remove path; `FUN_005bbc50` teardown walk of `+0xA24` |
| ECX at call | always `DAT_00b036c0` freelist head |
| Role | freelist-push slot (+ optional child @+0x8) after SlotTick returns 0 |
| Product mangled on this VA | **No** |

**Decision:** promote **`ObjectMotion_SlotReleaseToFreelist_Inferred`** (role sealed; product English residual → `_Inferred`).

## Signature

```c
// __thiscall; ECX = freelist head*; stack SlotNode*; RET 4; void
void ObjectMotion_SlotReleaseToFreelist_Inferred(SlotNode **freelist_head, SlotNode *node);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005be2b0_FUN_005be2b0.md`
- Annotated: `docs/reconstruction/raw/aa_005be2b0_FUN_005be2b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ObjectMotion_SlotReleaseToFreelist_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005be2b0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005be2b0_ObjectMotion_SlotReleaseToFreelist_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005be2b0_ObjectMotion_SlotReleaseToFreelist_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_005be2b0_FUN_005be2b0.md`

## Confidence

| Claim | Level |
|---|---|
| Body 57 B + ret 4 | **Confirmed** (`read_memory`) |
| Freelist push + child@+0x8 | **Confirmed** (decomp ≡ bytes) |
| Global freelist `DAT_00b036c0` | **Confirmed** (caller site bytes) |
| Product English | **Inferred** |
| Runtime | **Open** |
