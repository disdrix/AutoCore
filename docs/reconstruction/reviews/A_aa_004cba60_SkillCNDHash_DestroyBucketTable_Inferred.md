# Review A (reconstruction fidelity): `aa_004cba60` SkillCNDHash_DestroyBucketTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba60` |
| **VA** | `0x004cba60` |
| **Canonical name** | `SkillCNDHash_DestroyBucketTable_Inferred` |
| **Prior alias** | `FUN_004cba60` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9E-A) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md` |
| **System** | skills-abilities / skill-family CNDHash |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory`, callers/xrefs, assembly_context |
| **Partition** | `WAVE_2026-08-04_wq009_depth2_partition_map.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tear down the **bucket pointer table** of a skill-family CNDHash (`ECX=hash`):

```text
// __thiscall; bare ret
*(hash+0x0c) = 0                 // live entry count
FUN_004cb680(hash)               // release chain nodes → freelist @+0x20
if table = *(hash+0x10):
  free(*table)                   // contiguous 0xc sentinel slab
  operator_delete[](table)       // pointer array
  *(hash+0x10) = 0
```

**Not** freelist release alone. **Not** full object dtor (`FUN_0051de80` calls this then more). **Not** inventory `CNDHash_DestroyBucketTable_Inferred` `0x00413e20` (EAX ABI).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x004cba60)` ≡ 2026-07-23 raw |
| Entry / body bytes | `read_memory` — `56 8B F1` … `5E C3` + `CC` |
| Body range | `0x004cba60`–`0x004cba93` (**52 B**); Ghidra end `004cba93` |
| Callers | recreate `004cbdc0` @ `004cbde6`; dtor `0051de80` @ `0051dece` |
| Callees | `004cb680` freelist walk; `free`; `operator_delete[]` |
| Parent dual | `SkillCNDHash_Recreate_Inferred` (`aa_004cbdc0`) — destroy-then-alloc |
| Inventory twin | `CNDHash_DestroyBucketTable_Inferred` (`aa_00413e20`) — pattern contrast |
| Clean | `reconstructed-exact/SkillCNDHash_DestroyBucketTable_Inferred.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | hash* | entry `mov esi,ecx`; callers `mov ecx,esi` before CALL |
| stack | none | bare `ret` (`C3`) |
| return | void | no EAX produce |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Zero live count `@+0x0c` | **Yes** |
| Freelist helper `004cb680` | **Yes** |
| Conditional free slab + delete[] table | **Yes** |
| Null `+0x10` | **Yes** |
| Leave `+0x08` / ordered lists / lock untouched | **Yes** |

### Post-condition

Table pointer null; live count 0; freelist may hold former chain nodes (`+0x20` managed by nested helper). Mask at `+0x08` still valid for freelist helper during walk (caller had set mask via prior alloc).

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = destroy bucket table after node release | **High** (CF + recreate/dtor callers + inventory twin pattern) |
| thiscall ECX / bare ret | **High** (entry+exit bytes + caller context) |
| free(*table)=slab; delete[]=ptr array | **High** (matches alloc dual free shape) |
| Zeros `+0x0c` not mask `+0x08` | **High** (bytes `c7460c00000000`) |
| Product English class name | **Open** (`_Inferred`) |
| Nested freelist helper full dual | **Open** (not OWN) |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
