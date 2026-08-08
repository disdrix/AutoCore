# Review A (reconstruction fidelity): `aa_004c5510` Object_ApplyPrimaryAndLocalMaterialBanks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c5510` |
| **VA** | `0x004c5510`–`0x004c555d` inclusive (**78 B** / `0x4E`) |
| **Canonical name** | `Object_ApplyPrimaryAndLocalMaterialBanks_Inferred` |
| **Ghidra name** | `FUN_004c5510` |
| **Prior scaffold** | `FUN_004c5510` (2026-07-23 generic plate; decompiler omits primary this-adjust) |
| **Rejected misname** | bare permanent `FUN_*`; skill-cast / ability helper; single-bank-only; free function |
| **Review date** | `2026-08-05` (R10-029 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004c5510_Object_ApplyPrimaryAndLocalMaterialBanks_Inferred.md` |
| **System** | object / gfx material bank (R10 partition residual under skills-abilities parent) |
| **Parent dual** | `0x005194f0` `Gfx_BindMatDiffuseAmbientEmissive_Inferred` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_xrefs` + `get_function_callers` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MI-subobject virtual method that **applies material color banks on two paths**:

1. **Primary path:** recompute primary object from vbptr-like table at `this-0x4FC`, then call dualed `Object_ApplyMaterialBank_Inferred` (`0x0051b310`) which gates `+0x144` bank and binds via `vtbl+0x1CC` host.
2. **Local path:** if host at `this-0x27C` and local bank (`header this-0x20C`, begin/end +4/+8, stride `0x10`) is non-empty, call dualed `Gfx_BindMatDiffuseAmbientEmissive_Inferred` (`0x005194f0`) with `(host, header)`.

```text
Object_ApplyPrimaryAndLocalMaterialBanks_Inferred(subThis) -> void
  primary = (subThis - 0x4FC) + *(int*)(*(subThis-0x4FC)+4)
  Object_ApplyMaterialBank_Inferred(primary)
  host = *(subThis - 0x27C)
  if !host: return
  begin = *(subThis - 0x208); header = subThis - 0x20C
  if !begin: return
  if ((end-begin)>>4)==0: return
  Gfx_BindMatDiffuseAmbientEmissive_Inferred(host, header)
```

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x004c5510` — ≡ 2026-07-23 raw CF (minus Path A this rewrite) |
| Full body | `disassemble_function` + `read_memory` 78 B to `RET` |
| Bounds | `get_function_by_address` body `004c5510`–`004c555d` |
| Callees | dualed `0x0051b310`, `0x005194f0` |
| Xrefs | JMP adjustors `0x004cc9f3`, `0x0053bcf9` |
| Raw / annotated / clean | `aa_004c5510_*`, named + `FUN_` twins |

**Not performed:** Launcher, runtime material capture, parent ledger edits, dual of adjustor islands.

---

## 3. Signature (sealed)

```c
// __thiscall; ECX = MI subobject*; bare RET; no stack formals
void Object_ApplyPrimaryAndLocalMaterialBanks_Inferred(void *subThis /* ECX */);
```

| Formal | Source | Conf |
|---|---|---|
| subThis | ECX → ESI | **Confirmed** |
| return | void (no EAX write; `C3`) | **Confirmed** |
| cleanup | bare `RET`; callee `ADD ESP,8` for binder | **Confirmed** |
| convention | **thiscall** (not free cdecl) | **Confirmed** |
| entry | JMP adjustors only (no Ghidra CALL callers) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match raw/live/bytes |
|---|---|
| PUSH ECX / PUSH ESI / MOV ESI,ECX | **Yes** (bytes) |
| Path A primary this rewrite from `-0x4FC` | **Bytes win** over decompile no-arg call |
| CALL `0051b310` | **Yes** |
| host null gate `-0x27C` | **Yes** |
| begin null gate `-0x208` + LEA header `-0x20C` | **Yes** |
| count `(end-begin)>>4` zero gate | **Yes** |
| PUSH header / PUSH host / CALL `005194f0` / ADD ESP,8 | **Yes** (arg order sealed) |
| POP ESI / POP ECX / RET | **Yes** |

---

## 5. Call graph (this unit)

**Callees:** `Object_ApplyMaterialBank_Inferred` (`FUN_0051b310`), `Gfx_BindMatDiffuseAmbientEmissive_Inferred` (`FUN_005194f0`).  
**Callers:** none as CALL; two JMP MI adjustors (`0x004cc9f0` family, `0x0053bcf0` family with `SUB ECX,0x8A0`).

---

## 6. Gaps / open

1. Product / RTTI class owning the MI subobject and negative-offset field layout.
2. Whether `-0x4FC` table is MSVC vbtable vs custom base pointer table (usage matches slot+4 delta).
3. When Path B host/bank are populated relative to Path A-only objects.
4. Runtime / bit-exact.

---

## 7. Verdict

**accept-with-gaps** — dual-path CF, ABI, offsets, callees, and adjustor entry sealed; product type names open (`_Inferred`).
