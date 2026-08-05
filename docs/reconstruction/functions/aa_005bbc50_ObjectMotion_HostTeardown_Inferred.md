# Function record: ObjectMotion_HostTeardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bbc50` |
| **Canonical name** | `ObjectMotion_HostTeardown_Inferred` |
| **Ghidra name** | `FUN_005bbc50` |
| **Address** | `0x005bbc50`–`0x005bbd96` exclusive Ghidra (**326** B / `0x146`); true epilog `c3` ≈ `0x005bbdc0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object motion / reaction host teardown |
| **Completion status** | **Sealed** — dual A/B W30-S 2026-07-29; **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept-with-gaps** |

## Naming evidence

| Source | Value |
|---|---|
| Caller | `FUN_005be310` — teardown then optional freelist push of host |
| Callee | `ObjectMotion_SlotReleaseToFreelist_Inferred` on each `+0xa24` payload |
| Freelist ECX | always `DAT_00b036c0` at slot-release site |
| Scaffold alias | `Named_CalleeOf_Named_CalleeOf_Named_missileExplosion_005bbc50` — **reject** as product |
| Product mangled on this VA | **No** |

**Decision:** promote **`ObjectMotion_HostTeardown_Inferred`** (role sealed; product English residual → `_Inferred`).

## Signature

```c
// __thiscall; ECX = host*; no stack args; ret (c3); void
void ObjectMotion_HostTeardown_Inferred(void *host);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005bbc50_FUN_005bbc50.md`
- Annotated: `docs/reconstruction/raw/aa_005bbc50_FUN_005bbc50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ObjectMotion_HostTeardown_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005bbc50.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005bbc50_ObjectMotion_HostTeardown_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005bbc50_ObjectMotion_HostTeardown_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_005bbc50_FUN_005bbc50.md`

## Callers / callees

| Dir | VA | Name |
|---|---|---|
| Caller | `0x005be310` | `FUN_005be310` (W30-R) |
| Callee | `0x005b8340` | buffer/list clear helper |
| Callee | `0x005be2b0` | `ObjectMotion_SlotReleaseToFreelist_Inferred` |
| Callee | `0x00489822` | `operator_delete` |

## Confidence

| Claim | Level |
|---|---|
| Host teardown + slot freelist walk | **Confirmed** (decomp + call-site bytes) |
| Freelist head `DAT_00b036c0` | **Confirmed** (`B9 C0 36 B0 00`) |
| Primary/secondary buffer free pattern | **High** |
| True `c3` after SEH (Ghidra truncated) | **Confirmed** (`read_memory`) |
| Product English | **Inferred** |
| Runtime | **Open** |
