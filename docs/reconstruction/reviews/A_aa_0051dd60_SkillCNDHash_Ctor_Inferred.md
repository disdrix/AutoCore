# Review A (reconstruction fidelity): `aa_0051dd60` SkillCNDHash_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051dd60` |
| **VA** | `0x0051dd60` |
| **Canonical name** | `SkillCNDHash_Ctor_Inferred` |
| **Prior alias** | `FUN_0051dd60`, long scaffold callee-chain name |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9D-A) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_0051dd60_SkillCNDHash_Ctor_Inferred.md` |
| **System** | skills-abilities / skill-family CNDHash |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory`, callers/xrefs |
| **Partition** | `WAVE_2026-08-04_wq009_depth_partition_map.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Construct** skill-family **CNDHash** in a pre-allocated **`0x34`**-byte block:

```text
// __thiscall:
//   ECX = raw block (from operator_new(0x34))
//   stack byte log2
//   returns this in EAX

SEH LAB_009a371b
*this = PTR_FUN_009ce1b8          // skill CNDHash vtbl
zero +0x04, +0x0c, +0x10, +0x14, +0x18, +0x20, +0x28, +0x2c, +0x30
*(+8)  = 1 << (log2 & 0x1f)       // provisional COUNT
*(+0x1c) = log2                   // byte
*(+0x1d) = 0                      // lock clear
// +0x24 NOT written (odd; preserve)
FUN_004cb410(this)                // empty bucket table; mask post-cond
return this
```

Sole sealed caller: `Object_CreateOrRecreateSkillHash_Inferred` missing path stores return at `owner+0x70`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `decompile_function(0x0051dd60)` ≡ 2026-07-23 raw |
| Body bytes | `read_memory` — SEH + `c706 b8e19c00` vtbl store + field inits + `call 004cb410` + `ret 4` |
| Body range | `0x0051dd60`–`0x0051ddd2` (**115 B**); Ghidra end `0051ddd2` |
| Vtbl | `PTR_FUN_009ce1b8` @ data `0x009ce1b8` |
| Caller | sole xref `FUN_00518e30` create path (`push 0x34; new; this ctor`) |
| Recreate peer | `SkillCNDHash_Recreate_Inferred` (`aa_004cbdc0`) same wave |
| Clean | `reconstructed-exact/SkillCNDHash_Ctor_Inferred.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | raw hash block* | `mov esi,ecx` |
| **Stack[0x4]** | log2 | `mov cl,[esp+0x18]` (after SEH/push frame) |
| **EAX** | returns this | `mov eax,esi` before teardown |
| cleanup | **`ret 4`** | `C2 04 00` |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| SEH install | **Yes** (bytes; clean may omit frame boilerplate) |
| Vtbl install `009ce1b8` | **Yes** |
| log2 / count / lock / list zeros | **Yes** |
| **Skip +0x24** | **Yes** (bytes; decompiler also omits) |
| Alloc buckets | **Yes** |
| Return this | **Yes** |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = skill CNDHash constructor | **High** (vtbl + sole create caller + sizeof 0x34) |
| thiscall + ret 4 + return this | **High** |
| Field layout @ +0x08/+0x1c/+0x1d | **High** |
| Unwritten +0x24 oddity | **High** (bytes) |
| Product English class name | **Open** |
| Full vtbl method map | **Open** |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
