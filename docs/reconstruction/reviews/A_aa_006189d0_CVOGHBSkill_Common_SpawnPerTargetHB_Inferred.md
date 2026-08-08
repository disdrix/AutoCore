# Review A (reconstruction fidelity): `aa_006189d0` CVOGHBSkill_Common_SpawnPerTargetHB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006189d0` |
| **VA** | `0x006189d0`–`0x00618be2` (Ghidra body) |
| **Body** | **530 bytes** / `0x212` |
| **Canonical name (Ghidra)** | `FUN_006189d0` |
| **Proposed name** | `CVOGHBSkill_Common_SpawnPerTargetHB_Inferred` |
| **Review date** | `2026-08-05` (R12-040 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_006189d0_CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.md` |
| **System** | skills-abilities |
| **Parent** | `CVOGHBSkill_Common_ctor` @ `0x00618180` |
| **Dual status** | **Present (first dual seal)** |
| **Dual start** | 2646 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

`CVOGHBSkill_Common` **vtbl+0x2c** multi-target fanout: chance-gated walk of a stride-`0x10` target table, resolve each TFID, spawn **Common** skill HBs (`new(0x6d0)` + `CVOGHBSkill_Common_ctor` with flag `0` / scale `1.0f`), Enqueue+Start, emit combat events **0x14/0x15**, return whether any HB started.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x006189d0` |
| Meta | `get_function_by_address` body `006189d0`–`00618be2` |
| Bytes | `read_memory` entry + mid (new/ctor) + epilogue; vtbl `0x009e1f2c`; slot `0x009e1f58`; COL `0x00ab1820` |
| Xrefs | `get_function_xrefs` / `get_xrefs_to` — sole DATA `0x009e1f58` |
| Callers | `get_function_callers` — none direct |
| Parent dual | `CVOGHBSkill_Common_ctor` R11 report (not edited) |
| Peer pattern | OnKill/Master Execute duals (vtbl+0x2c fanout) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_006189d0` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, other VAs duals.

---

## 3. Signature

```c
bool __thiscall CVOGHBSkill_Common_SpawnPerTargetHB_Inferred(
    CVOGHBSkill_Common *this,   // ECX unused in body
    void *pSourceObj,           // stack 1
    void *pSkillBlob,           // stack 2 — +0xe4 chance, event fields
    void *pWorld,               // stack 3 — +0xe4e8 reaction, +0xe4ec list
    TargetEntry *pTable,        // stack 4 — stride 0x10
    void *pTfid16,              // stack 5
    uint32_t rngSeed);          // stack 6 → Rng_CloneSeededTable
// ret 0x18; EAX = (spawnCount != 0)
```

| Item | Evidence |
|---|---|
| Terminal | `C2 18 00` @ `0x00618be0` |
| Bool return | `0F 95 C0` (setne al) after cmp spawnCount |
| Vtbl slot | `0x009e1f58` = `D0 89 61 00` → this VA |
| Class | COL `0x00ab1820` → type_info `0x00af2918` → `.?AVCVOGHBSkill_Common@@` |
| Child ctor | rel32 → `0x00618180`; pushes `0` + `0x3f800000` |
| Child size | `PUSH 0x6d0` before `operator_new` |
| Resolve this | `MOV ECX,[world+0xe4e8]` before call (bytes; decompiler drops) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH + Rng_CloneSeededTable(seed) | Yes |
| Loop table stride 0x10 + sentinel | Yes |
| Chance gate FUN_00589b80 | Yes |
| Resolve + new(0x6d0) + Common_ctor(0, 1.0f) | Yes |
| Owner null → dtor(1); else Enqueue+Start | Yes |
| Events 0x14/0x15 + self-skip | Yes |
| Return spawnCount != 0 / ret 0x18 | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Class = `CVOGHBSkill_Common` | **Confirmed** | RTTI + vtbl |
| Role = vtbl+0x2c multi-target spawn | **High** | DATA slot + CF |
| ABI thiscall surface + 6 stack + ret 0x18 | **Confirmed** | bytes |
| Bool any-started return | **High** | setne |
| Child Common_ctor path | **High** | parent dual VA |
| Product method English | **Open** | `_Inferred` required |
| Event 0x14/0x15 product names | **Open** | opcodes sealed only |
| Runtime Confirmed | **Rejected** | Terminal false |

---

## 6. Gaps / open

1. Product/PDB method spelling beyond structural name.  
2. Full C++ types for skill blob / world / TargetEntry producer.  
3. Product meaning of chance float `skill+0xe4` and scale `DAT_009d4d20`.  
4. Identity of vtbl+0x238 event channel (0x14/0x15).  
5. `FUN_00589b80` / `FUN_007a4120` product names (other partitions).  
6. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — class Confirmed; CF/ABI/vtbl+0x2c/spawn pipeline High; method English Inferred; no Runtime Confirmed.
