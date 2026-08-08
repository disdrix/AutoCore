# Review A (reconstruction fidelity): `aa_004085e0` CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004085e0` |
| **VA** | `0x004085e0` |
| **Body** | `0x004085e0`–`0x00408635` exclusive (**85 B** / `0x55`) |
| **Canonical name** | `CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred` |
| **Ghidra name** | `FUN_004085e0` |
| **Prior scaffold** | `FUN_004085e0` / VOG_DEBUG_STOP callee alias |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual **WQ9H-A**) |
| **Counterpart** | `reviews/B_aa_004085e0_CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.md` |
| **System** | container / CNDHash (host `00a2c2b0`; node stamp `00a2c2bc`) |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Release every bucket chain of a host-family **CNDHash** onto freelist `@+0x20`, deleting owned payloads. Nested freelist step of destroy-bucket-table `FUN_00406fc0`. **Not** table free, **not** live-count zero, **not** tree free-subtree, **not** VA-neighbor tree iterator `00408590`.

```text
// custom EBX = hash*; bare ret
for bucket = 0 .. mask:
  node = *(table[bucket] + 4)
  while node:
    next = node[4]
    *node = &PTR_FUN_00a2c2bc
    if node[3]: operator_delete(node[3])
    node[3] = 0
    freelist push @ hash+0x20  // *node = head; head = node
    node = next
  *(table[bucket] + 4) = 0
```

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **EBX** | `CNDHash*` (decompiler `unaff_EBX`) |
| stack | none |
| return | void; bare **`ret`** (`C3`) |

Parent `00406fc0` @ `00406fc1`: `mov ebx,eax` before `call 004085e0`.

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x004085e0` (2026-08-04) ≡ raw scaffold CF |
| Bytes | `read_memory` — entry `55 56 33 C9 57 33 ED 8B 43 10…`; exit `5F 5E 5D C3`; vtbl imm `BC C2 A2 00` |
| Bounds | `get_function_by_address` body through ret; pad `CC` to neighbor |
| Callers | `get_function_callers` → `FUN_00406fc0` only (1 xref @ `00406fca`) |
| Callees | `operator_delete` only |
| Parent dual | WQ9G-J sealed `aa_00406fc0` DestroyBucketTable |
| Clean | `reconstructed-exact/CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| EBX host; no stack formals | **Yes** |
| Bucket loop `0..mask` inclusive | **Yes** |
| Chain walk via `node[4]` / +0x10 | **Yes** |
| Stamp `PTR_FUN_00a2c2bc` then payload delete | **Yes** |
| Freelist push `@+0x20` overwriting slot0 | **Yes** |
| Clear chain head after walk | **Yes** |
| Bare ret; no live-count / table free | **Yes** |
| No domain / packet logic | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body ≡ raw ≡ live | **Confirmed** | CF spine identical |
| EBX custom ABI / bare ret | **Confirmed** | parent + entry/exit bytes |
| Freelist role + node layout | **Confirmed** (CF) | slot0/payload/next |
| Sole caller destroy table | **Confirmed** | 1 xref |
| Product English | **Open** | `_Inferred` stamp-family |
| Runtime freelist integrity | **Open** | no live capture |

---

## 6. Gaps / open

1. Product / MSVC demangle for host CNDHash English type.
2. Whether payload is a typed object with virtual dtor (bytes use scalar delete).
3. Bit-exact / runtime / image diff.
4. Decompiler warning on `operator_delete` "does not return" is a decomp artifact — freelist push after free is load-bearing.

**Verdict:** **accept-with-gaps**
