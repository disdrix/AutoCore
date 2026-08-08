# Review A (reconstruction fidelity): `aa_004cbdc0` SkillCNDHash_Recreate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbdc0` |
| **VA** | `0x004cbdc0` |
| **Canonical name** | `SkillCNDHash_Recreate_Inferred` |
| **Prior alias** | `FUN_004cbdc0`, `Named_VOG_DEBUG_STOP_004cbdc0` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9D-A) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md` |
| **System** | skills-abilities / skill-family CNDHash |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory`, callers/xrefs, assembly_context |
| **Partition** | `WAVE_2026-08-04_wq009_depth_partition_map.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Recreate** skill-family **CNDHash** table at a new power-of-two size:

```text
// __thiscall:
//   ECX = hash*
//   stack byte log2 → stored at hash+0x1c; provisional size = 1 << (log2 & 0x1f)

if (*(hash+0x1d) != 0):  // traversal lock
  log "HashError:Recreate, already locked for traversal"
  log "VOG_DEBUG_STOP"
  // continue (does not abort)

FUN_004cba60(hash)                 // destroy old buckets/table
*(hash+0x1c) = log2
*(hash+0x18) = 0                   // ordered-list tail
*(hash+8)    = 1 << (log2 & 0x1f)  // provisional bucket COUNT
*(hash+0x14) = 0                   // ordered-list head
FUN_004cb410(hash)                 // alloc; then *(hash+8)-- → MASK
```

**Not** inventory `CNDHash_Recreate` `0x004138d0` (EAX/BL custom ABI). **Not** a skill insert / ensure-loaded path.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `decompile_function(0x004cbdc0)` ≡ 2026-07-23 raw |
| Entry / body bytes | `read_memory` — `56 8B F1` … `5E C2 04 00` + `CC` |
| Body range | `0x004cbdc0`–`0x004cbe14` (**85 B**); Ghidra end `004cbe14` |
| Strings | `"HashError:Recreate…"` @ `0x00a64c48`; `"VOG_DEBUG_STOP"` @ `0x00a15844` |
| Callees | `004cba60` destroy, `004cb410` alloc, `007a4480` log ×2 |
| Callers | `00518e30` CreateOrRecreateSkillHash; `004c8f00` @ `004c902c` push 2 |
| Parent dual | `Object_CreateOrRecreateSkillHash_Inferred` (`aa_00518e30`) |
| Ctor peer | `SkillCNDHash_Ctor_Inferred` (`aa_0051dd60`) same wave |
| Clean | `reconstructed-exact/SkillCNDHash_Recreate_Inferred.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | hash* | entry `mov esi,ecx` |
| **Stack[0x4]** | log2 (byte width, dword push) | `mov cl,[esp+8]` after push esi; `ret 4` |
| return | void | no EAX produce |
| cleanup | **`ret 4`** | `C2 04 00` |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Lock log-only (continue) | **Yes** |
| Destroy old table (`004cba60`) | **Yes** |
| Store log2 + power-of-two count | **Yes** |
| Clear ordered list head/tail | **Yes** |
| Alloc new buckets (`004cb410`) | **Yes** |

### Post-condition on `hash+8`

After full Recreate: `*(hash+8) = (1 << log2) - 1` (bit mask) — via alloc callee decrement. Insert paths use `key & mask` — **High** by family analogy + live alloc decompile.

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = skill CNDHash recreate / rebucket | **High** (string + CF + skill callers) |
| thiscall ECX/stack log2 / ret 4 | **High** (entry+exit bytes) |
| Lock is non-fatal log | **High** |
| Distinct from inventory `004138d0` | **High** (ABI + VA + helpers) |
| Product English class name | **Open** (`_Inferred`) |
| Nested destroy/alloc full dual | **Open** (support-only) |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
