# Review A (reconstruction fidelity): `aa_00626240` CVOGHBSkill_PossessCreature_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626240` |
| **VA** | `0x00626240`–`0x006262e4` (165 B / `0xA5`; pad `CC` → `0x006262f0`) |
| **Canonical name** | `CVOGHBSkill_PossessCreature_ctor` (Ghidra `FUN_00626240`) |
| **Review date** | `2026-08-05` (OWN-ONLY dual A — R11-021) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00626240_CVOGHBSkill_PossessCreature_ctor.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (create / residual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs/bulk xrefs. **No** `disassemble_bytes`. Parent dual of `CVOGHBSkillBase_ctor` (`0x005788d0`) used for base arg semantics only.

---

## 1. Purpose

**PossessCreature skill HB subclass constructor** (RTTI Confirmed). After heap alloc of **0x6f0**:

1. SEH frame (`LAB_009a8ae8`)
2. `CVOGHBSkillBase_ctor` with six stack args
3. Install vtbl **`0x009d1ba4`**
4. Clear `+0x6c8`, `+0x6c4`, `+0x6c9`
5. Dyn-cast `pTarget` (`param_5`) `CVOGClonedObjectBase` → `CVOGCreature` → store `+0x6c0`
6. Null cast → `FUN_007a4480(0, "VOG_DEBUG_STOP")` (construction still returns `this`)
7. Return `this` / `ret 0x18`

Does **not** Enqueue/Start HB, pack network state, or allocate — caller owns alloc and lifecycle.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00626240_FUN_00626240.md` | Append re-verify |
| Annotated | `docs/reconstruction/raw/aa_00626240_FUN_00626240.annotated.md` | Refined |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_PossessCreature_ctor.cpp` | New/replace |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_00626240.cpp` | Refined |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_00626240.cpp` | Retired (string≠class) |
| Function record | `docs/reconstruction/functions/aa_00626240_CVOGHBSkill_PossessCreature_ctor.md` | New |
| Scaffold record | `docs/reconstruction/functions/aa_00626240_FUN_00626240.md` | Updated |
| Live decompile | Ghidra @ `0x00626240` | ≡ raw CF |
| Live bytes | `read_memory` 180 B | body + pad + next leaf head |
| Xrefs | complete + bulk | 1 code call + vtbl DATA |
| RTTI | COL `0x00aae5ec` / TD `0x00afecec` | class string Confirmed |
| Type table | `FUN_0054a640` id `0x1a` | size `0x6f0` + vtbl |

**Not performed:** Launcher, runtime golden, dual of non-OWN vtbl methods, parent ledger edits.

---

## 3. Signature (image-sealed)

```c
// __thiscall  ECX = this (fresh 0x6f0 allocation)
// stack: pSource, pSkillBlob, arg4, pTarget, pTfid, arg7
// ret 0x18
// returns this*
void *CVOGHBSkill_PossessCreature_ctor(
    void *this,
    void *pSourceObj,
    void *pSkillBlob,
    uint32_t arg4,
    void *pTarget,
    void *pTfid,
    uint32_t arg7);
```

| Item | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = this | `mov esi,ecx`; ops via `[esi]` | **High** |
| Six stack args / `ret 0x18` | `C2 18 00`; stack offsets | **High** |
| Returns this | `mov eax,esi` | **High** |
| Vtbl `0x009d1ba4` | `C7 06 A4 1B 9D 00` | **High** |
| Base ctor `0x005788d0` | relative call | **High** |
| Fields `+0x6c8/6c4/6c9/6c0` | immediates `C8 06`…`C0 06` | **High** |
| Dyn cast TDs | push `0x00af8d0c` / `0x00af8e10` + strings | **High** |
| Class name | RTTI `.?AVCVOGHBSkill_PossessCreature@@` | **Confirmed** |
| Size `0x6f0` | factory `push 0x6f0` + type table | **High** (caller/registry) |
| Assert path non-fatal | falls through after `FUN_007a4480` | **High** |

---

## 4. Byte seal (relative calls / immediates)

| next-IP | Target / imm | Meaning |
|---|---|---|
| `0x00626284` | `0x005788d0` | `CVOGHBSkillBase_ctor` |
| `0x00626297` | `0x009d1ba4` | subclass vtbl store |
| `0x006262af` | `__RTDynamicCast` | CRT cast |
| `0x006262cc` | `0x007a4480` | debug-stop helper |
| `0x006262e2` | `C2 18 00` | ret 24 |

RTTI TD strings:

| Addr | String |
|---|---|
| `0x00afecec+8` | `.?AVCVOGHBSkill_PossessCreature@@` |
| `0x00af8e10+8` | `.?AVCVOGClonedObjectBase@@` |
| `0x00af8d0c+8` | `.?AVCVOGCreature@@` |
| `0x00a15844` | `VOG_DEBUG_STOP` |

---

## 5. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| SEH → base skill ctor | **Yes** |
| vtbl install then three clears | **Yes** |
| dyn_cast param_5 → +0x6c0 | **Yes** |
| null → debug stop, still return this | **Yes** |
| ret 0x18 / no Enqueue | **Yes** |

---

## 6. Gaps / open

1. Product English for non-OWN vtbl methods on `0x009d1ba4` (OnHeartBeat / pack / EndOrDestroy).
2. Producers that fill `+0x6c4` after ctor (consumer visible in `FUN_00626160` — not OWN).
3. Full arg-site catalog beyond sole full-ctor call `0x006263ab`.
4. Runtime / bit-exact / differential — open (Terminal false).

**Verdict:** **accept-with-gaps** — CF/ABI/RTTI/fields/size sealed; non-OWN method English + runtime open.
