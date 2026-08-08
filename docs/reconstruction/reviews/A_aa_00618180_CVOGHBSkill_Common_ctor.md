# Review A (reconstruction fidelity): `aa_00618180` CVOGHBSkill_Common_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00618180` |
| **VA** | `0x00618180`–`0x00618265` (Ghidra body end `00618267`) |
| **Body** | **230 bytes** / `0xE6` |
| **Canonical name (Ghidra)** | `FUN_00618180` |
| **Proposed name** | `CVOGHBSkill_Common_ctor` |
| **Review date** | `2026-08-05` (R11-014 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00618180_CVOGHBSkill_Common_ctor.md` |
| **System** | skills-abilities |
| **Parent** | `CVOGHBSkillBase_ctor` @ `0x005788d0` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Constructor** for RTTI class **`CVOGHBSkill_Common`**: skill-base init, install Common vtbl, seed Common-tail fields, optionally clamp/rescale HB period when remaining seconds exceed 30.0f under a target-side gate. Intermediate base for multiple subclass ctors (notably Virus).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x00618180` |
| Meta | `get_function_by_address` body `00618180`–`00618267` |
| Bytes | `read_memory` entry + mid + epilogue; vtbl; COL; type_info; `DAT_00a0f694` |
| Callers | `get_function_callers` / `get_function_xrefs` (15 CALL) |
| Peer | `CVOGHBSkill_Virus_Ctor` dual (calls this with `0, 1.0f`) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00618180` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, other VAs duals.

---

## 3. Signature

```c
CVOGHBSkill_Common* __thiscall CVOGHBSkill_Common_ctor(
    CVOGHBSkill_Common *this,
    void *pSourceObj, void *pSkillBlob, uint32_t arg4,
    void *pTarget, void *pTfid16, uint32_t arg7,
    uint8_t commonFlag,   // → this+0x6c0
    float commonScale);   // → this+0x6c4 (movss)
// ret 0x20; EAX = this
```

| Item | Evidence |
|---|---|
| Convention | `8B F1` (`mov esi,ecx`); terminal `C2 20 00` |
| Vtbl | `C7 06 2C 1F 9E 00` → `PTR_FUN_009e1f2c` |
| Class | type_info `0x00af2918` → `.?AVCVOGHBSkill_Common@@` |
| Base | rel32 → `0x005788d0` |
| +0x6c0 / +0x6c4 / +0x6c8 | `88 96 C0 06…` / `F3 0F 11 86 C4 06…` / `89 8E C8 06…` |
| Period helpers | calls `0x00508280`, `0x005081a0` |
| Threshold | `DAT_00a0f694` = `30.0f` (`00 00 F0 41`) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH + SkillBase ctor | Yes |
| Vtbl install | Yes |
| Tail field stores (byte/float/0) | Yes (bytes correct float) |
| Gate `+0x44` / `pTarget+0xa4` / `+0xf6` | Yes |
| Remaining > 30 → rescale or clamp | Yes |
| Return this / ret 0x20 | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Class = `CVOGHBSkill_Common` | **Confirmed** | RTTI string |
| Role = ctor | **High** | vtbl install + `new(0x6d0)` callers |
| ABI thiscall + 8 stack + ret 0x20 | **Confirmed** | bytes |
| `+0x6c4` is float | **Confirmed** | `movss` |
| Period clamp math 30000 / `+0x08` | **Confirmed** | `div` + SetPeriod |
| Product English for flag/scale fields | **Open** | structural only |
| Gate `+0xa4`/`+0xf6` product meaning | **Open** | offsets sealed |

---

## 6. Gaps / open

1. Product design English for Common skill beyond RTTI name.  
2. Field English for `+0x6c0` / `+0x6c4` / blob `+0x44`.  
3. Entity subobject at `target+0xa4` identity.  
4. Full Common vtbl method map.  
5. Runtime / bit-exact / differential.

**Verdict:** **accept** — class Confirmed; ctor CF/ABI/vtbl/period gate High.
