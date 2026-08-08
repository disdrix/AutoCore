# Function record: RdtscTimer_StampAndArm_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c4d0` |
| **Canonical name** | `RdtscTimer_StampAndArm_Inferred` |
| **Ghidra name** | `FUN_0076c4d0` |
| **Address** | `0x0076c4d0`–`0x0076c4f1` exclusive (**33 B** / `0x21`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | timer subobject stamp (HostBase `+0x10`; CWndVehicle nested) |
| **Naming evidence** | Shape: RDTSC write + arm byte; paired with `FUN_0076c500`; HostBase/CWndVehicle callers. No RTTI/string product demangle → **`_Inferred`**. |
| **Rejected** | `Named_CalleeOf_Named_gfxPerfGraph_0076c4d0` (scaffold) |
| **Completion status** | **Dual sealed** WQ9L-D 2026-08-05 — **accept-with-gaps** |
| **Terminal** | **false** |

## Signature

```c
void __fastcall RdtscTimer_StampAndArm_Inferred(void *timer /*ECX*/);
```

## Semantics

1. `RDTSC` → 64-bit stamp.
2. Store low @ `timer+0x08`, high @ `timer+0x0C`.
3. `*(uint8_t*)(timer+0x18) = 1`.

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0076c4d0_FUN_0076c4d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0076c4d0_FUN_0076c4d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RdtscTimer_StampAndArm_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0076c4d0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0076c4d0_FUN_0076c4d0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0076c4d0_RdtscTimer_StampAndArm_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0076c4d0_RdtscTimer_StampAndArm_Inferred.md` |

## Gaps

- Product / MSVC demangle for timer type.
- Exact product English for flag `+0x18`.
- Runtime / bit-exact / differential.
