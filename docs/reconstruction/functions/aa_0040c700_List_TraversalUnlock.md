# Function record: List_TraversalUnlock

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c700` |
| **Canonical name** | `List_TraversalUnlock` |
| **Ghidra name** | `FUN_0040c700` |
| **Address** | `0x0040c700`–`0x0040c715` (21 B exclusive) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client::list |
| **Completion status** | **Dual A/B sealed** (WQ9D-E 2026-08-04) — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias / superseded

- Scaffold: `FUN_0040c700`
- Legacy: `Named_CalleeOf_Client_RecvSkillStatusEffect_0040c700`

## Purpose

Release traversal ownership on the shared CS list family: if `list+0x28` is set, clear it and `LeaveCriticalSection(list+4)`. Exact inverse of string-sealed `List_TraversalLock` (`0x004294f0`). No-op when flag already clear. Used after locked walks (including `Client_RecvSkillStatusEffect`).

## Signature

```c
void __fastcall List_TraversalUnlock(void *list);
// ECX = list*; void; ret
```

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `Client_RecvSkillStatusEffect` | skill status path (WQ-009 residual) |
| Caller | multiple UI/list helpers | 17 total UNCONDITIONAL_CALL |
| Callee | `LeaveCriticalSection` | Win32 IAT |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0040c700_FUN_0040c700.md`
- Annotated: `docs/reconstruction/raw/aa_0040c700_FUN_0040c700.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/List_TraversalUnlock.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0040c700.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040c700_List_TraversalUnlock.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040c700_List_TraversalUnlock.md`
- Pair lock: `docs/reconstruction/reviews/A_aa_004294f0_List_TraversalLock.md`

## Confidence

| Claim | Level |
|---|---|
| CF: flag gate + clear + LeaveCS(+4) | **High** |
| Pair of `List_TraversalLock` layout | **High** |
| Product list class RTTI name | **Open** |
