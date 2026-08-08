# Function record: StdVector_DestroyRuns_0x80_Thunk_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00427040` |
| **Canonical name** | `StdVector_DestroyRuns_0x80_Thunk_Inferred` |
| **Prior scaffold** | `thunk_FUN_004271c0` |
| **Address** | `0x00427040`–`0x00427044` inclusive (**5 B** / `0x5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / UI text-layout SEH alias |
| **Agent** | R10-003 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept**) |
| **Terminal** | **false** (runtime open) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Parent** | `0x004271c0` `StdVector_DestroyRuns_0x80_Inferred` (MEGA-128 **accept**) |

## Purpose

SEH **JMP thunk** for the dualed 0x80-stride vector tidy used by `UiTextLayout` run storage at `layout+0x80`.

```text
EBX = vector shell*  (begin@+4 end@+8 cap@+0xC)
JMP → destroy each elem (FUN_00426f70 ~wstring@+0x0C, stride 0x80)
      operator_delete(begin); zero triple
```

Retail keeps this 5 B alias for EH unwind tables; product CALL sites target the parent VA directly.

## Signature

```c
// EBX = Vec80Shell*; void; parent bare RET
void StdVector_DestroyRuns_0x80_Thunk_Inferred(void /* EBX */);
```

| Item | Value |
|---|---|
| Body bytes | `E9 7B 01 00 00` |
| Target | `0x004271c0` |
| Twin FUN | `FUN_00427040` / Ghidra `thunk_FUN_004271c0` |

## Port note (AutoCore)

```csharp
// Prefer single implementation:
void DestroyRuns0x80(Vec80Shell* v /* retail: EBX */);
// This VA is a pure alias — no second tidy body required.
```

Pair with dualed `UiTextLayout_CompleteDtor_Inferred` (vector at `+0x80`). Element dtor trampoline `FUN_00426f70` residual (R10-026).

## Artifacts

| Kind | Path |
|---|---|
| Raw + re-verify | `docs/reconstruction/raw/aa_00427040_thunk_FUN_004271c0.md` |
| Annotated | `docs/reconstruction/raw/aa_00427040_thunk_FUN_004271c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DestroyRuns_0x80_Thunk_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00427040.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00427040_StdVector_DestroyRuns_0x80_Thunk_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00427040_StdVector_DestroyRuns_0x80_Thunk_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00427040_FUN_00427040.md` |
| Report | `docs/agents/task-dual-ab-00427040-r10-report.md` |

## Confidence

| Claim | Level |
|---|---|
| JMP-only body | **Confirmed** |
| EBX SEH alias @ +0x80 | **Confirmed** |
| Parent tidy semantics | **Confirmed** (MEGA-128) |
| Product element English | **Tentative** (`_Inferred`) |
