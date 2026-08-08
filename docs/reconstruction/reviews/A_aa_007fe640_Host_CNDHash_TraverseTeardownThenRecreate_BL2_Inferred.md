# Review A (reconstruction fidelity): `aa_007fe640` Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fe640` |
| **VA** | `0x007fe640`–`0x007fe710` exclusive (**209 B**) |
| **Canonical name** | `Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred` |
| **Ghidra name** | `FUN_007fe640` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9I-D) |
| **Counterpart** | `reviews/B_aa_007fe640_Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.md` |
| **System** | host / CNDHash (stamp **00a2c2e4**; field **owner+0x3084**) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` |
| **Partition** | `WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-D** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Host-side **CNDHash traverse → per-object teardown → unlock → recreate**:

```text
hash = *(owner + 0x3084)
if hash == 0: return
TraversalLock soft-assert; lock@+0x1d = 1
walk ordered list (head +0x14, next +0x20, payload +0xc):
  if obj->vtbl[+0x3d8](): obj->vtbl[+0x440]()
  if obj+0x2b0: (*(obj+0x2b0))->vtbl[+0xb0](obj)
unlock @+0x1d
CNDHash_Recreate_00a2c2e4(EAX=hash, BL=2)
```

Sole static caller of dualed recreate with **immediate BL=2** (matches host ctor log2 seed).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007fe640_FUN_007fe640.md` |
| Annotated | `docs/reconstruction/raw/aa_007fe640_FUN_007fe640.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007fe640.cpp` |
| Function record | `docs/reconstruction/functions/aa_007fe640_Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.md` |
| Nested dual | `CNDHash_Recreate_00a2c2e4` (WQ9H-E) |
| Family ADV | `reviews/ADV_wq9h_spotcheck_cndhash.md` (caller residual closed here) |
| Live | decompile ≡ raw CF; recreate handoff sealed by bytes |

---

## 3. Signature (sealed)

```c
// stdcall; RET 4
void Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred(void* owner /*Stack[0x4]*/);
// Recreate: EAX = *(owner+0x3084); BL = 2; bare ret into dualed unit
```

| Slot | Role | Conf |
|---|---|---|
| Stack[0x4] | owner* (`MOV EBP,[ESP+8]`) | **High** |
| cleanup | `C2 04 00` | **High** |
| return | void | **High** |
| Recreate EAX | hash at +0x3084 | **High** |
| Recreate BL | imm **2** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Null hash early-out | **Yes** | **High** |
| Lock soft-log then force 1 | **Yes** | **High** |
| Ordered walk head/next/payload | **Yes** | **High** |
| vtbl 0x3d8 / 0x440 / secondary 0x2b0→0xb0 | **Yes** | **High** |
| Unlock then recreate | **Yes** | **High** |
| BL=2 seed | **Yes** (bytes; decompiler omits) | **High** |
| 2 host callers | **Yes** | **High** |

### Recreate call site (bytes)

```text
MOV byte [hash+0x1d], 0
MOV EAX, [EBP+0x3084]
MOV BL, 2
CALL 0x004195d0
```

---

## 5. Machine bytes (`read_memory`)

Body 209 B @ `0x007fe640`; entry `55 8B 6C 24 08 56 8B B5 84 30 00 00` (EBP=owner, ESI=hash@+0x3084); epilogue `5B 5F 5E 5D C2 04 00`; pad `CC`.

Strings: TraversalLock / TraverseToNext / VOG_DEBUG_STOP via `FUN_007a4480`.

---

## 6. Gaps

- Product / PDB English for host class owning +0x3084.
- Exact English for vtbl+0x3d8 / +0x440 / secondary +0xb0.
- Dual of callers `FUN_00934880` / `FUN_009349b0`.
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/recreate handoff sealed; product English residual.
