# Review B (skeptical / adversarial): `aa_004cba60` SkillCNDHash_DestroyBucketTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba60` |
| **VA** | `0x004cba60` |
| **Canonical name** | `SkillCNDHash_DestroyBucketTable_Inferred` |
| **Review date** | `2026-08-04` (WQ9E-A dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + caller assembly_context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Custom EAX ABI like inventory `0x00413e20` | **Falsified** — entry `push esi; mov esi,ecx`; callers set ECX |
| 2 | Zeros mask / count at `+0x08` | **Falsified** — only writes `+0x0c` (`c7460c…`) then freelist/free |
| 3 | `free(table)` frees pointer array as slab | **Falsified** — `free(**table)` = free first bucket ptr = slab base; `delete[]` on table |
| 4 | Full object destructor | **Falsified** — dtor `0051de80` calls this then `FUN_0059c8a0`; no vtbl reset here |
| 5 | ECX is owner object (`owner+0x70` host) | **Falsified** — recreate loads hash then passes hash; dtor is on hash object |
| 6 | Stack args / ret 4 | **Falsified** — bare `ret` (`C3`) |
| 7 | Product class name sealed | **Fails** — role High; English `_Inferred` |
| 8 | Nested freelist dual complete | **Fails** — `004cb680` residual open |
| 9 | Bit-exact / runtime Confirmed | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
// entry
ESI = ECX (hash)
[ESI+0x0c] = 0
call 004cb680          // ECX = ESI (thiscall restore before call — decomp shows free-form)
// if [ESI+0x10] != 0:
//   free(**[ESI+0x10])   // slab
//   delete[]([ESI+0x10]) // table
//   [ESI+0x10] = 0
pop esi; ret
```

Caller recreate context (`004cbde6`):

```text
MOV ECX, ESI           ; hash*
CALL 0x004cba60
; then seed log2 / count / head / tail; call alloc
```

Caller dtor context (`0051dece`):

```text
MOV ECX, ESI
CALL 0x004cba60
LEA ECX, [ESI+0x20]
CALL 0x0059c8a0        ; freelist host teardown (not OWN)
```

A ≡ B on live decompile + entry/exit. WQ9D parent dual B wording that destroy “zeros **count** field” was imprecise: it zeros **`+0x0c`**, not `+0x08` — corrected here without rejecting parent recreate CF.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Destroy CF / dual free | **High** | Use-after-free / leak on skill hash recreate |
| thiscall vs inventory EAX | **High** | Wrong port calling convention |
| `+0x0c` vs `+0x08` zero target | **High** | Wrong field model |
| Freelist helper semantics | **Medium** (shape High; full dual Open) | Residual leak if freelist mis-modeled |
| Product class name | **Open** | Naming only |

---

## 4. Surviving contract

```text
// hash* may be non-empty; +8 still mask from prior alloc when called from recreate/dtor
SkillCNDHash_DestroyBucketTable_Inferred(hash);
// after: +0xc=0; +0x10=0 if was non-null; freelist may hold nodes; +8 unchanged
```

Do **not**:

- treat as full dtor
- free the pointer array with `free` (must `delete[]`)
- free the slab with `delete[]` (must `free(*table)`)
- use inventory EAX calling convention
- claim product English sealed

**Verdict:** **accept-with-gaps.** Accept A.
