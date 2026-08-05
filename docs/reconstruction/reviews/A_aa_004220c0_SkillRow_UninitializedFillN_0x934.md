# Review A (reconstruction fidelity): `aa_004220c0` SkillRow_UninitializedFillN_0x934

| Field | Value |
|---|---|
| **Stable ID** | `aa_004220c0` |
| **VA** | `0x004220c0` |
| **Body** | `0x004220c0`–`0x004220e3` (36 bytes) |
| **Canonical name** | `SkillRow_UninitializedFillN_0x934` |
| **Ghidra name** | `FUN_004220c0` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Skill_DbLoadSkillsCharacters_004220c0` |
| **Review date** | `2026-07-29` (W22-M dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004220c0_SkillRow_UninitializedFillN_0x934.md` |
| **System** | skills-abilities / vector helpers (stride 0x934) |
| **Live tools** | Ghidra `decompile_function` / `batch_decompile` + `read_memory` + callers/xrefs (`autoassault.exe`) |
| **Verdict** | **accept** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `SkillRowVec_EmplaceBack_Stride934_Inferred` / skill DbLoad vector plumbing |

---

## 1. Purpose

Leaf **uninitialized_fill_n** for fixed-stride **0x934** (2356-byte) elements:

```
ECX = count
EAX = dst
EBX = src prototype (fixed)
→ for each of count: if dst: rep movsd 0x24d dwords from EBX; dst += 0x934
```

Used by skill-row vector emplace/grow paths to stamp a template element into newly reserved slots.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `batch_decompile` @ `0x004220c0` (2026-07-29) ≡ raw |
| Bytes | `read_memory` 36 B — full body `test ecx` … `rep movsd` … `ret` |
| Call sites | `0x0041af46` (ecx=1), `0x0041c9a9`, `0x0041f884` (EBX=local prototype) |
| Raw / annotated / clean | `raw/aa_004220c0_*`, `reconstructed-exact/SkillRow_UninitializedFillN_0x934.cpp` |
| Function record | `functions/aa_004220c0_SkillRow_UninitializedFillN_0x934.md` |
| Parent dual | `reviews/A_aa_0041aef0_SkillRowVec_EmplaceBack_Stride934_Inferred.md` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf, 36 bytes, bare `ret` | **Confirmed** | `read_memory` + `get_function_by_address` |
| `0x24d` dwords / `0x934` stride | **Confirmed** | immediates `b9 4d 02 00 00` / `05 34 09 00 00` |
| ECX=count | **Confirmed** | `test ecx` / call-site `mov ecx,1` |
| EAX=dst | **Confirmed** | `test eax` / `mov eax,esi` at emplace site |
| EBX=src prototype | **Confirmed** | `mov esi,ebx` before `rep movsd`; grow path `lea ebx,local` |
| No ctor (POD copy only) | **Confirmed** | leaf; only movsd |
| Skill-row product fields | Medium | parent DbLoad; not this unit |
| Three known callers | **Confirmed** | xrefs |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| count==0 early out (`jbe`) | **Yes** |
| per-element null-dst skip | **Yes** |
| `rep movsd` 0x24d / add 0x934 | **Yes** |
| No modernization beyond naming | **Yes** |

---

## 5. Gaps

1. Product field map of 0x934-byte skill-character row (parent/loader-owned).
2. Runtime / bit-exact / differential.
3. Exhaustive proof no non-skill caller exists outside current 3 xrefs (static xrefs sealed).

**Verdict:** Leaf fill-N fully sealed from bytes + call sites. **accept.**
