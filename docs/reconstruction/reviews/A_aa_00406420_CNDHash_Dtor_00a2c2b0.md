# Review A (reconstruction fidelity): `aa_00406420` CNDHash_Dtor_00a2c2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406420` |
| **VA** | `0x00406420` |
| **Canonical name** | `CNDHash_Dtor_00a2c2b0` |
| **Prior alias** | `FUN_00406420` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9H-D) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_00406420_CNDHash_Dtor_00a2c2b0.md` |
| **System** | container / CNDHash (host vtbl `00a2c2b0`) |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, `disassemble_function`, callers/xrefs, `get_assembly_context` |
| **Partition** | `WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-D** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Destroy host-family **CNDHash** with vtbl **`PTR_FUN_00a2c2b0`**:

```text
// __thiscall ECX=self; bare ret
self->vtbl = 00a2c2b0
if lock@+0x1d:
  log "HashError:Destructor, already locked for traversal"
  log "VOG_DEBUG_STOP"
  // fall through — non-fatal
EAX = self; CALL CNDHash_DestroyBucketTable_00a2c2e4
FUN_00416e80(self + 0x20)   // freelist slab vector dtor
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x00406420)` ≡ raw CF |
| Body bytes | `read_memory` — vtbl imm; string pushes `0xa2c270` / `0xa15844`; bare `C3` |
| Disasm | `MOV ESI,ECX`; lock `CMP [ESI+0x1d],0`; `MOV EAX,ESI; CALL 00406fc0`; `LEA EAX,[ESI+0x20]; CALL 00416e80` |
| Caller | `FUN_00406520` @ `00406523` — scalar deleting dtor (vtbl[0]) |
| Nested dual | `CNDHash_DestroyBucketTable_00a2c2e4` sealed WQ9G-J |
| Clean | `reconstructed-exact/CNDHash_Dtor_00a2c2b0.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | self | entry `MOV ESI,ECX` |
| stack | none | bare `ret` (`C3`) |
| Destroy nested | **EAX**=self | `MOV EAX,ESI; CALL 00406fc0` |
| Freelist nested | stack `self+0x20` | `LEA EAX,[ESI+0x20]; PUSH EAX` |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Re-stamp vtbl | **Yes** |
| Lock soft log (no throw / no skip) | **Yes** |
| DestroyBucketTable EAX ABI | **Yes** |
| Freelist dtor at +0x20 | **Yes** |
| Sole scalar-deleting caller | **Yes** |

### String evidence

- `0x00a2c270` → `HashError:Destructor, already locked for traversal`
- `0x00a15844` → `VOG_DEBUG_STOP`

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = CNDHash complete dtor body for vtbl 00a2c2b0 | **High** |
| thiscall + bare ret | **High** |
| Non-fatal lock assert | **High** |
| Destroy + freelist order | **High** |
| Product English | **Open** |
| Full dual of FUN_00416e80 | **Open** (residual) |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
