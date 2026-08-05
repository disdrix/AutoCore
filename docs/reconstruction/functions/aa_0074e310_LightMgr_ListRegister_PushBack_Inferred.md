# Function record: LightMgr_ListRegister_PushBack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e310` |
| **Canonical name** | `LightMgr_ListRegister_PushBack_Inferred` |
| **Ghidra name** | `FUN_0074e310` |
| **Address** | `0x0074e310` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Palantir light / effect-list manager |
| **Wave** | W38-T |
| **Verdict** | **accept-with-gaps** |
| **Naming** | **Inferred** structural (no RTTI/string on VA) |

## Role

List-register **push-back** for refcounted light/effect cores on a host that owns a dword pointer vector at **+8/+0xC**. Complements single-slot `LightMgr_SetActiveSlot3c_Refcount_Inferred` (`0x0074e0d0`) and list unregister `FUN_0074e260`.

## Signature

```c
uint32_t __thiscall LightMgr_ListRegister_PushBack_Inferred(void* host, void* obj);
```

## Cross-links

- Ghidra record: `docs/reconstruction/functions/aa_0074e310_FUN_0074e310.md`
- Dual A/B: `reviews/A_aa_0074e310_LightMgr_ListRegister_PushBack_Inferred.md`, `reviews/B_aa_0074e310_LightMgr_ListRegister_PushBack_Inferred.md`
- Report: `docs/agents/task-dual-ab-0074e310-0040ead0-w38t-report.md`
