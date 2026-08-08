# Review B (skeptical / adversarial): `aa_004cb410` SkillCNDHash_AllocBucketTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb410` |
| **VA** | `0x004cb410` |
| **Canonical name** | `SkillCNDHash_AllocBucketTable_Inferred` |
| **Review date** | `2026-08-04` (WQ9E-A dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004cb410_SkillCNDHash_AllocBucketTable_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + caller assembly_context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Soft-fail / return error on bad log2 | **Falsified** — log + `_CxxThrowException` noreturn |
| 2 | log2 domain 0..15 or 0..16 inclusive of 0 | **Falsified** — `cmp al,1; jl` rejects 0; `cmp al,0x10; jg` rejects >16 |
| 3 | `+8` remains bucket **count** after return | **Falsified** — `add dword [esi+8], -1` → **mask** |
| 4 | Single allocation for table+slab | **Falsified** — `new[]` then `malloc` |
| 5 | Type-merge with `CNDHash_AllocBucketTable_Inferred` `0x00413d80` | **Falsified** — different VA; stamp `009cb970` vs other families |
| 6 | ECX is owner / skill-id arg | **Falsified** — thiscall on hash; log2 already at `+0x1c` |
| 7 | Stack arg / ret 4 | **Falsified** — bare ret |
| 8 | Product class / stamp English sealed | **Fails** — `_Inferred` correct |
| 9 | Runtime Confirmed / bit-exact | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
// entry
ESI = ECX
AL = [ESI+0x1c]
if AL < 1 or AL > 0x10: VOG_DEBUG_STOP; throw 0x80004003
EAX = [ESI+8]                 // N
new[](N*4) → [ESI+0x10]
malloc(N*0xc) → slab in EAX/EDX walk
for i=0..N-1:
  table[i] = slab+i*0xc
  *sent = 0x009cb970; sent+4=0; sent+8=0
[ESI+8] = N - 1
pop edi; pop esi; pop ecx; ret
```

Caller recreate (`004cbe0c`) seeds before call:

```text
// after destroy:
[ESI+0x1c] = log2
[ESI+8]    = 1 << log2
[ESI+0x18]=0; [ESI+0x14]=0
MOV ECX, ESI
CALL 0x004cb410
```

Ctor path (`0051ddba`) same alloc after field zeros + provisional count.

A ≡ B on live decompile + gate/mask bytes. Parent WQ9D recreate dual mask post-condition **holds** via this unit.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alloc CF + mask | **High** | Insert bucket wrong (`key & mask`) |
| log2 throw domain | **High** | Silent corrupt table |
| Stamp identity skill family | **High** (imm) | Cross-family type merge |
| OOM path | **Open** | Crash vs undefined if null |
| Product English | **Open** | Naming only |

---

## 4. Surviving contract

```text
// pre: hash+0x1c = log2 in 1..16; hash+8 = 1<<log2; table typically null
SkillCNDHash_AllocBucketTable_Inferred(hash);
// post: hash+0x10 = table; each bucket empty sentinel; hash+8 = (1<<log2)-1
// bad log2: throws 0x80004003 after VOG_DEBUG_STOP
```

Do **not**:

- treat as soft no-op on bad log2
- leave `+8` as count after success
- merge with inventory/medal alloc helpers
- invent product class English without RTTI/string

**Verdict:** **accept-with-gaps.** Accept A.
