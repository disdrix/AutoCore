# Review B (skeptical / adversarial): `aa_0052db50` SkillTree_RemoveBySkillId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052db50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-T) |
| **Counterpart** | `reviews/A_aa_0052db50_SkillTree_RemoveBySkillId_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role claims).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler body is complete (delete then return) | **Falsified** — slide/erase after delete; loop continues |
| 2 | `operator_delete` is noreturn | **Falsified** — standard CRT delete; execution continues |
| 3 | TFID base is `+0x164` on the **same** this as SiblingCastClear | **Falsified as contradiction** — clear this is `adj+4`, so TFID is host `+0x160` |
| 4 | Sibling clear flag is 0 (like hash refresh) | **Falsified** — `push 1` |
| 5 | `__cdecl` / bare `ret` | **Falsified** — `ret 4` thiscall |
| 6 | Removes from skill **hash** (`+0x70`) | **Falsified** — vector at `+0x550` only |
| 7 | Stops after first match always | **Partially false** — continues loop; may hit duplicates |
| 8 | Clean may omit erase “because decomp did” | **Falsified** — erase is required for retail CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 4 | **High** | stack imbalance |
| Erase after delete | **High** | leak slots / double-free next iter |
| Flag 1 (OKToCastAgain too) | **High** | leftover cast-again HBs |
| host = adj+4 | **High** | wrong list / TFID |
| Product name | **Open** | catalog |

---

## 3. Cross-check against raw + bytes

```
// sealed match path (hex-backed):
adj = this + *(*(this+4)+4);
Skill_SiblingCastClear(adj+4, skillId, *(adj+0x164..), flag=1);
operator_delete(*it);
// erase 12-byte element at it; end -= 0xC; do not it += 1 element
```

Any clean plate that returns immediately after delete, uses flag 0, or reads TFID from unadjusted `this+0x160` without the `+4` host is **wrong**.

---

## 4. Surviving contract for AutoCore

```c
// Port:
void SkillTree_RemoveBySkillId_Inferred(TreeOwner* self, int skillId);

// - Container: vector-like [begin,end) of 12-byte nodes, skill* at +0.
// - On match: clear casts (incl. OKToCastAgain), free skill, compact vector.
// - this-adjust before clear is mandatory for multi-inheritance hosts.
// - Do not implement as hash-table erase.
```

---

## 5. Open questions

1. PDB / class name for tree owner.
2. Whether UI/skillbook always guarantees unique skillIds in the vector.
3. Relationship of this vector to hash at host+0x70 (parallel containers?).

**Verdict:** **accept-with-gaps**
