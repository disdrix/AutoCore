# Review A (reconstruction fidelity): `aa_00606ff0` Outpost_PreRecastBankWalk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00606ff0` |
| **VA** | `0x00606ff0` |
| **Body** | `0x00606ff0`–`0x006070d6` exclusive (**230** B) |
| **Canonical name** | `Outpost_PreRecastBankWalk` |
| **Prior / alias** | `FUN_00606ff0` |
| **Review date** | `2026-07-29` (W20-C OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00606ff0_Outpost_PreRecastBankWalk.md` |
| **System** | skills-abilities / outpost |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-faction outpost **skill-bank side-effect walk** used immediately before BeaconShare recast (ratio change) and during CaptureOutpost outgoing-faction teardown.

For each bank entry with **`flag@+0x0C == 0`**, resolve every faction TFID (mode 0), get skill host via `vtbl+0x1ec`, then **`vtbl+0x220(skillId, 1)`**. No ratio gate and no full cast pipeline.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00606ff0_FUN_00606ff0.md` (+ W20-C re-seal) |
| Annotated | `docs/reconstruction/raw/aa_00606ff0_FUN_00606ff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Outpost_PreRecastBankWalk.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00606ff0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00606ff0_Outpost_PreRecastBankWalk.md` |
| Live decompile | ≡ frozen raw CF |
| Live bytes | `read_memory` @ `0x00606ff0` length 256 |
| Meta | body 230 B; 2 xrefs; callee ResolveObjectTarget |
| Context (not owned) | BeaconShare `0x006070e0`, ratio update `0x006078e0`, CaptureOutpost `0x006082e0` |

---

## 3. Byte seal (summary)

```
push ecx / mov eax,[esp+8]     ; faction stack arg
test eax / mov ebx,ecx         ; this
jl/jge early if faction∉[0,4)
lea  scale → factionBase = this + faction*0x48  (ESI)
outer: bank begin/end +0xd4/+0xd8; count >>4
  cmp byte [entry+0x0C],0 / jnz skip
  inner: TFID +0xb4/+0xb8; count >>3
    ResolveObjectTarget @ 004bae70 (mode 0)
    call [vtbl+0x1ec]; jz
    MI adjust; push 1; push skillId; call [vtbl+0x220]
pop/ret 4   (c2 04 00)
```

| Claim | Evidence | Conf |
|---|---|---|
| thiscall + ret 4 | `mov ebx,ecx`; epilogue `c2 04 00` | **High** |
| faction ∈ [0,4) | signed jl / jge 4 | **High** |
| *0x48 faction stride | `lea` scale from bytes + decompile | **High** |
| bank 0x10 / TFID 8 | `>>4` / `>>3` | **High** |
| flag==0 only | `80 7d 0c 00` | **High** |
| no ratio float compare | no `+0x24c` / entry+8 loads | **High** |
| 0x220(skillId,1) | `6a 01` / `ff 90 20 02 00 00` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Faction gate | **Yes** |
| Outer bank / flag filter | **Yes** |
| Inner TFID + Resolve mode 0 | **Yes** |
| 0x1ec → 0x220(skillId,1) | **Yes** |
| No invent ratio / CastSkillOnTarget | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ABI / body size / ret 4 | **Confirmed** | |
| Shared bank/TFID layout with BeaconShare | **Confirmed** | same +0xd4/+0xb4 family |
| Distinct from BeaconShare cast | **Confirmed** | no ResolveSkillTargets / batch |
| Role = pre-recast / teardown walk | **High** | call-site order sealed |
| Product name / +0x220 English | **Inferred / Open** | |
| Runtime | Open | |

---

## 6. Gaps / open

1. Product/PDB method name.
2. Exact product meaning of `vtbl+0x220(skillId, 1)` (related: wire remove uses `(id, 0)`).
3. Whether CaptureOutpost path expects “clear” vs “apply” semantics — CF sealed, intent residual.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
