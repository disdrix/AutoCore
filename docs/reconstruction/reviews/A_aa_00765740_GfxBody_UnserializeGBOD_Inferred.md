# Review A (reconstruction fidelity): `aa_00765740` GfxBody_UnserializeGBOD_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00765740` |
| **VA** | `0x00765740`–`0x00766045` (**2310 B** / `0x906`) |
| **Canonical name** | `GfxBody_UnserializeGBOD_Inferred` |
| **Ghidra name** | `FUN_00765740` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-S) |
| **Counterpart** | `reviews/B_aa_00765740_GfxBody_UnserializeGBOD_Inferred.md` |
| **System** | palantir graphics / gfxBody GBOD unserialize |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `read_memory` (prologue, tag cmp, epilogue, plates) + `analyze_function_complete` + `get_function_by_address` + callers + caller decompile `FUN_0073eb40`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unserialize a **GBOD** gfxBody root chunk from a sto reader into an already-allocated body object: enter chunk scope, reject wrong tag/version with product plates, version-dispatch (1 vs 2/3), OR nested reader statuses, run MapA factory loops on two pointer vectors, optional MapB attach (v2/v3), copy 12 dwords of transform-ish data `body+4 → body+0x34`, leave scope, return OR-status.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-S append) | `docs/reconstruction/raw/aa_00765740_FUN_00765740.md` |
| Annotated | `docs/reconstruction/raw/aa_00765740_FUN_00765740.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBody_UnserializeGBOD_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00765740.cpp` |
| Function record | `docs/reconstruction/functions/aa_00765740_FUN_00765740.md` |
| Named record | `docs/reconstruction/functions/aa_00765740_GfxBody_UnserializeGBOD_Inferred.md` |
| Plates | `0x00a9dc40` Invalid TAG…; `0x00a9dc0c` Invalid chunk version… |
| Caller | `FUN_0073eb40` @ `0x0073ebce` |
| Nested duals | W36-A `FUN_00437b00`; W36-C `FUN_00437c90`; W36-A `FUN_004449b0` register sites in this body |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, `disassemble_bytes`, unowned VA ownership writes.

---

## 3. Signature (sealed)

```c
// stdcall; RET 8; SEH LAB_009b31c4; ADD ESP,0x5C before RET
uint32_t __stdcall GfxBody_UnserializeGBOD_Inferred(void* body, void* reader);
```

| Item | Evidence | Conf |
|---|---|---|
| RET 8 | epilogue `c2 08 00` | **High** |
| body formal | param_1 used as +4/+0x34/+0x80/… host | **High** |
| reader formal | param_2 / ppuVar3; `[0x1011]` mode | **High** |
| Bad tag −1 | early return `0xffffffff` | **High** |
| OR status | `local_5c \|= …` throughout | **High** |

---

## 4. Control flow (sealed)

```
EnterChunkScope(reader)
if tag != GBOD(0x47424F44): log Invalid TAG; leave?; return -1
if version == 1:
  v1 mesh/section/factory path (OR status; no signed early-abort on factory)
else if version == 2 or 3:
  if version == 3: extra counts + string skip loop
  shared v2/v3 path (inline dword or helper; factory early-abort if status < 0)
  optional MapB at body+0x94 when bool set
else:
  log Invalid chunk version; leave?; return -1
memcpy 12 dwords body+4 → body+0x34
leave chunk if active
return status
```

| Stage | Match | Conf |
|---|---|---|
| GBOD tag gate | Yes — `44 4f 42 47` imm | **High** |
| Version 1 / 2 / 3 | Yes | **High** |
| Factory MapA ×4 sites | Yes — `FUN_00437b00` | **High** |
| `\|0x40` on second vector objs | Yes | **High** |
| Copy 12 dwords | Yes — loop count 0xC | **High** |
| Body size 2310 B | Yes — Ghidra body end | **High** |

---

## 5. Callers / classification

- **Callers (1):** `FUN_0073eb40` — allocates 0x14c body host, peeks tag; **SAMB** alternate; else this unserialize.
- **Classification:** worker (gfxBody GBOD unserialize).

---

## 6. Naming

| Name | Status |
|---|---|
| `GfxBody_UnserializeGBOD_Inferred` | **Accept** — path + plates + tag |
| `Named_gfxBody_00765740` | Scaffold only; superseded |
| Product exact method English | **Open** — no RTTI; keep `_Inferred` |

---

## 7. Gaps

- Per-field product names for body offsets.
- Nested unowned read-helper full contracts.
- Exact EnterChunkScope out-param layout (tag/version locals).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity pass seals ABI, GBOD/version gates, status OR, factory/copy tail, and product plates. Residual field English and nested helpers → **accept-with-gaps**.
