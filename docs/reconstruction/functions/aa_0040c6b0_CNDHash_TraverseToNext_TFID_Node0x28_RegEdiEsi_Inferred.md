# Function record: CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c6b0` |
| **Canonical name** | `CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred` |
| **Ghidra name** | `FUN_0040c6b0` |
| **Address** | `0x0040c6b0`–`0x0040c6f0` |
| **Module** | `autoassault.exe` (base `0x400000`) |
| **System** | interaction-activation / CNDHash |
| **Partition** | MEGA-112 (OWN-ONLY dual) |
| **Dual verdict** | **accept-with-gaps** (A ≡ B) |
| **Terminal** | **false** |

## Naming rationale

| Evidence | Contribution |
|---|---|
| `"HashError:TraverseToNext, not locked for traversal"` | Product method family **TraverseToNext** |
| `"VOG_DEBUG_STOP"` | Shared debug-stop tag (not method name) |
| Parent casts return → `TFID_16*` + `Object_ResolveFromTFID` | Payload typed **TFID\*** at sole consumer |
| `node+0x20` next / `node+0xc` value | **0x28 / u64-key** node family (≠ 0x1c twin) |
| EDI/ESI + plain RET (parent LEA/MOV seal) | **RegEdiEsi** ABI suffix |
| Product hash RTTI @ `e8f4` open | **`_Inferred`** |

Retired misnames: `Named_VOG_DEBUG_STOP_0040c6b0`, any `Named_CalleeOf_*` scaffold for this VA.

## Contract

```
payload = TraverseToNext(hash, &cursor):   // EDI=hash, ESI=&cursor
  if !hash.lockedForTraversal(+0x1d): log HashError:TraverseToNext…; // continue
  if cursor==0: cursor = hash.listHead (+0x14)
  else:         cursor = cursor->listNext (+0x20)   // 0x28-node family
  return cursor ? cursor->value (+0xc) : 0          // TFID* at npc-interact consumer
```

Does **not** set/clear lock, mutate membership, or free nodes.

## Family map (not dualled here)

| VA | Role |
|---|---|
| `0x00411e10` | TraversalLock set (ESI=hash; +0x1d=1) — companion |
| `0x00411e40` | Reg-ABI TraverseToNext next+0x14 / value+8 |
| `0x00411900` | thiscall TraverseToNext next+0x14 / value+8 / RET 4 (**dualed**) |
| `0x0091b8d0` | `Client_UpdateNpcInteractIcons` — sole caller |

## Artifacts

See `aa_0040c6b0_FUN_0040c6b0.md` for full path table.
