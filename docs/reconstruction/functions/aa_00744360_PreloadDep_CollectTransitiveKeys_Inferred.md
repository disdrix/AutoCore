# Function record: PreloadDep_CollectTransitiveKeys_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00744360` |
| **Canonical name** | `PreloadDep_CollectTransitiveKeys_Inferred` |
| **Ghidra name** | `FUN_00744360` |
| **Address** | `0x00744360`–`0x0074445c` (**253 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | preload / asset dependency graph |
| **Completion status** | **Dual reviewed (W32-L)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

See twin record `aa_00744360_FUN_00744360.md` for full callers/callees and confidence tables.

## Signature (sealed)

```c
void __fastcall PreloadDep_CollectTransitiveKeys_Inferred(
    void* host /*ECX*/,
    const int* key /*stack*/,
    GuardedVectorHeader* ring /*stack*/);  // RET 8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00744360_FUN_00744360.md`
- Annotated: `docs/reconstruction/raw/aa_00744360_FUN_00744360.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PreloadDep_CollectTransitiveKeys_Inferred.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_00744360_PreloadDep_CollectTransitiveKeys_Inferred.md`, `B_aa_00744360_PreloadDep_CollectTransitiveKeys_Inferred.md`
