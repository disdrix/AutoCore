# Function record: EmptyDtorStub

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074b580` |
| **Canonical name** | `EmptyDtorStub` |
| **Ghidra name** | `FUN_0074b580` |
| **Address** | `0x0074b580`–`0x0074b581` exclusive (**1** B / `0x1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared empty leaf / EH unwind + trivial member dtor |
| **Completion status** | **Sealed** — dual A/B W31-B 2026-07-29; **accept** |
| **Bit-for-bit / runtime / diff** | Open (vacuous) |
| **Dual verdict** | **accept** |

## Naming evidence

| Source | Value |
|---|---|
| Body | single-byte `c3` — no work |
| Xrefs | 20 CALL sites: ListTrackedObj ×3 member offsets; many `Unwind@009a…`; FUN_00492*/496* |
| Product mangled on this VA | **No** |
| Scaffold rejected | `Named_CalleeOf_Mission_Uses_CVOGReaction_FailMissionNotify_0074b580` |

**Decision:** promote **`EmptyDtorStub`** (descriptive multi-role empty leaf). Distinct from mass `EmptyRet` @ `0x0056f570`.

## Signature

```c
// bare ret; callers may pass ECX this; body ignores all
void EmptyDtorStub(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0074b580_FUN_0074b580.md`
- Annotated: `docs/reconstruction/raw/aa_0074b580_FUN_0074b580.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/EmptyDtorStub.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0074b580.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0074b580_EmptyDtorStub.md`
- Review B: `docs/reconstruction/reviews/B_aa_0074b580_EmptyDtorStub.md`
- Scaffold record: `docs/reconstruction/functions/aa_0074b580_FUN_0074b580.md`

## Confidence

| Claim | Level |
|---|---|
| Body 1 B `c3` | **Confirmed** (`read_memory`) |
| Empty — no side effects | **Confirmed** (decomp ≡ bytes) |
| Multi-role shared stub | **Confirmed** (xrefs) |
| Product English | **Open** (descriptive name only) |
| Runtime | **Open** (vacuous) |
