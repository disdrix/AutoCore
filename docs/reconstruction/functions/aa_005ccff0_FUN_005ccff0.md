# Function record: FUN_005ccff0 / CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ccff0` |
| **Canonical name** | `CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred` |
| **Ghidra name** | `FUN_005ccff0` |
| **Address** | `0x005ccff0`–`0x005cd220` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CVOGHB AI engage / target select |
| **Wave** | W29-L OWN dual |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Signature

```c
void __thiscall CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred(void *hbai);
// plain ret; 0 stack formals
```

## Sealed contract

1. Copy TFID from `owner(this+0x64)+0x228`; resolve via manager ECX + `Object_ResolveFromTFID`.
2. Resolve miss → mode 0 via `Object_SetMode278_SelectFromTFID228_Inferred`.
3. Prefer `resolved+0xA0` when owner `vtbl+0x298` and candidate `vtbl+0x1c8` pass → `Object_SetSelectedTarget`.
4. Else optional `FUN_004c8970` gate; else LinkedDeath list walk for partner promote.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ccff0_FUN_005ccff0.md`
- Annotated: `docs/reconstruction/raw/aa_005ccff0_FUN_005ccff0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005ccff0.cpp`
- Named record: `docs/reconstruction/functions/aa_005ccff0_CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.md`
- Dual A/B: `reviews/A_aa_005ccff0_CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.md`, `reviews/B_aa_005ccff0_CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.md`

## Callers / callees

| Role | Symbol |
|---|---|
| Caller (1) | `CVOGHBAICreatureBase_OnHeartBeat` @ `0x005d0704` |
| Callees | `Object_ResolveFromTFID` `0x004bb950`; `Object_SetMode278…` `0x004c3c80`; `Object_SetSelectedTarget` `0x005172d0`; `FUN_004c8970`; `FUN_004294f0`; `LockedList_TryAdvanceIterator` `0x004022a0`; `__RTDynamicCast`; `LeaveCriticalSection` |

## Confidence

| Claim | Level |
|---|---|
| ABI thiscall / plain ret | **High** |
| Resolve / mode0 / SetSelectedTarget CF | **High** |
| LinkedDeath walk CF | **High** |
| Product English for vtbl slots | Open |
