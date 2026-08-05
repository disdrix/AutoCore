# Review A (reconstruction fidelity): `aa_0041aef0` SkillRowVec_EmplaceBack_Stride934_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041aef0` |
| **VA** | `0x0041aef0` (0x0041aef0-0x0041af6f) |
| **Canonical name** | `SkillRowVec_EmplaceBack_Stride934_Inferred` |
| **Ghidra name** | `FUN_0041aef0` |
| **Prior alias** | `Named_CalleeOf_Skill_DbLoadSkillsCharacters_0041aef0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0041aef0_SkillRowVec_EmplaceBack_Stride934_Inferred.md` |
| **System** | skills-abilities / DB load (Skill_DbLoadSkillsCharacters nested) |
| **Live tools** | Ghidra HTTP `batch_decompile` / `read_memory` / callers / callees / xrefs (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `Skill_DbLoadSkillsCharacters` `aa_007e34b0` nested (or shared DbLoad plumbing) |

---

## 1. Purpose

MSVC-like **vector emplace-back** for fixed stride **0x934** (2356) elements.

```c
// __fastcall (decompiler; sole static parent)
void SkillRowVec_EmplaceBack_Stride934_Inferred(Vec934 *v /*, element src via EAX/regs */);
```

Layout on `v`: `+0x04` begin, `+0x08` end, `+0x0c` capacity end.

1. If `begin != 0` and `(end-begin)/0x934 < (capEnd-begin)/0x934`:
   - `FUN_004220c0(v)` copies **0x24d dwords** (= **0x934 bytes**) into `*end`.
   - `end += 0x934`; return.
2. Else: `FUN_0041c920(&tmp, end, …)` grow/insert path.

Sole static caller: `Skill_DbLoadSkillsCharacters` (`0x007e34b0`) - 4 call sites (`007e3d66`, `007e4855`, `007e5057`, `007e592e`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x0041aef0` (2026-07-29) ≡ raw |
| Raw / annotated / clean | `raw/aa_0041aef0_*`, `reconstructed-exact/FUN_0041aef0.cpp` |
| Function record | `functions/aa_0041aef0_*.md` |
| Parent dual | `reviews/A_aa_007e34b0_Skill_DbLoadSkillsCharacters.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Stride is 0x934 | **High** | div/add immediates; FUN_004220c0 copies 0x24d dwords |
| begin/end/cap at +4/+8/+0xc | **High** | all three offsets in body |
| Fast path only when size < capacity | **High** | compare of two divisions |
| Parent is Skill_DbLoadSkillsCharacters only | **Confirmed** | get_function_callers / 4 xrefs |
| Element type is skill-character row | **Medium** | parent XPath //vSkillsCharacters/row |
| FUN_004220c0 is element dword-copy | **High** | 0x24d dword loop |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Body CF from scaffold clean | **Yes** |
| Live batch_decompile ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

---

## 5. Gaps

1. Product struct name for 0x934 row (field map owned by parent loader).
2. Full register ABI of FUN_0041c920 / FUN_004220c0.
3. Whether +0 is allocator cookie / pointer.

**Verdict:** Structural contract sealed from live decompile + xrefs. Product type names remain inferred. **accept-with-gaps.**
