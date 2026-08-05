# Review A (reconstruction fidelity): `aa_005ccff0` CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ccff0` |
| **VA** | `0x005ccff0`–`0x005cd220` |
| **Canonical name** | `CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred` |
| **Ghidra** | `FUN_005ccff0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W29-L) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live + sealed callees) |
| **Counterpart** | `reviews/B_aa_005ccff0_CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.md` |
| **System** | CVOGHB AI engage / target select |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

HBAI engage helper: resolve **owner TFID** (`owner@this+0x64`, TFID `@+0x228`), promote direct candidate (`resolved+0xA0`) or **CVOGHBLinkedDeath** partner via locked list walk; on resolve fail set owner mode **0** via sealed `Object_SetMode278_SelectFromTFID228_Inferred`. Sole caller: `CVOGHBAICreatureBase_OnHeartBeat` engage arm.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `decompile_function` @ `0x005ccff0` |
| Body bytes | `read_memory` entry + tail (plain `ret` after `add esp,0x18`) |
| Meta | `get_function_by_address` / xrefs |
| Sealed callees | W28-L `004c3c80`; `Object_SetSelectedTarget` `005172d0`; resolve `004bb950`; list iter `004022a0` |
| Caller context | `CVOGHBAICreatureBase_OnHeartBeat` clean |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, `disassemble_bytes`.

---

## 3. Signature

```c
void __thiscall CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred(void *hbai);
// plain RET; 0 stack formals
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| TFID copy + resolve | Yes (bytes also seal manager ECX rebuild) |
| Fail → mode 0 @ `004c3c80` | Yes (`call` site `005cd0a2`) |
| Direct promote SetSelectedTarget | Yes (`005172d0`) |
| `FUN_004c8970` gate | Yes |
| LinkedDeath cast + partner promote | Yes |
| CS leave on list exit | Yes |
| Plain ret / no stack formals | Yes (bytes) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall HBAI + owner@+0x64 | **High** | prologue / loads |
| Resolve + mode0 fail path | **High** | sealed callee dual |
| Candidate `+0xA0` / vtbl gates | **High** | decompile + bytes |
| LinkedDeath walk | **High** | RTTI symbols in decompile |
| Product English vtbl/mode | Open | residual |
| `FUN_004c8970` product role | Open | residual |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product English for `+0x278` modes and vtbl `+0x298` / `+0x1c8` / `+0x214` / `+0x19c`.
2. Product name of `FUN_004c8970`.
3. Runtime / bit-exact / differential.

---

## 7. Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005ccff0_FUN_005ccff0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ccff0_FUN_005ccff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_005ccff0_CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.md` |

**Verdict:** **accept-with-gaps**
