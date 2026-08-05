# Review A (reconstruction fidelity): `aa_00576860` WaterPhase_RegisterToken_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00576860` |
| **VA** | `0x00576860`–`0x00576889` exclusive (**41 B** / `0x29`) |
| **Canonical name** | `WaterPhase_RegisterToken_Inferred` |
| **Ghidra name** | `FUN_00576860` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-S) |
| **Counterpart** | `reviews/B_aa_00576860_WaterPhase_RegisterToken_Inferred.md` |
| **System** | client / VOGEnvironmentSector water phase |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (body); callee decompiles for host semantics only. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Water-arm post-init helper after water object ctor + vcall(+0x20):

1. `operator_new(4)`.
2. `FUN_00576c40(token)` — install phase-token vtbl `PTR_FUN_009d3ac4`.
3. `FUN_00746400(DAT_00d1f620, token)` — find-or-append in global registry.
4. Return **1** (found), **0** (appended), or **-1** (OOM).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-S) | `docs/reconstruction/raw/aa_00576860_FUN_00576860.md` |
| Annotated | `docs/reconstruction/raw/aa_00576860_FUN_00576860.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/WaterPhase_RegisterToken_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00576860.cpp` |
| Function records | `functions/aa_00576860_FUN_00576860.md`, `functions/aa_00576860_WaterPhase_RegisterToken_Inferred.md` |
| Related | W31-P water arm; ctor peer `WaterPhase_Ctor_Inferred`; distort twin `FUN_00576d70` |
| Live | body 41 B; `C3`; `8B 0D 20 F6 D1 00` before `FUN_00746400` |

---

## 3. Signature (sealed)

```c
// no stack formals; bare RET; status in EAX
int32_t WaterPhase_RegisterToken_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| (none) | bare `ret` | **High** |
| return -1 | `83 C8 FF` fail path | **High** |
| return 0/1 | `FUN_00746400` | **High** |
| host | `DAT_00d1f620` via ECX | **High** (bytes) |

---

## 4. Control flow (clean ≡ raw ≡ live bytes)

```
token = new(4)
if !token: return -1
obj = FUN_00576c40(token)   // vtbl install
if !obj: return -1
return FUN_00746400(*&DAT_00d1f620 host, obj)
```

| Stage | Match | Conf |
|---|---|---|
| Body 41 B / bare RET | **Yes** | **High** |
| new(4) + micro-ctor | **Yes** | **High** |
| Registry this-arg global | **Yes** (bytes; decompiler gap filled) | **High** |
| Parent `hr < 0` fail | **Yes** (W31-P) | **High** |

---

## 5. Gaps

- Product demangle for 4-byte token (`CVOGPhase*` family hint only).
- Full registry host type at `DAT_00d1f620`.
- Append failure modes inside `FUN_004406e0`.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals CF, sizes, return codes, and registry this-arg omitted by decompiler. Residual product English → **accept-with-gaps**.
