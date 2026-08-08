# Function record: StdMap_Find_Tfid_Isnil29_EaxMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402ae0` |
| **Canonical name** | `StdMap_Find_Tfid_Isnil29_EaxMap_Inferred` |
| **Ghidra symbol** | `FUN_00402ae0` |
| **Address** | `0x00402ae0`–`0x00402b2f` inclusive (**80 B** / `0x50`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` |
| **Wave** | MEGA-083 OWN-ONLY dual `2026-08-05` |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

Exact-match **find** shell: residual lower_bound `FUN_00403e50` + equality gate on TFID-shaped pair key (lo u32 @ node+0x10, hi i32 @ node+0x14); isnil family **+0x29** inside lower_bound. Writes node* or head(end) to `*outIt`.

## ABI

| Formal | Source | Cleanup |
|---|---|---|
| map | **EAX** (`head` @ `+4`) | — |
| pKey | **EDI** | — |
| outIt | stack | **`RET 4`** |
| return | EAX = outIt after `*outIt` store | both exits |

**Distinct** from twin `StdMap_Find_Tfid_Isnil29_Inferred` (`0x004cba00`: ECX thiscall, stack out+key, **RET 8**, lower_bound `004cb4b0`).

## Signature

```c
Node** StdMap_Find_Tfid_Isnil29_EaxMap_Inferred(
    /*EAX*/ MapHost_Head4* map,
    /*EDI*/ const KeyU32I32* pKey,
    /*stack*/ Node_Isnil29** outIt);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00402ae0_FUN_00402ae0.md` |
| Annotated | `docs/reconstruction/raw/aa_00402ae0_FUN_00402ae0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00402ae0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00402ae0_FUN_00402ae0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00402ae0_StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00402ae0_StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00402ae0-mega-083-report.md` |

## Call graph (OWN boundary)

```text
FUN_00402ae0  StdMap_Find_Tfid_Isnil29_EaxMap_Inferred  [OWN MEGA-083]
  └─ FUN_00403e50  lower_bound isnil29 pair-key  [residual — not dualled]

Callers (evidence only):
  Client_SendRespawnInSector @ 00935340
  FUN_00944d50 @ 00944e4b
  Client_Input_OnKeyDown_MatchAction @ 0091120a
  FUN_0091da70 @ 0091df4e
  site 00957e3a
```

## Confidence

| Claim | Level |
|---|---|
| CF + body size + RET 4 | **High** |
| EAX map / EDI key | **High** |
| Find equality semantics | **High** |
| TFID English | **Inferred** |
| Product map / value_type | **Open** |
| Runtime | **Open** |

## Retired names

- `Named_CalleeOf_Client_SendRespawnInSector_00402ae0`
