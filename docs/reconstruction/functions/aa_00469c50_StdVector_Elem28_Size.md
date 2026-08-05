# Function record: StdVector_Elem28_Size

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469c50` |
| **Canonical name** | `StdVector_Elem28_Size` (**Inferred**) |
| **Ghidra name** | `FUN_00469c50` |
| **Address** | `0x00469c50`–`0x00469c70` (**33 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / std::vector size helper |
| **Completion status** | Dual A/B sealed W33-J 2026-07-29 — **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Null-safe vector element count for **stride-0x1c** hosts: `begin==0 ? 0 : (end-begin)/0x1c`. Layout begin@+4, end@+8. Leaf.

## Signature

```c
int __fastcall StdVector_Elem28_Size(void* vec /*ECX*/);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- Full body hex via `read_memory`; magic `0x92492493` ÷28
- 9 callers / 9 xrefs; leaf
- Dual A/B **accept**

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00469c50_FUN_00469c50.md` |
| Annotated | `docs/reconstruction/raw/aa_00469c50_FUN_00469c50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Elem28_Size.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469c50.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00469c50_FUN_00469c50.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00469c50_StdVector_Elem28_Size.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00469c50_StdVector_Elem28_Size.md` |
| Scratch | `docs/reconstruction/tmp/a_00469c50.md` |
