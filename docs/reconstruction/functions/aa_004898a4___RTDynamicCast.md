# Function record: __RTDynamicCast

| Field | Value |
|---|---|
| **Stable ID** | `aa_004898a4` |
| **Canonical name** | `__RTDynamicCast` |
| **Address** | `0x004898a4`–`0x004898a9` (**6 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation (R10 partition parent); CRT cross-cutting |
| **Completion status** | **Dual sealed** — R10-011 A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (CRT external; Terminal false) |
| **Classification** | MSVC **IAT thunk** |

## Purpose

Import trampoline for MSVC CRT RTTI helper `__RTDynamicCast` (C++ `dynamic_cast` support). In-image body is solely `jmp dword ptr [0x009C6648]` (`PTR___RTDynamicCast_009c6648`).

## Signature (call-site sealed)

```c
void* __cdecl __RTDynamicCast(
    void* inptr,
    long  VfDelta,
    void* srcType,      // TypeDescriptor*
    void* targetType,   // TypeDescriptor*
    int   isReference);
// Caller: ADD ESP,0x14 after CALL. EAX = adjusted pointer or NULL (pointer casts).
```

## Machine

```
0x004898a4: FF 25 48 66 9C 00   ; jmp dword ptr [0x009C6648]
```

## Artifacts

- Raw (+ R10-011 re-verify): `docs/reconstruction/raw/aa_004898a4___RTDynamicCast.md`
- Annotated: `docs/reconstruction/raw/aa_004898a4___RTDynamicCast.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/__RTDynamicCast.cpp`
- Twin record: `docs/reconstruction/functions/aa_004898a4_FUN_004898a4.md`
- Dual A: `docs/reconstruction/reviews/A_aa_004898a4___RTDynamicCast.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004898a4___RTDynamicCast.md`
- Report: `docs/agents/task-dual-ab-004898a4-r10-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| Callees | none in-image (IAT → EXTERNAL CRT) |
| Callers | 100+; includes parent `FUN_00938670`, `CVOGCharacter_LevelUp`, inventory/UI/skill/mission paths |
| Sample ABI | 5×PUSH + CALL + `ADD ESP,0x14` |

## Confidence

| Claim | Level |
|---|---|
| IAT thunk bytes / range | **High** |
| CRT export name | **High** |
| cdecl 5-arg ABI | **High** |
| Full CRT cast implementation | External / not dualled |
| Per-site TypeDescriptor product names | Probable at parent; census open |

## Dual verdict

| Path | Verdict |
|---|---|
| A fidelity | **accept-with-gaps** |
| B adversarial | **accept-with-gaps** |
