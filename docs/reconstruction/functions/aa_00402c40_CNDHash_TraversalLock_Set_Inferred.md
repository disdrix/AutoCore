# Function record: CNDHash_TraversalLock_Set_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402c40` |
| **Canonical name** | `CNDHash_TraversalLock_Set_Inferred` |
| **Ghidra name** | `FUN_00402c40` |
| **Address** | `0x00402c40`–`0x00402c69` inclusive (**42 B** / `0x2A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition** | MEGA-110 OWN-ONLY (parent dual context `0x0091b8d0` Client_UpdateNpcInteractIcons) |
| **Completion status** | **Dual sealed** (A/B **accept**) |
| **Bit-for-bit / runtime / diff** | Open — terminal **false** |

## Purpose

Soft-set the CNDHash **TraversalLock** flag:

```text
if (hash->traversalFlag @ +0x1d)
  DebugLog HashError already-locked + VOG_DEBUG_STOP
hash->traversalFlag = 1   // always
```

Enables ordered hash walks (`CNDHash_TraverseToNext`). Distinct from CS-list `List_TraversalLock`.

## Signature

```c
void __fastcall CNDHash_TraversalLock_Set_Inferred(int hash /* ECX */);
```

| ABI | Evidence |
|---|---|
| ECX = CNDHash* | `MOV ESI,ECX`; call sites `MOV ECX, hash` |
| Bare RET | `C3` @ `0x00402c69` |
| Void | no EAX write |

## Strings

| VA | String |
|---|---|
| `0x00a27cd0` | `HashError:TraversalLock, already locked for traversal` |
| `0x00a15844` | `VOG_DEBUG_STOP` |

## Callees

| VA | Role |
|---|---|
| `0x007a4480` `FUN_007a4480` | cdecl debug log (level, fmt) ×2 |

## Callers (21)

`Client_UpdateNpcInteractIcons`, `FUN_004bae00` (×2 sites), `FUN_004d2e50`, `FUN_004d4040`, `FUN_004d5c10` (×3), `FUN_004fdcb0`, `FUN_00507a40`, `FUN_00514390`, `FUN_00541e70`, `FUN_005ffa10`, `FUN_00627170` (×3), `FUN_0084e840`, `FUN_00896b20`, `FUN_0089bc30`, `FUN_008a5060`, `FUN_00921890`, `FUN_0092b020`, `FUN_009344b0` (×2), `FUN_00954670` (×3), `FUN_009572e0`, `QuickBar_UpdateSkillSlotCooldownGauge`.

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ MEGA-110 re-verify) | `docs/reconstruction/raw/aa_00402c40_FUN_00402c40.md` |
| Annotated | `docs/reconstruction/raw/aa_00402c40_FUN_00402c40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_TraversalLock_Set_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402c40.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00402c40_CNDHash_TraversalLock_Set_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00402c40_CNDHash_TraversalLock_Set_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00402c40_FUN_00402c40.md` |
| Report | `docs/agents/task-dual-ab-00402c40-mega-110-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / flag `+0x1d` / soft force-set | **High** |
| Hash TraversalLock role | **High** |
| CNDHash class tag | **High (role)** via TraverseToNext pairing |
| Product method English | **Open** → `_Inferred` |
| Runtime Confirmed | **Open** |

## Retired scaffolds

- `Named_VOG_DEBUG_STOP_00402c40` / `Named_CalleeOf_*` — do not use as identity.
