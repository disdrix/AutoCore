# Review A (reconstruction fidelity): `aa_0061b960` Skill_HB_CopyTfid16At668_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061b960` |
| **VA** | `0x0061b960`–`0x0061b986` |
| **Canonical name (Ghidra)** | `FUN_0061b960` |
| **Proposed name** | `Skill_HB_CopyTfid16At668_Inferred` |
| **Review date** | `2026-08-05` (MEGA-016 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0061b960_Skill_HB_CopyTfid16At668_Inferred.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **TFID_16 out-copy** from skill-HB field **`+0x668`**. Not the object-identity twin at `+0x228` (`Object_CopyTfid16At228_Inferred`), not equality/resolve helpers, not a mutator.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0061b960` |
| Complete analyze | `analyze_function_complete` (leaf, 1 xref, 0 callees) |
| Bytes | `read_memory` 40 B @ entry |
| Disasm | `disassemble_function` (full body; **not** `disassemble_bytes`) |
| Meta | `get_function_by_address` body `0061b960`–`0061b986` |
| Callers / xrefs | `get_function_callers` / `get_function_xrefs` → sole site `0x0061b760` |
| Call-site | `get_assembly_context` @ `0x0061b760` + parent decompile `FUN_0061b6f0` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0061b960` |
| Peer dual | `Object_CopyTfid16At228_Inferred` `aa_0040aff0` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Signature

```c
TFID_16* __thiscall Skill_HB_CopyTfid16At668_Inferred(void *thisSkillHb, TFID_16 *out);
// ret 4; EAX = out
```

| Item | Evidence |
|---|---|
| Convention | `ret 4` @ `0x0061b984` (`c2 04 00`) |
| Offset | `add ecx, 0x668` (`81 c1 68 06 00 00`) |
| Width | four `mov` dword pairs → 16 B (`+0x668..+0x677`) |
| Leaf | no CALL in body |
| EAX return | `mov eax,[esp+4]` preserved; post-call `mov ebp,[eax]` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Four dword copy +0x668..+0x674 | Yes |
| No branches | Yes |
| No callees | Yes |
| ret 4 | Yes |
| Decompile CF ≡ 2026-07-23 raw | Yes (live re-verify append) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 16 B copy from +0x668 | **High** | bytes + disasm + decompile |
| Out buffer = TFID_16 role | **High** | parent pushes 4 dwords into target apply; twin shape @ +0x228 dualed as TFID |
| `this` = skill-HB object | **High** | sole caller `FUN_0061b6f0` pulse path; ECX=ESI skill object |
| Product English name | **Tentative** | `_Inferred` |
| Exact RTTI of `this` | **Probable** | skill-HB base layout; concrete class residual |

---

## 6. Gaps / open

1. Product/PDB symbol.  
2. Full formal type of `this` without parent-specific cast.  
3. Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/offset/role High; product English Inferred.
