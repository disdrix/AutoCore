# Review A (reconstruction fidelity): `aa_0040afb0` Host_LookupObjectByKey_PairTable30_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040afb0` |
| **VA** | `0x0040afb0`–`0x0040afed` inclusive (**62 B** / `0x3E`) |
| **Canonical name** | `Host_LookupObjectByKey_PairTable30_Inferred` |
| **Ghidra name** | `FUN_0040afb0` |
| **Prior scaffold** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_0040afb0` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-028 OWN dual A) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0040afb0_Host_LookupObjectByKey_PairTable30_Inferred.md` |
| **System** | interaction-activation (shared host pair-table leaf) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **keyed object\* lookup** on a host-owned pair table:

```text
Host_LookupObjectByKey_PairTable30(host, out, key)
  count = host->count@+0x34
  table = host->pairs@+0x30          // {int key; void* value}[] stride 8
  for i in 0..count-1:
    if table[i].key == key:
      *out = table[i].value; return out
  *out = NULL; return out
```

Partition hint ("resolve object\* from soft-cast hit table") is a **primary consumer role** (`FUN_00925820` key=1 via hit payload host), not the exclusive product identity — same leaf serves GetObjectsInArea and collision material keys 3/4.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF |
| Full body | `disassemble_function` + `read_memory` 64 B |
| Callers | `get_function_callers` (7) / `get_function_xrefs` (13 UNCONDITIONAL_CALL) |
| Call-site ABI | `get_assembly_context` on soft-cast, area, contact, UI sites |
| Prior duals | `Drive_CollisionListener_PrepBodyContact` (`aa_005d9ea0`) cites this as material keys 3/4 |
| Scaffold | `Named_CalleeOf_Named_VOG_DEBUG_STOP_0040afb0` — misnamed parent seed |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, other VAs.

---

## 3. Signature (sealed)

```c
// ECX=host; stack out**, key; EAX=out; RET 8
void* __thiscall Host_LookupObjectByKey_PairTable30_Inferred(
    void* host,
    void** outObject,
    int key);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX → table base/count loads | **Confirmed** |
| outObject | stack `[ESP+4]` entry / `[ESP+0xC]` after pushes | **Confirmed** |
| key | stack `[ESP+8]` / `[ESP+0x10]` after pushes | **Confirmed** |
| return | EAX = outObject | **Confirmed** |
| cleanup | `RET 8` (`C2 08 00`) both exits | **Confirmed** |
| leaf | no CALL in body | **Confirmed** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| count @+0x34; miss if `<=0` | Yes | **Confirmed** |
| base @+0x30; stride +8 loop | Yes | **Confirmed** |
| hit: `*out = [base+i*8+4]` | Yes | **Confirmed** |
| miss: `*out = 0` | Yes | **Confirmed** |
| RET 8 both paths | Yes | **Confirmed** |
| No callees | Yes | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| External callers | **7** functions / **13** UNCONDITIONAL_CALL |
| Soft-cast parent | `FUN_00925820` @ `0x00925c8f` key **1** (partition context) |
| Area query | `FUN_004ea350` ×3 key **1** |
| Drive contact | `FUN_005d9ea0` keys **3/4**; `FUN_005da0a0` key **3** |
| Other | `FUN_005911b0` key 3; `FUN_00642b70` / `FUN_00932c80` / `005dd*` key 1 |
| Callees | none |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Algorithm = pair-table int-key → object\* | **Yes** (bytes) |
| Offsets +0x30/+0x34 stride 8 | **Yes** |
| Soft-cast / area / collision consumer roles | **Yes** (xrefs) |
| Product/PDB host type English | **No** → `_Inferred` |
| Scaffold VOG_DEBUG_STOP product name | **No** (string is distant area-debug path) |

**Name:** `Host_LookupObjectByKey_PairTable30_Inferred` — role **High**, product English **Inferred**.

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF / ABI / RET 8 / offsets | **High** | disasm + bytes |
| Out-param + EAX=out idiom | **High** | callers `mov reg,[eax]` |
| Key domain includes 1/3/4 | **High** | call-site immediates |
| Product host type / symbol | **Tentative** | `_Inferred` |
| Soft-cast-only identity | **Rejected** | multi-system xrefs |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 8. Gaps / open

1. Product/PDB symbol and host RTTI English.  
2. Semantic catalog of all key IDs beyond 1/3/4 samples.  
3. Whether pair table allows duplicate keys (first-match only).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/layout/call-role sealed; product English open.
