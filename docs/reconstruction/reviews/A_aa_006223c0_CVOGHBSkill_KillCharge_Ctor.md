# Review A (reconstruction fidelity): `aa_006223c0` CVOGHBSkill_KillCharge_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006223c0` |
| **VA** | `0x006223c0`–`0x006223f3` (52 B / `0x34`; pad `CC` after) |
| **Canonical name (Ghidra)** | `FUN_006223c0` |
| **Proposed name** | `CVOGHBSkill_KillCharge_Ctor` |
| **Review date** | `2026-08-05` (R11-019 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_006223c0_CVOGHBSkill_KillCharge_Ctor.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`. **No** Launcher.

---

## 1. Purpose

**Constructor** for `CVOGHBSkill_KillCharge`:

1. `CVOGHBSkillBase_ctor(this, 6 stack args)` at `0x005788d0`
2. Install vtbl **`PTR_FUN_009d16e4`**
3. Return `this`

No subclass field stores, Enqueue, Start, or period seed in this leaf. Sole CALL is `FUN_00622f70` (CommonCastOnDeath factory) which may immediately replace the vtbl.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x006223c0` |
| Bytes | `read_memory` 64 B @ entry |
| Meta | `get_function_by_address` body `006223c0`–`006223f3` |
| RTTI | COL `0x00aae2d8` → type_info `0x00af2b70` → **`.?AVCVOGHBSkill_KillCharge@@`** |
| Vtbl | `read_memory` `0x009d16e4` |
| Caller | `FUN_00622f70` @ `0x00623009` (`operator_new(0x6d0)` then this ctor) |
| Peer factory (evidence) | `FUN_006226a0` installs same vtbl after `operator_new(0x6c0)` |
| Parent | `CVOGHBSkillBase_ctor` `0x005788d0` (partition parent; dual sealed prior) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_006223c0` |

**Not performed:** Launcher, runtime golden, dual of vtbl methods / `FUN_00622f70` / `FUN_006226a0`, parent ledger edits.

---

## 3. Signature (image-sealed)

```c
// __thiscall  ECX = this
// stack: pCaster, pSkillBlob, pWorldOrCtx, pTarget, pTfidBlob, arg7
// ret 0x18
// returns this*
void *CVOGHBSkill_KillCharge_Ctor(
    void *thisHb,
    void *pCaster, void *pSkillBlob, void *pWorldOrCtx,
    void *pTarget, void *pTfidBlob, uint32_t arg7);
```

| Item | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = this | `mov esi, ecx`; vtbl via `[esi]` | **High** |
| Six stack args / `ret 0x18` | `c2 18 00`; six pushes before base call | **High** |
| Returns this | `mov eax, esi` | **High** |
| Base = `CVOGHBSkillBase_ctor` | rel32 → `0x005788d0` | **High** |
| Vtbl `0x009d16e4` | `C7 06 E4 16 9D 00` | **High** |
| Class = KillCharge | RTTI string at type_info | **Confirmed** |
| Sole CALL | xref_count 1 → `FUN_00622f70` | **High** |
| Pure size `0x6c0` | peer factory `operator_new` (not this VA) | **High** (caller evidence) |
| Product skill English | RTTI token only | **Open** |

---

## 4. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| Forward 6 stack args into base ctor | **Yes** |
| Install `PTR_FUN_009d16e4` | **Yes** |
| Return this / `ret 0x18` | **Yes** |
| No branches / no extra stores | **Yes** |
| No Enqueue / Start in leaf | **Yes** |

---

## 5. Gaps / open

1. Product/PDB design English for KillCharge skill behavior.
2. Full semantic names of the six base-ctor stack parameters (parent domain).
3. Dual of sole caller `FUN_00622f70` / peer `FUN_006226a0` (not OWN).
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept** — class Confirmed; ctor CF/ABI/vtbl High.
