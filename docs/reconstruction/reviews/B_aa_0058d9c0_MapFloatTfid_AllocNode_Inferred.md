# Review B (skeptical / adversarial): `aa_0058d9c0` MapFloatTfid_AllocNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d9c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058d9c0_MapFloatTfid_AllocNode_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Void / no return | Callers assign `local = FUN_0058d9c0()`; must return EAX | **Falsified void product** (decomp bug) |
| 2 | Gather-only helper | 7 callers including spatial + AI | **Falsified** |
| 3 | Full tree ctor (head links) | Only alloc+partial init; gather **itself** sets isnil=1 and self-links | **Falsified full-ctor** |
| 4 | Zeros entire 0x30 | Only links + two flag bytes; key/payload uninitialized | **Falsified full zero** |
| 5 | Inserts into a global map | No tree param; pure factory | **Falsified** |
| 6 | Size 0x28 / std modern node | Literal `operator_new(0x30)` | **Falsified** |
| 7 | Product name sealed | No RTTI/string | **Hold `_Inferred`** |
| 8 | `+0x29=0` means head | Head path **overwrites** to 1 after return | **Falsified as head-ready** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alloc size 0x30 | **High** | Heap corruption |
| Partial init only | **High** | Assume zero payload wrongly |
| Multi-system reuse | **High** | Rename as gather-private |
| EAX return | **High** | Port drops return |
| STL identity exact | **Probable** | Wrong modernizer container |
| +0x28 color semantics | **Probable** | RB balance edge (if porting tree) |

---

## 3. Cross-check against raw

```
p = new(0x30)
if p: p[0]=p[1]=p[2]=0; *(u8*)(p+0x28)=1; *(u8*)(p+0x29)=0
return p  // decomp omits; callers require
```

Clean ≡ raw CF (plus documented return hole). Gather head post-init sealed in parent raw.

---

## 4. Surviving contract for AutoCore

```
MapFloatTfid_AllocNode_Inferred():
  allocate 0x30 node skeleton (links 0, flags +0x28/+0x29)
  caller finishes head (isnil=1, self-links) OR insert fills key/payload
Do NOT treat as complete map construction.
Do NOT scope as GatherTargets-only.
```

---

## 5. Open questions

1. Insert allocator vs this function for interior nodes.
2. All consumers’ value_type layout beyond float+TFID gather case.
3. Runtime OOM.

**Verdict:** **accept-with-gaps**
