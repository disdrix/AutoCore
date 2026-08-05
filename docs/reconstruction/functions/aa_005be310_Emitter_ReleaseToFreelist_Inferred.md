# Function record: Emitter_ReleaseToFreelist_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005be310` |
| **Canonical name** | `Emitter_ReleaseToFreelist_Inferred` |
| **Ghidra name** | `FUN_005be310` |
| **Address** | `0x005be310`–`0x005be32e` exclusive (**30** B / `0x1e`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client NDSpecialFX / emitter freelist |
| **Completion status** | **Sealed** — dual A/B W30-R 2026-07-29; **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept** |

## Naming evidence

| Source | Value |
|---|---|
| Callers | `NDSpecialFX_HostTick` kill after `Emitter_UpdateTick` returns 0; `ClearChildLists` walk of host `+0x1E0`; `FUN_004a34f0` ×7 |
| ECX at call | always `DAT_00b454fc` freelist head |
| Callee | `FUN_005bbc50` heavy emitter body teardown, then freelist-push |
| Product mangled on this VA | **No** |

**Decision:** promote **`Emitter_ReleaseToFreelist_Inferred`** (role sealed; product English residual → `_Inferred`). Reject scaffold alias `Named_CalleeOf_Named_missileExplosion_*` as product claim.

## Signature

```c
// __thiscall; ECX = freelist head*; stack Emitter*; RET 4; void
void Emitter_ReleaseToFreelist_Inferred(Emitter **freelist_head, Emitter *node);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005be310_FUN_005be310.md`
- Annotated: `docs/reconstruction/raw/aa_005be310_FUN_005be310.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Emitter_ReleaseToFreelist_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005be310.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005be310_Emitter_ReleaseToFreelist_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005be310_Emitter_ReleaseToFreelist_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_005be310_FUN_005be310.md`

## Confidence

| Claim | Level |
|---|---|
| Body 30 B + ret 4 | **Confirmed** (`read_memory`) |
| Teardown then freelist push | **Confirmed** (decomp ≡ bytes; ECX rebound for child) |
| Global freelist `DAT_00b454fc` | **Confirmed** (caller site bytes `B9 FC 54 B4 00`) |
| Product English | **Inferred** |
| Runtime | **Open** |
