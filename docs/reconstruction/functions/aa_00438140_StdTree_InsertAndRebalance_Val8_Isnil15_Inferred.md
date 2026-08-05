# Function record: StdTree_InsertAndRebalance_Val8_Isnil15_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438140` |
| **Canonical name** | `StdTree_InsertAndRebalance_Val8_Isnil15_Inferred` |
| **Ghidra** | `FUN_00438140` |
| **Address** | `0x00438140` |
| **Body** | `0x00438140`–`0x004382be` inclusive (**383 B**) |
| **Wave** | W38-L OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** |

## Node Val8 (0x18)

| Off | Field |
|---|---|
| +0 | left |
| +4 | parent |
| +8 | right |
| +0x0C | key (u32) |
| +0x10 | mapped (u32) |
| +0x14 | color (u8; 0=red) |
| +0x15 | isnil (u8; 0 for live nodes) |

## Map shell (EDI)

| Off | Field |
|---|---|
| +4 | head sentinel |
| +8 | size |

## Contrast (do not merge)

| Peer | Diff |
|---|---|
| `StdTree_InsertAndRebalance_Val12` `0x005e13b0` | thiscall; max `0x15555553`; color@+0x18; isnil@+0x19 |
| W24-O rotates `004e22d0`/`006753b0` | same isnil15 family; **different VA clones** than `004219b0`/`0046f030` used here |

## Parent consumers

Primary dualed parent: `StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred` (`0x00458510`, W37-K). Closes that residual on insert-helper dual.
