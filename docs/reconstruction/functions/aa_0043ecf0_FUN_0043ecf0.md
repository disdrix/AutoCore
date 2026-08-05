# Function record: FUN_0043ecf0 / PodU32U8_CopyIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ecf0` |
| **Canonical name** | `PodU32U8_CopyIfNonNull` (**Inferred**) |
| **Ghidra name** | `FUN_0043ecf0` |
| **Address** | `0x0043ecf0`–`0x0043ecfe` (**15 B** / `0x0F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-deque POD store helper |
| **Wave** | W32-N OWN-ONLY dual 2026-07-29 |
| **Completion status** | **Sealed** — dual A/B **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Classification** | **leaf** |

## Purpose

Null-safe copy of a **dword + byte** POD into an 8-byte container slot. Sole callee of stride-2 U32U8 push_back store path.

## Signature (sealed)

```c
// EAX = dest (nullable); ECX = const PodU32U8* src; RET (no stack); void
void PodU32U8_CopyIfNonNull(uint8_t* dest /*EAX*/, const PodU32U8* src /*ECX*/);
```

## Call graph

| Role | Symbol |
|---|---|
| Callers (1) | `FUN_0043e9e0` / `GuardedVector_PushBack_Stride2_U32U8` @ `0x0043ea3f` |
| Callees | none |
| Twin | `FUN_0043ece0` (u32×2 / Pod8 store) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0043ecf0_FUN_0043ecf0.md`
- Annotated: `docs/reconstruction/raw/aa_0043ecf0_FUN_0043ecf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PodU32U8_CopyIfNonNull.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0043ecf0.cpp`
- Named record: `docs/reconstruction/functions/aa_0043ecf0_PodU32U8_CopyIfNonNull.md`
- A: `docs/reconstruction/reviews/A_aa_0043ecf0_PodU32U8_CopyIfNonNull.md`
- B: `docs/reconstruction/reviews/B_aa_0043ecf0_PodU32U8_CopyIfNonNull.md`
- Scratch: `docs/reconstruction/tmp/a_0043ecf0.md`

## Confidence

| Claim | Level |
|---|---|
| Body 15 B + full hex | **High** |
| EAX dest / ECX src / RET | **High** |
| u32 + u8 write width | **High** |
| Null dest skips write | **High** |
| Leaf / sole caller | **High** |
| Product English | **Inferred** |
| Runtime / bit-exact | **Open** |
