# Review A (reconstruction fidelity): `aa_0054fec0` Skill_StoreEffectPresenceFlags_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054fec0` |
| **VA** | `0x0054fec0`–`0x0054fef8` |
| **Canonical name (Ghidra)** | `FUN_0054fec0` |
| **Proposed name** | `Skill_StoreEffectPresenceFlags_Inferred` |
| **Review date** | `2026-08-04` (WQ9E-B OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0054fec0_Skill_StoreEffectPresenceFlags_Inferred.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Skill-runtime **presence-flag store helper**. Calls dualed `Skill_ComputeEffectPresenceFlags_Inferred` and writes the mask to **`skill+0x624`**, applying the sealed `|4` / `|0x100000` post-process used by `Skill_ReevaluateForCurrentRank`. Does not re-materialize ranked elements.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x0054fec0` |
| Bytes | `read_memory` @ `0x0054fec0` (64 B) — entry `56 8B F1 E8…`; dual ret paths; `CC` pad |
| Twin | live decompile `Skill_ReevaluateForCurrentRank` @ `0x00553390` — identical store after Evaluate |
| Presence leaf | dual sealed `aa_00627be0` / WQ9D-E |
| Xrefs | `get_xrefs_to` / bulk / data pattern `C0 FE 54 00` → empty |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0054fec0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledgers.

---

## 3. Signature

```c
void __fastcall Skill_StoreEffectPresenceFlags_Inferred(void *pSkill);
// ECX = skill; void; plain ret
```

| Item | Evidence |
|---|---|
| Convention | `push esi; mov esi,ecx` … `pop esi; ret` |
| ECX = skill | fields `+0x620/+0x624/+0x148` match Reevaluate skill layout; callee is skill presence scan |
| Void return | no EAX use after call chain |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Call presence leaf (ECX=skill) | **Yes** |
| `+0x620==0` → store mask plain to `+0x624` | **Yes** |
| else store `mask\|4` to `+0x624` | **Yes** (`or al,4`) |
| if `+0x148==0` → `+0x620 \|= 0x100000` | **Yes** |
| Does not call Evaluate | **Yes** (leaf store only) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Store CF + offsets | **High** | decompile ≡ bytes |
| Presence callee identity | **High** | dual WQ9D-E + relative call |
| Twin of Reevaluate store | **High** | CF-identical post-Evaluate tail |
| Static call graph complete | **Open** | zero xrefs |
| Bit 4 / 0x100000 / +0x148 English | **Open** | no strings |

---

## 6. Gaps / open

1. Product/PDB symbol.  
2. Why this VA has no static callers (dead extract vs dynamic).  
3. Full `+0x624` targeting enum glossary (shared residual).  
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/store High; caller graph + product English open.
